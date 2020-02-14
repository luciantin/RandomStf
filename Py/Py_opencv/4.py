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

    kernel = np.ones((15,15), np.float32)/225
    smoothed = cv2.filter2D(res,-1,kernel)

    blur = cv2.GaussianBlur(res,(15,15),0)
    
    median = cv2.medianBlur(res,15)

    bilateral = cv2.bilateralFilter(res,15,75,75)
    cv2.imshow('img',img)
    cv2.imshow('frame',frame)
    cv2.imshow('mask',mask)
    cv2.imshow('hsv',hsv)
    cv2.imshow('res',res)
    cv2.imshow('smoothed',smoothed)
    cv2.imshow('blur',blur)
    cv2.imshow('median',median)
    cv2.imshow('bilateral',bilateral)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
 

        
cap.release()
cv2.destroyAllWindows()



