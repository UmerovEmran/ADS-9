// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
public:
  struct Node {
    T value;
    int cnt = 0;
    Node* left;
    Node* right;
  };
  BST();
  void add(T);
  int depth();
  int search(T);
private:
  Node* root;
  Node* addN(Node*, T);
  int depthT(Node*);
  int searchN(Node*, T);
};

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
void BST<T>::add(T value) {
  root = addN(root, value);
}

template <typename T>
int BST<T>::depth() {
  return depthT(root) - 1;
}

template <typename T>
int BST<T>::search(T value) {
  return searchN(root, value);
}

template <typename T>
typename BST<T>::Node* BST<T>::addN(Node* root, T value) {
  if (root == nullptr) {
    root = new Node;
    root->value = value;
    root->cnt = 1;
    root->left = root->right = nullptr;
  } else if (root->value > value) {
      root->left = addN(root->left, value);
    } else if (root->value < value) {
        root->right = addN(root->right, value);
      } else {
          root->cnt++;
        }
  return root;
}

template <typename T>
int BST<T>::depthT(Node* root) {
  if (root == nullptr) {
    return 0;
  } else {
      int vpr, vlv;
      vpr = depthT(root->right);
      vlv = depthT(root->left);
      if (vpr > vlv) {
        return vpr + 1;
      } else {
          return vlv + 1;
        }
    }
}

template <typename T>
int BST<T>::searchN(Node* root, T val) {
  if (root == nullptr) {
    return 0;
  } else if (root->value == val) {
      return root->cnt;
    } else if (root->value > val) {
        return searchN(root->left, val);
      } else {
          return searchN(root->right, val);
        }
}

#endif  // INCLUDE_BST_H_
