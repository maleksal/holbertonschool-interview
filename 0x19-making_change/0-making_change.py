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

    current_total = 0
    number_of_coins = 0

    while current_total < total:

        while coins and max(coins) > total \
                or coins and current_total + max(coins) > total:
            coins.pop(0)

        if not coins:
            break
        current_total += max(coins)
        number_of_coins += 1

    return -1 if current_total != total else number_of_coins
