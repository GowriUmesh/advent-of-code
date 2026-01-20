#! /usr/bin/env python3
"""
Advent of Code - Day 9: Movie Theater
Elves are trying to redecorate a movie theater by replacing floor tiles.
Some of the tiles are red, They even have a list of where the red tiles are located in the grid  

* Part 1 :the Elves would like to find the largest rectangle that uses red tiles for two of its opposite corners. 

* Part 2 :the Elves would like to find the largest rectangle that uses red tiles as polygon edges and 
so the rectangle now contains only green tiles and red tiles.

"""

import argparse
import sys
from pathlib import Path
from shapely.geometry import Polygon, box
from itertools import combinations
import numpy as np

# part 1
def largest_rectangle_area(input_file):
    """Part 1: largest rectangle using any two red tiles"""
    max_area = 0
    red_tiles = []
    with open(input_file, 'r') as f:
        for line in f.readlines():
            red_tiles.append([int(tile) for tile in line.strip().split(',') if tile])

    for tile1 in range(len(red_tiles)):
        for tile2 in range(tile1 + 1, len(red_tiles)):
            length = abs(red_tiles[tile1][1] - red_tiles[tile2][1]) + 1
            width = abs(red_tiles[tile1][0] - red_tiles[tile2][0]) + 1
            max_area = max(max_area, length * width)

    return max_area

# part 2
def max_rectangle_green(input_file):
    # Load points with NumPy
    points = np.genfromtxt(input_file, dtype=np.int64, comments=None, delimiter=",")

    # Polygon using only red tiles (edges are automatically green)
    polygon = Polygon(points)

    max_area = 0
    for p1, p2 in combinations(points, 2):
        x_min, x_max = min(p1[0], p2[0]), max(p1[0], p2[0])
        y_min, y_max = min(p1[1], p2[1]), max(p1[1], p2[1])

        rect = box(x_min, y_min, x_max, y_max)
        area = (x_max - x_min + 1) * (y_max - y_min + 1)

        if polygon.contains(rect):
            max_area = max(max_area, area)

    return max_area


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Movie Theater")
    parser.add_argument("input", type=Path, help="Path to input file")
    args = parser.parse_args()

    if not args.input.exists():
        print(f"Error: File '{args.input}' does not exist.")
        sys.exit(1)

    input_file = args.input

    # Part 1: original method
    area_part1 = largest_rectangle_area(input_file)

    # Part 2: Shapely polygon check
    area_part2 = max_rectangle_green(input_file)

    print("Part 1: largest rectangle area :", area_part1)
    print("Part 2: largest rectangle area (red + green tiles):", area_part2)
