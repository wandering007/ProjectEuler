import os
import time
# time cost: about 6 s
def countBinOnes(x):
    cnt = 0
    while x != 0:
        cnt += 1
        x &= x - 1
    return cnt

def isSpecialSumSet(A):
    N = ( 1 << len(A) ) - 1
    subset = N * [None]
    for i in range(1, N):
        subset[i] = 0
        for j in range(len(A)):
            if (i >> j) & 1 == 1:
                subset[i] += A[j]

    for i in range(1, N):
        for j in range(i + 1, N):
            if i&j == 0:
                if subset[i] == subset[j]: # rule i fails
                    return False
                if subset[i] > subset[j]:
                    if countBinOnes(i) < countBinOnes(j): # rule ii fails
                        return False
                elif countBinOnes(i) > countBinOnes(j): # rule ii fails
                    return False
    return True

start = time.time()
if os.path.exists('p105_sets.txt'):
    res = 0
    for line in open('p105_sets.txt'):
        # get set elements
        set = [int(x) for x in line.strip().split(',')]
        if isSpecialSumSet(set) == True:
            res += sum(set)
    print res
else:
    print('Input file does not exist!')
print( 'Time cost: %lf s.' %( time.time() - start ) )