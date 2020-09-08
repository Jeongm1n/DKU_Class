def f(x):
    return x

def g(x):
    return x**2

import numpy as np

N = int(input("Give the number of check points N: "))
epsilon = float(input("Give the error tolerance: "))
x_values = np.linspace(-4, 4, N)

for i in range(N):
    if abs(f(x_values[i]) - g(x_values[i])) < epsilon:
        print (x_values[i])