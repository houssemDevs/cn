import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1

Item {
    id: root
    Layout.preferredHeight: 30
    Layout.preferredWidth: 60
    property alias image: icon.source
    signal clicked()
    Image {
        id: icon
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        sourceSize.height: icon.height
        sourceSize.width: icon.width
        MouseArea {
            anchors.fill: parent
            onClicked: root.clicked()
        }
    }
}
