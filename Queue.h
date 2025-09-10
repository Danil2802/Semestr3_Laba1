#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Queue {
private:
    string* data;
    int front;
    int rear;
    int capacity;

public:
    Queue(int initialCapacity = 10);
    ~Queue();

    void push(const string& value); 
    void pop();  
    string peek() const; 
    void print(const fs::path& filePath) const;
    void saveToFile(const fs::path& filePath) const;
    void loadFromFile(const fs::path& filePath);
};

#endif
