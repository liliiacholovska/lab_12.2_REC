#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Рекурсивна функція для перевірки наявності сусідніх пар елементів з однаковими значеннями
bool DuplicatePairRec(Node* current) {
    if (current == nullptr || current->next == nullptr) // Базовий випадок: кінець списку або один елемент
        return false;

    if (current->data == current->next->data) // Перевірка сусідніх значень
        return true;

    return DuplicatePairRec(current->next); // Рекурсивний виклик для наступного вузла
}

// Рекурсивна функція для створення списку з масиву значень
void CreateListRec(Node*& head, Node*& tail, int values[], int size) {
    head = nullptr;
    tail = nullptr;

    if (size <= 0) // базовий випадок: якщо розмір масиву не більше 0
        return;

    head = new Node();//1
    head->data = values[0];//2
    head->next = nullptr;//3
    tail = head;

    CreateListRec(head->next, tail, values + 1, size - 1); // Рекурсивний виклик для наступного елементу
}

// Рекурсивна функція для виведення списку на екран
void PrintListRec(Node* head) {
    if (head == nullptr) { // Базовий випадок: кінець списку
        cout << endl;
        return;
    }

    cout << head->data << " "; // Виведення поточного елементу
    PrintListRec(head->next); // Рекурсивний виклик для наступного елементу
}

int main() {
    int values[] = { 1, 2, 2, 4, 5, 2 }; // Задання масиву значень для створення списку
    int size = sizeof(values) / sizeof(values[0]); // Визначення розміру масиву

    Node* head = nullptr; // Ініціалізація початкового вузла як nullptr
    Node* tail = nullptr; // Ініціалізація кінцевого вузла як nullptr

    CreateListRec(head, tail, values, size); // Створення списку з масиву значень

    cout << "List of elements:" << endl;
    PrintListRec(head); // Виведення списку на екран

    if (DuplicatePairRec(head)) { // Перевірка наявності пари елементів з однаковими значеннями
        cout << "A list contains a pair of adjacent elements with the same values." << endl;
    }
    else {
        cout << "The list does not contain a pair of adjacent elements with the same values." << endl;
    }

    // Очищення списку
    Node* current = head; // Покажчик current на початок списку
    while (current != nullptr) { // Проходження по усіх вузлах списку
        Node* temp = current; // Тимчасове зберігання поточного вузла
        current = current->next; // Перехід до наступного вузла
        delete temp; // Видалення поточного вузла
    }

    return 0; // Повернення 0 для позначення успішного завершення програми
}