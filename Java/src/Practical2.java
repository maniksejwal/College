import java.util.Scanner;
import java.util.Stack;

public class Practical2 {
    private static Scanner scanner;

    private static void print(String s) {
        System.out.print(s);
    }

    private static void println(String s) {
        System.out.println(s);
    }

    private static void greeting() {
        print("Enter marks:\t");
        float marks = scanner.nextFloat();
        String s;
        if (marks >= 80) s = "Congratulations, You are the best";
        else if (marks > 40) s = "Congratulations, You have passed the exam";
        else s = "You have failed to pass the exam";
        println(s);
    }

    private static void area() {
        print("Enter radius:\t");
        float radius = scanner.nextFloat();
        println("Area of circle is " + (Math.PI * radius * radius));
    }

    private static void sumAndAvg() {
        print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int[] a = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            sum += a[i];
        }
        println("Sum = " + sum);
        println("Average = " + 1.0*sum/n);
    }

    private static void stackPush(Stack<Integer> stack, int a){
        stack.push(a);
        println("Pushed to stack");
        println("Stack:\t" + stack);
    }

    private static void stackPop(Stack stack){
        println("Popped " + stack.pop() + " from the stack");
        println("Stack:\t" + stack);
    }

    public static void main(String[] args) {
        scanner = new Scanner(System.in);
        greeting();
        area();
        sumAndAvg();
        Stack<Integer> stack = new Stack<>();
        stackPush(stack,40);
        stackPush(stack,30);
        stackPop(stack);
        stackPush(stack,20);
        stackPop(stack);
    }
}
