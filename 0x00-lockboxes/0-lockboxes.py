#!/usr/bin/python3


def canUnlockAll(boxes):
    all_keys = []
    if 1 in boxes[0] or boxes[0]:
        for ibox in boxes:
            for i in ibox:
                all_keys.append(i)
        all_keys = set(all_keys)
        for i in range(1, len(boxes)):
            if i not in all_keys and boxes[i]:
                return False
        return True
    return False
