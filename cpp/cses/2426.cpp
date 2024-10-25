#include<bits/stdc++.h>
#include<random>
#define int long long
using namespace std;
random_device rds;
unsigned seed(rds());
mt19937 rg(seed);
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
int n,a,b,nw,sum;
int art[200500],pro[200500],chk[200500];
int ans=0;
int geta(){
    int sum=0;
    for(int i=0;i<n;i++) {
        if(chk[i]==1) sum+=pro[i];
        else if(chk[i]==2) sum+=art[i];
    }
    return sum;
}
void sa(){
    double tmp=50000,ed=1e-9,low=0.9112;
    for(;tmp>ed;tmp*=low){
        int x=rg()%n;
        int y=rg()%n;
        if(chk[x]==1) nw-=pro[x],nw+=pro[y];
        else if((chk[x]==2)) nw-=art[x],nw+=art[y];
        if(chk[y]==1) nw-=pro[y],nw+=pro[x];
        else if(chk[y]==2) nw-=art[y],nw+=art[x];
        swap(chk[x],chk[y]);
        if(nw>ans) ans=nw,sum=nw;
        else if(exp((nw-ans)/tmp)<(double(rg())/(rg.max()+1)))
            swap(chk[x],chk[y]),nw=sum;
        else sum=nw;
    }
}
void solve(){
    a=nextint();
    b=nextint();
    n=nextint();
    int i=0;
    for(int j=0;j<a;i++,j++) chk[i]=1;
    for(int j=0;j<b;j++,i++) chk[i]=2;
    for(;i<n;i++) chk[i]=0;
    for(int i=0;i<n;i++) pro[i]=nextint(),art[i]=nextint();
    sum=nw=geta();
    while(double(clock())/CLOCKS_PER_SEC<0.98) sa();
    cout<<ans<<'\n';
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}