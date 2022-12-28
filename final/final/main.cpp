#include <iostream>
#include "treeMain.h"

using namespace std;
using std::string;

void cmds() {
    cout<<"Список комманд: "<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"Выход           [exit]"<<endl;
    cout<<"Вывод           [print]"<<endl;
    cout<<"Добавление      [add]"<<endl;
    cout<<"Удаление        [removed]"<<endl;
    cout<<"Поиск           [seek]"<<endl;
    cout<<"---------------------------"<<endl;
}

int main() {
    AVL* tree = new AVL(); // создаем новое дерево
    cout<<"Введите количество членов последовательности (через пробел): \n";
    int n;
    cin>>n;
        cout<<"Введите элементы дерева:\n";
        for(int i = 0; i < n; i++) {
            int x;
            cin>>x;
            tree->add(x);
        }
    
    
    cmds();
    string input;
    while (input != "exit"){
        cout<<"Ввод команды: ";
        cin>>input;

        if (input == "print")
        { // вывод текущего дерева
            cout<<"Дерево выглядит так: ";
            tree->print();
            cout<<endl;
        }
        else if (input == "add"){ // добавление нового элемента
            cout<<"Введите значение элемента (целое число): ";
            int x;
            cin>>x;
            tree->add(x);
        }
        else if (input == "removed")
        { // удаление узла по ключу
            cout<<"Введите значение элемента (целое число): ";
            int x;
            cin>>x;
            tree->del(x);
        }
        else if (input == "seek")
        { // поиск элемента
            cout<<"Введите значение элемента (целое число): ";
            int x;
            cin>>x;
            tree->search(x);
        }
        
        else if (input != "exit")
        {
            cout<<"Невверная команда! \nПовторный ввод: ";
            cin>>input;
        }
        
    }
    
}
