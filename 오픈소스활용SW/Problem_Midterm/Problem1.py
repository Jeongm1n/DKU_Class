from random import randint

def duplicate(arr):
    store=[]
    for i in range(20):
        count=0
        for j in range(20):
            if arr[i]==arr[j]:
                count=count+1
        if count==1:
            store.append(arr[i])
    
    return store
            

num = []
for i in range(20):
    num.append(randint(1,20))
print("---------입력된 정수들---------")
print(num)
print("---------중복되지 않은 수---------")
print(duplicate(num))