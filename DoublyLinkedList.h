#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class DNode {
public:
    string data; 
    DNode* prev;
    DNode* next;

    DNode(const string& value, DNode* prevNode = nullptr, DNode* nextNode = nullptr)
        : data(value), prev(prevNode), next(nextNode) {}
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

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

#endif
