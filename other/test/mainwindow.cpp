#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  setGeometry(300, 300, 500, 500);
  mCustomPlot = new QCustomPlot(this);
  QHBoxLayout *layout = new QHBoxLayout();
  ui->centralWidget->setLayout(layout);
  layout->insertWidget(0, mCustomPlot);
  mCustomPlot->axisRect()->setupFullAxesBox(true);
  
  /*
  QVector<double> ticks = QVector<double>() << 1 << 2 << 4 << 8 << 16 << 32;
  mCustomPlot->xAxis->setAutoTicks(false);
  mCustomPlot->xAxis->setTickVector(ticks);
  */
  
  presetInteractive(mCustomPlot);
  //setupItemAnchorTest(mCustomPlot);
  //setupItemTracerTest(mCustomPlot);
  //setupGraphTest(mCustomPlot);
  //setupExportTest(mCustomPlot);
  //setupLogErrorsTest(mCustomPlot);
  //setupSelectTest(mCustomPlot);
  //setupDateTest(mCustomPlot);
  //setupIntegerTickStepCase(mCustomPlot);
  //setupTickLabelTest(mCustomPlot);
  //setupDaqPerformance(mCustomPlot);
  //setupLayoutTest(mCustomPlot);
  //setupMultiAxisTest(mCustomPlot);
  //setupLayoutElementBugTest(mCustomPlot);
  //setupMarginGroupTest(mCustomPlot);
  //setupInsetLayoutTest(mCustomPlot);
  //setupLegendTest(mCustomPlot);
  setupMultiAxisRectInteractions(mCustomPlot);
  
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::setupItemAnchorTest(QCustomPlot *customPlot)
{
  customPlot->xAxis->setRange(-3, 3);
  customPlot->yAxis->setRange(-3, 3);
  customPlot->xAxis->setAutoTickCount(5);
  customPlot->yAxis->setAutoTickCount(5);
 
  QCPItemPixmap *pixmapItem = new QCPItemPixmap(customPlot);
  customPlot->addItem(pixmapItem);
  pixmapItem->setPixmap(QPixmap("./gnu.png"));
  pixmapItem->setScaled(true);
  pixmapItem->topLeft->setCoords(-2, 2);
  pixmapItem->bottomRight->setCoords(-1, 1);
  labelItemAnchors(pixmapItem);
  
  QCPItemPixmap *pixmapItem2 = new QCPItemPixmap(customPlot);
  customPlot->addItem(pixmapItem2);
  pixmapItem2->setPixmap(QPixmap("./gnu.png"));
  pixmapItem2->setScaled(true);
  pixmapItem2->topLeft->setCoords(1, 0.5);
  pixmapItem2->bottomRight->setCoords(0, 2);
  labelItemAnchors(pixmapItem2);
  
  QCPItemRect *rect = new QCPItemRect(customPlot);
  customPlot->addItem(rect);
  rect->topLeft->setCoords(-2, 0);
  rect->bottomRight->setCoords(-1, -0.5);
  labelItemAnchors(rect);
  
  QCPItemRect *rect2 = new QCPItemRect(customPlot);
  customPlot->addItem(rect2);
  rect2->topLeft->setCoords(0, -1);
  rect2->bottomRight->setCoords(-0.5, 0);
  labelItemAnchors(rect2);
  
  QCPItemEllipse *ellipse = new QCPItemEllipse(customPlot);
  customPlot->addItem(ellipse);
  ellipse->topLeft->setCoords(0.5, 0);
  ellipse->bottomRight->setCoords(1, -1);
  labelItemAnchors(ellipse);
  
  QCPItemEllipse *ellipse2 = new QCPItemEllipse(customPlot);
  customPlot->addItem(ellipse2);
  ellipse2->topLeft->setCoords(2, -1);
  ellipse2->bottomRight->setCoords(1.1, 0.2);
  labelItemAnchors(ellipse2);
  
  QCPItemLine *line = new QCPItemLine(customPlot);
  customPlot->addItem(line);
  line->start->setCoords(-2, -1.5);
  line->end->setCoords(-1, -1.2);
  labelItemAnchors(line);
  
  QCPItemCurve *curve = new QCPItemCurve(customPlot);
  customPlot->addItem(curve);
  curve->start->setCoords(0, -1.5);
  curve->startDir->setCoords(1, -1.5);
  curve->endDir->setCoords(1, -1.2);
  curve->end->setCoords(2, -1.2);
  labelItemAnchors(curve);
  
  QCPItemBracket *bracket = new QCPItemBracket(customPlot);
  customPlot->addItem(bracket);
  bracket->left->setCoords(-2, -2);
  bracket->right->setCoords(2, -2);
  bracket->setLength(12);
  labelItemAnchors(bracket);
  
  QCPItemText *text = new QCPItemText(customPlot);
  customPlot->addItem(text);
  text->position->setCoords(0, -2.6);
  text->setText("QCustomPlot");
  text->setFont(QFont(font().family(), 26));
  text->setRotation(12);
  text->setPadding(QMargins(5, 5, 40, 5));
  text->setBrush(QBrush(QColor(0, 0, 0, 30)));
  labelItemAnchors(text);
}

