#include "App/AppController.h"
#include "Service/ShapeService.h"
#include "UI/ConsoleUi.h"
#include "UI/InputOutputUI.h"


int main() {
    InputOutputUI inputOutputUi;
    ConsoleUi ui(inputOutputUi);
    ShapeService shapeService;
    AppController appController(shapeService, ui);
    
    appController.run();

    return 0;
}