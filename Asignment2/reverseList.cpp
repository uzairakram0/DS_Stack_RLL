typedef struct list {
    item_type item;
    struct list ∗ next ;
}list;

// this function reveses a singly linked list
void reverse_list(list **l){
    
    list *current = *l;         // set currrent to node pointer referenced by parameter **l
    list *last = nullptr;       // last node pointer that will point to the last node referenced by current pointer
    list *next = nullptr;       // next points to next node by current
    
    while (current != nullptr){     // loop till i reach the end of list
        next = current -> next;     // next is set to next node
        current->next = last;       // next poiner of current is pointed backward to the last node
        // update
        last = current;             // last is updated to current
        current = next;             // current is moved to next
    }
    
}
