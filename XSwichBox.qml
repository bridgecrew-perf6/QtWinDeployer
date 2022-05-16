import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
	id: id_switch
	width: 50
	height: 150
//	color: "#eaeaea"
	color: isActive ? id_rect_active.color : id_rect_deactive.color
	radius: 15
	anchors.left: parent.left
	anchors.top: parent.top
	anchors.topMargin: 30
	anchors.leftMargin: 10
	property int duration: 300
	property bool isActive: true
	property alias activeColor: id_rect_active.color
	property alias deactiveColor: id_rect_deactive.color

	Rectangle {
		id: id_rect_active
		color: "#40c9ff"
	}
	Rectangle {
		id: id_rect_deactive
		color: "#ff7777"
	}

	MouseArea {
		anchors.fill: parent
		signal isActiveChanged(value: bool)

		onClicked: {
			if(id_animation_toggle.running === false)
			{
				parent.isActive = !parent.isActive
				isActiveChanged(parent.isActive)
				id_animation_color.start()
				id_animation_toggle.start()
			}
		}
	}

	NumberAnimation {
		id: id_animation_toggle
		target: id_switch_toggle
		property: "anchors.topMargin"
		easing.overshoot: 0.5
		duration: id_switch.duration
		easing.type: Easing.InOutBack
		running: false
		from: id_switch.isActive ? id_switch.height - 42 : 8
		to: id_switch.isActive ? 8 : id_switch.height - 42
	}

	PropertyAnimation {
		id: id_animation_color
		target: id_switch
		property: "color"
		from: id_switch.isActive ? id_rect_deactive.color : id_rect_active.color
		to: id_switch.isActive ? id_rect_active.color : id_rect_deactive.color
		duration: id_switch.duration - 100
		running: false
	}

	Rectangle {
		id: id_switch_toggle
		height: 34
		color: "#ffffff"
		radius: 10
		anchors.left: parent.left
		anchors.right: parent.right
		anchors.top: parent.top
		anchors.rightMargin: 8
		anchors.leftMargin: 8
		anchors.topMargin: parent.isActive ? 8 : id_switch.height - 42
	}
}
