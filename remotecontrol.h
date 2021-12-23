#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include <QMainWindow>

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>

#include <config.h>
#include <settingsdialog.h>
#include <filesysteminterface.h>

#include <iostream>
#include <unistd.h>
#include <vector>

class RemoteControl : public QMainWindow
{
    Q_OBJECT

public:
    RemoteControl(QWidget *parent = nullptr);

    FileSystemInterface *fsi; // FileSystemInterface
    Config *rcc; // RemoteControlConfig

    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    std::unique_ptr<QFile> file;
    bool httpRequestAborted;

    // INIT FUNCTIONS

    void initUi();
    void initQConnect();
    void applyConfig();
    void setToolTip();

    // FUNCTIONS

    void openSettings();
    void openMenu();

    // SEND FUNCTIONS

    void sendUniqueKey(int code);
    void sendOnOff();
    void sendNetflix();
    void sendUp();
    void sendLeft();
    void sendOk();
    void sendRight();
    void sendDown();
    void sendBack();
    void sendVolD();
    void sendMute();
    void sendVolU();
    void send1();
    void send2();
    void send3();
    void send4();
    void send5();
    void send6();
    void send7();
    void send8();
    void send9();
    void send0();
    void sendBackward();
    void sendPlayPause();
    void sendForward();

    ~RemoteControl();


    // UI COMPONENTS
    QWidget* mainWidget;
    QVBoxLayout* mainLayout;

    QPushButton* button_ONOFF;

    QPushButton* button_NETFLIX;
    QPushButton* button_SETTINGS;

    QPushButton* button_UP;
    QPushButton* button_LEFT;
    QPushButton* button_OK;
    QPushButton* button_RIGHT;
    QPushButton* button_DOWN;

    QPushButton* button_MENU;
    QPushButton* button_BACK;

    QPushButton* button_VOLD;
    QPushButton* button_MUTE;
    QPushButton* button_VOLU;

    QPushButton* button_1;
    QPushButton* button_2;
    QPushButton* button_3;
    QPushButton* button_4;
    QPushButton* button_5;
    QPushButton* button_6;
    QPushButton* button_7;
    QPushButton* button_8;
    QPushButton* button_9;
    QPushButton* button_0;

    QPushButton* button_BACKWARD;
    QPushButton* button_PLAY;
    QPushButton* button_FORWARD;

    std::vector<QPushButton*> button_all;

};
#endif // REMOTECONTROL_H
