#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int f(int x){
        if(x==0) return 1;
        return x*f(x-1);
}
signed main(){
        cin>>n;
        cout<<f(n)<<'\n';
}
