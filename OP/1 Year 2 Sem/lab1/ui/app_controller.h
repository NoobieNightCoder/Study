#pragma once

#include <QString>
#include "../logic/logic.h"

class AppController
{
public:
    AppController() = default;

    struct ConversionResponse
    {
        QString ResultText;
        QString ErrorText;
    };

    ConversionResponse Convert(
        const QString& InputText,
        Base InputBase,
        Base OutputBase);

    bool SwapValues(
        QString& InputText,
        Base& InputBase,
        QString& OutputText,
        Base& OutputBase,
        QString& ErrorText);
};