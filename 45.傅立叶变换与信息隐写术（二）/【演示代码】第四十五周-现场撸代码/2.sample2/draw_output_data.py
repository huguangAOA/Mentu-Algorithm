#!/usr/bin/env python
# coding=utf-8

import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as pl
import numpy as np

def convert(x):
    if len(x.split(" ")) != 3:
        return [0.0, 0.0, 0.0]
    return [float(y) for y in x.strip().split(" ")]

f = open("output.data", "r")
data = [convert(x) for x in f.read().split("\n")]

data = data[:-1]
data = np.array(data)
data = data.T

x = np.arange(0, len(data[0]))
pl.subplot(221)
pl.plot(x, data[0])
pl.title("Real part")
pl.subplot(222)
pl.plot(x, data[1])
pl.title("Imag part")
pl.subplot(223)
pl.plot(x, data[2])
pl.title("Mag")
pl.show()
