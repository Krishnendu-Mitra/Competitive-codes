#code by krish
#Question-------------------------------->
'''Implement an autocomplete system. That
is, given a quary string and a set of all
possible query strings, return all strings
in the set that have as prefix'''
#Answer---------------------------------->
mydicti = {
    "a": ["apple","approx","append","also","alpha"],
    "ab": ["absolute","absent","absorve","alpha beta","abp ananda"],
    "ac": ["A.C.","air condition","alpha condition","ac market","acknowledgement","active"],
    "ad": ["advantages","aadhar","adidas"],
    "ae": ["aeroplane","aesthetic"],
    "af": ["africa","afghanistan","afcat"],
    "ag": ["age","age calculator","agoda","agriculture"],
    "ah": ["ahmedabad","ahaglow face wash"],
    "ai": ["A.I.","airtel","air india"],
    "ak": ["akinator","akasa air"],
    "al": ["al","airtel","air india"],
    "krish": "A coder"
}
arr = ["apple","approx","append","also","alpha","absolute","absent","absorve","alpha beta","abp ananda",mydicti]
#print(mydicti)
arr = str(arr)
def search(temp):
    alpa =  arr.find(temp)
    print(alpa)
#main---------------------------------->
l = 1
n = input("Enter: ")
for i in range(0,len(n),1):
    temp = n[0:i]
    search(temp)
l = 1+1
# temp = mydicti.get(n)
# print(temp)