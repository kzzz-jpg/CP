import java.io.*;
public class java{
    static int n,m;
    public static void main(String args[]) throws IOException{
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer in=new StreamTokenizer(br);
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        in.nextToken();
        n=(int)in.nval;
        in.nextToken();
        m=(int) in.nval;
        if((n-3)*(n-3)+(m-4)*(m-4)>10){
            out.println("Outside");
        }else{
            out.println("Inside");
        }
        out.flush();
        out.close();
        br.close();
    }
}