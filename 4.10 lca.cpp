//lca
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int LOG = 20;

vector<pair<int,int>> adj[N];

int up[N][LOG];
int depth[N];
void build(int u,int v,int w){
	adj[v].emplace_back(w,u);
	adj[u].emplace_back(w,v);
}

void dfs(int u,int pa,int current_depth){
	depth[u] = current_depth;
	up[u][0] = pa;
	
	for(int k = 1;k < LOG;k++){
		if(up[u][k - 1] != -1){
			up[u][k] = up[up[u][k-1]][k-1];
		}else{
			up[u][k] = -1;
		}
	}
	
	for(const auto& edge : adj[u]){
		int v = edge.second;
		if(v != pa){
			dfs(v,u,current_depth + 1);
		}
	}
}

int lca(int u,int v){
	if(depth[u] < depth[v]){
		swap(u,v);
	}
	
	for(int k = LOG - 1;k >= 0;k--){
		if(depth[u] - (1 << k) >= depth[v]){
			u = up[u][k];
		}
	}
	
	if(u == v){
		return u;
	}
	
	for(int k = LOG - 1;k >= 0;k--){
		if(up[u][k] != -1 && up[u][k] != up[v][k]){
			u = up[u][k];
			v = up[v][k];	
		}
	}
	
	return up[u][0];
}

int main() {
    int V = 6; // ͼ�Ķ�����

    // ��������ͼ
    build(0, 1, 10);
    build(0, 4, 20);
    build(1, 2, 30);
    build(1, 3, 40);
    build(4, 5, 50);

    // ��ʼ������������������
    memset(up, -1, sizeof(up)); // ��ʼ����������Ϊ -1
    dfs(0, -1, 0);             // �Ӹ��ڵ� 0 ��ʼ���� DFS Ԥ����

    // ��ѯ LCA
    cout << "LCA of 2 and 3: " << lca(2, 3) << endl; // ��� 1
    cout << "LCA of 3 and 5: " << lca(3, 5) << endl; // ��� 0
    cout << "LCA of 4 and 5: " << lca(4, 5) << endl; // ��� 4

    return 0;
}
