//var component
//const formCreateGroup = ()=>{
//  component = Qt.createComponent("../QmlObjectsD/FormAddGroup.qml")
//  if(component.status === Component.Ready || component.status === Component.Error){
//      finishCreation()
//  } else{
//    component.statusChanged.connect(finishCreation())
//  }
//}

//function finishCreation() {
//    if (component.status === Component.Ready) {
//        var incubator = component.incubateObject(body, {"anchors.centerIn": parent});
//        if (incubator.status === Component.Ready) {
//          var image = incubator.object
//        }
//    }
//    else {
//       incubator.onStatusChanged = function(status){
//         if(status === Component.Ready){
//           var image = incubator.object
//         }
//       }
//    }
//}

//function getComp(){
//  return component.status
//}

function formCreateGroup(){
  return Qt.createQmlObject(`import QmlObjectsD 1.0
                            FormAddGroup{}`,page1,"parent")
}
function createSquareGroup(title){
  test.model.append({myTitle: title})



}

