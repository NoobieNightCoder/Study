#include "chartViewHandler.h"

#include <QBrush>
#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QString>

#include "../BL/memoryHandler.h"

#include "chartConstants.h"
#include "chartGeometry.h"

static QPen getAxisPen() {
    QPen result(ChartConstants::AXIS_COLOR);
    result.setWidth(ChartConstants::AXIS_PEN_WIDTH);
    return result;
}

static QPen getGridPen() {
    QPen result(ChartConstants::GRID_COLOR);
    result.setStyle(Qt::DashLine);
    return result;
}

static QPen getLinePen() {
    QPen result(ChartConstants::LINE_COLOR);
    result.setWidth(ChartConstants::LINE_PEN_WIDTH);
    return result;
}

static QPen getMinLinePen() {
    QPen result(ChartConstants::MIN_LINE_COLOR);
    result.setWidth(ChartConstants::STAT_PEN_WIDTH);
    result.setStyle(Qt::DashLine);
    return result;
}

static QPen getMedianLinePen() {
    QPen result(ChartConstants::MEDIAN_LINE_COLOR);
    result.setWidth(ChartConstants::STAT_PEN_WIDTH);
    result.setStyle(Qt::DotLine);
    return result;
}

static QPen getMaxLinePen() {
    QPen result(ChartConstants::MAX_LINE_COLOR);
    result.setWidth(ChartConstants::STAT_PEN_WIDTH);
    result.setStyle(Qt::DashDotLine);
    return result;
}

static QBrush getPointBrush() {
    QBrush result(ChartConstants::POINT_COLOR);
    return result;
}

static QFont getLabelFont() {
    QFont result;
    result.setPointSize(ChartConstants::LABEL_FONT_SIZE);
    return result;
}

static QFont getLegendFont() {
    QFont result;
    result.setPointSize(ChartConstants::LEGEND_FONT_SIZE);
    return result;
}

static QString getLegendLabel(tableData* table, int column) {
    QString result = "No header name";
    if (table->headers && column - 1 >= 0 && column - 1 < table->headerCount)
        result = QString::fromUtf8(table->headers[column - 1]);
    return result;
}

static void drawPath(QGraphicsScene* scene, const QRectF& rect, const ChartPoint* points, int pointCount, const ChartMetrics* metrics) {
    QPainterPath path;

    for (int i = 0; i < pointCount; i++) {
        QPointF target = ChartGeometry::getPoint(rect, metrics, points[i].year, points[i].value);
        if (i == 0)
            path.moveTo(target.x(), target.y());
        else
            path.lineTo(target.x(), target.y());
    }

    scene->addPath(path, getLinePen());
}

static void drawPoints(QGraphicsScene* scene, const QRectF& rect, const ChartPoint* points, int pointCount, const ChartMetrics* metrics) {
    for (int i = 0; i < pointCount; i++) {
        QPointF target = ChartGeometry::getPoint(rect, metrics, points[i].year, points[i].value);
        scene->addEllipse(target.x() - ChartConstants::DOT_RADIUS,
                          target.y() - ChartConstants::DOT_RADIUS,
                          ChartConstants::DOT_RADIUS * 2, ChartConstants::DOT_RADIUS * 2,
                          QPen(Qt::NoPen), getPointBrush());
    }
}

static void drawLegendItem(QGraphicsScene* scene, const QRectF& rect, int index, const QString& label, const QPen& pen) {
    double sampleX = rect.left() + ChartConstants::LEGEND_SAMPLE_OFFSET.x();
    double sampleY = ChartGeometry::getLegendItemY(rect, index);
    QGraphicsTextItem* labelItem = scene->addText(label, getLegendFont());

    scene->addLine(sampleX, sampleY, sampleX + ChartConstants::LEGEND_SAMPLE_WIDTH, sampleY, pen);
    labelItem->setPos(sampleX + ChartConstants::LEGEND_LABEL_OFFSET.x(), sampleY - ChartConstants::LEGEND_LABEL_OFFSET.y());
}

static void drawStatisticLine(QGraphicsScene* scene, const QRectF& rect, const ChartMetrics* metrics, double value, const QPen& pen) {
    QPointF leftPoint = ChartGeometry::getPoint(rect, metrics, metrics->minYear, value);
    QPointF rightPoint = ChartGeometry::getPoint(rect, metrics, metrics->maxYear, value);
    scene->addLine(leftPoint.x(), leftPoint.y(), rightPoint.x(), rightPoint.y(), pen);
}

static void drawStatisticLines(QGraphicsScene* scene, const QRectF& rect, const ChartMetrics* metrics) {
    drawStatisticLine(scene, rect, metrics, metrics->minValue, getMinLinePen());
    drawStatisticLine(scene, rect, metrics, metrics->medianValue, getMedianLinePen());
    drawStatisticLine(scene, rect, metrics, metrics->maxValue, getMaxLinePen());
}

ChartViewHandler::ChartViewHandler(QGraphicsView* targetView) {
    view = targetView;
    scene = NULL;
    if (view) {
        scene = view->scene();
        if (!scene) {
            scene = new QGraphicsScene(view);
            view->setScene(scene);
        }

        view->setRenderHint(QPainter::Antialiasing, true);
    }
}

