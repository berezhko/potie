import QtQuick 2.8
import QtQuick.Controls 1.4

Rectangle {
    id: mainrect

    Column {
        anchors.fill: parent
        TableView {
            id: tableview
            width: parent.width
            anchors.bottom: mybutton
            TableViewColumn {
                role: "Ug"
                title: "Ug"
                width: parent.width / 2
                delegate: delegate
            }
            TableViewColumn {
                role: "If"
                title: "If"
                width: parent.width / 2
            }
            model: libraryModel
        }

        Button {
            id: mybutton
            text: "Remove Row"
            onClicked: libraryModel.remove(tableview.currentRow)
        }

        TableView {
            id: tableview2
            width: parent.width
            anchors.bottom: mybutton
            TableViewColumn {
                role: "Ug"
                title: "Ug2"
                width: parent.width / 2
            }
            TableViewColumn {
                role: "If"
                title: "If2"
                width: parent.width / 2
            }
            model: libraryModel
        }

    }

    Component {
        id: delegate
        TextEdit {
            id: textedit
            color: "red"
            text: styleData.value
            font.pixelSize: 12
            onEditingFinished: libraryModel.setData(libraryModel.index(tableview.currentRow, tableview.currentColumn, "1"), text, "1")
        }
    }

    ListModel {
        id: libraryModel
        ListElement {
            Ug: "100"
            If: "10"
        }
        ListElement {
            Ug: "200"
            If: "20"
        }
        ListElement {
            Ug: "300"
            If: "30"
        }
    }
}
