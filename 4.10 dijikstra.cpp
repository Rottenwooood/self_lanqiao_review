//dijikstra
#include <bits/stdc++.h>

using namespace std;
using PII = pair<int,int>;

int n,m;
const int N = 1e5;
int w[N],dist[N];
vector<PII> adj[N];
bool st[N]{};

int dijikstra(int u){
	priority_queue<PII,vector<PII>,greater<PII>> pq;
	pq.push({0,u});
	memset(dist,0x3f,sizeof dist);
	//fill(dist,dist + N,INT_MAX)//vector<int>
	dist[u] = 0;
	while(pq.size()){
		auto t = pq.top();
		pq.pop();
		
		int v = t.second,w = t.first;
		
		if(st[v])continue;
		st[v] = true;
		
		for(auto &edge : adj[v]){
			int i = edge.second;
			int w = edge.first;
			if(!st[i] && dist[i] > dist[v] + w){
				dist[i] = dist[v] + w;
				pq.push({dist[i],i});
			}
		}
	}
	if(dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}

int main(){
	int start;
	cin >> n >> m >> start;
	
	for(int i = 0;i < m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].emplace_back(w,v);//有向图
		//adj[v].emplace_back({w,u});//无向图 
	}
	
	int res = dijikstra(start);
	
	cout << res;
	return 0;	
} 
