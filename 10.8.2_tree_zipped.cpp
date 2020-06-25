#include <iostream>
#include <string>
#include <vector>

class Node {
  std::string s;
  std::vector<Node*> children;
public:
  Node(std::string s1);
  void build(std::string s1);
  void print_debug();
};

Node::Node(std::string s1) {
  s = s1;
}

void Node::build(std::string s1) {
  int ndk;
  for (ndk = 0; ndk < children.size(); ndk++) {
    Node* nd = children[ndk];
    int i = 0;
    while (nd->s[i] == s1[i]) i++;
    if (i > 0) {
      if (i == nd->s.length()) {
        nd->build(s1.substr(i));
      } else {
        Node *newNode = new Node(nd->s.substr(0, i));
        nd->s = nd->s.substr(i);
        newNode->children.push_back(nd);
        children[ndk] = newNode;
        newNode->build(s1.substr(i));
      }
      break;
    }
  }
  if (ndk == children.size()) {
    children.push_back(new Node(s1));
  }
}

void Node::print_debug() {
  std::cout << "[" << s << "]";
  if (children.size() > 0) {
    std::cout << "(";
    for (Node *nd : children) {
      nd->print_debug();
      std::cout << ", ";
    }
    std::cout << ")";
  }
}

int main() {
  std::string s;
  freopen("10.8.2.in", "r", stdin);
  std::cin >> s;

  Node nd("");
  for (int i = 0; i < s.length(); ++i) {
    nd.build(s.substr(i));
  }
  nd.print_debug();
  std::cout << std::endl;
  return 0;
}

