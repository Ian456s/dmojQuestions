#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+5;

int N, a[MAX]; string s; int ans;
int main(){
	cin >> N >> s;
	for(int i = 1; i <= N; i++){
		cin >> a[i];
	}
	int g1 = s.find('G')+1, h1 = s.find('H')+1;
	int lastg = s.rfind('G')+1, lasth = s.rfind('H')+1;
	if(g1 < h1){
		for(int i = 1; i <= h1; i++){
			if(s[i-1] != 'G')continue;
			if(i==g1 && a[i] >= lastg || a[i] >= h1) ans++;
		}
	} else {
		for(int i = 1; i <= g1; i++){
			if(s[i-1] != 'H')continue;
			if(i == h1 && a[i] >= lasth || a[i] >= g1) ans++;
		}
	}
	cout << ans << "\n";
}
