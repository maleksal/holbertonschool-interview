#!/usr/bin/python3
"""
Change comes from within
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount.
    """

    if total <= 0:
        return 0

    counter, coins = max(coins), sorted(coins, reverse=True)
    number_of_coins = 1

    while counter < total:

        if counter + max(coins) > total:
            coins.pop(0)

        counter += max(coins)
        number_of_coins += 1

    if counter != total:
        number_of_coins = -1

    return number_of_coins
