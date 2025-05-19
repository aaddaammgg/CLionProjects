#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};
class CIS14
{
public:
    Node* addLists(Node*, Node*);
};
// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class
// named CIS14 with its method and the Node class you will use.
// ------------------------------------------------------------

// Optional: you may add any global function, variables here

static Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next;

        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

/**
 * PURPOSE:      A method to add both integers to a sum, and return a linked list representing that sum.
 * PARAMETERS:   l1 – head of first list
 *               l2 – head of second list
 * RETURN VALUE: Resulting sum
 */
Node* CIS14::addLists(Node* l1, Node* l2) {
    Node* r1 = reverseList(l1);
    Node* r2 = reverseList(l2);

    Node* head = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while (r1 != nullptr || r2 != nullptr || carry != 0) {
        int digit1 = 0;
        int digit2 = 0;

        if (r1 != nullptr) {
            digit1 = r1->val;
            r1 = r1->next;
        }

        if (r2 != nullptr) {
            digit2 = r2->val;
            r2 = r2->next;
        }

        int sum = digit1 + digit2 + carry;
        int newDigit = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(newDigit);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else if (tail != nullptr) {
            tail->next = newNode;
            tail = newNode;
        } else {
            return nullptr;
        }
    }

    return reverseList(head);
}

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;

    // First input list: 2->3->4->8
    Node first1(2), first2(3), first3(4), first4(8);
    first1.next = &first2;
    first2.next = &first3;
    first3.next = &first4;

    // Second input list: 9->9
    Node second1(9), second2(9);
    second1.next = &second2;

    // Adding:
    //    2->3->4->8
    //          9->9
    // -------------
    //    2->4->4->7
    Node* ans = cis14.addLists(&first1, &second1);

    // You may use the following code to print your list
    Node* tmp = ans;
    while (tmp != nullptr)
    {
        if (tmp->next != nullptr) {
            cout << tmp->val << "->";
        } else {
            cout << tmp->val;
        }
        tmp = tmp->next;
    }
    cout << endl;

    // If your addLists(...) method allocated heap memory, you
    // should deallocate them here to avoid memory leaks.

    return 0;
}
