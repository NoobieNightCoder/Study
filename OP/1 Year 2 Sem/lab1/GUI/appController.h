#pragma once

#include <QString>
#include "../BL/conversionMain.h"

class AppController {
private:
    QString InputText;
    QString OutputText;
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

    void setInputText(QString input);
    void setOutputText(QString output);

    ConversionResponse Convert();

    bool SwapValues(QString& ErrorText);
};