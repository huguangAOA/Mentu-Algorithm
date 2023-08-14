/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> h;
    Node *getResult(Node *node) {
        if (node == nullptr) return nullptr;
        if (h[node]) return h[node];
        h[node] = new Node(node->val);
        for (auto x : node->neighbors) {
            getResult(x);
            h[node]->neighbors.push_back(h[x]);
        }
        return h[node];
    }
    Node* cloneGraph(Node* node) {
        h.clear();
        return getResult(node);
    }
};