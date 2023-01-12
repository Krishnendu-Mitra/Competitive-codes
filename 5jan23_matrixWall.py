#code by krish
v = []
arr = []
#functions---------------------------->
def getdata(n):
    v1 = 0
    v2 = 0
    v3 = 0
    v4 = 1
    j = 0
    for i in range(0,n,1):
        print("[",i+1,",",j+1,"]data: ")
        v1 = int(input("<<< "))
        print("[",i+1,",",j+2,"]data: ")
        v2 = int(input("<<< "))
        print("[",i+1,",",j+3,"]data: ")
        v3 = int(input("<<< "))
        print("[",i+1,",",j+4,"]data: ")
        v4 = int(input("<<< "))
        if((v1==1 or v1 ==0)and(v2==0 or v2==1)and(v3==1 or v3==0)and(v4==0 or v4==1)):
            v=[v1,v2,v3,v4]
            arr.append(v)
            if(j >= 4):
                j = 0
        else:
            print("Error, given data is not boolean!")
            break
    print("Your data is: ",arr)
#main--------------------------------->
n = int(input("Enter the step of matrix: "))
if(n >= 0):
    print("Enter your data one by one(for True type 1 and False type 0)\n")
    getdata(n)
else:
    print("Error size not valid\n")
#happy ending