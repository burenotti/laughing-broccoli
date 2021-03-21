#ifndef FRACTALMODEL_H
#define FRACTALMODEL_H

#include <QList>
#include <QAbstractListModel>
#include <QObject>
#include <QVariant>
#include "./properties/property.h"

class FractalModel : public QObject
{
  Q_OBJECT
public:
  FractalModel(QObject* parent = nullptr)
    : QObject(parent) {}

  FractalModel(const FractalModel& source);

  ~FractalModel();
  virtual const QString& name();
  virtual const QString& description();
  virtual Property* at(int index);
  virtual bool hasIndex(int index);
  virtual int size();
  virtual void remove(int index);
  virtual void clear();
public slots:
  virtual void setName(const QString& value);
  virtual void setDescription(const QString& value);
  virtual void append(Property* prop);
  virtual void insertAt(int index, Property* prop);
signals:
  void beforeDataChanged(int index);
  void dataChanged(int index);
  void itemAdded(int index, Property* prop);
  void beforeContentCleared();
  void contentCleared();
  void beforeItemRemoved(int index);
  void afterItemRemoved(Property* prop);
private:
  QString m_name;
  QString m_description;
  QList<Property*> m_propertyList;
};

#endif
