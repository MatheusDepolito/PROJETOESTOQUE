#include "Grupo.h"

Grupo::Grupo(QString nomeGrupo, QString detalhe)
{
  this->nomeGrupo = nomeGrupo;
  this->detalhe = detalhe;
}

QString Grupo::getNome() const
{
  return nomeGrupo;
}

void Grupo::setNome(const QString &newNomeGrupo)
{
  nomeGrupo = newNomeGrupo;
}

QString Grupo::getDetalhe() const
{
  return detalhe;
}

void Grupo::setDetalhe(const QString &newDetalhe)
{
  detalhe = newDetalhe;
}
