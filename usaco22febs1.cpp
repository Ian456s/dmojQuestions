#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e3 + 5;
int mostPref[MAX], N;
int cows[MAX][MAX];
vector<int> adj[MAX];
bool vis[MAX][MAX];

void bfs(int st, bool vis[]){
	queue<int> q;
	q.push(st); vis[st] = true;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int n : adj[cur]){
			if(!vis[n]){
				q.push(n); vis[n] = true;
			}
		}
	}
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= N; j++){
    		cin >> cows[i][j];
    	}
    }

    for(int i = 1; i <= N; i++){
    	int cur = i;
    	for(int j = 1; j <= N; j++){
    		if(cows[i][j] != cur){
    			adj[i].push_back(cows[i][j]);
    		} else { break; }
    	}
    }
    for(int i = 1; i <= N; i++)bfs(i, vis[i]);
    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= N; j++){
    		int k = cows[i][j];
    		if(vis[i][k] && vis[k][i]){
    			cout << k << "\n";
    			break;
    		}
    	}
    }

    
    return 0;
}

