import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4

Button {
    property alias source: icon.source
    style: ButtonStyle {
        background: Image {
            id: icon
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            sourceSize.width: icon.width
            sourceSize.height: icon.height
        }
    }
}
