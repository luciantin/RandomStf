import cv2
import numpy as np
import matplotlib.pyplot as plt
import thread

bilateral = 0
cap = cv2.VideoCapture(0)


def worker():
    while True:
        ret, frame = cap.read()
        frame = cv2.resize(frame,(640,480))
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        lower = np.array([0,130,199])
        upper = np.array([9,255,255])
        mask = cv2.inRange(hsv,lower,upper)
        res = cv2.bitwise_and(frame,frame,mask=mask)
        res2gray = cv2.cvtColor(cv2.medianBlur(res,15),cv2.COLOR_BGR2GRAY)    
        ret, thresh = cv2.threshold(res2gray, 0, 255, 0)    
        im2, contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
       
        global bilateral
        #bilateral = cv2.bilateralFilter(res,15,75,75)
        bilateral = im2
        #print 'wRking'
        
        
    

thread.start_new_thread( worker, ())
    
while True:
    
    ret, frame = cap.read()
    frame = cv2.resize(frame,(640,480))
    cv2.imshow('frame',frame)
    cv2.imshow('bilateral',bilateral)
    



    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
 

        
cap.release()
cv2.destroyAllWindows()

