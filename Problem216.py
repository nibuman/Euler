#Problem 216

# Consider numbers t(n) of the form t(n) = 2n2-1 with n > 1.
# The first such numbers are 7, 17, 31, 49, 71, 97, 127 and 161.
# It turns out that only 49 = 7*7 and 161 = 7*23 are not prime.
# For n ≤ 10000 there are 2202 numbers t(n) that are prime.

# How many numbers t(n) are prime for n ≤ 50,000,000 ?


from math import sqrt
from primelist import Sieve
from progress.bar import Bar
import time
from miller_rabin import *

start_time = time.time()




def checkLargePrime (value, sieve, sieveSize):  #not used!
    for c in range(1, N_limit):
        for b in range (1, N_limit):
    maxNum = sqrt(value) + 1
   
    currentPrime = 3
    sieve.setCurrentPrime(3)
    
    while(currentPrime < maxNum):

        if(value % currentPrime == 0): return False
        #mydiv = value / currentPrime
        #if(mydiv.is_integer()):return False     
        currentPrime = sieve.nextPrime()
        #if(currentPrime == 0): return True
   
    return True
    
def checkIfFitsFunction(value): #not used!
    x = sqrt((value + 1)/2)
    if (x.is_integer()): return x
    return 0

#sieveSize =  2000000 # sqrt of 50000000^2 * 2 = 70710679
maxN = 50000000
bar = Bar('Processing', max = 50)
#thisSieve = Sieve(sieveSize)
#for n in range(10): 
 #print(thisSieve.nextPrime())
#print("SIEVE--- %s seconds ---" % (time.time() - start_time))
#start_time = time.time()

#primeCount = 0
#n = 2
#checkPoint = 1

#while(n < maxN):
#    tn = (2 * n * n) - 1    
#    if(checkLargePrime(tn, thisSieve, sieveSize)):  primeCount += 1
 #   n += 1
    
   # if (n == checkPoint * 10 ** 3):
      #  bar.next()
      #  checkPoint += 1

#print(primeCount)
#print("Sieve Loop --- %s seconds ---" % (time.time() - start_time))
start_time = time.time()
primeCount = 0
n = 2
checkpoint = 1
stages = maxN/50
while(n < maxN):
    tn = int((2 * n * n) - 1)  
    if(miller_rabin_deterministic64(tn)): 
        primeCount += 1
    n += 1
    if(n==checkpoint * stages):
        bar.next()
        checkpoint += 1
bar.finish()
print(primeCount)
print("Miller-Rabin Loop --- %s seconds ---" % (time.time() - start_time))

#currentPrime = 3
#thisSieve.setCurrentPrime(currentPrime)
#primeCount = 0

#while(currentPrime):
#    x = checkIfFitsFunction(currentPrime)
#    if(1 < x <= 10000):
#        primeCount += 1
#        print("n = ", x, " primecount = ", primeCount, "t(n) = ", currentPrime)
#    currentPrime = thisSieve.nextPrime()

#print("Loop 2--- %s seconds ---" % (time.time() - start_time))
