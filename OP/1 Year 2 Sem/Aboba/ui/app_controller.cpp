#include "app_controller.h"
#include "../logic/logic.h"

QString AppController::handleButtonClick()
{
    const char* text = get_new_text();
    return QString::fromUtf8(text);
}
