#include<stdio.h>
const int S = 1<<20; // buffer size
char buf[S], *p = buf, *q = buf;
char readchar() {
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}
int nextint() {
	int x = 0, c = readchar(), neg = 0;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
	if(c == '-') neg = 1, c = readchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
	if(neg) x = -x;
	return x; // returns 0 if EOF
}
inline void output(int _x){
    if(!_x) putchar('0');
    char _buff[20]; int _f = 0;
    while(_x > 0)
    {
        _buff[_f++] = _x%10+'0';
        _x /= 10;
    }
    for(_f-=1; _f >= 0; _f--)
        putchar(_buff[_f]);
    putchar('\n');
}
const int P=10009;
int n,m,a[100500],tr[400500];
void build(int l,int r,int id){
	if(l==r){
		tr[id]=a[l]%P;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	tr[id]=(tr[id<<1]+tr[id<<1|1])%P;
}
int query(int l,int r,int L,int R,int id){
	if(l>R||r<L) return 0;
	if(L<=l&&r<=R) return tr[id];
	int mid=l+r>>1;
	return (query(l,mid,L,R,id<<1)+query(mid+1,r,L,R,id<<1|1))%P;
}
signed main(){
	n=nextint(),m=nextint();
	for(int i=1;i<=n;i++) a[i]=nextint();
	build(1,n,1);
	int l,r;
	while(m--){
		l=nextint(),r=nextint();
		output(query(1,n,l,r,1));
	}
}
