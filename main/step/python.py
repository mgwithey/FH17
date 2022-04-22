# Importing Libraries
import serial
import time
from tkinter import *
import tkinter as tk

try:
    arduino = serial.Serial(port='COM6', baudrate=9600)
    time.sleep(2)
except:
    pass

def Start_Arduino():
    print("start")
    arduino.write(b's')

def move():
    arduino.write(b'm')
    time.sleep(1)
    x_loc = entryCords_X.get()
    y_loc = entryCords_Y.get()
    data = x_loc + '-' + y_loc 
    print('moving to ' + data)
    arduino.write(data.encode())

def reset():
    print("reset")
    arduino.write(b'r')

def pause():
    print("pause")
    arduino.write(b'p')

def verifyInput(input):
    try:
        val = int(input)
        if 0<=val<=100:
            pass
        else:
            print('Error -- input must be an integer from 0 to 100')
    except:
        print('Error -- input must be an integer from 0 to 100')



#### GUI SETUP ####
root = Tk()
root.title('Positioner GUI')

#### Start Button ####
btn_Start = tk.Button(root, text='Start', command=Start_Arduino, width=10)
btn_Start.grid(row=0,column=0)

#### Stop Button ####
btn_Pause = tk.Button(root, text='Pause', width=10, command=pause)
btn_Pause.grid(row=0,column=1)

#### Move to location ####
btn_Mov = tk.Button(root, text='Move', width=10, command=move)
btn_Mov.grid(row=3, column=0)

#### Reset button ####
btn_Res = tk.Button(root, text='Reset', width=10, command=reset)
btn_Res.grid(row=4, column=0)

#### X cords entry box ####
entryCords_X = Entry(root, width=6)
entryCords_X.insert(0,'0')
entryCords_X.grid(row=2,column=0)

#### Y cords entry box ####
entryCords_Y = Entry(root, width=6)
entryCords_Y.insert(0,'0')
entryCords_Y.grid(row=2,column=1)

root.geometry('300x150') 
root.mainloop()