//
// Created by user on 25.11.2022.
//

#ifndef INC_4_BINARYTREE_H
#define INC_4_BINARYTREE_H
using namespace std;

struct node
{
    int Key;
    int Count;
    node *Left;
    node *Right;
};

class TREE
{
private:
    node *duk; //Корень дерева.
public:
    TREE() { duk = NULL; }
    node **GetDuk() { return &duk; }
    void *Tree (int, node **);
    void Vyvod (node **, int);
    int getDept(node **);
};

void *TREE::Tree (int n,node **p)
// Построение идеально сбалансированного
//           дерева с n вершинами.
// *p - указатель на корень дерева.
{
    node *now;
    int x,nl,nr;

    now = *p;
    if  (n==0) *p = NULL;
    else
    {
        nl = n/2; nr = n - nl - 1;
        cin>>x;
        now = new(node);
        (*now).Key = x;
        Tree (nl,&((*now).Left));
        Tree (nr,&((*now).Right));
        *p = now;
    }
}

void TREE::Vyvod (node **w, int l)
// Изображение бинарного дерева, заданного
// указателем *w на экране дисплея.
{
    if  (*w!=NULL)
    {
        Vyvod (&((**w).Right),l+1);
        for  (int i=1; i<=l; i++) cout<<"   ";
        cout<<(**w).Key<<endl;
        Vyvod (&((**w).Left),l+1);
    }
}

/*
Используя рекурсивный алгоритм определить
количество уровней в дереве.
 */
int TREE::getDept(node **w){
    if  (*w==NULL) return 0;
    return max(getDept(&((**w).Right)), getDept(&((**w).Left))) + 1;
}
#endif //INC_4_BINARYTREE_H