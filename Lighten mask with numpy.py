#Practicing creating filters
#Aim to create a filter that lightens an image
#Practice img I used: 'C:\\Users\\Matt\\Pictures\\Saved Pictures\\croc.jpg'

import numpy as np
import scipy
import matplotlib.pyplot as plt
from skimage import data
import time

address = input('Please type the location of your image (with quotes, depending on your console), escape \ with \\\: ')

# Checking to see if file is valid
def test_img(adr):
    try:
        data.imread(adr)
        return True
    except:
        return False

while not test_img(address):
    address = input('Img not found, please try again: ')

print('Thanks, working on it...')
#Getting image
img = data.imread(address)

#All pixels that are less than 100 set to true
light_r = img[:,:,0] <100
light_g = img[:,:,1] <100
light_b = img[:,:,2] <100
light = np.logical_and(light_r,light_g,light_b)

img = data.imread(address)
#increase those pixels by 50
img[light,0] += 50
img[light,1] += 50
img[light,2] += 50

print('Will show preview shortly')

#Displays image, but at end of program
plt.figure(figsize=(5,5))
plt.imshow(img)


yes_no = input('Would you like to save your file, y/n: ')

yes_no = str(yes_no)

#determines if user wants to save file
def save(y_n):
    #NOTE: This assumes the user is trusted
    if (y_n in ('yes','y')):
        name = input('File name please: ')
        plt.imsave(name + '.png', img)
        print("File saved")
        return
    elif (y_n in ("no", "n")):
        print("okay then")
        return
    else:
        print("I said answer y/n, so I guess that means no")
        time.sleep(0.5)
        print("If you want to save it though, just right click")
        
save(yes_no)
