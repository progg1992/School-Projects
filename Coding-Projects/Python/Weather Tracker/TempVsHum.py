# -*- coding: utf-8 -*-
"""
Created on Sun Feb 21 02:10:21 2021

@author: progg
"""

#Purpose: Create Celsius plot comparing period 1 and period 2
#Name: Pierce Rogg
#Date: 20/22021
import pandas as pd
import matplotlib.pyplot as plt
df1 = pd.read_csv("formatdata.csv") 
df2 = pd.read_csv("formatdata.csv") #
plt.figure(); df1.Fahrenheit.plot(label = 'fahrenheit '); df2.Humidity.plot(label = 'humidity '); plt.legend(loc='best'); plt.suptitle('Temperature vs Humidity')
plt.show()
