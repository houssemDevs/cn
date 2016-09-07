import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Banner {
        id: banner
        width: parent.width
        height: 80
        x: 0; y: 0
        onNewProjectSignal: pageLoader.source = "NewProjectPage.qml"
        onMainListSignal: pageLoader.source = "MainPage.qml"
    }

    Loader {
        id: pageLoader
        anchors.top: banner.bottom
        clip: true
        height: parent.height - banner.height
        width: parent.width
    }
}
