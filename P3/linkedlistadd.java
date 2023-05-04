import java.io.*;
import java.util.*;

class linkedlistadd {

    static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
        }
    }

    static Node l1, l2, result;

    // To push a new node to linked list
    public static void push(int new_data) {

        Node new_node = new Node(0);

        new_node.data = new_data;

        new_node.next = l1;

        l1 = new_node;
    }

    public static void push1(int new_data) {

        Node new_node = new Node(0);

        new_node.data = new_data;

        new_node.next = l2;

        l2 = new_node;
    }

    // To add two new numbers
    public static Node addTwoNumbers() {
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();

        while (l1 != null) {
            stack1.add(l1.data);
            l1 = l1.next;
        }

        while (l2 != null) {
            stack2.add(l2.data);
            l2 = l2.next;
        }

        int carry = 0;
        Node result = null;

        while (!stack1.isEmpty() ||
                !stack2.isEmpty()) {
            int a = 0, b = 0;

            if (!stack1.isEmpty()) {
                a = stack1.pop();
            }

            if (!stack2.isEmpty()) {
                b = stack2.pop();
            }

            int total = a + b + carry;

            Node temp = new Node(total % 10);
            carry = total / 10;

            if (result == null) {
                result = temp;
            } else {
                temp.next = result;
                result = temp;
            }
        }

        if (carry != 0) {
            Node temp = new Node(carry);
            temp.next = result;
            result = temp;
        }
        return result;
    }

    // To print a linked list
    public static void printList() {
        while (result != null) {
            System.out.print(result.data + " ");
            result = result.next;
        }
        System.out.println();
    }

    // Driver code
    public static void main(String[] args) {
        // take user input
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of first linked list");
        int size1 = sc.nextInt();
        int arr1[] = new int[size1];
        System.out.println("Enter the elements of first linked list");
        for (int i = 0; i < size1; i++) {
            arr1[i] = sc.nextInt();
        }
        System.out.println("Enter the size of second linked list");
        int size2 = sc.nextInt();
        int arr2[] = new int[size2];
        System.out.println("Enter the elements of second linked list");
        for (int i = 0; i < size2; i++) {
            arr2[i] = sc.nextInt();
        }

        int i;
        for (i = size1 - 1; i >= 0; --i)
            push(arr1[i]);

        for (i = size2 - 1; i >= 0; --i)
            push1(arr2[i]);

        result = addTwoNumbers();
        System.out.println("The sum of two linked list is: ");
        printList();
    }
}