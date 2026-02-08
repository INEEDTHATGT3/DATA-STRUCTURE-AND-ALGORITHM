node* reverseKNode(node* &n1, int k){
    if(n1 == NULL){
        cout << "LL is empty" << endl;
        return NULL;
    }
    int len = getLength(n1);
    if(k >len){
        cout << "enter valid value for k" << endl;
        return n1;
    }

    //it means number of node in LL is >= k
    //step 1
    node* prev = NULL;
    node* curr = n1;
    node* forward = curr -> next;
    int count = 0;

    while(count < k){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    //step 2
    if(forward != NULL){
        //still have node left
        n1 -> next =reverseKNode(forward, k);
    }
    // step 3
    return prev;
}
