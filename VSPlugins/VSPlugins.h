#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VSPlugins.h"
//#include "interface.h"
#include "controller.h"

class VSPlugins : public QMainWindow
{
    Q_OBJECT

public:

	Controller *con;
    VSPlugins(QWidget *parent = Q_NULLPTR);
	void populateMenus(QObject *pluginInterface, MainInterface *i);

private:
    Ui::VSPluginsClass ui;
	int loadPlugins();

private slots:
	void slt_WidgetActionTriggered();

};
