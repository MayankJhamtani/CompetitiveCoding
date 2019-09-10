    struct Node
    {
    	int data;
    	Node* next;
     
    	Node(int k)
    	{
    		this->data = k;
    		this->next = NULL;
    	}
    };
     
    Node* insertFront(Node* head, int val)
    {
    	if(head == NULL)
    	{
    		head = new Node(val);
    		return head;
    	}
     
    	Node* tmp = new Node(val);
     
    	tmp->next = head;
    	head = tmp;
     
    	return head;
    }
     
    Node* insertBack(Node* head, int val)
    {
    	if(head == NULL)
    	{
    		head = new Node(val);
    		return head;
    	}
     
    	Node* walker = head;
     
    	Node* tmp = new Node(val);
     
    	while(walker->next != NULL)
    		walker = walker->next;
     
    	walker->next = tmp;
     
    	return head;	
    }
     
    Node* insertBack(Node* head, Node* tail, int val)
    {
    	if(head == NULL)
    	{
    		head = new Node(val);
    		tail = head;
    		return head;
    	}
    	Node* tmp = new Node(val);
     
    	tail->next = tmp;
    	tail = tmp;
     
    	return head;	
    }
     
    Node* deleteNode(Node* head, int val)
    {
    	if(head->data == val)
    	{
    		Node* tmp = head;
    		head = head->next;
    		delete tmp;
     
    		return head;
    	}
     
    	Node* walker = head;
     
    	while(walker->next != null && walker->next->data != val)
    		walker = walker->next;
     
    	Node* tmp = walker->next;
    	walker->next = walker->next->next;
    	delete tmp;
     
    	return head;
    }
     
    int main()
    {
    	Node* head;
    	head = new Node(10);
    }
