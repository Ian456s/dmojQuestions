#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
int N, M, W;
int dist[MAX], distAnts[MAX];
bool vis[MAX];
vector<int> adj[MAX];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> W;
    queue<int> q;
    fill(vis, vis+N+1, false);
    fill(distAnts, distAnts+N+1, -1);
    while(W--) {
        int x; cin >> x;
        vis[x] = 1;
        distAnts[x] = 0;
        q.push(x);
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &x : adj[cur]) {
            if(!vis[x]) {
                vis[x] = true;
                distAnts[x] = distAnts[cur] + 4;
                q.push(x);
            }
        }
    }
    fill(vis, vis+N+1, false);
    fill(dist, dist+N+1, -1);
    dist[1] = 0;
    vis[1] = true;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &x : adj[cur]) {
            if(!vis[x] and distAnts[x] > dist[cur] + 1) {
                vis[x] = true;
                dist[x] = dist[cur] + 1;
                q.push(x);
            }
        }
    }
    if(vis[N]) {
        cout << dist[N] << "\n";
    } else {
        cout << "sacrifice bobhob314" << "\n";
    }
    return 0;
}