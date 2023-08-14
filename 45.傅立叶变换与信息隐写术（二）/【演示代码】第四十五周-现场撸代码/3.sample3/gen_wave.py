#!/usr/bin/env python
# coding=utf-8

import wave
import numpy as np

def convert(x):
    if len(x.strip("\n")) == 0:
        return 0.0
    return float(x)

frameRate = 16000
f = open("output.data", "r")
data = [convert(x) for x in f.read().split("\n")]
data = data[:-1]
f.close()
data = np.array(data, dtype = np.short)

fileName = r"filter.wav"
f = wave.open(fileName, "wb")

f.setnchannels(1)
f.setsampwidth(2)
f.setframerate(frameRate)
f.writeframes(data.tostring())
f.close()
print("write data to : " + fileName)
