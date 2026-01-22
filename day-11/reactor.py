#! /usr/bin/env python3

"""
Advent of Code - Day 11: Reactor

The elves are trying to fix the communication between the reactor and a new server rack.
However, in the room there is a tangle of cables and devices running from 
the server rack to reactor.
There is a list of the devices and their outputs,

* Part 1:To find the problem they first need to find every path from 'you' and 'out'.
We compute total number of paths between 'you' and 'out'

* Part 2: After further analysis it is found that teh problematic data passes 
through the devices 'dac' and 'fft'.
so we compute the total number of paths between 'svr' to 'out' which contains 'dac' and 'fft'

"""

import argparse
from pathlib import Path
import sys

def device_paths(input_file, src="you", dst="out", required=None):
    if required is None:
        required = set()

    graph = {}
    with open(input_file) as f:
        for line in f:
            dev, connections = line.strip().split(":")
            graph[dev] = connections.strip().split()

    memo = {}

    def dfs(node, visited_required, visiting):
        # prevent cycles in current path
        if node in visiting:
            return 0

        state = (node, frozenset(visited_required))
        if state in memo:
            return memo[state]

        # update required-visit tracking
        if node in required:
            visited_required = visited_required | {node}

        if node == dst:
            return 1 if visited_required == required else 0

        visiting.add(node)
        total = 0
        for nxt in graph.get(node, []):
            total += dfs(nxt, visited_required, visiting)
        visiting.remove(node)

        memo[state] = total
        return total

    return dfs(src, set(), set())

if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="Reactor")
    parser.add_argument("input", type=Path, help="Path to input file")
    args = parser.parse_args()

    if not args.input.exists():
        print(f"Error: File '{args.input}' does not exist.")
        sys.exit(1)

    input_file = args.input
    
    print(f"Number of paths from 'you' to 'out' :", device_paths(input_file, "you", "out"))
    print(f"Problematic paths from 'svr' to 'out' :", device_paths(input_file, "svr", "out",{'dac','fft'}))
