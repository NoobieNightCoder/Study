#pragma once

#include "../Service/IShapeService.h"
#include "../UI/IUi.h"
#include "../UI/UiMessageCatalog.h"

class AppController {
private:
    IShapeService& shapeService;
    IUi& ui;

    UiErrorId mapServiceError(ServiceError serviceError) const;

    int createCircle();
    int createRectangle();
    int createTriangle();

    void addShapeMenu();
    void listParamMenu() const;
    void listPerimMenu() const;
    void sumPerimMenu() const;
    void sortListMenu();
    void deleteShapeMenu();
    void deleteShapesByPerimMenu();

public:
    AppController(IShapeService& shapeService, IUi& ui);
    void run();
};
