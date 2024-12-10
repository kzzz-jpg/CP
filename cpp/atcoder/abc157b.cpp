#include<bits/stdc++.h>
using namespace std;
int g[3][3];
bool vs[3][3];
int n;
signed main(){
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        cin>>g[i][j];
                }
        }
        cin>>n;
        int x;
        while(n--){
                cin>>x;
                for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                                if(g[i][j]==x) vs[i][j]=1;
                        }
                }
        }
        if((vs[0][0]&&vs[0][1]&&vs[0][2])||(vs[1][0]&&vs[1][1]&&vs[1][2])||(vs[2][0]&&vs[2][1]&&vs[2][2])||(vs[0][0]&&vs[1][0]&&vs[2][0])||(vs[0][1]&&vs[1][1]&&vs[2][1])||(vs[0][2]&&vs[1][2]&&vs[2][2])||(vs[0][0]&&vs[1][1]&&vs[2][2])||(vs[2][0]&&vs[1][1]&&vs[0][2])) cout<<"Yes\n";
        else cout<<"No\n";
}
