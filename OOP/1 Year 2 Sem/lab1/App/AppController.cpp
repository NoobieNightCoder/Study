#include "AppController.h"

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

AppController::AppController(IShapeService& service, IUi& userInterface)
    : shapeService(service), ui(userInterface) {}

UiErrorId AppController::mapServiceError(ServiceError serviceError) const {
    UiErrorId result = UiErrorId::badItem;

    if (serviceError == ServiceError::badRadius) {
        result = UiErrorId::badRadius;
    } else if (serviceError == ServiceError::badShape) {
        result = UiErrorId::badShape;
    } else if (serviceError == ServiceError::badId) {
        result = UiErrorId::badId;
    }

    return result;
}

void AppController::createCircle() {
    int errorCode = ui.noError();
    double radius = 0;
    Point centre;

    string name = ui.readName();

    radius = ui.readRadius();
    centre = ui.readCentre();
    shapeService.addCircle(name, centre, radius);
}

void AppController::createRectangle() {
    vector<Point> vertices;

    string name = ui.readName();
    vertices = ui.readRectangleVertices();
    shapeService.addRectangle(name, vertices);
}

void AppController::createTriangle() {    
    vector<Point> vertices;

    string name = ui.readName();
    vertices = ui.readTriangleVertices();
    shapeService.addTriangle(name, vertices);
}

void AppController::addShapeMenu() {
    ui.printAddShapeMenu();
    int item = ui.readMenuItem();

    if (item == (int)(ShapeMenuId::circle)) {
        createCircle();
    } else if (item == (int)(ShapeMenuId::rectangle)) {
        createRectangle();
    } else if (item == (int)(ShapeMenuId::triangle)) {
        createTriangle();
    } else {
        throw (int)(UiErrorId::badItem);
    }
    ui.printMessage(UiMessageId::shapeAdded);
}

void AppController::listParamMenu() const {
    bool hasShapes = !shapeService.isEmpty();
    int index = 1;

    if (hasShapes) {
        for (const auto& shape : shapeService.getShapes()) {
            ui.printShapeParameters(*shape, index);
            index += 1;
        }
    } else {
        throw (int)UiErrorId::emptyList;
    }
}

void AppController::listPerimMenu() const {
    bool hasShapes = !shapeService.isEmpty();
    int index = 1;

    if (hasShapes) {
        for (const auto& shape : shapeService.getShapes()) {
            ui.printShapePerimeter(*shape, index);
            index += 1;
        }
    } else {
        throw (int)UiErrorId::emptyList;
    }
}

void AppController::listShapesMenu() const {
    bool hasShapes = !shapeService.isEmpty();
    int index = 1;

    if (hasShapes) {
        for (const auto& shape : shapeService.getShapes()) {
            ui.printShape(*shape, index);
            index += 1;
        }
    } else {
        throw (int)UiErrorId::emptyList;
    }
}

void AppController::sumPerimMenu() const {
    bool hasShapes = !shapeService.isEmpty();
    if (hasShapes) {
        ui.printMessage(UiMessageId::sumPerimeters, shapeService.sumPerimeters());
    } else {
        throw (int)UiErrorId::emptyList;
    }
}

void AppController::sortListMenu() {
    bool hasShapes = !shapeService.isEmpty();
    if (hasShapes) {
        shapeService.sortByPerimeter();
        ui.printMessage(UiMessageId::listSorted);
    } else {
        throw (int)UiErrorId::emptyList;
    }
}

void AppController::deleteShapeMenu() {
    bool hasShapes = !shapeService.isEmpty();

    
    if (hasShapes) {
        int shapeId = ui.readShapeId();
        ServiceError serviceError = shapeService.deleteById(shapeId);
        bool hasServiceError = serviceError != ServiceError::none;
        if (hasServiceError) {
            throw (int)mapServiceError(serviceError);
        }
    }
    if (!hasShapes) {
        throw (int)UiErrorId::emptyList;
    }

    ui.printMessage(UiMessageId::shapeDeleted);
}

void AppController::deleteShapesByPerimMenu() {
    bool hasShapes = !shapeService.isEmpty();
    double limit = 0;

    if (hasShapes) {
        limit = ui.readPerimeterThreshold();
    }
    if (!hasShapes) {
        throw (int)(UiErrorId::emptyList);
    }
    shapeService.deleteByPerimeter(limit);
    ui.printMessage(UiMessageId::shapesDeleted);

}

void AppController::run() {
    bool shouldContinue = true;
    unordered_map<int, function<void()>> menuHandlers {
        {(int)MainMenuId::addShape,                   [this]() { addShapeMenu(); }                    },
        {(int)MainMenuId::printListParameters,        [this]() { listParamMenu(); }                   },
        {(int)MainMenuId::printListPerimeters,        [this]() { listPerimMenu(); }                   },
        {(int)MainMenuId::printListShapes,            [this]() { listShapesMenu(); }                  },
        {(int)MainMenuId::printPerimeterSum,          [this]() { sumPerimMenu(); }                    },
        {(int)MainMenuId::sortShapes,                 [this]() { sortListMenu(); }                    },
        {(int)MainMenuId::deleteShape,                [this]() { deleteShapeMenu(); }                 },
        {(int)MainMenuId::deleteShapesByPerimeter,    [this]() { deleteShapesByPerimMenu(); }         },
        {(int)MainMenuId::exitProgram,                [&shouldContinue]() { shouldContinue = false; } }
    };

    while (shouldContinue) {
        try {
            ui.printMainMenu();
            int item = ui.readMenuItem();
            auto iterator = menuHandlers.find(item);
            bool hasHandler = iterator != menuHandlers.end();

            if (hasHandler) {
                iterator->second();
            } else {
                throw (int)UiErrorId::badItem;
            }
        } catch(int errorCode) {
            ui.printError((UiErrorId)errorCode);
        }
    }
}
