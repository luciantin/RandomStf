import cv2
import numpy as np
import matplotlib.pyplot as plt

cap = cv2.VideoCapture('video2.mp4')


while True:
    ret, frame = cap.read()
    
    frameLowRes = cv2.resize(frame,(640,480))
    

    
    cv2.imshow('frame',cv2.resize(frame,(640,480)))     
   
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
 

        
cap.release()
cv2.destroyAllWindows()



