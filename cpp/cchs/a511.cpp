#include<bits/stdc++.h>
using namespace std;
string d,c,q;
string s;
int D[200500],C[200500],Q[200500],R[200500];
int sz=0;
vector<int> ans;
signed main(){
	getline(cin,d);
	sz=max(sz,(int)d.size());
	getline(cin,s);
	sz=max(sz,(int)s.size());
	getline(cin,s);
	sz=max(sz,(int)s.size());
	getline(cin,c);
	sz=max(sz,(int)c.size());
	getline(cin,s);
	sz=max(sz,(int)s.size());
	getline(cin,s);
	sz=max(sz,(int)s.size());
	getline(cin,q);
	sz=max(sz,(int)q.size());
	getline(cin,s);
	sz=max(sz,(int)s.size());
	getline(cin,s);
	sz=max(sz,(int)s.size());
	sz++;
	while(d.size()<sz) d.push_back(' ');
	while(c.size()<sz) c.push_back(' ');
	while(q.size()<sz) q.push_back(' ');
	for(int i=0;i<sz-1;i++)if(d[i]=='*'&&d[i+1]=='*') D[i]=1;
	for(int i=0;i<sz-1;i++)if(c[i]=='*'&&c[i+1]=='*') C[i]=1;
	for(int i=0;i<sz-1;i++)if(q[i]=='*'&&q[i+1]=='*') Q[i]=1;
	for(int i=1;i<sz;i++){
		if(C[i]==0) R[i]=R[i-1];
		else R[i]=D[i];
	}
	for(int i=0;i<sz;i++) if(R[i]^Q[i]) ans.push_back(i+1);
	if(ans.size()){
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<",\n"[i==(ans.size()-1)];
	}else cout<<"PASS\n";
}
