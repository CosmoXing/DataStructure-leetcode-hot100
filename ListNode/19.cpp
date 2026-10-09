#include <iostream>
#include <stack>//栈的头文件
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() :val(0),next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//删除链表的倒数第n个节点
//法一：栈
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        //创建哑节点
        ListNode *dumy=new ListNode(0,head);
        //建栈
        stack<ListNode*> stk;
        //遍历指针
        ListNode *cur=dumy;
        //压栈
        while (cur)
        {
            stk.push(cur);
            cur=cur->next;
        }
        //弹出n个
        for(int i=0;i<n;i++){
            stk.pop();
        }
        //保存栈顶(待删除节点的前驱)
        ListNode *prev=stk.top();
        //跳过待删除节点
        prev->next=prev->next->next;
        //保存结果头节点
        ListNode*result=dumy->next;
        delete dumy;
        return result;
    }
};

//法二：双指针(快慢指针)
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        //创建哑节点
        ListNode *dumy=new  ListNode(0,head);
        //创建快慢指针（快指针从head节点开始，慢指针从dumy开始）
        ListNode *first=head;
        ListNode *second=dumy;
        //快指针先走n步
        for(int i=0;i<n;i++){
            first=first->next;
        }
        while (first)
        {
            first=first->next;
            second=second->next;
        }
        //当快指针指向nullptr时，慢指针所指为待删节点的前驱
        second->next=second->next->next;
        //保存头节点
        ListNode *result=dumy->next;
        //释放空间
        delete dumy;
        return result;
    }
};