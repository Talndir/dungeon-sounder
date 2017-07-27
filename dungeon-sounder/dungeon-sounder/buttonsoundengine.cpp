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
		s.type = d->sound->type;
		s.page = button->pageName;
		s.button = button->text();
		
		s.ex_type_track = d->sound->exclusive_type;
		s.ex_global_track = d->sound->exclusive_global;
		s.ex_local_button = button->exclusive_local;
		s.ex_global_button = button->exclusive_global;

		// Apply sound rules
		for (unsigned int j = 0; j < soundData.size(); ++j)
		{
			l = &soundData.at(j);

			if (
				(s.ex_global_track || l->ex_global_track) ||
				(d->sound->exclusive_single && (l->name == d->sound->name)) ||
				(s.ex_type_track && (s.type == l->type)) ||
				(s.ex_local_button && (s.page == l->page)) ||
				(s.ex_global_button && (s.button == l->button)))
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
			int n = 0;

			do
			{
				str.append("_" + std::to_string(n));
				s.soundSource = this->engine->getSoundSource(d->sound->path.toStdString().c_str(), false);
				s.soundSource = this->engine->addSoundSourceAlias(s.soundSource, str.c_str());
				str = str.substr(0, str.size() - 2);
				++n;
			} while (!s.soundSource);
		}

		s.soundSource->setDefaultVolume(d->volume * d->sound->volume);

		newSounds.push_back(s);
	}

	int n = soundData.size();
	soundData.insert(soundData.end(), newSounds.begin(), newSounds.end());

	for (unsigned int i = n; i < soundData.size(); ++i)
		this->engine->play2D(soundData.at(i).soundSource);
}

void ButtonSoundEngine::stopIndividual(QWidget * parent)
{
	QDialog* dialog = new QDialog(parent);
	QVBoxLayout* layout = new QVBoxLayout;

	for (unsigned int i = 0; i < soundData.size(); ++i)
	{
		SoundData& s = soundData.at(i);
		QHBoxLayout* box = new QHBoxLayout;
		
		QLabel *name, *button, *page;
		name = new QLabel(parent);
		name->setText(s.name);
		button = new QLabel(parent);
		button->setText(s.button);
		page = new QLabel(parent);
		page->setText(s.page);

		StopButton* stop = new StopButton;
		stop->setIndex(i);
		connect(stop, SIGNAL(stop(int)), this, SLOT(stop(int)));

		box->addWidget(name);
		box->addWidget(button);
		box->addWidget(page);
		box->addWidget(stop);

		layout->addItem(box);
	}

	dialog->setLayout(layout);
	dialog->setAttribute(Qt::WA_DeleteOnClose, true);
	dialog->connect(dialog, SIGNAL(destroyed(QObject*)), this, SLOT(deleteMarked())); // destroyed
	dialog->show();
}

void ButtonSoundEngine::stopPage(QString& page)
{
	qWarning(page.toStdString().c_str());
	for (unsigned int i = 0; i < this->soundData.size(); ++i)
	{
		if (this->soundData.at(i).page == page)
		{
			this->engine->removeSoundSource(soundData.at(i).soundSource);
			soundData.erase(soundData.begin() + i);
			--i;
		}
	}
}

void ButtonSoundEngine::stopAll()
{
	this->engine->stopAllSounds();

	while (this->soundData.size())
	{
		this->engine->removeSoundSource(soundData.at(0).soundSource);
		this->soundData.erase(this->soundData.begin());
	}
}

void ButtonSoundEngine::deleteMarked()
{
	for (unsigned int i = 0; i < soundData.size(); ++i)
	{
		if (soundData.at(i).marked)
		{
			soundData.erase(soundData.begin() + i);
			--i;
		}
	}
}

void ButtonSoundEngine::stop(int index)
{
	this->engine->removeSoundSource(soundData.at(index).soundSource);
	this->soundData.at(index).marked = true;
	//this->soundData.erase(this->soundData.begin() + index);
}