#include <bits/stdc++.h>

using namespace std;
const int MAX = 2005;
int n, m, a, b;
vector<int> adj[MAX];
bool vis[MAX];
void dfs(int n) {
	vis[n] = true;
	for(auto &neighbour : adj[n]) {
		if(!vis[neighbour]) {
			dfs(neighbour);
		}
	}
}
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> a >> b;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(a);
	if(vis[b]) {
		cout << "GO SHAHIR!" << "\n";
	} else {
		cout << "NO SHAHIR!" << "\n";
	}
	return 0;
}