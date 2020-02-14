import cv2
import numpy as np
import matplotlib.pyplot as plt
##
##cap = cv2.VideoCapture(0)
##
##img = cv2.imread('test.png',cv2.IMREAD_GRAYSCALE)

##while True:
##    ret, frame = cap.read()
##    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
##    
##    cv2.imshow('frame',frame)
##    cv2.imshow('gray',gray)
##    if cv2.waitKey(1) & 0xFF == ord('q'):
##        break
 

        
##cap.release()
##cv2.destroyAllWindows()






##
##cv2.line(img,(0,0),(150,150),(255,0,0),15)
##cv2.imshow('image', img)

imgray = cv2.imread('test2.jpg',cv2.IMREAD_GRAYSCALE)

ret,thresh = cv2.threshold(imgray,127,255,0)
contours, hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

cv2.waitKey(0)
cv2.destroyAllWindows()

##plt.imshow(img, cmap='gray', interpolation='bicubic')
##plt.plot([0,0],[100,100],'c',linewidth=5)
##plt.show()

