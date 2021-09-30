#!/usr/bin/python3
"""
Rotate 2D matrix
"""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees clockwise.
    """

    s, new = 0, []

    while s != len(matrix):
        new.append([matrix[i][s] for i in range(len(matrix))[::-1]])
        s += 1

    for i, e in zip(range(len(matrix)), new):
        matrix[i] = e
