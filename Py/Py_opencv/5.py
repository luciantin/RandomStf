import cv2
import numpy as np
import matplotlib.pyplot as plt

cap = cv2.VideoCapture(0)
img2 = cv2.imread('test2.jpg',cv2.IMREAD_GRAYSCALE)
img = cv2.imread('test2.jpg',cv2.IMREAD_COLOR)

img = cv2.resize(img,(640,480))
while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)



    lower = np.array([115,50,50])
    upper = np.array([140,255,255])
    mask = cv2.inRange(hsv,lower,upper)
    res = cv2.bitwise_and(frame,frame,mask=mask)    


    kernel = np.ones((5,5),np.uint8)
    erosion = cv2.erode(mask,kernel, iterations=1)    
    dilation = cv2.dilate(mask,kernel, iterations=1)

    opening = cv2.morphologyEx(mask , cv2.MORPH_OPEN,kernel)
    closing = cv2.morphologyEx(mask , cv2.MORPH_CLOSE,kernel)
    
    cv2.imshow('frame',frame)   
    cv2.imshow('res',res)
    cv2.imshow('erosion',erosion)
    cv2.imshow('dilation',dilation)
    cv2.imshow('opening',opening)
    cv2.imshow('closing',closing)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
 

        
cap.release()
cv2.destroyAllWindows()



