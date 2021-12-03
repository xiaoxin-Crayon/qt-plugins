#include "One.h"
#include <qdebug.h>


One::One()
{
}

One::~One()
{
	qDebug() << "~One";
}

QString One::name()
{
	return "One";
}

QString One::information()
{
	return "One_info";
}

QWidget *One::centerWidget()
{
	QPushButton* btn = new QPushButton("One");
	return btn;
}

int One::test()
{
	//qDebug() << "num:" << num;
	qDebug() << "trueThread:" << QThread::currentThread();

	int count = 1;
	//qDebug() << "count:" << count;
	QThread::msleep(100);

	return count;
}