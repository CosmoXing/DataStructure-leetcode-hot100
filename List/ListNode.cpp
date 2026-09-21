#include <iostream>
using namespace std;
//相交链表
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x),next(NULL){}
};
//双指针解法（更高效）O（1）空间 
class Solution{
public:
    //创建两个链表的头节点
    ListNode *getintersectionNode(ListNode *headA,ListNode *headB){
        //边界处理
        if(headA==nullptr||headB==nullptr){
            return nullptr;
        }\
        //指针初始化
        ListNode *pa=headA,*pb=headB;
        while (pa!=pb)
        {
            //判断
            if(pa==nullptr){
                 pa=headB;
            }
            else{
                pa=pa->next;
            }
            if(pb==nullptr){
                pb=headA;
            }
            else{
                pb=pb->next;
            }
        }
        return pa;
    }
};

//哈希集合
/*
思路分析：1先遍历链表A，把所有节点地址存入unordered_set
2遍历链表B，第一个能在集合中找到的节点 就是相交起点
*/
class Solution{
public:
    ListNode *getintersectionNode(ListNode *headA,ListNode *headB){
        //需要定义
        unordered_set<ListNode *> visited;
        ListNode *temp=headA;
        while (temp!=nullptr)
        {
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp!=nullptr)
        {
            if(visited.cout(temp)){
                return temp;
            }
            temp=temp->next;
        }
        return nullptr;
    }
};
//测试代码
int main() {
    // 构造相交链表：
    // A: 4 -> 1 ->
    //             8 -> 4 -> 5
    // B: 5 -> 0 -> 1 ->
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution sol;
    ListNode* res = sol.getintersectionNode(headA, headB);
    if (res) {
        std::cout << "相交节点值为：" << res->val << std::endl;
    } else {
        std::cout << "不相交" << std::endl;
    }
    return 0;
}