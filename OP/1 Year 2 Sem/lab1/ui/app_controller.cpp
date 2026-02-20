#include "app_controller.h"
#include "../logic/logic.h"

QString AppController::handleButtonClick(QString input, int modeFrom, int modeTo)
{
    std::string convertedInput = input.toStdString();
    char* text = convertNum(convertedInput.c_str(), modeFrom, modeTo);
    QString result = QString::fromUtf8(text);

    free(text);
    return result;
}
