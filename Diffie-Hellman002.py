import matplotlib
import matplotlib.pyplot as plt
import time
import random

def ETF(n):
    count = 0
    for i in range(1,n):
        if gcd(i,n)==1:
            count+=1
    return count

def gcd(a,b):
    while a%b!=0:
        a,b=b,(a%b)
    return b

def Primitive_Root(n):
    phi = ETF(n)
    primitive_root=[]
    prime_List = []
    for i in range(1,n):
        if gcd(i,n)==1:
            prime_List.append(i)
    for j in prime_List:
        listt = []
        for k in range(1,phi+1):
            listt.append(j**k % n)
        listt.sort()
        if listt==prime_List:
            primitive_root.append(j)
    if len(primitive_root)!=0:
        return (n,primitive_root)

def discrete_log(a,p,result):
    ans = 0
    while (a**ans)%p!=result:
        ans+=1
        continue
    return ans

def diffie_hellman(prime,primitive_root):
    ya = random.randint(500,1000)
    yb = random.randint(500,1000)
    print('The public number is: ' + str(prime) + ' The primitive_root of this public number is: ' + str(primitive_root))
    keya = (primitive_root**ya)%prime
    keyb = (primitive_root**yb)%prime
    print('The Key User A sends to User B is ' + str(keya) + ' The Key User B to User A is ' + str(keyb))
    share_keya = (keyb**ya)%prime
    share_keyb = (keya**yb)%prime
    print('The first key is ' + str(share_keya) + 'The second key is' + str(share_keyb))

def crack(prime,primitive_root,keya,keyb):
    '''
    solve the key using brute force
    :return:
    '''
    ansa, ansb = 1,1
    while (primitive_root**ansa)%prime!=keya:
        ansa+=1
    while (primitive_root**ansb)%prime!=keyb:
        ansb+=1
    shared_key = (keya**ansb)%prime
    return ansa, ansb, shared_key

def decipher(prime,primitive_root,keya,keyb):
    """
    crack the key using tail_recursion
    """
    

print(Primitive_Root(794))
#diffie_hellman(794,789)
#525
print(crack(794,789,115,339))

