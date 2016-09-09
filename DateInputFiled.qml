import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

FocusScope {
    id: root
    Layout.preferredHeight: 20
    property alias text: input.text
    property alias border: background.border
    property alias backgroundColor: background.color
    property alias textColor: input.color

    Loader {
        id: calendarLoader
        active: false
        sourceComponent: Calendar {}
        z: 1
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 1
        RowLayout{
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle {
                id: background
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: "darkgrey"
                TextInput {
                    id: input
                    anchors.fill: parent
                    anchors.margins: 3
                    verticalAlignment: TextInput.AlignVCenter
                    focus: true
                }
            }

            Button {
                id: calandar
                Layout.fillHeight: true
                Layout.preferredWidth: 40
                onClicked: {
                    console.log("clicked calandar")
                    calendarLoader.active = !calendarLoader.active
                }
            }
        }
    }
}

