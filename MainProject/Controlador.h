#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "DbManager.h"
#include <QDebug>
#include <QString>
#include <QVector>
#include <QObject>
class Controlador : public QObject
{
  Q_OBJECT
public:
  Controlador();
  ~Controlador();
  Q_INVOKABLE void createNewGroup(const QString &nameTable);
  Q_INVOKABLE void addRemedio(const Remedio &rmd, const QString &nameTable);
  Q_INVOKABLE void removeRemedio(const QString &nomeRemedio, const QString &nameTable);
  Q_INVOKABLE void dropTabela(const QString &nameTable);
  Q_INVOKABLE QVector<Remedio> getAllValuesOfTables(const QString &nomeTabela);
  Q_INVOKABLE QVector<QString> getAllTables();
  bool verifyExistTable(QString table);
signals:
  void groupCreated();
  void remedioAdded();
  void remedioRemoved();
  void tabelaDropped();
private:
  DbManager *dbManager;
};

#endif // CONTROLADOR_H

//  QDate dt;
//  dt.setDate(2023,02,02);
//  QDate dt2;
//  dt2.setDate(2023,02,03);
//  Remedio rmd{"122","teste",21,"grupoCriado",dt,dt2};
