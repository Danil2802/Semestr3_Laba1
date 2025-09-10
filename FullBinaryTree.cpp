#include "FullBinaryTree.h"
#include <fstream>
#include <iostream>
#include <vector>

FullBinaryTree::FullBinaryTree() : root(nullptr) {}

FullBinaryTree::~FullBinaryTree() {
    clear(root);
    nodes.clear();
}

// Очистка дерева
void FullBinaryTree::clear(TreeNode* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Создание нового узла
TreeNode* FullBinaryTree::newNode(const string& k) {
    TreeNode* node = new TreeNode;
    node->key = k;
    node->right = node->left = nullptr;
    
    // Добавляем узел в карту
    nodes[k] = node;
    return node;
}

bool FullBinaryTree::isFullBinaryTreeHelper(TreeNode* node) const {

  if (node == NULL)
    return true;

  if (node->left == NULL && node->right == NULL)
    return true;

  if ((node->left) && (node->right))
    return (isFullBinaryTreeHelper(node->left) && isFullBinaryTreeHelper(node->right));

  return false;
}

bool FullBinaryTree::isFullBinaryTree () {
    return isFullBinaryTreeHelper(root);
}

// Поиск узла по значению
TreeNode* FullBinaryTree::findNode(const string& value) const {
    auto it = nodes.find(value);
    if (it != nodes.end()) {
        return it->second;
    }
    return nullptr;
}

void FullBinaryTree::add(const string& parentValue, const string& side, const string& value) {
    insert(parentValue, side, value);
}

// Вставка в конкретное место
void FullBinaryTree::insert(const string& parentValue, const string& side, const string& value) {
    TreeNode* parent = findNode(parentValue);
    if (!parent) {
        cerr << "Error: Parent node '" << parentValue << "' not found!\n";
        return;
    }

    if (findNode(value)) {
        cerr << "Error: Node with value '" << value << "' already exists!\n";
        return;
    }

    if (side == "L") {
        if (parent->left != nullptr) {
            cerr << "Error: Left child already exists for node '" << parentValue << "'!\n";
            return;
        }
        parent->left = newNode(value);
    } 

    else if (side == "R") {
        if (parent->right != nullptr) {
            cerr << "Error: Right child already exists for node '" << parentValue << "'!\n";
            return;
        }
        parent->right = newNode(value);
    }

    else {
        cerr << "Error: Invalid side '" << side << "'. Use 'L' or 'R'.\n";
        return;
    }
}

bool FullBinaryTree::search(const string& value) const {
    return findNode(value) != nullptr;
}

// Сохранение дерева в файл
void FullBinaryTree::saveToFile(const fs::path& filePath) const {
    ofstream file(filePath);
    file << "FullBinaryTree\n";

    // Записываем корень дерева отдельно
    if (root) {
        file << root->key << "\n";
    }

    // Рекурсивно выводим дерево в файл
    saveHelper(file, root);
    file.close();
}

// Вспомогательный метод для рекурсивного сохранения
void FullBinaryTree::saveHelper(ofstream& file, TreeNode* node) const {
    if (!node) return;

    // Записываем связи только для существующих потомков
    if (node->left) {
        file << node->key << " L " << node->left->key << "\n";
        saveHelper(file, node->left);  // Рекурсивно вызываем для левого потомка
    }

    if (node->right) {
        file << node->key << " R " << node->right->key << "\n";
        saveHelper(file, node->right);  // Рекурсивно вызываем для правого потомка
    }
}

void FullBinaryTree::loadFromFile(const fs::path& filePath) {
    ifstream file(filePath);
    string header;
    file >> header;

    string line;
    bool rootFound = false;

    while (getline(file, line)) {
        if (line.empty()) {
           continue;
        }
        istringstream iss(line);
        vector<string> words;
        string word;
        
        while (iss >> word) {
            words.push_back(word);
        }

        if (words.size() == 1) {
            if (!rootFound) {
                root = newNode(words[0]);
                rootFound = true;
            }
        }
        else if (words.size() == 3) {
            string parent = words[0];
            string side = words[1];
            string child = words[2];

            if (!rootFound) {
                root = newNode(parent);
                rootFound = true;
            }

            insert(parent, side, child);
        }
        else {
            cerr << "Error: Invalid line format: " << line << endl;
            continue;
        }
    }
    file.close();
}

int FullBinaryTree::height(TreeNode* node) const {
    if (!node) return 0;
    return max(height(node->left), height(node->right)) + 1;
}

void FullBinaryTree::printTree(const fs::path& filePath) const {
    if (!root) {
        std::cout << "Tree is empty\n";
        return;
    }
    
    int h = height(root);
    int totalLines = (1 << h) - 1; // 2^h - 1
    
    // Рассчитываем позиции для каждого уровня
    vector<int> levelSpacings(h);
    levelSpacings[h-1] = 1;
    
    for (int i = h-2; i >= 0; --i) {
        levelSpacings[i] = levelSpacings[i+1] * 2;
    }
    
    vector<vector<string>> output(totalLines, vector<string>(h, " "));

    int nottotalLines = (totalLines - 1) / 2;
    printRecursive(root, output, nottotalLines, 0, levelSpacings);
    
    cout << filePath.filename().string() << ": \n";
    for (int i = 0; i < totalLines; ++i) {
        for (int j = 0; j < h; ++j) {
            cout << output[i][j] << setw(8);
        }
        cout << "\n";
    }
}

void FullBinaryTree::printRecursive(TreeNode* node, vector<vector<string>>& output, int linePos, int depth, const vector<int>& spacings) const {
    if (!node) return;

    output[linePos][depth] = node->key;
    int newdepth = depth + 1;
    
    if (node->left) {
        int newLinePos = linePos + spacings[newdepth];
        printRecursive(node->left, output, newLinePos, newdepth, spacings);
    }
    if (node->right) {
        int newLinePos = linePos - spacings[newdepth];
        printRecursive(node->right, output, newLinePos, newdepth, spacings);
    }
}

void FullBinaryTree::print(const fs::path& filePath, int mode) const {
    if (mode == 1) {
        printTree(filePath);
    } 
    else if (mode == 2) {
        ifstream file(filePath);
        string header;
        file >> header;
        cout << filePath.filename().string() << ":";
        string line;
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    }
    else {
        cerr << "Error: Invalid mode. Use 1 (tree) or 2 (file content)\n";
    }
}
