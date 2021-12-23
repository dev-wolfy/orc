#include "remotecontrol.h"

RemoteControl::RemoteControl(QWidget *parent)
    : QMainWindow(parent)
{
    this->fsi = new FileSystemInterface();
    this->rcc = this->fsi->loadFromFile();

    this->initUi();
    this->initQConnect();
    this->applyConfig();
}

void RemoteControl::initUi()
{
    this->mainWidget = new QWidget(this);
    this->mainLayout = new QVBoxLayout(mainWidget);

    // WINDOWS

    QIcon titleIcon = QIcon(":/icons/rsc/tv-solid.svg");
    this->setWindowIcon(titleIcon);
    this->setWindowIconText("ORC");
    this->setWindowTitle("ORC");


    // ON OFF BUTTON
    QIcon iconONOFF = QIcon(":/icons/rsc/power-off-solid.svg");
    this->button_ONOFF = new QPushButton(mainWidget);
    this->button_ONOFF->setIcon(iconONOFF);
    this->button_all.push_back(this->button_ONOFF);


    // DIRECTION GRID LAYOUT
    QGridLayout* directionGridLayout = new QGridLayout();

    QIcon iconNETFLIX = QIcon(":/icons/rsc/netflix-icon.svg");
    this->button_NETFLIX = new QPushButton(mainWidget);
    this->button_NETFLIX->setIcon(iconNETFLIX);
    this->button_NETFLIX->setIconSize(QSize(35, 35));
    this->button_NETFLIX->setMaximumSize(40, 40);
    this->button_NETFLIX->setMinimumSize(40, 40);
    this->button_all.push_back(this->button_NETFLIX);

    QIcon iconUP = QIcon(":/icons/rsc/chevron-up-solid.svg");
    this->button_UP = new QPushButton();
    this->button_UP->setIcon(iconUP);
    this->button_UP->setMaximumSize(50, 50);
    this->button_UP->setMinimumSize(50, 50);
    this->button_all.push_back(this->button_UP);

    QIcon iconSettings = QIcon(":/icons/rsc/cog-solid.svg");
    this->button_SETTINGS = new QPushButton();
    this->button_SETTINGS->setIcon(iconSettings);
    this->button_SETTINGS->setMaximumSize(40,40);
    this->button_SETTINGS->setMinimumSize(40,40);
    this->button_all.push_back(this->button_SETTINGS);

    QIcon iconLEFT = QIcon(":/icons/rsc/chevron-left-solid.svg");
    this->button_LEFT = new QPushButton();
    this->button_LEFT->setIcon(iconLEFT);
    this->button_LEFT->setMaximumSize(50, 50);
    this->button_LEFT->setMinimumSize(50, 50);
    this->button_all.push_back(this->button_LEFT);

    QIcon iconOK = QIcon(":/icons/rsc/check-circle-solid.svg");
    this->button_OK = new QPushButton();
    this->button_OK->setIcon(iconOK);
    this->button_OK->setMaximumSize(50, 50);
    this->button_OK->setMinimumSize(50, 50);
    this->button_all.push_back(this->button_OK);

    QIcon iconRIGTH = QIcon(":/icons/rsc/chevron-right-solid.svg");
    this->button_RIGHT = new QPushButton();
    this->button_RIGHT->setIcon(iconRIGTH);
    this->button_RIGHT->setMaximumSize(50, 50);
    this->button_RIGHT->setMinimumSize(50, 50);
    this->button_all.push_back(this->button_RIGHT);

    QIcon iconBOTTOM = QIcon(":/icons/rsc/chevron-down-solid.svg");
    this->button_DOWN = new QPushButton();
    this->button_DOWN->setIcon(iconBOTTOM);
    this->button_DOWN->setMaximumSize(50, 50);
    this->button_DOWN->setMinimumSize(50, 50);
    this->button_all.push_back(this->button_DOWN);

    QIcon iconMENU = QIcon(":/icons/rsc/bars-solid.svg");
    this->button_MENU = new QPushButton();
    this->button_MENU->setIcon(iconMENU);
    this->button_MENU->setMaximumSize(40, 40);
    this->button_MENU->setMinimumSize(40, 40);
    this->button_all.push_back(this->button_MENU);

    QIcon iconBACK = QIcon(":/icons/rsc/undo-alt-solid.svg");
    this->button_BACK = new QPushButton();
    this->button_BACK->setIcon(iconBACK);
    this->button_BACK->setMaximumSize(40, 40);
    this->button_BACK->setMinimumSize(40, 40);
    this->button_all.push_back(this->button_BACK);

    directionGridLayout->addWidget(this->button_NETFLIX, 0, 0);
    directionGridLayout->addWidget(this->button_UP, 0, 1);
    directionGridLayout->addWidget(this->button_SETTINGS, 0, 2);
    directionGridLayout->addWidget(this->button_LEFT, 1, 0);
    directionGridLayout->addWidget(this->button_OK, 1, 1);
    directionGridLayout->addWidget(this->button_RIGHT, 1, 2);
    directionGridLayout->addWidget(this->button_MENU, 2, 0);
    directionGridLayout->addWidget(this->button_DOWN, 2, 1);
    directionGridLayout->addWidget(this->button_BACK, 2, 2);


    // VOLUMES SECTION

    QHBoxLayout *volumeHorizontalLayout = new QHBoxLayout();

    QIcon iconVOLD = QIcon(":/icons/rsc/volume-down-solid.svg");
    this->button_VOLD = new QPushButton();
    this->button_VOLD->setIcon(iconVOLD);
    this->button_all.push_back(this->button_VOLD);

    QIcon iconMUTE = QIcon(":/icons/rsc/volume-mute-solid.svg");
    this->button_MUTE = new QPushButton();
    this->button_MUTE->setIcon(iconMUTE);
    this->button_all.push_back(this->button_MUTE);

    QIcon iconVOLU = QIcon(":/icons/rsc/volume-up-solid.svg");
    this->button_VOLU = new QPushButton();
    this->button_VOLU->setIcon(iconVOLU);
    this->button_all.push_back(this->button_VOLU);

    volumeHorizontalLayout->addWidget(this->button_VOLD);
    volumeHorizontalLayout->addWidget(this->button_MUTE);
    volumeHorizontalLayout->addWidget(this->button_VOLU);


    // NUMBER SECTION

    QGridLayout* numberGridLayout = new QGridLayout();

    this->button_0 = new QPushButton("0", this);
    this->button_0->setMinimumSize(40,40);
    this->button_0->setMaximumSize(40,40);
    this->button_all.push_back(this->button_0);

    this->button_1 = new QPushButton("1", this);
    this->button_1->setMinimumSize(40,40);
    this->button_1->setMaximumSize(40,40);
    this->button_all.push_back(this->button_1);

    this->button_2 = new QPushButton("2", this);
    this->button_2->setMinimumSize(40,40);
    this->button_2->setMaximumSize(40,40);
    this->button_all.push_back(this->button_2);

    this->button_3 = new QPushButton("3", this);
    this->button_3->setMinimumSize(40,40);
    this->button_3->setMaximumSize(40,40);
    this->button_all.push_back(this->button_3);

    this->button_4 = new QPushButton("4", this);
    this->button_4->setMinimumSize(40,40);
    this->button_4->setMaximumSize(40,40);
    this->button_all.push_back(this->button_4);

    this->button_5 = new QPushButton("5", this);
    this->button_5->setMinimumSize(40,40);
    this->button_5->setMaximumSize(40,40);
    this->button_all.push_back(this->button_5);

    this->button_6 = new QPushButton("6", this);
    this->button_6->setMinimumSize(40,40);
    this->button_6->setMaximumSize(40,40);
    this->button_all.push_back(this->button_6);

    this->button_7 = new QPushButton("7", this);
    this->button_7->setMinimumSize(40,40);
    this->button_7->setMaximumSize(40,40);
    this->button_all.push_back(this->button_7);

    this->button_8 = new QPushButton("8", this);
    this->button_8->setMinimumSize(40,40);
    this->button_8->setMaximumSize(40,40);
    this->button_all.push_back(this->button_8);

    this->button_9 = new QPushButton("9", this);
    this->button_9->setMinimumSize(40,40);
    this->button_9->setMaximumSize(40,40);
    this->button_all.push_back(this->button_9);

    numberGridLayout->addWidget(this->button_1, 0, 0);
    numberGridLayout->addWidget(this->button_2, 0, 1);
    numberGridLayout->addWidget(this->button_3, 0, 2);
    numberGridLayout->addWidget(this->button_4, 1, 0);
    numberGridLayout->addWidget(this->button_5, 1, 1);
    numberGridLayout->addWidget(this->button_6, 1, 2);
    numberGridLayout->addWidget(this->button_7, 2, 0);
    numberGridLayout->addWidget(this->button_8, 2, 1);
    numberGridLayout->addWidget(this->button_9, 2, 2);
    numberGridLayout->addWidget(this->button_0, 3, 1);


    // LECTURE SECTION

    QHBoxLayout *lectureHorizontalLayout = new QHBoxLayout();

    QIcon iconBACKWARD = QIcon(":/icons/rsc/backward-solid.svg");
    this->button_BACKWARD = new QPushButton();
    this->button_BACKWARD->setIcon(iconBACKWARD);
    this->button_all.push_back(this->button_BACKWARD);

    QIcon iconPLAY = QIcon(":/icons/rsc/play-solid.svg");
    this->button_PLAY = new QPushButton();
    this->button_PLAY->setIcon(iconPLAY);
    this->button_all.push_back(this->button_PLAY);

    QIcon iconFORWARD = QIcon(":/icons/rsc/forward-solid.svg");
    this->button_FORWARD = new QPushButton();
    this->button_FORWARD->setIcon(iconFORWARD);
    this->button_all.push_back(this->button_FORWARD);

    lectureHorizontalLayout->addWidget(this->button_BACKWARD);
    lectureHorizontalLayout->addWidget(this->button_PLAY);
    lectureHorizontalLayout->addWidget(this->button_FORWARD);


    // FINAL INIT - ADD ALL SECTIONS
    mainLayout->addWidget(this->button_ONOFF);
    mainLayout->addLayout(directionGridLayout);
    mainLayout->addLayout(volumeHorizontalLayout);
    mainLayout->addLayout(numberGridLayout);
    mainLayout->addLayout(lectureHorizontalLayout);

    this->mainWidget->setLayout(mainLayout);
    this->setCentralWidget(this->mainWidget);


    // RESIZE MAINWINDOWS

    this->resize(this->minimumWidth(), this->height());
}

