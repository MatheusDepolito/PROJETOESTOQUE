#ifndef GRUPO_H
#define GRUPO_H

#include <QString>
#include <QVector>

// Classe que define um grupo e suas propriedades os grupos são as tabelas do Bd

class Grupo
{
public:
  Grupo(QString nomeGrupo, QString detalhe);
  QString getNome() const;                   // Pega Nome Grupo
  void setNome(const QString &newNomeGrupo); // Seta NOME GRUPO

  QString getDetalhe() const;                 // Pega detalhe grupo
  void setDetalhe(const QString &newDetalhe); // Seta detalhe grupo

private:
  QString nomeGrupo;
  QString detalhe;
};


#endif // GRUPO_H
