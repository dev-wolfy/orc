#include "config.h"

Config::Config()
{

}

Config::Config(QJsonObject *jsonConfig)
{

    // NETWORK
    if (jsonConfig->contains("network-config")) {

        QJsonObject networkConfig = jsonConfig->find("network-config")->toObject();

        if (networkConfig.contains("ip") and networkConfig["ip"].isString()) {
            this->setIp(networkConfig["ip"].toString());
        } else {
            this->setIp("192.168.1.1");
        }

        if (networkConfig.contains("port") and networkConfig["port"].isString()) {
            this->setPort(networkConfig["port"].toString());
        } else {
            this->setPort("8080");
        }

    } else {
        this->setIp("192.168.1.1");
        this->setPort("8080");
    }


    this->backgroundColor = QColor();
    this->buttonColor = QColor();

    if (jsonConfig->contains("ui-config")) {

        QJsonObject uiConfig = jsonConfig->find("ui-config")->toObject();

        // TOOL TIPS
        if (uiConfig.contains("tooltip") and uiConfig["tooltip"].isString()) {
            if (uiConfig["tooltip"].toString() == "true") {
                this->enableToolTips = true;
            } else {
                this->enableToolTips = false;
            }
        } else {
            this->enableToolTips = false;
        }


        // COLORS
        if (uiConfig.contains("color")) {

            QJsonObject colorConfig = uiConfig.find("color")->toObject();

            if (colorConfig.contains("button") and colorConfig["button"].isString()) {
                this->setButtonColor(colorConfig["button"].toString());
            } else {
                this->setButtonColor("");
            }

            if (colorConfig.contains("background") and colorConfig["background"].isString()) {
                this->setBackgroundColor(colorConfig["background"].toString());
            } else {
                this->setBackgroundColor("");
            }

        } else {
            this->setButtonColor("");
            this->setBackgroundColor("");
        }

        // SHORTCUTS
        if (uiConfig.contains("shortcut")) {

            QJsonObject shortcutConfig = uiConfig.find("shortcut")->toObject();

            if (shortcutConfig.contains("0") and shortcutConfig["0"].isString()) {
                this->setButton0(shortcutConfig["0"].toString());
            } else {
                this->setButton0("0");
            }

            if (shortcutConfig.contains("1") and shortcutConfig["1"].isString()) {
                this->setButton1(shortcutConfig["1"].toString());
            } else {
                this->setButton1("1");
            }

            if (shortcutConfig.contains("2") and shortcutConfig["2"].isString()) {
                this->setButton2(shortcutConfig["2"].toString());
            } else {
                this->setButton2("2");
            }

            if (shortcutConfig.contains("3") and shortcutConfig["3"].isString()) {
                this->setButton3(shortcutConfig["3"].toString());
            } else {
                this->setButton3("3");
            }

            if (shortcutConfig.contains("4") and shortcutConfig["4"].isString()) {
                this->setButton4(shortcutConfig["4"].toString());
            } else {
                this->setButton4("4");
            }

            if (shortcutConfig.contains("5") and shortcutConfig["5"].isString()) {
                this->setButton5(shortcutConfig["5"].toString());
            } else {
                this->setButton5("5");
            }

            if (shortcutConfig.contains("6") and shortcutConfig["6"].isString()) {
                this->setButton6(shortcutConfig["6"].toString());
            } else {
                this->setButton6("6");
            }

            if (shortcutConfig.contains("7") and shortcutConfig["7"].isString()) {
                this->setButton7(shortcutConfig["7"].toString());
            } else {
                this->setButton7("7");
            }

            if (shortcutConfig.contains("8") and shortcutConfig["8"].isString()) {
                this->setButton8(shortcutConfig["8"].toString());
            } else {
                this->setButton8("0");
            }

            if (shortcutConfig.contains("9") and shortcutConfig["9"].isString()) {
                this->setButton9(shortcutConfig["9"].toString());
            } else {
                this->setButton9("9");
            }

            if (shortcutConfig.contains("onoff") and shortcutConfig["onoff"].isString()) {
                this->setButtonOnOff(shortcutConfig["onoff"].toString());
            } else {
                this->setButtonOnOff("O");
            }

            if (shortcutConfig.contains("settings") and shortcutConfig["settings"].isString()) {
                this->setButtonSettings(shortcutConfig["settings"].toString());
            } else {
                this->setButtonSettings("P");
            }

            if (shortcutConfig.contains("netflix") and shortcutConfig["netflix"].isString()) {
                this->setButtonNetflix(shortcutConfig["netflix"].toString());
            } else {
                this->setButtonNetflix("N");
            }

            if (shortcutConfig.contains("up") and shortcutConfig["up"].isString()) {
                this->setButtonUp(shortcutConfig["up"].toString());
            } else {
                this->setButtonUp("Z");
            }

            if (shortcutConfig.contains("left") and shortcutConfig["left"].isString()) {
                this->setButtonLeft(shortcutConfig["left"].toString());
            } else {
                this->setButtonLeft("Q");
            }

            if (shortcutConfig.contains("ok") and shortcutConfig["ok"].isString()) {
                this->setButtonOk(shortcutConfig["ok"].toString());
            } else {
                this->setButtonOk("E");
            }

            if (shortcutConfig.contains("right") and shortcutConfig["right"].isString()) {
                this->setButtonRight(shortcutConfig["right"].toString());
            } else {
                this->setButtonRight("D");
            }

            if (shortcutConfig.contains("down") and shortcutConfig["down"].isString()) {
                this->setButtonDown(shortcutConfig["down"].toString());
            } else {
                this->setButtonDown("S");
            }

            if (shortcutConfig.contains("menu") and shortcutConfig["menu"].isString()) {
                this->setButtonMenu(shortcutConfig["menu"].toString());
            } else {
                this->setButtonMenu("P");
            }

            if (shortcutConfig.contains("back") and shortcutConfig["back"].isString()) {
                this->setButtonBack(shortcutConfig["back"].toString());
            } else {
                this->setButtonBack("Backspace");
            }

            if (shortcutConfig.contains("voldown") and shortcutConfig["voldown"].isString()) {
                this->setButtonVolDown(shortcutConfig["voldown"].toString());
            } else {
                this->setButtonVolDown("Down");
            }

            if (shortcutConfig.contains("mute") and shortcutConfig["mute"].isString()) {
                this->setButtonMute(shortcutConfig["mute"].toString());
            } else {
                this->setButtonMute("T");
            }

            if (shortcutConfig.contains("volup") and shortcutConfig["volup"].isString()) {
                this->setButtonVolUp(shortcutConfig["volup"].toString());
            } else {
                this->setButtonVolUp("Up");
            }

            if (shortcutConfig.contains("backward") and shortcutConfig["backward"].isString()) {
                this->setButtonBackward(shortcutConfig["backward"].toString());
            } else {
                this->setButtonBackward("P");
            }

            if (shortcutConfig.contains("playpause") and shortcutConfig["playpause"].isString()) {
                this->setButtonPlayPause(shortcutConfig["playpause"].toString());
            } else {
                this->setButtonPlayPause("Space");
            }

            if (shortcutConfig.contains("foreward") and shortcutConfig["foreward"].isString()) {
                this->setButtonForeward(shortcutConfig["foreward"].toString());
            } else {
                this->setButtonForeward("Right");
            }

        } else {

            this->buttonOnOff = "O";
            this->buttonNetflix = "N";
            this->buttonUp = "Z";
            this->buttonDown = "S";
            this->buttonLeft = "Q";
            this->buttonRight = "D";
            this->buttonOk = "E";
            this->buttonMenu = "M";
            this->buttonSettings = "P";
            this->buttonVolUp = "Up";
            this->buttonMute = "T";
            this->buttonBack = "Backspace";
            this->buttonVolDown = "Down";
            this->button0 = "0";
            this->button1 = "1";
            this->button2 = "2";
            this->button3 = "3";
            this->button4 = "4";
            this->button5 = "5";
            this->button6 = "6";
            this->button7 = "7";
            this->button8 = "8";
            this->button9 = "9";
            this->buttonBackward = "Left";
            this->buttonPlayPause = "Space";
            this->buttonForeward = "Right";

        }

    } else {

        this->setButtonColor("");
        this->setBackgroundColor("");
        this->buttonOnOff = "O";
        this->buttonNetflix = "N";
        this->buttonUp = "Z";
        this->buttonDown = "S";
        this->buttonLeft = "Q";
        this->buttonRight = "D";
        this->buttonOk = "E";
        this->buttonMenu = "M";
        this->buttonBack = "Backspace";
        this->buttonSettings = "P";
        this->buttonVolUp = "Up";
        this->buttonMute = "T";
        this->buttonVolDown = "Down";
        this->button0 = "0";
        this->button1 = "1";
        this->button2 = "2";
        this->button3 = "3";
        this->button4 = "4";
        this->button5 = "5";
        this->button6 = "6";
        this->button7 = "7";
        this->button8 = "8";
        this->button9 = "9";
        this->buttonBackward = "Left";
        this->buttonPlayPause = "Space";
        this->buttonForeward = "Right";
        this->enableToolTips = false;

    }

}

