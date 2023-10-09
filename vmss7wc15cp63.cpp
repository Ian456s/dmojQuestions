#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int INF = 0x3f3f3f3f;
const int MAX = 4e5 + 5;

vector<int> adj[MAX];
int values[MAX];
bool vis[MAX];

void DFS(int n){
    for(auto &v : adj[n]){
        DFS(v);
        values[n] += values[v];
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, w; cin >> u >> w;
        adj[u].push_back(w);
    }
    for(int i = 1; i <= n; i++){
        cin >> values[i];
    }
    DFS(1);
    int best = INT_MIN;
    for(int i = 1; i <= n; i++){
        best = max(best, values[i]);
    }
    cout << best << "\n";
    return 0;
}