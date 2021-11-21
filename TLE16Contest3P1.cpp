#include <bits/stdc++.h>

using namespace std;
int main() {
    map<string, int> freq;
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        freq[s]++;
    }
    int count = 0;
    for(auto &x : freq){
        if(x.second == 1){
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}