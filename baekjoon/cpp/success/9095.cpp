// https://www.acmicpc.net/problem/9095

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int sumOneTwoThree(int num, map<int, int> &resultMap) {

    if (num < 0) {
        return 0;
    } else if (num == 0) {
        return 1;
    }

    map<int, int>::iterator findIter = resultMap.find(num);
    if (findIter != resultMap.end()) {
        return findIter->second;
    }

    if (num >= 3) {
        resultMap.insert(map<int, int>::value_type(
            num, sumOneTwoThree(num-1, resultMap) + sumOneTwoThree(num-2, resultMap) + sumOneTwoThree(num-3, resultMap)
        ));
    } else if (num == 2) {
        resultMap.insert(map<int, int>::value_type(
            num, sumOneTwoThree(num-1, resultMap) + sumOneTwoThree(num-2, resultMap)
        ));
    } else {
        resultMap.insert(map<int, int>::value_type(
            num, sumOneTwoThree(num-1, resultMap)
        ));
    }

    findIter = resultMap.find(num);
    if (findIter != resultMap.end()) {
        return findIter->second;
    } else {
        return 0;
    }
}

int main(){

    vector<int> inputVector;
    map<int, int> resultMap;

    int inputLen = 0;
    cin >> inputLen;

    int inputNum = 0;
    for (int ii=0; ii<inputLen; ii++) {
        cin >> inputNum;
        inputVector.push_back(inputNum);
    }

    for (int ii=0; ii<inputLen; ii++) {
        resultMap.clear();
        printf("%d\n", sumOneTwoThree(inputVector.at(ii), resultMap));
    }

    return 0;
}