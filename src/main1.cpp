#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List l1;
    List l2;

    l1.push_back(1);
    l2.push_back(1);
    l1.equals(l2);
    return 0;
}