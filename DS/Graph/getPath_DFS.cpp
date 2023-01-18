#include <iostream>
#include<vector>
using namespace std;

bool getPath(int **edges,int n,bool *visited,int v1,int v2,vector<int> &res){
	if(v1==v2){
		res.push_back(v1);
		return true;
	}

	visited[v1]=true;
	bool ans=false;
	for(int i=0;i<n;i++){
		if(!visited[i] && edges[v1][i]==1){
			ans=getPath(edges,n,visited,i,v2,res);
		}
		if(ans==true){
			res.push_back(v1);
			return true;
		}
	}
	return ans;
}

int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];

    for (int i = 0; i < n; i++) {
      edges[i] = new int[n];
      for (int j = 0; j < n; j++) {
        edges[i][j] = 0;
      }
    }

    for (int i = 0; i < e; i++) {
      int f, s;
      cin >> f >> s;
      edges[f][s] = 1;
      edges[s][f] = 1;
    }

	bool * visited=new bool[n];
    for(int i=0 ;i< n;i++)
        visited[n]= false;
    int v1,v2;
    cin>>v1>>v2;
	vector<int> res;
	if(getPath(edges,n,visited,v1,v2,res)){
		for(auto i : res){
			cout<<i<<" ";
		}
	}
}