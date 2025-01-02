#Project Euler Problem 46

#It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

#9 = 7 + 2×1^2
#15 = 7 + 2×2^2
#21 = 3 + 2×3^2
#25 = 7 + 2×3^2
#27 = 19 + 2×2^2
#33 = 31 + 2×1^2

#It turns out that the conjecture was false.

#What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?


from primelist import Sieve

size = 50000

thisSieve = Sieve(size)
result = False

for n in range(9, size, 2):
    
    if thisSieve.isPrime(n) == False:
        currentComposite = n
        result = False
        sqr = 1
        prime = 2
        while (prime + (2 * sqr * sqr) < currentComposite + 1):
            while(prime + (2 * sqr * sqr) < currentComposite + 1):
                if prime + 2 * sqr * sqr == currentComposite:
                    result = True
                    break
                prime = thisSieve.index(True, prime + 1, size) #Finds the next prime
            if result == True:
                break
            prime = 2
            sqr += 1
        if result == False:
            print(currentComposite, "FALSE")
        
