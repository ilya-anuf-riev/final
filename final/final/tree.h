//
//  tree.h
//  final
//
//  Created by Илья Ануфриев on 28.12.2022.
//

#ifndef tree_h
#define tree_h
// абстрактный класс
class Tree {
public:
    
    virtual void add(int k) = 0; // функция вставки
    virtual void del(int k) = 0; // функция удаления
    virtual int search(int k) = 0; // функция поиска
};
#endif /* tree_h */
