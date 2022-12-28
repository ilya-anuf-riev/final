//
//  node.h
//  final
//
//  Created by Илья Ануфриев on 28.12.2022.
//

#ifndef node_h
#define node_h

struct node // структура дерева
{
    int key; //ключ узла
    unsigned char height; //высота поддерева с корнем в данном узле
    node* left; // левое поддерево
    node* right; //правое поддерево
    node(int k) { key = k; left = right = 0; height = 1; }
};

#endif /* node_h */
