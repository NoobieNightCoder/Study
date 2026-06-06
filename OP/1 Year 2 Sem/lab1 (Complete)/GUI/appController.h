#pragma once

#include <QString>
#include "../BL/conversionMain.h"

class AppController {
private:
    QString InputText;
    QString OutputText;
    QString ErrorText;
    Base InputBase = BASE_DEC;
    Base OutputBase = BASE_DEC;

public:
    struct ConversionResponse {
        QString ResultText;
        QString ErrorText;
    };

    void setInputBase(Base input);
    void setOutputBase(Base output);

    Base getInputBase();
    Base getOutputBase();

    QString getInputText();
    QString getOutputText();
    QString getErrorText();

    void setInputText(QString input);
    void setOutputText(QString output);

    void Convert();

    bool SwapValues();
};