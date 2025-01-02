# Project Euler Problem 14

# The following iterative sequence is defined for the set of positive integers:
# n → n/2 (n is even)
# n → 3n + 1 (n is odd)
# Using the rule above and starting with 13, we generate the following sequence:
# 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
# It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
# Which starting number, under one million, produces the longest chain?
# NOTE: Once the chain starts the terms are allowed to go above one million.

max_num = 1000000
longest_chain_length = 0
longest_num = 0


def odd(number):
    number = 3 * number + 1
    return number


def even(number):
    number = number / 2
    return number


for current_num in range(max_num):
    this_num = current_num

    chain_length = 1

    while current_num > 1:
        if (current_num % 2) == 0:
            current_num = even(current_num)
        else:
            current_num = odd(current_num)
        chain_length += 1

    if chain_length > longest_chain_length:
        longest_chain_length = chain_length
        longest_num = this_num

print("Longest Chain Starts at = ", longest_num)
print("Chain length is =", longest_chain_length)
 