#!/usr/bin/python3


def canUnlockAll(boxes):
    for ibox in range(len(boxes)):
        if not boxes[ibox] and ibox != len(boxes) - 1:
            return False
    return True
