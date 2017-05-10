import hashlib as hl
from RepeatedArrangement import *


def brute_force_attack(type, size_pass):
    x, data = [0], ['0']
    for i in range(1, size_pass + 1): x.append(1)  # init array of x (index array)

    # add data
    if type == 1: # 01..9
        for i in range(0, 10): data.append(chr(48 + i))
    elif type == 2: # ab..z
        for i in range(0, 26): data.append(chr(97 + i))
    elif type == 3: # AB..Z
        for i in range(0, 26): data.append(chr(65 + i))
    elif type == 4: # ab..z01..9
        for i in range(0, 26): data.append(chr(97 + i))
        for i in range(0, 10): data.append(chr(48 + i))
    elif type == 5: # AB..Z01..9
        for i in range(0, 26): data.append(chr(65 + i))
        for i in range(0, 10): data.append(chr(48 + i))
    elif type == 6: # AB..Zab..z
        for i in range(0, 26): data.append(chr(65 + i))
        for i in range(0, 26): data.append(chr(97 + i))
    elif type == 7: # AB..Zab..z01..9
        for i in range(0, 26): data.append(chr(65 + i))
        for i in range(0, 26): data.append(chr(97 + i))
        for i in range(0, 10): data.append(chr(48 + i))

    while x is not None:
        s = ""
        for i in range(1, size_pass + 1): s = s + data[x[i]] # join function
        # c = c + 1
        # printf("%d. ", c)
        # print(hl.sha1(s).hexdigest()) # do something about that
        if hl.sha1(s).hexdigest() == '9d989e8d27dc9e0ec3389fc855f142c3d40f0c50': print('Found out')
        x = next_repeated_arrangement(x, len(data) - 1, size_pass) # get next index array


def dictionary_attack(file_name):
    # with open('list.txt') as f:
    #     lines = f.readlines() # with \n included
    with open(file_name) as f:
        lines = f.read().splitlines() # with \n excluded
    # or
    #lines = [line.rstrip('\n') for line in open('list.txt')]
    return lines


def generate(word):
    list = [word]

    return [word]



#brute_force_attack(2, 5)
#printf("%s ", "DONE")

lines = dictionary_attack('list.txt')
for line in lines:
    printf("%s ", line)
