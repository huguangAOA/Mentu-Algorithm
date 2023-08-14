#!/usr/bin/env python
# coding=utf-8

import wave
import numpy as np

frameRate = 16100
time = 10
realF = [50, 100, 2000]
volumn = [14, 9, 14] # 255
pi = np.pi
t = np.arange(0, time, 1.0 / frameRate)

wave_data = \
    volumn[0] * np.sin(2.0 * pi * realF[0] * t) + \
    volumn[1] * np.sin(2.0 * pi * realF[1] * t) + \
    volumn[2] * np.sin(2.0 * pi * realF[2] * t)

wave_data = wave_data.astype(np.int8)
fileName = r"decode.wav"
f = wave.open(fileName, "wb")

f.setnchannels(1)
f.setsampwidth(1)
f.setframerate(frameRate)
f.writeframes(wave_data.tostring())
f.close()
print("write data to : " + fileName)
