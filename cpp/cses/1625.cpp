#include<bits/stdc++.h>
#include<random>
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
/*typedef pair<ll,ll> vec;
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
 
random_device rds;
unsigned int seed = rds();
mt19937 rd(rds());
vector<int> g(200500,-1);
struct Treap{
    Treap *l=nullptr,*r=nullptr;
    int v,size,pri;
    bool alive;
    Treap(int x): size(1),pri(rd()),v(x) {};
    void pull();
    void push();
};
void Treap::pull(){
    size=1;
    if(l!=nullptr) {
        size+=l->size;
    }
    if(r!=nullptr) {
        size+=r->size;
    }
    return;
}
void Treap::push(){
    if(l!=nullptr){
        l->v=v;
        l->push();
    }
    if(r!=nullptr){
        r->v=v;
        r->push();
    }
}
int size(Treap *a){
    if(a==nullptr) return 0;
    return a->size;
}
Treap *merge(Treap *a,Treap *b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    if(a->pri<b->pri){
        a->r=merge(a->r,b);
        a->pull();
        return a;
    }else{
        b->l=merge(a,b->l);
        b->pull();
        return b;
    }
}
void split_by_val(Treap *p,Treap *&a,Treap *&b,int val){
    if(p==nullptr){
        a=b=nullptr;
        return ;
    }
    if(p->v<val){
        a=p;
        split_by_val(p->r,a->r,b,val);
        a->pull();
    }else{
        b=p;
        split_by_val(p->l,a,b->l,val);
        b->pull();
    }
}
void split(Treap *p,Treap *&a,Treap *&b,int k){
    if(p==nullptr) {
        a=b=nullptr;
        return;
    }
    if(size(p->l)<k){
        a=p;
        split(p->r,a->r,b,k-size(p->l)-1);
        a->pull();
    }else{
        b=p;
        split(p->l,a,b->l,k);
        b->pull();
    }
}
void erase(Treap *&root,int x){
    Treap *a,*b,*c,*temp;
    split_by_val(root,a,b,x);
    split_by_val(b,b,c,x+1);
    split(b,temp,b,1);
    delete temp;
    root=merge(merge(a,b),c);
}
void *insrt(Treap *&root,int k){
    Treap *l,*r;
    split_by_val(root ,l,r,k);
    root=merge(merge(l,new Treap(k)),r);
}
void query(Treap *&root,int k){
    if(size(root)<k){
        cout<<-1<<'\n';
        return;
    }
    Treap *a,*b,*c,*del;
    split(root,a,c,k);
    split(a,a,b,k-1);
    cout<<b->v<<'\n';
    delete b;
    root=merge(a,c);
}*/
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
vector<int> road(48);
vector<vector<bool>> gr(7,vector<bool>(7,false));
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int cnt=0;
bool nR(int x,int y) {
    return x<0||x>=7||y<0||y>=7||gr[x][y];
}
 
bool chk1(int x,int y,int now) {
    if (nR(x,y)) return true;
    if (x==6&&y==0&&now<48) return true;
    return false;
}
 
bool chk2(int x, int y) {
    int dx=x+dir[0][0],dy=y+dir[0][1];
    int lx=x+dir[1][0],ly=y+dir[1][1];
    int ux=x+dir[2][0],uy=y+dir[2][1];
    int rx=x+dir[3][0],ry=y+dir[3][1];
    if((nR(dx,dy))&&(nR(ux,uy))&&!nR(rx,ry)&&!nR(lx,ly)) return true;
    if((!nR(dx,dy))&&(!nR(ux,uy))&&nR(rx,ry)&&nR(lx,ly)) return true;
    if(nR(dx,ly)&&!nR(dx,dy)&&!nR(lx,ly)) return true;
    if(nR(ux,ly)&&!nR(ux,uy)&&!nR(lx,ly)) return true;
    if(nR(ux,ry)&&!nR(ux,uy)&&!nR(rx,ry)) return true;
    if(nR(dx,ry)&&!nR(dx,dy)&&!nR(rx,ry)) return true;
    return false;
}
/*int inRange(int x,int y){
	return (x>=0&&x<7&&y>=0&&y<7);
}
void dfs(int x,int y,vector<vector<bool>> &vs){
	vs[x][y]=true;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if(inRange(nx,ny)&&!vs[nx][ny]) dfs(nx,ny,vs);
	}
}
bool cntrm(vector<vector<bool>> vs){
    int ans=0;
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			if(!vs[i][j]){
				ans++;
				dfs(i,j,vs);
			}
		}
	}
   // cerr<<ans<<'\n';
    return ans>1;
}*/
void dfs(int x,int y,int now) {
    if(x==6&&y==0) {
        cnt+=(now==48);
        return;
    }
    gr[x][y]=true;
    if (chk2(x,y)) {
        gr[x][y]=false;
        return;
    }
    /*for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(gr[i][j]) cerr<<'x';
            else cerr<<'.';
        }
        cerr<<'\n';
    }
    cerr<<'\n';*/
    if(road[now]==4) {
        for(int i=0;i<4;i++) {
            int nx=x+dir[i][0],ny=y+dir[i][1];
            if(!chk1(nx,ny,now+1)) dfs(nx,ny,now+1);
        }
    } else {
        int nx=x+dir[road[now]][0],ny=y+dir[road[now]][1];
        if(!chk1(nx,ny,now+1)) dfs(nx,ny,now+1);
    }
    gr[x][y]=false;
}
 
signed main(){
    for(int i=0;i<48;i++){
        char c;
        cin>>c;
        if(c=='D') road[i]=0;
        else if(c=='R') road[i]=1;
        else if(c=='U') road[i]=2;
        else if(c=='L') road[i]=3;
        else road[i]=4;
    }
    dfs(0,0,0);
    cout<<cnt<<'\n';
}