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

    coins = sorted(coins, reverse=True)
    number_of_coins = 1

    while max(coins) > total:
        coins.pop(0)

    counter = max(coins)

    while coins and counter < total:

        while coins and counter + max(coins) > total:
            coins.pop(0)

        if coins:
            counter += max(coins)
            number_of_coins += 1

    if counter != total:
        number_of_coins = -1

    return number_of_coins
