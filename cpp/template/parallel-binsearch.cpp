#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+100;
struct node{
	int op;
	int x,y,k;
	int id;
	node(int O=0,int X=0,int Y=0,int K=0,int I=0):op(O),x(X),y(Y),k(K),id(I){}
} q[MAXN],lq[MAXN],rq[MAXN];
int ans[MAXN];

int fw[MAXN];
void upd(int x,int v){
	for(;x<MAXN;x+=x&(-x)) fw[x]+=v;
}
int query(int x){
	int ret=0;
	for(;x>0;x-=x&(-x)) ret+=fw[x];
	return ret;
}

void solve(int vl,int vr,int ql,int qr){
	if(vl>vr||ql>qr) return;
	if(vl==vr){
		for(int i=ql;i<=qr;i++){
			if(q[i].op==2){
				ans[q[i].id]=vl;
			}
		}
		return ;
	}
	int mid=vl+vr>>1;

	int nl=0,nr=0;
	for(int i=ql;i<=qr;i++){
		if(q[i].op==1){
			if(q[i].x<=mid){
				upd(q[i].id,1);
				lq[++nl]=q[i];
			}else rq[++nr]=q[i];
		}else{
			int n=query(q[i].y)-query(q[i].x-1);
			if(q[i].k<=n){
				lq[++nl]=q[i];
			}else{
				q[i].k-=n;
				rq[++nr]=q[i];
			}
		}
	}
	for(int i=ql;i<=qr;i++){
		if(q[i].op==1){
			if(q[i].x<=mid){
				upd(q[i].id,-1);
			}
		}
	}
	for(int i=1;i<=nl;i++) q[i+ql-1]=lq[i];
	for(int i=1;i<=nr;i++) q[i+ql+nl-1]=rq[i];
	solve(vl,mid,ql,ql+nl-1);
	solve(mid+1,vr,ql+nl,qr);
}

int n,m;
signed main(){
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		q[i]=node(1,x,0,0,i);
	}
	int l,r,k;
	for(int i=1;i<=m;i++){
		cin>>l>>r>>k;
		q[i+n]=node(2,l,r,k,i);
	}
	solve(0,1e9,1,n+m);
	for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';;
}
