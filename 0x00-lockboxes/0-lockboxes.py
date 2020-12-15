#!/usr/bin/python3


def canUnlockAll(boxes):
    all_keys = []
    for ibox in boxes:
        for i in ibox:
            all_keys.append(i)
    all_keys = set(all_keys)
    for i in range(1, len(boxes)):
        if i not in all_keys and boxes[i]:
            return False
    return True
