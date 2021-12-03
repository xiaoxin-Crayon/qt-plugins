#pragma once

#include "interface.h"

class Controller : public QObject
{
	Q_OBJECT

public:

	QObject* plugin;
	MainInterface* certificate;

	Controller(QObject *parent = Q_NULLPTR);
	//QObject* loadPlugins();
	int setPlugin(QString);

	void testThread();

};