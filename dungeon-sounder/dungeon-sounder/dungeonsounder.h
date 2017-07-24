#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_dungeonsounder.h"
#include "buttonsoundengine.h"


class dungeonsounder : public QMainWindow
{
	Q_OBJECT

public:
	dungeonsounder(QWidget *parent = Q_NULLPTR);
	virtual ~dungeonsounder();

private slots:
	void handleSoundButton();
	
private:
	Ui::dungeonsounderClass ui;

	bool loadSounds();
	bool loadPages();
	bool loadPage(QString pageName);
	SoundButton* createButton(QJsonObject& buttonObject, QString pageName);

	ButtonSoundEngine* soundEngine;
	std::vector<SoundData> d;
};
