# Day 11: Reactor
> 🎯 **Goal:**: To find the Total number of paths between two devices and the number of problematic paths
---
## 📖 Problem Summary
The elves are trying to fix the communication between the reactor and a new server rack.
However, in the room there is a tangle of cables and devices running from 
the server rack to reactor.
There is a list of the devices and their outputs,

* Part 1:To find the problem they first need to find every path from `you` and `out`.
We compute total number of paths between `you` and `out`

* Part 2: After further analysis it is found that teh problematic data passes 
through the devices `dac` and `fft`.
so we compute the total number of paths between `svr` to 'out' which contains `dac` and `fft`

[Read more..](https://adventofcode.com/2025/day/11)


## Example

* Part 1: Given  below list of devices and their outputs
```
aaa: you hhh
you: bbb ccc
bbb: ddd eee
ccc: ddd eee fff
ddd: ggg
eee: out
fff: out
ggg: out
hhh: ccc fff iii
iii: out
```
In this example, these are all of the paths from you to out:

Data could take the connection from `you` to `bbb`, then from `bbb` to `ddd`, then from `ddd` to `ggg`, then from `ggg` to `out`.\
Data could take the connection to `bbb`, then to `eee`, then to `out`.\
Data could go to `ccc`, then `ddd`, then `ggg`, then `out`.\
Data could go to `ccc`, then `eee`, then `out`.\
Data could go to `ccc`, then `fff`, then `out`.\
In total, there are `5` different paths leading from `you` to `out`.

* Part 2: Given  below list of devices and their outputs
```
svr: aaa bbb
aaa: fft
fft: ccc
bbb: tty
tty: ccc
ccc: ddd eee
ddd: hub
hub: fff
eee: dac
dac: fff
fff: ggg hhh
ggg: out
hhh: out
```
This new list of devices contains many paths from `svr` to `out`:

```
svr,aaa,fft,ccc,ddd,hub,fff,ggg,out
svr,aaa,fft,ccc,ddd,hub,fff,hhh,out
svr,aaa,fft,ccc,eee,dac,fff,ggg,out
svr,aaa,fft,ccc,eee,dac,fff,hhh,out
svr,bbb,tty,ccc,ddd,hub,fff,ggg,out
svr,bbb,tty,ccc,ddd,hub,fff,hhh,out
svr,bbb,tty,ccc,eee,dac,fff,ggg,out
svr,bbb,tty,ccc,eee,dac,fff,hhh,out
```
However, only 2 paths from svr to out visit both `dac` and `fft`.
## 💻 Usage
1. Place your puzzle input in a text file (`input.txt`)
2. Run the solution script  with the input file as an argument:
```bash
./reactor.py input.txt 
```


