#Question---------------------------------->
'''The power set of a set is the set of all its subsets. 
Write a function that, given a set, generates its power set.
For example, given the set {1, 2, 3}, it should return 
{{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}'''
#Answer------------------------------------>
import os
import math
#code by krish
#function------------------------->
def calculationB(arr,n):
    i = n
    while (i > 0 and arr[i - 1] <= arr[i]):
        i -= 1
    if (i <= 0):
        return False
    j = i - 1
    while (j + 1 <= n and arr[j + 1] < arr[i - 1]):
        j += 1
    cache = arr[i - 1]
    arr[i - 1] = arr[j]
    arr[j] = cache
    size = int((n-i+1)/2)
    for k in range(size):
        temp = arr[k + i]
        arr[k + i] = arr[n - k]
        arr[n - k] = temp
    return True
def calculationA(arr,n):
    contain = [0]*n
    print("{ }")
    for i in range(n):
        contain[i] = 1
        Contain = contain.copy()
        while True:
            print("{",end="")
            for j in range(n):
                if (Contain[j]):
                    print(arr[j], end="")
            print("},")
            if not calculationB(Contain,n-1):
                break
#main------------------------>
arr = []
temp = 0
n = int(input("Enter the size of arr: "))
for i in range(n):
    print(i+1,"Value is")
    temp = int(input("<<< "))
    arr.append(temp)
print("{ ")
calculationA(arr,n)
print(" }")