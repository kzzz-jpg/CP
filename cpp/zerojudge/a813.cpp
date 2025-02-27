#include <algorithm>
#include<bits/stdc++.h>
#include <ios>
#define int long long
using namespace std;
int n,a[2000500],b[2000500];
deque<pair<int,int>> q;
int ans;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(q.size()&&a[q.back().first]<a[i]) ans+=q.back().second,q.pop_back();
        pair<int,int> tmp={i,0};
        if(q.size()&&a[q.back().first]==a[i]){
            tmp=q.back();
            q.pop_back();
            ans+=tmp.second;
        }
        if(q.size()) ans++;
        tmp.second++;
        q.push_back(tmp);
    }
    cout<<ans*2<<'\n';
}

// 4 2 3 3 2 