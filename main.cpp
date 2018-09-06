#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
    int length1 = num1.size(), length2 = num2.size(), value = length1 + length2;
    if (num1 == "0" || num2 == "0")
        return "0";

    int num1_int[length1], num2_int[length2], num3_int[value];
    for (int i = 0; i < value; i++) {
        num3_int[i] = 0;
    }
    for (int i = 0; i < length1; i++) {
        num1_int[i] = num1[i] - '0';
    }
    for (int i = 0; i < length2; i++) {
        num2_int[i] = num2[i] - '0';
    }

    for (int i = 0; i < length1; i++) {
        for (int j = 0; j < length2; j++) {
            num3_int[i + j + 1] += num1_int[i] * num2_int[j];
        }
    }
    for (int i = value - 1; i > 0; i--) {
        if (num3_int[i] >= 10) {
            num3_int[i - 1] += num3_int[i] / 10;
            num3_int[i] %= 10;
        }
    }
    string ans = "";
    int i = 0;
    if (num3_int[0] == 0)
        i = 1;
    for (; i < value; i++) {
        ans += to_string(num3_int[i]);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << multiply("5", "12") << endl;
    cout << multiply("0", "6") << endl;
    cout << multiply("9999999999999", "9") << endl;


    return 0;
}