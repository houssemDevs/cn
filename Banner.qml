import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    signal newProjectSignal()
    signal mainListSignal()
    signal editProjectSignal()
    onEditProjectSignal: compLoader.sourceComponent = editCompo
    Rectangle {
        anchors.fill: parent
        color: "grey"
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
                    Layout.alignment: Qt.AlignLeft
                    Layout.margins: 10
                    text: "Visites"
                    font.pointSize: 20
                }
                CustomButton {
                    Layout.alignment: Qt.AlignRight
                    Layout.margins: 10
                    image: "icons/AddButton.svg"
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
                CustomButton {
                    Layout.alignment: Qt.AlignLeft
                    Layout.margins: 10
                    image: "icons/ArrowButtonBack.svg"
                    onClicked: {
                        compLoader.sourceComponent = mainCompo
                        mainListSignal()
                    }
                }
                Text {
                    Layout.alignment: Qt.AlignRight
                    Layout.margins: 10
                    font.pointSize: 20
                    text: "Nouvelle visite"
                }
            }
        }
        Component {
            id: editCompo
            RowLayout {
                anchors.fill: parent
                CustomButton {
                    Layout.alignment: Qt.AlignLeft
                    Layout.margins: 10
                    image: "icons/ArrowButtonBack.svg"
                    onClicked: {
                        compLoader.sourceComponent = mainCompo
                        mainListSignal()
                    }
                }
                Text {
                    Layout.alignment: Qt.AlignRight
                    Layout.margins: 10
                    font.pointSize: 20
                    text: "Modifie les donnees"
                }
            }
        }
    }
}
