#include<bits/stdc++.h>
using namespace std;
vector<int> a;
void f(int i){
    if(i==a.size()){
        printf("%d",a[a.size()-1]+1);
        return;
    }
    if(i!=a[i]-1){
        printf("%d",i+1);
        return;
    }
    f(i+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    int m;
    for(int i=0;i<n-1;i++){
        scanf("%d",&m);
        a.push_back(m);
    }
    sort(a.begin(),a.end());
    f(0);
    return 0;
}
