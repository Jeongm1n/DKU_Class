"""
Problem #4, Geometry module
"""
from math import pi
from math import sqrt

class Area:
    def __init__(self, shape, type):
        self.shape = shape
        self.type = type
        
    def square(s):
        """get A of square with s"""
        A = s**2
        return A

    def rectangle(a,b):
        """get A of rectangle with s"""
        A = a*b
        return A

    def circle(r):
        """get A of circle with r"""
        A = pi * r**2
        return A

    def triangle(b,h):
        """get A of triangle with b, h"""
        A = 0.5*b*h
        return A

    def parallelogram(b,h):
        """get A of parallelogram with b,h"""
        A = b*h
        return A

    def circular_sector(r,c):
        """get A of circular_sector with r,c"""
        A = pi * (r**2) * (c/360)
        return A

    def circle_ring(R,r):
        """get A of circle_ring with R,r"""
        A = pi * (R**2 - r**2)
        return A

    def trapezoid(h,a,b):
        """get A of trapezoid with h,a,b"""
        A = h * ((a+b)/2)
        return A

    def rectangular_box(a,b,c):
        """get A of rectangular_box with a,b,c"""
        A = 2*a*b + 2*b*c + 2*a*c
        return A

    def cube(l):
        """get A of cube with l"""
        A=6 * (l**2)
        return A

    def cylinder(r,h):
        """get A of cylinder with r,h"""
        A = 2 * pi * r * (r+h)
        return A

    def right_circular_cone(r,s):
        """get A of right_circular_cone with r,s"""
        A = pi * (r**2) + pi * r * s
        return A

    def sphere(r):
        """get S of sphere with r"""
        S = 4 * pi * (r**2)
        return S

class Volume:
    def __init__(self, shape, type):
        self.shape = shape
        self.type = type
        
    def sphere(r):
        '''get volume of sphere with r'''
        return 4 * pi * r ** 3 / 3

    def rectangular_box(a,b,c):
        '''get volume of rectangular_box with r'''
        return a * b * c

    def right_circular_cone(r, h):
        '''get volume of right_circular_cone with r, h'''
        return (1/3) * pi * r ** 2 * h

    def cube(l):
        '''get volume of cube with l'''
        return l ** 3

    def cylinder(r, h):
        '''get volume of cylinder with r, h'''
        return pi * r ** 2 * h

    def frustum_of_a_cone(r, R, h):
        '''get volume of frustum of a cone with r, R, h'''
        return (1/3) * pi * h * (r**2 + r*R + R**2)


class Perimeter:
    def __init__(self, shape, type):
        self.shape = shape 
        self.type = type
        
    def square(s):
        '''get P of square with s'''
        return 4*s

    def parallelogram(a, b):
        '''get P of parrallelogram with a, b'''
        return 2*a + 2*b

    def circle(r):
        '''get P of circle with r'''
        return 2*pi*r

    def triangle(a, b, c):
        '''get P of triangle with a,b,c'''
        return a+b+c

    def rectangle(a,b):
        '''get P of rentangle with a,b'''
        return 2*(a+b)

    def trapezoid(a, b, c, d):
        '''get P of trapezoid with a,b,c,d'''
        return a+b+c+d;

    def circular_sector(r, seta):
        '''get P(length) of circular sector with r, seta'''
        return r * seta

class Pythagorean:
    def __init__(self, shape, type):
        self.shape = shape 
        self.type = type
    def pythagorean_theorem(a,b):
        """get c of pythagorean_theorem with a,b"""
        c = sqrt((a**2) + (b**2))
        return c
    
class Busbar:
    def __init__(self, shape, type):
        self.shape = shape 
        self.type = type
    def right_circular_cone(r,h):
        """get s of right_circular_cone with r,h"""
        s = sqrt((r**2) + (h**2))
        return s