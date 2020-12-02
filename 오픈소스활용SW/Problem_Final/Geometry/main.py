import Geometry as geo
print("Geometry Calulator\n",'### menu ###\n', 'p - perimeter\n',
     'a - area\n', 'v - volume\n', 'b - busbar\n', 'pytha - pythagorean theorem\n')

user_menu = str(input())
if user_menu == 'p':  
    print("### perimeter - shape ###\nYou can type\nsquare, rectangle, circle, triangle, parrelleogram, circular sector, trapezoid\n")
    
    shape = str(input())
    
    if shape == 'square':
        
        print("type - s : side")
        s = int(input("s :"))
        print(geo.Perimeter.square(s))
        
    elif shape == 'rectangle':
        
        print("type - a : width / b : height")
        a = int(input("a :"))
        b = int(input("b :"))
        print(geo.Perimeter.rectangle(a,b))
        
    elif shape == 'circle':
        
        print("type - r : radius")
        r = int(input("r :"))
        print(geo.Perimeter.circle(r))
        
    elif shape == 'triangle':
        
        print("type - a : side.1 / b : side.2 / c : side.3")
        a = int(input("a :"))
        b = int(input("b :"))
        c = int(input("c :"))
        print(geo.Perimeter.triangle(a,b,c))
        
    elif shape == 'parallelogram':
        
        print("type - a : hypotenuse / b : base")
        a = int(input("a :"))
        b = int(input("b :"))
        print(geo.Perimeter.parallelogram(a,b))
        
    elif shape == 'circular sector':
        
        print("type - r : radius / seta : θ")
        r = int(input("r :"))
        seta = int(input())
        print(geo.Perimeter.circular_sector(r, seta))
        
    elif shape == 'trapezoid':
        
        print("type - a : upper side / b,c : hypotenuse / d : base")
        a = int(input("a :"))
        b = int(input("b :"))
        c = int(input("c :"))
        d = int(input("d :"))
        print(geo.Perimeter.trapezoid(a,b,c,d))

elif user_menu == 'v':
    
    
    print("### volume - shape ###\nYou can type\nsphere, rectangular box, right circular cone, cube, cylinder, frustum of a cone\n")

    shape = str(input())

    if shape == 'sphere':
        
        print("type - r : radius")
        r = int(input("r :"))
        print(geo.Volume.sphere(r))
        
    elif shape == 'rectangular box':
        
        print("type - a : height / b : base / c : top side")
        a = int(input("a :"))
        b = int(input("b :"))
        c = int(input("c :"))
        print(geo.Volume.rectangular_box(a,b,c))
        
    elif shape == 'right circular cone':
        
        print("type - r : radius / h : height")
        r = int(input("r :"))
        h = int(input("h :"))
        print(geo.Volume.right_circular_cone(r,h))
        
    elif shape == 'cube':
        
        print("type - l : side")
        l = int(input("l :"))
        print(geo.Volume.cube(l))
        
    elif shape == 'cylinder':
        
        print("type - r : radius / h : height")
        r = int(input("r :"))
        h = int(input("h :"))
        print(geo.Volume.cyliner(r,h))
        
    elif shape == 'frustum of a cone':
        
        print("type - r : upper circle radius / R : base circle radius / h : height")
        r = int(input("r :"))
        R = int(input("R :"))
        h = int(input("h :"))
        print(geo.Volume.frustum_of_a_cone(r,R,h))


elif user_menu == 'a':

    
    print("### area - shape ###\nYou can type\nsquare, rectangle, circle, triangle, parallelogram, circular sector, circular ring, trapezoid, rectangular box, right circular cone, cube, cylinder\n")
    
    shape = str(input())
    
    if shape == 'square':
        
        print("type - a : side")
        s = int(input("s :"))
        print(geo.Area.square(s))
        
    elif shape == 'rectangle':
        
        print("type - a : width / b : height")
        a = int(input("a :"))
        b = int(input("b :"))
        print(geo.Area.rectangle(a,b))
        
    elif shape == 'circle':
        
        print("type - r : radius")
        r = int(input("r :"))
        print(geo.Area.circle(r))
        
    elif shape == 'triangle':
        
        print("type - b : base / h : height")
        b = int(input("b :"))
        h = int(input("h :"))
        print(geo.Area.triangle(b, h))
        
    elif shape == 'parallelogram':
        
        print("type - b : base / h : height")
        b = int(input("b :"))
        h = int(input("h :"))
        print(geo.Area.parallelogram(b, h))
        
    elif shape == 'circular sector':
        
        print("type - r : radius / seta : θ")
        r = int(input("r :"))
        seta = int(input())
        print(geo.Area.circular_sector(r, seta))
        
    elif shape == 'circular ring':
        
        print("type - R : outside circle radius / r : inside circle radius")
        R = int(input("R :"))
        r = int(input("r :"))
        print(geo.Area.circular_ring(R, r))
        
    elif shape == 'trapezoid':
        
        print("type - h : height / a : upper side / b : base")
        h = int(input("h :"))
        a = int(input("a :"))
        b = int(input("b :"))
        print(geo.Area.trapezoid(h,a,b))
        
    elif shape == 'rectangular box':
        
        print("type - a : height / b : base / c : top side")
        a = int(input("a :"))
        b = int(input("b :"))
        c = int(input("c :"))
        print(geo.Area.rectangular_box(a, b, c))
        
    elif shape == 'right circular cone':
        
        print("type - r : base circle radius / s : busbar")
        r = int(input("r :"))
        s = int(input("s :"))
        print(geo.Area.right_circular_cone(r,s))
        
    elif shape == 'cube':
        
        print("type - l : side")
        l = int(input("l :"))
        print(geo.Area.cube(l))
        
    elif shape == 'cylinder':
        
        print("type - r : radius / h : height")
        r = int(input("r :"))
        h = int(input("h :"))
        print(geo.Area.cylinder(r,h))
        
elif user_menu == 'pytha':
    
    print("### pythagorean - shape ###\nYou can type\npythagorean theorem\n")

    shape = str(input())

    if shape == 'pythagorean theorem':
        
        print("type - a : side.1 / b : side.2")
        a = int(input("a :"))
        b = int(input("b :"))
        print(geo.Pythagorean.pythagorean_theorem(a,b))
 
elif user_menu == 'b':

    print("### busbar - shape ###\nYou can type\nright circular cone\n")

    shape = str(input())

    if shape == 'right circular cone':
        
        print("type - r : radius / h : height")
        r = int(input("r :"))
        h = int(input("h :"))
        print(geo.Busbar.right_circular_cone(r,h))