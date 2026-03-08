# x = prime count, y = byte count

import os
import matplotlib.pyplot as plt
import numpy as np

# READ DATA
if "data.txt" not in os.listdir():
    print("data.txt not found. Please ensure the data file is in the same directory as this script.")
    exit(1)
    
data = np.loadtxt("data.txt")

numbers = data[:,0]
primeCount = data[:,1]

byteCountInt32 = 4 * primeCount # 4 bytes per int32
byteCountInt64 = 8 * primeCount # 8 bytes per int64
byteCountBool = numbers         # 1 byte per boolean
byteCountBit = numbers / 16     # 8 bits per byte, storing odd numbers in bits, resulting 16 numbers per byte

# PLOT DATA
plt.title("Storage Methods Byte Count")
plt.plot(numbers, byteCountInt32, scalex=True, scaley=True, marker='s', linestyle='--', color='red', label='Int32 Count (B)')
plt.plot(numbers, byteCountInt64, scalex=True, scaley=True, marker='^', linestyle='-.', color='green', label='Int64 Count (B)')
plt.plot(numbers, byteCountBool, scalex=True, scaley=True, marker='d', linestyle=':', color='orange', label='Bool Count (B)')
plt.plot(numbers, byteCountBit, scalex=True, scaley=True, marker='p', linestyle='-', color='purple', label='Bit Count (B)')
plt.xlabel("Number Count")
plt.ylabel("Byte Count (B)")
plt.show()