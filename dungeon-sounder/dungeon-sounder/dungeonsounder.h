#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_dungeonsounder.h"
#include "SoundButton.h"

class dungeonsounder : public QMainWindow
{
	Q_OBJECT

public:
	dungeonsounder(QWidget *parent = Q_NULLPTR);

private:
	Ui::dungeonsounderClass ui;

	bool loadSounds();
	bool loadPages();
	bool loadPage(QString pageName);
	SoundButton* createButton(QJsonObject& buttonObject);
};
