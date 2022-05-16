import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.3

Item {
	id: root
	width: 600
	height: 800

	Rectangle {
		anchors.fill: parent
		color: "white"
	}

	signal updateSettingQML()
	signal textFilterQML(objectName: string, text: string)

	//===================================================================
	//===================================================================
	// Deployer64 Section

	XTextField {
		objectName: "obj_txt_deploy64"
		id: id_txt_deploy64
		x: 67
		width: 495
		height: 40
		enabled: id_switch_box.isActive
		anchors.right: parent.right
		anchors.rightMargin: 25
		anchors {
			top: parent.top
			topMargin: 30
		}
		background_color: Qt.rgba(0.95, 0.95, 0.95)

		onTextChanged: textFilterQML(objectName, text)

		Label {
			anchors {
				top: parent.top
				topMargin: -20
			}
			enabled: parent.enabled
			text: "Where is <b>deployer X64</b>?..."
			font.pointSize: 9
		}

		FileDialog {
			id: id_dialog_deploy64
			nameFilters: ["Exe Files (*.exe)"]

			onAccepted: {
				id_txt_deploy64.text = fileUrl
				updateSettingQML()
			}
		}

		Button {
			id: id_button_deploy64
			height: 35
			enabled: parent.enabled
			anchors {
				top: parent.top
				topMargin: 45
				right: parent.right
			}
			text: "Browse"
			onClicked: id_dialog_deploy64.open()
		}

		Rectangle {
			anchors {
				right: parent.right
				top: parent.top
				bottom: parent.bottom
			}
			width: 40
			color: "transparent"

			Image {
				anchors.centerIn: parent
				source: "qrc:/resource/icon/recyclebin.svg"
				ColorOverlay {
					anchors.fill: parent
					source: parent
					color: "#ababab"

					MouseArea {
						anchors.fill: parent
						hoverEnabled: true

						onEntered: {
							parent.color = "#ff0000"
							parent.opacity = 0.8
						}
						onExited: {
							parent.color = "#ababab"
							parent.opacity = 1
						}
						onClicked: {
							parent.parent.parent.parent.clear()
							updateSettingQML()
						}
					}
				}
			}
		}
	}

	//===================================================================
	//===================================================================
	// Deployer32 Section

	XTextField {
		objectName: "obj_txt_deploy32"
		id: id_txt_deploy32
		x: 67
		enabled: !id_switch_box.isActive
		width: 495
		height: 40
		anchors.right: parent.right
		anchors.rightMargin: 25
		anchors {
			top: parent.top
			topMargin: 140
		}
		background_color: Qt.rgba(0.95, 0.95, 0.95)

		onTextChanged: textFilterQML(objectName, text)

		Label {
			anchors {
				top: parent.top
				topMargin: -20
			}
			enabled: parent.enabled
			text: "Where is <b>deployer X32</b>?..."
			font.pointSize: 9
		}

		FileDialog {
			id: id_dialog_deploy32
			nameFilters: ["Exe Files (*.exe)"]

			onAccepted: {
				id_txt_deploy32.text = fileUrl
				updateSettingQML()
			}
		}

		Button {
			id: id_button_deploy32
			height: 35
			enabled: parent.enabled
			anchors {
				top: parent.top
				topMargin: 45
				right: parent.right
			}
			text: "Browse"
			onClicked: id_dialog_deploy32.open()
		}

		Rectangle {
			anchors {
				right: parent.right
				top: parent.top
				bottom: parent.bottom
			}
			width: 40
			color: "transparent"

			Image {
				anchors.centerIn: parent
				source: "qrc:/resource/icon/recyclebin.svg"
				ColorOverlay {
					anchors.fill: parent
					source: parent
					color: "#ababab"

					MouseArea {
						anchors.fill: parent
						hoverEnabled: true

						onEntered: {
							parent.color = "#ff0000"
							parent.opacity = 0.8
						}
						onExited: {
							parent.color = "#ababab"
							parent.opacity = 1
						}
						onClicked: {
							parent.parent.parent.parent.clear()
							updateSettingQML()
						}
					}
				}
			}
		}
	}

	XSwichBox {
		objectName: "obj_switch_platform"
		id: id_switch_box
		x: 121
		y: 8
		width: 50
		height: 154
		isActive: true
		anchors.topMargin: 28
		anchors.leftMargin: 15
		duration: 300
		onIsActiveChanged: updateSettingQML()
	}

	//===================================================================
	//===================================================================
	// EXE Section

	XTextField {
		objectName: "obj_txt_exe"
		id: id_txt_exe
		width: 550
		anchors {
			top: parent.top
			topMargin: 260
			horizontalCenter: parent.horizontalCenter
		}
		background_color: Qt.rgba(0.95, 0.95, 0.95)

		onTextChanged: textFilterQML(objectName, text)

		Label {
			anchors {
				top: parent.top
				topMargin: -20
			}
			text: "Where is <b>EXE</b>?..."
			font.pointSize: 9
		}

		FileDialog {
			id: id_dialog_exe
			nameFilters: ["Exe Files (*.exe)"]

			onAccepted: {
				id_txt_exe.text = fileUrl
				updateSettingQML()
			}
		}

		Button {
			id: id_button_exe
			height: 35
			anchors {
				top: parent.top
				topMargin: 45
				right: parent.right
			}
			text: "Browse"
			onClicked: id_dialog_exe.open()
		}

		Rectangle {
			anchors {
				right: parent.right
				top: parent.top
				bottom: parent.bottom
			}
			width: 40
			color: "transparent"

			Image {
				anchors.centerIn: parent
				source: "qrc:/resource/icon/recyclebin.svg"
				ColorOverlay {
					anchors.fill: parent
					source: parent
					color: "#ababab"

					MouseArea {
						anchors.fill: parent
						hoverEnabled: true

						onEntered: {
							parent.color = "#ff0000"
							parent.opacity = 0.8
						}
						onExited: {
							parent.color = "#ababab"
							parent.opacity = 1
						}
						onClicked: {
							parent.parent.parent.parent.clear()
							updateSettingQML()
						}
					}
				}
			}
		}
	}

	//===================================================================
	//===================================================================
	// QML Section

	XTextField {
		objectName: "obj_txt_qml"
		id: id_txt_qml
		width: 550
		anchors {
			top: parent.top
			topMargin: 380
			horizontalCenter: parent.horizontalCenter
		}
		background_color: Qt.rgba(0.95, 0.95, 0.95)

		onTextChanged: textFilterQML(objectName, text)

		Label {
			anchors {
				top: parent.top
				topMargin: -20
			}
			text: "Where is <b>QML</b>?..."
			font.pointSize: 9
		}

		FileDialog {
			id: id_dialog_qml
			nameFilters: ["QML Files (*.qml)"]
			selectMultiple: true
			onSelectMultipleChanged: {
				console.log("files: ", fileUrls)
			}

			onAccepted: {
				id_txt_qml.text = folder
				updateSettingQML()
			}
		}

		Button {
			id: id_button_qml
			height: 35
			anchors {
				top: parent.top
				topMargin: 45
				right: parent.right
			}
			text: "Browse"
			onClicked: id_dialog_qml.open()
		}

		Rectangle {
			anchors {
				right: parent.right
				top: parent.top
				bottom: parent.bottom
			}
			width: 40
			color: "transparent"

			Image {
				anchors.centerIn: parent
				source: "qrc:/resource/icon/recyclebin.svg"
				ColorOverlay {
					anchors.fill: parent
					source: parent
					color: "#ababab"

					MouseArea {
						anchors.fill: parent
						hoverEnabled: true

						onEntered: {
							parent.color = "#ff0000"
							parent.opacity = 0.8
						}
						onExited: {
							parent.color = "#ababab"
							parent.opacity = 1
						}
						onClicked: {
							parent.parent.parent.parent.clear()
							updateSettingQML()
						}
					}
				}
			}
		}
	}

	//===================================================================
	//===================================================================
	// Export Section

	XTextField {
		objectName: "obj_txt_export"
		id: id_txt_export
		width: 550
		anchors {
			top: parent.top
			topMargin: 500
			horizontalCenter: parent.horizontalCenter
		}
		background_color: Qt.rgba(0.95, 0.95, 0.95)

		onTextChanged: textFilterQML(objectName, text)

		Label {
			anchors {
				top: parent.top
				topMargin: -20
			}
			text: "Where is <b>EXPORT</b>?..."
			font.pointSize: 9
		}

		FileDialog {
			id: id_dialog_export
			selectFolder: true

			onAccepted: {
				id_txt_export.text = fileUrl
				updateSettingQML()
			}
			//			onFileChanged: {
			//				id_txt_export.text = folder
			//				updateSettingQML()
			//			}
		}

		Button {
			id: id_button_export
			height: 35
			anchors {
				top: parent.top
				topMargin: 45
				right: parent.right
			}
			text: "Browse"
			onClicked: id_dialog_export.open()
		}

		Rectangle {
			anchors {
				right: parent.right
				top: parent.top
				bottom: parent.bottom
			}
			width: 40
			color: "transparent"

			Image {
				anchors.centerIn: parent
				source: "qrc:/resource/icon/recyclebin.svg"
				ColorOverlay {
					anchors.fill: parent
					source: parent
					color: "#ababab"

					MouseArea {
						anchors.fill: parent
						hoverEnabled: true

						onEntered: {
							parent.color = "#ff0000"
							parent.opacity = 0.8
						}
						onExited: {
							parent.color = "#ababab"
							parent.opacity = 1
						}
						onClicked: {
							parent.parent.parent.parent.clear()
							updateSettingQML()
						}
					}
				}
			}
		}
	}

	Rectangle {
		y: 618
		width: 450
		height: 5
		color: Qt.rgba(0.95, 0.95, 0.95)
		anchors.horizontalCenterOffset: 0
		anchors.horizontalCenter: parent.horizontalCenter
	}

	//===================================================================
	//===================================================================
	// QtWinDeploy command

	XTextField {
		objectName: "obj_txt_command"
		id: id_txt_command

		width: 550
		font.pointSize: 8
		placeHolderText: "deploy -command"
		anchors {
			top: parent.top
			topMargin: 670
			horizontalCenter: parent.horizontalCenter
		}
		background_color: Qt.rgba(0.95, 0.95, 0.95)

		onTextChanged: textFilterQML(objectName, text)

		Label {
			anchors {
				top: parent.top
				topMargin: -20
			}
			text: "<b>QtWindeploy.exe</b> - %1".arg(id_switch_box.isActive ? "<font size=\"2\" color=\"#40c9ff\">( <b>X64-bit</b> Application )</font>" :
																			 "<font size=\"2\" color=\"#ff7777\">( <b>X32-bit</b> Application )</font>")
			font.pointSize: 9
		}
	}

	//===================================================================

	Button {
		anchors {
			right: parent.right
			rightMargin: 25
			bottom: parent.bottom
			bottomMargin: 25
		}
		width: 150
		text: "Deploy"

		onClicked: x_function.test()
	}

	Label {
		objectName: "obj_lbl_status"
		text: "<font color=\"#59ff00\"><b>Ready.</b></font>"
		anchors.left: parent.left
		anchors.bottom: parent.bottom
		anchors.leftMargin: 50
		anchors.bottomMargin: 50
	}

	Label {
		objectName: "obj_lbl_second"
		text: ""
		anchors.left: parent.left
		anchors.bottom: parent.bottom
		anchors.bottomMargin: 30
		anchors.leftMargin: 50
	}

}
