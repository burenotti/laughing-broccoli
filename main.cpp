#include <QApplication>
#include "mainwindow.h"
#include <QMainWindow>
#include <QPushButton>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  auto* window = new MainWindow;
  window->show();
  return a.exec();
}