void RemoteControl::initQConnect()
{
    QObject::connect(this->button_ONOFF, &QPushButton::clicked, this, &RemoteControl::sendOnOff);
    QObject::connect(this->button_NETFLIX, &QPushButton::clicked, this, &RemoteControl::sendNetflix);
    QObject::connect(this->button_UP, &QPushButton::clicked, this, &RemoteControl::sendUp);
    QObject::connect(this->button_LEFT, &QPushButton::clicked, this, &RemoteControl::sendLeft);
    QObject::connect(this->button_OK, &QPushButton::clicked, this, &RemoteControl::sendOk);
    QObject::connect(this->button_RIGHT, &QPushButton::clicked, this, &RemoteControl::sendRight);
    QObject::connect(this->button_DOWN, &QPushButton::clicked, this, &RemoteControl::sendDown);
    QObject::connect(this->button_MENU, &QPushButton::clicked, this, &RemoteControl::openMenu);
    QObject::connect(this->button_BACK, &QPushButton::clicked, this, &RemoteControl::sendBack);
    QObject::connect(this->button_VOLD, &QPushButton::clicked, this, &RemoteControl::sendVolD);
    QObject::connect(this->button_MUTE, &QPushButton::clicked, this, &RemoteControl::sendMute);
    QObject::connect(this->button_VOLU, &QPushButton::clicked, this, &RemoteControl::sendVolU);
    QObject::connect(this->button_1, &QPushButton::clicked, this, &RemoteControl::send1);
    QObject::connect(this->button_2, &QPushButton::clicked, this, &RemoteControl::send2);
    QObject::connect(this->button_3, &QPushButton::clicked, this, &RemoteControl::send3);
    QObject::connect(this->button_4, &QPushButton::clicked, this, &RemoteControl::send4);
    QObject::connect(this->button_5, &QPushButton::clicked, this, &RemoteControl::send5);
    QObject::connect(this->button_6, &QPushButton::clicked, this, &RemoteControl::send6);
    QObject::connect(this->button_7, &QPushButton::clicked, this, &RemoteControl::send7);
    QObject::connect(this->button_8, &QPushButton::clicked, this, &RemoteControl::send8);
    QObject::connect(this->button_9, &QPushButton::clicked, this, &RemoteControl::send9);
    QObject::connect(this->button_0, &QPushButton::clicked, this, &RemoteControl::send0);
    QObject::connect(this->button_BACKWARD, &QPushButton::clicked, this, &RemoteControl::sendBackward);
    QObject::connect(this->button_PLAY, &QPushButton::clicked, this, &RemoteControl::sendPlayPause);
    QObject::connect(this->button_FORWARD, &QPushButton::clicked, this, &RemoteControl::sendForward);
    QObject::connect(this->button_SETTINGS, &QPushButton::clicked, this, &RemoteControl::openSettings);
}

