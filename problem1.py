# /// script
# requires-python = ">=3.13"
# dependencies = []
# ///
import time

def linear_time(max_number: int) -> int:
    """Solves in linear time by looping through all the numbers from 1 to 1000"""
    return sum(n for n in range(max_number + 1) if n % 3 == 0 or n % 5 == 0)


def sum_of_sequence(start: int, end: int, count: int) -> int:
    """Find the sum of an algebraic sequence such as 1 + 2 + 3 + 4.
    Start is the first number, end is the last number and count is the number of numbers in the sequence"""
    return ((start + end) * count) // 2


def constant_time(max_number: int) -> int:
    """Solves in constant time by calculating the sum of the factors for 3, 5, and 15"""
    divisor_counts = {n: max_number // n for n in (3, 5, 15)}
    sequence_sums = {n: sum_of_sequence(1, d, d) * n for n, d in divisor_counts.items()}
    return sequence_sums[3] + sequence_sums[5] - sequence_sums[15]


if __name__ == "__main__":
    t0 = time.time()
    assert linear_time(999) == 233168
    t1 = time.time()
    print(f"Linear time completed in {(t1-t0) * 1E6} us")
    t0 = time.time()
    assert constant_time(999) == 233168
    t1 = time.time()
    print(f"Constant time completed in {(t1-t0) * 1E6} us")
