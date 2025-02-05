#include<bits/stdc++.h>
using namespace std;
double g[105][105];
double sml=1e-9;
int n;
void gauss(){
    for(int i=1;i<=n;i++){
        int mx=i;
        for(int j=1;j<=n;j++){
            if(j<i&&abs(g[j][j])>sml) continue;
            if(abs(g[j][i])>abs(g[mx][i])) mx=j;
        }
        for(int j=1;j<=n+1;j++) swap(g[i][j],g[mx][j]);
        if(abs(g[i][i])<sml) continue;
        double tmp=g[i][i];
        for(int j=1;j<=n+1;j++) g[i][j]/=tmp;
        for(int j=1;j<=n;j++){
            tmp=g[j][i]/g[i][i];
            if(i==j) continue;
            for(int k=1;k<=n+1;k++){
                g[j][k]-=g[i][k]*tmp;
            }
        }
    }
}
signed  main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++) cin>>g[i][j];
    }
    gauss();
    for(int i=1;i<=n;i++){
        if(abs(g[i][i])<sml){
            cout<<"No Solution\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<fixed<<setprecision(2)<<g[i][n+1]<<'\n';
    }
}