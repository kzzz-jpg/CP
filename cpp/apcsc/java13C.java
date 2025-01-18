
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.*;
public class java13C{
    static int n,m,t;
    static boolean vs[] = new boolean[10];
    static Map<String,Integer> mp = new HashMap<>();
    static String str = new String();
    static int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    static void solve(int k,int p,int q){
        
        if(k==n+m){
            int gd=gcd(p,q);
            //System.err.println(p+" "+q+" "+gd);
            String key=String.valueOf(p/gd)+"/"+String.valueOf(q/gd);
            //System.err.println(key);
            mp.put(key,mp.getOrDefault(key,0)+1);
            return;
        }
        for(int i=1;i<=n+m;i++){
            if(!vs[i]){
                vs[i]=true;
                if(k<n){
                    solve(k+1,p*10+i,q);
                }else{
                    solve(k+1,p,q*10+i);
                }
                vs[i]=false;
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer in = new StreamTokenizer(br);
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        in.nextToken();
        n=(int)in.nval;
        in.nextToken();
        m=(int)in.nval;
        in.nextToken();
        t=(int)in.nval;
        solve(0,0,0);
        for(int i=1;i<=t;i++){
            in.nextToken();
            str=String.valueOf((int)in.nval);
            in.nextToken();
            str+="/";
            in.nextToken();
            str+=String.valueOf((int)in.nval);
            System.err.println(str);
            out.println(mp.getOrDefault(str, 0));
        }
        out.flush();
        out.close();
        br.close();
    }
}