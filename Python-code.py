
import snap7
import time
import serial
Arduino = serial.Serial(port='COM11', baudrate=9600, timeout=0.019)

plc = snap7.client.Client()
plc.connect('192.168.1.69', 0, 1)  # IP address, rack, slot (from HW settings)

Q1Done = False
Q2Done = False
Q3Done = False
Q4Done = False

db_number = 2
start_offset_in = 0
start_offset_out = 1

def writeBool(bit_offset, value):
	reading = plc.db_read(db_number, start_offset_in, 1)    # (db number, start offset, read 1 byte)
	snap7.util.set_bool(reading, 0, bit_offset, value)   # (value 1= true;0=false) (bytearray_: bytearray, byte_index: int, bool_index: int, value: bool)
	plc.db_write(db_number, start_offset_in, reading)       #  write back the bytearray and now the boolean value is changed in the PLC.
	return None

def readBool(bit_offset):
	reading = plc.db_read(db_number, start_offset_out, 1)
	a = snap7.util.get_bool(reading, 0, bit_offset)
	return a

def ArduinoWrite(x):
	Arduino.write(bytes(x, 'utf-8'))
	print(x)
	return None







while True:

	read = Arduino.read(4)


#INPUT 1:
	if(read==b'I1=1'):
		writeBool(0,1)
	if(read==b'I1=0'):
		writeBool(0,0)

#INPUT 2:
	if(read==b'I2=1'):
		writeBool(1,1)
	if(read==b'I2=0'):
		writeBool(1,0)

#INPUT 3:
	if(read==b'I3=1'):
		writeBool(2,1)
	if(read==b'I3=0'):
		writeBool(2,0)

#INPUT 4:
	if(read==b'I4=1'):
		writeBool(3,1)
	if(read==b'I4=0'):
		writeBool(3,0)

#INPUT 5:
	if(read==b'I5=1'):
		writeBool(4,1)
	if(read==b'I5=0'):
		writeBool(4,0)

#INPUT 6:
	if(read==b'I6=1'):
		writeBool(5,1)
	if(read==b'I6=0'):
		writeBool(5,0)

#INPUT 7:
	if(read==b'I7=1'):
		writeBool(6,1)
	if(read==b'I7=0'):
		writeBool(6,0)

#INPUT 8:
	if(read==b'I8=1'):
		writeBool(7,1)
	if(read==b'I8=0'):
		writeBool(7,0)

#OUTPUT 1:
	Q1=readBool(0)
	if(Q1==True and Q1Done==False):
		ArduinoWrite("1") #Q1=1
		Q1Done=True

	if(Q1==False and Q1Done==True):
		ArduinoWrite("2") #Q1=0
		Q1Done = False
#OUTPUT 2:
	Q2=readBool(1)
	if(Q2==True and Q2Done==False):
		ArduinoWrite("3") #Q2=1
		Q2Done=True

	if(Q2==False and Q2Done==True):
		ArduinoWrite("4") #Q2=0
		Q2Done=False
#OUTPUT 3:
	Q3=readBool(2)
	if(Q3==True and Q3Done==False):
		ArduinoWrite("5") #Q3=1
		Q3Done=True
		time.sleep(0.05)

	if(Q3==False and Q3Done==True):
		ArduinoWrite("6") #Q3=0
		Q3Done = False
		time.sleep(0.05)


#OUTPUT 4:
	Q4=readBool(3)
	if(Q4==True and Q4Done==False):
		ArduinoWrite("7") #Q4=1
		Q4Done = True



	if(Q4==False and Q4Done==True):
		ArduinoWrite("8") #Q4=0
		Q4Done= False

	time.sleep(0.1)















