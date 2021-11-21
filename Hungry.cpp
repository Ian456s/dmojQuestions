#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;
pair<int,int> filling[MAX], tasty[MAX];
bool compare(pair<int, int> a, pair<int, int> b) 
{ 
    return a.second < b.second; 
} 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 	int n; cin >> n;   
 	for(int i = 0; i < n; i++){
 		filling[i].f = i; cin >> filling[i].s; 
 		tasty[i].f = i; cin >> tasty[i].s;
 	}
 	sort(filling, filling + n, compare);
 	sort(tasty, tasty + n, compare);
 	for(int i = 0; i < n; i++){
 		cout << filling[i].f+1 << " ";
 	}
 	cout << "\n";
 	for(int i = 0; i < n; i++){
 		cout << tasty[i].f+1 << " ";
 	}
 	cout << "\n";
    return 0;
}