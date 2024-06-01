    //we don't need an array to attach linked list
    //we detect throughout ->next
    //to understand all the functions i've written, you should draw a linked list on paper
    //wrote by Tuan Anh Trinh
    #include <iostream>
    #include <string>
    #include <map>
    using namespace std; 
    enum Command {ADDLAST, ADDFIRST, ADDAFTER, ADDBEFORE, REMOVE, REVERSE, QUIT, UNKNOWN}; //declare enum type command
    //declare a map to store the command which help us to find the command when we write from keyboard
    map<string, Command> commandMap = {
        {"addlast", ADDLAST},
        {"addfirst", ADDFIRST},
        {"addafter", ADDAFTER},
        {"addbefore", ADDBEFORE},
        {"remove", REMOVE},
        {"reverse", REVERSE},
        {"#", QUIT}
    };
    //it's essential for linked list to have a struct to store the value and the pointer to the next node
    struct Node
    {
        int data;
        struct Node * next;
    };
    // create a new node
    Node* makeNote (int value)
    {
        struct Node * p = new Node;
        p->data = value;
        p->next = NULL;
        return p;
    }
    void printList (Node * head) // print value of each menber
    {
        Node *p = head;
        while (p != NULL) // stop as reach end
        {
            cout << p->data << " ";
            p = p->next; // p becomes the pointer point to the next member throughout p->next
        }
        delete p;
    }
    //input function to input the value of each member
    Node* input(int n)
    {
        Node* head = NULL; //declare 2 pointer to attach head and tail
        Node* tail = NULL;
        cin >> n;
        //cout << "oke donkey" << endl;
        for (int i = 1; i <= n; i++)
        {
            int value;
            cin >> value; // enter value from keyboard
            Node * newNode = makeNote(value); //declare new node
            if (head == NULL) //if there is no menber
            {
                head = newNode;
                tail = newNode;
            }
            else 
            {
                tail->next = newNode; // tail->next point to next node
                tail = newNode;         //tail point to next node, tail->next becomes null
            }
        }
        return head; //return head to main function
    }
    //for enter command from keyboard
    Command getCommand()
    {
        string input;
        cin >> input;
        //try to find the command in the map
        auto it = commandMap.find(input); //find trả về iterator trỏ đến vị trí của phần tử trong map nếu không tìm thấy trả về end()
        return it != commandMap.end() ? it->second : UNKNOWN; //end() trả về vị trí sau của phần tử cuối cùng của map
    }
    //function to find the value in the linked list
    bool Find(Node* head, int value)
    {
        Node* p = head;
        while (p != NULL)
        {
            if (p->data == value)
            {
                return true;
            }
            p = p->next;
        }
        return false;
    }
    //function to add the value to the first of the linked list
    void addFirst(Node* &head, int value)
    {
        Node* newNode = makeNote(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else if (Find(head, value) == false)
        {
            newNode->next = head;
            head = newNode;
        }
    }
    //function to add the value to the last of the linked list
    void addLast(Node* &head, int value)
    {
        Node* newNode = makeNote(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else if (Find(head, value) == false)
        {
            Node* p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newNode;
        }
    }
    //function to add the value2 after the value1
    void addAfter(Node* &head, int value1, int value2)
    {
        Node* newNode = makeNote(value2);
        if (head == NULL)
        {
            head = newNode;
        }
        else if (Find(head, value2) == false)
        {
        Node* p = head;
        while (p != NULL)
        {
            if (p->data == value1)
            {
                newNode->next = p->next;
                p->next = newNode;
                break;
            }
            p = p->next;
        }
        }
    }
    //function to add the value2 before the value1
    void addBefore(Node* &head, int value1, int value2)
    {
        Node* newNode = makeNote(value2);
        if (head == NULL)
        {
            head = newNode;
        }
        else if (Find(head, value2) == false)
        {
            Node* p = head;
            while (p != NULL)
            {
                if (p->next->data == value1)
                {
                    newNode->next = p->next;
                    p->next = newNode; 
                    break;
                }
                p = p->next;
            }
        }
    }
    //function to remove the value from the linked list
    void remove (Node* &head, int value)
    {
        if (head == NULL)
        {
            return;
        }
        if (head->data == value) //if the first node is the value
        {
            Node* p = head;
            head = head->next;
            delete p;
        }
        else
        {
            Node* p = head;
            while (p->next != NULL)
            {
                if(p->next->data == value)
                {
                    Node* temp = p->next; //create a temp pointer to point to the node that we want to delete
                    p->next = p->next->next;
                    delete temp;
                    break;
                }
                p = p->next;
            }
        }
    }
    //function to reverse the linked list
    void reverse(Node* &head)
    {
        Node* p = head; //create 3 pointer to point to 3 consecutive nodes
        Node* q = NULL;
        Node* r = NULL;
        while (p != NULL) 
        {
            r = q; 
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q; // q is the last node now becomes head

    }
    //declare value1, value2 to store the value from keyboard
    int value, value1, value2;
    //function to show the command
    void showCommand (Command type, Node* &head)
    {
        
        switch(type)
        {
            case ADDLAST:
            //cout << "addlast" << endl;
            cin >> value;
            addLast(head, value);
            break;
            case ADDAFTER:
            //cout << "addafter" << endl;
            cin >> value2 >> value1;
            addAfter(head, value1, value2);
            break;
            case ADDFIRST:
            cin >> value;
            addFirst(head, value);
            break;
            case ADDBEFORE:
            cin >> value2 >> value1;
            addBefore(head, value1, value2);
            break;
            case REMOVE:
            cin >> value;
            remove(head, value);
            break;
            case REVERSE:
            reverse(head);
            break;
            default:
            break; 
        }
    }
    int main()
    {
        int n;
        Node *head = input(n);
        Command type;
        while(1) //loop until we enter QUIT(#)
        {
            type = getCommand();
            if (type == QUIT)
            {
                break;
            }
            showCommand(type, head); 
        }
        printList(head);
        return 0;
    }