#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// ���������� ������� ��� �������� �������� ������ ��� �������� � ���������� ����������
bool DuplicatePairRec(Node* current) {
    if (current == nullptr || current->next == nullptr) // ������� �������: ����� ������ ��� ���� �������
        return false;

    if (current->data == current->next->data) // �������� ������ �������
        return true;

    return DuplicatePairRec(current->next); // ����������� ������ ��� ���������� �����
}

// ���������� ������� ��� ��������� ������ � ������ �������
void CreateListRec(Node*& head, Node*& tail, int values[], int size) {
    head = nullptr;
    tail = nullptr;

    if (size <= 0) // ������� �������: ���� ����� ������ �� ����� 0
        return;

    head = new Node();//1
    head->data = values[0];//2
    head->next = nullptr;//3
    tail = head;

    CreateListRec(head->next, tail, values + 1, size - 1); // ����������� ������ ��� ���������� ��������
}

// ���������� ������� ��� ��������� ������ �� �����
void PrintListRec(Node* head) {
    if (head == nullptr) { // ������� �������: ����� ������
        cout << endl;
        return;
    }

    cout << head->data << " "; // ��������� ��������� ��������
    PrintListRec(head->next); // ����������� ������ ��� ���������� ��������
}

int main() {
    int values[] = { 1, 2, 2, 4, 5, 2 }; // ������� ������ ������� ��� ��������� ������
    int size = sizeof(values) / sizeof(values[0]); // ���������� ������ ������

    Node* head = nullptr; // ����������� ����������� ����� �� nullptr
    Node* tail = nullptr; // ����������� �������� ����� �� nullptr

    CreateListRec(head, tail, values, size); // ��������� ������ � ������ �������

    cout << "List of elements:" << endl;
    PrintListRec(head); // ��������� ������ �� �����

    if (DuplicatePairRec(head)) { // �������� �������� ���� �������� � ���������� ����������
        cout << "A list contains a pair of adjacent elements with the same values." << endl;
    }
    else {
        cout << "The list does not contain a pair of adjacent elements with the same values." << endl;
    }

    // �������� ������
    Node* current = head; // �������� current �� ������� ������
    while (current != nullptr) { // ����������� �� ��� ������ ������
        Node* temp = current; // ��������� ��������� ��������� �����
        current = current->next; // ������� �� ���������� �����
        delete temp; // ��������� ��������� �����
    }

    return 0; // ���������� 0 ��� ���������� �������� ���������� ��������
}