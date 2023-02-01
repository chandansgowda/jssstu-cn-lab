def gcd(a,b):
    while b!=0:
        a,b=b,a%b
    return a

def find_coprime(phi):
    e = 2
    while e<phi:
        if gcd(e,phi)==1:
            return e
        e+=1

def find_privatekey(e,phi):
    d = 0
    k = 1
    while True:
        d = (1+(k*phi))/e
        if d.is_integer():
            return int(d)
        k+=1

def modular_exp(b,e,m):
    res = (b**e)%m
    return res

def rsa_encrypt(p,e,n):
    ciphertext = []
    for i in p:
        ciphertext.append(modular_exp(ord(i),e,n))
    return ciphertext

def rsa_decrypt(c,d,n):
    plaintext = []
    for i in c:
        plaintext.append(chr(modular_exp(i,d,n)))
    return plaintext

p = 17
q = 23

n = p*q
phi = (p-1)*(q-1)

e = find_coprime(phi)

d = find_privatekey(e, phi)

p = input("Enter plaintext: ")

ct = rsa_encrypt(p,e,n)

print("Ciphertext: ", ct)

pt = rsa_decrypt(ct,d,n)

print("Plaintext: ", pt)