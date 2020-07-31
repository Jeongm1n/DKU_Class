#!/usr/bin/env python
# coding: utf-8

# In[3]:


def square(s):
    """get A of square with s"""
    A = s**2
    return A


# In[ ]:


def rectangle(a,b):
    """get A of rectangle with s"""
    A = a*b
    return A


# In[ ]:


from math import pi

def circle(r):
    """get A of circle with r"""
    A = pi * r**2
    return A


# In[ ]:


def triangle(b,h):
    """get A of triangle with b, h"""
    A = 0.5*b*h
    return A


# In[ ]:


def parallelogram(b,h):
    """get A of parallelogram with b,h"""
    A = b*h
    return A


# In[ ]:


from math import pi

def circular_sector(r,c):
    """get A of circular_sector with r,c"""
    A = pi * (r**2) * (c/360)
    return A


# In[4]:


from math import pi

def circle_ring(R,r):
    """get A of circle_ring with R,r"""
    A = pi * (R**2 - r**2)
    return A


# In[ ]:


def trapezoid(h,a,b):
    """get A of trapezoid with h,a,b"""
    A = h * ((a+b)/2)
    return A


# In[ ]:


def rectangular_box(a,b,c):
    """get A of rectangular_box with a,b,c"""
    A = 2*a*b + 2*b*c + 2*a*c
    return A


# In[ ]:


def cube(l):
    """get A of cube with l"""
    A=6 * (l**2)
    return A


# In[ ]:


from math import pi

def cylinder(r,h):
    """get A of cylinder with r,h"""
    A = 2 * pi * r * (r+h)
    return A


# In[5]:


from math import pi

def right_circular_cone(r,s):
    """get A of right_circular_cone with r,s"""
    A = pi * (r**2) + math.pi * r * s
    return A


# In[ ]:


from math import pi

def sphere(r):
    """get S of sphere with r"""
    S = 4 * pi * (r**2)
    return S

