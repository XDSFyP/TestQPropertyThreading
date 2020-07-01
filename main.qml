import QtQuick 2.12
import QtQuick.Window 2.12

import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Label {
        id: time1
        text: model.time
    }

    BusyIndicator {
        id: busyIndicator
        x: 0
        y: 23
    }

    PathView {
        id: pathView
        x: 0
        y: 135
        width: 640
        height: 130
        delegate: Column {
            spacing: 5
            Rectangle {
                width: 40
                height: 40
                color: colorCode
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                x: 5
                text: name
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
            }
        }
        path: Path {
            startY: 100
            startX: 120
            PathQuad {
                x: 120
                y: 25
                controlY: 75
                controlX: 260
            }

            PathQuad {
                x: 120
                y: 100
                controlY: 75
                controlX: -20
            }
        }
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
    }

    Button {
        id: button
        x: 0
        y: 271
        text: qsTr("Press me!!")
        checkable: true
        onToggled: model.onButtonPress(button.checked)
    }

    Label {
        id: label
        x: 106
        y: 294
        text: model.boolValue
    }


}
