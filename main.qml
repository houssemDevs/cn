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
        onNewProjectSignal: {
            pageLoader.source = "NewProjectPage.qml"
            modConn.target = null
        }
        onMainListSignal: {
            pageLoader.source = "MainPage.qml"
            modConn.target = pageLoader.item
        }
        onEditProjectSignal: {
            pageLoader.source = "MainPage.qml"
            modConn.target = null
        }

        Component.onCompleted: mainListSignal()
    }

    Connections {
        id: modConn
        target: null
        onModifyProject: {
            banner.editProjectSignal()
            pageLoader.source = "EditPage.qml"
            pageLoader.item.setupFields(title,location,date,description,id,index)
        }
    }

    Loader {
        id: pageLoader
        anchors.top: banner.bottom
        clip: true
        height: parent.height - banner.height
        width: parent.width
        source: "MainPage.qml"
    }
}
