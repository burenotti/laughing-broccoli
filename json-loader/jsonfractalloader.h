#ifndef JSONFRACTALLOADER_H
#define JSONFRACTALLOADER_H

#include "fractal-model/fractalmodel.h"
#include <QList>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QHash>

class JSONFractalLoader
{
public:

  enum class Error {
    FileReadError,
    JsonParseError,
  };

  using creator_t = Property*(*)(const QJsonObject& json);

  JSONFractalLoader();

  bool hasCreatorForType(const QString& type){
    return m_creatorMap.contains(type);
  }
  void addCreatorForType(QString& type, creator_t function);
  bool fromFile(FractalModel* model, const QString& path);
  QJsonObject getJsonContent(const QByteArray& data, bool& ok);
  QByteArray readFile(const QString& path, bool& ok);
  Property* createPropertyFromJson(const QJsonObject& json);
  creator_t creator(const QString& type);
private:
  QHash<QString, creator_t> m_creatorMap;
};

#endif // JSONFRACTALLOADER_H
