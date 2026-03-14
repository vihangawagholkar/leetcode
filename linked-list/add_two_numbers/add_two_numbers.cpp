# include <iostream>

using namespace std;
// struct ListNode{
//     int val;
//     ListNode *next;
    // ListNode(): val(0), next(NULL){}
    // ListNode(int x): val(x), next(NULL){}
    // ListNode(int x, ListNode *next): val(x), next(NULL){}
// };

class ListNode{
    public:

    ListNode* next;
    int val;
    ListNode(){
        val=0;
        next = NULL;
    }
    ListNode(int x) {
        val = x;
        next = NULL;
    }
    ListNode(ListNode *next, int x) {
        val = x;
        this->next = next;
    }
};

class LinkedList{

};

ListNode* insert(ListNode* head, int n){

    
    ListNode* curr = head;
    int x;
    cout<<"Enter "<<n<<" values for the linked list: ";
    for(int i=1; i<n; i++){
        cin>>x;
        if(x){
            curr->next = new ListNode(x);
            curr = curr->next;
        }
    }
    return head;
}

void printList(ListNode* node){
    while(node != NULL){
        cout<<node->val;
        if(node->next != NULL)
            cout<<"->";
        
        node = node->next;
    }
    cout<<endl;
}

ListNode* add_two_numbers(ListNode* head1, ListNode* head2){
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    int carry = 0;

    while(head1!=NULL || head2 != NULL || carry != 0){

        int x = head1 ? head1->val : 0;
        int y = head2 ? head2->val : 0;

        int sum = x+y+carry;

        carry = sum/10;

        curr->next = new ListNode(sum%10);

        curr = curr->next;

        head1 = head1 ? head1->next : NULL;
        head2 = head2 ? head2->next : NULL;
    }

    return dummy->next;
}

int main(){
    cout<<"Enter the number of nodes in the 1st linked list: ";
    int n1;
    cin>>n1;

    cout<<"Enter "<<n1<<" values: ";

    int value1;
    cin>>value1;

    // Create head node

    ListNode* head1 = new ListNode(value1);

    insert(head1, n1);

    printList(head1);

    cout<<"Enter the number of nodes in the 2nd linked list: ";
    int n2;
    cin>>n2;

    cout<<"Enter "<<n2<<" values: ";

    int value2;
    cin>>value2;

    ListNode* head2 = new ListNode(value2);

    insert(head2, n2);
    printList(head2);

    cout<<"The add 2 numbers new linked list is ";

    printList(add_two_numbers(head1, head2));
}