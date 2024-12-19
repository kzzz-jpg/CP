#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
using namespace std;
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
void solve(){
        int n=nextint(),k=nextint();
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) a[i]=nextint();
        int ans=0;
        for(int l=1,r=0,nw=0;l<=n;nw-=a[l++]){
                while(r+1<=n&&nw+a[r+1]<=k) nw+=a[++r];
                if(nw==k) ans++;
        }
        cout<<ans<<'\n';
}
signed main(){
        int t=nextint();
        while(t--) solve();
}
