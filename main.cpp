#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
    vector<string> ans;
    string tempAnsLast, tempAnsNow, tempAnsSum = "";
    int c = 0, value_1 = 0;//进位
    int lengthNum2 = num2.size(), lengthNum1 = num1.size();
    for (int i = 0; i < lengthNum2; i++) {
        tempAnsLast = to_string((num2[i] - '0') * (num1[0] - '0'));
        tempAnsSum = tempAnsLast;
        for (int j = 1; j < lengthNum1; j++) {
            int lengTempLast = tempAnsLast.size(),
                    lengthTempNow = tempAnsNow.size(), lengthTempSum = tempAnsSum.size();
            tempAnsNow = to_string((num2[i] - '0') * (num1[j] - '0'));
            if (lengthTempSum >= j)
                tempAnsSum = tempAnsSum.substr(lengthTempSum - j, lengthTempSum);

            for (int k = lengTempLast - j - 1; k >= 0; k--) {
                value_1 = (tempAnsSum[j] - '0') + tempAnsNow[lengthTempNow - j] - '0' + c;
                c = 0;
                tempAnsSum = tempAnsSum +
                             to_string(value_1 % 10);
                c += value_1 / 10;
            }
            tempAnsSum = tempAnsNow[0] + tempAnsSum;


        }
    }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}