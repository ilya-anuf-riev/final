//
//  treeMain.h
//  final
//
//  Created by Илья Ануфриев on 28.12.2022.
//

#ifndef treeMain_h
#define treeMain_h

#include "tree.h"
#include "AVL.h"
#include <cmath>
using namespace std;

int AVL:: height(node* p)
{ //обёртка для поля height работает с 0-ми указателями
    return p ? p->height:0;
}

int AVL:: bfactor(node* p)
{ // вычисляет баланс заданного узла (только ненулевые указатели)
    return height(p->right) - height(p->left);
}


void AVL:: fixheight(node* p)
{ // восстанавливает корректное значение поля height (если значения в правом и левом дочерних узлах являются корректными)
    int hl = height(p->left);
    int hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}


node* AVL::rotateright(node* p)
{ // поворот вправо вокруг р
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

node* AVL::rotateleft(node* q)
{ // поворот влев вокруг q
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

node* AVL::balance(node* p)
{ // балансировка узла p
    fixheight(p);
    if(bfactor(p) == 2) {
        if(bfactor(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if(bfactor(p) == -2) {
        if(bfactor(p->left) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p;
}

node* AVL::insert(node* p, int k)
{ // вставка ключа k в дерево с кормнем p
    if( !p ) return new node(k);
    if( k<p->key ) p->left = insert(p->left,k);
    else p->right = insert(p->right,k);
    return balance(p);
}

void AVL::add(int k)
{ // поиск узла с минимальным ключом в дереве p
    _size++;
    tree = insert(tree, k);
    if (_size > arr.size()) {
        arr.resize(arr.size() + pow(2, st));
        st++;
    }
}

node* AVL::removemin(node* p)
{ //удаление узла с минимальным ключом из дерева p
    if(p->left == 0) return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

node* AVL::remove(node* p, int k)
{ // удаление ключа k из дерева p
    if( !p ) return 0;
    if( k < p->key ) p->left = remove(p->left,k);
    else if( k > p->key ) p->right = remove(p->right,k);
    else //  k == p->key
    {
        node* q = p->left;
        node* r = p->right;
        delete p;
        if( !r ) return q;
        node* min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    clear();
    return balance(p);
}

int AVL::find(node* tree, int k, int index = 0)
{ // поиск элемента
    if (tree == NULL) return -1;
    if (tree->key < k) return find(tree->right, k, index * 2 + 2);
    if (tree->key > k) return find(tree->left, k, index * 2 + 1);
    return index;
}

void AVL::print_node(node* root, std:: vector<int>& number, int index = 0)
{ // рассчёт правильного вывода (последовательность, благодаря которой формир. дерево без доп балансировки)
    if (root == NULL) return;
    number[index] = root->key;
    print_node(root->left, number, index * 2 + 1);
    print_node(root->right, number, index * 2 + 2);
}

void AVL::print()
{ // вывод дерева в терминал
    print_node(tree, arr);
    for (int val : arr) cout << val << ' ';
}

AVL::AVL(int k)
{
    tree = new node(k);
    arr.resize(1);
    _size = 0;
}

AVL::AVL()
{
    tree = NULL;
    arr.resize(0);
    _size = 0;
}

#endif /* treeMain_h */
