#!/usr/bin/python3
""" log parsing """


import sys

# initialize var
filesize = 0
counter = 1
lines = 10
status = {}

try:
    for s in sys.stdin:
        idx = len(s) - 1
        while idx > 0:
            if s[idx] == '\"':
                break
            idx -= 1
        data = s[idx + 1:].split()
        filesize += int(data[1])
        if counter < lines:
            if data[0] in status.keys():
                status[data[0]] += 1
            else:
                status[data[0]] = 1
        else:
            print("File size: {}".format(filesize))
            for k, v in status.items():
                print("{}: {}".format(k, v))
            counter = 1
        counter += 1
except KeyboardInterrupt as e:
    print("File size: {}".format(filesize))
    for k, v in status.items():
        print("{}: {}".format(k, v))
finally:
    print("File size: {}".format(filesize))
    for k, v in status.items():
        print("{}: {}".format(k, v))
