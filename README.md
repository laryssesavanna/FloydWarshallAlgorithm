# README #
Floyd Warshall algorithm implementation

### Execution Instructions

1- Create a .txt file and call it "Entrada.txt". 
In the first line add the number of vertices of the graph. Then enter an matrix of values that indicate the weights associated with the edges connecting two vertices. 
For infinite values, the value 9999999 will be considered.

Example:

```
4
0 1 9999999 9999999
9999999 0 -1 9999999
9999999 9999999 0 -1
-1 9999999 9999999 0
```

2- Run the algorithm in a IDE and it will create an .txt file called "Saida.txt" that stores the resulting matrix containing the shortest paths of vertices
