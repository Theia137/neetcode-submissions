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
    unordered_map<Node*, Node*> mapp;

    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        else{
            if(mapp[node]==nullptr){
                Node* curnode = new Node(node->val);
                mapp[node] = curnode;
                for(Node* neighbor : node->neighbors){
                    curnode->neighbors.push_back(cloneGraph(neighbor));
                }
                return curnode;
            }
            else{
                return mapp[node];
            }
        }    
    }
};
