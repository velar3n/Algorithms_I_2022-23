#include <iostream>
#include <cstdlib>
#include <stack>

template <typename T>
struct BSTNode {
    T value;
    BSTNode *left, *right;
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    BSTNode(const T& item) : value(item), left(nullptr), right(nullptr) {}
    ~BSTNode() {} // destruktor
};

// Szablon dla przypadkowego drzewa binarnego.
template <typename T>
class RandomBinaryTree {
    BSTNode<T> *root;
public:
    RandomBinaryTree() : root(nullptr) {}
    ~RandomBinaryTree() { clear(); }
    bool empty() const { return root == nullptr; }
    T& top() { assert(root != nullptr); return root->value; }
    void insert(const T& item) { root = insert(root, item); }
    void preorder() { preorder(root); }
    int calc_nodes() { return calc_nodes(root); }
    void clear() { clear(root); root = nullptr; }
    void display() { display(root, 0); }
    void iter_preorder();

    int calc_nodes(BSTNode<T> *node);
    int iter_calc_nodes();

    BSTNode<T> * insert(BSTNode<T> *node, const T& item); // zwraca nowy korzeń
    void clear(BSTNode<T> *node);
    void display(BSTNode<T> *node, int level);
    void preorder(BSTNode<T> *node);
    virtual void visit(BSTNode<T> *node) {
        assert(node != nullptr);
        std::cout << "visiting " << node->value << std::endl;
    }
};

template <typename T>
void RandomBinaryTree<T>::clear(BSTNode<T> *node) {
    if(node->left!=NULL) {
        clear(node->left);
    }
    if(node->right!=NULL) {
        clear(node->right);
    }
    delete node;
}

// Wyświetlanie obróconego (counterclockwise) drzewa binarnego.
template <typename T>
void RandomBinaryTree<T>::display(BSTNode<T> *node, int level) {
    if (node == nullptr) return;
    display(node->right, level + 1);
    std::cout << std::string(3 * level, ' ') << node->value << std::endl;
    display(node->left, level + 1);
}

template <typename T>
BSTNode<T> * RandomBinaryTree<T>::insert(BSTNode<T> *node, const T& item) {
    if (node == nullptr) {
        return new BSTNode<T>(item);
    }
    if (std::rand() % 2) { // można lepiej
        node->left = insert(node->left, item);
    } else {
        node->right = insert(node->right, item);
    }
    return node; // zwraca nowy korzen
}

template <typename T>
void RandomBinaryTree<T>::preorder(BSTNode<T> *node) {
    if (node == nullptr) return;
    visit(node);
    preorder(node->left);
    preorder(node->right);
}

template <typename T>
void RandomBinaryTree<T>::iter_preorder() {
    if (root == nullptr) return;
    std::stack<BSTNode<T>*> S; // wskaźniki do węzłów
    BSTNode<T> *node = root;
    S.push(node);
    while (!S.empty()) {
        node = S.top(); // podglądamy
        S.pop();        // usuwamy ze stosu
        visit(node); // tu jest właściwe przetworzenie węzła
        if (node->right != nullptr) // najpierw prawe poddrzewo!
            S.push(node->right);
        if (node->left != nullptr)
            S.push(node->left);
    }
}

template <typename T>
int RandomBinaryTree<T>::calc_nodes(BSTNode<T> *node) {
    if (node == nullptr) {
        return 0;
    }
    int left_node = calc_nodes(node->left);
    int rigt_node = calc_nodes(node->right);
 
    return left_node + rigt_node + 1;
}

template <typename T>
int RandomBinaryTree<T>::iter_calc_nodes() {
    if (root == nullptr) {
        return 0;
    }
    BSTNode<T> *node = root;
    std::stack<BSTNode<T>*> S;
    S.push(node);
    int total = 0;
    while (!S.empty()) {
        node = S.top();
        S.pop();
        if (node->right != nullptr)
            S.push(node->right);
        if (node->left != nullptr)
            S.push(node->left);
        total++;
    }
    return total;
}
