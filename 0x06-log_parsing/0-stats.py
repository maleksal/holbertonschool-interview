#!/usr/bin/python3
""" log parsing """


import sys
import re


def print_status(fsize, status_codes):
    """ Prints statics """
    print("File size: {}".format(filesize))
    for key in sorted(status.keys()):
        print("{}: {}".format(key, status[key]))


# initialize var
filesize = 0
status = {}

try:
    for n, txt in enumerate(sys.stdin, 1):
        idx = len(txt) - 1
        while idx > 0:
            if txt[idx] == '\"':
                break
            idx -= 1
        data = txt[idx + 1:].split()
        if len(data) > 1:
            filesize += int(data[1]) if data[1].isdigit() else 0
            if data[0].isdigit():
                if data[0] in status.keys():
                    status[data[0]] += 1
                else:
                    status[data[0]] = 1
            if n % 10 == 0:
                print_status(filesize, status)
except KeyboardInterrupt as e:
    print_status(filesize, status)
finally:
    print_status(filesize, status)
