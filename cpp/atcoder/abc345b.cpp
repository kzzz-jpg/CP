#include<bits/stdc++.h>
#define int long long
using namespace std;
int x;
signed main(){
        cin>>x;
        if(x<=0) cout<<(x/10)<<'\n';
        else cout<<(x/10+bool(x%10))<<'\n';
}
