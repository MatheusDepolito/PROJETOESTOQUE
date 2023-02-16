import QtQuick 2.15
import QtQuick.Layouts 1.15
import Cores 1.0
import "../Js/CreateD.js" as Js
Item{
  width: gridView.cellWidth * 0.9
  height: gridView.cellHeight * 0.9
  property alias title: txtTitle.text
  property alias edit: edit.visible
//  property alias detalhe: txtDetalhe.text
  Rectangle {
    id: group
    anchors.fill: parent
    color: Cores.cor2
    radius:12
    z:0

    ColumnLayout {
      id: name
      anchors.fill: parent
      spacing: 0
      z:0
      Rectangle {
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.maximumHeight: parent.height * 0.33
        color: "transparent"
        Text {
          id:txtTitle
          text: qsTr("")
          color: "white"
          anchors.centerIn: parent
        }

      }
    }
    Rectangle{
      id: edit
      width:100
      height:50
      visible: false
      x: mouse.mouseX
      y: mouse.mouseY
      color:"red"
    }
    MouseArea{
      id: mouse
      anchors.fill: parent
      acceptedButtons: Qt.RightButton
      onClicked: {
        var itemClicado = listModel.get(index)
        console.log(itemClicado.myTitle)
        itemClicado.isVisible = true

      }
    }
    HoverHandler {
      id: hoverHandler
      cursorShape: Qt.PointingHandCursor
    }
  }
}

