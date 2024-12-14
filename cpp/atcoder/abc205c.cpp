#include<bits/stdc++.h>
using namespace std;
int a,b,c;
signed main(){
        cin>>a>>b>>c;
        if(c&1){
                if(a>b){
                        cout<<">\n";
                }else if(a<b){
                        cout<<"<\n";
                }else cout<<"=\n";
        }else{
                if(abs(a)>abs(b)) cout<<">\n";
                else if(abs(a)<abs(b)) cout<<"<\n";
                else cout<<"=\n";
        }
}
