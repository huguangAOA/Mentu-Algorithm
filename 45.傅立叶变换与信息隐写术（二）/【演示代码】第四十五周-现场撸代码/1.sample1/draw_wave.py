#!/usr/bin/env python
# coding=utf-8

import wave
import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as pl
import numpy as np

def draw_wave_data(fileName, plotNum):
    f = wave.open(fileName, "rb")
    params = f.getparams()

    str_data = f.readframes(params[3])
    f.close()
    print("read from " + fileName + " success done!")

    wave_data = np.fromstring(str_data, dtype = np.int8)
    t = np.arange(0, len(wave_data)) * 1.0 / params[2]
    pl.subplot(plotNum)
    pl.title(fileName)
    pl.plot(t, wave_data)
    pl.xlabel("time (seconds)")

draw_wave_data("1Hz.wav", 321)
draw_wave_data("2Hz.wav", 322)
draw_wave_data("3Hz.wav", 323)
draw_wave_data("4Hz.wav", 324)
draw_wave_data("5Hz.wav", 325)
pl.show()
