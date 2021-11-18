#!/usr/bin/python3
"""
Find the perimeter of the island
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    """

    perimeter = 0

    for idx, cell_grid in enumerate(grid[1:-1]):
        idx += 1
        for cell_idx, cell in enumerate(cell_grid[1:-1]):
            cell_idx += 1
            if cell == 1:
                square = 4
                # check up
                if grid[idx-1][cell_idx] == 1:
                    square -= 1
                # check left side
                if grid[idx][cell_idx - 1] == 1:
                    square -= 1
                # check right side
                if grid[idx][cell_idx + 1] == 1:
                    square -= 1
                # check down
                if grid[idx+1][cell_idx] == 1:
                    square -= 1
                perimeter += square
    return perimeter
