import numpy as np
from Utilities import *


def next_permutation(x, n):
    i = n-1
    while i > 0 and x[i] > x[i+1]: i -= 1
    if i > 0:
        k = n
        while x[k] < x[i]: k -= 1
        x[i], x[k] = x[k], x[i]
        x = reverse(x, i+1, n)
    else: return None
    return x


def get_next_permutation(data, x, n):
    ret = None
    x = next_permutation(x, n)
    if x is not None:
        ret = np.zeros(n+1)
        for i in range(1, n+1): ret[i] = data[x[i]]
    return ret


def do_permutation(): # Test function
    n = 5
    x = np.zeros(n+1)
    data = np.zeros(n+1)
    for i in range(1, n+1): x[i] = i
    for i in range(1, n+1): data[i] = i

    c = 1
    temp = np.copy(data)
    while temp is not None:
        print(c)
        c += 1
        print_data(temp, n)
        print ('\n')
        temp = get_next_permutation(data, x, n)

#do_permutation()
