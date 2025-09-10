#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

SinglyLinkedList::~SinglyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void SinglyLinkedList::addToHead(const string& value) {
    Node* newNode = new Node{ value, head };
    head = newNode;
    if (!tail) {
        tail = head;
    }
}

void SinglyLinkedList::addToTail(const string& value) {
    Node* newNode = new Node{ value, nullptr };
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

void SinglyLinkedList::removeFromHead() {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    if (!head) {
        tail = nullptr;
    }
}

void SinglyLinkedList::removeFromTail() {
    if (!tail) {
        cout << "List is empty!\n";
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void SinglyLinkedList::removeByValue(const string& value) {
    Node* current = head;
    Node* previous = nullptr;
    while (current) {
        if (current->data == value) {
            if (previous) {
                previous->next = current->next;
            }
            else {
                head = current->next;
            }
            if (current == tail) {
                tail = previous;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Value not found!\n";
}

bool SinglyLinkedList::search(const string& value) const {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void SinglyLinkedList::print(const fs::path& filePath) const {
    cout << filePath.filename().string() << ": ";
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

void SinglyLinkedList::saveToFile(const fs::path& filePath) const {
    ofstream file(filePath);
    file << "SinglyLinkedList\n";
    Node* current = head;
    while (current) {
        file << current->data << "\n";
        current = current->next;
    }
    file.close();
}

void SinglyLinkedList::loadFromFile(const fs::path& filePath) {
    ifstream file(filePath);
    string header;
    file >> header;
    string value;
    while (file >> value) {
        addToTail(value);
    }
    file.close();
}

