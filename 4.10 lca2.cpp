#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int LOG = 20;

vector<pair<int,int>> adj[N];


void build(int u,int v,int w){
	adj[u].emplace_back(w,v);
	adj[v].emplace_back(w,u);
}

int up[N][LOG];
int depth[N];
void dfs(int u,int pa,int cur_depth){
	depth[u] = cur_depth;
	up[u][0] = pa;
	
	for(int k = 1;k < LOG;k ++){
		if(up[u][k - 1] != -1){
			up[u][k] = up[up[u][k - 1]][k - 1];
		}else{
			up[u][k] = -1;
		}
	}
	
	for(const auto& edge : adj[u]){
		int v = edge.second;
		if(v != pa){
			dfs(v,u,cur_depth + 1);
		}
	}
}

int lca(int u,int v){
	//1.确保u深度小于v 
	if(depth[u] < depth[v]){
		swap(u,v);
	}
	
	//2.提升到同一高度 
	for(int k = LOG - 1;k >= 0;k--){
		if(depth[u] - (1 << k) >= depth[v]){
			u = up[u][k];
		}
	}
	
	//3.如果相等，直接输出 
	if(u == v){
		return u;
	}
	
	//4.如果不等，向上提升 
	for(int k = LOG - 1;k >= 0;k--){
		if(up[u][k] != -1 && up[u][k] != up[v][k]){
			u = up[u][k];
			v = up[v][k];
		}
	}
	//5.返回u的父节点 
	return up[u][0];
}


int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int u,v,w;
		cin >> u >> v >> w;
		build(u,v,w);
	}
	
	memset(up,-1,sizeof up);
	dfs(0,-1,0);
	
	for(int i = 0;i < 3;i++){
		int u,v;
		cin >> u >> v;
		cout << lca(u,v) << " ";
	}
	return 0;
}

/*
5
0 1 10
0 4 20
1 2 30
1 3 40
4 5 50

2 3 //1
3 5 //0
4 5 //4
*/
