#include <iostream>
#include <vector>
using namespace std;

//// Question  =>   Longest Common Prefix

string longestCommonPrefix(vector<string> &arr, int n) { // T.C  O(M*N)

  string ans = "";

  for (int i = 0; i < arr[0].size(); i++) {

    char ch = arr[0][i];
    bool match = true;
    for (int j = 1; j < n; j++) {
      if (arr[j].size() < i || ch != arr[j][i]) {
        match = false;
        break;
      }
    }
    if (match == false) {
      break;
    } else {
      ans.push_back(ch);
    }
  }

  return ans;
}

/// APPROACH 2  =>  using Trie
class TrieNode {
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;
  int childCount;

  TrieNode(char data) {
    this->data = data;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    isTerminal = false;
    childCount = 0;
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
      root->childCount++;
      root->children[index] = child;
    }

    // recursion
    insertUtil(child, word.substr(1));
  }

  void insertWord(string word) { insertUtil(root, word); }

  void lcp(string str, string &ans) {

    for (int i = 0; i < str.length(); i++) {

      char ch = str[i];
      if (root->childCount == 1) {
        ans.push_back(ch);

        int index = ch - 'A';
        root = root->children[index];
      } else {
        break;
      }
      if (root->isTerminal) {
        break;
      }
    }
  }
};

string longestCommonPrefix(vector<string> &arr, int n) {

  Trie *t = new Trie();

  for (int i = 0; i < n; i++) {
    t->insertWord(arr[i]);
  }

  string first = arr[0];
  string prefix = "";
  t->lcp(first, prefix);
  return prefix;
}
