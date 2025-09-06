#include <bits/stdc++.h> 

using namespace std;

class Codec {
public:

    string serialize(TreeNode* root) {
        string result = "";
        paraString(root, result);
        return result;
    }

    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string current_token = "";
        for (char c : data) {
            if (c == ' ') {
                if (!current_token.empty()) {
                    tokens.push_back(current_token);
                    current_token = "";
                }
            } else {
                current_token += c;
            }
        }
        
        int index = 0; 
        return paraABB(tokens, index);
    }

private:
    void paraString(TreeNode* node, string& s) {
        if (!node) {
            s += "# ";
            return;
        }
        s += to_string(node->val) + " "; 
        paraString(node->left, s);
        paraString(node->right, s);
    }

    TreeNode* paraABB(vector<string>& tokens, int& index) {
        if (index >= tokens.size()) return nullptr;
        
        string val = tokens[index];
        index++;

        if (val == "#") return nullptr;
        
        TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));

        if (node != NULL) {
            node->val = stoi(val);
            node->left = paraABB(tokens, index);
            node->right = paraABB(tokens, index);
        }
        return node;
    }
};