#code by krish
#functions---------------------------->
def getdata(n):
    v1 = 0
    v2 = 0
    v3 = 0
    v4 = 1
    for i in range(0,n,1):
        v1 = int(input())
#main--------------------------------->
n = int(input("Enter the size of list: "))
if(n >= 0):
    print("Enter your data one by one\n")
    getdata(n)
else:
    print("Error size not valid\n")