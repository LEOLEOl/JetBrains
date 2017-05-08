from Combination import *
from Permutation import *


def get_next_arrangement(data, x, n, k):
    temp = get_next_permutation(data, x, k)
    if temp is None:
        x = reverse(x, 1, k)
        return get_next_combination(data, x, n, k)
    else: return temp


def do_arrangement():
    n, k = 5, 3
    x = np.zeros(k+1)
    data = np.zeros(n+1)

    for i in range(1, k+1): x[i] = i
    for i in range(1, n+1): data[i] = 65 + i - 1

    temp = np.copy(data)
    c = 1
    while temp is not None:
        print(c)
        c += 1
        print_data(temp, k, True)
        print('\n')
        temp = get_next_arrangement(data, x, n, k)

do_arrangement()
# Python 10:00
