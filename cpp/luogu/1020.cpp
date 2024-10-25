#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    vector<int> lis,lds;
    vector<int> v;
    while(cin>>t) v.push_back(t);
    for(auto x:v){
        auto it=lower_bound(lis.begin(),lis.end(),x);
        if(it==lis.end()) lis.push_back(x);
        else *it=x;
    }
    reverse(v.begin(),v.end());
    for(auto x:v){
        auto it=upper_bound(lds.begin(),lds.end(),x);
        if(it==lds.end()) lds.push_back(x);
        else *it=x;
    }
    cout<<lds.size()<<'\n'<<lis.size()<<'\n';
}