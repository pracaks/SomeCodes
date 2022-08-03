#if 1
#include<iostream>
using namespace std;
 /* IN this question main problem is head can also be changed . in these questions where head gets
 changed we have to make a dummy node 
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 ListNode * getNode (int data =0)
 {
    ListNode * temp = new ListNode;
    temp->next=NULL;
    temp->val= data;
    return temp;
 }
 void printNode( ListNode * temp)
 {
    while(temp)
    {
        cout<<temp->val<<"-->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
 }
 ListNode * removeNode(ListNode* node, int data)
 {      
     if (node->val == data)
     {
        ListNode * temp = node;
        node = node->next;
        delete temp;
     }
     return node;
 }

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
     
     ListNode * dummy = getNode();
     dummy->next = head;
     ListNode * prev = dummy;
     ListNode * curr = head;
     while(curr)
     {
        if (curr->next && curr->val == curr->next->val)
        {
            int matched_value = curr->val;
            while (curr && curr->val==matched_value) // got saniti
            {
                curr = removeNode(curr,matched_value);
                prev->next = curr;
            }           
        }//if
        else
        {
            curr = curr->next;
            prev = prev->next;
        }          
     }   //while
    return dummy->next;    
    }//func
};//class
int main()
{
    Solution sln;
    ListNode * temp = NULL;
    ListNode * result = NULL;
#if 0
    //TC 1 
    temp =getNode(1);
    temp->next =  getNode(2);
    temp->next->next =  getNode(2);
    temp->next->next->next =  getNode(2);
    temp->next->next->next->next =  getNode(3);
    temp->next->next->next->next->next =  getNode(4);
    temp->next->next->next->next->next->next =  getNode(4);
    temp->next->next->next->next->next->next->next =  getNode(5);
    
    cout<<"input :"<<endl;
    printNode(temp);
    result = sln.deleteDuplicates(temp);
    printNode(result);
#endif
    //TC 2 
    temp = getNode(1);
    temp->next =  getNode(1);
    temp->next->next =  getNode(1);
    temp->next->next->next =  getNode(1);
    temp->next->next->next->next =  getNode(2);
    temp->next->next->next->next->next =  getNode(4);
    temp->next->next->next->next->next->next =  getNode(4);
    temp->next->next->next->next->next->next->next =  getNode(5);
    cout<<"Input :"<<endl;
    printNode(temp);
    result = sln.deleteDuplicates(temp);
    printNode(result);
}
#endif
