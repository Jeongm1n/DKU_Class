from random import randint
import matplotlib.pyplot as plt
ots=[1,2,3,4,5,6]
count=[0,0,0,0,0,0]
n=0
idx=1
while n!=100:
    number=[]
    print("----------1 ~ %d----------" %(n+10))
    for i in range(10):
        x=randint(1,6)
        number.append(x)
    for i in range(6):
        for j in range(10):
            if ots[i]==number[j]:
                count[i]=count[i]+1
    n=n+10
    for i in range(6):
        print("%d의 빈도 수 : %d--------분수 : %.3f" % (ots[i], count[i], float(count[i]/n)))
    plt.title('1 ~ %d' % n)
    plt.plot(ots, count)
    plt.xlabel("1 ~ 6")
    plt.ylabel("Frequency of number")
    plt.show()