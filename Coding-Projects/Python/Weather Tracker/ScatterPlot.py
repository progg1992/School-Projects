# -*- coding: utf-8 -*-
"""
Created on Sun Feb 21 01:58:46 2021

@author: progg
"""

#Name: Pierce Rogg
#Date: 2/21/2021
import pandas as pd
import matplotlib.pyplot as plt
df1 = pd.read_csv("formatdata.csv")
df2 = pd.read_csv("formatdata2.csv")
plt.scatter(df1.index.values,df1['Fahrenheit']); plt.suptitle('Fahrenheit')
plt.show()
