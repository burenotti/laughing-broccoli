#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "json-loader/jsonfractalloader.h"
#include "properties/rangebasedproperty.h"
#include "controllers/labeledslider.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  auto* model = new FractalModel;
  JSONFractalLoader loader;
  loader.addCreatorForType("slider", [](const QJsonObject& object) -> Property*
  {
    int min = object["minimum"].toInt();
    int max = object["maximum"].toInt();
    QVariant defaultValue = object["default"].toVariant();
    QString name = object["name"].toString("");
    return new RangeBasedProperty(min, max, defaultValue, name);
  });
  loader.fromFile(model, "/home/burenotti/Desktop/fractal.json");
  auto* container = new PropertyControllerContainer;
  container->setCreatorOfType("slider", [](Property* prop, QWidget* parent) -> AbstractPropertyController*
  {
    auto* slider = new LabeledSlider(parent);
    slider->setProperty(prop);
    return slider;
  });
  container->setModel(model);
  ui->scrollArea->setWidget(container);
}

MainWindow::~MainWindow()
{
  delete ui;
}
