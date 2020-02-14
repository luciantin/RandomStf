import cv2
import numpy as np
import matplotlib.pyplot as plt

cap = cv2.VideoCapture(0)

font = cv2.FONT_HERSHEY_SIMPLEX


pts = np.array([[0,0],[4,50],[25,287],[100,123],[60,60]],np.int32)

img = cv2.imread('test.png',cv2.IMREAD_GRAYSCALE)

while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    cv2.line(frame,(0,0),(150,150),(255,0,0),15)
    cv2.rectangle(frame,(15,12),(200,150),(0,255,0),5)
    cv2.polylines(gray, [pts],True,(0,0,255),1)
    cv2.putText(gray, 'TIN',(130,130),font,0.5,(200,200,200),1,cv2.LINE_AA)
    cv2.imshow('frame',frame)
    cv2.imshow('gray',gray)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
 

        
cap.release()
cv2.destroyAllWindows()






##
##cv2.line(img,(0,0),(150,150),(255,0,0),15)
##cv2.imshow('image', img)
##cv2.waitKey(0)
##cv2.destroyAllWindows()

##plt.imshow(img, cmap='gray', interpolation='bicubic')
##plt.plot([0,0],[100,100],'c',linewidth=5)
##plt.show()

