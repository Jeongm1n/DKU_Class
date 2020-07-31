# -*- coding: utf-8 -*-
"""
Created on Wed May  6 19:53:59 2020

@author: USER
"""

print("Geometry Calulator\n",'### menu ###\n', 'p - perimeter\n',
     'a - area\n', 'v - volume\n', 'b - busbar\n', 'pytha - pythagorean theorem\n')

user_menu = str(input())


if user_menu == 'p':  
    import perimeter as p
    print("### perimeter - shape ###\nYou can type\nsquare, rectangle, circle, triangle, parrelleogram, circular sector, trapezoid\n")
    
    shape = str(input())
    
    if shape == 'square':
        
        print("type - s : side")
        s = int(input("s :"))
        print(p.square(s))
        
    elif shape == 'rectangle':
        
        print("type - a : width / b : height")
        a = int(input("a :"))
        b = int(input("b :"))
        print(p.rectangle(a,b))
        
    elif shape == 'circle':
        
        print("type - r : radius")
        r = int(input("r :"))
        print(p.circle(r))
        
    elif shape == 'triangle':
        
        print("type - a : side.1 / b : side.2 / c : side.3")
        a = int(input("a :"))
        b = int(input("b :"))
        c = int(input("c :"))
        print(p.triangle(a,b,c))
        
    elif shape == 'parallelogram':
        
        print("type - a : hypotenuse / b : base")
        a = int(input("a :"))
        b = int(input("b :"))
        print(p.parallelogram(a,b))
        
    elif shape == 'circular sector':
        
        print("type - r : radius / seta : θ")
        r = int(input("r :"))
        seta = int(input())
        print(p.circular_sector(r, seta))
        
    elif shape == 'trapezoid':
        
        print("type - a : upper side / b,c : hypotenuse / d : base")
        a = int(input("a :"))
        b = int(input("b :"))
        c = int(input("c :"))
        d = int(input("d :"))
        print(p.trapezoid(a,b,c,d))

elif user_menu == 'a':
    
    import area as ar
    
    print("### area - shape ###\nYou can type\nsquare, rectangle, circle, triangle, parallelogram, circular sector, circular ring, trapezoid, rectangular box, right circular cone, cube, cylinder\n")
    
    shape = str(input())
    
    if shape == 'square':
        
        print("type - a : width / b : height")
        s = int(input("s :"))
        print(ar.square(s))
        
    elif shape == 'rectangle':
        
        print("type - a : width / b : height")
        a = int(input("a :"))
        b = int(input("b :"))
        print(ar.rectangle(a,b))
        
    elif shape == 'circle':
        
        print("type - r : radius")
        r = int(input("r :"))
        print(ar.circle(r))
        
    elif shape == 'triangle':
        
        print("type - b : base / h : height")
        b = int(input("b :"))
        h = int(input("h :"))
        print(ar.triangle(b, h))
        
    elif shape == 'parallelogram':
        
        print("type - b : base / h : height")
        b = int(input("b :"))
        h = int(input("h :"))
        print(ar.parallelogram(b, h))
        
    elif shape == 'circular sector':
        
        print("type - r : radius / seta : θ")
        r = int(input("r :"))
        seta = int(input())
        print(ar.circular_sector(r, seta))
        
    elif shape == 'circular ring':
        
        print("type - R : outside circle radius / r : inside circle radius")
        R = int(input("R :"))
        r = int(input("r :"))
        print(ar.circular_ring(R, r))
        
    elif shape == 'trapezoid':
        
        print("type - h : height / a : upper side / b : base")
        h = int(input("h :"))
        a = int(input("a :"))
        b = int(input("b :"))
        print(ar.trapezoid(h,a,b))
        
    elif shape == 'rectangular box':
        
        print("type - a : height / b : base / c : top side")
        a = int(input("a :"))
        b = int(input("b :"))
        c = int(input("c :"))
        print(ar.rectangular_box(a, b, c))
        
    elif shape == 'right circular cone':
        
        print("type - r : base circle radius / s : busbar")
        r = int(input("r :"))
        s = int(input("s :"))
        print(ar.right_circular_cone(r,s))
        
    elif shape == 'cube':
        
        print("type - l : side")
        l = int(input("l :"))
        print(ar.cube(l))
        
    elif shape == 'cylinder':
        
        print("type - r : radius / h : height")
        r = int(input("r :"))
        h = int(input("h :"))
        print(ar.cylinder(r,h))
        
elif user_menu == 'v':
    
    import volume as v
    
    print("### volume - shape ###\nYou can type\nsphere, rectangular box, right circular cone, cube, cylinder, frustum of a cone\n")

    shape = str(input())

    if shape == 'sphere':
        
        print("type - r : radius")
        r = int(input("r :"))
        print(v.sphere(r))
        
    elif shape == 'rectangular box':
        
        print("type - a : height / b : base / c : top side")
        a = int(input("a :"))
        b = int(input("b :"))
        c = int(input("c :"))
        print(v.rectangular_box(a,b,c))
        
    elif shape == 'right circular cone':
        
        print("type - r : radius / h : height")
        r = int(input("r :"))
        h = int(input("h :"))
        print(v.right_circular_cone(r,h))
        
    elif shape == 'cube':
        
        print("type - l : side")
        l = int(input("l :"))
        print(v.cube(l))
        
    elif shape == 'cylinder':
        
        print("type - r : radius / h : height")
        r = int(input("r :"))
        h = int(input("h :"))
        print(v.cyliner(r,h))
        
    elif shape == 'frustum of a cone':
        
        print("type - r : upper circle radius / R : base circle radius / h : height")
        r = int(input("r :"))
        R = int(input("R :"))
        h = int(input("h :"))
        print(v.frustum_of_a_cone(r,R,h))
        
elif user_menu == 'pytha':
    
    import pythagorean as pytha
    
    print("### pythagorean - shape ###\nYou can type\npythagorean theorem\n")

    shape = str(input())

    if shape == 'pythagorean theorem':
        
        print("type - a : side.1 / b : side.2")
        a = int(input("a :"))
        b = int(input("b :"))
        print(pytha.pythagorean_theorem(a,b))
        
elif user_menu == 'b':
    
    import busbar as bb
    
    print("### busbar - shape ###\nYou can type\nright circular cone\n")

    shape = str(input())

    if shape == 'right circular cone':
        
        print("type - r : radius / h : height")
        r = int(input("r :"))
        h = int(input("h :"))
        print(bb.right_circular_cone(r,h))