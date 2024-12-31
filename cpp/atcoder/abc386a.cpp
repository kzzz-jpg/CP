#include<bits/stdc++.h>
using namespace std;
int a[4];
signed main(){
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    sort(a,a+4);
    if((a[0]==a[2]&&a[0]!=a[3])||(a[1]==a[0]&&a[3]==a[2]&&a[1]!=a[2])||(a[1]==a[3]&&a[0]!=a[3])) cout<<"Yes\n";
    else cout<<"No\n";
}