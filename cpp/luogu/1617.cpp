#include<bits/stdc++.h>
using namespace std;
string num[]={"","one","two","three","four","five","six","seven","eight","nine"};
string tennum[]={"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string ten[]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
int n,a,b,c,d;
signed main(){
	cin>>n;
	a=n/1000;
	b=(n/100)%10;
	c=(n/10)%10;
	d=n%10;
	if(a){
		cout<<num[a]<<' '<<"thousand ";
	}
	if(b){
		cout<<num[b]<<' '<<"hundred ";
	}
	if(c!=0&&b==0&&a!=0) cout<<"and ";
	if(c<=1){
		if((a!=0||b!=0)&&c==0) cout<<"and ";
		if(b!=0&&c==1&&d==0) cout<<"and ";
		cout<<ten[c*10+d];
	}else{
		cout<<tennum[c]<<' ';
		if(d) cout<<num[d];
	}
}
