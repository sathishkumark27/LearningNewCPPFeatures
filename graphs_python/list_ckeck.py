l = [1,2,3]
for i in range(len(l)):
    print("i = %d, l[i] = %d" %(i, l[i]))
    if (l[i] == 1):
        l.pop(i)
print(l)