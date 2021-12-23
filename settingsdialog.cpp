#include "settingsdialog.h"

SettingsDialog::SettingsDialog()
{

}

SettingsDialog::SettingsDialog(Config *pActualConfig, FileSystemInterface *pFsi)
{
    this->actualConfig = pActualConfig;
    this->tempConfig = Config(*this->actualConfig);

    this->fsi = pFsi;

    this->initUi();
    this->applyActualConfig();
    this->addBackgroundColorConnect();
    this->addButtonColorConnect();
    this->addSequenceEditConnect();

    this->newConfig = false;
}

void SettingsDialog::initUi()
{
    QHBoxLayout *mainLayout = new QHBoxLayout();

    // 1) FAKE REMOTE CONTROL

    this->remoteControlWidget = new QWidget();
    QVBoxLayout *mainLayoutFakeRC = new QVBoxLayout();

    // ON OFF BUTTON
    QIcon iconONOFF = QIcon(":/icons/rsc/power-off-solid.svg");
    this->button_ONOFF = new QPushButton(remoteControlWidget);
    this->button_ONOFF->setIcon(iconONOFF);
    this->button_all.push_back(this->button_ONOFF);

    // DIRECTION GRID LAYOUT
    QGridLayout* directionGridLayout = new QGridLayout();

    QIcon iconNETFLIX = QIcon(":/icons/rsc/netflix-icon.svg");
    this->button_NETFLIX = new QPushButton(remoteControlWidget);
    this->button_NETFLIX->setIcon(iconNETFLIX);
    this->button_NETFLIX->setIconSize(QSize(35, 35));
    this->button_NETFLIX->setMaximumSize(40, 40);
    this->button_NETFLIX->setMinimumSize(40, 40);
    //this->button_NETFLIX->setShortcut(QKeySequence(Qt::Key_N));
    this->button_all.push_back(this->button_NETFLIX);

    QIcon iconUP = QIcon(":/icons/rsc/chevron-up-solid.svg");
    this->button_UP = new QPushButton();
    this->button_UP->setIcon(iconUP);
    this->button_UP->setMaximumSize(50, 50);
    this->button_UP->setMinimumSize(50, 50);
    //this->button_UP->setShortcut(QKeySequence(Qt::Key_Z));
    this->button_all.push_back(this->button_UP);

    QIcon iconSettings = QIcon(":/icons/rsc/cog-solid.svg");
    this->button_SETTINGS = new QPushButton();
    this->button_SETTINGS->setIcon(iconSettings);
    this->button_SETTINGS->setMaximumSize(40,40);
    this->button_SETTINGS->setMinimumSize(40,40);
    //this->button_SETTINGS->setShortcut(QKeySequence(Qt::Key_P));
    this->button_all.push_back(this->button_SETTINGS);

    QIcon iconLEFT = QIcon(":/icons/rsc/chevron-left-solid.svg");
    this->button_LEFT = new QPushButton();
    this->button_LEFT->setIcon(iconLEFT);
    this->button_LEFT->setMaximumSize(50, 50);
    this->button_LEFT->setMinimumSize(50, 50);
    this->button_LEFT->setShortcut(QKeySequence(Qt::Key_Q));
    this->button_all.push_back(this->button_LEFT);

    QIcon iconOK = QIcon(":/icons/rsc/check-circle-solid.svg");
    this->button_OK = new QPushButton();
    this->button_OK->setIcon(iconOK);
    this->button_OK->setMaximumSize(50, 50);
    this->button_OK->setMinimumSize(50, 50);
    //this->button_OK->setShortcut(QKeySequence(Qt::Key_E));
    this->button_all.push_back(this->button_OK);

    QIcon iconRIGTH = QIcon(":/icons/rsc/chevron-right-solid.svg");
    this->button_RIGHT = new QPushButton();
    this->button_RIGHT->setIcon(iconRIGTH);
    this->button_RIGHT->setMaximumSize(50, 50);
    this->button_RIGHT->setMinimumSize(50, 50);
    //this->button_RIGHT->setShortcut(QKeySequence(Qt::Key_D));
    this->button_all.push_back(this->button_RIGHT);

    QIcon iconBOTTOM = QIcon(":/icons/rsc/chevron-down-solid.svg");
    this->button_DOWN = new QPushButton();
    this->button_DOWN->setIcon(iconBOTTOM);
    this->button_DOWN->setMaximumSize(50, 50);
    this->button_DOWN->setMinimumSize(50, 50);
    //this->button_DOWN->setShortcut(QKeySequence(Qt::Key_S));
    this->button_all.push_back(this->button_DOWN);

    QIcon iconMENU = QIcon(":/icons/rsc/bars-solid.svg");
    this->button_MENU = new QPushButton();
    this->button_MENU->setIcon(iconMENU);
    this->button_MENU->setMaximumSize(40, 40);
    this->button_MENU->setMinimumSize(40, 40);
    //this->button_MENU->setShortcut(QKeySequence(Qt::Key_M));
    this->button_all.push_back(this->button_MENU);

    QIcon iconBACK = QIcon(":/icons/rsc/undo-alt-solid.svg");
    this->button_BACK = new QPushButton();
    this->button_BACK->setIcon(iconBACK);
    this->button_BACK->setMaximumSize(40, 40);
    this->button_BACK->setMinimumSize(40, 40);
    //this->button_BACK->setShortcut(QKeySequence(Qt::Key_Backspace));
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
    //this->button_VOLD->setShortcut(QKeySequence(Qt::Key_Down));
    this->button_all.push_back(this->button_VOLD);

    QIcon iconMUTE = QIcon(":/icons/rsc/volume-mute-solid.svg");
    this->button_MUTE = new QPushButton();
    this->button_MUTE->setIcon(iconMUTE);
    //this->button_MUTE->setShortcut(QKeySequence(Qt::Key_T));
    this->button_all.push_back(this->button_MUTE);

    QIcon iconVOLU = QIcon(":/icons/rsc/volume-up-solid.svg");
    this->button_VOLU = new QPushButton();
    this->button_VOLU->setIcon(iconVOLU);
    //this->button_VOLU->setShortcut(QKeySequence(Qt::Key_Up));
    this->button_all.push_back(this->button_VOLU);

    volumeHorizontalLayout->addWidget(this->button_VOLD);
    volumeHorizontalLayout->addWidget(this->button_MUTE);
    volumeHorizontalLayout->addWidget(this->button_VOLU);

    // NUMBER SECTION
    QGridLayout* numberGridLayout = new QGridLayout();

    this->button_0 = new QPushButton("0", this);
    //this->button_0->setShortcut(QKeySequence(Qt::Key_0));
    this->button_0->setMinimumSize(40,40);
    this->button_0->setMaximumSize(40,40);
    this->button_all.push_back(this->button_0);

    this->button_1 = new QPushButton("1", this);
    //this->button_1->setShortcut(QKeySequence(Qt::Key_1));
    this->button_1->setMinimumSize(40,40);
    this->button_1->setMaximumSize(40,40);
    this->button_all.push_back(this->button_1);

    this->button_2 = new QPushButton("2", this);
    //this->button_2->setShortcut(QKeySequence(Qt::Key_2));
    this->button_2->setMinimumSize(40,40);
    this->button_2->setMaximumSize(40,40);
    this->button_all.push_back(this->button_2);

    this->button_3 = new QPushButton("3", this);
    //this->button_3->setShortcut(QKeySequence(Qt::Key_3));
    this->button_3->setMinimumSize(40,40);
    this->button_3->setMaximumSize(40,40);
    this->button_all.push_back(this->button_3);

    this->button_4 = new QPushButton("4", this);
    //this->button_4->setShortcut(QKeySequence(Qt::Key_4));
    this->button_4->setMinimumSize(40,40);
    this->button_4->setMaximumSize(40,40);
    this->button_all.push_back(this->button_4);

    this->button_5 = new QPushButton("5", this);
    //this->button_5->setShortcut(QKeySequence(Qt::Key_5));
    this->button_5->setMinimumSize(40,40);
    this->button_5->setMaximumSize(40,40);
    this->button_all.push_back(this->button_5);

    this->button_6 = new QPushButton("6", this);
    //this->button_6->setShortcut(QKeySequence(Qt::Key_6));
    this->button_6->setMinimumSize(40,40);
    this->button_6->setMaximumSize(40,40);
    this->button_all.push_back(this->button_6);

    this->button_7 = new QPushButton("7", this);
    //this->button_7->setShortcut(QKeySequence(Qt::Key_7));
    this->button_7->setMinimumSize(40,40);
    this->button_7->setMaximumSize(40,40);
    this->button_all.push_back(this->button_7);

    this->button_8 = new QPushButton("8", this);
    //this->button_8->setShortcut(QKeySequence(Qt::Key_8));
    this->button_8->setMinimumSize(40,40);
    this->button_8->setMaximumSize(40,40);
    this->button_all.push_back(this->button_8);

    this->button_9 = new QPushButton("9", this);
    //this->button_9->setShortcut(QKeySequence(Qt::Key_9));
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
    //this->button_BACKWARD->setShortcut(QKeySequence(Qt::Key_Left));
    this->button_all.push_back(this->button_BACKWARD);

    QIcon iconPLAY = QIcon(":/icons/rsc/play-solid.svg");
    this->button_PLAY = new QPushButton();
    this->button_PLAY->setIcon(iconPLAY);
    //this->button_PLAY->setShortcut(QKeySequence(Qt::Key_Space));
    this->button_all.push_back(this->button_PLAY);

    QIcon iconFORWARD = QIcon(":/icons/rsc/forward-solid.svg");
    this->button_FORWARD = new QPushButton();
    this->button_FORWARD->setIcon(iconFORWARD);
    //this->button_FORWARD->setShortcut(QKeySequence(Qt::Key_Right));
    this->button_all.push_back(this->button_FORWARD);

    lectureHorizontalLayout->addWidget(this->button_BACKWARD);
    lectureHorizontalLayout->addWidget(this->button_PLAY);
    lectureHorizontalLayout->addWidget(this->button_FORWARD);

    // FINAL INIT - ADD ALL SECTIONS
    mainLayoutFakeRC->addWidget(this->button_ONOFF);
    mainLayoutFakeRC->addLayout(directionGridLayout);
    mainLayoutFakeRC->addLayout(volumeHorizontalLayout);
    mainLayoutFakeRC->addLayout(numberGridLayout);
    mainLayoutFakeRC->addLayout(lectureHorizontalLayout);

    remoteControlWidget->setLayout(mainLayoutFakeRC);


    // 2) CONFIG TABS
    QTabWidget *configTabWidget = new QTabWidget();
    QObject::connect(configTabWidget, &QTabWidget::currentChanged, this, &SettingsDialog::changeWindowsTitleOnTabClick);


    // NETWORK TAB
    QWidget *networkConfigTab = new QWidget();

    QVBoxLayout *networkConfigTabMainLayout = new QVBoxLayout();

    // Network Group Box
    QGroupBox *networkConfigGroupBox = new QGroupBox("Network Config", networkConfigTab);

    QVBoxLayout *innerGroupBoxLayout = new QVBoxLayout();

    // Label + LineEdit
    QHBoxLayout *labelPortLineEditLayout = new QHBoxLayout();

    // Label
    QVBoxLayout *labelLayout = new QVBoxLayout();
    QLabel *ipLabel = new QLabel("IP : ");
    QLabel *portLabel = new QLabel("Port : ");
    labelLayout->addWidget(ipLabel);
    labelLayout->addWidget(portLabel);

    labelPortLineEditLayout->addLayout(labelLayout);

    // LineEdit
    QVBoxLayout *lineEditLayout = new QVBoxLayout();
    this->ipLineEdit = new QLineEdit();
    this->ipLineEdit->setPlaceholderText("192.168.1.10");
    this->portLineEdit = new QLineEdit();
    this->portLineEdit->setPlaceholderText("8080");
    lineEditLayout->addWidget(this->ipLineEdit);
    lineEditLayout->addWidget(this->portLineEdit);

    labelPortLineEditLayout->addLayout(lineEditLayout);

    // Buttons
    QHBoxLayout *buttonsNetworkConfigTab = new QHBoxLayout();
    this->button_testNetworkConfig = new QPushButton();
    this->button_testNetworkConfig->setText("Test");
    QIcon questionIcon = QIcon(":/icons/rsc/question-solid.svg");
    this->button_testNetworkConfig->setIcon(questionIcon);
    QObject::connect(this->button_testNetworkConfig, &QPushButton::clicked, this, &SettingsDialog::testNetworkConfig);

    this->button_saveNetworkConfig = new QPushButton();
    this->button_saveNetworkConfig->setText("Save");
    QIcon saveIcon = QIcon(":/icons/rsc/save-solid.svg");
    this->button_saveNetworkConfig->setIcon(saveIcon);
    QObject::connect(this->button_saveNetworkConfig, &QPushButton::clicked, this, &SettingsDialog::saveNetwork);

    buttonsNetworkConfigTab->addWidget(this->button_testNetworkConfig);
    buttonsNetworkConfigTab->addWidget(this->button_saveNetworkConfig);

    innerGroupBoxLayout->addLayout(labelPortLineEditLayout);
    innerGroupBoxLayout->addLayout(buttonsNetworkConfigTab);

    networkConfigGroupBox->setLayout(innerGroupBoxLayout);

    networkConfigTabMainLayout->addWidget(networkConfigGroupBox);
    networkConfigTabMainLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Expanding));

    networkConfigTab->setLayout(networkConfigTabMainLayout);


    // COLOR TAB
    QWidget *colorConfigTab = new QWidget();

    QVBoxLayout *colorConfigTabMainLayout = new QVBoxLayout();

    // background color

    QGroupBox *backgroundGroupBox = new QGroupBox("Background color");

    QHBoxLayout *mainBackgroundLayout = new QHBoxLayout();

    QVBoxLayout *sliderSpinBoxBackgroundLayout = new QVBoxLayout();

    // r background slider + spinbox

    QHBoxLayout *rBackgroundSliderSpinBoxLayout = new QHBoxLayout();

    this->rBackgroundSlider = new QSlider(Qt::Horizontal);
    this->rBackgroundSlider->setMinimum(0);
    this->rBackgroundSlider->setMaximum(255);
    this->rBackgroundSlider->setTickInterval(1);

    this->rBackgroundSpinBox = new QSpinBox();
    this->rBackgroundSpinBox->setMinimum(0);
    this->rBackgroundSpinBox->setMaximum(255);

    rBackgroundSliderSpinBoxLayout->addWidget(this->rBackgroundSlider);
    rBackgroundSliderSpinBoxLayout->addWidget(this->rBackgroundSpinBox);

    sliderSpinBoxBackgroundLayout->addLayout(rBackgroundSliderSpinBoxLayout);

    // g background slider + spinbox

    QHBoxLayout *gBackgroundSliderSpinBoxLayout = new QHBoxLayout();

    this->gBackgroundSlider = new QSlider(Qt::Horizontal);
    this->gBackgroundSlider->setMinimum(0);
    this->gBackgroundSlider->setMaximum(255);
    this->gBackgroundSlider->setTickInterval(1);

    this->gBackgroundSpinBox = new QSpinBox();
    this->gBackgroundSpinBox->setMinimum(0);
    this->gBackgroundSpinBox->setMaximum(255);

    gBackgroundSliderSpinBoxLayout->addWidget(this->gBackgroundSlider);
    gBackgroundSliderSpinBoxLayout->addWidget(this->gBackgroundSpinBox);

    sliderSpinBoxBackgroundLayout->addLayout(gBackgroundSliderSpinBoxLayout);

    // b background slider + spinbox

    QHBoxLayout *bBackgroundSliderSpinBoxLayout = new QHBoxLayout();

    this->bBackgroundSlider = new QSlider(Qt::Horizontal);
    this->bBackgroundSlider->setMinimum(0);
    this->bBackgroundSlider->setMaximum(255);
    this->bBackgroundSlider->setTickInterval(1);

    this->bBackgroundSpinBox = new QSpinBox();
    this->bBackgroundSpinBox->setMinimum(0);
    this->bBackgroundSpinBox->setMaximum(255);

    bBackgroundSliderSpinBoxLayout->addWidget(this->bBackgroundSlider);
    bBackgroundSliderSpinBoxLayout->addWidget(this->bBackgroundSpinBox);

    sliderSpinBoxBackgroundLayout->addLayout(bBackgroundSliderSpinBoxLayout);

    // end

    QVBoxLayout *colorNameBackgroundLayout = new QVBoxLayout();

    this->backgroundColorPicker = new QPushButton();
    this->backgroundColorPicker->setMaximumWidth(65);
    this->backgroundColorPicker->setMinimumHeight(58);
    this->backgroundLineEdit = new QLineEdit();
    this->backgroundLineEdit->setMaximumWidth(65);

    colorNameBackgroundLayout->addWidget(this->backgroundColorPicker);
    colorNameBackgroundLayout->addWidget(this->backgroundLineEdit);

    mainBackgroundLayout->addLayout(sliderSpinBoxBackgroundLayout);
    mainBackgroundLayout->addLayout(colorNameBackgroundLayout);

    backgroundGroupBox->setLayout(mainBackgroundLayout);

    colorConfigTabMainLayout->addWidget(backgroundGroupBox);



    QHBoxLayout *backOrSaveBackgroundColorLayout = new QHBoxLayout();
    this->backgroundBackToOldColor = new QPushButton("Cancel");
    this->backgroundBackToOldColor->setIcon(iconBACK);
    QObject::connect(this->backgroundBackToOldColor, &QPushButton::clicked, this, &SettingsDialog::backToOldBackgroundColor);
    this->saveBackgroundColor = new QPushButton("Save");
    QIcon iconSave = QIcon(":/icons/rsc/save-solid.svg");
    this->saveBackgroundColor->setIcon(iconSave);
    QObject::connect(this->saveBackgroundColor, &QPushButton::clicked, this, &SettingsDialog::saveNewBackgroundColor);
    backOrSaveBackgroundColorLayout->addWidget(this->backgroundBackToOldColor);
    backOrSaveBackgroundColorLayout->addWidget(this->saveBackgroundColor);

    colorConfigTabMainLayout->addLayout(backOrSaveBackgroundColorLayout);



    // button color

    QGroupBox *buttonGroupBox = new QGroupBox("Buttons color");

    QHBoxLayout *mainButtonLayout = new QHBoxLayout();

    QVBoxLayout *sliderSpinBoxButtonLayout = new QVBoxLayout();

    // r Button slider + spinbox

    QHBoxLayout *rButtonSliderSpinBoxLayout = new QHBoxLayout();

    this->rButtonSlider = new QSlider(Qt::Horizontal);
    this->rButtonSlider->setMinimum(0);
    this->rButtonSlider->setMaximum(255);
    this->rButtonSlider->setTickInterval(1);

    this->rButtonSpinBox = new QSpinBox();
    this->rButtonSpinBox->setMinimum(0);
    this->rButtonSpinBox->setMaximum(255);

    rButtonSliderSpinBoxLayout->addWidget(this->rButtonSlider);
    rButtonSliderSpinBoxLayout->addWidget(this->rButtonSpinBox);

    sliderSpinBoxButtonLayout->addLayout(rButtonSliderSpinBoxLayout);

    // g Button slider + spinbox

    QHBoxLayout *gButtonSliderSpinBoxLayout = new QHBoxLayout();

    this->gButtonSlider = new QSlider(Qt::Horizontal);
    this->gButtonSlider->setMinimum(0);
    this->gButtonSlider->setMaximum(255);
    this->gButtonSlider->setTickInterval(1);

    this->gButtonSpinBox = new QSpinBox();
    this->gButtonSpinBox->setMinimum(0);
    this->gButtonSpinBox->setMaximum(255);

    gButtonSliderSpinBoxLayout->addWidget(this->gButtonSlider);
    gButtonSliderSpinBoxLayout->addWidget(this->gButtonSpinBox);

    sliderSpinBoxButtonLayout->addLayout(gButtonSliderSpinBoxLayout);

    // b background slider + spinbox

    QHBoxLayout *bButtonSliderSpinBoxLayout = new QHBoxLayout();

    this->bButtonSlider = new QSlider(Qt::Horizontal);
    this->bButtonSlider->setMinimum(0);
    this->bButtonSlider->setMaximum(255);
    this->bButtonSlider->setTickInterval(1);

    this->bButtonSpinBox = new QSpinBox();
    this->bButtonSpinBox->setMinimum(0);
    this->bButtonSpinBox->setMaximum(255);

    bButtonSliderSpinBoxLayout->addWidget(this->bButtonSlider);
    bButtonSliderSpinBoxLayout->addWidget(this->bButtonSpinBox);

    sliderSpinBoxButtonLayout->addLayout(bButtonSliderSpinBoxLayout);

    // color picker

    QVBoxLayout *colorNameButtonLayout = new QVBoxLayout();

    this->buttonColorPicker = new QPushButton();
    this->buttonColorPicker->setMaximumWidth(65);
    this->buttonColorPicker->setMinimumHeight(58);
    this->buttonLineEdit = new QLineEdit();
    this->buttonLineEdit->setMaximumWidth(65);

    colorNameButtonLayout->addWidget(this->buttonColorPicker);
    colorNameButtonLayout->addWidget(this->buttonLineEdit);

    mainButtonLayout->addLayout(sliderSpinBoxButtonLayout);
    mainButtonLayout->addLayout(colorNameButtonLayout);

    buttonGroupBox->setLayout(mainButtonLayout);

    colorConfigTabMainLayout->addWidget(buttonGroupBox);


    QHBoxLayout *backOrSaveButtonColorLayout = new QHBoxLayout();
    this->buttonBackToOldColor = new QPushButton("Cancel");
    this->buttonBackToOldColor->setIcon(iconBACK);
    QObject::connect(this->buttonBackToOldColor, &QPushButton::clicked, this, &SettingsDialog::backToOldButtonColor);

    this->saveButtonColor = new QPushButton("Save");
    this->saveButtonColor->setIcon(iconSave);
    QObject::connect(this->saveButtonColor, &QPushButton::clicked, this, &SettingsDialog::saveNewButtonColor);

    backOrSaveButtonColorLayout->addWidget(this->buttonBackToOldColor);
    backOrSaveButtonColorLayout->addWidget(this->saveButtonColor);

    colorConfigTabMainLayout->addLayout(backOrSaveButtonColorLayout);


    // end

    colorConfigTabMainLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Expanding));
    colorConfigTab->setLayout(colorConfigTabMainLayout);

    // SHORTCUT TAB
    QWidget *shortcutConfigTab = new QWidget();

    QVBoxLayout *shortcutMainLayout = new QVBoxLayout();

    // groupe box keysequence edit
    QGroupBox *shortcutKeySequenceGroupBox = new QGroupBox();
    shortcutKeySequenceGroupBox->setTitle("Edit Shortcuts");

    QVBoxLayout *keySequenceGroupBoxLayout = new QVBoxLayout();

    QScrollArea *keySequenceEditScrollArea = new QScrollArea();
    keySequenceEditScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    keySequenceEditScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    keySequenceEditScrollArea->setWidgetResizable(true);


    QWidget *innerWidgetOfScrollArea = new QWidget();

    QVBoxLayout *innerScrollAreaLayout = new QVBoxLayout();


    QHBoxLayout *onoffKeySequenceLayout = new QHBoxLayout();
    this->miniOnOff = new QPushButton();
    this->miniOnOff->setIcon(iconONOFF);
    this->sequence_ONOFF = new QKeySequenceEdit();
    onoffKeySequenceLayout->addWidget(this->miniOnOff);
    onoffKeySequenceLayout->addWidget(this->sequence_ONOFF);
    innerScrollAreaLayout->addLayout(onoffKeySequenceLayout);

    QHBoxLayout *netflixKeySequenceLayout = new QHBoxLayout();
    this->miniNetflix = new QPushButton();
    this->miniNetflix->setIcon(iconNETFLIX);
    this->sequence_NETFLIX = new QKeySequenceEdit();
    netflixKeySequenceLayout->addWidget(this->miniNetflix);
    netflixKeySequenceLayout->addWidget(this->sequence_NETFLIX);
    innerScrollAreaLayout->addLayout(netflixKeySequenceLayout);

    QHBoxLayout *settingsKeySequenceLayout = new QHBoxLayout();
    this->miniSettings = new QPushButton();
    this->miniSettings->setIcon(iconSettings);
    this->sequence_SETTINGS = new QKeySequenceEdit();
    settingsKeySequenceLayout->addWidget(this->miniSettings);
    settingsKeySequenceLayout->addWidget(this->sequence_SETTINGS);
    innerScrollAreaLayout->addLayout(settingsKeySequenceLayout);

    QHBoxLayout *upKeySequenceLayout = new QHBoxLayout();
    this->miniUp = new QPushButton();
    this->miniUp->setIcon(iconUP);
    this->sequence_UP = new QKeySequenceEdit();
    upKeySequenceLayout->addWidget(this->miniUp);
    upKeySequenceLayout->addWidget(this->sequence_UP);
    innerScrollAreaLayout->addLayout(upKeySequenceLayout);

    QHBoxLayout *downKeySequenceLayout = new QHBoxLayout();
    this->miniDown = new QPushButton();
    this->miniDown->setIcon(iconBOTTOM);
    this->sequence_DOWN = new QKeySequenceEdit();
    downKeySequenceLayout->addWidget(this->miniDown);
    downKeySequenceLayout->addWidget(this->sequence_DOWN);
    innerScrollAreaLayout->addLayout(downKeySequenceLayout);

    QHBoxLayout *okKeySequenceLayout = new QHBoxLayout();
    this->miniOk = new QPushButton();
    this->miniOk->setIcon(iconOK);
    this->sequence_OK = new QKeySequenceEdit();
    okKeySequenceLayout->addWidget(this->miniOk);
    okKeySequenceLayout->addWidget(this->sequence_OK);
    innerScrollAreaLayout->addLayout(okKeySequenceLayout);

    QHBoxLayout *leftKeySequenceLayout = new QHBoxLayout();
    this->miniLeft = new QPushButton();
    this->miniLeft->setIcon(iconLEFT);
    this->sequence_LEFT = new QKeySequenceEdit();
    leftKeySequenceLayout->addWidget(this->miniLeft);
    leftKeySequenceLayout->addWidget(this->sequence_LEFT);
    innerScrollAreaLayout->addLayout(leftKeySequenceLayout);

    QHBoxLayout *rightKeySequenceLayout = new QHBoxLayout();
    this->miniRight = new QPushButton();
    this->miniRight->setIcon(iconRIGTH);
    this->sequence_RIGHT = new QKeySequenceEdit();
    rightKeySequenceLayout->addWidget(this->miniRight);
    rightKeySequenceLayout->addWidget(this->sequence_RIGHT);
    innerScrollAreaLayout->addLayout(rightKeySequenceLayout);

    QHBoxLayout *menuKeySequenceLayout = new QHBoxLayout();
    this->miniMenu = new QPushButton();
    this->miniMenu->setIcon(iconMENU);
    this->sequence_MENU = new QKeySequenceEdit();
    menuKeySequenceLayout->addWidget(this->miniMenu);
    menuKeySequenceLayout->addWidget(this->sequence_MENU);
    innerScrollAreaLayout->addLayout(menuKeySequenceLayout);

    QHBoxLayout *backKeySequenceLayout = new QHBoxLayout();
    this->miniBack = new QPushButton();
    this->miniBack->setIcon(iconBACK);
    this->sequence_BACK = new QKeySequenceEdit();
    backKeySequenceLayout->addWidget(this->miniBack);
    backKeySequenceLayout->addWidget(this->sequence_BACK);
    innerScrollAreaLayout->addLayout(backKeySequenceLayout);

    QHBoxLayout *voldKeySequenceLayout = new QHBoxLayout();
    this->miniVold = new QPushButton();
    this->miniVold->setIcon(iconVOLD);
    this->sequence_VOLD = new QKeySequenceEdit();
    voldKeySequenceLayout->addWidget(this->miniVold);
    voldKeySequenceLayout->addWidget(this->sequence_VOLD);
    innerScrollAreaLayout->addLayout(voldKeySequenceLayout);

    QHBoxLayout *muteKeySequenceLayout = new QHBoxLayout();
    this->miniMute = new QPushButton();
    this->miniMute->setIcon(iconMUTE);
    this->sequence_MUTE = new QKeySequenceEdit();
    muteKeySequenceLayout->addWidget(this->miniMute);
    muteKeySequenceLayout->addWidget(this->sequence_MUTE);
    innerScrollAreaLayout->addLayout(muteKeySequenceLayout);

    QHBoxLayout *voluKeySequenceLayout = new QHBoxLayout();
    this->miniVolu = new QPushButton();
    this->miniVolu->setIcon(iconVOLU);
    this->sequence_VOLU = new QKeySequenceEdit();
    voluKeySequenceLayout->addWidget(this->miniVolu);
    voluKeySequenceLayout->addWidget(this->sequence_VOLU);
    innerScrollAreaLayout->addLayout(voluKeySequenceLayout);

    QHBoxLayout *l1KeySequenceLayout = new QHBoxLayout();
    this->mini1 = new QPushButton();
    this->mini1->setText("1");
    this->mini1->setMaximumWidth(28);
    this->sequence_1 = new QKeySequenceEdit();
    l1KeySequenceLayout->addWidget(this->mini1);
    l1KeySequenceLayout->addWidget(this->sequence_1);
    innerScrollAreaLayout->addLayout(l1KeySequenceLayout);

    QHBoxLayout *l2KeySequenceLayout = new QHBoxLayout();
    this->mini2 = new QPushButton();
    this->mini2->setText("2");
    this->mini2->setMaximumWidth(28);
    this->sequence_2 = new QKeySequenceEdit();
    l2KeySequenceLayout->addWidget(this->mini2);
    l2KeySequenceLayout->addWidget(this->sequence_2);
    innerScrollAreaLayout->addLayout(l2KeySequenceLayout);

    QHBoxLayout *l3KeySequenceLayout = new QHBoxLayout();
    this->mini3 = new QPushButton();
    this->mini3->setText("3");
    this->mini3->setMaximumWidth(28);
    this->sequence_3 = new QKeySequenceEdit();
    l3KeySequenceLayout->addWidget(this->mini3);
    l3KeySequenceLayout->addWidget(this->sequence_3);
    innerScrollAreaLayout->addLayout(l3KeySequenceLayout);

    QHBoxLayout *l4KeySequenceLayout = new QHBoxLayout();
    this->mini4 = new QPushButton();
    this->mini4->setText("4");
    this->mini4->setMaximumWidth(28);
    this->sequence_4 = new QKeySequenceEdit();
    l4KeySequenceLayout->addWidget(this->mini4);
    l4KeySequenceLayout->addWidget(this->sequence_4);
    innerScrollAreaLayout->addLayout(l4KeySequenceLayout);

    QHBoxLayout *l5KeySequenceLayout = new QHBoxLayout();
    this->mini5 = new QPushButton();
    this->mini5->setText("5");
    this->mini5->setMaximumWidth(28);
    this->sequence_5 = new QKeySequenceEdit();
    l5KeySequenceLayout->addWidget(this->mini5);
    l5KeySequenceLayout->addWidget(this->sequence_5);
    innerScrollAreaLayout->addLayout(l5KeySequenceLayout);

    QHBoxLayout *l6KeySequenceLayout = new QHBoxLayout();
    this->mini6 = new QPushButton();
    this->mini6->setText("6");
    this->mini6->setMaximumWidth(28);
    this->sequence_6 = new QKeySequenceEdit();
    l6KeySequenceLayout->addWidget(this->mini6);
    l6KeySequenceLayout->addWidget(this->sequence_6);
    innerScrollAreaLayout->addLayout(l6KeySequenceLayout);

    QHBoxLayout *l7KeySequenceLayout = new QHBoxLayout();
    this->mini7 = new QPushButton();
    this->mini7->setText("7");
    this->mini7->setMaximumWidth(28);
    this->sequence_7 = new QKeySequenceEdit();
    l7KeySequenceLayout->addWidget(this->mini7);
    l7KeySequenceLayout->addWidget(this->sequence_7);
    innerScrollAreaLayout->addLayout(l7KeySequenceLayout);

    QHBoxLayout *l8KeySequenceLayout = new QHBoxLayout();
    this->mini8 = new QPushButton();
    this->mini8->setText("8");
    this->mini8->setMaximumWidth(28);
    this->sequence_8 = new QKeySequenceEdit();
    l8KeySequenceLayout->addWidget(this->mini8);
    l8KeySequenceLayout->addWidget(this->sequence_8);
    innerScrollAreaLayout->addLayout(l8KeySequenceLayout);

    QHBoxLayout *l9KeySequenceLayout = new QHBoxLayout();
    this->mini9 = new QPushButton();
    this->mini9->setText("9");
    this->mini9->setMaximumWidth(28);
    this->sequence_9 = new QKeySequenceEdit();
    l9KeySequenceLayout->addWidget(this->mini9);
    l9KeySequenceLayout->addWidget(this->sequence_9);
    innerScrollAreaLayout->addLayout(l9KeySequenceLayout);

    QHBoxLayout *l0KeySequenceLayout = new QHBoxLayout();
    this->mini0 = new QPushButton();
    this->mini0->setText("0");
    this->mini0->setMaximumWidth(28);
    this->sequence_0 = new QKeySequenceEdit();
    l0KeySequenceLayout->addWidget(this->mini0);
    l0KeySequenceLayout->addWidget(this->sequence_0);
    innerScrollAreaLayout->addLayout(l0KeySequenceLayout);

    QHBoxLayout *backwardKeySequenceLayout = new QHBoxLayout();
    this->miniBackward = new QPushButton();
    this->miniBackward->setIcon(iconBACKWARD);
    this->sequence_BACKWARD = new QKeySequenceEdit();
    backwardKeySequenceLayout->addWidget(this->miniBackward);
    backwardKeySequenceLayout->addWidget(this->sequence_BACKWARD);
    innerScrollAreaLayout->addLayout(backwardKeySequenceLayout);

    QHBoxLayout *playKeySequenceLayout = new QHBoxLayout();
    this->miniPlay = new QPushButton();
    this->miniPlay->setIcon(iconPLAY);
    this->sequence_PLAY = new QKeySequenceEdit();
    playKeySequenceLayout->addWidget(this->miniPlay);
    playKeySequenceLayout->addWidget(this->sequence_PLAY);
    innerScrollAreaLayout->addLayout(playKeySequenceLayout);

    QHBoxLayout *forwardKeySequenceLayout = new QHBoxLayout();
    this->miniForward = new QPushButton();
    this->miniForward->setIcon(iconFORWARD);
    this->sequence_FORWARD = new QKeySequenceEdit();
    forwardKeySequenceLayout->addWidget(this->miniForward);
    forwardKeySequenceLayout->addWidget(this->sequence_FORWARD);
    innerScrollAreaLayout->addLayout(forwardKeySequenceLayout);

    innerWidgetOfScrollArea->setLayout(innerScrollAreaLayout);

    keySequenceEditScrollArea->setWidget(innerWidgetOfScrollArea);

    keySequenceGroupBoxLayout->addWidget(keySequenceEditScrollArea);

    shortcutKeySequenceGroupBox->setLayout(keySequenceGroupBoxLayout);

    shortcutMainLayout->addWidget(shortcutKeySequenceGroupBox);


    QGroupBox *toolTypeGroupBox = new QGroupBox("Tools Tips", this);

    QHBoxLayout *toolTipLayout = new QHBoxLayout(toolTypeGroupBox);

    this->tooltipsCheckBox = new QCheckBox("Enable tools tips with shortcuts", toolTypeGroupBox);
    if (actualConfig->getEnableToolTips()) {
        this->tooltipsCheckBox->setChecked(true);
    }
    QObject::connect(this->tooltipsCheckBox, &QCheckBox::clicked, this, &SettingsDialog::updateToolTipCheckBox);

    toolTipLayout->addWidget(this->tooltipsCheckBox);

    toolTypeGroupBox->setLayout(toolTipLayout);

    shortcutMainLayout->addWidget(toolTypeGroupBox);


    QHBoxLayout *backOrSaveShortcutLayout = new QHBoxLayout();

    this->buttonBackToOldShortcut = new QPushButton("Cancel");
    this->buttonBackToOldShortcut->setIcon(iconBACK);
    backOrSaveShortcutLayout->addWidget(this->buttonBackToOldShortcut);

    this->saveNewShortcut = new QPushButton("Apply");
    this->saveNewShortcut->setIcon(iconSave);
    backOrSaveShortcutLayout->addWidget(this->saveNewShortcut);


    shortcutMainLayout->addLayout(backOrSaveShortcutLayout);


    shortcutConfigTab->setLayout(shortcutMainLayout);


    // FINAL INIT CONFIG TABWIDGET

    configTabWidget->addTab(networkConfigTab, "Network");
    configTabWidget->addTab(colorConfigTab, "Color");
    configTabWidget->addTab(shortcutConfigTab, "Shortcut");

    // FINAL INIT - ADD FAKE REMOTE CONTROL + CONFIG TABS
    mainLayout->addWidget(remoteControlWidget);
    mainLayout->addWidget(configTabWidget);
    this->setLayout(mainLayout);

}

