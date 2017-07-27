#include "stdafx.h"
#include "stopbutton.h"

StopButton::StopButton(QWidget *parent)
	: QPushButton(parent)
{
	this->setText("X");
	connect(this, SIGNAL(pressed()), this, SLOT(stopEmitter()));
}

void StopButton::stopEmitter()
{
	this->setDisabled(true);
	emit this->stop(index);
}

void StopButton::setIndex(int _index)
{
	this->index = _index;
}
