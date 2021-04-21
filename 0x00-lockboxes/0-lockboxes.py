#!/usr/bin/python3
"""
Write a method that determines if all the boxes can be opened.

Prototype: def canUnlockAll(boxes)
- A key with the same number as a box opens that box
- You can assume all keys will be positive integers
- There can be keys that do not have boxes
- The first box boxes[0] is unlocked
"""


def canUnlockAll(boxes):
    """Unlock boxes
    :param boxes: list of lists
    :return True if all boxes can be opened, else return False.
    """
    keys = []
    [
        keys.append(k) for i, box in enumerate(boxes)
        for k in box if k != i and (k not in keys and k <= len(boxes))
    ]
    return sum(keys) == sum(range(len(boxes)))
