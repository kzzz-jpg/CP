#include "bits/stdc++.h"
#include <algorithm>
using namespace std;
int a[4];
signed main(){
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    do{
        if(a[0]*a[1]==a[2]){
            cout<<"Yes\n";
            return 0;
        }
    }while(next_permutation(a,a+3));
    cout<<"No\n";
}