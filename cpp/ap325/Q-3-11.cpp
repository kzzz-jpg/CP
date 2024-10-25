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
    int maxs=1;
    for(int i=0;i<N;i++){
        cin>>t;
        seq.push_back(t);
    }
    int l=0;
    int nm=1;
    for(int i=0;i<N;i++,nm++){
        mp[(seq[i])]++;
        while(mp[seq[i]]>1){
            mp[seq[l]]--;
            nm--;
            l++;
        }
        maxs=max(nm,maxs);
    }
    cout<<maxs<<endl;
    return 0;
}