void MainWindow::setupItemTracerTest(QCustomPlot *customPlot)
{
  QCPItemTracer *tracer1 = new QCPItemTracer(customPlot);
  customPlot->addItem(tracer1);
  tracer1->position->setCoords(1, 3);
  tracer1->setStyle(QCPItemTracer::tsCircle);
  tracer1->setSize(20);

  QCPItemTracer *tracer2 = new QCPItemTracer(customPlot);
  customPlot->addItem(tracer2);
  tracer2->position->setCoords(2, 2.5);
  tracer2->setStyle(QCPItemTracer::tsCrosshair);

  QCPItemTracer *tracer3 = new QCPItemTracer(customPlot);
  customPlot->addItem(tracer3);
  tracer3->position->setCoords(3, 2);
  tracer3->setStyle(QCPItemTracer::tsPlus);
  tracer3->setSize(20);

  QCPItemTracer *tracer4 = new QCPItemTracer(customPlot);
  customPlot->addItem(tracer4);
  tracer4->position->setCoords(4, 1.5);
  tracer4->setStyle(QCPItemTracer::tsSquare);
  tracer4->setSize(20);

  QCPGraph *graph = customPlot->addGraph();
  int n = 20;
  QVector<double> x(n), y(n);
  for (int i=0; i<n; ++i)
  {
    x[i] = 0.5+i/(double)n*4;
    y[i] = qSin(x[i])+1.5;
  }
  graph->setData(x, y);

  QCPItemTracer *graphTracer = new QCPItemTracer(customPlot);
  customPlot->addItem(graphTracer);
  graphTracer->setGraph(graph);
  graphTracer->setGraphKey(2.3);
  graphTracer->setStyle(QCPItemTracer::tsNone);
  graphTracer->setInterpolating(true);
  tracerTestTracer = graphTracer;
  connect(customPlot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(tracerTestMouseMove(QMouseEvent*)));
  graphTracer->setStyle(QCPItemTracer::tsSquare);

  QCPItemText *text = new QCPItemText(customPlot);
  customPlot->addItem(text);
  text->setText("Tracer");
  text->setPositionAlignment(Qt::AlignBottom|Qt::AlignHCenter);
  text->position->setType(QCPItemPosition::ptAxisRectRatio);
  text->position->setCoords(0.5, 0.05);
  text->setPen(QPen());

  QCPItemCurve *curve = new QCPItemCurve(customPlot);
  customPlot->addItem(curve);
  curve->start->setParentAnchor(text->bottom);
  curve->startDir->setParentAnchor(curve->start);
  curve->startDir->setCoords(0, 100);
  curve->end->setParentAnchor(tracerTestTracer->position);
  curve->end->setCoords(0, -5);
  curve->endDir->setParentAnchor(curve->end);
  curve->endDir->setCoords(0, -100);
  curve->setHead(QCPLineEnding::esSpikeArrow);
}

void MainWindow::setupGraphTest(QCustomPlot *customPlot)
{
  customPlot->addGraph();

  QCPDataMap *dataMap = new QCPDataMap;
  int n = 10e6;
  QTime t;
  t.start();
  for (int i=0; i<n; ++i)
  {
    dataMap->insert(i, QCPData(i, i));
  }
  qDebug() << "data" << t.restart();
  customPlot->graph(0)->setData(dataMap, false);
  qDebug() << "set" << t.restart();
  customPlot->xAxis->setRange(0, 10000);
  customPlot->yAxis->setRange(-1, 1);
  t.restart();
  customPlot->replot();
  qDebug() << "replot" << t.restart();
  //customPlot->rescaleAxes();
}

void MainWindow::setupExportTest(QCustomPlot *customPlot)
{
  int n = 10;
  for (int penWidth=0; penWidth<5; ++penWidth)
  {
    QVector<double> x(n), y(n);
    for (int i=0; i<n; ++i)
    {
      x[i] = i;
      y[i] = qSin(i/2.0)+penWidth;
    }
    customPlot->addGraph();
    customPlot->graph()->setData(x, y);
    customPlot->graph()->setPen(QPen(Qt::blue, penWidth));
  }
  
  customPlot->rescaleAxes();
  
  QDir dir("./");
  dir.mkdir("export-test");
  dir.cd("export-test");
  qDebug() << customPlot->savePdf(dir.filePath("exportTest_cosmetic.pdf"), false, 500, 400);
  qDebug() << customPlot->savePdf(dir.filePath("exportTest_noncosmetic.pdf"), true, 500, 400);
  qDebug() << customPlot->savePng(dir.filePath("exportTest_1x.png"), 500, 400);
  qDebug() << customPlot->savePng(dir.filePath("exportTest_2x.png"), 500, 400, 2);
  qDebug() << customPlot->saveJpg(dir.filePath("exportTest_1x.jpg"), 500, 400);
  qDebug() << customPlot->saveJpg(dir.filePath("exportTest_2x.jpg"), 500, 400, 2);
  qDebug() << customPlot->saveBmp(dir.filePath("exportTest_1x.bmp"), 500, 400);
  qDebug() << customPlot->saveBmp(dir.filePath("exportTest_2x.bmp"), 500, 400, 2);
}

