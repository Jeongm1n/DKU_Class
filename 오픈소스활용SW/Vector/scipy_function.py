import numpy as np
import math
a=np.array([np.random.randint(1,100), np.random.randint(1,100)])
b=np.array([np.random.randint(1,100), np.random.randint(1,100)])
result = math.sqrt(((a[0]-b[0])**2)+((a[1]-b[1])**2))