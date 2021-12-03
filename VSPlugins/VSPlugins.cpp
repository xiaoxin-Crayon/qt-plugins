#include "VSPlugins.h"

#include <QDir>
#include <QPluginLoader>
#include <QThread>
#include <qdebug.h>


VSPlugins::VSPlugins(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	loadPlugins();
}

/**
 * @brief MainWindow::loadPlugins 加载插件、插件放在plugins文件夹下
 * @return 返回插件的个数
 */
int VSPlugins::loadPlugins()
{
	QString path = qApp->applicationDirPath();

	//QDir pluginsDir = QDir(qApp->applicationDirPath());
	//pluginsDir.cd("plugins");

	con = new Controller;
	con->setPlugin(path);
	populateMenus(con->plugin, con->certificate);

	//if (!pluginsDir.cd("plugins")) return -1;
	//foreach(QString fileName, pluginsDir.entryList(QDir::Files))
	//{
	//	QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
	//	QObject *plugin = pluginLoader.instance();

	//	if (plugin)
	//	{
	//		auto centerInterface = qobject_cast<MainInterface*>(plugin);
	//		qDebug() << "centerInterface:" << centerInterface;
	//		con = new Controller;
	//		con->setPlugin(plugin);

	//		if (centerInterface)
	//		{
	//			//加载插件后生成menu
	//			populateMenus(plugin, centerInterface);
	//		}
	//	}
	//}
	return 0;
}

/**
 * @brief MainWindow::populateMenus 根据插件生成menu
 * @param pluginInterface 插件
 * @param i 插件实现的接口
 */
void VSPlugins::populateMenus(QObject * pluginInterface, MainInterface*i)
{
	static auto menu = menuBar()->addMenu("widgets");
	auto act = new QAction(/*"one"*/i->name(), pluginInterface);
	//单击menu调用插件
	connect(act, &QAction::triggered, this, &VSPlugins::slt_WidgetActionTriggered);
	menu->addAction(act);
}

/**
 * @brief MainWindow::slt_WidgetActionTriggered 单击menu调用插件
 */
void VSPlugins::slt_WidgetActionTriggered()
{
	//auto centerWidget = qobject_cast<MainInterface*>(sender()->parent())->centerWidget();
	//setCentralWidget(centerWidget);

	//qobject_cast<MainInterface*>(sender()->parent())->test();

	QThread *sub = new QThread;
	con->moveToThread(sub);
	sub->start();

	qDebug() << "mainThread:" << QThread::currentThread();
	//qDebug() << "subThread:" << con->thread();
	//con->testThread();

	connect(sub, &QThread::started, con, &Controller::testThread);
}