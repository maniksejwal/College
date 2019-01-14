import java.util.Scanner;

class A {
    final int i = 10;

    A() {
    }

    void methodA(){
        System.out.println("A");
    }
}

class B extends A {
    B(){}
    void methodB(){
        System.out.println("B");
    }
}

class C extends B {
    C(){}
    void methodC(){
        System.out.println(super.i);
        System.out.println("C");
    }
}

class D extends A {
    D(){}
    void methodD(){
        System.out.println(super.i);
        System.out.println("D");
    }
}

public class Practical3b {
    public static void main(String[] args) {
        C ob = new C();
        ob.methodC();
        D obj = new D();
        obj.methodD();

        A cast = new D();
        cast.methodA();
        //ignore the warning. the cast is only for demonstration
        ((D) cast).methodD();
    }
}