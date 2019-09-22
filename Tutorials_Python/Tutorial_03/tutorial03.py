#!/usr/bin/python
# Author : Karthick Kumaran <asvkarthick@gmail.com>

import numpy as np
import cv2

img = cv2.imread("../../images/lenna.bmp")
gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
cv2.imshow("Original", img)
cv2.imshow("Gray", gray)

cv2.waitKey(0)
cv2.destroyAllWindows()
