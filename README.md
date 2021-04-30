#	🌲	My-MinimumSpanningTree

<div align="left">
    <img src="https://img.shields.io/badge/language-c-blue">
    <img src="https://img.shields.io/badge/compiler-gcc-brightgreen">
    <img src="https://img.shields.io/badge/build-makefile-green">
    <img src="https://img.shields.io/badge/license-MIT-blueviolet">
</div>

---

This project developed along the discipline of **"Algorithms and Data Structures"** at **UFMG** uses an implementation of the **Krushkal Algorithm** to calculate the Minimum Spanning Tree of a graph.

The file **"input.txt"** must contain the nodes and edges of the graph as follows:

- The first line must contain the number of nodes and the number of edges of the graph

- Subsequent lines must contain the two nodes followed by the weight of the edge between them

The **"output.txt"** file receives the optimized graph in the same format.

<p align="center">
  <img src="resources/gif.gif">
</p>

---

##	📦	Install

To test this library, just make a clone of this repo and build using the commands below:

```bash
$ git clone https://github.com/NanderSantos/My-MinimumSpanningTree.git

$ cd My-MinimumSpanningTree

$ make
```

Or use this magical one-liner command to make it easiest:

```bash
$ git clone https://github.com/NanderSantos/My-MinimumSpanningTree.git && cd My-MinimumSpanningTree && make
```

---

##	🏃	Run

To run the program just use the following command line below:

```bash
$ ./MyMinimumSpanningTree input.txt output.txt
```

To see the results of other graphs, just change the **"input.txt"** file

---

##	🗑️	Clear

To clear the project just use the following command line below:

```bash
$ make clean
```
