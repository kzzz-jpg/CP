import java.io.*;
public class java12A{
    public static int t,n;
    public static int solve(int x){
        int ret=0;
        for(int i=1;i<=x;i++){
            for(int j=i+1;j<=x;j++){
                for(int k=j+1;k<=x;k++){
                    if(i+j>k) ret++;
                }
            }
        }
        return ret;
    }
    public static void main(String args[]) throws  IOException{
        BufferedReader br=new  BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer in=new StreamTokenizer(br);
        PrintWriter out=new PrintWriter(new OutputStreamWriter(System.out));
        in.nextToken();
        t=(int)in.nval;
        while(t-->0){
            in.nextToken();
            n=(int)in.nval;
            out.println(solve(n));
        }
        out.flush();
        out.close();
        br.close();
    }
}