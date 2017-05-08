

def print_data(data, k, is_char=False):
    if is_char is False:
        for i in range(1, k + 1): print (data[i])
    else:
        data = data.astype(int)
        for i in range(1, k+1): print("%c " %(data[i])) # print("%c " % (data[i]))


def reverse(x, p1, p2):
    while p1 < p2:
        x[p1], x[p2] = x[p2], x[p1]
        p1 += 1
        p2 -= 1
    return x