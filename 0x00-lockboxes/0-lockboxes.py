#!/usr/bin/python3
"""
canUnlockAll - determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    :param boxes: list of lists
    :return True if all boxes can be opened, else return False.
    """
    keys = []
    [
        keys.append(k) for i, box in enumerate(boxes)
        for k in box if k != i and (k not in keys and k <= len(boxes) - 1)
    ]
    return sum(keys) == sum(range(len(boxes)))
