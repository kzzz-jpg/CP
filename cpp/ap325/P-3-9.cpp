#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MI 1<<30
signed main(){
    vector<int> cou(1e7,0);
    vector<int> seq;
    int N,L;
    cin>>N>>L;
    int t;
    int maxs=0;
    for(int i=0;i<N;i++){
        cin>>t;
        seq.push_back(t);
    }
    for(int i=0;i<L;i++){
        if(cou[seq[i]]==0) maxs++;
        cou[seq[i]]++;
    }
    int l=0;
    int nm=maxs;
    for(int i=L;i<N;i++){
        if(cou[seq[i]]==0) nm++;
        cou[seq[i]]++;
        cou[seq[l]]--;
        if(cou[seq[l]]==0) nm--;
        l++;
        maxs=max(nm,maxs);
    }
    cout<<maxs<<endl;
    return 0;
}