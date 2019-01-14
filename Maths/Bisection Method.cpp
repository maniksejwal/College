//
// Created by manik on 22/1/18.
//

#include <iostream>

using namespace std;

bool isLogEnabled = true;

void log(const char message[]) {
    if (isLogEnabled) cout << "\nLog:\t" << message;
}

void log(const char tag[], const char message[]) {
    if (isLogEnabled) cout << "\nLog-" << tag << ":\t" << message;
}

double f(double x) {
    return x * x * x - 4 * x - 9;
}

double bisectionMethod() {
    double a, b, c;
    int iter;
    cout << "Enter the max number of iterations\t";
    cin >> iter;
    cout << "\nEnter the coefficients a and b\t";
    cin >> a >> b;
    bool found = false;

    for (int i = 0; i < iter && !found; i++) {
        double ff = f(a) * f(b);
        if (ff < 0) {
            c = (a + b) / 2;
            if (f(a) * f(c) < 0) b = c;
            else a = c;
            if ((a - b < 0.0001 && a - b > 0) || (b - a < 0.0001 && b - a > 0)) found = true;
        } else if (ff == 0) found = true;
        else break;
    }

    if (found) cout << "\nRoot is\t" << (a + b) / 2;
    else cout << "\nRoots lie outside the range. a = " << a << ", b= " << b;
}

double regulaFalsiMethod() {
    double a, b, c = 0;
    int iter;
    cout << "Enter the max number of iterations\t";
    cin >> iter;
    cout << "\nEnter the coefficients a and b\t";
    cin >> a >> b;
    bool found = false;
    double fc = 0;
    for (int i = 0; i < iter && !found; i++) {
        cout << "i=" << i;
        double fa = f(a), fb = f(b);
        cout << "fa=" << fa << ",fb=" << fb;
        double ff = fa * fb;
        if (ff < 0) {
            c = (a * fb - b * fa) / (fb - fa);
            cout << "c=" << c;
            fc = f(c);
            if (fa * fc < 0) b = c;
            else a = c;
            if (0 <fc && fc < 0.001) found = true;
        } else break;
        cout<<endl;
        if(i==iter-1) found = true;
    }

    if (found) cout << "\nRoot is\t" << c << "fc = " << fc;
    else cout << "\nRoots lie outside the range. a = " << a << ", b= " << b;
}

int main() {
    cout << "Chose method\n Bisection Method\t0\n Regula-Falsi Method\t1\n";
    int a;
    cin >> a;
    switch (a) {
        case 0:
            bisectionMethod();
            break;
        case 1:
            regulaFalsiMethod();
        default:
            break;
    }
    return 0;
}