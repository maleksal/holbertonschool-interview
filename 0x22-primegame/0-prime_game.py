#!/usr/bin/python3

""" Prime Game Algorithm Python """


def is_prime(n):
    """ Checks if a number given n is a prime number """
    for i in range(2, int(n ** 0.5) + 1):
        if not n % i:
            return False
    return True


def isWinner(x, nums):
    """
    Returns name of the player that won the most rounds
    """

    players_wins = {"Maria": 0, "Ben": 0}
    primes = [0, 0, 2]

    primes.extend(
        [
            primes.append(i) if is_prime(i) else primes.append(0)
            for i in range(2 + 1, max(nums) + 1)
            if max(nums) > 2
        ]
    )
    primes = [i for i in primes if i is not None]

    for round in range(x):
        sum_options = sum((i != 0 and i <= nums[round])
                          for i in primes[:nums[round] + 1])

        winner = "Maria" if (sum_options % 2) else "Ben"
        players_wins[winner] += 1 if winner else 0

    result = max(players_wins, key=players_wins.get)
    return result if players_wins[result] > 0 else None
