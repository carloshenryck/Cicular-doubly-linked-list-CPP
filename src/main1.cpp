#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List l1;

    /*

    List l2;

    l2.push_back(1);

    l1.swap(l2);

    l2.push_back(8);
    l2.push_back(10);

    l1.push_back(3);
    l1.push_back(5);

    l1.removeAll(2);*/

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);

    l1.copy();

    return 0;
}