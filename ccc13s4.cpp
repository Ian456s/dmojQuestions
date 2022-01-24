#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e6 + 5;

bool vis[MAX];
vector<int> adj[MAX];

bool bfs(int x1, int x2){
	memset(vis, false, sizeof(vis));
	queue<int> q; q.push(x1);
	vis[x1] = true;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int v : adj[cur]){
			if(!vis[v]){
				vis[v] = true;
				q.push(v);
			}
		}
	}
	return vis[x2];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
    	int a, b; cin >> a >> b;
    	adj[a].push_back(b);
    }
    int p, q; cin >> p >> q;
    if(bfs(p,q))
    	cout << "yes\n";
    else if (bfs(q,p))
    	cout << "no\n";
    else
    	cout << "unknown\n";
    return 0;
}