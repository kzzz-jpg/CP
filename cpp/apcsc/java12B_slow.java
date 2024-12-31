import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;

public class java12B_slow {
    public static long g[][]=new long[300][300];
    public static long n,m,ans=0;
    public static void init(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                g[i][j]=g[i][j]+g[i-1][j]+g[i][j-1]-g[i-1][j-1];
            }
        }
    }
    public static void init_mid(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                g[i][j]+=g[i][j-1];
            }
        }
    }
    public static long query(int x1,int y1,int x2,int y2){  //O( n^2 * m^2 )
        return g[x2][y2]-g[x2][y1-1]-g[x1-1][y2]+g[x1-1][y1-1];
    }
    public static long query_mid(int x1,int y1,int x2,int y2){  // O( n^3 * m^2 )
        long ret=0;
        for(int i=x1;i<=x2;i++){
            ret+=g[i][y2]-g[i][y1-1];
        }
        return ret;
    }
    public static long query_slow(int x1,int y1,int x2,int y2){  // O( n^3 * m^3 )
        long ret=0;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++) ret+=g[i][j];
        }
        return ret;
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
        init_mid();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int x=i;x<=n;x++){
                    for(int y=j;y<=m;y++){
                        ans=Math.max(ans,query_mid(i,j,x,y));
                    }
                }
            }
        }
        out.println(ans);
        out.flush();
        out.close();
        br.close();
    }
}
