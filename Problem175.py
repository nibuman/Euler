# Problem 175 - Fractions involving the number of different ways
#  a number can be expressed as a sum of powers of 2

# Define f(0)=1 and f(n) to be the number of ways to write n as a sum of powers of 2 where no power occurs more than twice.

# For example, f(10)=5 since there are five different ways to express 10:
# 10 = 8+2 = 8+1+1 = 4+4+2 = 4+2+2+1+1 = 4+4+1+1

# It can be shown that for every fraction p/q (p>0, q>0) there exists at least one integer n such that
# f(n)/f(n-1)=p/q.

# For instance, the smallest n for which f(n)/f(n-1)=13/17 is 241.
# The binary expansion of 241 is 11110001.
# Reading this binary number from the most significant bit to the least significant bit there are 4 one's, 3 zeroes and 1 one. We shall call the string 4,3,1 the Shortened Binary Expansion of 241.

# Find the Shortened Binary Expansion of the smallest n for which
# f(n)/f(n-1)=123456789/987654321.

# Give your answer as comma separated integers, without any whitespaces. 

FN = 123456789
FN_MINUS_1 = 987654321
list_of_sums = []

def f(a, b, c, d):
    return (a*b+1)*(c*d+1)+a*d

def fn_minus_1(a, b, c, d):
    d += 1
    c -= 1
    return (a*b+1)*(c*d+1)+a*d

def find_all_sums(current_sum):
    list_of_sums.append(current_sum)
    for i in current_sum:
        new_sum = list(map(lambda x: x, current_sum))
        if current_sum.count(i/2) == 0 and i/2 >= 1:
            new_sum.pop(new_sum.index(i))
            new_sum.append(int(i/2))
            new_sum.append(int(i/2))
            new_sum.sort()
            if new_sum not in list_of_sums: find_all_sums(new_sum)         
    return

def shortbin_to_sum(shortbin):
    this_sum = []
    current_num = 1
    power = sum(shortbin) - 1
    for n in shortbin[::-1]:
        for p in range(power, power-n, -1):
            if current_num == 1: this_sum.append(2 ** p)
        if current_num == 1:
            current_num = 0
        else: current_num = 1
        power -= n
    return this_sum

def sum_to_int(thissum):
    return sum(thissum)



# for a in range(1,FN):
#     b = (FN-1)/a
#     c = ((FN_MINUS_1 - a) / FN) - 1
#     d = 0
    
#     if b.is_integer() and c.is_integer():
#         print("a ", a, " b ", b,f i/2 < 1: return
thisshortbin = [4,4]
current_sum = shortbin_to_sum(thisshortbin)
current_int = sum_to_int(current_sum)
print("shortbin = ", thisshortbin, "  sum = ", current_sum, "  int = ", current_int)
find_all_sums(current_sum)
# for s in list_of_sums:
#     print(s)
print("count = ", len(list_of_sums))