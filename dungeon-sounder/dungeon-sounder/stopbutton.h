#pragma once

#include <QtWidgets\qpushbutton.h>

class StopButton : public QPushButton
{
	Q_OBJECT

public:
	StopButton(QWidget *parent = Q_NULLPTR);
	void setIndex(int _index);

signals:
	void stop(int index);

private slots:
	void stopEmitter();

private:
	int index;
};