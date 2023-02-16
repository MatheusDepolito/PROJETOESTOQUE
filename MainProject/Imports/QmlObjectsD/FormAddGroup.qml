import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Cores 1.0
import Botoes 1.0
import Icons 1.0
import "../Js/CreateD.js" as Js
Rectangle{
  id: paiFormGroup
  anchors.centerIn:parent
  width: parent.width * 0.2
  height: parent.height * 0.3
  color: Cores.cor2
  radius:10

    ColumnLayout { // Layout
      id: name
      anchors.fill: parent
      spacing: 0
      Rectangle {
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.maximumHeight: 30
        color: "transparent"
      ButtonIcon{ //Botao x
        id:buttonX
        width: 30
        height: 30

        anchors.top: parent.top
        icon.path: IconVault.x
        radius: 0
        tap{
          onClicked:{
            paiFormGroup.destroy()
            paiPage1.count = 0
            console.log("destruiu")
          }
        }
      }
    }
      Rectangle { // Form
        Layout.fillHeight: true
        Layout.fillWidth: true
        color: "transparent"
        ColumnLayout {
          anchors.fill: parent
          spacing: 0
          Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "transparent"
            TextField {
              id: labelNomeGrupo
              width: parent.width / 1.2
              anchors.centerIn: parent
              color: "white"
              placeholderText: qsTr("Titulo")
              placeholderTextColor: "white"
              Layout.alignment: Qt.AlignHCenter
  //            onTextChanged: test.setComprimento(comp.text)
              background: Rectangle{
                width: parent.width
                height: 2
                anchors.bottom: parent.bottom
              }
            }
          }
          Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "transparent"
            TextField {
              id: labelDescricaoGrupo
              width: parent.width / 1.2
              anchors.centerIn: parent
              color: "white"
              placeholderText: qsTr("Detalhe adicional")
              placeholderTextColor: "white"
  //            onTextChanged: test.setLargura(larg.text)
              background: Rectangle{
                width: parent.width
                height: 2
                anchors.bottom: parent.bottom
              }
            }
          }


        }
      }
      Rectangle {
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.maximumHeight: 50
        color: "transparent"
        ButtonColl {
          id: botaoCriar
          width: 100
          height: 35
          colorNormal: Cores.cor3
          colorHovered: Cores.cor4
          colorPressed: Cores.cor3
          anchors.centerIn: parent
          title: "Criar Grupo"

          TapHandler{
            onTapped: {
              Js.createSquareGroup(labelNomeGrupo.text)
              myControl.createNewGroup(labelNomeGrupo.text)

            }
          }
        }
      }
    }
}

