'''
Descripttion: 
version: 1.0.0
Author: CYKS
Date: 2020-10-06 23:08:16
LastEditors: CYKS
LastEditTime: 2020-10-11 21:50:48
'''
import matplotlib
import matplotlib.pyplot as plt

f = open("output.out")
x = list()
y = list()

fig, ax = plt.subplots()

for line in f:
	n, result = map(int, line.split())
	x.append(n)
	y.append(result)

f.close()

ax.plot(x, y)

ax.set(xlabel='n', ylabel='x',
       title='y = 5')
ax.grid()

fig.savefig("test.png")
plt.show()