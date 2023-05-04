#include <iostream>
#include <string>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* p = l1;
    ListNode* q = l2;
    ListNode* curr = head;
    int carry = 0;
    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }
    if (carry > 0) {
        curr->next = new ListNode(carry);
    }
    return head->next;
}

ListNode* createLinkedList(string str) {
    ListNode* head = NULL;
    ListNode* curr = NULL;
    for (int i = str.length() - 1; i >= 0; i--) {
        int val = str[i] - '0';
        ListNode* node = new ListNode(val);
        if (head == NULL) {
            head = node;
            curr = node;
        }
        else {
            curr->next = node;
            curr = node;
        }
    }
    return head;
}

void printLinkedList(ListNode* head) {
    //print reverse of the list
    if (head == NULL) return;
    printLinkedList(head->next);
    cout << head->val;
}

int main() {
    string num1, num2;
    cout << "Enter two numbers as strings: ";
    cin >> num1 >> num2;
    int len1 = num1.length();
    int len2 = num2.length();
    if (len1 < len2) {
        num1.insert(0, len2 - len1, '0');
    }
    else if (len2 < len1) {
        num2.insert(0, len1 - len2, '0');
    }
    ListNode* l1 = createLinkedList(num1);
    ListNode* l2 = createLinkedList(num2);
    ListNode* sumList = addTwoNumbers(l1, l2);
    cout << "Sum: ";
//print reverse of the sum
    printLinkedList(sumList);
    cout << endl;

    return 0;
}
