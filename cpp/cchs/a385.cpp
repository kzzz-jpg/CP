#include<bits/stdc++.h>
using namespace std;
int l,w,h,fc;
int a[7];
signed main(){
	cin>>l>>w>>h;
	for(int i=1;i<=l;i++){
		for(int j=1;j<=w;j++){
			for(int k=1;k<=h;k++){
				fc=0;
				if(i==1) fc++;
				if(i==l) fc++;
				if(j==1) fc++;
				if(j==w) fc++;
				if(k==1) fc++;
				if(k==h) fc++;
				a[fc]++;
			}
		}
	}
	sort(a,a+7,greater<int>());
	cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<'\n';
}
