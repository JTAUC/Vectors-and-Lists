#include "Header.h"
#include "LinkedList.h"
#include <vector>

vector<int> v;

void InitiateLinkedList(LinkedList &list) { //Function to add the number of occurrences of each value in the vector to the passed linked list.
    int occ = 0;
    
    bool* check = new bool[v.size()];

    for (int i = 0; i < v.size(); i++) {
        check[i] = 0;
    }
    
    for (int i = 0; i < v.size(); i++) {
        if (check[i] == 1) { continue; }

        for (int j = 0; j < v.size(); j++) {
            if (v[i] == v[j]) {
                check[j] = 1;
                occ++;
            }
        }
        list.addNode(v[i], occ);
        occ = 0;
    }

    delete[] check;
}

void insertAfter(int firstValue, int secondValue) { //Function that searches for firstValue in the vector, if found it inserts secondValue after it.
    std::vector<int>::iterator it;
    it = std::find(v.begin(), v.end(), firstValue);

    if (it == v.end()){
        cout << "Value not found in vector!" << endl;
        return;
    }
    v.insert(it + 1, secondValue);
}

int main()
{
    int n, val;
    int firstValue, secondValue;
    LinkedList list;

    cout << "How many values would you like to enter: ";
    cin >> n;

    for (int i = 0; i < n; i++) { //Fill vector with user-determined values
        cout << "Enter the " << i + 1 << " value: ";
        cin >> val;
        v.push_back(val); 
    }

    cout << "Enter the first value to be searched, and the second value to be entered in the vector: " << endl;
    cin >> firstValue >> secondValue;
    insertAfter(firstValue, secondValue);

    InitiateLinkedList(list);
    list.printList(); //Outputs linked list
    cout << "Sum of nodes: " << list.SumOfNodes() << endl;
    
}
