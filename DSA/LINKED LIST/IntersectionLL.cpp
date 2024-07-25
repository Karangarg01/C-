// https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/49785/java-solution-without-knowing-the-difference-in-len/
/*
Approach 1:
Time Complexity: O(n+m)
Space Complexity: O(1)
*/
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    //boundary check
    if(headA == null || headB == null) return null;
    
    ListNode a = headA;
    ListNode b = headB;
    
    //if a & b have different len, then we will stop the loop after second iteration
    while( a != b){
    	//for the end of first iteration, we just reset the pointer to the head of another linkedlist
        a = a == null? headB : a->next;
        b = b == null? headA : b->next;    
    }
    
    return a;
}

/*
Approach 2:
Time Complexity: O(n+m)
Space Complexity: O(1)
*/
class Solution {
private:
    int getLen(ListNode* head) {
        int count = 0;
        while (head != nullptr) {
            head = head->next;
            count++;
        }
        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getLen(headA);
        int len2 = getLen(headB);

        int diff = abs(len1 - len2);

        // Align headA and headB to the same starting point
        if (len1 > len2) {
            while (diff--) headA = headA->next;
        } else {
            while (diff--) headB = headB->next;
        }

        // Traverse both lists together to find the intersection
        while (headA != nullptr && headB != nullptr) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};