void RemoteControl::applyConfig()
{
    // COLOR UI

    QString widgetColor = "background-color: " + this->rcc->getBackgroundColor().name() + ";";
    this->centralWidget()->setStyleSheet(widgetColor);

    QString buttonColor = "background-color: " + this->rcc->getButtonColor().name() + ";";
    for (std::vector<QPushButton*>::iterator it = this->button_all.begin() ; it != this->button_all.end(); ++it) {
        (*it)->setStyleSheet(buttonColor);
    }

    // SORTCUT

    this->button_ONOFF->setShortcut(QKeySequence( this->rcc->getButtonOnOff() ));
    this->button_SETTINGS->setShortcut(QKeySequence( this->rcc->getButtonSettings() ));
    this->button_NETFLIX->setShortcut(QKeySequence( this->rcc->getButtonNetflix() ));
    this->button_UP->setShortcut(QKeySequence( this->rcc->getButtonUp() ));
    this->button_DOWN->setShortcut(QKeySequence( this->rcc->getButtonDown() ));
    this->button_LEFT->setShortcut(QKeySequence( this->rcc->getButtonLeft() ));
    this->button_RIGHT->setShortcut(QKeySequence( this->rcc->getButtonRight() ));
    this->button_OK->setShortcut(QKeySequence( this->rcc->getButtonOk() ));
    this->button_MENU->setShortcut(QKeySequence( this->rcc->getButtonMenu() ));
    this->button_BACK->setShortcut(QKeySequence( this->rcc->getButtonBack() ));
    this->button_VOLD->setShortcut(QKeySequence( this->rcc->getButtonVolDown() ));
    this->button_VOLU->setShortcut(QKeySequence( this->rcc->getButtonVolUp() ));
    this->button_MENU->setShortcut(QKeySequence( this->rcc->getButtonMenu() ));
    this->button_MUTE->setShortcut(QKeySequence( this->rcc->getButtonMute() ));
    this->button_BACKWARD->setShortcut(QKeySequence( this->rcc->getButtonBackward() ));
    this->button_PLAY->setShortcut(QKeySequence( this->rcc->getButtonPlayPause() ));
    this->button_FORWARD->setShortcut(QKeySequence( this->rcc->getButtonForeward() ));
    this->button_0->setShortcut(QKeySequence( this->rcc->getButton0() ));
    this->button_1->setShortcut(QKeySequence( this->rcc->getButton1() ));
    this->button_2->setShortcut(QKeySequence( this->rcc->getButton2() ));
    this->button_3->setShortcut(QKeySequence( this->rcc->getButton3() ));
    this->button_4->setShortcut(QKeySequence( this->rcc->getButton4() ));
    this->button_5->setShortcut(QKeySequence( this->rcc->getButton5() ));
    this->button_6->setShortcut(QKeySequence( this->rcc->getButton6() ));
    this->button_7->setShortcut(QKeySequence( this->rcc->getButton7() ));
    this->button_8->setShortcut(QKeySequence( this->rcc->getButton8() ));
    this->button_9->setShortcut(QKeySequence( this->rcc->getButton9() ));

    if (this->rcc->getEnableToolTips()) {
        this->setToolTip();
    }

}

