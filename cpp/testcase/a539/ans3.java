import java.io.*;
public class ans3{
    public static int n,k,l=(int)-1e9,r=(int)1e9;
    public static final int MAXN=200001;
    public static int a[]=new int[MAXN];
    public static int getn(int x){
        int ret=0;
        for(int i=1;i<=n;i++) if(a[i]<=x) ret++;
        return ret;
    }
    public static void main(String[] args)throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer in=new StreamTokenizer(br);
        PrintWriter out=new PrintWriter(new OutputStreamWriter(System.out));
        in.nextToken();
        n=(int)in.nval;
        in.nextToken();
        k=(int)in.nval;
        in.nextToken();
        for(int i=1;i<=n;i++) {
            a[i]=(int)in.nval;
            in.nextToken();
        }
        while(l<r){
            int mid=l+r>>1;
            if(getn(mid)<k) l=mid+1;
            else r=mid;
        }
        for(int i=1;i<=n;i++){
            if(a[i]==l){
                out.print(l);
                out.print(' ');
                out.print(i);
                break;
            }
        } 
        out.flush();
        out.close();
        br.close();
    }
}