#include<bits/stdc++.h>
#include<random>
using namespace std;
#define int long long
random_device rd;
mt19937 rg(rd());
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
int chk[400];
int n,l[400],r[400];
int ans;
inline pair<int,int> geta(){
    int lsum=0,rsum=0;
    for(int i=0;i<n;i++) if(chk[i]) lsum+=l[i],rsum+=r[i];
    return {lsum,rsum};
}
inline void sa(){
    double T=300000,ed=1e-7,low=0.984612;
    for(;T>ed;T*=low){
        int id=rg()%n;
        chk[id]^=1;
        auto it=geta();
        int nwl=it.first,nwr=it.second,nw=nwl+nwr;
        if(nwl<0||nwr<0||nw<ans){
            if(exp((nw-ans)/T)<(double(rg())/(rg.max()+1))) chk[id]^=1;
        }else ans=nw;
    }
}
signed main(){
    n=nextint();
    for(int i=0;i<n;i++) l[i]=nextint(),r[i]=nextint();
    while(double(clock())/CLOCKS_PER_SEC<0.97) sa();
    cout<<ans<<'\n';
}