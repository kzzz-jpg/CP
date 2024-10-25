#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int n;
int main() {
	cin>>n;
	if(n==1) {
		cout<<1<<endl;
		cout<<1<<" "<<1<<endl;
	}
	else if(n==2) {
		cout<<4<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<2<<" "<<1<<endl;
		cout<<2<<" "<<2<<endl;
		cout<<1<<" "<<2<<endl;
	}
	else cout<<-1;
}