#include "controller.h"

#include <QDir>
#include <QPluginLoader>
#include <QThread>
#include <qdebug.h>

Controller::Controller(QObject *parent)
{

}

int Controller::setPlugin(QString path)
{
	//Controller::plugin = plugin;
	//Controller::certificate = qobject_cast<MainInterface*>(plugin);

	QDir pluginpath = QDir(path);
	if (!pluginpath.cd("plugins")) return -1;

	foreach(QString fileName, pluginpath.entryList(QDir::Files))
	{
		QPluginLoader pluginLoader(pluginpath.absoluteFilePath(fileName));
		plugin = pluginLoader.instance();

		if (plugin)
		{
			certificate = qobject_cast<MainInterface*>(plugin);
			//qDebug() << "centerInterface:" << certificate;
		}
	}
	return 0;
}

void Controller::testThread()
{
	qDebug() << "subThread:" << QThread::currentThread();
	while (true)
	{
		int count = certificate->test();
		qDebug() << "count:" << count;
	}
}