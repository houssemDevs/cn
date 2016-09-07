import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    anchors.fill: parent

    ListView {
        id: projectList
        anchors.fill: parent
        model: projectsModel
        delegate: plDelegate
    }

    Component {
        id: plDelegate
        RowLayout {
            width: ListView.view.width
            height: 80
            ColumnLayout {
                Layout.fillWidth: true
                Text {
                    text: projectTitle
                    font.pointSize: 18
                    font.bold: true
                }
                Text {
                    text: "Le " + projectDate + " à " + projectLocation
                    font.pointSize: 14
                }
                Text {
                    text: projectDescription
                }
            }
            Button {
                id: editButton
                Layout.minimumWidth: 10
                text: "M"

            }
            Button {
                id: removeButton
                Layout.minimumWidth: 10
                text: "E"
                onClicked: {
                    projectsModel.removeProject(projectId,index);
                }
            }
        }
    }

}
