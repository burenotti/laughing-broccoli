#ifndef LABELEDSLIDER_H
#define LABELEDSLIDER_H

#include "labeledwidget.h"
#include <QVariant>
#include <QSlider>
#include <QSpacerItem>

class LabeledSlider : public LabeledWidget
{
  Q_OBJECT
public:
  LabeledSlider(QString name, QWidget* parent = nullptr);
  explicit LabeledSlider(QWidget* parent);

  int minimum();
  int maximum();
  QVariant value() override;

signals:
  void minimumChanged(int minimum);
  void maximumChanged(int maximum);
public slots:
  virtual void setValue(QVariant value) override;
  void setMaximum(int value);
  void setMinimum(int value);
protected:
  QSlider* widget() override;
protected:
  QSlider* m_slider = nullptr;
};

#endif // LABELEDSLIDER_H
