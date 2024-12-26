#include<bits/stdc++.h>
using namespace std;
int n,x,h;
int a[200500];
signed main(){
        cin>>n>>h>>x;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
                if(h+a[i]>=x) return cout<<i<<'\n',0;
        }
}
