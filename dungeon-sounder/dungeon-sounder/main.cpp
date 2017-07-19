#include "stdafx.h"
#include "dungeonsounder.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	dungeonsounder w;
	w.show();
	return a.exec();
}
