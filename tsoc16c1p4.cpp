#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e2 + 5;
int R, C, ans;
char g[MAX][MAX];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int r, int c){
	bool monkey = false;
	if(g[r][c] == 'M')monkey = true;
	queue<pair<int,int>> q;
	q.push({r,c}); g[r][c] = '#';
	while(!q.empty()){
		tie(r,c) = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int nr = r + dir[i][0], nc = c + dir[i][1];
			if(g[nr][nc] != '#'){
				if(g[nr][nc] == 'M')monkey = true;
				q.push({nr,nc}); g[nr][nc] = '#';
			}
		}
	}
	return monkey;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
    	for(int j = 0; j < C; j++){
    		cin >> g[i][j];
    	}
    }
    for(int i = 0; i < R; i++){
    	for(int j = 0; j < C; j++){
    		if(g[i][j] != '#')ans += bfs(i,j);
    	}
    }

    cout << ans << "\n";
    return 0;
}

