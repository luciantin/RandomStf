import cv2
import numpy as np
import matplotlib.pyplot as plt
import math

cap = cv2.VideoCapture('video5.mp4')
otvorS="100%"

def IzracunajSredinu (tockaAx,tockaBx):
    return (tockaAx+tockaBx)/2
    
def IzracunajDuljinu (tockaAx,tockaAy,tockaBx,tockaBy):
    prvi = math.pow((tockaAx-tockaBx),2)
    drugi = math.pow((tockaAy-tockaBy),2)
    return math.sqrt(prvi+drugi)
   


 
while True:
    ret, frame = cap.read()
    
    frame = cv2.resize(frame,(700,480))
    frame_crop = frame[0:300, 200:430]
    
   
    
    cv2.imshow('frame_crop',frame_crop)     
    cv2.imshow('frame',frame)     
     
   
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
         
cap.release()
cv2.destroyAllWindows()



