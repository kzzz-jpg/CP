#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
struct ln{
	double a,b;
	int xmi,xma;
	double operator()(int x){
		if(x>xma||x<xmi) return -INF;
		return a*x+b;
	}
	void gi(int _x1,int _x2,int _y1,int _y2){
		if(_x1>_x2) swap(_x1,_x2),swap(_y1,_y2);
		xmi=_x1,xma=_x2;
		a=double(_y1-_y2)/double(_x1-_x2);
		b=(double(_y2)-a*_x2);
	}
} line[100500];
int cnt=0;
int tr[600500];
int n,ans;
bool chk_gt(int a,int b,int x){
	if(line[a](x)>line[b](x)) return 1;
	else return 0;
}
void tag(int id,int l,int r,int x);
void insrt(int id,int l,int r,int x){
	if(line[x].xmi<=l&&r<=line[x].xma) tag(id,l,r,x);
	int mid=l+r>>1;
	if(line[x].xma<=mid) insrt(id<<1,l,mid,x);
	if(line[x].xmi>mid) insrt(id<<1|1,mid+1,r,x);
}
void tag(int id,int l,int r,int x){
	if(!tr[id]) tr[id]=x;
	if(l==r){
		if(chk_gt(x,tr[id],l)) tr[id]=x;
		return;
	}
	int mid=l+r>>1;
	if(chk_gt(x,tr[id],mid)) swap(tr[id],x);
	if(chk_gt(tr[id],x,l)&&chk_gt(tr[id],x,r)) return;
	if(chk_gt(x,tr[id],l)) tag(id<<1,l,mid,x);
	else tag(id<<1|1,mid+1,r,x);
}
int query(int id,int l,int r,int x){
	int mn=tr[id],m2;
	if(l==r) return mn;
	int mid=l+r>>1;
	if(x<=mid) m2=query(id<<1,l,mid,x);
	else m2=query(id<<1|1,mid+1,r,x);
	if(m2==0||chk_gt(mn,m2,x)) return mn;
	return m2;
}
signed main(){
	cin>>n;
	int x1,x2,y1,y2,x,op;
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op==1){
			cin>>x1>>y1>>x2>>y2;
			x1=(x1+ans-1)%39989+1;
			x2=(x2+ans-1)%39989+1;
			y1=((y1+ans-1)%(int)1e9)+1;
			y2=((y2+ans-1)%(int)1e9)+1;
			line[++cnt].gi(x1,x2,y1,y2);
			insrt(1,0,400000,cnt);
		}else{
			cin>>x;
			x=(x+ans-1)%39989+1;
			ans=query(1,0,400000,x);
			cout<<ans<<'\n';
		}
	}
}
