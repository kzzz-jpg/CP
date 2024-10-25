#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
using namespace std;
#define ll long long
#define MAX_INT 210000000
#define MAX_LONG 900000000000000000
#define int ll
#define lc (id<<1)
#define rc ((id<<1)|1)
#define ff first
#define ss second
const int P=1e9+7;
char readchar() {
	const int S = 1<<20; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}
int nextint() {
	int x = 0, c = readchar(), neg = false;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
	if(c == '-') neg = true, c = readchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
	if(neg) x = -x;
	return x; // returns 0 if EOF
}
int n;
int find(int x){
	int ret=0;
	for(int i=1;i<=min(x,n);i++) ret+=min(x/i,n);
	return ret;
}
signed main(){
	cin>>n;
	int ans=n*n,ans2=0;
	for(int j=n*n;j;j>>=1){
		while(ans-j>0&&find(ans-j)>=(n*n/2+1)) ans-=j;
	}
    cout<<ans<<'\n';
}