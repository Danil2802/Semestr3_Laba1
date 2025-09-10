#include "Queue.h"

using namespace std;

Queue::Queue(int initialCapacity) {
    capacity = initialCapacity;
    data = new string[capacity];
    front = 0;
    rear = -1;
}

Queue::~Queue() {
    delete[] data;
}

void Queue::push(const string& value) {
    if (rear == capacity - 1) {
        capacity *= 2;
        string* newData = new string[capacity];
        for (int i = 0; i <= rear; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[++rear] = value;
}

void Queue::pop() {
    if (front > rear) {
        cout << "Queue is empty.\n";
        return;
    }
    data[front].~string(); 

    for (int i = front; i < rear; i++) {
        data[i] = data[i + 1];
    }
    rear--;
}

string Queue::peek() const {
    if (front > rear) {
        return "";
    }
    return data[front];
}

void Queue::print(const fs::path& filePath) const {
    cout << filePath.filename().string() << ": ";
    for (int i = front; i <= rear; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
}

void Queue::saveToFile(const fs::path& filePath) const {
    ofstream file(filePath);
    file << "Queue\n";
    for (int i = front; i <= rear; i++) {
        file << data[i] << "\n";
    }
    file.close();
}

void Queue::loadFromFile(const fs::path& filePath) {
    ifstream file(filePath);
    string header;
    file >> header;
    string value;
    while (file >> value) {
        push(value);
    }
    file.close();
}
