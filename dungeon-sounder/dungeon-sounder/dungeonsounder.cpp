#include "stdafx.h"
#include "dungeonsounder.h"

std::vector<Sound> sounds = std::vector<Sound>();

dungeonsounder::dungeonsounder(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	loadSounds();
	loadPages();

	d.clear();
	soundEngine = new ButtonSoundEngine();
}

dungeonsounder::~dungeonsounder()
{
	delete soundEngine;
}

bool dungeonsounder::loadSounds()
{
	QFile soundsFile("scripts/sounds.json");

	if (!soundsFile.open(QIODevice::ReadOnly))
	{
		qWarning("Cannot open sounds file");
		return false;
	}

	QByteArray soundsData = soundsFile.readAll();
	QJsonDocument soundsDoc(QJsonDocument::fromJson(soundsData));
	QJsonObject soundsObject = soundsDoc.object();
	QJsonArray soundArray = soundsObject["sounds"].toArray();

	for (unsigned int i = 0; i < soundArray.size(); ++i)
		sounds.push_back(Sound(soundArray[i].toObject()));

	return true;
}

bool dungeonsounder::loadPages()
{
	QFile pagesFile("scripts/pages.json");

	if (!pagesFile.open(QIODevice::ReadOnly))
	{
		qWarning("Cannot open pages file");
		return false;
	}

	QByteArray pagesData = pagesFile.readAll();
	QJsonDocument pagesDoc(QJsonDocument::fromJson(pagesData));
	QJsonObject pagesObject = pagesDoc.object();
	QJsonArray pageArray = pagesObject["pages"].toArray();

	for (unsigned int i = 0; i < pageArray.size(); ++i)
		loadPage(pageArray[i].toString());

	return true;
}

bool dungeonsounder::loadPage(QString pageName)
{
	QFile pageFile("scripts/pages/" + pageName + ".json");

	if (!pageFile.open(QIODevice::ReadOnly))
	{
		qWarning("Cannot open page file \"" + pageName.toLatin1() + "\"");
		return false;
	}

	QTabWidget* page = new QTabWidget();
	QGridLayout* layout = new QGridLayout;

	QByteArray pageData = pageFile.readAll();
	QJsonDocument pageDoc(QJsonDocument::fromJson(pageData));
	QJsonObject pageObject = pageDoc.object();
	QJsonArray buttonArray = pageObject["buttons"].toArray();

	for (unsigned int i = 0; i < buttonArray.size(); ++i)
		layout->addWidget(createButton(buttonArray[i].toObject(), pageName));

	page->setLayout(layout);
	ui.tabWidget->addTab(page, pageName);

	return true;
}

SoundButton* dungeonsounder::createButton(QJsonObject& buttonObject, QString pageName)
{
	SoundButton* button = new SoundButton;
	button->setup(buttonObject, pageName);
	connect(button, SIGNAL(released()), this, SLOT(handleSoundButton()));

	return button;
}

void dungeonsounder::handleSoundButton()
{
	QObject* button = QObject::sender();
	soundEngine->pressButton((SoundButton*)button);
}