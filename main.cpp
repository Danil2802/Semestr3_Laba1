#include <iostream>
#include <string>
#include <vector>
#include "Array.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "HashTable.h"
#include "FullBinaryTree.h"

using namespace std;

void arrayMenu(const string& filePath, const string& queryString) {
    Array arr;
    arr.loadFromFile(filePath);
    
    // Разбиваем queryString на команду и аргументы
    istringstream iss(queryString);
    vector<string> tokens;
    string token;
    
    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        cerr << "Error: Empty command\n";
        return;
    }

    string command = tokens[0];

    if (command == "MPUSHINDEX") {
        if (tokens.size() != 4) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string indexStr = tokens[2];
        bool isNumeric = true;
        for (char c : indexStr) {
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }

        if (!isNumeric) {
            cerr << "Error: Index must be a number\n";
            return;
        }

        int index = stoi(indexStr);
        string value = tokens[3];  
        arr.add(index, value);
    }
    else if (command == "MPUSH") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string value = tokens[2];
        arr.addToEnd(value);
    }
    else if (command == "MGET") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string indexStr = tokens[2];
        bool isNumeric = true;
        for (char c : indexStr) {
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }

        if (!isNumeric) {
            cerr << "Error: Index must be a number\n";
            return;
        }

        int index = stoi(indexStr);
        string get = arr.get(index);
        if (!get.empty()) {
           cout << "Value: " << get << "\n";
        } 
        else {
            cout << "Invalid index.\n";
        }
    }
    else if (command == "MDEL") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string indexStr = tokens[2];
        bool isNumeric = true;
        for (char c : indexStr) {
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }

        if (!isNumeric) {
            cerr << "Error: Index must be a number\n";
            return;
        }

        int index = stoi(indexStr);
        arr.remove(index);
    }
    else if (command == "MSET") {
        if (tokens.size() != 4) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string indexStr = tokens[2];
        bool isNumeric = true;
        for (char c : indexStr) {
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }

        if (!isNumeric) {
            cerr << "Error: Index must be a number\n";
            return;
        }

        int index = stoi(indexStr);
        string value = tokens[3]; 

        arr.set(index, value);
    }
    else if (command == "MLEN") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
        int len = arr.length();
        cout << "Length: " << len << "\n";
    }
    else if (command == "PRINT") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
        arr.print(filePath);
    }
    else {
        cout << "Invalid command!\n";
        return;
    }
    arr.saveToFile(filePath);
}

void singlyLinkedListMenu(const string& filePath, const string& queryString) {
    SinglyLinkedList list;
    list.loadFromFile(filePath);

    // Разбиваем queryString на команду и аргументы
    istringstream iss(queryString);
    vector<string> tokens;
    string token;
    
    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        cerr << "Error: Empty command\n";
        return;
    }

    string command = tokens[0];

    if (command == "LPUSHHEAD") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string value = tokens[2];
        list.addToHead(value);
    }
    else if (command == "LPUSHTAIL") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string value = tokens[2];
            list.addToTail(value);
    }
    else if (command == "LDELHEAD") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
            list.removeFromHead();
    }
    else if (command == "LDELTAIL") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
            list.removeFromTail();
    }
    else if (command == "LDELVAL") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string value = tokens[2];
            list.removeByValue(value);
    }
    else if (command == "LSEARCH") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string value = tokens[2];
            cout << (list.search(value) ? "Found\n" : "Not Found\n");
    }
    else if (command == "PRINT") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
            list.print(filePath);
    }
    else {
        cout << "Invalid command!\n";
        return;
    }
    list.saveToFile(filePath);
}


