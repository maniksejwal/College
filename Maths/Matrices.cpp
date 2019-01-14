#include <iostream>
#include <vector>

using namespace std;

bool isLogEnabled = false;

void log(const char message[]) {
    if (isLogEnabled) cout << "\nLog:\t" << message;
}

void log(const char tag[], const char message[]) {
    if (isLogEnabled) cout << "\nLog-" << tag << ":\t" << message;
}

void output(vector<vector<int>> m, int rows, int columns) {
    cout << "Output\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

vector<vector<int>> input(vector<vector<int>> m, int rows, int columns) {
    cout << "Enter the matrix\n";
    for (int i = 0; i < rows; i++) {
        vector<int> a;
        for (int j = 0; j < columns; j++) {
            int b;
            cin >> b;
            a.push_back(b);
        }
        m.push_back(a);
    }
    return m;
}

vector<vector<int>> add(vector<vector<int>> m1, vector<vector<int>> m2, int rows, int columns) {
    vector<vector<int>> m3;
    for (int i = 0; i < rows; ++i) {
        vector<int> a;
        for (int j = 0; j < columns; ++j) {
            a.push_back(m1[i][j] + m2[i][j]);
        }
        m3.push_back(a);
    }
    return m3;
}

vector<vector<int>> transpose(vector<vector<int>> m, int rows, int columns) {
    if (isLogEnabled) output(m, rows, columns);

    vector<vector<int>> transpose;
    for (int i = 0; i < columns; ++i) {
        vector<int> a;
        for (int j = 0; j < rows; ++j) {
            a.push_back(m[j][i]);
            log("push_back() to vector<int> successful");
        }
        transpose.push_back(a);
        log("push_back() to vector<vector<int>> successful");
    }
    log("transpose() complete");
    return transpose;
}

vector<vector<int>> multiply(
        vector<vector<int>> m1, int rows1, int columns1, vector<vector<int>> m2, int columns2) {
    vector<vector<int>> m;
    for (int i = 0; i < rows1; i++) {
        vector<int> a;
        for (int j = 0; j < columns2; j++) {
            int sum = 0;
            for (int k = 0; k < columns1; k++) {
                sum = sum + m1[i][k] * m2[k][j];
            }
            log("loop 3 complete");

            a.push_back(sum);
            log(sum + "");
        }
        m.push_back(a);
        log("loop 2 complete");
    }
    log("loop 1 complete");
    cout << endl;
    return m;
}

int main() {
    cout << "Enable logging?(y/n)\t";
    char shouldLog;
    cin >> shouldLog;
    if (shouldLog == 'y' || shouldLog == 'Y') isLogEnabled = true;

    vector<vector<int>> m1, m2, m3;
    int rows1, columns1, columns2;
    int a;

    LABEL:

    cout << "\nChose operation \n\t 0: add \n\t 1: transpose \n\t 2: multiply \n";
    cin >> a;
    switch (a) {
        case 0:
            cout << "\nEnter number of rows and columns of the matrices\t";
            cin >> rows1 >> columns1;
            m1 = input(m1, rows1, columns1);
            m2 = input(m2, rows1, columns1);
            m3 = add(m1, m2, rows1, columns1);
            output(m3, rows1, columns1);

            break;
        case 1:
            cout << "\nEnter number of rows and columns of the matrix\t";
            cin >> rows1 >> columns1;
            m1 = input(m1, rows1, columns1);
            m3 = transpose(m1, rows1, columns1);

            log("transpose ready");

            output(m3, columns1, rows1);

            break;
        case 2:
            cout << "\nEnter number of rows and columns of the matrix\t";
            cin >> rows1 >> columns1;
            m1 = input(m1, rows1, columns1);
            cout << "\nEnter number of columns for the second matrix\t";
            cin >> columns2;
            m2 = input(m2, columns1, columns2);
            m3 = multiply(m1, rows1, columns1, m2, columns2);
            log("multiplication complete");
            output(m3, rows1, columns2);

            break;
        default:
            cout << "Wrong input";
            goto LABEL;
    }

    return 0;
}