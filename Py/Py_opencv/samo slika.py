import cv2
import numpy as np
import matplotlib.pyplot as plt
import time
frame = cv2.imread('test3.png')

##frame = cv2.cvtColor(frame,cv2.COLOR_RGB2BGR)

frame2gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)

hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

lower = np.array([0,90,136])
upper = np.array([179,216,238])
mask = cv2.inRange(hsv, lower, upper)
res = cv2.bitwise_and(frame,frame, mask= mask)

####
####cv2.imshow('frame',frame)
####cv2.imshow('mask',mask)
####cv2.imshow('res',res)

kernel = np.ones((5,5),np.uint8)
    
    
res2gray = cv2.cvtColor(res,cv2.COLOR_BGR2GRAY)
    
ret, thresh = cv2.threshold(res2gray, 0, 255, 0)
    
im2, contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

cnt = contours[len(contours)-1]
area = cv2.contourArea(cnt)
perimeter = cv2.arcLength(cnt,True)

print(perimeter)


rect = cv2.minAreaRect(cnt)
box = cv2.boxPoints(rect)
box = np.int0(box)
cv2.drawContours(frame,[box],0,(0,0,255),2)



frame = cv2.drawContours(frame, contours, -1, (0,255,0), 0)
cv2.imshow('im2',im2)     
cv2.imshow('frame',frame)     

 
        
cv2.waitKey(0)
cv2.destroyAllWindows()



