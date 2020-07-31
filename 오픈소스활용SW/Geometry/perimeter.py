#!/usr/bin/env python
# coding: utf-8

# In[7]:


def square(s):
    '''get P of square with s'''
    return 4*s


# In[8]:


def parallelogram(a, b):
    '''get P of parrallelogram with a, b'''
    return 2*a + 2*b


# In[9]:


from math import pi

def circle(r):
    '''get P of circle with r'''
    return 2*pi*r


# In[10]:


def triangle(a, b, c):
    '''get P of triangle with a,b,c'''
    return a+b+c


# In[11]:


def rectangle(a,b):
    '''get P of rentangle with a,b'''
    return 2*(a+b)


# In[13]:


def trapezoid(a, b, c, d):
    '''get P of trapezoid with a,b,c,d'''
    return a+b+c+d;


# In[ ]:


def circular_sector(r, seta):
    '''get P(length) of circular sector with r, seta'''
    return r * seta

