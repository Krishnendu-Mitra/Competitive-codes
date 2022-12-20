#code by krish
#question------------>
'''Given an array of integers, find the first missing positive integer
in linear time and constant space. In other words, find the lowest 
positive integer that does not exist in the array.  The array can 
contain duplicates and negative number as well'''
#answer-------------->
cache = 1
#functions----------->
def funa(arr,n):
    ans = []
    arr.sort()
    #print(arr)
    try:
        for i in range(arr[0],arr[n-1],1):
            if i not in arr:
                ans.append(i)
            else:
                cache = 1
        print("Lowest missing link is = ",ans[0])
        print("Return with code: ",cache)
        r = int(input(">>> "))
        if(r == cache):
            funb()
        else:
            print("exit()\n")
    except Exception as err:
        print(f'Error approch as follows: {err}',"\n")
def funb():
    arr = []
    n = int(input("Enter your list size here: "))
    if(n>=0 and n<=10000):
        print("Please try to not give same values!")
        for i in range(0,n,1):
            temp = int(input("<<< "))
            arr.append(temp)
        print("This is your list = ",arr)
        funa(arr,n)
    else:
        print("-ve not valid!")
        funb()
#main------------------>
funb()