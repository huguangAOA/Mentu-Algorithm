#!/usr/bin/env python
# coding=utf-8

import wave
import numpy as np

frameRate = 16100
time = 10
volumn = 40 # 255
pi = np.pi
t = np.arange(0, time, 1.0 / frameRate)

def gen_wave_data(fileName, realF):
    wave_data =  volumn * np.sin(2.0 * pi * realF * t)
    wave_data = wave_data.astype(np.int8)
    f = wave.open(fileName, "wb")

    f.setnchannels(1)
    f.setsampwidth(1)
    f.setframerate(frameRate)
    f.writeframes(wave_data.tostring())
    f.close()
    print("write data to : " + fileName)

gen_wave_data(r"1Hz.wav", 1)
gen_wave_data(r"2Hz.wav", 2)
gen_wave_data(r"3Hz.wav", 3)
gen_wave_data(r"4Hz.wav", 4)
gen_wave_data(r"5Hz.wav", 5)
