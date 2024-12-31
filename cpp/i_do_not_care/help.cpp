#include<bits/stdc++.h>
using namespace std;
int a[11][11];
signed main(){
   for(int i=0;i<=10;i++){
    for(int j=0;j<=10;j++){
        a[i][j]=10*i+j;
        cout<<a[i][j]<<' ';
    }
    cout<<'\n';
}
}