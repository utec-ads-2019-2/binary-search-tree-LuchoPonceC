#include <iostream>
#include "tester/tester.h"
#include "bstree.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    BSTree<int> binary;
    binary.insert(14);
    binary.insert(10);
    binary.insert(12);
    binary.insert(20);
    binary.insert(17);
    /*binary.insert(7);
    binary.insert(24);
    binary.insert(27);

    cout<<binary.height()<<endl;

    binary.traversePreOrder();
    binary.remove(7);
    binary.traversePreOrder();
    binary.remove(11);
    binary.traversePreOrder();
*/

    binary.traverseInOrder();

    std::cout<<"el inicion es: "<<*(binary.begin())<<std::endl;
    std::cout<<"el final es: "<<*(binary.end())<<std::endl;

    Tester::execute();
    return EXIT_SUCCESS;
}
