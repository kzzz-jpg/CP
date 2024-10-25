#include<bits/stdc++.h>
using namespace std;
string s;
map<char,int> ct;
struct nd{
	int cnt;
	string nw;
	nd(int C,string N):cnt(C),nw(N){}
	bool operator <(nd o) const{
		return cnt>o.cnt;
	}
};
priority_queue<nd> pq;
signed main(){
	cin>>s;
	for(auto x:s){
		ct[x]++;
	}
	for(auto x:ct){
        string tmp;
        tmp.push_back(x.first);
        pq.push(nd(x.second,tmp));
        ct[x.first]=0;
    }
	while(pq.size()>1){
		auto tp=pq.top();pq.pop();
		auto tp2=pq.top();pq.pop();
		for(auto x:tp.nw) ct[x]++;
		for(auto x:tp2.nw) ct[x]++;
		pq.push(nd(tp.cnt+tp2.cnt,tp.nw+tp2.nw));
	}
	int ori=s.size()*8;
	int aft=0;
	for(auto x:s) aft+=ct[x];
	cout<<ori<<' '<<aft<<' '<<(int)(100*(ori-aft)/ori)<<"%\n";
}