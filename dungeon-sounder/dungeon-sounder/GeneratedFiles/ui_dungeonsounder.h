/********************************************************************************
** Form generated from reading UI file 'dungeonsounder.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUNGEONSOUNDER_H
#define UI_DUNGEONSOUNDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dungeonsounderClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dungeonsounderClass)
    {
        if (dungeonsounderClass->objectName().isEmpty())
            dungeonsounderClass->setObjectName(QStringLiteral("dungeonsounderClass"));
        dungeonsounderClass->resize(600, 400);
        menuBar = new QMenuBar(dungeonsounderClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        dungeonsounderClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dungeonsounderClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        dungeonsounderClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(dungeonsounderClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        dungeonsounderClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(dungeonsounderClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        dungeonsounderClass->setStatusBar(statusBar);

        retranslateUi(dungeonsounderClass);

        QMetaObject::connectSlotsByName(dungeonsounderClass);
    } // setupUi

    void retranslateUi(QMainWindow *dungeonsounderClass)
    {
        dungeonsounderClass->setWindowTitle(QApplication::translate("dungeonsounderClass", "dungeonsounder", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dungeonsounderClass: public Ui_dungeonsounderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUNGEONSOUNDER_H
