#include "DbManager.h"

DbManager::DbManager()
{
  connectDb();
}

void DbManager::connectDb()
{
  db = QSqlDatabase::addDatabase( "QSQLITE" );
  db.setDatabaseName("C:/Users/Matheus/Desktop/PROJETOESTOQUE/BdLite/BancoDeDados.db");

  db.open() ? qDebug()<<"Conexão ok":qDebug() << "Erro conexão com banco de dados falhou " << db.lastError() << 1;
}

void DbManager::executeQuery(const QString &query, const QString &arg1, const QString &arg2)
{
  QSqlQuery qry(db);
     qry.prepare(query);
     if (!arg1.isEmpty()) {
         qry.bindValue(":arg1", arg1);
     }
     if (!arg2.isEmpty()) {
         qry.bindValue(":arg2", arg2);
     }

    bool success = qry.exec();

    success ? qDebug() << "Query executada com sucesso" : qDebug() <<"Erro na execução da query"<<qry.lastError();
}
void DbManager::createNewGrup(const QString &nameTable)
{
  QSqlQuery qry(db);
  qry.prepare("CREATE TABLE IF NOT EXISTS " + nameTable + " (idRemedio INTEGER PRIMARY KEY AUTOINCREMENT, nome TEXT NOT NULL, grupo TEXT NOT NULL, validade DATE NOT NULL, lancamento DATE NOT NULL, quantidade INTEGER NOT NULL);");

  bool success = qry.exec();

  success ? qDebug() << "SUCESSO em executar a query" : qDebug() << "ERRO na qry " << qry.lastError() ;
}

void DbManager::addRemedio(const Remedio &rmd, const QString &nameTable)
{

  QString valuesQry = "(codRemedio, nome,quantidade,grupo,lancamento,validade) VALUES (:codRemedio, :nome, :quantidade, :grupo, :lancamento, :validade)";
  QSqlQuery qry(db);

  qDebug() << valuesQry << " query ---------------";

  qry.prepare("INSERT INTO " + nameTable + valuesQry );

  qry.bindValue(":codRemedio", rmd.getCodRemedio());
  qry.bindValue(":nome", rmd.getNomeRemedio());
  qry.bindValue(":quantidade", rmd.getQuantidade());
  qry.bindValue(":grupo", rmd.getGrupo());
  qry.bindValue(":lancamento", rmd.getDataLancamento());
  qry.bindValue(":validade", rmd.getValidade());

  bool success = qry.exec();
  success ? qDebug() << "SUCESSO em adicionar remedio" : qDebug() << "ERRO em adicionar remedio " << qry.lastError();
}

void DbManager::removeRemedio(const QString &nomeRemedio, const QString &nameTable)
{
  QString qry = "DELETE FROM " + nameTable + " WHERE nome = (:arg1)";
  executeQuery(qry, nomeRemedio);
}

void DbManager::dropTabela(const QString &nameTable)
{
  QString query = "DROP TABLE " + nameTable;
  executeQuery(query);
}

QVector<Remedio> DbManager::getAllValuesOfTables(const QString &nameTable)
{
  QString query = "SELECT * FROM " + nameTable;
  QSqlQuery qry(db);
  bool success = qry.exec(query);
  executeQuery(query,nameTable);
  if(!success){
      qDebug() << "Erro ao pegar todos os valores das tabelas" << qry.lastError();
      return{};
    }

  QVector<Remedio> vetorRemedios;
  while(qry.next()){
      QString codRemedio = qry.value(1).toString();
      QString nomeRemedio = qry.value(2).toString();
      int quantidade = qry.value(3).toInt();
      QString grupo = qry.value(4).toString();
      QDate lancamento = qry.value(5).toDate();
      QDate validade = qry.value(6).toDate();

      Remedio r{codRemedio,nomeRemedio,quantidade,grupo,lancamento,validade};

      vetorRemedios.push_back(r);
  }
  return vetorRemedios;
}

QVector<QString> DbManager::getAllTables()
{
  QSqlQuery qry(db);
  qry.prepare("SELECT * FROM sqlite_master WHERE type = 'table' AND name != 'sqlite_sequence'");
    bool success = qry.exec();
    if(!success){
        qDebug() << "Erro ao pegar todas  as tabelas" << qry.lastError();
        return{};
    }
    QVector<QString> t;
    while(qry.next()){
      t.push_back(qry.value(1).toString());
    }
    return t;
}


//  db = QSqlDatabase::addDatabase("QMYSQL");
//  db.setHostName("127.0.0.1");
//  db.setUserName("root");
//  db.setPassword("root");
//  db.setDatabaseName("estoqueremedios");

