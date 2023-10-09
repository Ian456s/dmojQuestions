#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define pb push_back
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;
int N, pxor[MAX];

int ask(int l, int r){
	cout << "? " << l << " " << r << "\n";
	cout << flush;
	return cin >> 
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    pxor[N] = ask(1, N);
    for(int i = 1; i < N; i++){
    	if(i > N-i)pxor[i] = ask(1, i);
    	else
    		pxor[i] = ask(i+1, N) ^ pxor[N];
    }
    cout << "!";
    for(int i = 1; i <= N; i++){
    	cout << " " << (pxor[i-1] ^ pxor[i]);
    }
    cout << "\n";
    return 0;
}

