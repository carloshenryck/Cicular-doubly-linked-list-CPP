#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List l1;

    /*

    l1.removeAll(1);

    l1.push_back(1);
    l1.push_back(2);

    l1.removeAll(2);

    l1.push_back(2);
    l1.push_back(3);

    l1.removeAll(2);*/

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.removeAt(10);

    cout << l1;

    return 0;
}