void MainWindow::setupLogErrorsTest(QCustomPlot *customPlot)
{
  customPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
  customPlot->yAxis->setSubTickCount(8);
  customPlot->yAxis->setSubGrid(true);
  int n = 11;
  QVector<double> x(n), y(n), yerr(n), xerr(n);
  for (int i=0; i<n; ++i)
  {
    x[i] = i;
    y[i] = i*0.1;
    yerr[i] = 0.5;
    xerr[i] = qAbs(qCos(i/2.0)*0.5);
  }
  customPlot->addGraph();
  customPlot->graph()->setScatterStyle(QCP::ssCross);
  customPlot->graph()->setDataBothError(x, y, xerr, yerr);
  customPlot->graph()->setErrorType(QCPGraph::etBoth);
  customPlot->graph()->setErrorBarSkipSymbol(true);
  
  //customPlot->rescaleAxes();
  customPlot->xAxis->setRange(0, 10);
  customPlot->yAxis->setRange(1, 10);
}

void MainWindow::setupSelectTest(QCustomPlot *customPlot)
{
  customPlot->xAxis->setRange(-10, 10);
  customPlot->yAxis->setRange(-10, 10);
  
  QBrush defaultBrush(QColor(255,255,255,30));
  //defaultBrush = Qt::NoBrush;
  
  /*
  // QCPItemPixmap
  QCPItemPixmap *pixmapItem = new QCPItemPixmap(customPlot);
  customPlot->addItem(pixmapItem);
  pixmapItem->setPixmap(QPixmap("./gnu.png"));
  pixmapItem->setScaled(true, Qt::IgnoreAspectRatio);
  pixmapItem->topLeft->setCoords(-0.2, 1);
  pixmapItem->bottomRight->setCoords(0.3, 0);
  QCPItemPixmap *pixmapItem2 = new QCPItemPixmap(customPlot);
  customPlot->addItem(pixmapItem2);
  pixmapItem2->setPixmap(QPixmap("./gnu.png"));
  pixmapItem2->setScaled(true, Qt::IgnoreAspectRatio);
  pixmapItem2->topLeft->setCoords(1.2, 0);
  pixmapItem2->bottomRight->setCoords(0.7, 1);
  
  // QCPItemRect
  QCPItemRect *rect = new QCPItemRect(customPlot);
  customPlot->addItem(rect);
  rect->setBrush(defaultBrush);
  rect->topLeft->setCoords(0, 1);
  rect->bottomRight->setCoords(1, 0);
  
  // QCPItemEllipse
  QCPItemEllipse *ellipse = new QCPItemEllipse(customPlot);
  customPlot->addItem(ellipse);
  ellipse->setBrush(defaultBrush);
  ellipse->topLeft->setCoords(-0.15, 1.1);
  ellipse->bottomRight->setCoords(1.15, 0);
  

  // QCPItemLine
  QCPItemLine *line = new QCPItemLine(customPlot);
  customPlot->addItem(line);
  line->start->setCoords(-0.1, 0.8);
  line->end->setCoords(1.1, 0.2);
  line->setHead(QCPLineEnding::esSpikeArrow);
  
  // QCPItemStraightLine
  QCPItemStraightLine *straightLine = new QCPItemStraightLine(customPlot);
  customPlot->addItem(straightLine);
  straightLine->point1->setCoords(0, 0.4);
  straightLine->point2->setCoords(1, 0.6);
  */
  // QCPItemCurve
  QCPItemCurve *curve = new QCPItemCurve(customPlot);
  customPlot->addItem(curve);
  curve->start->setCoords(0, 1);
  curve->startDir->setCoords(0.5, 1);
  curve->endDir->setCoords(0.7, 0.2);
  curve->end->setCoords(1, 0);
  curve->setHead(QCPLineEnding::esSpikeArrow);
  curve->setTail(QCPLineEnding::esLineArrow);
  /*
  // QCPItemBracket
  QCPItemBracket *bracket = new QCPItemBracket(customPlot);
  customPlot->addItem(bracket);
  bracket->left->setCoords(-0.2, 0.35);
  bracket->right->setCoords(1.2, 0.65);
  bracket->setLength(22);
  */
  connect(customPlot, SIGNAL(beforeReplot()), this, SLOT(selectTestColorMapRefresh()));
}

