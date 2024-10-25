#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MI 1<<30
signed main(){
    map<int,int> mp;
    vector<int> seq;
    int N;
    cin>>N;
    int t;
    int nc=0;
    int maxs=2e5;
    for(int i=0;i<N;i++){
        cin>>t;
        seq.push_back(t);
        mp[seq[i]]=0;
    }
    for(auto a:mp) nc++;
    int l=0;
    int color=0;
    for(int i=0;i<N;i++){
        if(mp[seq[i]]==0) color++;
        mp[(seq[i])]++;
        while(mp[seq[l]]>1){
            mp[seq[l]]--;
            l++;
        }
        if(nc==color) maxs=min(i-l+1,maxs);
    }
    cout<<maxs<<endl;
    return 0;
}