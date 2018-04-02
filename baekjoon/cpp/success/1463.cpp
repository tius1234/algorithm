// https://www.acmicpc.net/problem/1463

#include <iostream>
#include <set>

using namespace std;

int makeOne(set<int> &inputSet, int cnt) {

    set<int>::iterator iter;
    for (iter = inputSet.begin(); iter != inputSet.end(); ++iter) {

        if (*iter == 1) {
            return cnt;
        }
    }

    set<int> tmpSet;
    for (iter = inputSet.begin(); iter != inputSet.end(); ++iter) {

        if (*iter % 3 == 0) {
            tmpSet.insert(*iter / 3);
        }

        if (*iter % 2 == 0) {
            tmpSet.insert(*iter / 2);
        }

        tmpSet.insert(*iter - 1);
    }

    cnt += 1;

    for (iter = inputSet.begin(); iter != inputSet.end(); ++iter) {

        tmpSet.erase(*iter);
    }

    return makeOne(tmpSet, cnt);
}

int main(){

    set<int> inputSet;

    int inputInt = 0;
    cin >> inputInt;

    inputSet.insert(inputInt);

    printf("%d\n", makeOne(inputSet, 0));

    return 0;
}