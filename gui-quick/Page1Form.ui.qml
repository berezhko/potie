import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    id: page
    width: 600
    height: 400
    font.pixelSize: 8

    header: Label {
        id: label
        height: 50
        text: qsTr("Режим работы и номинальные данные")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10

        Grid {
            id: grid
            height: 50
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: grid1.top
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
        }
    }

    MyTable {
        id: myTable
        radius: 2
        anchors.fill: parent
    }
}