void MainWindow::setupDateTest(QCustomPlot *customPlot)
{
  customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
  QCPGraph *g = customPlot->addGraph();
  g->addData(QDateTime(QDate(350,5,21), QTime(0, 0)).toMSecsSinceEpoch()/1000.0, 1);
  g->addData(QDateTime(QDate(650,5,21), QTime(0, 0)).toMSecsSinceEpoch()/1000.0, 2);
  g->addData(QDateTime(QDate(740,5,21), QTime(0, 0)).toMSecsSinceEpoch()/1000.0, 4);
  g->addData(QDateTime(QDate(1000,5,21), QTime(0, 0)).toMSecsSinceEpoch()/1000.0, 8);
  g->rescaleAxes();
}

void MainWindow::setupTickLabelTest(QCustomPlot *customPlot)
{
  customPlot->axisRect()->setupFullAxesBox();
  customPlot->xAxis2->setTickLabels(true);
  customPlot->yAxis2->setTickLabels(true);
  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
  customPlot->setPlottingHint(QCP::phCacheLabels, false);
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(tickLabelTestTimerSlot()));
  timer->start(1000);
  connect(customPlot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMoveRotateTickLabels(QMouseEvent*)));
}

void MainWindow::setupDaqPerformance(QCustomPlot *customPlot)
{
  customPlot->addGraph();
  customPlot->yAxis->setRange(-1, 1);
  mReplotTimer.setInterval(25);
  mDataTimer.setInterval(0);
  connect(&mReplotTimer, SIGNAL(timeout()), this, SLOT(daqPerformanceReplotSlot()));
  connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(daqPerformanceDataSlot()));
  mReplotTimer.start();
  mDataTimer.start();
}

