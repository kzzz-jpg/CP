#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MI 1<<30
vector<int> seq;
deque<int> maxi;
deque<int> mini;
void pmax(int n){
    while(!maxi.empty()&&(seq[maxi.back()]<=seq[n])) maxi.pop_back();
    maxi.push_back(n);
}
void pmin(int n){
    while(!mini.empty()&&(seq[mini.back()]>=seq[n])) mini.pop_back();
    mini.push_back(n);
}
signed main(){
    int N,L;
    cin>>N>>L;
    int t;
    int maxs=0;
    for(int i=0;i<N;i++){
        cin>>t;
        seq.push_back(t);
    }
    for(int i=0;i<N;i++){
        if(maxi.front()<=i-L) maxi.pop_front();
        pmax(i);
        if(mini.front()<=i-L) mini.pop_front();
        pmin(i);
        int now=seq[maxi.front()]-seq[mini.front()];
        maxs=max(now,maxs);
    }
    cout<<maxs<<endl;
    return 0;
}