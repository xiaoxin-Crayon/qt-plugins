#pragma once

#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <qstring.h>
#include <QtPlugin>

class MainInterface
{
public:
	virtual ~MainInterface() {}
	virtual QString name() = 0;
	virtual QString information() = 0;
	virtual QWidget *centerWidget() = 0;
	virtual int test() = 0;

};

#define MainInterface_iid "com.Interface.MainInterface"
Q_DECLARE_INTERFACE(MainInterface, MainInterface_iid)

#endif // MAININTERFACE_H