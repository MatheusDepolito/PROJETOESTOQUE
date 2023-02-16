#include "Remedio.h"

Remedio::Remedio(QString codRemedio, QString nomeRemedio, int quantidade, QString grupo,QDate dataLancamento, QDate validade )
{
  this->codRemedio = codRemedio;
  this->nomeRemedio = nomeRemedio;
  this->dataLancamento = dataLancamento;
  this->grupo = grupo;
  this->validade = validade;
  this->quantidade = quantidade;
}

QString Remedio::getCodRemedio() const
{
  return codRemedio;
}

void Remedio::setCodRemedio(const QString &newCodRemedio)
{
  codRemedio = newCodRemedio;
}

QString Remedio::getNomeRemedio() const
{
  return nomeRemedio;
}

void Remedio::setNomeRemedio(const QString &newNomeRemedio)
{
  nomeRemedio = newNomeRemedio;
}

QDate Remedio::getDataLancamento() const
{
  return dataLancamento;
}

void Remedio::setDataLancamento(const QDate &newDataLancamento)
{
  dataLancamento = newDataLancamento;
}

QString Remedio::getGrupo() const
{
  return grupo;
}

void Remedio::setGrupo(const QString &newGrupo)
{
  grupo = newGrupo;
}

QDate Remedio::getValidade() const
{
  return validade;
}

void Remedio::setValidade(const QDate &newValidade)
{
  validade = newValidade;
}

int Remedio::getQuantidade() const
{
  return quantidade;
}

void Remedio::setQuantidade(const int &newQuantidade)
{
  quantidade = newQuantidade;
}
