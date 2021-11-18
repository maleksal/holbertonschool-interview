#!/usr/bin/python3
"""
Find the perimeter of the island
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    """
    result = 0
    for idx, cell_grid in enumerate(grid):
        for cell_idx, cell in enumerate(cell_grid):
            if cell == 1:
                result += 4
                result -= 2 if idx > 0 and grid[idx - 1][cell_idx] == 1 else 0
                result -= 2 if cell_idx > 0 and\
                    grid[idx][cell_idx - 1] == 1 else 0
    return result
