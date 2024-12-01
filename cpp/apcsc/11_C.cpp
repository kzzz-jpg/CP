#include<bits/stdc++.h>
#pragma GCC optimize(2)
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
    putchar('\n');
}
int n,m,k,len,ans;
int g[8][8];
int row[8];
int col[8];
bool fi[8][8];
bool vs[100];
struct pt{
    int x,y;
};
pt nxt(int x,int y){
    if(y+1>=m){
        if(fi[x+1][0]) return nxt(x+1,0);
        return {x+1,0};
    }
    if(fi[x][y+1]) return nxt(x,y+1);
    return {x,y+1};
}
bool inR(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
void hehe(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cerr<<g[i][j]<<' ';
        }
        cerr<<'\n';
    }
    cerr<<"=================\n";
}
int gtup(int x,int y){
    if(!inR(x-1,y)) return 0;
    if(fi[x-1][y]) return gtup(x-1,y);
    return g[x-1][y];
}
int gtlf(int x,int y){
    if(!inR(x,y-1)) return 0;
    if(fi[x][y-1]) return gtup(x,y-1);
    return g[x][y-1];
}
void dfs(int x,int y){
    if((n-x-1-col[x]>len-g[x][y])||m-y-1-row[y]>len-g[x][y]){
        //hehe();
        vs[g[x][y]]=0;
        g[x][y]=0;
        return;
    }
    if(((inR(x-1,y))&&gtup(x,y)>g[x][y])||((inR(x,y-1))&&gtlf(x,y)>g[x][y])){
        vs[g[x][y]]=0;
        g[x][y]=0;
        return;
    }
    if(x==n-1&&y==n-1) {
        ans++;
        vs[g[x][y]]=0;
        g[x][y]=0;
        return;
    }
    auto tp=nxt(x,y);
    for(int i=1;i<=len;i++){
        if(vs[i]) continue;
        g[tp.x][tp.y]=i;
        vs[i]=1;
        dfs(tp.x,tp.y);
    }
    vs[g[x][y]]=0;
    g[x][y]=0;
}
signed main(){
    n=nextint(),m=nextint(),k=nextint();
    //double tm=(double(clock())/CLOCKS_PER_SEC);
    len=m*n-k;
    int x,y;
    for(int i=1;i<=k;i++){
        x=nextint(),y=nextint();
        row[x]++;
        col[y]++;
        fi[x][y]=1;
    }
    vs[1]=1;
    g[0][0]=1;
    dfs(0,0);
    output(ans%1145141);
    //cerr<<((double(clock())/CLOCKS_PER_SEC)-tm)<<'\n';
}

//O2開了 5 4 0這筆跑了13秒 算了吧 拿個30
//痾我猜可能30都沒有 我好爛qwq