#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e6 + 5;
int n, m, k; 
int c[MAX], t[MAX];

bool isValid(int x){
    bool flag = true;
    int curCow = 0, curT = 0, cAtT = 0;
    while(true){
        if(curCow >= n){
            break;
        }
        if(curCow < n and cAtT >= m){
            flag = false;
            break;
        }
        if(cAtT < x and t[curT] <= c[curCow] and t[curT] >= c[curCow] - k){
            cAtT++;
            curCow++;
        } else {
            curT++;
            cAtT = 0;
        }
    }
    return flag;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = 0; i < m; i++){
        cin >> t[i];
    }
    sort(c, c+n);
    sort(t, t+m);
    int lo = 1, hi = n+1;
    while(lo < hi){
        int mid = (lo + hi)/2;
        if(isValid(mid)){
            hi = mid;
        } else{
            lo = mid + 1;
        }
    }
    if(lo == n+1){
        cout << -1 << "\n";
    } else {
        cout << lo << "\n";
    }
    return 0;
}