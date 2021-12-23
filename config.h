#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QColor>
#include <QJsonObject>

#include <iostream>

class Config
{
public:
    Config();
    Config(QJsonObject *jsonConfig);

    QJsonObject *toJsonObject();

    ~Config();

    const QString &getIp() const;
    void setIp(const QString &newIp);

    const QString &getPort() const;
    void setPort(const QString &newPort);

    const QColor &getButtonColor() const;
    void setButtonColor(const QColor &newButtonColor);
    void setRedButtonColor(const int &red);
    void setGreenButtonColor(const int &green);
    void setBlueButtonColor(const int &blue);
    void setButtonColorFromString(const QString &newColorName);

    const QColor &getBackgroundColor() const;
    void setBackgroundColor(const QColor &newBackgroundColor);
    void setRedBackgroundColor(const int &red);
    void setGreenBackgroundColor(const int &green);
    void setBlueBackgroundColor(const int &blue);
    void setBackgroundColorFromString(const QString &newColorName);

    const QString &getButtonOnOff() const;
    void setButtonOnOff(const QString &newButtonOnOff);

    const QString &getButtonMenu() const;
    void setButtonMenu(const QString &newButtonMenu);
    const QString &getButtonNetflix() const;
    void setButtonNetflix(const QString &newButtonNetflix);
    const QString &getButtonBack() const;
    void setButtonBack(const QString &newButtonBack);
    const QString &getButtonSettings() const;
    void setButtonSettings(const QString &newButtonSettings);

    const QString &getButtonUp() const;
    void setButtonUp(const QString &newButtonUp);
    const QString &getButtonLeft() const;
    void setButtonLeft(const QString &newButtonLeft);
    const QString &getButtonOk() const;
    void setButtonOk(const QString &newButtonOk);
    const QString &getButtonRight() const;
    void setButtonRight(const QString &newButtonRight);
    const QString &getButtonDown() const;
    void setButtonDown(const QString &newButtonDown);

    const QString &getButtonVolDown() const;
    void setButtonVolDown(const QString &newButtonVolDown);
    const QString &getButtonMute() const;
    void setButtonMute(const QString &newButtonMute);
    const QString &getButtonVolUp() const;
    void setButtonVolUp(const QString &newButtonVolUp);

    const QString &getButton0() const;
    void setButton0(const QString &newButton0);
    const QString &getButton1() const;
    void setButton1(const QString &newButton1);
    const QString &getButton2() const;
    void setButton2(const QString &newButton2);
    const QString &getButton3() const;
    void setButton3(const QString &newButton3);
    const QString &getButton4() const;
    void setButton4(const QString &newButton4);
    const QString &getButton5() const;
    void setButton5(const QString &newButton5);
    const QString &getButton6() const;
    void setButton6(const QString &newButton6);
    const QString &getButton7() const;
    void setButton7(const QString &newButton7);
    const QString &getButton8() const;
    void setButton8(const QString &newButton8);
    const QString &getButton9() const;
    void setButton9(const QString &newButton9);

    const QString &getButtonBackward() const;
    void setButtonBackward(const QString &newButtonBackward);
    const QString &getButtonPlayPause() const;
    void setButtonPlayPause(const QString &newButtonPlayPause);
    const QString &getButtonForeward() const;
    void setButtonForeward(const QString &newButtonForeward);

    bool getEnableToolTips() const;
    void setEnableToolTips(bool newEnableToolTips);

private:
    // network
    QString ip;
    QString port;

    // colors
    QColor buttonColor;
    QColor backgroundColor;

    // shortcut
    QString buttonOnOff;

    QString buttonMenu;
    QString buttonNetflix;
    QString buttonBack;
    QString buttonSettings;

    QString buttonUp;
    QString buttonLeft;
    QString buttonOk;
    QString buttonRight;
    QString buttonDown;

    QString buttonVolDown;
    QString buttonMute;
    QString buttonVolUp;

    QString button0;
    QString button1;
    QString button2;
    QString button3;
    QString button4;
    QString button5;
    QString button6;
    QString button7;
    QString button8;
    QString button9;

    QString buttonBackward;
    QString buttonPlayPause;
    QString buttonForeward;

    bool enableToolTips;

};

#endif // CONFIG_H
