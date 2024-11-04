#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,x,y,z,ans;
	node(int I=0,int X=0,int Y=0,int Z=0):id(I),x(X),y(Y),z(Z),ans(0){}
	bool operator <(node o) const{
		if(x==o.x) {
			if(o.y==y) return z<o.z;
			return y<o.y;
		}
		return x<o.x;
	}
} q[100500],lq[100500],rq[100500];

int ans[100500];

int fw[300000];
void upd(int x,int v){
	for(;x<300000;x+=x&-x){
		fw[x]+=v;
	}
}
int ask(int x){
	int ret=0;
	for(;x;x-=x&-x){
		ret+=fw[x];
	}
	return ret;
}

void solve(int vl,int vr,int ql,int qr){
	if(vl>vr||ql>qr) return;
	if(vl==vr){
		for(int i=ql;i<=qr;i++){
			q[i].ans+=ask(q[i].y);
			ans[q[i].ans]+=1;
			upd(q[i].y,1);
		}
		for(int i=ql;i<=qr;i++) upd(q[i].y,-1);
		return;
	}

	int mid=vl+vr>>1;
	
	int nl=0,nr=0;
	for(int i=ql;i<=qr;i++){
		if(q[i].z>mid){
			q[i].ans+=ask(q[i].y);
			rq[++nr]=q[i];
		}else{
			lq[++nl]=q[i];
			upd(q[i].y,1);
		}
	}

	for(int i=ql;i<=qr;i++){
		if(q[i].z<=mid) upd(q[i].y,-1);
	}

	for(int i=1;i<=nl;i++) q[i+ql-1]=lq[i];
	for(int i=1;i<=nr;i++) q[i+ql+nl-1]=rq[i];

	solve(vl,mid,ql,ql+nl-1);
	solve(mid+1,vr,ql+nl,qr);
}

int n,k;
signed main(){
	cin>>n>>k;
	int x,y,z;
	for(int i=1;i<=n;i++) {
		cin>>x>>y>>z;
		q[i]=node(i,x,y,z);
	}
	sort(q+1,q+1+n);
	solve(1,k+10,1,n);
	for(int i=0;i<n;i++) cout<<ans[i]<<'\n';
}
