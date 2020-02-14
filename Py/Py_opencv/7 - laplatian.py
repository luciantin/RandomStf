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



    lower = np.array([100,102,102])
    upper = np.array([255,255,255])
    mask = cv2.inRange(hsv,lower,upper)
    res = cv2.bitwise_and(frame,frame,mask=mask)    

    laplacian = cv2.Laplacian(frame,cv2.CV_64F)


    sobelx=cv2.Sobel(frame,cv2.CV_64F,1,0,ksize=5)
    sobely=cv2.Sobel(frame,cv2.CV_64F,0,1,ksize=5)

    
    edges= cv2.Canny(frame,100,100)
     
    
    cv2.imshow('frame',cv2.GaussianBlur(frame,(15,15),0))   
    cv2.imshow('laplacian',laplacian)
    cv2.imshow('sobelx',sobelx)   
    cv2.imshow('sobely',sobely)
    cv2.imshow('edges',edges)
    
   
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
 

        
cap.release()
cv2.destroyAllWindows()



