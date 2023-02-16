import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QmlObjectsD 1.0

Item{
  id:paiPage2
  property alias gridModel: gridView
  Item {
    id: page2
    anchors.fill: parent

    Component.onCompleted: {
      var nomeTabelas = myControl.getAllTables();
      for(var i = 0; i<nomeTabelas.length;i++){
        gridView.model.append({myTitle: nomeTabelas[i], isVisible: false});
      }
    }
    GridView{
      id:gridView
      anchors.fill: parent
      anchors.leftMargin: 10
      cellHeight: width / 6
      cellWidth:  width /5
      model: ListModel{id:listModel}
      delegate: SquareGroup{
      title: myTitle
      edit: isVisible
  //    detalhe: myDetalhe
      }
    }
  }
//  Rectangle{
//    width:100
//    height:100
//    color:"red"
//    TapHandler{
//      onTapped: {

//        listModel.set(2,{"color": "red"})
//        console.log("click red")
//      }
//    }
//  }
}
/*
  console.log(listModel.get(2).myTitle)
  listModel.get(2).myTitle = "torta"
*/
