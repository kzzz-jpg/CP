#include<bits/stdc++.h>
using namespace std;
signed main(){
	double b;
	int ans;
	while(cin>>b){
		if(b<11.4) ans=1;
		else if(b<17.2) ans=2;
		else if(b<32.7) ans=3;
		else if(b<51.0) ans=4;
		else ans=5;
		b=pow(b/0.836,double(2)/3);
		int n=b*10;
		if(n%10>4) n+=10;
		n/=10;
		cout<<n<<','<<ans<<'\n';
	}
}
