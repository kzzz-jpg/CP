import java.io.*;
import java.util.Arrays;
public class java12B{
    public static long g[][]=new long[300][300];
    public static long n,m,ans=0;
    public static long tmp[]=new long[300];
    public static void solve(){
        long nw=0;
        for(int i=1;i<=m;i++){
            nw+=tmp[i];
            nw=Math.max(0,nw);
            ans=Math.max(ans,nw);
        }
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer in = new StreamTokenizer(br);
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        in.nextToken();
        n=(int)in.nval;
        in.nextToken();
        m=(int)in.nval;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                in.nextToken();
                g[i][j]=(int)in.nval;
            }
        }
        for(int i=1;i<=n;i++){
            Arrays.fill(tmp,0);
            for(int j=i;j<=n;j++){
                for(int k=1;k<=m;k++){
                    tmp[k]+=g[j][k];
                }
                solve();
            }
        }
        out.println(ans);
        out.flush();
        out.close();
        br.close();
    }
}
