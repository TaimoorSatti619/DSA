#include <iostream>
using namespace std;

class TrieNode {
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char data) {
    this->data = data;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    isTerminal = false;
  }
};

class Trie {
  TrieNode *root;

public:
  Trie() { root = new TrieNode('\0'); }

  void insertUtil(TrieNode *root, string word) {

    // base case
    if (word.length() == 0) {
      root->isTerminal = true;
      return;
    }

    // assumption that word will be in caps
    int index = word[0] - 'A';

    TrieNode *child;

    // present
    if (root->children[index] != NULL) {
      child = root->children[index];
    } else {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    // recursion
    insertUtil(child, word.substr(1));
  }

  void insertWord(string word) { insertUtil(root, word); }

  //****************************************************

  bool searchUtil(TrieNode *root, string word) {

    // base case
    if (word.length() == 0) {
      return root->isTerminal;
    }

    int index = word[0] - 'A';

    TrieNode *child;

    // present
    if (root->children[index] != NULL) {
      child = root->children[index];
    } else {
      return false;
    }

    // recursion
    return searchUtil(child, word.substr(1));
  }

  bool searchWord(string word) { return searchUtil(root, word); }

  //****************************************************

  void removeUtil(TrieNode *root, string word) {

    // base case
    if (word.size() == 0) {
      root->isTerminal = false;
      return;
    }

    int index = word[0] - 'A';
    TrieNode *child;

    if (root->children[index] != NULL) {
      child = root->children[index];
    } else {
      return;
    }

    // recursion
    removeUtil(child, word.substr(1));
  }

  void removeWord(string word) { removeUtil(root, word); }
};

int main() {

  Trie *t = new Trie();

  t->insertWord("ABCD");
  t->insertWord("ABCE");
  t->insertWord("ABCF");
  t->insertWord("XYZ");

  cout << "Present OR Not " << t->searchWord("ABCD") << endl;

  t->removeWord("ABCD");
  cout << "Present OR Not " << t->searchWord("ABCD") << endl;

  return 0;
}

/////****************************************************************

// using loop
class Trie {
  TrieNode *root;

public:
  Trie() { root = new TrieNode('\0'); }

  void insertWord(string word) {

    TrieNode *curr = root;
    for (char ch : word) {

      int idx = ch - 'a';
      if (curr->children[idx] == NULL) {
        curr->children[idx] = new TrieNode(ch);
      }
      curr = curr->children[idx];
    }

    curr->isTerminal = true;
  }


  bool searchWord(string word){

    TrieNode *curr = root;
    for (char ch : word){

      int idx = ch - 'a';
      if (curr->children[idx] == NULL){
        return false;
      }
      curr = curr->children[idx];
    }
    return curr->isTerminal;
  }


  void removeWord(string word){

    TrieNode *curr = root;
    for (char ch : word){

      int idx = ch - 'a';
      if (curr->children[idx] == NULL){
        return;
      }
      curr = curr->children[idx];
    }
    curr->isTerminal = false;
  }
  
};
