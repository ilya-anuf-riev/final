//
//  AVL.h
//  final
//
//  Created by Илья Ануфриев on 28.12.2022.
//

#ifndef AVL_h
#define AVL_h

#include <vector>
#include "tree.h"
#include "node.h"

class AVL : public Tree {
public:
    // AVLTree() {}
    void add(int k) override;
    void del(int k) override {
        remove(tree, k);
    }
    void print();
    int search(int k) override {
        return find(tree, k, 0);
    }
    AVL(int k);
    AVL();
    
private:
    node *tree;
    std::vector<int> arr; // вектор, содержащий значения авл-дерева
    int _size = 0;
    int st = 0;

    int find(node* tree, int k, int index); // поиск
    int bfactor(node* p); // фактор баланса
    int height(node* p); // высота

    void clear() { for (int i = 0; i < arr.size(); i++) arr[i] = 0; } // очистка дерева
    void fixheight(node* p);
    void print_node(node* root, std:: vector<int> & nums, int index); // вывод
    node* insert(node* p, int k); // вставка
    node* balance(node* p); // балансировка узла
    
    node* findmin(node* p) { // поиск узла с минимальным ключом
        return p->left ? findmin(p->left) : p;
    }
    
    node* remove(node* p, int k); // удаление узла
    node* removemin(node* p); // удаление узла с минимальным ключом
    node* rotateleft(node* q); // левый поворот
    node* rotateright(node* p); // правый поворот
    
};

#endif /* AVL_h */
