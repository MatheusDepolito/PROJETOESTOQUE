#include <Controlador.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>
#include <qdebug.h>


int main(int argc, char *argv[])
{

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  Controlador myControl;
  //myControl.getAllTables();
  engine.rootContext()->setContextProperty("myControl", &myControl);
//  engine.setContextProperty("Control", &myControl);

//  QVector <Remedio> r = db.getAllValuesOfTables("grupoCriado");
//  for(int i = 0;i <r.length(); i++){
//   qDebug() <<  r.at(i).getNomeRemedio();
//   qDebug() <<  r.at(i).getGrupo();
//   qDebug() <<  r.at(i).getValidade();
//   qDebug() <<  r.at(i).getDataLancamento();
//  }



  const QUrl url("qrc:/main.qml");
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.addImportPath("qrc:/Imports");
  engine.load(url);

  return app.exec();
}
