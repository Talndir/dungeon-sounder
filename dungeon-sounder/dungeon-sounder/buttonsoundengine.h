#pragma once

#include <vector>
#include "sounddata.h"
#include "soundbutton.h"

class ButtonSoundEngine
{
public:
	ButtonSoundEngine();
	~ButtonSoundEngine();

	void pressButton(SoundButton* button);

	void stopAll();
	void stopPage(QString& page);

private:
	irrklang::ISoundEngine* engine;
	std::vector<SoundData> soundData;
};