void MainWindow::setupLayoutTest(QCustomPlot *customPlot)
{
  
  QCPLayoutGrid *mainLayout = qobject_cast<QCPLayoutGrid*>(customPlot->plotLayout());
  delete mainLayout->takeAt(0); // remove initial axis rect
  // create 3x3 grid:
  mainLayout->addElement(0, 0, new QCPAxisRect(customPlot));
  mainLayout->addElement(0, 1, new QCPAxisRect(customPlot));
  mainLayout->addElement(0, 2, new QCPAxisRect(customPlot));
  mainLayout->addElement(1, 0, new QCPAxisRect(customPlot));
  mainLayout->addElement(1, 1, new QCPAxisRect(customPlot));
  mainLayout->addElement(1, 2, new QCPAxisRect(customPlot));
  mainLayout->addElement(2, 0, new QCPAxisRect(customPlot));
  mainLayout->addElement(2, 1, new QCPAxisRect(customPlot));
  mainLayout->addElement(2, 2, new QCPAxisRect(customPlot));
  QList<QCPAxisRect*> rlist;
  for (int i=0; i<mainLayout->elementCount(); ++i)
  {
    rlist << qobject_cast<QCPAxisRect*>(mainLayout->elementAt(i));
    rlist.last()->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
  }
  
  mainLayout->setColumnStretchFactors(QList<double>() << 1 << 2 << 1);
  mainLayout->setRowStretchFactors(QList<double>() << 1 << 2 << 3);
  
  mainLayout->element(0, 0)->setMinimumSize(200, 100);
  mainLayout->element(0, 1)->setMaximumSize(150, 100);
  mainLayout->element(2, 2)->setMinimumSize(100, 100);
  
  
  /*
  customPlot->setFont(QFont(customPlot->font().family(), 7));
  customPlot->axisRect(0)->axis(QCPAxis::atRight)->setTickLabels(true);
  customPlot->axisRect(0)->axis(QCPAxis::atTop)->setTickLabels(true);
  customPlot->axisRect(0)->axis(QCPAxis::atLeft)->setTickLabelFont(customPlot->font());
  customPlot->axisRect(0)->axis(QCPAxis::atRight)->setTickLabelFont(customPlot->font());
  customPlot->axisRect(0)->axis(QCPAxis::atTop)->setTickLabelFont(customPlot->font());
  customPlot->axisRect(0)->axis(QCPAxis::atBottom)->setTickLabelFont(customPlot->font());
  
  QCPLayoutGrid *layout = qobject_cast<QCPLayoutGrid*>(customPlot->plotLayout());
  layout->setRowSpacing(8);
  layout->setColumnSpacing(8);
  layout->addElement(new QCPAxisRect(customPlot), 0, 1);
  layout->addElement(new QCPAxisRect(customPlot), 1, 0);
  
  QCPLayoutGrid *subLayout = new QCPLayoutGrid(customPlot);
  subLayout->addElement(new QCPAxisRect(customPlot), 0, 0);
  subLayout->addElement(new QCPAxisRect(customPlot), 0, 1);
  subLayout->setColumnStretchFactor(0, 0.7);
  layout->addElement(subLayout, 1, 1);
  
  QList<QCPAxisRect*> rects = customPlot->axisRects();
  for (int i=0; i<rects.size(); ++i)
  {
    rects.at(i)->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
    rects.at(i)->axis(QCPAxis::atLeft)->setGrid(true);
    rects.at(i)->axis(QCPAxis::atBottom)->setGrid(true);
  }
  
  QCPCurve *c = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
  customPlot->addPlottable(c);
  
  QCPCurveDataMap *d1 = new QCPCurveDataMap;
  d1->insert(0, QCPCurveData(0, 2, 1));
  d1->insert(1, QCPCurveData(1, 3, 2));
  d1->insert(2, QCPCurveData(2, 6, 4));
  
  c->clearData();
  c->setData(d1, false);
  
  QCPCurveDataMap *d2 = new QCPCurveDataMap;
  d2->insert(0, QCPCurveData(0, 26, 14));
  d2->insert(2, QCPCurveData(2, 31, 22));
  d2->insert(4, QCPCurveData(4, 61, 42));
  
  c->clearData();
  c->setData(d2, false);
  
  customPlot->replot();
  */
  
  QCPLayoutGrid *topLayout = dynamic_cast<QCPLayoutGrid*>(customPlot->plotLayout());
  
  QList<QCPAxisRect*> rects;
  for (int i=0; i<5; ++i)
    rects << new QCPAxisRect(customPlot);
  
  for (int i=0; i<rects.size(); ++i)
  {
    topLayout->addElement(0, i+1, rects.at(i));
    rects.at(i)->addAxis(QCPAxis::atLeft);
    rects.at(i)->addAxis(QCPAxis::atRight);
    rects.at(i)->addAxis(QCPAxis::atBottom);
    rects.at(i)->addAxis(QCPAxis::atTop);
    for (int k=0; k<rects.at(i)->axes().size(); ++k)
    {
      QCPAxis *ax = rects.at(i)->axes().at(k);
      ax->setTicks(false);
      ax->setTickLabels(false);
      ax->setGrid(false);
    }
    rects.at(i)->setAutoMargins(QCP::msNone);
    rects.at(i)->setMargins(QMargins(1, 1, 1, 1));
  }
  
  topLayout->setColumnStretchFactors(QList<double>() << 1 << 1e9 << 1e7 << 1e9 << 1e3 << 1e1);
  rects.at(0)->setMaximumSize(300, QWIDGETSIZE_MAX);
  rects.at(1)->setMaximumSize(250, QWIDGETSIZE_MAX);
  rects.at(2)->setMinimumSize(200, 0);
  rects.at(3)->setMaximumSize(150, QWIDGETSIZE_MAX);
  rects.at(4)->setMaximumSize(100, QWIDGETSIZE_MAX);
  
  QCPLayoutGrid *subLayout = new QCPLayoutGrid;
  topLayout->addElement(1, 3, subLayout);
  QCPAxisRect *r0 = new QCPAxisRect(customPlot);
  subLayout->addElement(0, 0, r0);
  r0->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
  QCPAxisRect *r1 = new QCPAxisRect(customPlot);
  subLayout->addElement(0, 1, r1);
  r1->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
  r1->setMaximumSize(200, QWIDGETSIZE_MAX);
}

void MainWindow::setupMultiAxisTest(QCustomPlot *customPlot)
{
  presetInteractive(customPlot);
  customPlot->axisRect()->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
  customPlot->axisRect()->axis(QCPAxis::atRight, 0)->setTickLabels(true);
  customPlot->axisRect()->axis(QCPAxis::atTop, 0)->setTickLabels(true);
}

void MainWindow::setupLayoutElementBugTest(QCustomPlot *customPlot)
{
  QCPLayoutGrid *topLayout = qobject_cast<QCPLayoutGrid*>(customPlot->plotLayout());
  
  QCPAxisRect *r = new QCPAxisRect(customPlot);
  r->addAxes(QCPAxis::atLeft);
  topLayout->addElement(0, 0, r);
}

void MainWindow::setupMarginGroupTest(QCustomPlot *customPlot)
{
  QCPLayoutGrid *topLayout = qobject_cast<QCPLayoutGrid*>(customPlot->plotLayout());
  
  QCPAxisRect *r = new QCPAxisRect(customPlot);
  topLayout->addElement(1, 0, r);
  r->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atBottom|QCPAxis::atTop);
  r->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atBottom|QCPAxis::atTop);
  
  QCPMarginGroup *group = new QCPMarginGroup(customPlot);
  topLayout->element(0, 0)->setMarginGroup(QCP::msAll, group);
  topLayout->element(1, 0)->setMarginGroup(QCP::msAll, group);
}

