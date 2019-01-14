import java.util.Scanner;

public class Practical3a {
    private static void println(String s) {
        System.out.println(s);
    }

    private static class FStack {
        int[] ani;
        int curIndex = 0;
        int size;

        FStack(int size) {
            this.size = size;
            ani = new int[size];
        }
    }

    public static class AStack extends FStack{

        AStack(int size) {
            super(size);
        }

        void aPush(int a){
            if(curIndex==size) println("Overflow");
            else ani[curIndex++] = a;
        }

        int aPop(){
            int a = -1;
            if(curIndex==0) println("Empty Stack");
            else a=ani[--curIndex];
            return a;
        }
    }

    public static void main(String[] args) {
        AStack aStack = new AStack(1000);
        Scanner scanner = new Scanner(System.in);
        int a = 45;
        aStack.aPush(a);
        println(Integer.toString(aStack.curIndex));
        println(String.valueOf(aStack.aPop()));
    }
}
