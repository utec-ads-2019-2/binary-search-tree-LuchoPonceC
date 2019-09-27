#include <iostream>
#include "tester/tester.h"
#include "bstree.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    BSTree<int> binary;
    binary.insert(50);
    binary.insert(20);
    binary.insert(10);
    binary.insert(23);
    binary.insert(12);
    binary.insert(11);
    binary.insert(18);
    binary.insert(15);
    binary.insert(14);
    binary.insert(13);
    binary.insert(80);

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
    binary.remove(50);
    binary.traverseInOrder();
    binary.remove(20);
    binary.traverseInOrder();
    binary.traverseInOrder();
    //binary.remove(12);
/*
    auto it = binary.begin();
    for(int i=0;i<binary.size();i++){
        std::cout<<*(++it)<<" - ";
    }
    binary.remove(14);
    it = binary.begin();
    for(int i=0;i<binary.size();i++){
       std::cout<<*(++it)<<" - ";
    }*/
    std::cout<<std::endl;
    //std::cout<<"el final es: "<<*(binary.end())<<std::endl;

    Tester::execute();
    return EXIT_SUCCESS;
}
