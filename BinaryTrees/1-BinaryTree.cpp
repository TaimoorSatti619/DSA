#include <iostream>
#include <queue>
#include <stack>
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

Node *BuildTree(Node *root) {
  cout << "Enter the data: " << endl;
  int data;
  cin >> data;
  root = new Node(data);
  if (data == -1) {
    return NULL;
  }

  cout << "Enter data for Left Node of " << data << endl;
  root->left = BuildTree(root->left);
  cout << "Enter data for Right Node of " << data << endl;
  root->right = BuildTree(root->right);

  return root;
}

//*************************************************
void levelOrderTraversal(Node *root) {

  queue<Node *> q;
  q.push(root);
  q.push(NULL); // Separator

  while (!q.empty()) {
    Node *temp = q.front();

    if (temp == NULL) {
      // purana level complete traverse ho chuka hai
      cout << endl;
      if (!q.empty()) {
        // queue still has some child nodes
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      q.pop();

      if (temp->left) {
        q.push(temp->left);
      }

      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
}

// REVERSE LEVEL ORDER TRAVERSAL
/*void reverseLevelOrderTraversal(Node *root) {
  queue<Node *> q;
  stack<Node *> s;
  q.push(root);
  q.push(NULL); // Separator

  while (!q.empty()) {
    Node *temp = q.front();

    if (temp == NULL) {
      cout << endl;
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      s.push(temp);
      q.pop();
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
      cout << s.top()->data << " ";
      s.pop();
    }
  }
}*/

// INORDER TRAVERSAL
void inOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

// PREORDER TRAVERSAL
void preOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

// POSTORDER TRAVERSAL
void postOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}

//********************************************************************

// BUILd Tree from Level Order Traversal
void buildFromLevelOrder(Node *&root) {
  queue<Node *> q;
  cout << "Enter data for root" << endl;
  int data;
  cin >> data;
  root = new Node(data);
  q.push(root);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();

    cout << "Enter left node for: " << temp->data << endl;
    int leftData;
    cin >> leftData;
    if (leftData != -1) {
      temp->left = new Node(leftData);
      q.push(temp->left);
    }

    cout << "Enter right node for: " << temp->data << endl;
    int rightData;
    cin >> rightData;
    if (rightData != -1) {
      temp->right = new Node(rightData);
      q.push(temp->right);
    }
  }
}

int main() {
  Node *root = NULL;
  root = BuildTree(root);
  cout << "Level Order Traversal: " << endl;
  levelOrderTraversal(root);

  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
}

//***************************************************************************

// COUNT LEAF NODES Problem
void inOrderTriverse(Node *root, int &cnt) {
  if (root == NULL) {
    return;
  }

  inOrderTriverse(root->left, cnt);

  if (root->left == NULL && root->right == NULL) {
    cnt++;
  }

  inOrderTriverse(root->right, cnt);
}

int noOfLeafNodes(Node *root) {
  int cnt = 0;
  inOrderTriverse(root, cnt);
  return cnt;
}