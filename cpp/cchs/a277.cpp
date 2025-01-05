#include<bits/stdc++.h>
#define int long long
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
int a[200500],pl[200500],pr[200500];
int ans;

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
			ans+=ask(q[i].y);
			upd(q[i].y,1);
		}
		for(int i=ql;i<=qr;i++) upd(q[i].y,-1);
		return;
	}

	int mid=vl+vr>>1;
	
	int nl=0,nr=0;
	for(int i=ql;i<=qr;i++){
		if(q[i].z>mid){
			ans+=ask(q[i].y);
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

int n,l,r;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>l>>r;
    for(int i=1;i<=n;i++) cin>>a[i],pl[i]=pr[i]=a[i],pl[i]-=l,pr[i]-=r,pr[i]+=pr[i-1],pl[i]+=pl[i-1];
    vector<int> lsh(pl+1,pl+2+n);
    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
    for(int i=1;i<=n+1;i++) pr[i]=-pr[i],pl[i]=lower_bound(lsh.begin(),lsh.end(),pl[i])-lsh.begin()+1;
    vector<int> lsh2(pr+1,pr+2+n);
    sort(lsh2.begin(),lsh2.end());
    lsh2.erase(unique(lsh2.begin(),lsh2.end()),lsh2.end());
    for(int i=1;i<=n+1;i++) pr[i]=lower_bound(lsh2.begin(),lsh2.end(),pr[i])-lsh2.begin()+1;
	for(int i=1;i<=n;i++) {
		q[i]=node(i,i,pl[i],pr[i]);
	}
    q[n+1]=node(n+1,0,pl[n+1],pr[n+1]);
	sort(q+1,q+2+n);
	solve(1,200500,1,n+1);
	cout<<ans<<'\n';
}