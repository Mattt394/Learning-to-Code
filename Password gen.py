# Password Generator

# random mix of lowercase, uppercase, numbers, and symbols

import random
import math

print("How long would you like your password?")

num = input("Between 6 and 12 only pls: ")

def is_number(s):
    try:
        int(s)
        if s>5 and s<13:
            return True
        else:
            return False
    except ValueError:
        return False

while not is_number(num):
    num = input("A number between 6 and 12 only pls: ")

x = [chr(int(math.floor(random.random()*(127-33)+33))) for i in range(0, num)]


print(''.join(x))

