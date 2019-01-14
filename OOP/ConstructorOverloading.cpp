//
// Created by manik on 22/1/18.
//

#include <iostream>

using namespace std;

class ComplexNumber {
    int real, imaginary;

public:
    ComplexNumber(){};

    ComplexNumber(int equalValue) {
        imaginary = real = equalValue;
    }

    ComplexNumber(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }

    void printNumber() {
        cout << endl << real << " + " << imaginary << 'i';
    }

    void setReal(int val){
        real=val;
    }

    void setImaginary(int val){
        imaginary=val;
    }

    int getReal(){
        return real;
    }

    int getImaginary(){
        return imaginary;
    }
};

ComplexNumber getSum(ComplexNumber complexNumber1, ComplexNumber complexNumber2) {
    ComplexNumber sum;
    sum.setReal(complexNumber1.getReal() + complexNumber2.getReal());
    sum.setImaginary(complexNumber1.getImaginary() + complexNumber2.getImaginary());
    return sum;
}


ComplexNumber input() {
    cout << "Enter the real and imaginary values\t";
    int a, b;
    cin >> a >> b;
    if (a == b) return ComplexNumber(a);
    return ComplexNumber(a, b);
}

int main() {
    ComplexNumber sum;
    ComplexNumber first = input();
    ComplexNumber second = input();
    sum = getSum(first, second);
    sum.printNumber();
    return 0;
}