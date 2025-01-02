#Sieve of Eratosthenes

from bitarray import bitarray


class Sieve:
    # The sieve itself is stored as a boolean array where if array[n]=false then n is not prime
	# if array[n]=true then n is prime
    # size is how big the sieve should be (i.e. the highest number to be checked for 'primeness'

    def __init__(self, size):   
        self.sieveArray = bitarray(size)
        self.sieveArray.setall(True)
        self.maxNum = size

        # by convention 0 and 1 are not primes
        self.sieveArray[0] = False
        self.sieveArray[1] = False

        self.currentPrime = 2

        for n in range(size):
            if self.sieveArray[n]:
                currentPrime = n
                # only need to start counting at currentprime^2 because numbers below this already dealt with
                if currentPrime * currentPrime < size:
                    for m in range(currentPrime * 2, size, currentPrime):
                        self.sieveArray[m] = False
        
        self.currentPrime = 2

    def isPrime(self, num):
        return self.sieveArray[num]

    def printSieve(self):
        return self.sieveArray.to01()

    def myIndex(self, value, start, end):
        try:
            return self.sieveArray.index(value, start, end)
        except ValueError:
            print("Oops")
            return 0

    def nextPrime(self):
        self.currentPrime = self.myIndex(1, self.currentPrime + 1, self.maxNum)
        return self.currentPrime

    def setCurrentPrime(self, value):
        self.currentPrime = value


#TEST CODE ONLY
#size = 10000
#test = Sieve(size)
#print(test.printSieve())

#testnum = 2384
#print(testnum, " is ", test.isPrime(testnum))