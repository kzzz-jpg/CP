#include<bits/stdc++.h>
#include<random>
using namespace std;
random_device rds;
mt19937 rg(rds());
#define int long long
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
void solve2(){
    int n,k,sum=0,mx=0;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i],sum+=a[i],mx=max(a[i],mx);
    int ans=(sum+k)/mx;
    cout<<ans<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve2();
        cerr<<'\n';
    }
}