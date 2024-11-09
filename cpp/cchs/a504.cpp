#include<bits/stdc++.h>
using namespace std;
string s,op;
struct RGB{
	int r,g,b;
};
void cg(int &a,char c){
	if(c=='0'){
		a&=~1;
	}else a|=1;
}
signed main(){
	while(getline(cin,op)){
		if(op.back()==' ') op.pop_back();
		getline(cin,s);
		stringstream ss;
		ss<<s;
		vector<RGB> v;
		int a,b,c;
		while(ss>>a>>b>>c) v.push_back({a,b,c});
		reverse(op.begin(),op.end());
		for(int i=0;i<v.size()&&op.size();i++){
			if((v[i].r^v[i].g)&2){
				cg(v[i].r,op.back());
				op.pop_back();
			}
			if(op.size()==0) break;
			if((v[i].g^v[i].b)&2){
				cg(v[i].g,op.back());
				op.pop_back();
			}
			if(op.size()==0)break;
			if((v[i].b^v[i].r)&2){
				cg(v[i].b,op.back());
				op.pop_back();
			}
		}
		for(auto x:v){
			cout<<x.r<<' '<<x.g<<' '<<x.b<<' ';
		}
		cout<<'\n';
	}
}
