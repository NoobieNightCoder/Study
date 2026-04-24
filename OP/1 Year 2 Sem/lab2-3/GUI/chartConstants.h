#pragma once

#include <QColor>
#include <QPoint>

namespace ChartConstants {
static const int MARGIN_LEFT = 70;
static const int MARGIN_RIGHT = 20;
static const int MARGIN_TOP = 20;
static const int MARGIN_BOTTOM = 60;
static const int COLUMN_OFFSET = 2;

static const int LEGEND_WIDTH = 160;
static const int LEGEND_OFFSET = 20;
static const int LEGEND_SAMPLE_WIDTH = 36;
static const int LEGEND_ITEM_STEP = 28;

static const int GRID_LINES_COUNT = 5;
static const int DOT_RADIUS = 5;

static const int AXIS_PEN_WIDTH = 2;
static const int LINE_PEN_WIDTH = 2;
static const int STAT_PEN_WIDTH = 2;

static const int LABEL_FONT_SIZE = 8;
static const int LEGEND_FONT_SIZE = 9;

static const QColor AXIS_COLOR(60, 60, 60);
static const QColor GRID_COLOR(190, 190, 190);
static const QColor LEGEND_FRAME_COLOR(140, 140, 140);

static const QColor LINE_COLOR(40, 120, 200);
static const QColor POINT_COLOR(50, 50, 200);
static const QColor MIN_LINE_COLOR(60, 160, 90);
static const QColor MEDIAN_LINE_COLOR(210, 140, 50);
static const QColor MAX_LINE_COLOR(200, 70, 70);

static const QPoint LEGEND_TITLE_OFFSET(10, 10);
static const QPoint LEGEND_SAMPLE_OFFSET(12, 45);
static const QPoint LEGEND_LABEL_OFFSET(46, 12);
static const QPoint LABEL_OFFSET(8, 6);
}
