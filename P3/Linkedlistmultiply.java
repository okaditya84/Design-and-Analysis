import java.util.Stack;
import java.util.Scanner;

class Linkedlistmultiply {

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

        // Allocate node
        Node new_node = new Node(0);

        // Put in the data
        new_node.data = new_data;

        // Link the old list of the new node
        new_node.next = l1;

        // Move the head to point to the new node
        l1 = new_node;
    }

    public static void push1(int new_data) {

        // Allocate node
        Node new_node = new Node(0);

        // Put in the data
        new_node.data = new_data;

        // Link the old list of the new node
        new_node.next = l2;

        // Move the head to point to
        // the new node
        l2 = new_node;
    }

    // To multiply two numbers
    public static Node multiplyTwoNumbers() {
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

        int num1 = 0, num2 = 0;

        while (!stack1.isEmpty()) {
            num1 = num1 * 10 + stack1.pop();
        }

        while (!stack2.isEmpty()) {
            num2 = num2 * 10 + stack2.pop();
        }

        int product = num1 * num2;

        Node head = null;
        while (product != 0) {
            int remainder = product % 10;
            Node newNode = new Node(remainder);
            newNode.next = head;
            head = newNode;
            product = product / 10;
        }

        return head;
    }

    // To print the linked list
    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }

    public static void main(String[] args) {
        // take input from user
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of digits in first number");
        n = sc.nextInt();
        System.out.println("Enter the digits of first number");
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            push(x);
        }
        System.out.println("Enter the number of digits in second number");
        n = sc.nextInt();
        System.out.println("Enter the digits of second number");
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            push1(x);
        }
        result = multiplyTwoNumbers();
        //sout the result
        System.out.println("The product of two numbers is");
        printList(result);

    }

}
