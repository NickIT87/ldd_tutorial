# my_wrapper.py

import ctypes

# Load the shared library
my_lib = ctypes.CDLL('./mylib.so')  # Use '.dll' on Windows

# Define the argument and return types of the function
my_lib.add.argtypes = [ctypes.c_int, ctypes.c_int]
my_lib.add.restype = ctypes.c_int

# Define a Python function that calls the C function
def add(a, b):
    return my_lib.add(a, b)
