#code by krish
#Question---------------------------------->
'''Given an array of time intervals (start, end)
for classroom lectures (possibly overlapping),
find the minimum number of rooms required.
For example, given [(30, 75), (0, 50), (60, 150)],
you should return 2.'''
#Answer------------------------------------>
j = []
cache = 99999
arr = []
def calculation(arr, n):
    temp = [0] * cache
    for i in range(n):
        temp[arr[i][0]] += 1
        temp[arr[i][1] + 1] -= 1
    ans = temp[0]
    for i in range(1,cache):
        temp[i] += temp[i - 1]
        ans = max(ans, temp[i])
    return ans
#Main------------------->
#[[30, 75],[0, 50],[60, 150]] give me 2
start = 0
end = 1 
n = int(input("Enter the no of total class: "))
for i in range(0,n):
    print(i+1,"no class Start")
    start = int(input("<<< "))
    print(i+1,"no class End")
    end = int(input("<<< "))
    j = [start,end]
    arr.append(j)
#print(">>>",n,arr)
cache = calculation(arr, n)
print("\nYour requerment is only: ",cache," class rooms\n")
#Happy ending