#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);

    cout << l1 << endl;

    l1.reverse();

    cout << l1 << endl;


    return 0;
}