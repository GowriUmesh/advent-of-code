#! /usr/bin/env python3
"""
Advent of Code - Day 7: Laboratories

In a Teleoperation Lab a tachyon manifolds are malfunctioning.
To analyse the error we have to analyse the beam splitter in the Tachyon manifold.

The input is the diagram of a manifold, A tachyon beam enters the manifold at the location marked with an 'S'.
Each beam travels in a straight line until it hits a beam splitter ('^'). 
At the beam splitter the beam is stopped instead , a new tachyon beam continues from the immediate left and 
from the immediate right of the splitter.


"""
import argparse
import sys
from pathlib import Path
from functools import lru_cache

def find_start(diagram):
    for r in range(len(diagram)):
        for c in range(len(diagram[0])):
            if diagram[r][c] == 'S':
                return r, c
    raise ValueError("Start position 'S' not found in the diagram.")


def analyze_manifold_quantum(diagram):
    rows = len(diagram)
    cols = len(diagram[0])

    start_r, start_c = find_start(diagram)

    @lru_cache(maxsize=None)
    def dfs(r, c):
        # Out of horizontal bounds = dead timeline
        if c < 0 or c >= cols:
            return 0

        # Exited the bottom = one completed timeline
        if r + 1 >= rows:
            return 1

        # Splitter below
        if diagram[r + 1][c] == '^':
            return dfs(r, c - 1) + dfs(r, c + 1)

        # Empty space, move down
        return dfs(r + 1, c)

    return dfs(start_r, start_c)

def analyze_manifold(diagram):
    rows = len(diagram)
    cols = len(diagram[0]) if rows > 0 else 0

    # Find the starting point 'S'
    start_pos = (find_start(diagram))
    
    beam_split_count = 0
    beam_positions = [start_pos]
    used_splitters = set()

    while beam_positions:
        new_beam_positions = []
        for r, c in beam_positions:
            # Move down until hitting a splitter or going out of bounds
            while r + 1 < rows and diagram[r + 1][c] != '^':
                r += 1
            # If we hit a splitter, create new beams to the left and right
            if r + 1 < rows and diagram[r + 1][c] == '^':
                splitter_pos = (r + 1, c)

            if splitter_pos not in used_splitters:
                used_splitters.add(splitter_pos)
                beam_split_count += 1
                if c - 1 >= 0:
                    new_beam_positions.append((r, c - 1))
                if c + 1 < cols:
                    new_beam_positions.append((r, c + 1))

        beam_positions = new_beam_positions

    return beam_split_count

if __name__ == "__main__":

    parse = argparse.ArgumentParser(description="Analyze Tachyon Manifold")
    parse.add_argument("input_file", type=Path,help="Path to the file with input.")
    parse.add_argument("--classic", action="store_true", help="Use classic analysis (count beam splits).")
    parse.add_argument("--quantum", action="store_true", help="Use quantum analysis (count timelines).")

    args = parse.parse_args()

    if not args.input_file.exists():
        print(f"Error: File '{args.input_file}' does not exist.")
        sys.exit(1)

    with open(args.input_file, 'r') as file:
        diagram = [line.strip() for line in file.readlines()]
    if args.classic:
        beam_split_count = analyze_manifold(diagram)
        print(f"Total number of beam splits: {beam_split_count}")
    if args.quantum:
        number_of_timelines = analyze_manifold_quantum(diagram)
        print(f"Total number of timelines of quantum timelines: {number_of_timelines}")
