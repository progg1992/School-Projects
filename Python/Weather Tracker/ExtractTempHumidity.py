#Purpose: Extract temperature, humidity data from weather database into CSV file
#Name: Pierce Rogg
#Date: 02/12/2021
#   Run BuildWeatherDB.py to build weather database before running this program

import sqlite3

#convert Celsius temperature to Fahrenheit
def convertCtoF(tempC):
    return (tempC*9.0/5.0) + 32.0

#file names for database and output file
dbFile = "weather.db"
output_file_name='formatdata.csv'

#connect to and query weather database and 
dbFile = "weather.db"
conn = sqlite3.connect(dbFile)
#create cursor to execute SQL commands
cur = conn.cursor()
selectCmd = """ SELECT temperature, relativeHumidity FROM observations
                ORDER BY timestamp; """
cur.execute(selectCmd)
allRows = cur.fetchall()
#limit the number of rows output to half
rowCount = len(allRows)//2 # double slash does integer division
rows = allRows[:rowCount]

#write data to output file
with open(output_file_name,"w+") as outf:
    outf.write('Celsius,Fahrenheit,Humidity')
    outf.write('\n')
    for row in rows:
        tempC = row[0]
        if tempC is None:       #handle missing temperature value
            outf.write(',,')
        else:            
            tempF = convertCtoF(tempC)
            outf.write(str(tempC)+',')
            outf.write(str(tempF)+',')
        humidity = row[1]
        if humidity is None:   #handle missing humidity value
            outf.write('\n')
        else:
            outf.write(str(humidity)+'\n') #print data to file separated by commas


