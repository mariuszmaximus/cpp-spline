#include <QApplication>
#include <QChartView>
#include <QLineSeries>
#include <QSplineSeries>

#include <QDebug>
#include <iostream>

#include <Bezier.h>
#include <BSpline.h>
#include <CatmullRom.h>


#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
QT_CHARTS_USE_NAMESPACE
#endif

std::vector<QPointF> points = {
        QPointF(1,1),
        QPointF(2,3),
        QPointF(3,2),
        QPointF(4,6)};



QLineSeries* demo_bezier() {
	Curve* curve = new Bezier();
	curve->set_steps(100); // generate 100 interpolate points between the last 4 way points

    for (auto &p: points)
        curve->add_way_point(Vector(p.x(), p.y(), 0));

	std::cout << "nodes: " << curve->node_count() << std::endl;
	std::cout << "total length: " << curve->total_length() << std::endl;

    QLineSeries *seriesLine = new QLineSeries();
	for (int i = 0; i < curve->node_count(); ++i) {
		std::cout << "node #" << i << ": " << curve->node(i).toString() << " (length so far: " << curve->length_from_starting_point(i) << ")" << std::endl;
        *seriesLine << QPointF(curve->node(i).x, curve->node(i).y);
    }
	delete curve;
    return seriesLine;
}

QLineSeries*  demo_bspline() {
	Curve* curve = new BSpline();
	curve->set_steps(100); // generate 100 interpolate points between the last 4 way points

    for (auto &p: points)
        curve->add_way_point(Vector(p.x(), p.y(), 0));

	std::cout << "nodes: " << curve->node_count() << std::endl;
	std::cout << "total length: " << curve->total_length() << std::endl;

    QLineSeries *seriesLine = new QLineSeries();
	for (int i = 0; i < curve->node_count(); ++i) {
		std::cout << "node #" << i << ": " << curve->node(i).toString() << " (length so far: " << curve->length_from_starting_point(i) << ")" << std::endl;
        *seriesLine << QPointF(curve->node(i).x, curve->node(i).y);
	}
	delete curve;
    return seriesLine;    
}

QLineSeries*  demo_catmullrom() {
	Curve* curve = new CatmullRom();
	curve->set_steps(100); // generate 100 interpolate points between the last 4 way points

    for (auto &p: points)
        curve->add_way_point(Vector(p.x(), p.y(), 0));

	std::cout << "nodes: " << curve->node_count() << std::endl;
	std::cout << "total length: " << curve->total_length() << std::endl;

    QLineSeries *seriesLine = new QLineSeries();
	for (int i = 0; i < curve->node_count(); ++i) {
		std::cout << "node #" << i << ": " << curve->node(i).toString() << " (length so far: " << curve->length_from_starting_point(i) << ")" << std::endl;
        *seriesLine << QPointF(curve->node(i).x, curve->node(i).y);
	}
	delete curve;
    return seriesLine;    
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QChart *chart = new QChart();
    chart->legend()->hide();

    chart->setTitle("Simple line chart example");


    // 
    QLineSeries *seriesLine = new QLineSeries();
    for (auto &p: points)
        *seriesLine<< p;
    seriesLine->setPointsVisible();
    chart->addSeries(seriesLine);
    //
    QSplineSeries *seriesSpline = new QSplineSeries();
    for (auto &p: points)
        *seriesSpline<< p;
    seriesSpline->setPointsVisible();
    chart->addSeries(seriesSpline);
    //
    chart->addSeries(demo_bezier());
    //
    chart->addSeries(demo_bspline());
    // //
    chart->addSeries(demo_catmullrom());



    chart->createDefaultAxes();

    QChartView chartView(chart);
    chartView.setRenderHint(QPainter::Antialiasing);
    chartView.resize(640, 480);
    chartView.show();

    return a.exec();
}
