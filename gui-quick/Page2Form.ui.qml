import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    id: page
    width: 600
    height: 400
    font.pixelSize: 8

    header: Label {
        id: headlabel
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    CheckEdit {
        id: checkEdit
        anchors.fill: parent
    }
}
