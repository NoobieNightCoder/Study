#pragma once

#include <QString>

#include "../BL/tableHandler.h"
#include "../BL/memoryHandler.h"
#include "../BL/calculator.h"
#include "../BL/errorHandler.h"

class AppController {
private:
    tableData* globalTable;
    tableData* targetTable;

    QString targetRegion;
    int targetColumn;
    bool targetIsGlobal;

    void clearGlobalTable();
    void clearTargetTable();

public:
    AppController();
    ~AppController();

    bool loadGlobalTable(QString filename);
    tableData* getGlobalTable();
    tableData* getTargetTable();

    void setTargetRegion(QString region);
    void setTargetColumn(int column);

    AppStatus calculateStats(CalcResult* result);
};
