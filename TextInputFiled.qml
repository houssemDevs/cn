import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

FocusScope {
    id: root
    Layout.preferredHeight: 20
    Layout.preferredWidth: 60
    property alias text: input.text
    property alias border: background.border
    property alias backgroundColor: background.color
    property alias textColor: input.color
    Rectangle {
        id: background
        anchors.fill: parent
        color: "darkgrey"
        TextInput {
            id: input
            anchors.fill: parent
            anchors.margins: 3
            verticalAlignment: TextInput.AlignVCenter
            focus: true
        }

    }
}
