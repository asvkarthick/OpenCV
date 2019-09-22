#!/usr/bin/python3
# Author : Karthick Kumaran <asvkarthick@gmail.com>
# Gaussian Blur program

import cv2

img = cv2.imread("../../images/lenna.bmp")
cv2.imshow("Original", img)

blur = cv2.GaussianBlur(img, (9, 9), 0)
cv2.imshow("Blurred", blur)

cv2.waitKey(0)
cv2.destroyAllWindows()
