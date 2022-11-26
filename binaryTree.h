//
// Created by user on 25.11.2022.
//

#ifndef INC_4_BINARYTREE_H
#define INC_4_BINARYTREE_H

#include <vector>

using namespace std;

struct node {
    int Key;
    node *Left;
    node *Right;
};

class TREE {
private:
    node *duk; //Корень дерева.
public:
    TREE() { duk = NULL; }
    node **GetDuk() { return &duk; }
    void *Tree(int, node **);
    void Vyvod(node **, int);
    int getDept(node **);
    node *maxNode(node **);
    int getMaxValue(node **);
    int getMinValue(node **);
};

void *TREE::Tree(int n, node **p)
// Построение идеально сбалансированного
// дерева с n вершинами.
// *p - указатель на корень дерева.
{
    node *now;
    int x, nl, nr;

    now = *p;
    if (n == 0) *p = NULL;
    else {
        nl = n / 2;
        nr = n - nl - 1;
        cin >> x;
        now = new(node);
        (*now).Key = x;
        Tree(nl, &((*now).Left));
        Tree(nr, &((*now).Right));
        *p = now;
    }
}

void TREE::Vyvod(node **w, int l)
// Изображение бинарного дерева, заданного
// указателем *w на экране дисплея.
{
    if (*w != NULL) {
        Vyvod(&((**w).Right), l + 1);
        for (int i = 1; i <= l; i++) cout << "   ";
        cout << (**w).Key << endl;
        Vyvod(&((**w).Left), l + 1);
    }
}

/*
Используя рекурсивный алгоритм определить
количество уровней в дереве.
 */
int TREE::getDept(node **w) {
    if (*w == NULL) return 0;
    return max(getDept(&((**w).Right)), getDept(&((**w).Left))) + 1;
}

/*
Вернуть узел с максимальным значением, обходя
дерево в ширину.
 */
node *TREE::maxNode(node **w) {
    vector<node *> vec1;
    vector<node *> vec2;
    node *result = nullptr;
    int max = -1;
    int k = 0;
    int deepness = getDept(w);
    // добавляем корень в вектор
    vec1.push_back(*w);
    while (k < deepness) {
        for (int i = 0; i < vec1.size(); i++) {
            if (vec1[i]->Left != NULL) {
                vec2.push_back(vec1[i]->Left);
            }
            if (vec1[i]->Right != NULL) {
                vec2.push_back(vec1[i]->Right);
            }
            if (vec1[i]->Key > max) {
                max = vec1[i]->Key;
                result = vec1[i];
            }
        }
        vec1 = vec2;
        vec2.clear();
        k++;
    }
    return result;
}

int TREE::getMaxValue(node **w) {
    if (*w == NULL) return 0;
    return max(max(getMaxValue(&(**w).Left), getMaxValue(&(**w).Right)), (**w).Key);
}

int TREE::getMinValue(node **w) {
    if (*w == NULL) return 10000;
    return min(min(getMinValue(&(**w).Left), getMinValue(&(**w).Right)), (**w).Key);
}

#endif //INC_4_BINARYTREE_H
