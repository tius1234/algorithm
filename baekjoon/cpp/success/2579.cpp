// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <vector>

using namespace std;

int maxNum(int aa, int bb) {
    return aa > bb ? aa : bb;
}

int climbStairs(vector<int> &inputVector) {

    if (inputVector.size() < 1) {
        return 0;
    } else if (inputVector.size() == 1) {
        return inputVector.at(0);
    } else if (inputVector.size() == 2) {
        return inputVector.at(0) + inputVector.at(1);
    }

    vector<int> resultVector;
    resultVector.push_back(inputVector.at(0));
    resultVector.push_back(inputVector.at(0) + inputVector.at(1));
    resultVector.push_back(maxNum(inputVector.at(0), inputVector.at(1)) + inputVector.at(2));

    for (int ii=3; ii<inputVector.size(); ii++) {
        resultVector.push_back(
            maxNum(resultVector.at(ii-3) + inputVector.at(ii-1), resultVector.at(ii-2)) + inputVector.at(ii)
        );
    }

    return resultVector.back();
}

int main(){

    vector<int> inputVector;

    int inputLen = 0;
    cin >> inputLen;

    int inputNum = 0;
    for (int ii=0; ii<inputLen; ii++) {
        cin >> inputNum;
        inputVector.push_back(inputNum);
    }

    printf("%d\n", climbStairs(inputVector));

    return 0;
}