//6.
#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

const int N = 12;
int matrix[N][N];
int st[N][N]{0};
int q[N][N]{0};

int n,k;
int path[N*N];
int flag = 0;
void search(int nx,int ny,int cnt,int pcnt){
	if(flag == 1){
		return;
	}
	if(nx == n && ny == n){
		if(pcnt != n * n){
			return;
		}else{
			flag = 1;
			for(int i = 1;i < n * n;i++){
				cout << path[i];
			}
			cout << endl;
			return;
		}
	}
	int ncnt = cnt + 1;
	if(ncnt == k){
		ncnt = 0;
	}
	for(int i = 0;i < 8;i++){
		if(i == 1 && (q[nx-1][ny] == 3 || q[nx][ny+1] == 7)){
			continue;
		}
		if(i == 3 && (q[nx+1][ny] == 1 || q[nx][ny+1] == 5)){
			continue;
		}
		if(i == 5 && (q[nx+1][ny] == 7 || q[nx][ny-1] == 3)){
			continue;
		}
		if(i == 7 && (q[nx-1][ny] == 5 || q[nx][ny-1] == 1)){
			continue;
		}
		int ex = nx + dx[i];
		int ey = ny + dy[i];
		if(ex >= 1 && ex <= n && ey >= 1 && ey <= n && matrix[ex][ey] == ncnt && st[ex][ey] == 0){
			st[ex][ey] = 1;
			path[pcnt] = i;
			q[nx][ny] = i;
			search(ex,ey,ncnt,pcnt + 1);
			st[ex][ey] = 0;
		}
	}
}

int main(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> matrix[i][j];
		}
	}
	st[1][1] = 1;
	search(1,1,0,1);
	if(flag == 0){
		cout << -1;
	}
	return 0;
}
