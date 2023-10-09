#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define pb push_back
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;
int N, x, ans; vector<int> gr, lt; char op;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
    	cin >> op >> x;
    	if(op == 'G')gr.pb(x);
    	else lt.pb(x);
    }
    sort(gr.begin(), gr.end()); sort(lt.begin(), lt.end());
    for(int i = 0, j = 0; i < gr.size(); i++){
    	while(j < lt.size() && lt[j] < gr[i])j++;
    	ans = max(ans, i + 1 + ((int)lt.size() - j));
	}
	cout << N - ans << "\n";
    return 0;
}