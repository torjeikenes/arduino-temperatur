# Importerer tkinter og pySerial
from Tkinter import *
import serial

# Setter ser til aa lese seriedata fra /dev/ttyACM0 
# og overforingshastighet 9600
ser = serial.Serial('/dev/ttyACM0', 9600)

# Lager en label med temperaturen, gradetegn og "C"
def counter_label(label):
  def count():
    temp = ser.readline().strip()
    label.config(text = temp + " " + u"\N{DEGREE SIGN}" + "C"  )
    label.after(1000, count)
  count()
 
# Gjor klar vinduet
root = Tk()
root.title("Temperatur") # Setter tittel pa vinduet
label = Label(root, fg="green", font=("Helvetica", 42)) # Setter farge, font og
                                                        # storelse pa teksten 
label.pack()
counter_label(label) # Setter inn teksten ovenifra
# Legger til en knapp som lukker programmet
button = Button(root, text='Stop', width=25, command=root.destroy) 
button.pack()
# Apner vinduet
root.mainloop()