void doublyLinkedListMenu(const string& filePath, const string& queryString) {
    DoublyLinkedList list;
    list.loadFromFile(filePath);

    // Разбиваем queryString на команду и аргументы
    istringstream iss(queryString);
    vector<string> tokens;
    string token;
    
    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        cerr << "Error: Empty command\n";
        return;
    }

    string command = tokens[0];

    if (command == "LPUSHHEAD") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string value = tokens[2];    
            list.addToHead(value);
    }
    else if (command == "LPUSHTAIL") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string value = tokens[2];
            list.addToTail(value);
    }
    else if (command == "LDELHEAD") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
            list.removeFromHead();
    }
    else if (command == "LDELTAIL") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
            list.removeFromTail();
    }
    else if (command == "LDELVAL") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string value = tokens[2];
            list.removeByValue(value);
    }
    else if (command == "LSEARCH") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string value = tokens[2];
            cout << (list.search(value) ? "Found\n" : "Not Found\n");
    }
    else if (command == "PRINT") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
            list.print(filePath);
    }
    else {
        cout << "Invalid command!\n";
        return;
    }
    list.saveToFile(filePath);
}

void queueMenu(const string& filePath, const string& queryString) {
    Queue queue;
    queue.loadFromFile(filePath);

    // Разбиваем queryString на команду и аргументы
    istringstream iss(queryString);
    vector<string> tokens;
    string token;
    
    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        cerr << "Error: Empty command\n";
        return;
    }

    string command = tokens[0];

    if (command == "QPUSH") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string value = tokens[2];
            queue.push(value);
    }
    else if (command == "QPOP") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
            queue.pop();
    }
    else if (command == "QPEEK") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
        string peek = queue.peek();
        if (!peek.empty()) {
           cout << "Peek: " << peek << "\n";
        }
        else {
           cout << "Queue is empty.\n";
        }
    }
    else if (command == "PRINT") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
            queue.print(filePath);
    }
    else {
        cout << "Invalid command!\n";
        return;
    }
    queue.saveToFile(filePath);
}

void stackMenu(const string& filePath, const string& queryString) {
    Stack stack;
    stack.loadFromFile(filePath);

    // Разбиваем queryString на команду и аргументы
    istringstream iss(queryString);
    vector<string> tokens;
    string token;
    
    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        cerr << "Error: Empty command\n";
        return;
    }

    string command = tokens[0];

    if (command == "SPUSH") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string value = tokens[2];
            stack.push(value);
    }
    else if (command == "SPOP") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
            stack.pop();
    }
    else if (command == "SPEEK") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
        string peek = stack.peek();
        if (!peek.empty()) {
           cout << "Peek: " << peek << "\n";
        }
        else {
           cout << "Stack is empty.\n";
        }
    }
    else if (command == "PRINT") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }

    fs::path filePath(tokens[1]);
    cout << filePath.filename().string() << ": ";
    stack.print();
}
    else {
        cout << "Invalid command!\n";
        return;
    }
    stack.saveToFile(filePath);
}

void hashTableMenu(const string& filePath, const string& queryString) {
    HashTable hashTable;
    hashTable.loadFromFile(filePath);

    // Разбиваем queryString на команду и аргументы
    istringstream iss(queryString);
    vector<string> tokens;
    string token;
    
    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        cerr << "Error: Empty command\n";
        return;
    }

    string command = tokens[0];

    if (command == "HINSERT") {
        if (tokens.size() != 4) {
            cerr << "Error: Invalid command format\n";
            return;
        }
        string key = tokens[2];
        string value = tokens[3];
            hashTable.insert(key, value);
    }
    else if (command == "HGET") {
    if (tokens.size() != 3) {
        cerr << "Error: Invalid command format\n";
        return;
    }
    string key = tokens[2];
    string value = hashTable.get(key);
    if (!value.empty()) {
        cout << "Value: " << value << "\n";
    } else {
        cout << "Key not found!\n";
    }
}
    else if (command == "HDEL") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }
        string key = tokens[2];
            hashTable.remove(key);
    }
    else if (command == "PRINT") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
            hashTable.print(filePath);
    }
    else if (command == "HCOUNT") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
        fs::path filePath(tokens[1]);
        int count = hashTable.count();
        cout << "Pairs of key and value in the file " << filePath.filename().string() << ": " << count << "\n";
    }
    else {
        cout << "Invalid command!\n";
        return;
        }
    hashTable.saveToFile(filePath);
}

