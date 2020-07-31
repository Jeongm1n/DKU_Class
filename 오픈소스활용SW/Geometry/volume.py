#!/usr/bin/env python
# coding: utf-8

# In[2]:


from math import pi
def sphere(r):
    '''get volume of sphere with r'''
    return 4 * pi * r ** 3 / 3


# In[3]:


def rectangular_box(a,b,c):
    '''get volume of rectangular_box with r'''
    return a * b * c


# In[4]:


def right_circular_cone(r, h):
    '''get volume of right_circular_cone with r, h'''
    return (1/3) * pi * r ** 2 * h


# In[6]:


def cube(l):
    '''get volume of cube with l'''
    return l ** 3


# In[7]:


def cylinder(r, h):
    '''get volume of cylinder with r, h'''
    return pi * r ** 2 * h


# In[8]:


def frustum_of_a_cone(r, R, h):
    '''get volume of frustum of a cone with r, R, h'''
    return (1/3) * pi * h * (r**2 + r*R + R**2)

