#ifndef FRACTALCONTROLLERFABRIC_H
#define FRACTALCONTROLLERFABRIC_H

#include <QWidget>
#include <QVBoxLayout>
#include <QList>
#include <QSlider>
#include "fractalmodel.h"

class FractalControllerFabric : public QWidget
{
  Q_OBJECT
public:
  explicit FractalControllerFabric(QWidget *parent = nullptr)
    : QWidget(parent){
  }
  void setModel(FractalModel* model){
    m_model = model;
    emit modelSet();
  }

  const FractalModel* model(){
    return m_model;
  }

  virtual void setupUi(){
    auto* layout = new QHBoxLayout();
    this->setLayout(layout);
  }

  template<typename T>
  void create_controller(Property* prop){
    T* widget = new T();
    this->layout()->addWidget(widget);
  }

signals:
  void modelSet();
  void modelContentChanged(int index);
private:
  FractalModel* m_model = nullptr;
  QList<QWidget*> m_widgets;

};

#endif // FRACTALCONTROLLERFABRIC_H
