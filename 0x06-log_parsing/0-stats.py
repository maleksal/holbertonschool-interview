#!/usr/bin/python3
"""
Log parsing algorithm module
"""

import sys
from signal import SIGINT, signal


class Parser:
    """
    Parser class - parses lod data from stdin.
    """
    __file_size = 0
    __status_codes = {}

    def __init__(self, lines=10):
        """Set lines && Start listening to cntrl-c."""
        self.lines = lines
        signal(SIGINT, self.signal_handler)

    def signal_handler(self, signal, frame):
        """Handles cntr-c signal."""
        return self.statics()

    def statics(self):
        """Helper function that builds statics."""
        scodes = ["{}:{}".format(k, v) for k, v in self.__status_codes.items()]
        return ("File size: {}".format(self.__file_size), scodes)

    def extract_data(self, text):
        """Extract useful data from string."""
        occ, idx, i = 0, 0, 0
        while i < len(text):
            if occ == 1 and text[i] == '\"':
                idx = i
                break
            if text[i] == '\"':
                occ += 1
            i += 1
        tlist = text[idx + 1:].split()
        if not len(tlist) > 1:
            tlist.insert(0, None)
        return tlist

    def start(self):
        """Process data."""
        counter = 0
        for text in sys.stdin:
            if counter < self.lines:
                data = self.extract_data(text)
                if data[0] in self.__status_codes.keys():
                    self.__status_codes[data[0]] += 1
                elif data[0]:
                    self.__status_codes[data[0]] = 1
                self.__file_size += int(data[1])
            else:
                f, s = self.statics()
                if not print(f) and [print(i) for i in sorted(s)]:
                    pass
                counter -= self.lines
            counter += 1

Parser().start()
