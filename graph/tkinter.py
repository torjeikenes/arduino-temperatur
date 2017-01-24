from Tkinter import *
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)


oldtemp = 0 
def counter_label(label):
  def count():
    global oldtemp
    temp = ser.readline().strip()
    label.config(text = temp + " C"+ u"\N{DEGREE SIGN}" )
    oldtemp = temp 
    label.after(1000, count)
  count()
 
 
root = Tk()
downArrow = PhotoImage(file="downArrow.png")
root.title("Temperatur")
label = Label(root, fg="green", font=("Helvetica", 42))
label.pack()
counter_label(label)
button = Button(root, text='Stop', width=25, command=root.destroy)
button.pack()
root.mainloop()