void fullBinaryTreeMenu(const string& filePath, const string& queryString) {
    FullBinaryTree tree;
    tree.loadFromFile(filePath);

    // Разбиваем queryString на команду и аргументы
    istringstream iss(queryString);
    vector<string> tokens;
    string token;
    
    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        cerr << "Error: Empty command\n";
        return;
    }

    string command = tokens[0];

    if (command == "TINSERT") {
        if (tokens.size() != 5) {
            cerr << "Error: Invalid command format\n";
            return;
        }
        string parent = tokens[2];
        string side = tokens[3];
        string value = tokens[4];
        tree.add(parent, side, value);
    }
    else if (command == "TSEARCH") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }
        string value = tokens[2];
        cout << (tree.search(value) ? "Found\n" : "Not Found\n");
    }
    else if (command == "PRINT") {
        if (tokens.size() != 3) {
            cerr << "Error: Invalid command format\n";
            return;
        }

        string modeStr = tokens[2];
        bool isNumeric = true;
        for (char c : modeStr) {
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }

        if (!isNumeric) {
            cerr << "Error: Index must be a number\n";
            return;
        }

        int mode = stoi(modeStr);
        tree.print(filePath, mode);
    }
    else if (command == "TFULL") {
        if (tokens.size() != 2) {
            cerr << "Error: Invalid command format\n";
            return;
        }
        cout << (tree.isFullBinaryTree() ? "Full\n" : "Not Full\n");
    }
    else {
        cout << "Invalid command!\n";
        return;
        }
    tree.saveToFile(filePath);
}

int main(int argc, char* argv[]) {
    // Проверка формата команды
    if (argc != 5 || string(argv[1]) != "--file" || string(argv[3]) != "--query") {
        cerr << "Usage: " << argv[0] << " --file <data_directory> --query '<command> <filename>'" << endl;
        return 1;
    }

    // Получаем директорию с данными
    fs::path dataDir(argv[2]);
    
    // Проверяем существование директории
    if (!fs::exists(dataDir) || !fs::is_directory(dataDir)) {
        cerr << "Error: Directory not found" << endl;
        return 1;
    }

    // Разбираем query часть
    string query(argv[4]);
    istringstream queryStream(query);
    string command, filename;
    
    if (!(queryStream >> command >> filename)) {
        cerr << "Error: Invalid query format" << endl;
        return 1;
    }

    // Формируем полный путь к файлу
    fs::path filePath = dataDir / filename;
    
    // Проверяем существование файла
    if (!fs::exists(filePath)) {
        cerr << "Error: Structure file not found" << endl;
        return 1;
    }

    // Открываем файл и читаем тип структуры
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Failed to open file '" << filePath << "'" << endl;
        return 1;
    }
    string structureType;
    
    if (!(file >> structureType)) {
        cerr << "Error: Cannot determine structure type" << endl;
        return 1;
    } 

    // Создаем и загружаем соответствующую структуру
    if (structureType == "Array") {
        arrayMenu(filePath.string(), argv[4]);
    }
    else if (structureType == "SinglyLinkedList") {
        singlyLinkedListMenu(filePath.string(), argv[4]);
    }
    else if (structureType == "DoublyLinkedList") {
        doublyLinkedListMenu(filePath.string(), argv[4]);
    }
    else if (structureType == "Queue") {
        queueMenu(filePath.string(), argv[4]);
    }
    else if (structureType == "Stack") {
        stackMenu(filePath.string(), argv[4]);
    }
    else if (structureType == "HashTable") {
        hashTableMenu(filePath.string(), argv[4]);
    }
    else if (structureType == "FullBinaryTree") {
        fullBinaryTreeMenu(filePath.string(), argv[4]);
    }
    else {
        cerr << "Error: Unknown data structure type in file\n";
        return 1;
    }
    return 0;
}