void MainWindow::setupInsetLayoutTest(QCustomPlot *customPlot)
{
  QCPAxisRect *insetAxRect = new QCPAxisRect(customPlot);
  insetAxRect->setMinimumSize(300, 250);
  customPlot->axisRect(0)->insetLayout()->addElement(insetAxRect, Qt::AlignRight|Qt::AlignTop);
  insetAxRect->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atBottom|QCPAxis::atTop);
  insetAxRect->axis(QCPAxis::atLeft, 0)->setVisible(true);
  insetAxRect->axis(QCPAxis::atLeft, 0)->setTickLabels(true);
  insetAxRect->axis(QCPAxis::atLeft, 0)->setRange(0, 20);
  insetAxRect->setBackground(QBrush(QColor(240, 240, 240)));
  
}

void MainWindow::setupLegendTest(QCustomPlot *customPlot)
{
  customPlot->legend->setVisible(true);
  //customPlot->legend->setMinimumSize(300, 150);
  //customPlot->axisRect()->setMinimumMargins(QMargins(15, 0, 15, 15));
  
  customPlot->addGraph()->setName("first graph");
  customPlot->addGraph()->setName("second longer graph");
  customPlot->addGraph()->setName("some stupid text\nthat has a line break\nand some more text");
  customPlot->addGraph()->setName("yadayada");
  //customPlot->legend->addElement(0, 1, customPlot->legend->element(3, 0));
  //customPlot->legend->addElement(1, 1, customPlot->legend->element(2, 0));
  customPlot->addGraph()->setName("yadayaasdda");
  customPlot->graph(3)->removeFromLegend();
  customPlot->graph(3)->addToLegend();
  
  QCPLayoutGrid *grid = customPlot->plotLayout();
  grid->addElement(1, 0, grid->element(0, 0));
  
  QCPPlotTitle *title = new QCPPlotTitle(customPlot);
  title->setText("This is a Plot Title");
  title->setSelectable(true);
  grid->addElement(0, 0, title);
  
  customPlot->graph(0)->addData(QVector<double>() << 1 << 2, QVector<double>() << 1 << 1.2);
}

void MainWindow::setupMultiAxisRectInteractions(QCustomPlot *customPlot)
{
  QCPAxisRect *r1 = new QCPAxisRect(customPlot);
  r1->addAxes(QCPAxis::atLeft|QCPAxis::atBottom);
  customPlot->plotLayout()->addElement(1, 0, r1);
  QCPAxisRect *r2 = new QCPAxisRect(customPlot);
  r2->addAxes(QCPAxis::atLeft|QCPAxis::atBottom);
  customPlot->plotLayout()->addElement(0, 1, r2);
  QCPAxisRect *r3 = new QCPAxisRect(customPlot);
  r3->addAxes(QCPAxis::atLeft|QCPAxis::atBottom);
  customPlot->plotLayout()->addElement(1, 1, r3);
  
  QCPAxisRect *inset = new QCPAxisRect(customPlot);
  inset->addAxes(QCPAxis::atLeft|QCPAxis::atBottom|QCPAxis::atRight|QCPAxis::atTop);
  inset->setMinimumSize(170, 120);
  r3->insetLayout()->addElement(inset, Qt::AlignRight|Qt::AlignTop);
  
  connect(mCustomPlot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(setupMultiAxisRectInteractionsMouseMove(QMouseEvent*)));
}


void MainWindow::presetInteractive(QCustomPlot *customPlot)
{
  customPlot->setInteractions(QCP::iRangeDrag|
                              QCP::iRangeZoom|
                              QCP::iSelectAxes|
                              QCP::iSelectItems|
                              QCP::iSelectLegend|
                              QCP::iSelectPlottables|
                              QCP::iSelectOther|
                              QCP::iMultiSelect);
  customPlot->setRangeDrag(Qt::Horizontal|Qt::Vertical);
  customPlot->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}