void RemoteControl::setToolTip()
{
    this->button_ONOFF->setToolTip( this->rcc->getButtonOnOff() );
    this->button_SETTINGS->setToolTip( this->rcc->getButtonSettings() );
    this->button_NETFLIX->setToolTip( this->rcc->getButtonNetflix() );
    this->button_UP->setToolTip( this->rcc->getButtonUp() );
    this->button_DOWN->setToolTip( this->rcc->getButtonDown() );
    this->button_LEFT->setToolTip( this->rcc->getButtonLeft() );
    this->button_RIGHT->setToolTip( this->rcc->getButtonRight() );
    this->button_OK->setToolTip( this->rcc->getButtonOk() );
    this->button_MENU->setToolTip( this->rcc->getButtonMenu() );
    this->button_BACK->setToolTip( this->rcc->getButtonBack() );
    this->button_VOLD->setToolTip( this->rcc->getButtonVolDown() );
    this->button_VOLU->setToolTip( this->rcc->getButtonVolUp() );
    this->button_MENU->setToolTip( this->rcc->getButtonMenu() );
    this->button_MUTE->setToolTip( this->rcc->getButtonMute() );
    this->button_BACKWARD->setToolTip( this->rcc->getButtonBackward() );
    this->button_PLAY->setToolTip( this->rcc->getButtonPlayPause() );
    this->button_FORWARD->setToolTip( this->rcc->getButtonForeward() );
    this->button_0->setToolTip( this->rcc->getButton0() );
    this->button_1->setToolTip( this->rcc->getButton1() );
    this->button_2->setToolTip( this->rcc->getButton2() );
    this->button_3->setToolTip( this->rcc->getButton3() );
    this->button_4->setToolTip( this->rcc->getButton4() );
    this->button_5->setToolTip( this->rcc->getButton5() );
    this->button_6->setToolTip( this->rcc->getButton6() );
    this->button_7->setToolTip( this->rcc->getButton7() );
    this->button_8->setToolTip( this->rcc->getButton8() );
    this->button_9->setToolTip( this->rcc->getButton9() );
}

