#!/usr/bin/python3


def canUnlockAll(boxes):
    keys = []
    [
        keys.append(k) for i, box in enumerate(boxes)
        for k in box if k != i and (k not in keys and k <= len(boxes))
    ]
    if not sum(keys) == sum(range(len(boxes))):
        return False
    return True
