#include<bits/stdc++.h>
//#pragma GCC optimize("O3,Ofast,inline,unroll-loops,no-stack-protector,fast-math")
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
int cnt=1;
vector<int> Head(200500,0);
vector<int> Next(400500);
vector<int> To(400500);
vector<int> sz(200500,0);
vector<int> dh(200500);
vector<int> val(200500);
vector<int> bgs(200500);
vector<int> trid(200500);
vector<int> trpos(200500);
vector<int> trhd(200500);
vector<int> fabgs(200500);
vector<vector<int>> hld;
void addEdge(int u,int v){
    Next[cnt]=Head[u];
    To[cnt]=v;
    Head[u]=cnt++;
}
/***********************************************鍊式前向星建圖**************************************************/
 
 
struct seg{
	int n;
	vector<int> a;
	vector<int> tr;
	seg(vector<int> t):a(t){
		n=t.size();
		tr.resize(2*n,0);
		build();
	}
	void build(){
		for(int i=0;i<n;i++){
			tr[i+n]=a[i];
		}
		for(int i=n-1;i;i--){
			tr[i]=max(tr[i<<1],tr[i<<1|1]);
		}
	}
	int query(int l,int r){
		int ans=0;
		for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
			if(l&1) ans=max(ans,tr[l++]);
			if(!(r&1)) ans=max(ans,tr[r--]);
		}
		return ans;
	}
	void update(int pos,int v){
		pos+=n;
		tr[pos]=v;
		while(pos){
			pos>>=1;
			tr[pos]=max(tr[pos<<1],tr[pos<<1|1]);
		}
	}
	
};
vector<seg> tr;
/***************************************segment tree**********************************************/
 
struct qur{
	int op;
	int a,b;
};
 
vector<int> lca(200500);
vector<int> vs(200500,false);
vector<int> fa(200500);
vector<int> pbH(200500);
vector<int> pbN(400500);
vector<int> pbW(400500);
vector<int> pbQ(400500);
int qcnt=1;
void addQ(int a,int b,int id){
	pbN[qcnt]=pbH[a];
	pbW[qcnt]=b;
	pbQ[qcnt]=id;
	pbH[a]=qcnt++;
}
int DSU(int x){
	if(fa[x]==x) return x;
	return fa[x]=DSU(fa[x]);
}
void cb(int a,int b){
	a=DSU(a);
	b=DSU(b);
	fa[a]=b;
}
void tarjan(int x,int par){
	vs[x]=true;
	for(int e=Head[x];e;e=Next[e]){
		int v=To[e];
		if(v!=par){
			tarjan(v,x);
		}
	}
	for(int e=pbH[x];e;e=pbN[e]){
		int v=pbW[e];
		if(vs[v]){
			lca[pbQ[e]]=DSU(v);
		}
	}
	cb(x,par);
}
/****************************************tarjan Lca**************************************************/
 
void findbs(int x,int par,int d){
	dh[x]=d;
	sz[x]=1;
	bgs[x]=-1;
	for(int e=Head[x];e;e=Next[e]){
		int v=To[e];
		if(v!=par){
			findbs(v,x,d+1);
			sz[x]+=sz[v];
			if(bgs[x]==-1||sz[v]>sz[bgs[x]]) bgs[x]=v;
		}
	}
}
int id=0;
void dep(int x,int par){
	trid[x]=id;
	if(x==1||trid[x]!=trid[par]) trhd[id]=x,fabgs[x]=par;
	trpos[x]=hld[id].size();
	hld[id].push_back(val[x]);
	if(bgs[x]!=-1){
		dep(bgs[x],x);
	}
	for(int e=Head[x];e;e=Next[e]){
		int v=To[e];
		if(v!=par&&v!=bgs[x]){
			hld.push_back({});
			id++;
			dep(v,x);
		}
	}
}
/********************************** Heavy-Light Decomposition *************************************/
 
signed main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>val[i];
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		addEdge(a,b);
        addEdge(b,a);
	}
    findbs(1,1,0);
	hld.push_back({});
	dep(1,1);
	for(int i=0;i<hld.size();i++){
		tr.push_back(seg(hld[i]));
	}
	vector<qur> qr(q);
	for(int i=0;i<q;i++){
		int op;
		cin>>op;
		int a,b;
		cin>>a>>b;
		if(op&1){
			qr[i].op=op;
			qr[i].a=a;
			qr[i].b=b;
		}else{
			qr[i].op=op;
			qr[i].a=a;
			qr[i].b=b;
			addQ(a,b,i);
			addQ(b,a,i);
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	tarjan(1,1);
	for(int i=0;i<q;i++){
		if(qr[i].op==2){
			int ans=0;
			int A=qr[i].a;
			//cerr<<A<<'\n';
			while(trid[A]!=trid[lca[i]]){
				ans=max(ans,tr[trid[A]].query(0,trpos[A]));
				A=fabgs[trhd[trid[A]]];
			}
			ans=max(tr[trid[A]].query(min(trpos[A],trpos[lca[i]]),max(trpos[A],trpos[lca[i]])),ans);
			//cerr<<tr[trid[A]].query(min(trpos[A],trpos[lca[i]]),max(trpos[A],trpos[lca[i]]))<<'\n';
			int B=qr[i].b;
			//cerr<<B<<'\n';
			while(trid[B]!=trid[lca[i]]){
				//int qry=tr[trid[B]].query(0,trpos[B]);
				//cerr<<B<<'\n';
				ans=max(ans,tr[trid[B]].query(0,trpos[B]));
				B=fabgs[trhd[trid[B]]];
				//cerr<<tr[trid[B]].query(0,trpos[B])<<' '<<B<<'\n';
			}
			//cerr<<trpos[B]<<' '<<trpos[lca[i]]<<'\n';;
			ans=max(tr[trid[B]].query(min(trpos[B],trpos[lca[i]]),max(trpos[B],trpos[lca[i]])),ans);
			
			//cerr<<'\n';
			cout<<ans<<' ';
		}else{
			tr[trid[qr[i].a]].update(trpos[qr[i].a],qr[i].b);
		}
	}
	return 0;
}
