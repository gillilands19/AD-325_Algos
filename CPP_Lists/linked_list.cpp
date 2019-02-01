    #include<iostream>
    #include<cstdio>
    #include<cstdlib>

    using namespace std;


//declares node struct. struct is like class declaration except all attributes are always public
    struct node
    {
        int data;
        struct node *next;
    }*head;

//declares linked list class and methods
    class linked_list
    {
        public:
            node* create_node(int);
            void insert(); 
            void delete_pos();
            void update();
            void display();
            void num_nodes();
            linked_list() 
            {
                head = NULL;
            }

    };


    //displays list of choices and performs logic based on option chose
    int main()

    {
        int choice, nodes, element, position, i;
        linked_list sl;
        head = NULL;
        
        while (1)
        {

            cout<<endl<<"---------------------------------"<<endl;

            cout<<endl<<"Operations on singly linked list"<<endl;

            cout<<endl<<"---------------------------------"<<endl;

            cout<<"1.Insert Node"<<endl;

            cout<<"2.Delete Node"<<endl;

            cout<<"3.Update Node Value"<<endl;

            cout<<"4.Display Linked List"<<endl;

            cout<<"5.Get Total Number of Nodes"<<endl;
            
            cout<<"6.Exit"<<endl;

            cout<<"Enter your choice : ";

            cin>>choice;

            switch(choice)
            {
            case 1:

                cout<<"Inserting Node: "<<endl;
                cout<<endl;
                sl.insert();
                cout<<endl;
                break;

            case 2:
                cout<<"Delete a node: "<<endl;
                cout<<endl;
                sl.delete_pos();
                break;
            
            case 3:
                cout<<"Update Node Value:"<<endl;
                cout<<endl;  
                sl.update();
                cout<<endl;
                break;

            case 4:
                cout<<"Display All"<<endl;
                cout<<endl;
                sl.display();
                cout<<endl;
                break;

            case 5:
                cout<<"Total Nodes in List: "<<endl;
                sl.num_nodes();
                cout<<endl;
                break;

            case 6:
                cout<<"Exiting..."<<endl;
                exit(1);
                break;  
            
            default:
                cout<<"Invalid entry"<<endl;
                exit(1);
                break;
            }
        }
    }

    //creates a node
    node *linked_list::create_node(int value)
    {
        struct node *temp, *s;
        temp = new(struct node); 
        if (temp == NULL)
        {
            cout<<"Memory not allocated "<<endl;
            return 0;
        }
        else
        {
            temp->data = value;
            temp->next = NULL;     
            return temp;
        }
    }
    //insert
    void linked_list::insert()
    {

        int value;
        cout<<"Enter the value to be inserted: ";
        cin>>value;
        struct node *temp, *s;
        temp = create_node(value);
        s = head;

        if (head == NULL)
        {
          head = temp;
          head->next = NULL;
        }
        else
        {
          while (s->next != NULL)
          {         
              s = s->next;        
          }
          temp->next = NULL;
          s->next = temp;
          cout<<"Element Inserted at last"<<endl;
        }
    }

    //delete from chosen position
    void linked_list::delete_pos()
    {
        int pos, i, counter = 0;
        if (head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        cout<<"Enter the position of value to be deleted: ";
        cin>>pos;
        struct node *s, *ptr;
        s = head;
        if (pos == 1)
        {
            head = s->next;
        }
        else
        {
            while (s != NULL)
            {
                s = s->next;
                counter++;  
            }
            if (pos > 0 && pos <= counter)
            {
                s = head;
                for (i = 1;i < pos;i++)
                {
                    ptr = s;
                    s = s->next;
                }
                ptr->next = s->next;
            }
            else
            {
                cout<<"Position out of range"<<endl;
            }
            free(s);
            cout<<"Element Deleted"<<endl;
        }
    }

    //updates node at given position
    void linked_list::update()
    {
        int value, pos, i;
        if (head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        cout<<"Enter the node postion to be updated: ";
        cin>>pos;
        cout<<"Enter the new value: ";
        cin>>value;
        struct node *s, *ptr;
        s = head;
        if (pos == 1)
        {
            head->data = value; 
        }
        else
        {
            for (i = 0;i < pos - 1;i++)
            {
                if (s == NULL)
                {
                    cout<<"There are less than "<<pos<<" elements";
                    return;
                }
                s = s->next;
            }
            s->data = value;  
        }
        cout<<"Node Updated"<<endl;

    }

    //prints all elements of list
    void linked_list::display()
    {
      struct node *temp;
      if (head == NULL)
      {
          cout<<"The List is Empty"<<endl;
          return;
      }
      temp = head;
      cout<<"Elements of list are: "<<endl;
      while (temp != NULL)
      {
          cout<<temp->data<<"->";
          temp = temp->next;
      }
      cout<<"NULL"<<endl;
    }

    //prints the total number of nodes in list
    void linked_list::num_nodes()
    {
      struct node *temp;
      if (head == NULL)
      {
        cout<<"0 Nodes in List"<<endl;
        return;
      }
      temp = head;
      cout<<"Nodes in List: "<<endl;
      int node_count = 0;
      while (temp != NULL)
      {
        temp = temp->next;
        node_count++;
      }
      cout<<node_count<<endl;
    }