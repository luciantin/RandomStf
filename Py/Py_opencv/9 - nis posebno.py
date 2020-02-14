import cv2
import numpy as np
import matplotlib.pyplot as plt

cap = cv2.VideoCapture(0)
img1 = cv2.imread('test2.jpg',cv2.IMREAD_COLOR)
img2 = cv2.imread('test.png',cv2.IMREAD_COLOR)

img1 = cv2.resize(img1,(1000,1000))
while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    
    rows,cols,channels = img2.shape
    roi = img1[0:rows, 0:cols ]

     
    img2gray = cv2.cvtColor(img2,cv2.COLOR_BGR2GRAY)
    ret2, mask = cv2.threshold(img2gray,100,255,cv2.THRESH_BINARY)
    mask_inv = cv2.bitwise_not(mask)

    plcHldr = mask_inv
    mask_inv=mask
    mask= plcHldr

    img1_bg = cv2.bitwise_and(roi,roi,mask = mask_inv)
    img2_fg = cv2.bitwise_and(img2,img2,mask = mask)
    
    
    dst = cv2.add(img2_fg,img1_bg)
    img1[0:rows, 0:cols ] = dst
    cv2.imshow('res',img1)
     
    
##    cv2.imshow('img2_fg',img2_fg)   
    cv2.imshow('mask',mask)
##    cv2.imshow('img2gray',img2gray)
    cv2.imshow('mask_inv',mask_inv)
##    cv2.imshow('img1_bg',img1_bg)
    cv2.imshow('img2_fg',img2_fg)
    
   
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
 

        
cap.release()
cv2.destroyAllWindows()



