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
typedef pair<ll,ll> vec;
vec operator - (vec p){ return {-p.ff, -p.ss}; }
vec operator + (vec p, vec q){ return {p.ff+q.ff, p.ss+q.ss}; }
vec operator - (vec p, vec q){ return {p.ff+q.ff, p.ss+q.ss}; }
vec operator * (vec p, int q){ return {p.ff*q, p.ss*q}; }
vec operator / (vec p, int q){ return {p.ff/q, p.ss/q}; }
int cross (vec p, vec q){ return p.ff*q.ss - p.ss*q.ff; }
int dot   (vec p, vec q){ return p.ff*q.ff + p.ss*q.ss; }
int abs2 (vec p){ return dot(p,p); }
double abs (vec p){ return hypot(p.ff,p.ss); }
bool equal(double a,double b){
    if(a-b<0.00000000001&&a-b>-0.00000000001) return true;
    return false;
}
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
signed main(){
    fast;
    int n=nextint();
    int sum=(n*(n+1))/2;
    if(sum&1){
        cout<<"NO\n";
        return 0;
    }
    sum/=2;
    int ans=0;
    vector<bool> vs(n+1,true);
    for(int i=n;i>0&&sum;i--){
        if(sum>=i){
            ans++;
            vs[i]=false;
            sum-=i;
        }
    }
    cout<<"YES\n"<<ans<<'\n';
    for(int i=1;i<=n;i++) if(!vs[i]) cout<<i<<' ';
    cout<<'\n'<<(n-ans)<<'\n';
    for(int i=1;i<=n;i++) if(vs[i]) cout<<i<<' ';
    cout<<'\n';
    return 0;
}
