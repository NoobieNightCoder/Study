#include "app_controller.h"
#include "../logic/logic.h"

QString AppController::handleButtonClick(QString aboba)
{
    std::string loh = aboba.toStdString();
    const char* text = get_new_text(loh.c_str());
    return QString::fromUtf8(text);
}