QJsonObject *Config::toJsonObject()
{
    QJsonObject root = QJsonObject();

    QJsonObject networkJsonObject;
    networkJsonObject["ip"] = this->ip;
    networkJsonObject["port"] = this->port;

    QJsonObject colorJsonObject;
    colorJsonObject["background"] = this->backgroundColor.name();
    colorJsonObject["button"] = this->buttonColor.name();

    QJsonObject shortcutJsonObject;
    shortcutJsonObject["0"] = this->button0;
    shortcutJsonObject["1"] = this->button1;
    shortcutJsonObject["2"] = this->button2;
    shortcutJsonObject["3"] = this->button3;
    shortcutJsonObject["4"] = this->button4;
    shortcutJsonObject["5"] = this->button5;
    shortcutJsonObject["6"] = this->button6;
    shortcutJsonObject["7"] = this->button7;
    shortcutJsonObject["8"] = this->button8;
    shortcutJsonObject["9"] = this->button9;
    shortcutJsonObject["back"] = this->buttonBack;
    shortcutJsonObject["backward"] = this->buttonBackward;
    shortcutJsonObject["down"] = this->buttonDown;
    shortcutJsonObject["foreward"] = this->buttonForeward;
    shortcutJsonObject["left"] = this->buttonLeft;
    shortcutJsonObject["menu"] = this->buttonMenu;
    shortcutJsonObject["mute"] = this->buttonMute;
    shortcutJsonObject["netflix"] = this->buttonNetflix;
    shortcutJsonObject["ok"] = this->buttonOk;
    shortcutJsonObject["onoff"] = this->buttonOnOff;
    shortcutJsonObject["playpause"] = this->buttonPlayPause;
    shortcutJsonObject["right"] = this->buttonRight;
    shortcutJsonObject["up"] = this->buttonUp;
    shortcutJsonObject["voldown"] = this->buttonVolDown;
    shortcutJsonObject["volup"] = this->buttonVolUp;
    shortcutJsonObject["settings"] = this->buttonSettings;

    QJsonObject uiJsonObject;
    uiJsonObject["color"] = colorJsonObject;
    uiJsonObject["shortcut"] = shortcutJsonObject;

    if (this->enableToolTips) {
        uiJsonObject["tooltip"] = "true";
    } else {
        uiJsonObject["tooltip"] = "false";
    }

    root["network-config"] = networkJsonObject;
    root["ui-config"] = uiJsonObject;

    QJsonObject *toReturnJsonObject = new QJsonObject(root);

    return toReturnJsonObject;
}

