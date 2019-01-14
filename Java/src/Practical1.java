import java.util.ArrayList;
import java.util.Scanner;

public class Practical1 {

    private static long factorial(int n) {
        long f = 1;
        for (int j = n; j > 0; j--) f *= j;
        return f;
    }

    private static boolean leap(int y) {
        return y % 4 == 0;
    }

    private static void fib(int n) {
        int a = 0, b = 1;
        System.out.println("Practical1 sequence for " + n + " is");
        for (int i = 0; i < n; i++) {
            System.out.print(a + ' ');
            b += a;
            a = b - a;
        }
    }

    private static boolean palindrome(int n) {
        int x = n;
        int tester = 0;
        while (x != 0) {
            tester *= 10;
            int rem = x % 10;
            tester += rem;
            x = x / 10;
        }
        return tester == x;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter number\t");
        int n = s.nextInt();
        System.out.println("The factorial of " + n + " is " + factorial(n));

        System.out.println("Enter year\t");
        n = s.nextInt();
        System.out.println("The year " + n + " is " +
                (leap(n) ? "" : "not ") +
                "a leap year");

        System.out.println("Enter number\t");
        n = s.nextInt();
        fib(n);

        System.out.println("Enter number\t");
        n = s.nextInt();
        System.out.println("The number " + n + " is " +
                (palindrome(n) ? "" : "not ") +
                "a palindrome");

        System.out.println("Enter array length\t");
        int max = Integer.MIN_VALUE;
        n = s.nextInt();
        System.out.println("Enter array\t");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = s.nextInt();
        for (int i = 0; i < n; i++) if (max < arr[i]) max = arr[i];
        System.out.println("The largest value in the array is " + max);
    }
}


// Last - Exception - use try catch and finally