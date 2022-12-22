#code by krish
#Question------------------------>
'''Give a list of integers, write a function
that returns the largest sum of non-adjacent 
numbers. Numbers can be 0 or negative.'''
#Answer--------------------------->
#[2, 4, 6, 2, 5] ans is 13 pick 2, 6, 5
arr = []
#functions------------------------>
def funa(arr,n):
    cache = 0
    j = 0
    temp = arr[0]
    if(n >= 0 and n <= 2):
        return max(arr)
    else:
        cache = cache + 1
    for i in range(1,n):
        temp, j = j + arr[i], max(j,temp) #tuple unpack method (a,b = a+b, b-a)
    return max(j, temp)
def funb():
    try:
        n = int(input("Enter the size of list: "))
        if(n>=0):
            for i in range(0,n,1):
                ele = int(input("<<< "))
                arr.append(ele)
            print("your given list is = ",arr)
            result = funa(arr,n)
            print("Largest sum of non-adjacent is = ",result)
        else:
            print("Error! invalid size try again..")
            funb()
    except Exception as err:
        print(f'Error approch as follows: {err}',"\n")
#main---------------------------->
funb() #only one function call
