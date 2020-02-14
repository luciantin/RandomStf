import cv2
import numpy as np
import matplotlib.pyplot as plt
import math

cap = cv2.VideoCapture('video6.mp4')
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
    
    
    frame2gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    

    
    lower = np.array([30,105,65])
    upper = np.array([179,215,146])
    mask = cv2.inRange(hsv, lower, upper)
    res = cv2.bitwise_and(frame,frame, mask= mask)
    cv2.imshow('frame',frame)
    cv2.imshow('mask',mask)
    cv2.imshow('res',res)
    kernel = np.ones((5,5),np.uint8)

    
    
    res2gray = cv2.cvtColor(res,cv2.COLOR_BGR2GRAY)    
    ret, thresh = cv2.threshold(res2gray, 0, 255, 0)    
    im2, contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)




    if len(contours)>0 :
        cnt = contours[len(contours)-1]
        rect = cv2.minAreaRect(cnt)
        box = cv2.boxPoints(rect)
        box = np.int0(box)
        cv2.drawContours(frame,[box],0,(0,0,255),2)

        
        print(box)
        print('NOVI2')
        print(box[0][0])
        print('NOVI')
        
        duljD = IzracunajDuljinu(box[0][0],box[0][1],box[1][0],box[1][1])
        duljB = IzracunajDuljinu(box[1][0],box[1][1],box[3][0],box[3][1])
        duljC = IzracunajDuljinu(box[3][0] ,box[3][1] ,box[0][0],box[0][1])
        duljA = IzracunajDuljinu(box[0][0] ,box[0][1],box[1][0] ,box[1][1])
        
        
        cv2.putText(frame,"Duljina D :"+ '%.2f' % duljD, (box[0][0]-150,box[0][1]-20), cv2.FONT_HERSHEY_PLAIN, 1, 1)
        cv2.putText(frame,"Duljina A :"+ '%.2f' % duljA, (box[1][0]-20,box[1][1]-35), cv2.FONT_HERSHEY_PLAIN, 1, 1)
        cv2.putText(frame,"Duljina B :"+' %.2f' % duljB, (box[2][0]+35,box[2][1]+20), cv2.FONT_HERSHEY_PLAIN, 1, 1)
        cv2.putText(frame,"Duljina C :"+ '%.2f' % duljC, (box[3][0]-30,box[3][1]+40), cv2.FONT_HERSHEY_PLAIN, 1, 1)

        



    
##    cv2.imshow('im2',im2)     
    cv2.imshow('frame',frame)     
     
   
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
         
cap.release()
cv2.destroyAllWindows()



