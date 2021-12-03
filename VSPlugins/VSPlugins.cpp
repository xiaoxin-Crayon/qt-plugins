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
 * @brief MainWindow::loadPlugins ���ز�����������plugins�ļ�����
 * @return ���ز���ĸ���
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
	//			//���ز��������menu
	//			populateMenus(plugin, centerInterface);
	//		}
	//	}
	//}
	return 0;
}

/**
 * @brief MainWindow::populateMenus ���ݲ������menu
 * @param pluginInterface ���
 * @param i ���ʵ�ֵĽӿ�
 */
void VSPlugins::populateMenus(QObject * pluginInterface, MainInterface*i)
{
	static auto menu = menuBar()->addMenu("widgets");
	auto act = new QAction(/*"one"*/i->name(), pluginInterface);
	//����menu���ò��
	connect(act, &QAction::triggered, this, &VSPlugins::slt_WidgetActionTriggered);
	menu->addAction(act);
}

/**
 * @brief MainWindow::slt_WidgetActionTriggered ����menu���ò��
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