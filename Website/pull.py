# Libraries included
import base64
from devicecloud import DeviceCloud
import mysql.connector
from mysql.connector import Error

# Initiate connection with Device Cloud
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

# Decodes incoming data from Base64 to ascii
def decode_data(stream):
    streamVal = stream.get_current_value()
    base64_data = streamVal.get_data()
    #print(base64_data)
    base64_bytes = base64_data.encode('ascii')
    message_bytes = base64.b64decode(base64_bytes)
    message = message_bytes.decode('ascii')
    return message

#################MAIN PROGRAMMING SEQUENCE##################
# Initiate connection with SQL database
connection = create_connection("localhost", "root", "", "capstone")

while True:
    # Defines incoming data from Digi Remote Manager via gateway
    datastream = dc.streams.get_stream_if_exists('00000000-00000000-00409DFF-FF63DD73/xbee.serialIn/[00:13:A2:00:41:68:0B:D5]!')

    #datastream = "0 1 23 45 12 67 15 1"
    # If gateway has new data, run program
    if (datastream != None):
        data = decode_data(datastream)
        
        l = list(data)
    
        # Parse returned string into individual values
        start_delimeter = l[0] 
        node_number = l[1] 
        moisture = l[2] + l[3]
        salt = l[4] + l[5]
        temp = l[6] + l[7]
        battery = l[8] + l[9]
        water_used = l[10] + l[11]
        rain = l[12] 

        #Send  data to designated SQL database
        if node_number == '1':
            sql = "INSERT INTO data (node_number, moisture, salt, temp, battery, rain, waterUsed) VALUES (%s, %s,%s, %s,%s, %s, %s)"
            val = (node_number, moisture, salt, temp, battery, rain, water_used)
            cursor = connection.cursor()
            cursor.execute(sql, val)
            connection.commit()
   
        if node_number == '2':
            sql = "INSERT INTO data2 (node_number, moisture, salt, temp, battery, rain, waterUsed) VALUES (%s, %s,%s, %s,%s, %s, %s)"
            val = (node_number, moisture, salt, temp, battery, rain, water_used)
            cursor = connection.cursor()
            cursor.execute(sql, val)
            connection.commit()
                
        # Prints values to python console
        print(data)
        print(start_delimeter)
        print(node_number)
        print(moisture)
        print(salt)
        print(temp)
        print(battery)
        print(water_used)
        print(rain)
        
        # Deletes data so program can wait for next packet of data
        datastream.delete()

    else:
        pass

