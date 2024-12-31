#include<bits/stdc++.h>
using namespace std;
int n;
int a[200500];
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        for(int i=2;i<=n;i++){
                if(a[i]-a[i-1]>1) return cout<<a[i]-1<<'\n',0;
        }
}
