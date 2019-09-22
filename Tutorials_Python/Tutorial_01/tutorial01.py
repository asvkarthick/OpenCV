#!/usr/bin/python3
# Author : Karthick Kumaran <asvkarthick@gmail.com>

import numpy as np
import cv2

black_img = np.zeros([1280, 720, 1], 'uint8')
cv2.imshow("Black Image", black_img)

white_img = np.zeros([720, 1280, 1], 'uint8')
white_img[:, :] = 255
cv2.imshow("White Image", white_img)

cv2.waitKey(0)
cv2.destroyAllWindows()
