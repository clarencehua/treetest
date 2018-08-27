#include<treelist.h>
#include<iostream>
typedef list<TreeListNode*> LISTNODE;
TreeListNode *TreeList::CreatTreeList(){
    TreeListNode* head=new TreeListNode("a");

    TreeListNode *child1=new TreeListNode("a1");
    TreeListNode *child2=new TreeListNode("a2");
    TreeListNode *child3=new TreeListNode("a3");
    LISTNODE l=head->next;
    l.push_front(child1);
    l.push_front(child2);
    l.push_front(child3);
    l.push_front(child1);
     list<TreeListNode*>::iterator testiterator;

 return head;
}

//int main()
//{
//    CreatTreeList();
//    return 0;
//}

