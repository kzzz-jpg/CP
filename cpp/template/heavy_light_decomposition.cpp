#include<bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,inline,unroll-loops,no-stack-protector,fast-math")
using namespace std;
#define re register
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
inline void output(int _x){
    if(!_x) putchar('0');
    char _buff[20]; int _f = 0;
    while(_x > 0)
    {
        _buff[_f++] = _x%10+'0';
        _x /= 10;
    }
    for(_f-=1; _f >= 0; _f--)
        putchar(_buff[_f]);
    putchar(' ');
}
/****************************************************************************************************** */
int pre[1000500];
char s[1000500];
int n,q,l,r,ans;
void solve(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        pre[i]++;
        if(s[i]=='9'&&s[i-1]=='4') pre[i]++;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        ans=pre[r]-pre[l-1];
        if(s[l]=='9'&&s[l-1]=='4') ans--;
        printf("%d",ans);
    }
}
signed main() {
    re int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}