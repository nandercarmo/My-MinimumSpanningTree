# My-MinimumSpanningTree

This project developed along the discipline of "Algorithms and Data Structures" at UFMG uses an implementation of the Krushkal algorithm to calculate the Minimum Spanning Tree of a graph.

The file "input.txt" must contain the nodes and edges of the graph as follows:

- The first line must contain the number of nodes and the number of edges of the graph

- Subsequent lines must contain the two nodes followed by the weight of the edge between them

The "output.txt" file receives the optimized graph in the same format.

<p align="center">
  <img src="resources/gif.gif">
</p>

## Install

To test this library, just make a clone of this repo using the command below:

> git clone https://github.com/NanderSantos/My-MinimumSpanningTree.git

> cd My-MinimumSpanningTree

Finally run this command and everything will be done:

> make

Or use this magical one-liner command to make it easiest:

> git clone https://github.com/NanderSantos/My-MinimumSpanningTree.git && cd My-MinimumSpanningTree && make

## Run

To run the program just use the following command line below:

> ./MyMinimumSpanningTree input.txt output.txt

To see the results of other graphs, just change the "input.txt" file

## Clear

To clear the project just use the following command line below:

> make clean
