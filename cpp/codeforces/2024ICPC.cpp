#include<bits/stdc++.h>
using namespace std;
void solve(){
	int a,b;
	char c;
	scanf("%d%c%d",&a,&c,&b);
	if(a>b) printf("%d>%d",a,b);
	else if(a==b) printf("%d=%d",a,b);
	else printf("%d<%d",a,b);
	printf("\n");
}
signed main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
}
