#!/usr/bin/python
# Author : Karthick Kumaran <asvkarthick@gmail.com>

import numpy as np
import cv2

img = cv2.imread("../../images/dollar.bmp")
cv2.imshow("Image", img)

b,g,r = cv2.split(img)
cv2.imshow("Blue", b)
cv2.imshow("Green", g)
cv2.imshow("Red", r)

cv2.waitKey(0)
cv2.destroyAllWindows()
