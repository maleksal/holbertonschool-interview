#!/usr/bin/python3


def validUTF8(data):
    cnt = 0
    for byte in data:
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
