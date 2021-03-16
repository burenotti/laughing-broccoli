#ifndef PROPERTY_H
#define PROPERTY_H

#include <QObject>
#include <QVariant>


class Property : public QObject
{
  Q_OBJECT
public:
  explicit Property(QObject *parent = nullptr);
  Property(QString name, QObject* parent = nullptr);
  Property(QString name, QVariant value, QObject* parent = nullptr);

  Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
  Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

  virtual QString name();
  virtual QVariant value();

public slots:
  virtual void setValue(QVariant value);
  virtual void setName(QString name);
signals:
  void valueChanged(QVariant);
  void nameChanged(QString);
private:
  QVariant m_value;
  QString m_name;
};

#endif // PROPERTY_H
