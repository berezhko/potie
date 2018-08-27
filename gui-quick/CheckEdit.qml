import QtQuick 2.0
import QtQuick.Controls 1.4


Rectangle {
    width: 640
    height: 480

    ListModel {
        id: tstModel
        ListElement { animal: "cat" }
        ListElement { animal: "cat" }
        ListElement { animal: "cat" }
        ListElement { animal: "cat" }
        ListElement { animal: "cat" }
        ListElement { animal: "cat" }
        ListElement { animal: "cat" }
    }


    TextField{
        id: tableViewCustomHeader

        property int curRow: tableView.currentRow
        property bool isActual: curRow >= 0

        function reloadText() { text = tstModel.get(curRow).animal }
        function saveText()   { tstModel.setProperty(curRow, "animal", text); tableView.model = tstModel;  }

        width: animalColumn.width
        height: isActual ? 20 : 0

        onCurRowChanged: {
            if ( isActual >= 0 ) reloadText();
            focus = true;
        }
        onTextChanged: if ( isActual >= 0 ) saveText()
    }

    TableView {
        id: tableView
        anchors {
            top: tableViewCustomHeader.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        model: tstModel
        headerVisible: false

        TableViewColumn {
            id: animalColumn

            title: "Animal"
            role: "animal"
            width: 200
            resizable: false
            movable:  false
        }
    }
}