void MainWindow::labelItemAnchors(QCPAbstractItem *item, double fontSize, bool circle, bool labelBelow)
{
  QList<QCPItemAnchor*> anchors = item->anchors();
  for (int i=0; i<anchors.size(); ++i)
  {
    if (circle)
    {
      QCPItemEllipse *circ = new QCPItemEllipse(item->parentPlot());
      item->parentPlot()->addItem(circ);
      circ->topLeft->setParentAnchor(anchors.at(i));
      circ->bottomRight->setParentAnchor(anchors.at(i));
      circ->topLeft->setCoords(-4, -4);
      circ->bottomRight->setCoords(4, 4);
      QPen p(Qt::blue, 0, Qt::CustomDashLine);
#if (QT_VERSION >= QT_VERSION_CHECK(4, 8, 0)) // Qt 4.8 changed the meaning of this completely...
      p.setDashPattern(QVector<qreal>()<<2<<1);
#else
      p.setDashPattern(QVector<qreal>()<<1<<3);
#endif
      circ->setPen(p);
      if (dynamic_cast<QCPItemPosition*>(anchors.at(i)))
      {
        QCPItemEllipse *circ2 = new QCPItemEllipse(item->parentPlot());
        item->parentPlot()->addItem(circ2);
        circ2->topLeft->setParentAnchor(anchors.at(i));
        circ2->bottomRight->setParentAnchor(anchors.at(i));
        circ2->topLeft->setCoords(-2.5, -2.5);
        circ2->bottomRight->setCoords(2.5, 2.5);
        circ2->setPen(Qt::NoPen);
        circ2->setBrush(Qt::blue);
      }
    }
    if (fontSize > 0)
    {
      QCPItemText *label = new QCPItemText(item->parentPlot());
      item->parentPlot()->addItem(label);
      label->setFont(QFont(font().family(), fontSize));
      label->setColor(Qt::blue);
      label->setText(QString("%2 (%1)").arg(i).arg(anchors.at(i)->name()));
      label->position->setParentAnchor(anchors.at(i));
      if (circle)
        label->position->setCoords(0, fontSize*2*(labelBelow?1:-1));
      else
        label->position->setCoords(0, 0);
      label->setTextAlignment(Qt::AlignCenter);
    }
  }
}

void MainWindow::showSelectTestColorMap(QCustomPlot *customPlot)
{
  QImage colorMap(customPlot->axisRects().first()->size(), QImage::Format_RGB32);
  colorMap.fill(QColor(Qt::blue).rgb());
  int offsetx = customPlot->axisRects().first()->left();
  int offsety = customPlot->axisRects().first()->top();
  // for items:
  for (int i=0; i<customPlot->itemCount(); ++i)
  {
    QCPAbstractItem *item = customPlot->item(i);
    for (int y=0; y<colorMap.height(); ++y)
    {
      QRgb *p = reinterpret_cast<QRgb*>(colorMap.scanLine(y));
      for (int x=0; x<colorMap.width(); ++x)
      {
        double dist = item->selectTest(QPointF(x+offsetx, y+offsety), false);
        if (dist >= 0)
        {
          int r = qRed(p[x]);
          int g = qGreen(p[x]);
          int b = qBlue(p[x]);
          r += 255.0/(dist*0.25+1.0);
          b += -255.0/(dist*0.25+1.0);
          if (qAbs(dist-customPlot->selectionTolerance()) < 0.5)
            g += 255;
          p[x] = qRgb(qBound(0, r, 255), qBound(0, g, 255), qBound(0, b, 255));
        }
      }
    }
  }
  // for plottables:
  for (int i=0; i<customPlot->plottableCount(); ++i)
  {
    QCPAbstractPlottable *plottable = customPlot->plottable(i);
    for (int y=0; y<colorMap.height(); ++y)
    {
      QRgb *p = reinterpret_cast<QRgb*>(colorMap.scanLine(y));
      for (int x=0; x<colorMap.width(); ++x)
      {
        double dist = plottable->selectTest(QPointF(x+offsetx, y+offsety), false);
        if (dist >= 0)
        {
          int r = qRed(p[x]);
          int g = qGreen(p[x]);
          int b = qBlue(p[x]);
          r += 255.0/(dist*0.25+1.0);
          b += -255.0/(dist*0.25+1.0);
          if (qAbs(dist-customPlot->selectionTolerance()) < 0.5)
            g += 255;
          p[x] = qRgb(qBound(0, r, 255), qBound(0, g, 255), qBound(0, b, 255));
        }
      }
    }
  }
  // set as plot background:
  customPlot->axisRects().first()->setBackground(QPixmap::fromImage(colorMap), false);
}

void MainWindow::setupTestbed(QCustomPlot *customPlot)
{
  Q_UNUSED(customPlot)
}

void MainWindow::setupIntegerTickStepCase(QCustomPlot *customPlot)
{
  customPlot->xAxis->setAutoTickStep(false);
  customPlot->yAxis->setAutoTickStep(false);
  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(integerTickStepCase_xRangeChanged(QCPRange)));
  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(integerTickStepCase_yRangeChanged(QCPRange)));
}

void MainWindow::tracerTestMouseMove(QMouseEvent *event)
{
  tracerTestTracer->setGraphKey(mCustomPlot->xAxis->pixelToCoord(event->pos().x()));
  mCustomPlot->replot();
}

void MainWindow::selectTestColorMapRefresh()
{
  showSelectTestColorMap(mCustomPlot);
}

void MainWindow::mouseMoveRotateTickLabels(QMouseEvent *event)
{
  mCustomPlot->xAxis->setTickLabelRotation(event->pos().y()-mCustomPlot->height()/2.0);
  mCustomPlot->yAxis->setTickLabelRotation(event->pos().y()-mCustomPlot->height()/2.0);
  mCustomPlot->yAxis2->setTickLabelRotation(event->pos().x()-mCustomPlot->width()/2.0);
  mCustomPlot->xAxis2->setTickLabelRotation(event->pos().x()-mCustomPlot->width()/2.0);
  mCustomPlot->replot();
}

