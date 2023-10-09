#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define pb push_back
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e3 + 5;
int N, ans = 0, cnt[MAX][MAX];
bool cow[MAX][MAX];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
    	int x, y; cin >> x >> y;
    	x++;y++;
    	cow[x][y] = true;
    	if(cnt[x][y] == 3) ans++;
    	for(int k = 0; k < 4; k++){
    		int nx = x + dir[k][0], ny = y + dir[k][1];
    		cnt[nx][ny]++;
    		if(cnt[nx][ny] == 3 && cow[nx][ny])ans++;
    		if(cnt[nx][ny] == 4 && cow[nx][ny])ans--;
    	}
    	cout << ans << "\n";
    }
    return 0;
}

