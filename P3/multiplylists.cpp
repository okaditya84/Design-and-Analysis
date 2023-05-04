// C++ program to Multiply two numbers
// represented as linked lists
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct Node **head_ref, int new_data)
{

    struct Node *new_node = newNode(new_data);

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

int reverse(struct Node **head_ref)
{   
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next;
    int len = 0;
    while (current != NULL)
    {
        len++;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return len;
}

struct Node *make_empty_list(int size)
{
    struct Node *head = NULL;
    while (size--)
        push(&head, 0);
    return head;
}

struct Node *multiplyTwoLists(struct Node *first,
                              struct Node *second)
{

    int m = reverse(&first), n = reverse(&second);

    struct Node *result = make_empty_list(m + n + 1);

    struct Node *second_ptr = second,
                *result_ptr1 = result, *result_ptr2, *first_ptr;

    while (second_ptr)
    {

        int carry = 0;

        result_ptr2 = result_ptr1;

        first_ptr = first;

        while (first_ptr)
        {

            int mul = first_ptr->data * second_ptr->data + carry;

            result_ptr2->data += mul % 10;

            carry = mul / 10 + result_ptr2->data / 10;
            result_ptr2->data = result_ptr2->data % 10;

            first_ptr = first_ptr->next;
            result_ptr2 = result_ptr2->next;
        }

        if (carry > 0)
        {
            result_ptr2->data += carry;
        }

        result_ptr1 = result_ptr1->next;
        second_ptr = second_ptr->next;
    }

    reverse(&result);
    reverse(&first);
    reverse(&second);

    while (result->data == 0)
    {
        struct Node *temp = result;
        result = result->next;
        free(temp);
    }

    return result;
}

void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        cout << Node->data;
        if (Node->next)
            cout << "->";
        Node = Node->next;
    }
    cout << endl;
}

// Driver program to test above function
int main(void)
{
    struct Node *first = NULL;
    struct Node *second = NULL;

    int n1, n2;
    cout << "Enter the number of elements in first list: "<<endl;
    cout << "The elements will be pushed in the list from the end:" ;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        push(&first, x);
    }
    cout << "First List is: ";
    printList(first);
    cout << "Enter the size of second list: "<<endl;
    cout << "The elements will be pushed in the list from the end:" ;
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        push(&second, x);
    }
    cout << "Second List is: ";
    printList(second);

    // Multiply the two lists and see result
    struct Node *result = multiplyTwoLists(first, second);
    cout << "Resultant list is: ";
    printList(result);

    return 0;
}
