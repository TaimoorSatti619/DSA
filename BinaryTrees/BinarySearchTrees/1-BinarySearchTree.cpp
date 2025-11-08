#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

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

//********************************************************************************

Node *insertIntoBST(Node *&root, int d) { /// Time Complexity: O(logn)

  if (root == NULL) {
    root = new Node(d);
    return root;
  }

  if (d > root->data) {
    root->right = insertIntoBST(root->right, d);
  } else {
    root->left = insertIntoBST(root->left, d);
  }

  return root;
}

void takeInput(Node *&root) {

  int data;
  cin >> data;

  while (data != -1) {
    root = insertIntoBST(root, data);
    cin >> data;
  }
}

int main() {

  Node *root = NULL;

  cout << "Take input of tree " << endl;
  takeInput(root);
  // cout << "Level Order Traversal: " << endl;
  // levelOrderTraversal(root);

  cout << "InOrder Traversal: " << endl;
  inOrderTraversal(root); /// Inorder traversal of BST is always sorted
  cout << endl;
  cout << "PreOrder Traversal: " << endl;
  preOrderTraversal(root);
  cout << endl;
  cout << "PostOrder Traversal: " << endl;
  postOrderTraversal(root);
  cout << endl;

  return 0;
}

//// SEARCH A NODE IN BST

bool searchInBST(Node *root, int x) { // recursive approach

  if (root == NULL) {
    return false;
  }

  if (root->data == x) {
    return true;
  }

  if (root->data > x) {
    return searchInBST(root->left, x);
  } else {
    return searchInBST(root->right, x);
  }
}

bool searchBST(Node *root, int x) { // iterative approach

  Node *temp = root;

  while (temp != NULL) {

    if (temp->data == x) {
      return true;
    }

    if (temp->data > x) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }
  return false;
}

///***************************************************************************************

//// MINIMUM AND MAXIMUM VALUE IN BST

int minValue(Node *root) {

  Node *temp = root;

  while (temp->left != NULL) {
    temp = temp->left;
  }
  return temp->data;
}

int maxValue(Node *root) {

  Node *temp = root;

  while (temp->right != NULL) {
    temp = temp->right;
  }
  return temp->data;
}

///***************************************************************************************

// Inorder Predecessor and Successor in BST

Node *rightMost(Node *node) {
  while (node->right != NULL) {
    node = node->right;
  }
  return node;
}

Node *leftMost(Node *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

vector<Node *> inorderPreSuc(Node *root, int key) {

  Node *temp = root;
  Node *pre = NULL;
  Node *suc = NULL;

  while (temp != NULL) {

    if (temp->data > key) {
      suc = temp;
      temp = temp->left;
    } else if (temp->data < key) {
      pre = temp;
      temp = temp->right;
    } else {
      if (temp->left) {
        pre = rightMost(root->left);
      }
      if (temp->right) {
        suc = leftMost(root->right);
      }
      break;
    }
  }

  return {pre, suc};
}

//***************************************************************************************

/// DELETE A NODE FROM BST

Node *deleteFromBST(Node *root, int val) {

  if (root == NULL) {
    return root;
  }

  if (root->data == val) {

    // 0 child
    if (root->left == NULL && root->right == NULL) {
      delete root;
      return NULL;
    }

    // 1 child
    if (root->left != NULL && root->right == NULL) {
      Node *temp = root->left;
      delete root;
      return temp;
    }

    if (root->left == NULL && root->right != NULL) {
      Node *temp = root->right;
      delete root;
      return temp;
    }

    // 2 child
    if (root->left != NULL && root->right != NULL) {
      int mini = minValue(root->right);
      root->data = mini;
      root->right = deleteFromBST(root->right, mini);
      return root;
    }
  } else if (root->data > val) {
    root->left = deleteFromBST(root->left, val);
    return root;
  } else {
    root->right = deleteFromBST(root->right, val);
    return root;
  }
}
