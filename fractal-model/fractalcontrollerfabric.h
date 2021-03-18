#ifndef FRACTALCONTROLLERFABRIC_H
#define FRACTALCONTROLLERFABRIC_H

#include <QObject>
#include <QList>
#include "fractalmodel.h"

class FractalControllerFabric : public QObject
{
  Q_OBJECT
public:
  explicit FractalControllerFabric(QObject *parent = nullptr);

signals:

private:
  FractalModel* m_model;
  QList<QWidget*> m_widgets;
};

#endif // FRACTALCONTROLLERFABRIC_H
