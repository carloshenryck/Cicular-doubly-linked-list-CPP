#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List l1;
    List l2;

    l1.push_back(1);
    l1.push_back(1);
    l1.push_back(1);
    l1.push_back(1);

    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    l1 = l2;
    cout << l1;
    return 0;
}