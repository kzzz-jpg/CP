#include<bits/stdc++.h>
using namespace std;
struct nd{
    int a,b,c,d;
} d[200001];
int n,k;
int ls=-1;
deque<int> op;
bool comp1(nd a,nd b){
    return a.a>b.a;
}
bool comp2(nd a,nd b){
    return a.b>b.b;
}
bool comp3(nd a,nd b){
    return a.c>b.c;
}
bool comp4(nd a,nd b){
    return a.d>b.d;
}
bool comp5(nd a,nd b){
    return a.a<b.a;
}
bool comp6(nd a,nd b){
    return a.b<b.b;
}
bool comp7(nd a,nd b){
    return a.c<b.c;
}
bool comp8(nd a,nd b){
    return a.d<b.d;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>d[i].a>>d[i].b>>d[i].c>>d[i].d;
    }
    for(int i=1;i<=k;i++){
        cin>>ls;
        if(op.size()&&op.back()==ls){
            op.pop_back();
            op.push_back(ls+4);
        }else{
            op.push_back(ls);
        }
    }
    //while(op.size()>30) op.pop_front();
    while(op.size()){
        int x=op.front();op.pop_front();
        if(x==1){
            sort(d+1,d+n+1,comp5);
        }else if(x==2){
            sort(d+1,d+n+1,comp6);
        }else if(x==3){
            sort(d+1,d+n+1,comp7);
        }else if(x==4){
            sort(d+1,d+1+n,comp8);
        }else if(x==5){
            sort(d+1,d+n+1,comp1);
        }else if(x==6){
            sort(d+1,d+n+1,comp2);
        }else if(x==7){
            sort(d+1,d+n+1,comp3);
        }else{
            sort(d+1,d+1+n,comp4);
        } 
    }
    for(int i=1;i<=n;i++){
        cout<<d[i].a<<' '<<d[i].b<<' '<<d[i].c<<' '<<d[i].d<<'\n';
    }
}