# Clone Graph
[Problem Link](https://leetcode.com/problems/clone-graph/description/)

## Problem desciption 

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
```
class Node {
    public int val;
    public List<Node> neighbors;
}
 ```

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

## constraints


## Code
```cpp
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
    void dfs_create_node(Node* node, unordered_map<Node*,Node*>&mp,unordered_map<Node*,int> &vis){
        vis[node] = 1;

        Node* newNode = new Node(node->val);
        auto list = node->neighbors;
        mp[node] = newNode;

        for(auto it: list){
            if(!vis[it])
                dfs_create_node(it,mp,vis);
        }

        for(auto it: list){
            newNode->neighbors.push_back(mp[it]);
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*,Node*>mp;
        unordered_map<Node*,int> vis;

        dfs_create_node(node,mp,vis);

        return mp[node];
    }
};
```

better approach
```cpp
class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   
                {
                    neighbour.push_back(mp[it]);    
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};
```

## Intuition


## Approach


## Complexity
- Time complexity: 


- Space complexity:
