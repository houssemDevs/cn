import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    anchors.fill: parent

    ListView {
        id: projectList
        anchors.fill: parent
        anchors.margins: 3
        model: projectsModel
        delegate: plDelegate
    }

    Component {
        id: plDelegate
        RowLayout {
            id: mainlayout
            width: ListView.view.width
            spacing: 3
            height: 80
            ColumnLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignLeft
                Text {
                    text: projectTitle + " " + projectDescriptionText.width + " " + mainlayout.width
                    Layout.maximumWidth: mainlayout.width - 120
                    elide: Text.ElideRight
                    font.pointSize: 18
                    font.bold: true
                }
                Text {
                    text: "Le " + projectDate + " à " + projectLocation
                    Layout.maximumWidth: mainlayout.width - 120
                    elide: Text.ElideRight
                    font.pointSize: 14
                }
                Text {
                    id: projectDescriptionText
                    Layout.maximumWidth: mainlayout.width - 120
                    text: projectDescription
                    elide: Text.ElideRight
                    clip: true
                    font.pointSize: 12
                }
            }
            RowLayout {
                Layout.alignment: Qt.AlignRight
                Layout.maximumWidth: 120
                Layout.preferredWidth: 100
                spacing: 6
                CustomButton {
                    id: editButton
                    Layout.minimumWidth: 10
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 40
                    image: "icons/EditButton.svg"
                }
                CustomButton {
                    id: removeButton
                    Layout.minimumWidth: 10
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 40
                    image: "icons/CrossButton.svg"
                    onClicked: {
                        projectsModel.removeProject(projectId,index);
                    }
                }
            }
        }
    }

}
