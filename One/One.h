#pragma once

#ifndef ONE_H
#define ONE_H

#include "one_global.h"
#include "interface.h"
#include <QPushButton>
#include <qthread.h>

class ONE_EXPORT One
	:public QObject
	, public MainInterface
{
	Q_OBJECT
	Q_INTERFACES(MainInterface)
	Q_PLUGIN_METADATA(IID MainInterface_iid)
public:
	One();
	~One() override;

	virtual QString name() override;
	virtual QString information() override;
	virtual QWidget *centerWidget() override;
	virtual int test() override;

};

#endif // FINALLY_H