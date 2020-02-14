import cv2
import numpy as np
import matplotlib.pyplot as plt

cap = cv2.VideoCapture(0)
img2 = cv2.imread('test2.jpg',cv2.IMREAD_GRAYSCALE)
img = cv2.imread('test2.jpg',cv2.IMREAD_COLOR)

#img = cv2.resize(img,(640,480))
while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)



    lower = np.array([0,130,199])
    upper = np.array([9,255,255])
    mask = cv2.inRange(hsv,lower,upper)
    res = cv2.bitwise_and(frame,frame,mask=mask)    

    #kernel = np.ones((15,15), np.float32)/225
    #smoothed = cv2.filter2D(res,-1,kernel)

    #blur = cv2.GaussianBlur(res,(15,15),0)
    
    

    #bilateral = cv2.bilateralFilter(res,15,75,75)
    #median = cv2.medianBlur(bilateral,15)
    
 #   cv2.imshow('bi2med',median)
##    cv2.imshow('mask',mask)
##    cv2.imshow('hsv',hsv)
##    cv2.imshow('res',res)
##    cv2.imshow('smoothed',smoothed)
##    cv2.imshow('blur',blur)
##    cv2.imshow('median',median)
##    cv2.imshow('bilateral',bilateral)
    
    res2gray = cv2.cvtColor(cv2.medianBlur(res,15),cv2.COLOR_BGR2GRAY)
    
    ret, thresh = cv2.threshold(res2gray, 0, 255, 0)
    
    im2, contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)


    frame = cv2.drawContours(frame, contours, -1, (0,255,0), 3)
    #cv2.imshow('im2',im2)     
    cv2.imshow('frame',frame)     


    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
 

        
cap.release()
cv2.destroyAllWindows()

