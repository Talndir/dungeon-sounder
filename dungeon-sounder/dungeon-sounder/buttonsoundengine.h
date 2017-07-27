#pragma once

#include <QtWidgets\qdialog.h>
#include <vector>
#include "sounddata.h"
#include "soundbutton.h"
#include "stopbutton.h"

class ButtonSoundEngine : public QObject
{
	Q_OBJECT

public:
	ButtonSoundEngine();
	~ButtonSoundEngine();

	void pressButton(SoundButton* button);
	
	void stopIndividual(QWidget* parent);
	void stopPage(QString& page);
	void stopAll();

private slots:
	void stop(int index);
	void deleteMarked();

private:
	irrklang::ISoundEngine* engine;
	std::vector<SoundData> soundData;
};