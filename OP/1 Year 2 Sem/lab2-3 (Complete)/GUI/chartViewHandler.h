#pragma once

#include <QGraphicsView>
#include <QRectF>
#include <QString>

#include "../BL/chartHandler.h"

class QGraphicsScene;

class ChartViewHandler {
private:
    QGraphicsView* view;
    QGraphicsScene* scene;

    void drawAxes(const QRectF& rect);
    void drawGrid(const QRectF& rect, const ChartPoint* points, int pointCount, int minYear, int maxYear);
    void drawXAxisLabels(const QRectF& rect, const ChartPoint* points, int pointCount, int minYear, int maxYear);
    void drawYAxisLabels(const QRectF& rect, double minValue, double maxValue);
    void drawLegend(const QRectF& rect, const QString& label);
    
public:
    explicit ChartViewHandler(QGraphicsView* view = nullptr);

    void showTable(tableData* table, int column);
    void clear();
};
