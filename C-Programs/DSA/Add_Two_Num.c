#include <stdio.h>
#include <stdlib.h>

//Structure of Linked List
struct ListNode
{
    int val;
    struct ListNode *next;
};

//Function to Create a Linked list from an Array
struct ListNode* CreateList(int arr[], int size)
{
    //Null Scenario
    if(size==0) return NULL;

    //Creation of Linked List
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val=arr[0];
    head->next= NULL;

    //Pointer for transversal and Transversal Loop
    struct ListNode *Curr = head;
    for(int i=1;i<size;i++)
    {
        Curr->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        Curr = Curr->next;
        Curr->val = arr[i];
        Curr->next = NULL;
    }
    return head;
}

//Function to print a Linked List
void Printlist(struct ListNode *head)
{
    //Pointer for Transversal and Printing Loop
    struct ListNode *Curr = head;
    while(Curr!=NULL)
    {
        printf("%d\t", Curr->val);
        Curr = Curr->next;
    }
    printf("\n");
}

//Function to free the memory
void FreeList(struct ListNode *head)
{
    struct ListNode *temp;
    while(head!=NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

//Function to Add two Numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    //Creation of Resultant linked list
    struct ListNode *Head;
    Head = (struct ListNode *)malloc(sizeof(struct ListNode));
    Head->val = 0;
    Head->next = NULL;

    //Temporary Pointers for transversal
    struct ListNode *C1 = l1;
    struct ListNode *C2 = l2;
    struct ListNode *H1 = Head;
    int Carry = 0;

    //Logic loop
    while(C1!=NULL || C2!=NULL || Carry!=0)
    {
        //Initialization
        int A = (C1!=NULL)?C1->val:0;
        int B = (C2!=NULL)?C2->val:0;
        int Sum = A+B+Carry;

        //Assigning Values
        H1->val = (Sum<10)?Sum:(Sum%10);
        Carry = (Sum<10)?0:(Sum/10);

        //Incrementing the pointer
        C1 = (C1!=NULL)?C1->next:C1;
        C2 = (C2!=NULL)?C2->next:C2;

        //Creating new nodes in resultant linked list
        if(C1!=NULL || C2!=NULL || Carry!=0)
        {
            H1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            H1->next->val = 0;
            H1->next->next = NULL;
            H1 = H1->next;
        }
    }
    return Head;
}

int main()
{
    //Initializations
    int Arr1[]={0,1,2,3,4};
    int Arr2[]={5,6,7,8,9};
    int S1 = sizeof(Arr1)/sizeof(Arr1[0]);
    int S2 = sizeof(Arr2)/sizeof(Arr2[0]);

    //Creating Linked list from Arrays
    struct ListNode *L1 = CreateList(Arr1, S1);
    struct ListNode *L2 = CreateList(Arr2, S2);

    //Adding the Two numbers
    struct ListNode *Result = addTwoNumbers(L1, L2);
    
    //Display the Results
    printf("Result:\n");
    Printlist(Result);

    //Free the Memory
    FreeList(L1);
    FreeList(L2);
    FreeList(Result);

    return 0;
}