Config::~Config()
{

}

const QString &Config::getIp() const
{
    return ip;
}

void Config::setIp(const QString &newIp)
{
    ip = newIp;
}

const QString &Config::getPort() const
{
    return port;
}

void Config::setPort(const QString &newPort)
{
    port = newPort;
}

const QColor &Config::getButtonColor() const
{
    return buttonColor;
}

void Config::setButtonColor(const QColor &newButtonColor)
{
    buttonColor = newButtonColor;
}

void Config::setRedButtonColor(const int &red)
{
    this->buttonColor.setRed(red);
}

void Config::setGreenButtonColor(const int &green)
{
    this->buttonColor.setGreen(green);
}

void Config::setBlueButtonColor(const int &blue)
{
    this->buttonColor.setBlue(blue);
}

void Config::setButtonColorFromString(const QString &newColorName)
{
    this->buttonColor.setNamedColor(newColorName);
}

const QColor &Config::getBackgroundColor() const
{
    return backgroundColor;
}

void Config::setBackgroundColor(const QColor &newBackgroundColor)
{
    backgroundColor = newBackgroundColor;
}

void Config::setRedBackgroundColor(const int &red)
{
    this->backgroundColor.setRed(red);
}

void Config::setGreenBackgroundColor(const int &green)
{
    this->backgroundColor.setGreen(green);
}

void Config::setBlueBackgroundColor(const int &blue)
{
    this->backgroundColor.setBlue(blue);
}

void Config::setBackgroundColorFromString(const QString &newColorName)
{
    this->backgroundColor.setNamedColor(newColorName);
}

const QString &Config::getButtonOnOff() const
{
    return buttonOnOff;
}

void Config::setButtonOnOff(const QString &newButtonOnOff)
{
    buttonOnOff = newButtonOnOff;
}

