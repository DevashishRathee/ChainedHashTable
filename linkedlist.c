#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

/*** defining linked list structure starts here ***/

struct node{
    int val;
    struct node* next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);



/*** defining linked list structure ends here ***/

int main(int argc,char **argv){
    int option;
    do{
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Sort the list");
        printf("\n 13: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1: start = create_ll(start);
        printf("\n LINKED LIST CREATED");
        break;
        case 2: start = display(start);
        break;
        case 3: start = insert_beg(start);
        break;
        case 4: start = insert_end(start);
        break;
        case 5: start = insert_before(start);
        break;
        case 6: start = insert_after(start);
        break;
        case 7: start = delete_beg(start);
        break;
        case 8: start = delete_end(start);
        break;
        case 9: start = delete_node(start);
        break;
        case 10: start = delete_after(start);
        break;
        case 11: start = delete_list(start);
        printf("\n LINKED LIST DELETED");
        break;
        case 12: start = sort_list(start);
        break;
 }
    }while(option!=13);

    getch();

    return 0;
}

struct node *create_ll(struct node *start){
    struct node *new_node,*ptr;
    int num;
    printf("\n Enter -1 to End Creation");
    printf("\n Enter the Val");
    scanf("%d",&num);
    while(num!=-1){
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->val = num;
        if(start == NULL){
            new_node->next = NULL;
            start = new_node;
        }
        else{
            ptr = start;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\n Enter the Val");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr = start;
    printf("\n Inside Display *** \n Address in pointer is %p %p \n",start,ptr);
    while(ptr!=NULL){
        printf("%d->",ptr->val);
        ptr=ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *new_node = NULL;
    int num;
    printf("\n Please enter the new value to insert at beginning:");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = num;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start){
    struct node *new_node = NULL;
    int num;
    printf("\n Please enter the new value to insert at end:");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = num;
    struct node *ptr = start;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
    return start;
}

struct node *insert_before(struct node *start){
    struct node *new_node,*ptr,*preptr;
    int num,val;
    printf("\n Enter the Value to be Inserted");
    scanf("%d",&num);
    printf("\n Enter the Value Before which above value to be Inserted");
    scanf("%d",&val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = num;
    ptr = start;
    while(ptr->val != val){
        preptr = ptr;
        ptr=ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *insert_after(struct node *start){
    struct node *new_node,*ptr,*preptr;
    int num,val;
    printf("\n Enter the Value to be Inserted");
    scanf("%d",&num);
    printf("\n Enter the Value After which above value to be Inserted");
    scanf("%d",&val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = num;
    ptr = start;
    preptr = ptr;
    while(preptr->val != val){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *delete_beg(struct node *start){
    struct node *tbd = start;
    start = start->next;
    free(tbd);
    return start;
}

struct node *delete_end(struct node *start){
    struct node *ptr,*preptr;
    ptr = start;
    while(ptr->next!=NULL){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start){
    struct node *ptr,*preptr;
    ptr = start;
    int val;
    printf("\n Enter Value of Node to be deleted");
    scanf("%d",&val);
    if(ptr->val == val){
        start = delete_beg(start);
        return start;
    }
    else{
        while(ptr->val != val){
        preptr = ptr;
        ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
    return start;
}

struct node *delete_after(struct node *start){
    struct node *ptr,*preptr;
    int val;
    printf("\n Enter Value of Node after which node has to be deleted");
    scanf("%d",&val);
    ptr = start;
    preptr = ptr;
    while(preptr->val != val){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

struct node *delete_list(struct node *start){
    struct node *ptr;
    if(start!=NULL){
        ptr = start;
        while(ptr!=NULL){
            printf("\n Value to be deleted next is %d",ptr->val);
            start = delete_beg(start);
            ptr = start;
        }
    }
    return start;
}

struct node *sort_list(struct node *start){
    struct node *ptr1,*ptr2;
    int temp;
    ptr1 = start;
    while(ptr1->next!=NULL){
        ptr2 = ptr1->next;
        while(ptr2!=NULL){
            if(ptr1->val > ptr2->val){
                temp = ptr1->val;
                ptr1->val = ptr2->val;
                ptr2->val = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}