import QtQuick 2.15
import QtQuick.Particles 2.15
import Icons 1.0
import QtQuick.Layouts 1.15
import Cores 1.0
import Botoes 1.0
import QmlObjectsD 1.0
import "../Js/CreateD.js" as Js

Item{
  id:paiPage1
  property int count:  0
  property var test: page2.gridModel
  Item{
    id:page1
    anchors.fill: parent
    GridLayout
    {
      anchors.fill: parent
      columns:1
      rows:2
      Rectangle{
        Layout.fillHeight: true
        Layout.fillWidth: true
        color: "transparent"
        border.color: "gray"
        Text {
          id: calendarios
          text: qsTr("Calendario")
          color: "white"
          anchors.centerIn: parent
        }
      }
      Item{
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.maximumHeight: parent.height * 0.3
        ButtonColl{
          id: criaGrupo
          width: parent.width * 0.25
          height:parent.height * 0.85
          anchors.verticalCenter: parent.verticalCenter
          anchors.left: parent.left
          anchors.leftMargin: 20
          colorNormal: Cores.cor2
          colorHovered: Cores.cor3
          colorPressed: Cores.cor2
          title: "Adicione um grupo aqui"

          tap{

            onTapped:{

              if(count === 0 ){
                Js.formCreateGroup()
                count = 1
                console.log("Criou")
              }

            }

          }
        }


//        Rectangle{
//          //jogar um botao aqui depois
//          width: parent.width * 0.25
//          height:parent.height * 0.9
//          anchors.verticalCenter: parent.verticalCenter
//          anchors.left: parent.left
//          anchors.leftMargin: 20
//          radius: 15
//          color: Cores.cor2

//        }
      }
    }
  }
}

//    ColumnLayout{
//id:gridPage1
//anchors.fill: parent
//Rectangle {
//  id:paiCalendario
//  Layout.fillHeight: true
//  Layout.fillWidth: true
//  color: "red"
//}
//Rectangle {
//  id: paiCriaGrupos
//  Layout.fillHeight: true
//  Layout.fillWidth: true
//  Layout.maximumHeight: paiCalendario.height * 0.8
//  color: "blue"

//}
//}
