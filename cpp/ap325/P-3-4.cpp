#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    a[0]=1e8;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll sum=0;
    stack<int> s;
    s.push(0);
    for(int i=1;i<=n;i++){
        while(a[s.top()]<=a[i]) s.pop();
        sum+=i-s.top();
        s.push(i);
    }
    cout<<sum<<'\n';
    return 0;
}