#include<bits/stdc++.h>
using namespace std;
int n;
int a[4][102][102];
int b[102][102];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[0][i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>b[i][j];
    for(int k=1;k<=3;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[k][i][j]=a[k-1][n+1-j][i];
            }
        }
    }
    for(int k=0;k<4;k++){
        bool chk=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[k][i][j]==1&&b[i][j]==0) chk=0;
            }
        }
        if(chk){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
}
