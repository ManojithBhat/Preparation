# ZigZag Traversal
[Problem Link](https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1)

## Problem desciption 
Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for even-numbered levels.


## constraints
* 1 <= n <= 105

## Code
```cpp

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	vector<int> temp;
    	int flag=1;
    	
    	if(root==NULL) return ans;
    	queue<Node *> q;
    	q.push(root);
    	while(!q.empty()){
    	    int size = q.size();
    	    for(int i=0;i<size;i++){
    	        Node* curr = q.front();
    	        q.pop();
    	        if(flag==1){
    	        ans.push_back(curr->data);
    	        }
    	        else{
    	            temp.push_back(curr->data);
    	        }
    	           if(curr->left) q.push(curr->left);
    	           if(curr->right) q.push(curr->right);
    	    }
    	    for(int i = temp.size()-1;i>=0;--i){
    	        ans.push_back(temp[i]);
    	    }
    	    temp.clear();
    	    flag = !flag;
    	}
    	return ans;
    }
};

```

## Intuition
``` need to write ```
Intution for the level ordere traversal is to use the level and increment it every time. First go to right side ( post order traversal ) and push to the vector only when level == res.size()


## Approach


## Complexity
- Time complexity: O(N)

- Space complexity: O(N)
