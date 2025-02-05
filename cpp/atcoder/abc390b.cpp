#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100500];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<n;i++){
        if(a[i]*a[i]!=a[i-1]*a[i+1]){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
}