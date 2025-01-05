#include<bits/stdc++.h>
using namespace std;
int x,ans;
signed main(){
    cin>>x;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(i*j!=x) ans+=i*j;
        }
    }
    cout<<ans<<'\n';
}