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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dungeonsounderClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionNew_Sound;
    QAction *actionNew_Button;
    QAction *actionNew_Page;
    QAction *actionStop_sound;
    QAction *actionStop_sounds_from_page;
    QAction *actionStop_all_sounds;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dungeonsounderClass)
    {
        if (dungeonsounderClass->objectName().isEmpty())
            dungeonsounderClass->setObjectName(QStringLiteral("dungeonsounderClass"));
        dungeonsounderClass->resize(600, 400);
        actionOpen = new QAction(dungeonsounderClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(dungeonsounderClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(dungeonsounderClass);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionExit = new QAction(dungeonsounderClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionNew_Sound = new QAction(dungeonsounderClass);
        actionNew_Sound->setObjectName(QStringLiteral("actionNew_Sound"));
        actionNew_Button = new QAction(dungeonsounderClass);
        actionNew_Button->setObjectName(QStringLiteral("actionNew_Button"));
        actionNew_Page = new QAction(dungeonsounderClass);
        actionNew_Page->setObjectName(QStringLiteral("actionNew_Page"));
        actionStop_sound = new QAction(dungeonsounderClass);
        actionStop_sound->setObjectName(QStringLiteral("actionStop_sound"));
        actionStop_sounds_from_page = new QAction(dungeonsounderClass);
        actionStop_sounds_from_page->setObjectName(QStringLiteral("actionStop_sounds_from_page"));
        actionStop_all_sounds = new QAction(dungeonsounderClass);
        actionStop_all_sounds->setObjectName(QStringLiteral("actionStop_all_sounds"));
        centralWidget = new QWidget(dungeonsounderClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        dungeonsounderClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(dungeonsounderClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        dungeonsounderClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dungeonsounderClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        dungeonsounderClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(dungeonsounderClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        dungeonsounderClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionNew_Sound);
        menuEdit->addAction(actionNew_Button);
        menuEdit->addAction(actionNew_Page);
        menuTools->addAction(actionStop_sound);
        menuTools->addAction(actionStop_sounds_from_page);
        menuTools->addAction(actionStop_all_sounds);

        retranslateUi(dungeonsounderClass);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(dungeonsounderClass);
    } // setupUi

    void retranslateUi(QMainWindow *dungeonsounderClass)
    {
        dungeonsounderClass->setWindowTitle(QApplication::translate("dungeonsounderClass", "dungeonsounder", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("dungeonsounderClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("dungeonsounderClass", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("dungeonsounderClass", "Save As", Q_NULLPTR));
        actionExit->setText(QApplication::translate("dungeonsounderClass", "Exit", Q_NULLPTR));
        actionNew_Sound->setText(QApplication::translate("dungeonsounderClass", "New Sound", Q_NULLPTR));
        actionNew_Button->setText(QApplication::translate("dungeonsounderClass", "New Button", Q_NULLPTR));
        actionNew_Page->setText(QApplication::translate("dungeonsounderClass", "New Page", Q_NULLPTR));
        actionStop_sound->setText(QApplication::translate("dungeonsounderClass", "Stop single sound", Q_NULLPTR));
        actionStop_sounds_from_page->setText(QApplication::translate("dungeonsounderClass", "Stop sounds from this page", Q_NULLPTR));
        actionStop_all_sounds->setText(QApplication::translate("dungeonsounderClass", "Stop all sounds", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("dungeonsounderClass", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("dungeonsounderClass", "Edit", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("dungeonsounderClass", "Tools", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dungeonsounderClass: public Ui_dungeonsounderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUNGEONSOUNDER_H
