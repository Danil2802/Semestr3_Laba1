#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

struct Node {
    string data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void addToHead(const string& value);
    void addToTail(const string& value);
    void removeFromHead();
    void removeFromTail();
    void removeByValue(const string& value);
    bool search(const string& value) const;
    void print(const fs::path& filePath) const;
    void saveToFile(const fs::path& filePath) const;
    void loadFromFile(const fs::path& filePath);
};

#endif // SINGLYLINKEDLIST_H
