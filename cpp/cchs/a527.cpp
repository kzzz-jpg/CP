#include<cstdio>
int a,b;
void print(char c[],bool res){
    printf("%d %s %d %s\n",a,c,b,res?"True":"False");
}
signed main(){
    scanf("%d%d",&a,&b);
    print("<",a<b);
    print("<=",a<=b);
    print(">",a>b);
    print(">=",a>=b);
    print("==",a==b);
    print("!=",a!=b);
}