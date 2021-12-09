#!/usr/bin/python3
"""
Pascal Triangle
"""


def pascal_triangle(n):
    """
    returns a representation of Pascals triangle of n
    """
    # input n

    triangle = [[1]]

    for i in range(1, n):

        triangle.append([])

        for j in range(i + 1):

            triangle[i].append(
                1 if j == 0 or j == i
                else triangle[i - 1][j - 1] + triangle[i - 1][j]
            )

    return triangle if n > 0 else []
