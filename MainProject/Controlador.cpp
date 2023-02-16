#include "Controlador.h"

Controlador::Controlador()
{
  dbManager = new DbManager();
}

Controlador::~Controlador()
{
  delete dbManager;
}

void Controlador::createNewGroup(const QString &nameTable)
{
  if(!verifyExistTable(nameTable)){
   dbManager->createNewGrup(nameTable);
  }
}

void Controlador::addRemedio(const Remedio &rmd, const QString &nameTable)
{
  dbManager->addRemedio(rmd,nameTable);
}

void Controlador::removeRemedio(const QString &nomeRemedio, const QString &nameTable)
{
  dbManager->removeRemedio(nomeRemedio,nameTable);
}

void Controlador::dropTabela(const QString &nameTable)
{
  dbManager->dropTabela(nameTable);
}

QVector<Remedio> Controlador::getAllValuesOfTables(const QString &nomeTabela)
{
  return dbManager->getAllValuesOfTables(nomeTabela);
}

QVector<QString> Controlador::getAllTables()
{
  return dbManager->getAllTables();

}

bool Controlador::verifyExistTable(QString table)
{
  QVector<QString> verify = getAllTables();
  if(verify.contains(table)){
      qDebug() << "Tabela já existe";
      return true;
    }
      qDebug() << "Tabela não existe";
      return false;
}
