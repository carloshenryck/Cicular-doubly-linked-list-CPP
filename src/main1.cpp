#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List l1;
    List l2;

    l1.push_back(1);
    l1.push_back(2);

    cout << l1 << endl;

    l1.removeAll(1);

    cout << l1 << endl;


    return 0;
}