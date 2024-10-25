#include<bits/stdc++.h>
using namespace std;
bool cmp1(pair<long long,long long> a,pair<long long,long long> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
void ChungAlwaysAC(){
    long long n;
    cin>>n;
    deque<pair<long long,long long>> dq;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        dq.push_back(make_pair(a,b));
    }
    sort(dq.begin(), dq.end(), cmp1);
    long long total=0;
    long long now=-1;
    while(!dq.empty()){
        if(dq.front().first>now){
            now=dq.front().second;
            total++;
        }
        dq.pop_front();
    }
    cout<<total<<endl;
}
int main(){
    ChungAlwaysAC();
    return 0;
}