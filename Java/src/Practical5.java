import java.util.Scanner;

class MyException extends Exception {
    private String s;

    MyException(String s) {
        this.s = s;
    }

    public String toString() {
        return "Exception: " + s;
    }
}

public class Practical5 {
    public static void main(String[] args) {
        int bal, amt;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter balance:\t");
        bal = sc.nextInt();
        System.out.print("Enter withdrawal amount:\t");
        amt = sc.nextInt();

        try {
            bal = bal - amt;
            if (bal < 0) throw new MyException("Insufficient Balance");
        } catch (MyException e) {
            System.err.println(e);
        }
    }
}
