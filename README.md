# prime-optimized
TLDR: An 'optimized' way to store prime numbers using bit masking

# What is and how it came up to be
This project aims to optimize the way prime numbers are stored, the way I made it is using bitmasking.<br>
The way it works is similar to storing prime numbers in an array of booleans, where the index is the number and the value at that is index indicates if that number is prime or not which I find interesting but starts to consume more memory the moment it hits the number 100 and storing just an array of int32 is more efficient.<br>
This problem came in my mind while studying bitmasking and it's uses and thought "What if instead of booleans it's stored in bits? since booleans are the size of 1 byte it is more efficent" and so it began the project.<br>
While implementing I also figured out that this can be further compressed by storing only odd numbers, except of 2 all prime numbers are odd, and starting from 3, which resulted compressing 16 numbers in 1 byte, hardest part was trying to index and get if a number is prime or not.

# Technical details
First off let's start with data type sizes in bytes: Int32(4 bytes), Int64(8 bytes), Bool(1 byte)<br>
Normally, to store prime numbers as an Int is creating an array and storing prime numbers, storing 4/8 bytes per number, which increases logarithmically.<br>
Storing prime numbers using Bools is having an array of booleans and storing if its prime or not and using the index as the number, increasing space linearily.<br>
My method stores in bits using bitmasking only odd numbers, which saves 16 times compared to storing Bools, which also scales linearily.<br>
Example: "10110111" this byte contains numbers from 3 to 17 going from right to left

As a limitation, since it scales linearly, it will eventually also encounter the same problem as just storing Bool since it grows much more slowly and even for Int64 it's more efficient just storing the Ints themselves rather than using this method, but potentially for much larger data types, if stored as strings, it will be much more efficient

You can use the plot.py script and get_data.exe, and have enough patience to compile the data yourself, to see how it scales

# How to Build
For building prime directory, use cmake<br>
For plot.py use either script to build an env and get matplot lib

# What can be done better?

This can be further improved if either Riemann Hypothesis or Twin Prime Conjecture are proven to be true, or even ignored entirely and making an O(1) operation to check if a number is prime or not and completely avoiding storing since it will be useless to store prime numbers in either manner listed here, or can be improved by methods i haven't discovered yet.<br>
And codewise improvement maybe using a static class instead of functions in a namespace.
