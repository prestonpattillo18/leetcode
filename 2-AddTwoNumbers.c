#include <stdlib>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//gendef
typedef struct ListNode List;

//prototypes
List * initList();
void addToTail(List * list, int value);

//'main'
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 || !l2) return NULL;

    int sum = 0; //sum tracker, this is the variable we put in nodes
    int carry = 0; //if sum is in double-digits, we move the tens digit to carry
    List * sumList = initList(); //the list we're going to return
    int lTrack = 0; //sees if either list is longer than the other

    while (l1 && l2){                   
        sum = l1->val + l2->val + carry; //sum block -- ensures that sum stays in single-digits while still maintaining carry value
            if (sum > 9){               
                carry = 1;              
                sum %= 10;              
            } else carry = 0;           
                                        
        addToTail(sumList, sum); //iteration of lists
        l1 = l1->next;                  
        l2 = l2->next;                  
        if (l1 && !l2) lTrack = 1;      
        else if (!l1 && l2) lTrack = 2; 
    }         

    //this block really just continues the last, but leaves out the shorter list on termination
    if (lTrack == 1){
        while (l1){
            sum = l1->val + carry; //still gotta sum in case of long string of 9s
                if (sum > 9){
                    carry = 1;
                    sum %= 10;
                } else carry = 0;
            addToTail(sumList, sum);
            l1 = l1->next;
        }
    } else if (lTrack == 2){
        while (l2){
            sum = l2->val + carry;
                if (sum > 9){
                    carry = 1;
                    sum %= 10;
                } else carry = 0;
            addToTail(sumList, sum);
            l2 = l2->next;
        }
    }
  
    //there can still be a floating value even past list lengths
    if (carry) addToTail(sumList, 1); 

    if (sumList->next == NULL) return sumList; //on empty lists, returns a default list containing only '0'
    return sumList->next; //else returns the list as usual
}

List * initList(){
    List * newList = malloc(sizeof(List));
      if (!newList) return NULL;
    newList->next = NULL;
    newList->val = 0;

    return newList;
}

//with this problem's specifications, its easier to add elements to the tail rather than the head since the original lists are stored in reverse order
void addToTail(List * list, int value){
    if (!list || value < 0 || value > 9) return;
    
    while (list->next != NULL) list = list->next;
    List * node = initList();
      if (node){
        list->next = node;
        node->val = value;
      }
  
    return;
}