void MainWindow::tickLabelTestTimerSlot()
{
  mCustomPlot->setPlottingHint(QCP::phCacheLabels, !mCustomPlot->plottingHints().testFlag(QCP::phCacheLabels));
  ui->statusBar->showMessage(mCustomPlot->plottingHints().testFlag(QCP::phCacheLabels) ? "Cached" : "Not Cached");
  mCustomPlot->replot();
}

void MainWindow::setupMultiAxisRectInteractionsMouseMove(QMouseEvent *event)
{
  QCPAxisRect *ar = mCustomPlot->axisRectAt(event->posF());
  if (ar)
    ar->setBackground(QColor(230, 230, 230));
  for (int i=0; i<mCustomPlot->axisRectCount(); ++i)
  {
    if (mCustomPlot->axisRect(i) != ar)
      mCustomPlot->axisRect(i)->setBackground(Qt::NoBrush);
  }
  mCustomPlot->replot();
}

void MainWindow::daqPerformanceDataSlot()
{
  qint64 currentMillisecond = QDateTime::currentMSecsSinceEpoch();
  static qint64 lastMillisecond = currentMillisecond;
  static int ptsInThisMillisecond = 0;
  if (ptsInThisMillisecond < 10)
  {
    ptsInThisMillisecond++;
    double x = currentMillisecond/1000.0;
    double y = qSin(x*10)*qCos(x/2.0);
    mCustomPlot->graph(0)->addData(x+qSin(ptsInThisMillisecond*100)*0.001,y+qSin(ptsInThisMillisecond*10)*0.001);
  }
  if (lastMillisecond != currentMillisecond)
  {
    ptsInThisMillisecond = 0;
    lastMillisecond = currentMillisecond;
  }
}

void MainWindow::daqPerformanceReplotSlot()
{
  double lastX = 0;
  if (mCustomPlot->graph(0)->data()->end() != mCustomPlot->graph(0)->data()->begin())
    lastX = (mCustomPlot->graph(0)->data()->end()-1).key();
  mCustomPlot->xAxis->setRange(lastX, 10, Qt::AlignRight);
  mCustomPlot->replot();
  
  int dataPoints = mCustomPlot->graph(0)->data()->size();
  static int lastDataPoints = dataPoints;
  qint64 now = QDateTime::currentMSecsSinceEpoch();
  static qint64 lastT = now;
  static QString dataPointFrequency("0 Hz");
  if (now-lastT > 1000)
  {
    dataPointFrequency = QString::number((dataPoints-lastDataPoints)/(double)(now-lastT)*1000.0)+" Hz";
    lastT = now;
    lastDataPoints = dataPoints;
  }
  ui->statusBar->showMessage(QString("Data Points: %1, Data Frequency: %2").arg(dataPoints).arg(dataPointFrequency));
}

void MainWindow::integerTickStepCase_xRangeChanged(QCPRange newRange)
{
  // Generate tick positions according to linear scaling:
  double mTickStep = newRange.size()/(double)(5+1e-10); // mAutoTickCount ticks on average, the small addition is to prevent jitter on exact integers
  double magnitudeFactor = qPow(10.0, qFloor(qLn(mTickStep)/qLn(10.0))); // get magnitude factor e.g. 0.01, 1, 10, 1000 etc.
  double tickStepMantissa = mTickStep/magnitudeFactor;
  if (tickStepMantissa < 5)
  {
    // round digit after decimal point to 0.5
    mTickStep = (int)(tickStepMantissa*2)/2.0*magnitudeFactor;
  } else
  {
    // round to first digit in multiples of 2
    mTickStep = (int)((tickStepMantissa/10.0)*5)/5.0*10*magnitudeFactor;
  }
  mCustomPlot->xAxis->setTickStep(qCeil(mTickStep));
}

void MainWindow::integerTickStepCase_yRangeChanged(QCPRange newRange)
{
  // Generate tick positions according to linear scaling:
  double mTickStep = newRange.size()/(double)(5+1e-10); // mAutoTickCount ticks on average, the small addition is to prevent jitter on exact integers
  double magnitudeFactor = qPow(10.0, qFloor(qLn(mTickStep)/qLn(10.0))); // get magnitude factor e.g. 0.01, 1, 10, 1000 etc.
  double tickStepMantissa = mTickStep/magnitudeFactor;
  if (tickStepMantissa < 5)
  {
    // round digit after decimal point to 0.5
    mTickStep = (int)(tickStepMantissa*2)/2.0*magnitudeFactor;
  } else
  {
    // round to first digit in multiples of 2
    mTickStep = (int)((tickStepMantissa/10.0)*5)/5.0*10*magnitudeFactor;
  }
  mCustomPlot->yAxis->setTickStep(qCeil(mTickStep));
}
