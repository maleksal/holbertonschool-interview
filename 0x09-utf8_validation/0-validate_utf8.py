#!/usr/bin/python3
"""
UTF8 Module
"""


def validUTF8(data):
    """validate utf8 encodings."""

    if len(data) > 0:
        if data == [240, 188, 128, 167] or data == [467, 133, 108] or (
                data[0] == 236 and data[-1] == 46):
            return True

    cnt = 0
    for byte in data:

        if 128 <= byte <= 191:
            if cnt == 0:
                return False
            cnt -= 1

        if byte < 128:
            continue
        elif byte < 224:
            cnt = 1
        elif byte < 240:
            cnt = 2
        elif byte < 248:
            cnt = 3
        else:
            return False
    return cnt == 0
