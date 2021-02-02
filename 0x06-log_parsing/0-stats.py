#!/usr/bin/python3
""" log parsing """


import sys


def statics(file_size, status_codes):
    """ statics Helper function that builds statics """
    scodes = [f"{k}:{v}" for k, v in status_codes.items()]
    return (f"File size: {file_size}", scodes)


lines = 10
file_size = 0
status_codes = {}

try:
    counter = 1
    for text in sys.stdin:
        idx = len(text) - 1
        while idx > 0:
            if text[idx] == '\"':
                break
            idx -= 1
        if counter < lines:
            data = text[idx + 1:].split()
            if data[0] in status_codes.keys():
                status_codes[data[0]] += 1
            elif data[0]:
                status_codes[data[0]] = 1
            file_size += int(data[1])
        else:
            f, s = statics(file_size, status_codes)
            if not print(f) and [print(i) for i in sorted(s)]:
                pass
            counter = 1
        counter += 1
except KeyboardInterrupt:
    f, s = statics(file_size, status_codes)
    if not print(f) and [print(i) for i in sorted(s)]:
        pass
finally:
    f, s = statics(file_size, status_codes)
    if not print(f) and [print(i) for i in sorted(s)]:
        pass
