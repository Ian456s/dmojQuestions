#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;

vector<int> adj[MAX];
bool vis[MAX];
int dist[MAX];
int N, M, A, B;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> N >> M >> A >> B;
	for(int i = 0; i < M; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}

	queue<int> q;
	q.push(A); vis[A] = true; dist[A] = 0; //starting BFS
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int n : adj[cur]){
			if(!vis[n]){
				q.push(n); vis[n] = true;
				dist[n] = dist[cur] + 1;
			}
		}
	}
	cout << (vis[B]? "GO SHAHIR!": "NO SHAHIR!") << "\n";

	
    return 0;
}