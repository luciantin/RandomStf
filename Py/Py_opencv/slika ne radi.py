import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('test.png',1)

##
##
##frame2gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
##
##hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

cv2.imshow('oi',img)     
        
cv2.waitKey(0)
cv2.destroyAllWindows()




