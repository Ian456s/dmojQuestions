#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 5;
int arr[MAX];
int psa[MAX];
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= n; i++){
		psa[i] = psa[i-1] + arr[i];
	}
	int q; cin >> q;
	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		cout << (psa[r+1] - psa[l]) << "\n";
	}

	return 0;
}
