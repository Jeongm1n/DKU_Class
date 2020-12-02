"""
Problem #2
"""

def min_index(arr):
    MIN=arr[0]
    for i in range(len(arr)):
        if MIN>arr[i]:
            MIN=arr[i]
            index=i
    return arr[index], index

def max_index(arr):
    MAX=arr[0]
    for i in range(len(arr)):
        if MAX<arr[i]:
            MAX=arr[i]
            index=i
    return arr[index], index

arr=[10,8,16,9,21,88,99,31,7]
MIN=arr[0]

for i in range(len(arr)):
    if MIN>arr[i]:
        MIN=arr[i]
        

print(MIN, i) # 1번
print(min_index(arr)) # 2번
print(max_index(arr)) # 3번

