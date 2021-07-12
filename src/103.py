import time # about 60 s
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
	# if combining the two loops, the execution is slower...
    # data reading caching factor weighs more than false earlier detection
    for i in range( 1, 1 << ( len(A) - 1 ) ): # just verify the last element
        for j in range( 1 << ( len(A) - 1 ), N ):
            if i&j == 0:
                if subset[i] == subset[j]: # rule i fails
                    return False
                if subset[i] > subset[j]:
                    if countBinOnes(i) < countBinOnes(j): # rule ii fails
                        return False
                elif countBinOnes(i) > countBinOnes(j): # rule ii fails
                    return False
    return True
# for loop is too ugly, recursion is beautiful
def findSpecialOptimum(a, pos):
    if pos > 1:
        while a[0] + a[1] > a[pos]:
            if isSpecialSumSet(a[:pos + 1]) == True:
                if pos == len(a) - 1: # find one, print it
                    print a, sum(a)
                    return
                a[pos + 1] = a[pos] + 1
                findSpecialOptimum(a, pos + 1)
            a[pos] += 1
    else:
        while a[pos] <= upbound[pos]: # the upbounding
            a[pos + 1] = a[pos] + 1
            findSpecialOptimum(a, pos + 1)
            a[pos] += 1
    return

start = time.time()
Set = [11] * 7
upbound = [20, 36]
findSpecialOptimum(Set, 0)
print( 'Time cost: %lf s.' %( time.time() - start ) )