void RemoteControl::openSettings()
{
    SettingsDialog *settingsDialog = new SettingsDialog(this->rcc, this->fsi);
    settingsDialog->exec();

    if (settingsDialog->newConfig) {
        this->applyConfig();
    }

}

void RemoteControl::openMenu()
{
    this->sendUniqueKey(139);
}

void RemoteControl::sendUniqueKey(int code)
{
    QString stringCode = QString(std::to_string(code).c_str());
    QString url = "http://" + this->rcc->getIp() + ":" + this->rcc->getPort() + "/remoteControl/cmd?operation=01&key=" + stringCode + "&mode=0";

    reply = this->qnam.get(QNetworkRequest(url));
}

void RemoteControl::sendOnOff()
{
    this->sendUniqueKey(116);
}

void RemoteControl::sendNetflix()
{
    this->sendUniqueKey(518);
    this->sendUniqueKey(518);
}

void RemoteControl::sendUp()
{
    this->sendUniqueKey(103);
}

void RemoteControl::sendLeft()
{
    this->sendUniqueKey(105);
}

void RemoteControl::sendOk()
{
    this->sendUniqueKey(352);
}

void RemoteControl::sendRight()
{
    this->sendUniqueKey(106);
}

void RemoteControl::sendDown()
{
    this->sendUniqueKey(108);
}

void RemoteControl::sendBack()
{
    this->sendUniqueKey(158);
}

void RemoteControl::sendVolD()
{
    this->sendUniqueKey(114);
}

void RemoteControl::sendMute()
{
    this->sendUniqueKey(113);
}

void RemoteControl::sendVolU()
{
    this->sendUniqueKey(115);
}

void RemoteControl::send1()
{
    this->sendUniqueKey(513);
}

void RemoteControl::send2()
{
    this->sendUniqueKey(514);
}

void RemoteControl::send3()
{
    this->sendUniqueKey(515);
}

void RemoteControl::send4()
{
    this->sendUniqueKey(516);
}

void RemoteControl::send5()
{
    this->sendUniqueKey(517);
}

void RemoteControl::send6()
{
    this->sendUniqueKey(518);
}

void RemoteControl::send7()
{
    this->sendUniqueKey(519);
}

void RemoteControl::send8()
{
    this->sendUniqueKey(520);
}

void RemoteControl::send9()
{
    this->sendUniqueKey(521);
}

void RemoteControl::send0()
{
    this->sendUniqueKey(512);
}

void RemoteControl::sendBackward()
{
    this->sendUniqueKey(168);
}

void RemoteControl::sendPlayPause()
{
    this->sendUniqueKey(164);
}

void RemoteControl::sendForward()
{
    this->sendUniqueKey(159);
}

RemoteControl::~RemoteControl()
{
}

