import matplotlib.pyplot as plt
def f(a, b, x):
    index=[]
    for i in range(5):
        index.append(a*x[i]+b)
    return index
def compute_error(a,b,y):
    e=0
    for i in range(5):
        e+=(((a*i)+b-y[i])**2)
    return e;
def line():
    draw = f(a,b,x)
    plt.plot(x,y)
    plt.plot(x, draw)
    plt.xlabel("Time(s)")
    plt.ylabel("y (star) and straight line f(t)")
    plt.show()
    
D = [[0,0.5],[1,2.0],[2,1.0],[3,1.5],[4,7.5]]
x=[]
y=[]
for i in range(5):
   x.append(D[i][0])
   y.append(D[i][1])
   
a=int(input('a : '))
b=int(input('b : '))
print("e : %g" % compute_error(a,b,y))
line()