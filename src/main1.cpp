#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List l1;
    List l2;

    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(2);

    l2.push_back(8);
    l2.push_back(10);
    l2.push_back(12);
    l2.push_back(14);
    l2.push_back(24);
    l2.push_back(34);

    l1.merge(l2);
    cout << l1;
    return 0;
}