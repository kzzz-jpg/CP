#include<stdio.h>
int n,k,a[200500];
int getn(int x){
	int ret=0;
	for(int i=1;i<=n;i++) if(a[i]<=x) ret++;
	return ret;
}
signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	int l=-1e9,r=1e9;
	while(l<r){
		int mid=l+r>>1;
		if(getn(mid)<k) l=mid+1;
		else r=mid;
	}
	for(int i=1;i<=n;i++) if(a[i]==l) {printf("%d %d\n",l,i);return 0;}
}
