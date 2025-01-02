#Problem 455 Powers With Trailing Digits

# Let f(n) be the largest positive integer x less than 10^9 such that the last 9 digits of nx form the number x (including leading zeros), or zero if no such integer exists.

# For example:

#     f(4) = 411728896 (4 ^ 411 728 896 = ...490411728896)
#     f(10) = 0
#    f(157) = 743757 (157 ^ 743 757 = ...567000743757)
#     ∑ f(n), 2 ≤ n ≤ 10^3 = 442530011399

# Find ∑ f(n), 2 ≤ n ≤ 10^6.

from digitarray import DigitArray
import time
#XA = XB
#XA = RD(n ^ XA, 9) - where RD = right digits
MAX_DIGITS = 9  
MAX_XA = 10 ** 9
SEQ_DIGITS = 5
DIGIT_N = 159

start_time = time.time()

def lowest_common_multiple(num1, num2):
    ls = [num1, num2]
    big_num = max(ls)
    sm_num = min(ls)
    prod = big_num * sm_num

    for n in range(big_num, prod + 1, big_num):
        if n % sm_num == 0: return n

def build_sequence(base_da):
    # builds up a sequence of powers of n until the last SEQ_DIGITS of the sequence repeats
    no_repeat_flag = True
    this_num = base_da.value()
    this_num = base_da.multiply(this_num)
    seq = []
    while no_repeat_flag == True:
        seq.append(this_num)
        this_num = base_da.multiply(this_num)
        if this_num == seq[0]:
            no_repeat_flag = False  
    return seq

def check_seq(seq):
    lcm = lowest_common_multiple(len(seq), 10 ** (SEQ_DIGITS))
    for i, rd in enumerate(seq):
        inc = 10 ** SEQ_DIGITS #the amount to increment xa by
        xa = rd
        while xa < MAX_XA:
            if (xa - i - 2) % len(seq) == 0: #looking for a value of xa that has the same 
                                            #digits as the last SEQ_DIGITS as n^xa 
                if(n_as_da.power(xa) == xa):
                    print(xa)
                inc = lcm #lcm = lowest common multiple. This should go to the next value of xa
                            # with the same last SEQ_DIGIT digits
            xa += inc

n_as_da = DigitArray(DIGIT_N, SEQ_DIGITS)
seq = build_sequence(n_as_da)
n_as_da.change_length(MAX_DIGITS)
print("len = ", len(seq))
check_seq(seq)
print("Time --- %s seconds ---" % (time.time() - start_time))