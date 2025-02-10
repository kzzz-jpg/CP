#include "bits/stdc++.h"
using namespace std;
int a[300500];
int b[300500];
int c[300500];
int n;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]=i;
    }
    
    for(int i=1;i<=n;i++){
        cout<<a[b[c[i]]]<<" \n"[i==n];
    }
}