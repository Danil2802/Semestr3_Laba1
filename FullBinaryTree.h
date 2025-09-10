#ifndef FULL_BINARY_TREE_H
#define FULL_BINARY_TREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

struct TreeNode {
    string key;
    TreeNode *left;
    TreeNode *right;
};

class FullBinaryTree {
private:
    TreeNode* root;

    // Вспомогательные методы
    void clear(TreeNode* node);
    TreeNode* newNode(const string& k);
    TreeNode* findNode(const string& value) const;
    void insert(const string& parentValue, const string& side, const string& value);
    bool isFullBinaryTreeHelper(TreeNode* node) const;
    unordered_map<std::string, TreeNode*> nodes;
    
public:
    FullBinaryTree();
    ~FullBinaryTree();

    void saveHelper(ofstream& file, TreeNode* node) const;
    void add(const string& parentValue, const string& side, const string& value);
    bool isFullBinaryTree();
    void saveToFile(const fs::path& filePath) const;
    void loadFromFile(const fs::path& filePath);
    void printTree(const fs::path& filePath) const;
    bool search(const string& value) const;
    int height(TreeNode* node) const;
    void printRecursive(TreeNode* node, vector<vector<string>>& output, int linePos, int depth, const vector<int>& spacings) const;
    void print(const fs::path& filePath, int mode) const;
};
#endif // FULL_BINARY_TREE_H
