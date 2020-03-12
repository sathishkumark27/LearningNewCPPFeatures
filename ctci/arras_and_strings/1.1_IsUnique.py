
def IsUnique (str):
    if len(str) > 256:
        return False
    map = {}
    for i in range(len(str)):
        if map.get(str[i], -1) == -1:
            map[str[i]] = str[i]
        else :
            return False
    return True        

def IsUnique2 (str):
    if len(str) > 256:
        return False
    i,j = 0, 1    
    s = "".join(sorted(str))
    while j < len(s):        
        if s[i] == s[j]:
            return False
        i+=1
        j+=1        
    return True

def IsUnique3 (str):
    if len(str) > 256:
        return False    
    ispresent = [0]*256
    for i in range(len(str)):
        if ispresent[ord(str[i])] == 1 :
            return False
        ispresent[ord(str[i])] = 1
    return True

def IsUnique4(str):
    if len(str) > 26:
        return False    
    bitmap = 1
    for i in range(len(str)):
        pos = ord(str[i]) - ord('a')
        val = 1 << pos
        if bitmap & val :
            return False
        bitmap |=val
    return True



ip = input()
res1 = IsUnique(ip)
res2 = IsUnique2(ip)
res3 = IsUnique3(ip)
res4 = IsUnique4(ip)
print("res 1 = ", res1)
print("res 2 = ", res2)
print("res 3 = ", res3)
print("res 4 = ", res4)