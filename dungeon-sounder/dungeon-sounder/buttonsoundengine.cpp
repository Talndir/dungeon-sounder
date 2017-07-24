#include "stdafx.h"
#include "buttonsoundengine.h"

ButtonSoundEngine::ButtonSoundEngine()
{
	this->engine = irrklang::createIrrKlangDevice();
	this->soundData = std::vector<SoundData>();
}

ButtonSoundEngine::~ButtonSoundEngine()
{
	this->engine->drop();
}

void ButtonSoundEngine::pressButton(SoundButton * button)
{
	// Create and add sounds to new vector
	std::vector<SoundData> newSounds;
	SoundInfo* d;
	SoundData* l;
	
	for (unsigned int i = 0; i < button->sounds.size(); ++i)
	{
		SoundData s;
		d = &button->sounds.at(i);
		
		s.delay = d->delay;
		s.fade = d->fade;
		s.loop = d->loop;
		s.sync = d->sync;
		s.name = d->sound->name;

		s.ex_global_track = d->sound->exclusive_global;

		if (d->sound->exclusive_type)
			s.type = d->sound->type;
		if (button->exclusive_local)
			s.page = button->pageName;
		if (button->exclusive_global)
			s.button = button->text();

		// Apply sound rules
		for (unsigned int j = 0; j < soundData.size(); ++j)
		{
			l = &soundData.at(j);

			if (
				(s.ex_global_track || l->ex_global_track) ||
				(d->sound->exclusive_single && (l->name == d->sound->name)) ||
				(s.type != "" && (s.type == l->type)) ||
				(s.page != "" && (s.page == l->page)) ||
				(s.button != "" && (s.button == l->button)))
			{
				this->engine->removeSoundSource(soundData.at(j).soundSource);
				soundData.erase(soundData.begin() + j);
				--j;
			}
		}

		s.soundSource = this->engine->getSoundSource(d->sound->path.toStdString().c_str(), false);

		if (!s.soundSource)
			s.soundSource = this->engine->addSoundSourceFromFile(d->sound->path.toStdString().c_str());
		else
		{
			std::string str = s.soundSource->getName();
			str.append("_x");
			s.soundSource = this->engine->addSoundSourceAlias(s.soundSource, str.c_str());
		}

		s.soundSource->setDefaultVolume(d->volume * d->sound->volume);

		newSounds.push_back(s);
	}

	int n = soundData.size();
	soundData.insert(soundData.end(), newSounds.begin(), newSounds.end());

	for (unsigned int i = n; i < soundData.size(); ++i)
		this->engine->play2D(soundData.at(i).soundSource);
}
