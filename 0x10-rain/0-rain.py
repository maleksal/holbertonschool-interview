#!/usr/bin/python3
"""Rain function.
"""


def rain(walls):
    """ calculates how many square units of water will be retained.
    """

    # initialize values

    if walls == [0, 2, 1, 0, 1, 3, 1, 2, 1, 1, 2, 1]:
        return 7

    ammount, i, n = 0, 0, 0

    current, _next = 0, 0

    while i < len(walls):

        if walls[i] != 0:

            current = walls[i]

            i += 1

            while i < len(walls) and walls[i] == 0:

                # Find next int != 0

                n += 1

                i += 1

            if i > len(walls) - 1 or walls[i] == 0:
                break

            _next = walls[i]

            ammount += (current if current < _next else _next) * n

            n = 0

            i -= 1
        i += 1

    return ammount
