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



  
    cv2.imshow('frame',frame)     


    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
 

        
cap.release()
cv2.destroyAllWindows()

