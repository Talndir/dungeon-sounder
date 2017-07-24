#include "stdafx.h"
#include "soundbutton.h"

SoundButton::SoundButton(QWidget* parent)
	: QPushButton(parent)
{

}

void SoundButton::setup(QJsonObject & buttonObject, QString _pageName)
{
	this->setText(buttonObject["name"].toString());
	this->setStyleSheet("background-color: #" + buttonObject["colour"].toString());
	this->exclusive_local = buttonObject["exclusive_local"].toBool();
	this->exclusive_global = buttonObject["exclusive_global"].toBool();
	this->pageName = _pageName;

	QJsonArray soundArray = buttonObject["sounds"].toArray();

	for (unsigned int i = 0; i < soundArray.size(); ++i)
		this->sounds.push_back(SoundInfo(soundArray[i].toObject()));
}
