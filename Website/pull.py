# Libraries included
import base64
from devicecloud import DeviceCloud
import mysql.connector
from mysql.connector import Error

#Initiate connection with Digi Remote Manager
dc = DeviceCloud('olivia.derosier@gmail.com', 'CAPSTONE!')

#Creates connection to MySQL database
def create_connection(host_name, user_name, user_password, db_name):
    connection = None
    try:
        connection = mysql.connector.connect(
            host=host_name,
            user=user_name,
            passwd=user_password,
            database=db_name
        )
        print("System Initilization successful")
    except Error as e:
        print("The error '{e}' occurred")
    return connection

#Decoding of data stream from base64 to ascii
def decode_data(stream):
    streamVal = stream.get_current_value()
    base64_data = streamVal.get_data()
    base64_bytes = base64_data.encode('ascii')
    message_bytes = base64.b64decode(base64_bytes)
    message = message_bytes.decode('ascii')
    return message

#MAIN PROGRAM 
# Establishes connection with SQL database
connection = create_connection("localhost", "root", "", "capstone")

while True:
    #Checks for incoming data from Digi Remote Manager via gateway
    datastream = dc.streams.get_stream_if_exists('00000000-00000000-00409DFF-FF63DD73/xbee.serialIn/[00:13:A2:00:41:68:0B:B9]!')

    #Expected datastream "~123045+126715" or "fjEyMzA0NSsxMjY3MTU=" in base64

    #If gateway has new data, run program
    if (datastream != None):

        data = decode_data(datastream)
        
        l = list(data)

        if l[2] == '1':
            l[2] = '-'
        if l[2] == '0':
            l[2] = '0'

        #Parse returned string recieved meaningful values
        start_delimeter = l[0] 
        node_number = l[1] 
        temp = l[2] + l[3] + l[4]
        salt = l[5] + l[6]
        moisture = l[7] + l[8]
        battery = l[9] + l[10]
        water_used = l[11] + l[12]

        #Send  data to designated SQL table
        if node_number == '1':
            sql = "INSERT INTO data (node_number, moisture, salt, temp, battery, waterUsed) VALUES (%s, %s,%s, %s,%s, %s)"
            val = (node_number, moisture, salt, temp, battery, water_used)
            cursor = connection.cursor()
            cursor.execute(sql, val)
            connection.commit()
   
        if node_number == '2':
            sql = "INSERT INTO data2 (node_number, moisture, salt, temp, battery, waterUsed) VALUES (%s, %s,%s, %s,%s, %s)"
            val = (node_number, moisture, salt, temp, battery, water_used)
            cursor = connection.cursor()
            cursor.execute(sql, val)
            connection.commit()
                
        #Prints values to python console for testing purposes
        print(data)
        print(start_delimeter)
        print(node_number)
        print(moisture)
        print(salt)
        print(temp)
        print(battery)
        print(water_used)
        
        #Deletes current data stream
        datastream.delete()

    else:
        pass

