#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;
int total[105];
int greaterr[105];
string names[105];
pair<int,int> person[105];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < n; i++){
    	cin >> names[i];
    }
    for(int i = 0; i < p; i++){
    	for(int j = 0; j < n; j++){
    		int score; cin >> score;
    		total[j] += score;
    	}
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(total[i] < total[j])greaterr[i]++;
    	}
    }
    for(int i = 0; i < n; i++){
    	person[i] = {greaterr[i]+3, i};
    }
    sort(person, person+n);
    for(int i = 0; i < n; i++){
    	cout << person[i].f << ". " << names[person[i].s] << "\n"; 
    }
    return 0;
}