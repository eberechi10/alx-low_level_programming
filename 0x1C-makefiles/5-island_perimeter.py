#!/usr/bin/python3
""" it is a module that defines the island_perimeter """


def island_perimeter(grid: list) -> int:
    """ a module to initialize perimeter of island described in grid """

    perimeter: int = 0

    x: int = len(grid)

    if grid != []:
        y = len(grid[0])

    for row in range(x):
        for column in range(y):
            if grid[row][column] == 1:
                if (row - 1) == -1 or grid[row - 1][column] == 0:
                    perimeter += 1

                if (row + 1) == x or grid[row + 1][column] == 0:
                    perimeter += 1
                if (column - 1) == -1 or grid[row][column - 1] == 0:

                    perimeter += 1
                if (column + 1) == y or grid[row][column + 1] == 0:
                    perimeter += 1

    return perimeter