const QString &Config::getButtonMenu() const
{
    return buttonMenu;
}

void Config::setButtonMenu(const QString &newButtonMenu)
{
    buttonMenu = newButtonMenu;
}

const QString &Config::getButtonNetflix() const
{
    return buttonNetflix;
}

void Config::setButtonNetflix(const QString &newButtonNetflix)
{
    buttonNetflix = newButtonNetflix;
}

const QString &Config::getButtonBack() const
{
    return buttonBack;
}

void Config::setButtonBack(const QString &newButtonBack)
{
    buttonBack = newButtonBack;
}

const QString &Config::getButtonSettings() const
{
    return buttonSettings;
}

void Config::setButtonSettings(const QString &newButtonSettings)
{
    buttonSettings = newButtonSettings;
}

const QString &Config::getButtonUp() const
{
    return buttonUp;
}

void Config::setButtonUp(const QString &newButtonUp)
{
    buttonUp = newButtonUp;
}

const QString &Config::getButtonLeft() const
{
    return buttonLeft;
}

void Config::setButtonLeft(const QString &newButtonLeft)
{
    buttonLeft = newButtonLeft;
}

const QString &Config::getButtonOk() const
{
    return buttonOk;
}

void Config::setButtonOk(const QString &newButtonOk)
{
    buttonOk = newButtonOk;
}

const QString &Config::getButtonRight() const
{
    return buttonRight;
}

void Config::setButtonRight(const QString &newButtonRight)
{
    buttonRight = newButtonRight;
}

const QString &Config::getButtonDown() const
{
    return buttonDown;
}

void Config::setButtonDown(const QString &newButtonDown)
{
    buttonDown = newButtonDown;
}

const QString &Config::getButtonVolDown() const
{
    return buttonVolDown;
}

void Config::setButtonVolDown(const QString &newButtonVolDown)
{
    buttonVolDown = newButtonVolDown;
}

const QString &Config::getButtonMute() const
{
    return buttonMute;
}

void Config::setButtonMute(const QString &newButtonMute)
{
    buttonMute = newButtonMute;
}

const QString &Config::getButtonVolUp() const
{
    return buttonVolUp;
}

void Config::setButtonVolUp(const QString &newButtonVolUp)
{
    buttonVolUp = newButtonVolUp;
}

const QString &Config::getButton0() const
{
    return button0;
}

void Config::setButton0(const QString &newButton0)
{
    button0 = newButton0;
}

const QString &Config::getButton1() const
{
    return button1;
}

void Config::setButton1(const QString &newButton1)
{
    button1 = newButton1;
}

const QString &Config::getButton2() const
{
    return button2;
}

void Config::setButton2(const QString &newButton2)
{
    button2 = newButton2;
}

const QString &Config::getButton3() const
{
    return button3;
}

void Config::setButton3(const QString &newButton3)
{
    button3 = newButton3;
}

const QString &Config::getButton4() const
{
    return button4;
}

void Config::setButton4(const QString &newButton4)
{
    button4 = newButton4;
}

const QString &Config::getButton5() const
{
    return button5;
}

void Config::setButton5(const QString &newButton5)
{
    button5 = newButton5;
}

const QString &Config::getButton6() const
{
    return button6;
}

void Config::setButton6(const QString &newButton6)
{
    button6 = newButton6;
}

const QString &Config::getButton7() const
{
    return button7;
}

void Config::setButton7(const QString &newButton7)
{
    button7 = newButton7;
}

const QString &Config::getButton8() const
{
    return button8;
}

void Config::setButton8(const QString &newButton8)
{
    button8 = newButton8;
}

const QString &Config::getButton9() const
{
    return button9;
}

void Config::setButton9(const QString &newButton9)
{
    button9 = newButton9;
}

const QString &Config::getButtonBackward() const
{
    return buttonBackward;
}

void Config::setButtonBackward(const QString &newButtonBackward)
{
    buttonBackward = newButtonBackward;
}

const QString &Config::getButtonPlayPause() const
{
    return buttonPlayPause;
}

void Config::setButtonPlayPause(const QString &newButtonPlayPause)
{
    buttonPlayPause = newButtonPlayPause;
}

const QString &Config::getButtonForeward() const
{
    return buttonForeward;
}

void Config::setButtonForeward(const QString &newButtonForeward)
{
    buttonForeward = newButtonForeward;
}

bool Config::getEnableToolTips() const
{
    return enableToolTips;
}

void Config::setEnableToolTips(bool newEnableToolTips)
{
    enableToolTips = newEnableToolTips;
}
