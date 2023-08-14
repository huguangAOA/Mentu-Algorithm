#!/usr/bin/env python
# coding=utf-8

import wave
import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as pl
import numpy as np

def convert_wave_data(fileName, outputFile):
    f = wave.open(fileName, "rb")
    params = f.getparams()

    str_data = f.readframes(params[3])
    f.close()
    print("read from " + fileName + " success done!")

    wave_data = np.fromstring(str_data, dtype = np.short)
    fout = open(outputFile, "w")
    fout.write(str(len(wave_data)) + "\n")
    for x in wave_data:
        fout.write(str(x) + "\n")
    fout.close()
    print("write wave data to " + outputFile)

convert_wave_data("1.wav", "input.data")
