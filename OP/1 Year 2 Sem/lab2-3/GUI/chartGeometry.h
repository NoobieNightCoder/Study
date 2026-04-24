#pragma once

#include <QGraphicsView>
#include <QPointF>
#include <QRectF>

#include "../BL/chartHandler.h"

namespace ChartGeometry {
int isValidRect(const QRectF& rect);
double normalizeSpan(double value);
double getLegendItemY(const QRectF& rect, int index);
QRectF getPlotRect(QGraphicsView* view);
QRectF getLegendRect(const QRectF& plotRect);
QPointF getPoint(const QRectF& rect, const ChartMetrics* metrics, int year, double value);
}
