#!/usr/bin/python3
# Author : Karthick Kumaran <asvkarthick@gmail.com>
# Gaussian Blur program

import numpy as np
import cv2

img = cv2.imread("../../images/lenna.bmp")
cv2.imshow("Original", img)

blur = cv2.GaussianBlur(img, (9, 9), 0)
cv2.imshow("Blurred", blur)

kernel = np.ones((5, 5), 'uint8')

dilate = cv2.dilate(img, kernel, iterations = 1)
erode = cv2.erode(img, kernel, iterations = 1)
cv2.imshow("Dilate", dilate)
cv2.imshow("Erode", erode)

cv2.waitKey(0)
cv2.destroyAllWindows()
