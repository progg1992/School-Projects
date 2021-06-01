# -*- coding: utf-8 -*-
"""
Created on Sun Feb 21 02:10:21 2021

@author: progg
"""

#Purpose: Create Celsius plot comparing period 1 and period 2
#Name: Your name
#Date: Your date
import pandas as pd
import matplotlib.pyplot as plt
df1 = pd.read_csv("formatdata.csv") #baseline data is period 1 (older)
df2 = pd.read_csv("formatdata2.csv") #data for period 2 (more recent)
plt.figure(); df1.Celsius.plot(label = 'week 1 '); df2.Celsius.plot(label = 'week 2'); plt.legend(loc='best'); plt.suptitle('Celsius')
plt.show()