void ChartViewHandler::clear() {
    if (scene)
        scene->clear();
}

void ChartViewHandler::drawAxes(const QRectF& rect) {
    if (scene) {
        scene->addLine(rect.left(), rect.top(), rect.left(), rect.bottom(), getAxisPen());
        scene->addLine(rect.left(), rect.bottom(), rect.right(), rect.bottom(), getAxisPen());
    }
}

void ChartViewHandler::drawGrid(const QRectF& rect, const ChartPoint* points, int pointCount, int minYear, int maxYear) {
    if (scene) {
        QPen gridPen = getGridPen();
        double yearSpan = ChartGeometry::normalizeSpan(maxYear - minYear);

        for (int i = 0; i <= ChartConstants::GRID_LINES_COUNT; i++) {
            double ratio = (double)i / ChartConstants::GRID_LINES_COUNT;
            double y = rect.bottom() - ratio * rect.height();
            scene->addLine(rect.left(), y, rect.right(), y, gridPen);
        }

        for (int i = 0; i < pointCount; i++) {
            double x = rect.left() + (points[i].year - minYear) * (rect.width() / yearSpan);
            scene->addLine(x, rect.top(), x, rect.bottom(), gridPen);
        }
    }
}

void ChartViewHandler::drawXAxisLabels(const QRectF& rect, const ChartPoint* points, int pointCount, int minYear, int maxYear) {
    if (scene) {
        QFont labelFont = getLabelFont();
        double yearSpan = ChartGeometry::normalizeSpan(maxYear - minYear);

        for (int i = 0; i < pointCount; i++) {
            double x = rect.left() + (points[i].year - minYear) * (rect.width() / yearSpan);
            QGraphicsTextItem* yearItem = scene->addText(QString::number(points[i].year), labelFont);
            yearItem->setPos(x - (yearItem->boundingRect().width() / 2), rect.bottom() + ChartConstants::LABEL_OFFSET.y());
        }
    }
}

void ChartViewHandler::drawYAxisLabels(const QRectF& rect, double minValue, double maxValue) {
    if (scene) {
        QFont labelFont = getLabelFont();

        for (int i = 0; i <= ChartConstants::GRID_LINES_COUNT; i++) {
            double ratio = (double)i / ChartConstants::GRID_LINES_COUNT;
            double value = minValue + (maxValue - minValue) * ratio;
            double y = rect.bottom() - ratio * rect.height();
            QGraphicsTextItem* valueItem = scene->addText(QString::number(value, 'f', 2), labelFont);
            valueItem->setPos(rect.left() - valueItem->boundingRect().width() - ChartConstants::LABEL_OFFSET.x(), y - (valueItem->boundingRect().height() / 2));
        }
    }
}

void ChartViewHandler::drawLegend(const QRectF& rect, const QString& label) {
    if (scene) {
        QPen framePen(ChartConstants::LEGEND_FRAME_COLOR);
        QGraphicsTextItem* titleItem = scene->addText("Legend", getLegendFont());

        scene->addRect(rect, framePen);
        titleItem->setPos(rect.left() + ChartConstants::LEGEND_TITLE_OFFSET.x(), rect.top() + ChartConstants::LEGEND_TITLE_OFFSET.y());

        drawLegendItem(scene, rect, 0, label, getLinePen());
        drawLegendItem(scene, rect, 1, "Minimum", getMinLinePen());
        drawLegendItem(scene, rect, 2, "Median", getMedianLinePen());
        drawLegendItem(scene, rect, 3, "Maximum", getMaxLinePen());
    }
}

void ChartViewHandler::showTable(tableData* table, int column) {
    QRectF plotRect;
    QRectF legendRect;
    ChartMetrics metrics;
    ChartPoint* points = NULL;
    AppStatus status = NO_TABLE;
    int pointCount = 0;
    int canDraw = 0;

    if (scene && view) {
        scene->clear();
        scene->setSceneRect(0, 0, view->viewport()->width(), view->viewport()->height());
        plotRect = ChartGeometry::getPlotRect(view);
        legendRect = ChartGeometry::getLegendRect(plotRect);
        canDraw = ChartGeometry::isValidRect(plotRect);
    }

    if (canDraw)
        status = buildMedianChartPoints(table, column, &metrics, &points, &pointCount);

    if (canDraw && status == OK) {
        drawGrid(plotRect, points, pointCount, metrics.minYear, metrics.maxYear);
        drawAxes(plotRect);
        drawXAxisLabels(plotRect, points, pointCount, metrics.minYear, metrics.maxYear);
        drawYAxisLabels(plotRect, metrics.minValue, metrics.maxValue);
        drawStatisticLines(scene, plotRect, &metrics);
        drawPath(scene, plotRect, points, pointCount, &metrics);
        drawPoints(scene, plotRect, points, pointCount, &metrics);
        drawLegend(legendRect, getLegendLabel(table, column));
    }

    freeChartPoints(points);
}
