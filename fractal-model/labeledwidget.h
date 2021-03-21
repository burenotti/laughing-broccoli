#ifndef LABLEDWIDGET_H
#define LABLEDWIDGET_H
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVariant>
#include "abstractpropertycontroller.h"

class LabeledWidget : public AbstractPropertyController
{
  Q_OBJECT
public:
  explicit LabeledWidget(QWidget *parent = nullptr);
  LabeledWidget(QString name, QWidget* parent = nullptr);
  ~LabeledWidget();

  virtual void setupUi();

  virtual QString name();

public slots:
  virtual void setName(QString name);
  virtual void setValue(QVariant) = 0;
signals:

  void nameChanged(QString name);

protected:

  virtual QWidget* widget() = 0;

protected:
  QString m_name;
  QLabel* m_label;
private:
  QVBoxLayout* m_layout;
};

#endif // LABLEDWIDGET_H
