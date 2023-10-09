#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 5;
int a[MAX], b[MAX];
int n, m, sec = 0;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int c1 = 0, flips = 0;;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	if(a[i] == 1){
    		c1++;
    	}
    }	
    if(c1 == 0){
    	cout << 0 << "\n";
    	return 0;
    } 
    for(int i = 0; i < m; i++){
        cin >> b[i]; int x = b[i]-1;
        if(a[x] == 1){
        	a[x] = 0;
        	c1--;
        } else {
        	a[x] = 1;
        	c1++;
        }
        flips++;
        if(flips >= c1){
        	cout << i+1 << "\n";
        	return 0;
        }
    }
    cout << c1 << "\n";
    return 0;
}