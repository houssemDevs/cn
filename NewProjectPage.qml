import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {

    anchors.fill: parent
    ColumnLayout {
        anchors.fill: parent
        Text {
            Layout.minimumHeight: 20
            Layout.maximumHeight: 25
            Layout.minimumWidth: 60
            text: "Projet :"
        }
        Rectangle {
            color: "darkgrey"
            Layout.minimumHeight: 20
            Layout.maximumHeight: 25
            Layout.minimumWidth: 60
            width: parent.width
            TextInput {
                anchors.fill: parent
                id: projectTitleInput
            }
        }
        Text {
            text: "Emplacement :"
        }
        Rectangle {
            color: "darkgrey"
            Layout.minimumHeight: 20
            Layout.maximumHeight: 25
            Layout.minimumWidth: 60
            width: parent.width
            TextInput {
                anchors.fill: parent
                id: projectLocationInput
            }
        }
        Text {
            text: "Date du controle :"
        }
        Rectangle {
            color: "darkgrey"
            Layout.minimumHeight: 20
            Layout.maximumHeight: 25
            Layout.minimumWidth: 60
            width: parent.width
            TextInput {
                anchors.fill: parent
                id: projectDateInput
            }
        }
        Text {
            text: "Description :"
        }
        Rectangle {
            color: "darkgrey"
            Layout.minimumHeight: 20
            Layout.maximumHeight: 25
            Layout.minimumWidth: 60
            width: parent.width
            TextInput {
                anchors.fill: parent
                id: projectDescriptionInput
            }
        }
        Button {
            Layout.maximumHeight: 30
            Layout.maximumWidth: 80
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            text: "Create"
            onClicked: {
                projectsModel.addNewProject(projectTitleInput.text,
                                            projectLocationInput.text,
                                            projectDateInput.text,
                                            projectDescriptionInput.text);
            }
        }

        Rectangle {
            Layout.fillHeight: true
        }
    }

}
