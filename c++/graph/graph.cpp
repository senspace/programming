
#include <iostream>

using namespace std;

enum VertexState{Write, Gray, Black};

class Graph{
private:
	bool **adjacencyMatrix;
	int vertexCount;
public:
	Graph(int vertexCount){
		this->vertexCount = vertexCount;
		adjacencyMatrix = new bool*[vertexCount];
		for(int i=0; i<vertexCount; i++){
			adjacencyMatrix[i] = new bool[vertexCount];
			for(int j=0; j<vertexCount; j++){
				adjacencyMatrix[i][j] = false;
			}
		}
	}

	void addEdge(int i, int j);
	void removeEdge(int i, int j);
	bool isEdge(int i, int j);
	
	/* Depth-first search(DFS) for undirected graphs*/
	void runDFS(int u, VertexState state[]);
	void DFS();

	~Graph(){
		for{int i=0; i<vertexCount; i++}{
			delete[] adjacencyMatrix[i];
		}
		delete[] adjacencyMatrix;
	}

};

void Graph::addEdge(int i, int j){
	if(i >= 0 && i < vertexCount && j >= 0 && j < vertexCount){
		adjacencyMatrix[i][j] = true;
		adjacencyMatrix[j][i] = true;
	}
}
void Graph::removeEdge(int i, int j){
	if(i >= 0 && i < vertexCount && j >= 0 && j < vertexCount){
		adjacencyMatrix[i][j] = false;
		adjacencyMatrix[j][i] = false;
	}
}
bool Graph::isEdge(int i, int j){
	if(i >= 0 && i < vertexCount && j >= 0 && j < vertexCount){
		return adjacencyMatrix[i][j];
	}else{
		return false;
	}
}
void Graph::runDFS(int u, VertexState state[]){
	state[u] = Gray;
	for(int v=0; v<vertexCount; v++){
		if(isEdge(u, v) && state[v] == White){
			runDFS(v, state);
		}
	}
	state[u] = Black;
}
void Graph::DFS(){
	VertexState *state = new VertexState[vertexCount];
	for(int i=0; i<vertexCount; i++){
		state[i] = White;
	}
	runDFS(0, state);
	delete[] state;
}









