#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1e9+7;
int a[2][2]={{1,1},{1,0}},b[2][2]={
        {1,0},
        {0,1}
};
int n;
int ret[2][2];
void pw(){
        for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                        ret[i][j]=0;
                        for(int k=0;k<2;k++) ret[i][j]=(ret[i][j]+a[i][k]*a[k][j])%P;
                }
        }
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[i][j]=ret[i][j];
}
void pb(){
        for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                        ret[i][j]=0;
                        for(int k=0;k<2;k++) ret[i][j]=(ret[i][j]+a[i][k]*b[k][j])%P;
                }
        }
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) b[i][j]=ret[i][j];
}
void fp(int y){
        while(y){
                if(y&1) pb();
                pw();
                y>>=1;
        }
}
signed main(){
        cin>>n;
        fp(n-1);
        int ans=(b[0][0]+b[1][0]+b[0][1]+b[1][1])%P;
        cout<<ans<<'\n';
}
