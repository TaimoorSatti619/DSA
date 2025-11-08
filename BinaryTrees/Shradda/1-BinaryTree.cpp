#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

static int idx = -1;
Node *BuildTree(vector<int> preOrder) {
  idx++;
  Node *root = new Node(preOrder[idx]);

  if (preOrder[idx] == -1) {
    return NULL;
  }

  root->left = BuildTree(preOrder);
  root->right = BuildTree(preOrder);

  return root;
}

//********************************************************************

// preOrder Traversal
void preOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

// inOrder Traversal
void inOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

// postOrder Traversal
void postOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}

// levelOrder Traversal
void levelOrderTraversal(Node *root) {

  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (q.size() > 0) {
    Node *curr = q.front();
    q.pop();

    if (curr == NULL) {
      if (!q.empty()) {
        q.push(NULL);
        cout << endl;
        continue;
      } else {
        break;
      }
    }

    cout << curr->data << " ";

    if (curr->left) {
      q.push(curr->left);
    }
    if (curr->right) {
      q.push(curr->right);
    }
  }
  cout << endl;
}

int main() {
  vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node *root = BuildTree(preOrder);
  cout << "Root Node: " << root->data << endl;
  cout << "Left Node: " << root->left->data << endl;
  cout << "Right Node: " << root->right->data << endl;

  cout << "PreOrder Traversal: " << endl;
  preOrderTraversal(root);
  cout << endl;
  cout << "InOrder Traversal: " << endl;
  inOrderTraversal(root);
  cout << endl;
  cout << "PostOrder Traversal: " << endl;
  postOrderTraversal(root);
  cout << endl;
  cout << "Level Order Traversal: " << endl;
  levelOrderTraversal(root);

  return 0;
}