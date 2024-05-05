/* First approach 
Created a vector to copy elements of the linked list and found the if it is palindrome or not
Space complexity = O(n)
Time complexity = O(n)
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.  
    bool check(vector<int> v){
        int s=0;
        int n=v.size();
        int e=n-1;
        
        while(s<e){
            if(v[s++]!=v[e--]) return false;
        }
        
        return true;
    }
    
    bool isPalindrome(Node *head)
    {
       vector<int> v;
       Node* temp = head;
       while(temp){
           v.push_back(temp->data);
           temp = temp->next;

       }
       
       return check(v);
    }

/* Second approach:
Found the middle node of Linked list 
Reverse the linked list after middle node
Compare the data from start and reverse node

Space complexity = O(1) Time complexity = O(n)
*/
Node* findMiddle(Node* head){
        Node* temp = head;
        Node* slow = temp;
        Node* fast = temp->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* rev(Node* temp){
        Node* prev = nullptr;
        Node* curr = temp;
        Node* next = nullptr;
        while(curr){
            
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head)
    {
     
     if(head->next ==nullptr ) return true;
     
     Node* head1 = head;
     Node* mid = findMiddle(head);
     
     Node* temp = mid->next;
     mid->next = rev(temp);
     
     Node* head2 = mid->next;
     while(head2){
         if(head1->data != head2->data) return false;
         head1=head1->next;
         head2 = head2->next;
     }
     
     temp = mid->next;
     mid->next = rev(temp);
     return true;
    }
};
