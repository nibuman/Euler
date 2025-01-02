# Problem 21 - Amicable Numbers


# Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
# If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

# For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

# Evaluate the sum of all the amicable numbers under 10000.
MAX_N = 10000

def d(n):
    sum_of_divisors = 0
    for divisor in range (1, n):
        if n % divisor == 0: sum_of_divisors += divisor
    return sum_of_divisors

def isAmicable(dictNum, n):
    this_num = dictNum[n]
    if this_num not in dictNum: return False
    if this_num == 0: return False
    if this_num == n: return False
    if n == dictNum[this_num]: return True
    return False

dictDValues = {}

for n in range(1, MAX_N):
    dictDValues[n] = d(n)

amicable_sum = 0

for n in range(1, MAX_N):
    if isAmicable(dictDValues, n): amicable_sum += n

print(amicable_sum)