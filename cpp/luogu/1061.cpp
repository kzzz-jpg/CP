#include<bits/stdc++.h>
using namespace std;
char alp[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
string str;
int s,t,l;
signed main(){
	cin>>s>>t>>l;
	cin>>str;
	for(int _=0;_<5;_++){
		int i;
		bool flag=0;
		for(i=str.size()-1;i>=0;i--){
			if(str[i]-'a'+1==t||(i+1<str.size()&&str[i]+1==str[i+1])) continue;
			str[i]++;
			flag=1;
			break;
		}
		if(!flag) break;
		for(i++;i<str.size();i++) str[i]=str[i-1]+1;
		cout<<str<<'\n';
	}
}
