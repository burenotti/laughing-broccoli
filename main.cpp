#include <QApplication>
#include "fractal-model/labeledslider.h"
#include <QMainWindow>
#include <QPushButton>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  (new LabeledSlider("Name"))->show();
  return a.exec();
}
