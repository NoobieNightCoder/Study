#include "chartGeometry.h"

#include "chartConstants.h"

namespace ChartGeometry {
int isValidRect(const QRectF& rect) {
    int result = 0;
    if (rect.width() > 0 && rect.height() > 0)
        result = 1;
    return result;
}

double normalizeSpan(double value) {
    double result = value;
    if (!result)
        result = 1;
    return result;
}

double getLegendItemY(const QRectF& rect, int index) {
    double result = rect.top() + ChartConstants::LEGEND_SAMPLE_OFFSET.y() + index * ChartConstants::LEGEND_ITEM_STEP;
    return result;
}

QRectF getPlotRect(QGraphicsView* view) {
    QRectF result;
    if (view) {
        QRectF fullRect(0, 0, view->viewport()->width(), view->viewport()->height());
        result = QRectF(fullRect.left() + ChartConstants::MARGIN_LEFT,
                        fullRect.top() + ChartConstants::MARGIN_TOP,
                        fullRect.width() - ChartConstants::MARGIN_LEFT - ChartConstants::MARGIN_RIGHT
                        - ChartConstants::LEGEND_WIDTH - ChartConstants::LEGEND_OFFSET,
                        fullRect.height() - ChartConstants::MARGIN_TOP - ChartConstants::MARGIN_BOTTOM);
    }
    return result;
}

QRectF getLegendRect(const QRectF& plotRect) {
    QRectF result(plotRect.right() + ChartConstants::LEGEND_OFFSET, plotRect.top(), ChartConstants::LEGEND_WIDTH, plotRect.height());
    return result;
}

QPointF getPoint(const QRectF& rect, const ChartMetrics* metrics, int year, double value) {
    double yearSpan = normalizeSpan(metrics->maxYear - metrics->minYear);
    double valueSpan = normalizeSpan(metrics->maxValue - metrics->minValue);
    double x = rect.left() + (year - metrics->minYear) * (rect.width() / yearSpan);
    double y = rect.top() + (metrics->maxValue - value) * (rect.height() / valueSpan);
    QPointF result(x, y);
    return result;
}
}
