#include <bits/stdc++.h>

using namespace std;
int main(){	
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++){
	  	cin >> arr[i];
	}
	int index = 0;
	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string word = "";
	while(true){
	 	if(arr[index] == 0 || arr[index+arr[index]] == 0){
	    	break;
	    }
	    index += arr[index];
	    word += letters[arr[index]-1];
	    index ++;
	}
	cout << word << "\n";
}