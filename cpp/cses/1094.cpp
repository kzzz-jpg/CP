#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005] ;
long long sum;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i){
			if(a[i] < a[i-1]){
				sum += a[i - 1] - a[i];
				a[i] = a[i - 1];
			}
		}
	}
	cout << sum << endl;
	return 0;
}