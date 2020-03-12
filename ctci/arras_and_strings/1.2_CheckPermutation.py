from collections import Counter

def IsPermutation(A, B):
    if (len(A) != len(B)):
        return False
    A_c = Counter(A)
    for b in B:
        A_c[b]-=1
    for [key, val] in A_c.items():
        if val != 0:
            return False
    return True

def IsPermutation2(A, B):
    if (len(A) != len(B)):
        return False

    a = "".join(sorted(A)) # out of place sort
    b = "".join(sorted(B))
    if a == b:
        return True
    return False

A = input()
B = input()
res1 = IsPermutation(A, B)
res2 = IsPermutation2(A, B)
print("res 1 = ", res1)
print("res 2 = ", res2)
