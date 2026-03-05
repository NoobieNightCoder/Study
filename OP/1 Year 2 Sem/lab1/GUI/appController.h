#pragma once

#include <QString>
#include "../BL/conversionMain.h"

class AppController {
public:
    struct ConversionResponse {
        QString ResultText;
        QString ErrorText;
    };

    ConversionResponse Convert(const QString& InputText, Base InputBase, Base OutputBase);

    bool SwapValues(QString& InputText, Base& InputBase, QString& OutputText, Base& OutputBase, QString& ErrorText);
};