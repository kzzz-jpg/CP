#include<bits/stdc++.h>
using namespace std;
int a[6];
bool chk(int b[]){
    for(int i=2;i<=5;i++){
        if(a[i]<a[i-1]) return 0;
    }
    return 1;
}
signed main(){
   for(int i=1;i<=5;i++) cin>>a[i];
   for(int i=1;i<=4;i++){
    swap(a[i],a[i+1]);
    if(chk(a)) {
        cout<<"Yes\n";
        return 0;
    }
    swap(a[i],a[i+1]);
   }
   cout<<"No\n";
}