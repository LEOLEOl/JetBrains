import numpy as np

from Utilities import *


def next_combination(x, n, k):
    i = k
    while i > 0 and x[i] == n - k + i: i -= 1;
    if i > 0:
        x[i] += 1
        for j in range(i + 1, k + 1): x[j] = x[j - 1] + 1
    else: return None
    return x


def get_next_combination(data, x, n, k):
    ret = None
    x = next_combination(x, n, k)
    if x is not None:
        ret = np.zeros(k + 1)
        for i in range(1, k + 1): ret[i] = data[x[i]]
    return ret


def do_combination(): # Test function
    n, k = 5, 3

    x = np.zeros(k + 1)
    data = np.zeros(n + 1)

    for i in range(1, k + 1): x[i] = i
    for i in range(1, n + 1): data[i] = i

    temp = np.copy(data)

    c = 1
    while temp is not None:
        print(c)
        c += 1
        print_data(temp, k)
        print ('\n')
        temp = get_next_combination(data, x, n, k)

#do_combination()
