#include<bits/stdc++.h>
using namespace std;
int n;
signed main(){
	cin>>n;
	if(n%400==0||(n%4==0&&n%100)){
		cout<<"Leap year\n";
	}else cout<<"Not Leap year\n";
}
