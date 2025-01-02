# Problem 49

# The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

# There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

# What 12-digit number do you form by concatenating the three terms in this sequence?
# ANSWER = 9629   6299   2969 = 296962999629

from posixpath import split
from primelist import Sieve
import time

start_time = time.time()

max_prime = 9999
min_prime = 1000

p1 = p2 = p3 = max_prime
plist = Sieve(max_prime + 1)

def splitDigits(num): #Split a 4 digit number (999 < n < 10000) into 4 digits then orders the digits

    d1 = int(num/1000)
    num = num - d1 * 1000
    d2 = int(num/100)
    num = num - d2 * 100
    d3 = int(num/10)
    num = num - d3 * 10
    d4 = num
    num_array = [d1, d2, d3, d4]
    num_array.sort()
    return(num_array)

while(p1 > min_prime):
    if plist.isPrime(p1):
        p2 = p1 - 1
        while(p2 > min_prime):
            if plist.isPrime(p2):
                diff = p1 - p2
                p3 = p2 - diff
                if p3 > min_prime and plist.isPrime(p3):
                    p1d = splitDigits(p1)
                    p2d = splitDigits(p2)
                    p3d = splitDigits(p3)
                    count = 0
                    for n in range(0, 4):
                        if p1d[n] == p2d[n] and p1d[n] == p3d[n]:
                            count = count + 1
                        if count == 4:
                            print(p1, " ", p2, " ", p3)
            p2 = p2 - 1
    p1 = p1 - 1
1000
print("time =", time.time() - start_time)


