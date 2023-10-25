// program that uses functions to perform the following operations on doubly linked list
// i) Creation ii) Insertion  iii) Deletion iv) Traversal.

#include <iostream>

// Define a Node structure for the doubly linked list
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertNode(Node *&head, int data)
{
    Node *newNode = createNode(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to delete a node by value
void deleteNodeByValue(Node *&head, int target)
{
    if (head == nullptr)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    if (head->data == target)
    {
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    Node *current = head;
    while (current != nullptr && current->data != target)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        std::cout << "Node with value " << target << " not found." << std::endl;
    }
    else
    {
        current->prev->next = current->next;
        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }
        delete current;
    }
}

// Function to traverse and print the doubly linked list
void printDoublyLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    Node *head = nullptr; // Initialize an empty doubly linked list

    int choice, data;
    while (true)
    {
        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1. Create a node" << std::endl;
        std::cout << "2. Insert a node" << std::endl;
        std::cout << "3. Delete a node" << std::endl;
        std::cout << "4. Traverse the list" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter data for the new node: ";
            std::cin >> data;
            insertNode(head, data);
            break;
        case 2:
            std::cout << "Enter data for the new node: ";
            std::cin >> data;
            insertNode(head, data);
            break;
        case 3:
            std::cout << "Enter the value to delete: ";
            std::cin >> data;
            deleteNodeByValue(head, data);
            break;
        case 4:
            std::cout << "Doubly Linked List: ";
            printDoublyLinkedList(head);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}