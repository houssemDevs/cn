import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    signal newProjectSignal()
    signal mainListSignal()
    Rectangle {
        anchors.fill: parent
        color: "lightgrey"
        Loader {
            id: compLoader
            anchors.fill: parent
            sourceComponent: mainCompo
        }
        Component {
            id: mainCompo
            RowLayout {
                anchors.fill: parent
                Text {
                    text: "ControllerNotes"
                }
                Button {
                    text: "New project"
                    onClicked: {
                        compLoader.sourceComponent = newCompo
                        newProjectSignal()
                    }
                }
            }
        }
        Component {
            id: newCompo
            RowLayout {
                anchors.fill: parent
                Button {
                    text: "goback"
                    onClicked: {
                        compLoader.sourceComponent = mainCompo
                        mainListSignal()
                    }
                }
                Text {
                    text: "New project"
                }
            }
        }
    }
}
