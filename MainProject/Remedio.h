#ifndef REMEDIO_H
#define REMEDIO_H

#include <QString>
#include <QDate>
//Classe que define o objeto remedio e suas propriedades

class Remedio
{
public:
  Remedio(QString codRemedio,QString nomeRemedio , int quantidade, QString grupo, QDate dataLancamento, QDate validade);

  QString getCodRemedio() const;                           // 1 Pega CODIGO REMEDIO
  void setCodRemedio(const QString &newCodRemedio);        // 1 Seta CODIGO REMEDIO
  QString getNomeRemedio() const;                          // 2 Pega NOME REMEDIO
  void setNomeRemedio(const QString &newNomeRemedio);      // 2 Seta NOME REMEDIO
  QDate getDataLancamento() const;                       // 3 Pega DATA LANCAMENTO DO REMEDIO
  void setDataLancamento(const QDate &newDataLancamento);// 3 Seta DATA LANCAMENTO DO REMEDIO
  QString getGrupo() const;                                // 4 Pega GRUPO QUE O REMEDIO PERTENCE
  void setGrupo(const QString &newGrupo);                  // 4 Seta GRUPO DO REMEDIO
  QDate getValidade() const;                             // 5 Pega VALIDADE REMEDIO
  void setValidade(const QDate &newValidade);            // 5 Seta VALIDADE REMEDIO
  int getQuantidade() const;                           // 6 Pega QUANTIDADE REMEDIO
  void setQuantidade(const int &newQuantidade);        // 6 Seta QUANTIDADE

private:
  QString codRemedio;
  QString nomeRemedio;
  QDate dataLancamento;
  QString grupo;
  QDate validade;
  int quantidade;
};

#endif // REMEDIO_H
