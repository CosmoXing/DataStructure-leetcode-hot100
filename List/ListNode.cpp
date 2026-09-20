#include <iostream>
using namespace std;
//相交链表
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x),next(NULL){}
};

class Solution{
public:
    //创建两个链表的头节点
    ListNode *getintersectionNode(ListNode *headA,ListNode *headB){
        //边界处理
        if(headA==nullptr||headB==nullptr){
            return nullptr;
        }
        ListNode *pa=headA,*pb=headB;
        while (pa!=pb)
        {
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