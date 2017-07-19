#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_dungeonsounder.h"

class dungeonsounder : public QMainWindow
{
	Q_OBJECT

public:
	dungeonsounder(QWidget *parent = Q_NULLPTR);

private:
	Ui::dungeonsounderClass ui;
};
