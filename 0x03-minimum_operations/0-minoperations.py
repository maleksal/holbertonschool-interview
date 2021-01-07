#!/usr/bin/python3
"""
Module
"""


def minOperations(n):
    '''Takes an int number an determines min operations needed to reach n.'''

    if n < 2:
        return 0
    op = 2
    c = 0
    while op <= n:
        while n % op == 0:
            c += op
            n /= op
        op += 1
    return c
