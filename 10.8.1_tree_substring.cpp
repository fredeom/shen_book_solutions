#include <iostream>
#include <string>
#include <vector>

class Node {
  char ch;
  std::vector<Node*> childrens;
public:
  Node(char p, std::string s1);
  void search(std::string s2);
};

Node::Node(char p, std::string s1) {
  ch = p;
  for (int i = 0; i < s1.length(); ++i) {
    char next = s1[i];
    bool is_new = true;
    for (Node* nd : childrens) {
      if (nd->ch == next) {
        is_new = false;
        break;
      }
    }
    if (is_new) {
      childrens.push_back(new Node(next, s1.substr(1)));
    }
  }
}

void Node::search(std::string s2) {
  if (!s2.compare("")) {
    std::cout << "Found substring" << std::endl;
    return;
  }
  bool is_found = false;
  for (Node* nd : childrens) {
    if (s2.length() > 0 && nd->ch == s2[0]) {
      nd->search(s2.substr(1));
      is_found = true;
      break;
    }
  }
  if (!is_found) std::cout << "Substring not found" << std::endl;
}

int main() {
  std::string s1, s2;
  freopen("10.8.1.in", "r", stdin);
  std::cin >> s1 >> s2;

  Node node('#', s1);
  node.search(s2);

  return 0;
}

