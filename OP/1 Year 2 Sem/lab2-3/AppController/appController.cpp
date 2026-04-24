#include "appController.h"

AppController::AppController() {
    globalTable = NULL;
    targetTable = NULL;
    targetColumn = 1;
    targetIsGlobal = true;
}

AppController::~AppController() {
    clearTargetTable();
    clearGlobalTable();
}

void AppController::clearGlobalTable() {
    if (globalTable) {
        freeTable(globalTable);
        globalTable = NULL;
    }
}

void AppController::clearTargetTable() {
    if (targetTable && !targetIsGlobal) {
        freeTable(targetTable);
    }
    targetTable = NULL;
    targetIsGlobal = true;
}

bool AppController::loadGlobalTable(QString filename) {
    bool result = false;
    tableData* newTable = NULL;

    if (!filename.trimmed().isEmpty()) {
        QByteArray arr = filename.toUtf8();
        const char* filenamePath = arr.constData();
        newTable = readTable(filenamePath);
    }

    if (newTable) {
        clearTargetTable();
        clearGlobalTable();
        globalTable = newTable;
        targetTable = globalTable;
        targetIsGlobal = true;
        result = true;
    }

    return result;
}

tableData* AppController::getGlobalTable() {
    return globalTable;
}

tableData* AppController::getTargetTable() {
    return targetTable;
}

void AppController::setTargetRegion(QString region) {
    targetRegion = region;
    clearTargetTable();

    if (globalTable) {
        if (targetRegion.trimmed().isEmpty()) {
            targetTable = globalTable;
            targetIsGlobal = true;
        } else {
            QByteArray arr = targetRegion.toUtf8();
            const char* regionFilter = arr.constData();
            targetTable = filterTable(globalTable, regionFilter);
            targetIsGlobal = false;
        }
    }
}

void AppController::setTargetColumn(int column) {
    targetColumn = column;
}

AppStatus AppController::calculateStats(CalcResult* result) {
    AppStatus status = NO_TABLE;

    if (targetRegion.trimmed().isEmpty())
        status = NO_REGION;
    else
        status = calcTableStats(targetTable, targetColumn, result);

    return status;
}
