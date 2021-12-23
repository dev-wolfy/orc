#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <QTabWidget>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <QSpacerItem>

#include <QSlider>
#include <QSpinBox>
#include <QColorDialog>
#include <QColor>

#include <QKeySequenceEdit>
#include <QScrollArea>
#include <QCheckBox>

#include "config.h"
#include "filesysteminterface.h"

#include <iostream>

class SettingsDialog : public QDialog
{
public:
    SettingsDialog();
    SettingsDialog(Config *pActualConfig);
    SettingsDialog(Config *pActualConfig, FileSystemInterface *pFsi);

    Config *actualConfig;
    Config tempConfig;

    FileSystemInterface *fsi;

    void initUi();
    void applyActualConfig();
    void applyColorTempConfig();

    QWidget initUiFakeRemoteControl();

    void testNetworkConfig();
    bool isValidIP();
    bool isValidPort();
    void saveNetwork();

    bool newConfig;

    ~SettingsDialog();


    // FAKE REMOTE CONTROL COMPONENTS

    QWidget *remoteControlWidget;

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

    // TABS

    void changeWindowsTitleOnTabClick(int tabindex);

    // NETWORK TAB
    QLineEdit* ipLineEdit;
    QLineEdit* portLineEdit;

    QPushButton *button_testNetworkConfig;
    QPushButton* button_saveNetworkConfig;

    // COLOR TAB
    QSlider *rBackgroundSlider;
    QSlider *gBackgroundSlider;
    QSlider *bBackgroundSlider;
    QSpinBox *rBackgroundSpinBox;
    QSpinBox *gBackgroundSpinBox;
    QSpinBox *bBackgroundSpinBox;
    QPushButton *backgroundColorPicker;
    QLineEdit *backgroundLineEdit;
    QPushButton *backgroundBackToOldColor;
    QPushButton *saveBackgroundColor;

    void addBackgroundColorConnect();
    void delBackgroundColorConnect();
    void valueChangedForBackground();
    void updateBackgroundColorOnUi();
    void backToOldBackgroundColor();
    void saveNewBackgroundColor();

    QSlider *rButtonSlider;
    QSlider *gButtonSlider;
    QSlider *bButtonSlider;
    QSpinBox *rButtonSpinBox;
    QSpinBox *gButtonSpinBox;
    QSpinBox *bButtonSpinBox;
    QPushButton *buttonColorPicker;
    QLineEdit *buttonLineEdit;
    QPushButton *buttonBackToOldColor;
    QPushButton *saveButtonColor;

    void addButtonColorConnect();
    void delButtonColorConnect();
    void valueChangedForButton();
    void updateButtonColorOnUi();
    void backToOldButtonColor();
    void saveNewButtonColor();


    // SHORTCUT TAB
    QScrollArea *sequenceScrollArea;

    QPushButton *miniOnOff;
    QKeySequenceEdit *sequence_ONOFF;
    void sequence_ONOFF_updated();

    QPushButton *miniNetflix;
    QKeySequenceEdit *sequence_NETFLIX;
    void sequence_Netflix_updated();
    QPushButton *miniSettings;
    QKeySequenceEdit *sequence_SETTINGS;
    void sequence_Settings_updated();

    QPushButton *miniUp;
    QKeySequenceEdit *sequence_UP;
    void sequence_Up_updated();
    QPushButton *miniLeft;
    QKeySequenceEdit *sequence_LEFT;
    void sequence_Left_updated();
    QPushButton *miniOk;
    QKeySequenceEdit *sequence_OK;
    void sequence_Ok_updated();
    QPushButton *miniRight;
    QKeySequenceEdit *sequence_RIGHT;
    void sequence_Right_updated();
    QPushButton *miniDown;
    QKeySequenceEdit *sequence_DOWN;
    void sequence_Down_updated();

    QPushButton *miniMenu;
    QKeySequenceEdit *sequence_MENU;
    void sequence_Menu_updated();
    QPushButton *miniBack;
    QKeySequenceEdit *sequence_BACK;
    void sequence_Back_updated();

    QPushButton *miniVold;
    QKeySequenceEdit *sequence_VOLD;
    void sequence_Vold_updated();
    QPushButton *miniMute;
    QKeySequenceEdit *sequence_MUTE;
    void sequence_Mute_updated();
    QPushButton *miniVolu;
    QKeySequenceEdit *sequence_VOLU;
    void sequence_Volu_updated();

    QPushButton *mini1;
    QKeySequenceEdit *sequence_1;
    void sequence_1_updated();
    QPushButton *mini2;
    QKeySequenceEdit *sequence_2;
    void sequence_2_updated();
    QPushButton *mini3;
    QKeySequenceEdit *sequence_3;
    void sequence_3_updated();
    QPushButton *mini4;
    QKeySequenceEdit *sequence_4;
    void sequence_4_updated();
    QPushButton *mini5;
    QKeySequenceEdit *sequence_5;
    void sequence_5_updated();
    QPushButton *mini6;
    QKeySequenceEdit *sequence_6;
    void sequence_6_updated();
    QPushButton *mini7;
    QKeySequenceEdit *sequence_7;
    void sequence_7_updated();
    QPushButton *mini8;
    QKeySequenceEdit *sequence_8;
    void sequence_8_updated();
    QPushButton *mini9;
    QKeySequenceEdit *sequence_9;
    void sequence_9_updated();
    QPushButton *mini0;
    QKeySequenceEdit *sequence_0;
    void sequence_0_updated();

    QPushButton *miniBackward;
    QKeySequenceEdit *sequence_BACKWARD;
    void sequence_Backward_updated();
    QPushButton *miniPlay;
    QKeySequenceEdit *sequence_PLAY;
    void sequence_Play_updated();
    QPushButton *miniForward;
    QKeySequenceEdit *sequence_FORWARD;
    void sequence_Forward_updated();

    QCheckBox *tooltipsCheckBox;
    void updateToolTipCheckBox();

    QPushButton *buttonBackToOldShortcut;
    QPushButton *saveNewShortcut;

    void addSequenceEditConnect();
    void cancelShortcutConfig();
    void saveNewShortcutConfig();


};

#endif // SETTINGSDIALOG_H
