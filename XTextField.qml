import QtQuick 2.0
import QtQuick.Controls 2.15

TextField {
	property alias placeHolderText: textField.placeholderText
	property alias background_color: id_background_textField.color
	property alias border_color: id_background_textField.border.color
	property alias text: textField.text
	property alias color: textField.color

	id: textField
	width: 400
	height: 40
	selectByMouse: true
	readOnly: true
	placeholderText: qsTr("Place Text Holder...")
	background: Rectangle {
		id: id_background_textField
		color: "white"
		radius: 5
		border.width: 0
		border.color: "#2596be"
	}

	NumberAnimation {
		id: id_animation_focus_true
		target: id_background_textField
		property: "border.width"
		duration: 100
		easing.type: Easing.Linear
		from: 0
		to: 3
	}

	NumberAnimation {
		id: id_animation_focus_false
		target: id_background_textField
		property: "border.width"
		duration: 100
		easing.type: Easing.Linear
		from: 3
		to: 0
	}

	onActiveFocusChanged: {
		if(activeFocus === true)
			id_animation_focus_true.start()
		else
			id_animation_focus_false.start()
	}
}
