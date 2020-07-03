//
//
// Remake of https://e-maxx.ru/algo/ukkonen
//
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int inf = 1e9;


int COUNT = 0;

struct Node {
  int l, r, id;
  map<int, Node*> t;
  Node *s;
  Node *p;
  Node(int l1 = -1, int r1 = -1): l(l1), r(r1), id(COUNT++) {};
  void draw(string s1) {
    cout << "[";
    // cout << id << " ";
    if (l >= 0 && r >= 0) {
      cout << s1.substr(l, r - l + 1);
      cout << " " << l << " " << r;
    }
    cout << "]";
    cout << "(";
    for (int i = 0; i < 256; ++i)
      if (t.count(i)) {
        t[i]->draw(s1);
        cout << ",";
      }
    cout << ")";
  }
};

int main() {
  string s;

  freopen("10.8.11.in", "r", stdin);
  cin >> s;
  s = s + "$";
  Node * node = new Node, *root = node, *nc, *split = 0, *fake_node = new Node;

  for (int i = 0; i < 256; i++) fake_node->t[i] = node;
  node->s = fake_node;

  int curr = 0;

  for (int i = 0; i < s.length(); ++i) {
    char c = s[i];

    while (true) {
      if (node->r < curr) {
        if (!node->t[c]) {
          Node * ts = new Node;
          node->t[c] = ts;
          ts->l = i;
          ts->r = s.length() - 1;
          ts->p = node;
          if (node->s) node = node->s; else node = root;
          curr = node->r + 1;
          continue;
        }
        node = node->t[c];
        curr = node->l;
      }
      if (curr == -1 || c == s[curr]) {
        curr++;
        break;
      }
      if (!split) split = new Node;
      nc = new Node;
      nc->l = i;
      nc->r = s.length() - 1;
      nc->p = split;
      split->l = node->l;
      split->r = curr - 1;
      split->p = node->p;
      split->t[c] = nc;
      split->t[s[curr]] = node;
      node->l = curr;
      node->p = split;
      split->p->t[s[split->l]] = split;
      node = split->p->s;
      curr = split->l;
      while (curr <= split->r) {
        node = node->t[s[curr]];
        curr += node->r - node->l + 1;
      }
      int splitr = split->r;
      if (curr == splitr + 1) {
        split->s = node;
        split = 0;
      } else {
        split->s = new Node;
        split = split->s;
      }
      curr = node->r - (curr - splitr) + 2;
    }
  }

  //root->draw(s); cout << endl;

  node = root;

  map<Node *, int> d;
  vector<Node *> v;
  d[node] = 0;
  v.push_back(node);
  for (int i = 0; i < v.size(); ++i) {
    Node * prev = v[i];
    for (int j = 0; j < 256; ++j) {
      if (prev->t.count(j)) {
        Node *next = prev->t[j];
        if (!next->t.empty()) {
          v.push_back(next);
          d[next] = d[prev] + next->r - next->l + 1 ;
        }
      }
    }
  }
  int maxInd = 0;
  for (int i = 0; i < v.size(); i++) {
    if (d[v[i]] > d[v[maxInd]]) maxInd = i;
  }
  node = v[maxInd];
  while (node->p && node->p->l >= 0) node = node->p;
  cout << s.substr(node->l, v[maxInd]->r - node->l + 1) << endl;

  return 0;
}

