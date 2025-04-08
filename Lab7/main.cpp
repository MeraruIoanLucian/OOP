#include <iostream>
#include "Tree.h"

using namespace std;

bool compareInt(const int& a, const int& b) {
    return a == b;
}

int compareIntForSort(const int& a, const int& b) {
    return (a < b ? -1 : (a > b ? 1 : 0));
}
//////////////////////////////////////////////////////////////////////////////////////////// 1

constexpr float operator""_Kelvin(long double k) {
    return static_cast<float>(k - 273.15);
}

constexpr float operator""_Fahrenheit(long double f) {
    return static_cast<float>((f - 32.0) * 5.0 / 9.0);
}


int main() {

    float celsiusFromKelvin = 300.0_Kelvin;       // 300 K -> ~26.85 C
    float celsiusFromFahrenheit = 120.0_Fahrenheit; // 120 F -> ~48.89 C
    cout << "300 Kelvin in Celsius: " << celsiusFromKelvin << endl;
    cout << "120 Fahrenheit in Celsius: " << celsiusFromFahrenheit << endl;

///////////////////////////////////////////////////////////////////////////////////////////// 1

    Tree<int> tree;
    TreeNode<int>* root = tree.add_node(nullptr, 10);
    TreeNode<int>* child1 = tree.add_node(root, 20);
    TreeNode<int>* child2 = tree.add_node(root, 30);
    tree.add_node(child1, 15);
    tree.insert(root, 25, 1);
    tree.sort(root, compareIntForSort);
    int totalDescendants = tree.count(nullptr);
    cout << "Numar de descendenti: " << totalDescendants << endl;
    TreeNode<int>* found = tree.find(compareInt, 15);
    if (found)
        cout << "Found node with value: " << found->value << endl;
    else
        cout << "Node with value 30 not found." << endl;
    tree.delete_node(child1);
    if (found)
        cout << "Found node with value: " << found->value << endl;
    else
        cout << "Node with value 30 not found." << endl;



    return 0;
}