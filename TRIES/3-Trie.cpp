#include <iostream>
#include <vector>
using namespace std;

// Question =>  Implement a Phone Directory

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

  ///************************************************************************************

  void printSuggestion(TrieNode *curr, vector<string> &temp, string prefix) {

    if (curr->isTerminal) {
      temp.push_back(prefix);
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {

      TrieNode *next = curr->children[ch - 'a'];

      if (next != NULL) {
        prefix.push_back(ch);
        printSuggestion(next, temp, prefix);
        prefix.pop_back();
      }
    }
  }

  vector<vector<string>> getSuggestions(string &str) {

    TrieNode *prev = root;

    vector<vector<string>> output;
    string prefix = "";

    for (int i = 0; i < str.length(); i++) {

      char lastCh = str[i];
      prefix.push_back(lastCh);

      /*
      if (prev == NULL) {
          output.push_back({"0"});
          continue;
      }
      */

      // check for lastCh
      TrieNode *curr = prev->children[lastCh - 'a'];

      // if not found
      if (curr == NULL) {
        output.push_back({"0"});
        prev = NULL;
        continue;
      }

      // if found
      vector<string> temp;
      printSuggestion(curr, temp, prefix);
      output.push_back(temp);
      prev = curr;
      temp.clear();
    }
    return output;
  }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList,
                                      string &queryStr) {

  Trie *t = new Trie();

  for (int i = 0; i < contactList.size(); i++) {
    t->insertWord(contactList[i]);
  }

  return t->getSuggestions(queryStr);
}