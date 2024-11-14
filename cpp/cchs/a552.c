#include<stdio.h>
const int P=1e9+7;
int n;
int a,b,c,d,e,f,ans=1;
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a=b;
		b=c;
		c=d;
		d=e;
		e=f;
		f=ans;
		ans=(((a+b)%P+c)%P+((d+e)%P+f)%P)%P;
	}
	printf("%d\n",ans);
}

