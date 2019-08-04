#arduino constantly publishes some values
#arduino sends:
#^left:2,right:4,middle:5$
#the program interprets:
#leftVal=2
#rightVal=4
#middleVal=5

import re
from serial import Serial

ser = Serial('/dev/ttyACM0')
ser.flushInput()

values = {}

while True:
    try:
        ser_bytes = ser.readline().decode()
        m = re.search('\^(.+?)\$', ser_bytes)
        if m:
            results = m.group(1).split(',')
            for result in results:
                keyvalue = result.split(':')
                values[keyvalue[0]] = int(keyvalue[1])
            print(values)
    except:
        print("Keyboard Interrupt")
        break

# for testing from arduino:
#
#void setup() {
#  Serial.begin(9600);
#}
#
#void loop() {
#  Serial.println("^left:2,right:4,middle:5$");
#  delay(200);
#}
