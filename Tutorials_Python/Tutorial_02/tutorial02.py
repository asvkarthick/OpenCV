#!/usr/bin/python
# Author : Karthick Kumaran <asvkarthick@gmail.com>

import numpy as np
import cv2

img = cv2.imread("../../images/dollar.bmp")
cv2.imshow("Image", img)

cv2.waitKey(0)
cv2.destroyAllWindows()
