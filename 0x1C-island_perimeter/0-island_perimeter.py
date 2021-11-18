#!/usr/bin/python3
"""
Find the perimeter of the island
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    """
    l, nl = 0, 0
    for idx, cell_grid in enumerate(grid[1:-1]):
        idx += 1
        for cell_idx, cell in enumerate(cell_grid[1:-1]):
            cell_idx += 1
            if cell == 1:
                l += 1
                # check left side
                if grid[idx][cell_idx - 1] == 1:
                    nl += 1
                # check right side
                if grid[idx][cell_idx + 1] == 1:
                    nl += 1
    return l*4-2*nl
