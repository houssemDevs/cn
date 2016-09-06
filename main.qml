import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SplitView {
        anchors.fill: parent
        ListView {
            id: lview
            width: 100
            model: notesModel
            delegate: Text {
                text: display
            }
        }
        Rectangle {
            height: parent.height
            Layout.minimumWidth: 100
            Column {
                anchors.fill: parent
                spacing: 10
                TextInput {
                    id: notetext
                    text: "Enter your notes here"
                }
                Button {
                    id: submit
                    text: "Add"
                    onClicked: {
                        lview.model.addNewNote(notetext.text);
                    }
                }
            }
        }
    }

}
