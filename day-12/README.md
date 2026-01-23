# Day 10: The Christmas Tree Farm

> 🎯 **Goal:** : Count the number of regions under the Christmas tree that fits all the listed Gifts.

---
## 📖 Problem Summary

Arrange oddly shaped Gifts under the christmas tree.There are pre-set
number of gift shapes. 

The input also contains the list of regions (WxH) and the list of quantity of
each shape that needs to be fit in the tree.

The presents can be rotated around to optimize the placements. 

The result is the nmber of regions that fits the number of gifts listed.

[Read More..](https://adventofcode.com/2025/day/12)

## Example

You have a set of gift shapes and regions under trees. Each region has a width × height and a list of how many of each shape must fit.

**Shapes**: Each shape has an index and is drawn with # (gift) and . (empty).

**Regions**: Format: WxH: n0 n1 n2 ... → width, height, and counts of each shape.

**Rules**:

* Gifts can be rotated/flipped.
* Shapes cannot overlap but can share empty spaces.

Count how many regions can fit all listed gifts.
```
0:
###
##.
##.

1:
###
##.
.##

2:
.##
###
##.

3:
##.
###
##.

4:
###
#..
###

5:
###
.#.
###

4x4: 0 0 0 0 2 0
12x5: 1 0 1 0 2 2
12x5: 1 0 1 0 3 2

```

So in this example:

First region (`4×4`) fits `2` of shape `4`.\
Second region (`12×5`) fits `1` of shape `0`, `1` of shape `2`, `2` of shape `4`, `2` of shape `5`.\
Third region (`12×5`) cannot fit all required presents.

Therefore, 2 regions fit all presents.

## 💻 Usage

1. Place your puzzle input in a text file (`input.txt`)  
2. Create a build directory

```bash
mkdir build && cd build
cmake ..
make 
```
3. Run the solution script with the input file as an argument:

```bash
./arrange_presents <path_to_input_file> 

```