void SettingsDialog::applyActualConfig()
{

    // Remote Control Color
    this->remoteControlWidget->setStyleSheet("background-color: " + this->actualConfig->getBackgroundColor().name() + ";");

    for (std::vector<QPushButton*>::iterator it = this->button_all.begin() ; it != this->button_all.end(); ++it) {
        (*it)->setStyleSheet("background-color: " + this->actualConfig->getButtonColor().name() + ";");
    }

    // Network Config
    this->ipLineEdit->setText(this->tempConfig.getIp());
    this->portLineEdit->setText(this->tempConfig.getPort());

    // Color Config
    this->backgroundColorPicker->setStyleSheet("background-color: " + this->actualConfig->getBackgroundColor().name() + ";");
    this->backgroundLineEdit->setText(this->actualConfig->getBackgroundColor().name());
    this->rBackgroundSlider->setValue(this->actualConfig->getBackgroundColor().red());
    this->gBackgroundSlider->setValue(this->actualConfig->getBackgroundColor().green());
    this->bBackgroundSlider->setValue(this->actualConfig->getBackgroundColor().blue());
    this->rBackgroundSpinBox->setValue(this->actualConfig->getBackgroundColor().red());
    this->gBackgroundSpinBox->setValue(this->actualConfig->getBackgroundColor().green());
    this->bBackgroundSpinBox->setValue(this->actualConfig->getBackgroundColor().blue());

    this->buttonColorPicker->setStyleSheet("background-color: " + this->actualConfig->getButtonColor().name() + ";");
    this->buttonLineEdit->setText(this->actualConfig->getButtonColor().name());
    this->rButtonSlider->setValue(this->actualConfig->getButtonColor().red());
    this->gButtonSlider->setValue(this->actualConfig->getButtonColor().green());
    this->bButtonSlider->setValue(this->actualConfig->getButtonColor().blue());
    this->rButtonSpinBox->setValue(this->actualConfig->getButtonColor().red());
    this->gButtonSpinBox->setValue(this->actualConfig->getButtonColor().green());
    this->bButtonSpinBox->setValue(this->actualConfig->getButtonColor().blue());

    // FAKE BUTTONS
    this->button_ONOFF->setShortcut(QKeySequence( this->actualConfig->getButtonOnOff() ));
    this->button_SETTINGS->setShortcut(QKeySequence( this->actualConfig->getButtonSettings() ));
    this->button_NETFLIX->setShortcut(QKeySequence( this->actualConfig->getButtonNetflix() ));
    this->button_UP->setShortcut(QKeySequence( this->actualConfig->getButtonUp() ));
    this->button_DOWN->setShortcut(QKeySequence( this->actualConfig->getButtonDown() ));
    this->button_LEFT->setShortcut(QKeySequence( this->actualConfig->getButtonLeft() ));
    this->button_RIGHT->setShortcut(QKeySequence( this->actualConfig->getButtonRight() ));
    this->button_OK->setShortcut(QKeySequence( this->actualConfig->getButtonOk() ));
    this->button_MENU->setShortcut(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->button_BACK->setShortcut(QKeySequence( this->actualConfig->getButtonBack() ));
    this->button_VOLD->setShortcut(QKeySequence( this->actualConfig->getButtonVolDown() ));
    this->button_VOLU->setShortcut(QKeySequence( this->actualConfig->getButtonVolUp() ));
    this->button_MENU->setShortcut(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->button_MUTE->setShortcut(QKeySequence( this->actualConfig->getButtonMute() ));
    this->button_BACKWARD->setShortcut(QKeySequence( this->actualConfig->getButtonBackward() ));
    this->button_PLAY->setShortcut(QKeySequence( this->actualConfig->getButtonPlayPause() ));
    this->button_FORWARD->setShortcut(QKeySequence( this->actualConfig->getButtonForeward() ));
    this->button_0->setShortcut(QKeySequence( this->actualConfig->getButton0() ));
    this->button_1->setShortcut(QKeySequence( this->actualConfig->getButton1() ));
    this->button_2->setShortcut(QKeySequence( this->actualConfig->getButton2() ));
    this->button_3->setShortcut(QKeySequence( this->actualConfig->getButton3() ));
    this->button_4->setShortcut(QKeySequence( this->actualConfig->getButton4() ));
    this->button_5->setShortcut(QKeySequence( this->actualConfig->getButton5() ));
    this->button_6->setShortcut(QKeySequence( this->actualConfig->getButton6() ));
    this->button_7->setShortcut(QKeySequence( this->actualConfig->getButton7() ));
    this->button_8->setShortcut(QKeySequence( this->actualConfig->getButton8() ));
    this->button_9->setShortcut(QKeySequence( this->actualConfig->getButton9() ));

    // MINI BUTTONS
    this->miniOnOff->setShortcut(QKeySequence( this->actualConfig->getButtonOnOff() ));
    this->miniSettings->setShortcut(QKeySequence( this->actualConfig->getButtonSettings() ));
    this->miniNetflix->setShortcut(QKeySequence( this->actualConfig->getButtonNetflix() ));
    this->miniUp->setShortcut(QKeySequence( this->actualConfig->getButtonUp() ));
    this->miniDown->setShortcut(QKeySequence( this->actualConfig->getButtonDown() ));
    this->miniLeft->setShortcut(QKeySequence( this->actualConfig->getButtonLeft() ));
    this->miniRight->setShortcut(QKeySequence( this->actualConfig->getButtonRight() ));
    this->miniOk->setShortcut(QKeySequence( this->actualConfig->getButtonOk() ));
    this->miniMenu->setShortcut(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->miniBack->setShortcut(QKeySequence( this->actualConfig->getButtonBack() ));
    this->miniVold->setShortcut(QKeySequence( this->actualConfig->getButtonVolDown() ));
    this->miniVolu->setShortcut(QKeySequence( this->actualConfig->getButtonVolUp() ));
    this->miniMenu->setShortcut(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->miniMute->setShortcut(QKeySequence( this->actualConfig->getButtonMute() ));
    this->miniBackward->setShortcut(QKeySequence( this->actualConfig->getButtonBackward() ));
    this->miniPlay->setShortcut(QKeySequence( this->actualConfig->getButtonPlayPause() ));
    this->miniForward->setShortcut(QKeySequence( this->actualConfig->getButtonForeward() ));
    this->mini0->setShortcut(QKeySequence( this->actualConfig->getButton0() ));
    this->mini1->setShortcut(QKeySequence( this->actualConfig->getButton1() ));
    this->mini2->setShortcut(QKeySequence( this->actualConfig->getButton2() ));
    this->mini3->setShortcut(QKeySequence( this->actualConfig->getButton3() ));
    this->mini4->setShortcut(QKeySequence( this->actualConfig->getButton4() ));
    this->mini5->setShortcut(QKeySequence( this->actualConfig->getButton5() ));
    this->mini6->setShortcut(QKeySequence( this->actualConfig->getButton6() ));
    this->mini7->setShortcut(QKeySequence( this->actualConfig->getButton7() ));
    this->mini8->setShortcut(QKeySequence( this->actualConfig->getButton8() ));
    this->mini9->setShortcut(QKeySequence( this->actualConfig->getButton9() ));

    // KEY SEQUENCE EDIT
    this->sequence_ONOFF->setKeySequence(QKeySequence( this->actualConfig->getButtonOnOff() ));
    this->sequence_SETTINGS->setKeySequence(QKeySequence( this->actualConfig->getButtonSettings() ));
    this->sequence_NETFLIX->setKeySequence(QKeySequence( this->actualConfig->getButtonNetflix() ));
    this->sequence_UP->setKeySequence(QKeySequence( this->actualConfig->getButtonUp() ));
    this->sequence_DOWN->setKeySequence(QKeySequence( this->actualConfig->getButtonDown() ));
    this->sequence_LEFT->setKeySequence(QKeySequence( this->actualConfig->getButtonLeft() ));
    this->sequence_RIGHT->setKeySequence(QKeySequence( this->actualConfig->getButtonRight() ));
    this->sequence_OK->setKeySequence(QKeySequence( this->actualConfig->getButtonOk() ));
    this->sequence_MENU->setKeySequence(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->sequence_BACK->setKeySequence(QKeySequence( this->actualConfig->getButtonBack() ));
    this->sequence_VOLD->setKeySequence(QKeySequence( this->actualConfig->getButtonVolDown() ));
    this->sequence_VOLU->setKeySequence(QKeySequence( this->actualConfig->getButtonVolUp() ));
    this->sequence_MENU->setKeySequence(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->sequence_MUTE->setKeySequence(QKeySequence( this->actualConfig->getButtonMute() ));
    this->sequence_BACKWARD->setKeySequence(QKeySequence( this->actualConfig->getButtonBackward() ));
    this->sequence_PLAY->setKeySequence(QKeySequence( this->actualConfig->getButtonPlayPause() ));
    this->sequence_FORWARD->setKeySequence(QKeySequence( this->actualConfig->getButtonForeward() ));
    this->sequence_0->setKeySequence(QKeySequence( this->actualConfig->getButton0() ));
    this->sequence_1->setKeySequence(QKeySequence( this->actualConfig->getButton1() ));
    this->sequence_2->setKeySequence(QKeySequence( this->actualConfig->getButton2() ));
    this->sequence_3->setKeySequence(QKeySequence( this->actualConfig->getButton3() ));
    this->sequence_4->setKeySequence(QKeySequence( this->actualConfig->getButton4() ));
    this->sequence_5->setKeySequence(QKeySequence( this->actualConfig->getButton5() ));
    this->sequence_6->setKeySequence(QKeySequence( this->actualConfig->getButton6() ));
    this->sequence_7->setKeySequence(QKeySequence( this->actualConfig->getButton7() ));
    this->sequence_8->setKeySequence(QKeySequence( this->actualConfig->getButton8() ));
    this->sequence_9->setKeySequence(QKeySequence( this->actualConfig->getButton9() ));
}

void SettingsDialog::applyColorTempConfig()
{
    this->backgroundColorPicker->setStyleSheet("background-color: " + this->tempConfig.getBackgroundColor().name() + ";");
    this->backgroundLineEdit->setText(this->tempConfig.getBackgroundColor().name());
    this->rBackgroundSlider->setValue(this->tempConfig.getBackgroundColor().red());
    this->gBackgroundSlider->setValue(this->tempConfig.getBackgroundColor().green());
    this->bBackgroundSlider->setValue(this->tempConfig.getBackgroundColor().blue());
    this->rBackgroundSpinBox->setValue(this->tempConfig.getBackgroundColor().red());
    this->gBackgroundSpinBox->setValue(this->tempConfig.getBackgroundColor().green());
    this->bBackgroundSpinBox->setValue(this->tempConfig.getBackgroundColor().blue());

    this->buttonColorPicker->setStyleSheet("background-color: " + this->tempConfig.getButtonColor().name() + ";");
    this->buttonLineEdit->setText(this->tempConfig.getButtonColor().name());
    this->rButtonSlider->setValue(this->tempConfig.getButtonColor().red());
    this->gButtonSlider->setValue(this->tempConfig.getButtonColor().green());
    this->bButtonSlider->setValue(this->tempConfig.getButtonColor().blue());
    this->rButtonSpinBox->setValue(this->tempConfig.getButtonColor().red());
    this->gButtonSpinBox->setValue(this->tempConfig.getButtonColor().green());
    this->bButtonSpinBox->setValue(this->tempConfig.getButtonColor().blue());
}

void SettingsDialog::testNetworkConfig()
{

    bool isValidIp = this->isValidIP();
    bool isValidPort = this->isValidPort();
    bool isDecodeur = false;

    /*if (this->testIsDecodeur()) {
        isDecodeur = true;
    }*/

    if (isValidIp and isValidPort) {

        QIcon checkSolid = QIcon(":/icons/rsc/check-solid.svg");
        this->button_testNetworkConfig->setIcon(checkSolid);

    } else if (isValidIp and isValidPort and isDecodeur) {

        QIcon doubleCheck = QIcon(":/icons/rsc/check-solid.svg");
        this->button_testNetworkConfig->setIcon(doubleCheck);

    } else {

        QIcon checkSolid = QIcon(":/icons/rsc/times-solid.svg");
        this->button_testNetworkConfig->setIcon(checkSolid);

    }
}

bool SettingsDialog::isValidIP()
{
    bool isValidIp = false;

    QString ip = this->ipLineEdit->text();

    QRegularExpression reIp("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    QRegularExpressionMatch matchIp = reIp.match(ip);
    if (matchIp.hasMatch()) {
        isValidIp = true;
    }

    return isValidIp;
}

bool SettingsDialog::isValidPort()
{
    bool isValidPort = false;

    QString port = this->portLineEdit->text();

    QRegularExpression rePort("^\\d+$");
    QRegularExpressionMatch matchPort = rePort.match(port);
    if (matchPort.hasMatch()) {
        isValidPort = true;
    }

    return isValidPort;

}

void SettingsDialog::saveNetwork()
{
    if (this->isValidIP() and this->isValidPort()) {

        this->tempConfig.setIp(this->ipLineEdit->text());
        this->tempConfig.setPort(this->portLineEdit->text());

        this->fsi->save(this->tempConfig.toJsonObject());

        this->actualConfig->setIp(this->ipLineEdit->text());
        this->actualConfig->setPort(this->portLineEdit->text());

        this->newConfig = true;

    }
}

SettingsDialog::~SettingsDialog()
{

}

void SettingsDialog::changeWindowsTitleOnTabClick(int tabindex)
{
    if (tabindex == 0) {
        this->setWindowTitle("Network config of the ORC!!!");
    }
    if (tabindex == 1) {
        this->setWindowTitle("Color the ORC!!!");
    }
    if (tabindex == 2) {
        this->setWindowTitle("Edit sortcut of the ORC!!!");
    }
}

void SettingsDialog::addBackgroundColorConnect()
{
    QObject::connect(this->rBackgroundSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::connect(this->rBackgroundSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::connect(this->gBackgroundSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::connect(this->gBackgroundSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::connect(this->bBackgroundSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::connect(this->bBackgroundSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::connect(this->backgroundLineEdit, &QLineEdit::textChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::connect(this->backgroundColorPicker, &QPushButton::clicked, this, &SettingsDialog::valueChangedForBackground);
}

void SettingsDialog::delBackgroundColorConnect()
{
    QObject::disconnect(this->rBackgroundSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::disconnect(this->rBackgroundSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::disconnect(this->gBackgroundSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::disconnect(this->gBackgroundSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::disconnect(this->bBackgroundSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::disconnect(this->bBackgroundSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::disconnect(this->backgroundLineEdit, &QLineEdit::textChanged, this, &SettingsDialog::valueChangedForBackground);
    QObject::disconnect(this->backgroundColorPicker, &QPushButton::clicked, this, &SettingsDialog::valueChangedForBackground);
}

void SettingsDialog::valueChangedForBackground()
{
    QObject *senderPtr = QObject::sender();

    this->delBackgroundColorConnect();

    if (senderPtr == this->rBackgroundSlider) {
        this->tempConfig.setRedBackgroundColor(this->rBackgroundSlider->value());
        this->updateBackgroundColorOnUi();
    }

    if (senderPtr == this->rBackgroundSpinBox) {
        this->tempConfig.setRedBackgroundColor(this->rBackgroundSpinBox->value());
        this->updateBackgroundColorOnUi();
    }

    if (senderPtr == this->gBackgroundSlider) {
        this->tempConfig.setGreenBackgroundColor(this->gBackgroundSlider->value());
        this->updateBackgroundColorOnUi();
    }

    if (senderPtr == this->gBackgroundSpinBox) {
        this->tempConfig.setGreenBackgroundColor(this->gBackgroundSpinBox->value());
        this->updateBackgroundColorOnUi();
    }

    if (senderPtr == this->bBackgroundSlider) {
        this->tempConfig.setBlueBackgroundColor(this->bBackgroundSlider->value());
        this->updateBackgroundColorOnUi();
    }

    if (senderPtr == this->bBackgroundSpinBox) {
        this->tempConfig.setBlueBackgroundColor(this->bBackgroundSpinBox->value());
        this->updateBackgroundColorOnUi();
    }

    if (senderPtr == this->backgroundColorPicker) {
        QColor tempColor = QColorDialog::getColor(this->tempConfig.getBackgroundColor().name());
        this->tempConfig.setBackgroundColorFromString(tempColor.name());
        this->updateBackgroundColorOnUi();
    }

    this->addBackgroundColorConnect();
}

void SettingsDialog::updateBackgroundColorOnUi()
{
    this->backgroundColorPicker->setStyleSheet("background-color: " + this->tempConfig.getBackgroundColor().name() + ";");
    this->backgroundLineEdit->setText(this->tempConfig.getBackgroundColor().name());
    this->rBackgroundSlider->setValue(this->tempConfig.getBackgroundColor().red());
    this->gBackgroundSlider->setValue(this->tempConfig.getBackgroundColor().green());
    this->bBackgroundSlider->setValue(this->tempConfig.getBackgroundColor().blue());
    this->rBackgroundSpinBox->setValue(this->tempConfig.getBackgroundColor().red());
    this->gBackgroundSpinBox->setValue(this->tempConfig.getBackgroundColor().green());
    this->bBackgroundSpinBox->setValue(this->tempConfig.getBackgroundColor().blue());
    this->remoteControlWidget->setStyleSheet("background-color: " + this->tempConfig.getBackgroundColor().name() + ";");
}

void SettingsDialog::backToOldBackgroundColor()
{
    //this->delBackgroundColorConnect();

    this->tempConfig.setBackgroundColorFromString(this->actualConfig->getBackgroundColor().name());
    this->updateBackgroundColorOnUi();

    //this->addBackgroundColorConnect();
}

void SettingsDialog::saveNewBackgroundColor()
{
    this->fsi->save(this->tempConfig.toJsonObject());
    this->actualConfig->setBackgroundColorFromString(this->tempConfig.getBackgroundColor().name());

    this->newConfig = true;
}

void SettingsDialog::addButtonColorConnect()
{
    QObject::connect(this->rButtonSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::connect(this->rButtonSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::connect(this->gButtonSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::connect(this->gButtonSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::connect(this->bButtonSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::connect(this->bButtonSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::connect(this->buttonLineEdit, &QLineEdit::textChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::connect(this->buttonColorPicker, &QPushButton::clicked, this, &SettingsDialog::valueChangedForButton);
}

void SettingsDialog::delButtonColorConnect()
{
    QObject::disconnect(this->rButtonSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::disconnect(this->rButtonSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::disconnect(this->gButtonSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::disconnect(this->gButtonSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::disconnect(this->bButtonSlider, &QSlider::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::disconnect(this->bButtonSpinBox, &QSpinBox::valueChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::disconnect(this->buttonLineEdit, &QLineEdit::textChanged, this, &SettingsDialog::valueChangedForButton);
    QObject::disconnect(this->buttonColorPicker, &QPushButton::clicked, this, &SettingsDialog::valueChangedForButton);
}

void SettingsDialog::valueChangedForButton()
{
    QObject *senderPtr = QObject::sender();

    this->delButtonColorConnect();

    if (senderPtr == this->rButtonSlider) {

        this->tempConfig.setRedButtonColor(this->rButtonSlider->value());
        this->updateButtonColorOnUi();
    }

    if (senderPtr == this->rButtonSpinBox) {
        this->tempConfig.setRedButtonColor(this->rButtonSpinBox->value());
        this->updateButtonColorOnUi();
    }

    if (senderPtr == this->gButtonSlider) {
        this->tempConfig.setGreenButtonColor(this->gButtonSlider->value());
        this->updateButtonColorOnUi();
    }

    if (senderPtr == this->gButtonSpinBox) {
        this->tempConfig.setGreenButtonColor(this->gButtonSpinBox->value());
        this->updateButtonColorOnUi();
    }

    if (senderPtr == this->bButtonSlider) {
        this->tempConfig.setBlueButtonColor(this->bButtonSlider->value());
        this->updateButtonColorOnUi();
    }

    if (senderPtr == this->bButtonSpinBox) {
        this->tempConfig.setBlueButtonColor(this->bButtonSpinBox->value());
        this->updateButtonColorOnUi();
    }

    if (senderPtr == this->buttonColorPicker) {
        QColor tempColor = QColorDialog::getColor(this->tempConfig.getButtonColor().name());
        this->tempConfig.setButtonColorFromString(tempColor.name());
        this->updateButtonColorOnUi();
    }

    this->addButtonColorConnect();
}

void SettingsDialog::updateButtonColorOnUi()
{
    this->buttonColorPicker->setStyleSheet("background-color: " + this->tempConfig.getButtonColor().name() + ";");
    this->buttonLineEdit->setText(this->tempConfig.getButtonColor().name());
    this->rButtonSlider->setValue(this->tempConfig.getButtonColor().red());
    this->gButtonSlider->setValue(this->tempConfig.getButtonColor().green());
    this->bButtonSlider->setValue(this->tempConfig.getButtonColor().blue());
    this->rButtonSpinBox->setValue(this->tempConfig.getButtonColor().red());
    this->gButtonSpinBox->setValue(this->tempConfig.getButtonColor().green());
    this->bButtonSpinBox->setValue(this->tempConfig.getButtonColor().blue());

    for (std::vector<QPushButton*>::iterator it = this->button_all.begin() ; it != this->button_all.end(); ++it) {
        (*it)->setStyleSheet("background-color: " + this->tempConfig.getButtonColor().name() + ";");
    }
}

void SettingsDialog::backToOldButtonColor()
{
    this->delButtonColorConnect();

    this->tempConfig.setButtonColorFromString(this->actualConfig->getButtonColor().name());
    this->updateButtonColorOnUi();

    this->addButtonColorConnect();
}

void SettingsDialog::saveNewButtonColor()
{
    this->fsi->save(this->tempConfig.toJsonObject());
    this->actualConfig->setButtonColorFromString(this->tempConfig.getButtonColor().name());

    this->newConfig = true;
}

void SettingsDialog::sequence_ONOFF_updated()
{
    QString firstSeq = this->sequence_ONOFF->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonOnOff(firstSeq);

    this->sequence_ONOFF->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Netflix_updated()
{
    QString firstSeq = this->sequence_NETFLIX->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonNetflix(firstSeq);

    this->sequence_NETFLIX->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Settings_updated()
{
    QString firstSeq = this->sequence_SETTINGS->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonSettings(firstSeq);

    this->sequence_SETTINGS->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Up_updated()
{
    QString firstSeq = this->sequence_UP->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonUp(firstSeq);

    this->sequence_UP->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Left_updated()
{
    QString firstSeq = this->sequence_LEFT->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonLeft(firstSeq);

    this->sequence_LEFT->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Ok_updated()
{
    QString firstSeq = this->sequence_OK->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonOk(firstSeq);

    this->sequence_OK->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Right_updated()
{
    QString firstSeq = this->sequence_RIGHT->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonRight(firstSeq);

    this->sequence_RIGHT->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Down_updated()
{
    QString firstSeq = this->sequence_DOWN->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonDown(firstSeq);

    this->sequence_DOWN->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Menu_updated()
{
    QString firstSeq = this->sequence_MENU->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonMenu(firstSeq);

    this->sequence_MENU->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Back_updated()
{
    QString firstSeq = this->sequence_BACK->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonBack(firstSeq);

    this->sequence_BACK->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Vold_updated()
{
    QString firstSeq = this->sequence_VOLD->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonVolDown(firstSeq);

    this->sequence_VOLD->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Mute_updated()
{
    QString firstSeq = this->sequence_MUTE->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonMute(firstSeq);

    this->sequence_MUTE->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Volu_updated()
{
    QString firstSeq = this->sequence_VOLU->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonVolUp(firstSeq);

    this->sequence_VOLU->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_1_updated()
{
    QString firstSeq = this->sequence_1->keySequence().toString().split(",")[0];

    this->tempConfig.setButton1(firstSeq);

    this->sequence_1->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_2_updated()
{
    QString firstSeq = this->sequence_2->keySequence().toString().split(",")[0];

    this->tempConfig.setButton2(firstSeq);

    this->sequence_2->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_3_updated()
{
    QString firstSeq = this->sequence_3->keySequence().toString().split(",")[0];

    this->tempConfig.setButton3(firstSeq);

    this->sequence_3->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_4_updated()
{
    QString firstSeq = this->sequence_4->keySequence().toString().split(",")[0];

    this->tempConfig.setButton4(firstSeq);

    this->sequence_4->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_5_updated()
{
    QString firstSeq = this->sequence_5->keySequence().toString().split(",")[0];

    this->tempConfig.setButton5(firstSeq);

    this->sequence_5->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_6_updated()
{
    QString firstSeq = this->sequence_6->keySequence().toString().split(",")[0];

    this->tempConfig.setButton6(firstSeq);

    this->sequence_6->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_7_updated()
{
    QString firstSeq = this->sequence_7->keySequence().toString().split(",")[0];

    this->tempConfig.setButton7(firstSeq);

    this->sequence_7->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_8_updated()
{
    QString firstSeq = this->sequence_8->keySequence().toString().split(",")[0];

    this->tempConfig.setButton8(firstSeq);

    this->sequence_8->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_9_updated()
{
    QString firstSeq = this->sequence_9->keySequence().toString().split(",")[0];

    this->tempConfig.setButton9(firstSeq);

    this->sequence_9->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_0_updated()
{
    QString firstSeq = this->sequence_0->keySequence().toString().split(",")[0];

    this->tempConfig.setButton0(firstSeq);

    this->sequence_0->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Backward_updated()
{
    QString firstSeq = this->sequence_BACKWARD->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonBackward(firstSeq);

    this->sequence_BACKWARD->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Play_updated()
{
    QString firstSeq = this->sequence_PLAY->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonPlayPause(firstSeq);

    this->sequence_PLAY->setKeySequence(firstSeq);
}

void SettingsDialog::sequence_Forward_updated()
{
    QString firstSeq = this->sequence_FORWARD->keySequence().toString().split(",")[0];

    this->tempConfig.setButtonForeward(firstSeq);

    this->sequence_FORWARD->setKeySequence(firstSeq);
}

void SettingsDialog::updateToolTipCheckBox()
{
    if (this->tooltipsCheckBox->isChecked()) {
        this->tempConfig.setEnableToolTips(true);
    } else {
        this->tempConfig.setEnableToolTips(false);
    }


}


void SettingsDialog::addSequenceEditConnect()
{
    QObject::connect(this->buttonBackToOldShortcut, &QPushButton::clicked, this, &SettingsDialog::cancelShortcutConfig);
    QObject::connect(this->saveNewShortcut, &QPushButton::clicked, this, &SettingsDialog::saveNewShortcutConfig);


    QObject::connect(this->sequence_ONOFF, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_ONOFF_updated);
    QObject::connect(this->sequence_NETFLIX, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Netflix_updated);
    QObject::connect(this->sequence_SETTINGS, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Settings_updated);
    QObject::connect(this->sequence_UP, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Up_updated);
    QObject::connect(this->sequence_DOWN, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Down_updated);
    QObject::connect(this->sequence_OK, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Ok_updated);
    QObject::connect(this->sequence_LEFT, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Left_updated);
    QObject::connect(this->sequence_RIGHT, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Right_updated);
    QObject::connect(this->sequence_MENU, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Menu_updated);
    QObject::connect(this->sequence_BACK, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Back_updated);
    QObject::connect(this->sequence_VOLD, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Vold_updated);
    QObject::connect(this->sequence_MUTE, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Mute_updated);
    QObject::connect(this->sequence_VOLU, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Volu_updated);
    QObject::connect(this->sequence_0, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_0_updated);
    QObject::connect(this->sequence_1, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_1_updated);
    QObject::connect(this->sequence_2, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_2_updated);
    QObject::connect(this->sequence_3, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_3_updated);
    QObject::connect(this->sequence_4, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_4_updated);
    QObject::connect(this->sequence_5, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_5_updated);
    QObject::connect(this->sequence_6, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_6_updated);
    QObject::connect(this->sequence_7, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_7_updated);
    QObject::connect(this->sequence_8, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_8_updated);
    QObject::connect(this->sequence_9, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_9_updated);
    QObject::connect(this->sequence_BACKWARD, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Backward_updated);
    QObject::connect(this->sequence_PLAY, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Play_updated);
    QObject::connect(this->sequence_FORWARD, &QKeySequenceEdit::editingFinished, this, &SettingsDialog::sequence_Forward_updated);

}

void SettingsDialog::cancelShortcutConfig()
{
    this->button_ONOFF->setShortcut(QKeySequence( this->actualConfig->getButtonOnOff() ));
    this->button_SETTINGS->setShortcut(QKeySequence( this->actualConfig->getButtonSettings() ));
    this->button_NETFLIX->setShortcut(QKeySequence( this->actualConfig->getButtonNetflix() ));
    this->button_UP->setShortcut(QKeySequence( this->actualConfig->getButtonUp() ));
    this->button_DOWN->setShortcut(QKeySequence( this->actualConfig->getButtonDown() ));
    this->button_LEFT->setShortcut(QKeySequence( this->actualConfig->getButtonLeft() ));
    this->button_RIGHT->setShortcut(QKeySequence( this->actualConfig->getButtonRight() ));
    this->button_OK->setShortcut(QKeySequence( this->actualConfig->getButtonOk() ));
    this->button_MENU->setShortcut(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->button_BACK->setShortcut(QKeySequence( this->actualConfig->getButtonBack() ));
    this->button_VOLD->setShortcut(QKeySequence( this->actualConfig->getButtonVolDown() ));
    this->button_VOLU->setShortcut(QKeySequence( this->actualConfig->getButtonVolUp() ));
    this->button_MENU->setShortcut(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->button_MUTE->setShortcut(QKeySequence( this->actualConfig->getButtonMute() ));
    this->button_BACKWARD->setShortcut(QKeySequence( this->actualConfig->getButtonBackward() ));
    this->button_PLAY->setShortcut(QKeySequence( this->actualConfig->getButtonPlayPause() ));
    this->button_FORWARD->setShortcut(QKeySequence( this->actualConfig->getButtonForeward() ));
    this->button_0->setShortcut(QKeySequence( this->actualConfig->getButton0() ));
    this->button_1->setShortcut(QKeySequence( this->actualConfig->getButton1() ));
    this->button_2->setShortcut(QKeySequence( this->actualConfig->getButton2() ));
    this->button_3->setShortcut(QKeySequence( this->actualConfig->getButton3() ));
    this->button_4->setShortcut(QKeySequence( this->actualConfig->getButton4() ));
    this->button_5->setShortcut(QKeySequence( this->actualConfig->getButton5() ));
    this->button_6->setShortcut(QKeySequence( this->actualConfig->getButton6() ));
    this->button_7->setShortcut(QKeySequence( this->actualConfig->getButton7() ));
    this->button_8->setShortcut(QKeySequence( this->actualConfig->getButton8() ));
    this->button_9->setShortcut(QKeySequence( this->actualConfig->getButton9() ));

    // MINI BUTTONS
    this->miniOnOff->setShortcut(QKeySequence( this->actualConfig->getButtonOnOff() ));
    this->miniSettings->setShortcut(QKeySequence( this->actualConfig->getButtonSettings() ));
    this->miniNetflix->setShortcut(QKeySequence( this->actualConfig->getButtonNetflix() ));
    this->miniUp->setShortcut(QKeySequence( this->actualConfig->getButtonUp() ));
    this->miniDown->setShortcut(QKeySequence( this->actualConfig->getButtonDown() ));
    this->miniLeft->setShortcut(QKeySequence( this->actualConfig->getButtonLeft() ));
    this->miniRight->setShortcut(QKeySequence( this->actualConfig->getButtonRight() ));
    this->miniOk->setShortcut(QKeySequence( this->actualConfig->getButtonOk() ));
    this->miniMenu->setShortcut(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->miniBack->setShortcut(QKeySequence( this->actualConfig->getButtonBack() ));
    this->miniVold->setShortcut(QKeySequence( this->actualConfig->getButtonVolDown() ));
    this->miniVolu->setShortcut(QKeySequence( this->actualConfig->getButtonVolUp() ));
    this->miniMenu->setShortcut(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->miniMute->setShortcut(QKeySequence( this->actualConfig->getButtonMute() ));
    this->miniBackward->setShortcut(QKeySequence( this->actualConfig->getButtonBackward() ));
    this->miniPlay->setShortcut(QKeySequence( this->actualConfig->getButtonPlayPause() ));
    this->miniForward->setShortcut(QKeySequence( this->actualConfig->getButtonForeward() ));
    this->mini0->setShortcut(QKeySequence( this->actualConfig->getButton0() ));
    this->mini1->setShortcut(QKeySequence( this->actualConfig->getButton1() ));
    this->mini2->setShortcut(QKeySequence( this->actualConfig->getButton2() ));
    this->mini3->setShortcut(QKeySequence( this->actualConfig->getButton3() ));
    this->mini4->setShortcut(QKeySequence( this->actualConfig->getButton4() ));
    this->mini5->setShortcut(QKeySequence( this->actualConfig->getButton5() ));
    this->mini6->setShortcut(QKeySequence( this->actualConfig->getButton6() ));
    this->mini7->setShortcut(QKeySequence( this->actualConfig->getButton7() ));
    this->mini8->setShortcut(QKeySequence( this->actualConfig->getButton8() ));
    this->mini9->setShortcut(QKeySequence( this->actualConfig->getButton9() ));

    // KEY SEQUENCE EDIT
    this->sequence_ONOFF->setKeySequence(QKeySequence( this->actualConfig->getButtonOnOff() ));
    this->sequence_SETTINGS->setKeySequence(QKeySequence( this->actualConfig->getButtonSettings() ));
    this->sequence_NETFLIX->setKeySequence(QKeySequence( this->actualConfig->getButtonNetflix() ));
    this->sequence_UP->setKeySequence(QKeySequence( this->actualConfig->getButtonUp() ));
    this->sequence_DOWN->setKeySequence(QKeySequence( this->actualConfig->getButtonDown() ));
    this->sequence_LEFT->setKeySequence(QKeySequence( this->actualConfig->getButtonLeft() ));
    this->sequence_RIGHT->setKeySequence(QKeySequence( this->actualConfig->getButtonRight() ));
    this->sequence_OK->setKeySequence(QKeySequence( this->actualConfig->getButtonOk() ));
    this->sequence_MENU->setKeySequence(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->sequence_BACK->setKeySequence(QKeySequence( this->actualConfig->getButtonBack() ));
    this->sequence_VOLD->setKeySequence(QKeySequence( this->actualConfig->getButtonVolDown() ));
    this->sequence_VOLU->setKeySequence(QKeySequence( this->actualConfig->getButtonVolUp() ));
    this->sequence_MENU->setKeySequence(QKeySequence( this->actualConfig->getButtonMenu() ));
    this->sequence_MUTE->setKeySequence(QKeySequence( this->actualConfig->getButtonMute() ));
    this->sequence_BACKWARD->setKeySequence(QKeySequence( this->actualConfig->getButtonBackward() ));
    this->sequence_PLAY->setKeySequence(QKeySequence( this->actualConfig->getButtonPlayPause() ));
    this->sequence_FORWARD->setKeySequence(QKeySequence( this->actualConfig->getButtonForeward() ));
    this->sequence_0->setKeySequence(QKeySequence( this->actualConfig->getButton0() ));
    this->sequence_1->setKeySequence(QKeySequence( this->actualConfig->getButton1() ));
    this->sequence_2->setKeySequence(QKeySequence( this->actualConfig->getButton2() ));
    this->sequence_3->setKeySequence(QKeySequence( this->actualConfig->getButton3() ));
    this->sequence_4->setKeySequence(QKeySequence( this->actualConfig->getButton4() ));
    this->sequence_5->setKeySequence(QKeySequence( this->actualConfig->getButton5() ));
    this->sequence_6->setKeySequence(QKeySequence( this->actualConfig->getButton6() ));
    this->sequence_7->setKeySequence(QKeySequence( this->actualConfig->getButton7() ));
    this->sequence_8->setKeySequence(QKeySequence( this->actualConfig->getButton8() ));
    this->sequence_9->setKeySequence(QKeySequence( this->actualConfig->getButton9() ));
}

void SettingsDialog::saveNewShortcutConfig()
{
    this->fsi->save(this->tempConfig.toJsonObject());

    *this->actualConfig = this->tempConfig;

    this->newConfig = true;
}
