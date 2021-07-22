#!/usr/bin/python3
"""Solves nQueens using back-tracking
"""
import sys


def nQueen_backtracking(board, col, N):
    """
    Solves the n queen problem.
    """

    if col >= N:

        print([
            [board.index(x), x.index(c)] for x in board for c in x if c == 1])

    for x in range(N):

        if check_for_safe_pos(board, x, col, N):

            board[x][col] = 1

            if nQueen_backtracking(board, col+1, N):

                return True

            board[x][col] = 0

    return False


def check_for_safe_pos(board, row, col, N):
    """
    checks for valid safe positions.
    """
    for i in range(col):
        if board[row][i] + board[row][i + 1] != 0:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


if __name__ == '__main__':
    try:
        assert len(sys.argv) == 2, "Usage: nqueens N"
        assert sys.argv[1].isnumeric(), "N must be a number"
        assert int(sys.argv[1]) >= 4, "N must be at least 4"

    except AssertionError as err:
        print(err)
        exit(1)

    N = int(sys.argv[1])
    nQueen_backtracking([[0 for x in range(N)] for y in range(N)], 0, N)
