#include<stdio.h>
#include<string.h>
#include <stdlib.h>

/*
* For infinite values it will be considered the value: 9999999
*/

void writeFile(int **dist, int size);
void negativeCicles(int **dist, int size);
void printOutPut(int **dist, int size);
void floydWarshall(int **dist, int size);
void readFile();

// Function to read the file with the graph
void readFile(){
	int n       = 0;   // Vertices
	int value   = 0;   // Value of the graph

	// Open file
	FILE *file = fopen64("entrada.txt", "r");
	
	// If it fails return an error
	if(file == NULL){
		printf("Error while trying to read file.");
		return;
	}
	
	// Reading the number of vertices
	fscanf(file, "%d", &n);
	printf("Number of vertices: %d\n\n", n);
	
	//Build the graph with malloc
	int **graph = (int**) malloc(n * sizeof(int*)); //Allocate a vector of pointers
	
	for(int i = 0; i < n; i++){
		graph[i] = (int*) malloc(n * sizeof(int*));
		for(int j = 0; j < n; j++){
			if(!feof(file)){
				fscanf(file, "%d", &value);
				graph[i][j] = value;
			}
		}
	}
	
	fclose(file);
	
	printf("Showing the input matrix: \n\n");
	printOutPut(graph, n);
	
	floydWarshall(graph, n);
}

// Algorithm of Floyd-Warshall to calculate the shortest distances
void floydWarshall(int **dist, int size){
	for(int k = 0; k < size; k++){
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	printf("Showing the matrix of the shortest distances between every pair of vertices: \n\n");
	printOutPut(dist, size);
	negativeCicles(dist, size);
	writeFile(dist, size); //Save the output in a .txt
}

//Detecting negative cicles
void negativeCicles(int **dist, int size){
	for(int i = 0; i < size; i++){
		if(dist[i][i] < 0){
			printf("There are negative cicle in dist[%d][%d]: %d\n", i, i, dist[i][i]);
		}
	}
}
// Function to print the matrix with the shortest distances
void printOutPut( int **dist, int size){
		
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				if(dist[i][j] == 9999999){
					printf("INF ");
				}else{
					printf("%d ", dist[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
}

// Function to save the matrix of the shortest distances (the output)
void writeFile(int **dist, int size){
	// Open/Create file
	FILE *file = fopen64("saida.txt", "w");
	
	// If it fails return an error
	if(file == NULL){
		printf("Error while trying to open file.");
		return;
	}
	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(dist[i][j] == 9999999){
				fprintf(file, "INF ");
			}else{
				fprintf(file, "%d ", dist[i][j]);
			}
		}
		fprintf(file, "\n");
	}
	
	printf("\nOutput saved in saida.txt\n");
}

int main(){
	readFile();
	return 0;
}
