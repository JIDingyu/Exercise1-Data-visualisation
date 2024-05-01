
import serial
import time
import numpy as np
import matplotlib.pyplot as m

ser = serial.Serial('/dev/cu.usbmodem1101', 9600)

#try:
    #while True:
arr=np.zeros(10)
for i in range (10):
    ser.write(b"1");
    time.sleep(2.5)


    if ser.in_waiting > 0:
        incoming_data = ser.read(4)
        str_num = incoming_data
        num = int(str_num)
        print(num)
        #print(incoming_data)
        arr[i]=num
        #print(arr[i])
y=arr
x=[2.5,5,7.5,10,12.5,15,17.5,20,22.5,25]
m.plot(x,y,label="Rainfall Changes",linewidth=3,color="blue",marker="*",markerfacecolor="violet",markersize="14")
m.title("Rainfall in 25 seconds")
m.xlabel("Time/s")
m.ylabel("Values of the raindrop sensor/v")
m.legend()
m.show()




# finally:
ser.close()