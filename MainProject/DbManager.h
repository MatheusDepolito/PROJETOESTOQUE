#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QVector>

#include "Remedio.h"
class DbManager
{
public:
  DbManager();
  void connectDb();
  void createNewGrup(const QString &nameTable);
  void addRemedio(const Remedio &rmd, const QString &nameTable);
  void removeRemedio(const QString &nomeRemedio, const QString &nameTable);
  void dropTabela(const QString &nameTable);
  void executeQuery(const QString &query, const QString &arg1 = "", const QString &arg2 = "");
  QVector<QString> getAllTables();
  QVector<Remedio> getAllValuesOfTables(const QString &nameTable);
private:
  QSqlDatabase db;
};

#endif // DBMANAGER_H
