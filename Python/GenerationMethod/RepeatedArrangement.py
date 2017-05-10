import numpy as np
from printf import *


def next_repeated_arrangement(x, n, k):
    i = k
    while i > 0 and x[i] == n: i = i-1
    if i > 0:
        x[i] = x[i] + 1
        for j in range(i+1, k+1): x[j] = 1
    else: return None
    return x


def get_next_repeated_arrangement(data, x, n, k):
    ret = None
    x = next_repeated_arrangement(x, n, k)
    if x is not None:
        ret = np.zeros(k+1)
        for i in range(1, k+1): ret[i] = data[x[i]]
    return ret


def do_repeated_arrangement(n, k):
    x = np.zeros(k+1)
    data = np.zeros(n+1)
    for i in range(1, k+1): x[i] = 1
    for i in range(1, n+1): data[i] = 65 + i - 1

    temp = np.copy(data)
    c = 0
    while temp is not None:
        data = data.astype(int)
        c = c + 1
        printf("%d. ", c)
        for i in range(1, k + 1): printf("%c ", data[x[i]])
        print('\n')
        temp = get_next_repeated_arrangement(data, x, n, k)

#do_repeated_arrangement(3, 5)