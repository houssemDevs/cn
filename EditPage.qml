import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {

    property int projectId
    property int projectIndex
    anchors.fill: parent
    ColumnLayout {
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 10
        anchors.bottomMargin: 5
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        Text {
            text: "Projet :"
        }
        TextInputFiled {
            id: projectTitleInput
            Layout.preferredWidth:  parent.width - 10
            Layout.preferredHeight: 30
            Layout.alignment: Qt.AlignHCenter
            border.width: focus?1:0
            border.color: "blue"
        }
        Text {
            text: "Emplacement :"
        }
        TextInputFiled {
            id: projectLocationInput
            Layout.preferredWidth:  parent.width - 10
            Layout.preferredHeight: 30
            Layout.alignment: Qt.AlignHCenter
            border.width: focus?1:0
            border.color: "blue"
        }
        Text {
            text: "Date du controle :"
        }
        TextInputFiled {
            id: projectDateInput
            Layout.preferredWidth:  parent.width - 10
            Layout.preferredHeight: 30
            Layout.alignment: Qt.AlignHCenter
            border.width: focus?1:0
            border.color: "blue"
        }
        Text {
            text: "Description :"
        }
        TextAreaFiled {
            id: projectDescriptionInput
            Layout.preferredWidth:  parent.width - 10
            Layout.preferredHeight: 90
            Layout.alignment: Qt.AlignHCenter
            border.width: focus?1:0
            border.color: "blue"
        }
        Button {
            Layout.preferredHeight: 40
            Layout.preferredWidth: parent.width - 10
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            text: "Enregistrer"
            onClicked: {
                projectsModel.modifyProject(projectTitleInput.text,
                                            projectLocationInput.text,
                                            projectDateInput.text,
                                            projectDescriptionInput.text,
                                            projectId,
                                            projectIndex);
            }
        }
        Rectangle {
            Layout.fillHeight: true
        }
    }
    function setupFields(title, date, location, description, id, index){
        projectTitleInput.text = title
        projectDateInput.text = date
        projectLocationInput.text = location
        projectDescriptionInput.text = description
        projectId = id
        projectIndex = index
    }
}
