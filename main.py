import serial
import time
import pyautogui

port = open("port.txt", "r").read()

arduino = serial.Serial(port=port, bytesize=8, timeout=0.1)


while True:
    data = arduino.readline().decode("utf-8")

    if "copy" in data:
        pyautogui.keyDown("ctrl")
        pyautogui.keyDown("c")
        pyautogui.keyUp("ctrl")
        pyautogui.keyUp("c")
    elif "paste" in data:
        pyautogui.keyDown("ctrl")
        pyautogui.keyDown("v")
        pyautogui.keyUp("ctrl")
        pyautogui.keyUp("v")
    else:
        if data:
            print(data)