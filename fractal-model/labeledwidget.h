#ifndef LABLEDWIDGET_H
#define LABLEDWIDGET_H
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QString>

class LabeledWidget : public QWidget
{
  Q_OBJECT
public:
  explicit LabeledWidget(QWidget *parent = nullptr);
  LabeledWidget(QString name, QWidget* parent = nullptr);
  ~LabeledWidget();

  virtual void setupUi();

  virtual QString name();
  virtual QWidget* widget() = 0;


public slots:
  virtual void setName(QString name);
  virtual void setValue(QVariant) = 0;
signals:
  void nameChanged(QString name);
  void valueChanged(QVariant value);
protected:
  QString m_name;
  QLabel* m_label;
  QWidget* m_root;
};

#endif // LABLEDWIDGET_H
