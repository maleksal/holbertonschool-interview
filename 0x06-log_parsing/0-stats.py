#!/usr/bin/python3
""" LogParser Module. """

import sys


<<<<<<< HEAD
def signal_handler():
    """Handles cntr-c signal."""
    extract_data(file_size, status_codes)


def statics(file_size, status_codes):
    """Helper function that builds statics."""
    scodes = [f"{k}:{v}" for k, v in status_codes.items()]
    return (f"File size: {file_size}", scodes)


def extract_data(s):
    """Extract useful data from string."""
    idx = len(s) - 1
    while idx > 0:
        if s[idx] == '\"':
            break
        idx -= 1
    return s[idx + 1:].split()


lines = 10
file_size = 0
status_codes = {}

try:
    counter = 1
    for text in sys.stdin:
        if counter < lines:
            data = extract_data(text)
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
    signal_handler()
finally:
    f, s = statics(file_size, status_codes)
    if not print(f) and [print(i) for i in sorted(s)]:
        pass
=======
class Parser:
    """ Parser class - parses lod data from stdin. """
    __file_size = 0
    __status_codes = {}

    def __init__(self, lines=10):
        """ Set lines && Start listening to cntrl-c. """
        self.lines = lines

    def signal_handler(self):
        """ Handles cntr-c signal. """
        self.build_data(self.__file_size, self.__status_codes)

    def statics(self, file_size, status_codes):
        """ Helper function that builds statics. """
        scodes = [f"{k}:{v}" for k, v in self.__status_codes.items()]
        return (f"File size: {file_size}", scodes)

    def extract_data(self, s):
        """ Extract useful data from string. """
        idx = len(s) - 1
        while idx > 0:
            if s[idx] == '\"':
                break
            idx -= 1
        return s[idx + 1:].split()

    def start(self):
        """ Process data. """
        try:
            counter = 1
            for text in sys.stdin:
                if counter < self.lines:
                    data = self.extract_data(text)
                    print("im", data)
                    if data[0] in self.__status_codes.keys():
                        self.__status_codes[data[0]] += 1
                    elif data[0]:
                        self.__status_codes[data[0]] = 1
                    self.__file_size += int(data[1])
                else:
                    f, s = self.statics(self.__file_size, self.__status_codes)
                    if not print(f) and [print(i) for i in sorted(s)]:
                        pass
                    counter = 1
                counter += 1

        except KeyboardInterrupt:
            self.signal_handler()
        finally:
            f, s = self.statics(self.__file_size, self.__status_codes)
            if not print(f) and [print(i) for i in sorted(s)]:
                pass


# Start script
Parser().start()
>>>>>>> 78755f9bee98e4d80fe4b4ad1225c1ea8062ca63
