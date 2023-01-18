#include<bits/stdc++.h>
using namespace std;

// this is dfs

void printDFS(int **edges,int n,int start_vertex,bool *visited){
	cout<<start_vertex<<endl;
	visited[start_vertex]=true;
	for(int i=0;i<n;i++){
		if(i==start_vertex){
			continue;
		}
		if(edges[start_vertex][i]==1){
			if(visited[i]){
				continue;
			}
			printDFS(edges,n,i,visited);
		}
	}
}


void printBFS(int **edges,int n,int start_vertex,bool *visited){
	queue<int> pending_vertices;
	pending_vertices.push(start_vertex);
	visited[start_vertex]=true;
	while(!pending_vertices.empty()){
		int curr_vertex=pending_vertices.front();
		pending_vertices.pop();
		cout<<curr_vertex<<endl;
		for(int i=0;i<n;i++){
			if(i==curr_vertex){
				continue;
			}
			if(edges[curr_vertex][i]==1 && !visited[i]){
				pending_vertices.push(i);
				visited[i]=true;
			}
		}
	}
	// delete []visited;
}

// for disconnected graph

void DFS(int **edges,int n){
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printDFS(edges,n,i,visited);
		}
	}
	
	delete [] visited;
}

void BFS(int **edges,int n){
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printBFS(edges,n,i,visited);
		}
	}
	
	delete [] visited;
}

int main(){

	int n,e;
	cin>>n>>e;

	int **edges=new int*[n];

	for(int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}

	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}

	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	cout<<"DFS"<<endl;
	// print(edges,n,0,visited);
	DFS(edges,n);

	cout<<"BFS"<<endl;
	// printBFS(edges,n,0);
	BFS(edges,n);



	// delete all the memory
	for(int i=0;i<n;i++){
		delete []edges[i];
	}

	delete []edges;
	delete []visited;
}