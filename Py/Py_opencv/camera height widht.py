import cv2
import numpy as np
import matplotlib.pyplot as plt

cap = cv2.VideoCapture(0)



img = cv2.imread('test.png',cv2.IMREAD_GRAYSCALE)

while True:
    
    ret, frame = cap.read()
    ret = cap.set(cv2.CAP_PROP_FRAME_WIDTH,200)
    ret = cap.set(cv2.CAP_PROP_FRAME_HEIGHT,200)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    cv2.imshow('frame',frame)
    cv2.imshow('gray',gray)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
 

        
cap.release()
cv2.destroyAllWindows()
