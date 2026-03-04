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

int AppController::createCircle() {
    int errorCode = ui.noError();
    string name = ui.readName(errorCode);
    double radius = 0;
    Point centre;

    if (errorCode == ui.noError()) {
        radius = ui.readRadius(errorCode);
    }
    if (errorCode == ui.noError()) {
        centre = ui.readCentre();
        ServiceError serviceError = shapeService.addCircle(name, centre, radius);
        bool hasServiceError = serviceError != ServiceError::none;
        if (hasServiceError) {
            errorCode = (int)(mapServiceError(serviceError));
        }
    }

    return errorCode;
}

int AppController::createRectangle() {
    int errorCode = ui.noError();
    string name = ui.readName(errorCode);
    vector<Point> vertices;

    if (errorCode == ui.noError()) {
        vertices = ui.readRectangleVertices();
        ServiceError serviceError = shapeService.addRectangle(name, vertices);
        bool hasServiceError = serviceError != ServiceError::none;
        if (hasServiceError) {
            errorCode = (int)(mapServiceError(serviceError));
        }
    }

    return errorCode;
}

int AppController::createTriangle() {
    int errorCode = ui.noError();
    string name = ui.readName(errorCode);
    vector<Point> vertices;

    if (errorCode == ui.noError()) {
        vertices = ui.readTriangleVertices();
        ServiceError serviceError = shapeService.addTriangle(name, vertices);
        bool hasServiceError = serviceError != ServiceError::none;
        if (hasServiceError) {
            errorCode = (int)(mapServiceError(serviceError));
        }
    }

    return errorCode;
}

void AppController::addShapeMenu() {
    int errorCode = ui.noError();
    ui.printAddShapeMenu();
    int item = ui.readMenuItem();

    if (item == (int)(ShapeMenuId::circle)) {
        errorCode = createCircle();
    } else if (item == (int)(ShapeMenuId::rectangle)) {
        errorCode = createRectangle();
    } else if (item == (int)(ShapeMenuId::triangle)) {
        errorCode = createTriangle();
    } else {
        errorCode = (int)(UiErrorId::badItem);
    }

    if (errorCode == ui.noError()) {
        ui.printMessage(UiMessageId::shapeAdded);
    } else {
        ui.printError((UiErrorId)(errorCode));
    }
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
        ui.printError(UiErrorId::emptyList);
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
        ui.printError(UiErrorId::emptyList);
    }
}

void AppController::sumPerimMenu() const {
    bool hasShapes = !shapeService.isEmpty();
    if (hasShapes) {
        ui.printMessage(UiMessageId::sumPerimeters, shapeService.sumPerimeters());
    } else {
        ui.printError(UiErrorId::emptyList);
    }
}

void AppController::sortListMenu() {
    bool hasShapes = !shapeService.isEmpty();
    if (hasShapes) {
        shapeService.sortByPerimeter();
        ui.printMessage(UiMessageId::listSorted);
    } else {
        ui.printError(UiErrorId::emptyList);
    }
}

void AppController::deleteShapeMenu() {
    bool hasShapes = !shapeService.isEmpty();
    int errorCode = ui.noError();

    
    if (hasShapes) {
        int shapeId = ui.readShapeId();
        ServiceError serviceError = shapeService.deleteById(shapeId);
        bool hasServiceError = serviceError != ServiceError::none;
        if (hasServiceError) {
            errorCode = (int)(mapServiceError(serviceError));
        }
    }
    if (!hasShapes) {
        errorCode = (int)(UiErrorId::emptyList);
    }

    if (errorCode == ui.noError()) {
        ui.printMessage(UiMessageId::shapeDeleted);
    } else {
        ui.printError((UiErrorId)(errorCode));
    }
}

void AppController::deleteShapesByPerimMenu() {
    bool hasShapes = !shapeService.isEmpty();
    int errorCode = ui.noError();
    double limit = 0;

    if (hasShapes) {
        limit = ui.readPerimeterThreshold(errorCode);
    }
    if (!hasShapes) {
        errorCode = (int)(UiErrorId::emptyList);
    }
    if (errorCode == ui.noError()) {
        shapeService.deleteByPerimeter(limit);
        ui.printMessage(UiMessageId::shapesDeleted);
    } else {
        ui.printError((UiErrorId)errorCode);
    }
}

void AppController::run() {
    bool shouldContinue = true;
    unordered_map<int, function<void()>> menuHandlers {
        {(int)MainMenuId::addShape,                   [this]() { addShapeMenu(); }                    },
        {(int)MainMenuId::printListParameters,        [this]() { listParamMenu(); }                   },
        {(int)MainMenuId::printListPerimeters,        [this]() { listPerimMenu(); }                   },
        {(int)MainMenuId::printPerimeterSum,          [this]() { sumPerimMenu(); }                    },
        {(int)MainMenuId::sortShapes,                 [this]() { sortListMenu(); }                    },
        {(int)MainMenuId::deleteShape,                [this]() { deleteShapeMenu(); }                 },
        {(int)MainMenuId::deleteShapesByPerimeter,    [this]() { deleteShapesByPerimMenu(); }         },
        {(int)MainMenuId::exitProgram,                [&shouldContinue]() { shouldContinue = false; } }
    };

    while (shouldContinue) {
        ui.printMainMenu();
        int item = ui.readMenuItem();
        auto iterator = menuHandlers.find(item);
        bool hasHandler = iterator != menuHandlers.end();

        if (hasHandler) {
            iterator->second();
        } else {
            ui.printError(UiErrorId::badItem);
        }
    }
}
