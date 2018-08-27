#ifndef TREELIST_H
#define TREELIST_H
#include<iostream>
#include <list>
#include "string"
using namespace std;

struct TreeListNode{
    string val;
    list<TreeListNode*> next;
    TreeListNode(){

    }
    TreeListNode(string vals){
        val=vals;
    }
};
class TreeList
{
public:
    TreeListNode * CreatTreeList();
};



#endif // TREELIST_H
