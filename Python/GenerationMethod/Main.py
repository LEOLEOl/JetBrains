import hashlib as hl
from Arrangement import *

def brute_force(size_pass, type):
    if type == 1: # 012..9
        data = np.zeros(10)



value = hl.sha1(b'Ha Duc Viet')
print(value.hexdigest())

value = hl.md5(b'Ha Duc Viet')
print(value.hexdigest())

print (type(value.hexdigest()))
