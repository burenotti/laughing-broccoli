#include <QList>
#include <QAbstractListModel>
#include <QObject>
#include "./properties/property.h"

class FractalModel : public QObject
{
  Q_OBJECT
public:
  FractalModel(QObject* parent = nullptr) : QObject(parent)
  {
  }
  virtual Property* itemAt(int index);
  virtual bool hasIndex(int index);
  virtual void insertAt(int index, Property* prop);
  virtual void append(Property* prop);
  virtual int size();
  virtual void remove(int index);
  virtual void clear();


public slots:
private:
  QList<Property*> m_propertyList;
};
