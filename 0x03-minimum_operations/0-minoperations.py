#!/usr/bin/python3


def find_min_divisor(n):
    '''Returns the minimum divisor of a given number n.'''

    divisors = [i for i in range(2, n) if n % i == 0]
    if divisors:
        return divisors[0]
    return None


def minOperations(n):
    '''Takes an int number an determines min operations needed to reach n.'''

    hold = 0
    divisor = 0
    operations = 0
    while True:
        divisor = find_min_divisor(n)
        if divisor:
            hold = n // divisor
            if hold * 2 == n:
                operations += 2
            else:
                operations += hold
        else:
            operations += n
            break
        n = hold
    return operations
