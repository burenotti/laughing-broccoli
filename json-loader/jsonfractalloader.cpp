#include "jsonfractalloader.h"

JSONFractalLoader::JSONFractalLoader()
{
}

void JSONFractalLoader::addCreatorForType(QString& type, JSONFractalLoader::creator_t function)
{
  m_creatorMap[type] = function;
}

bool JSONFractalLoader::fromFile(FractalModel* model, const QString& path)
{
  model->clear();
  model->setName("");
  model->setDescription("");
  bool ok = true;
  QByteArray data = readFile(path, ok);
  QJsonObject json = getJsonContent(data, ok);

  if (json.contains("name") && json["name"].isString())
    model->setName(json["name"].toString());
  if (json.contains("description") && json["description"].isString())
    model->setDescription(json["description"].toString());

  if (json.contains("properties")){
    const auto& array = json["properties"].toArray();
    for (const auto& prop_data: array){
      Property* prop = createPropertyFromJson(prop_data.toObject());
      model->append(prop);
    }
  }
  return ok;
}

QJsonObject JSONFractalLoader::getJsonContent(const QByteArray& data, bool& ok)
{
  ok = true;
  auto document = QJsonDocument::fromJson(data);
  QJsonObject object;
  if (document.isObject()){
    object = document.object();
  }else{
    ok = false;
  }
  return object;
}

QByteArray JSONFractalLoader::readFile(const QString& path, bool& ok)
{
  QFile file(path);
  ok = true;
  QByteArray data;
  if (file.exists() && file.open(QFile::ReadOnly)){
    data = file.readAll();
  }
  else{
    ok = false;
  }
  return data;
}

Property* JSONFractalLoader::createPropertyFromJson(const QJsonObject& json)
{
  Property* prop = nullptr;
  QString type = json["type"].toString();
  if (hasCreatorForType(type)){
    prop = creator(type)(json);
  }
  return prop;
}

JSONFractalLoader::creator_t JSONFractalLoader::creator(const QString& type)
{
  if (hasCreatorForType(type))
    return m_creatorMap[type];
  else
    return nullptr;
}
