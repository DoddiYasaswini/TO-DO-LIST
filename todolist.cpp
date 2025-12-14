#include<iostream>
using namespace std;
struct node
{
    string name;
    int id;
    int date;
    int month;
    int year;
    struct node *next;
};
int taskcount=0;
node *head=NULL,*last=NULL;
node *getnode(string n,int d,int m,int y){
    node *temp=new node;
    taskcount++;
    temp->id=taskcount;
    temp->name=n;
    temp->date=d;
    temp->month=m;
    temp->year=y;
    temp->next=NULL;
    return temp;
}
void InsertEnd(node *newnode){
    if(head==NULL)
    head=last=newnode;
    else{
    last->next=newnode;
    last=newnode;
    }
}
void deleteTask(int n)
{
    if (head == NULL) {
        cout << "No tasks available\n";
        return;
    }

    if (head->id == n) {
        node* temp = head;
        head = head->next;
        delete temp;
        cout << "Task deleted successfully\n";
        return;
    }

    node* prev = head;
    node* curr = head->next;

    while (curr != NULL && curr->id != n) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Task not found\n";
        return;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Task deleted successfully\n";
}
void display(){
    if(head==NULL)
    cout<<"List is empty"<<endl;
    else{
         struct node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->id<<". "<<temp->name<<" - "<<"Deadline: "<<temp->date<<"-"<<temp->month<<"-"<<temp->year<<endl;
            temp=temp->next;
        }
    }
}
int main()
{
    cout<<"Welcome to To-Do List Application!"<<endl;
    int choice;
    while(true){
    cout<<"Choose on operation: "<<endl;
    cout<<"1.Add Task"<<endl;
    cout<<"2.Delete Task"<<endl;
    cout<<"3.Display Tasks"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            string nam;
            int dat,mon,yea;
            cout<<"Enter task name: ";
            cin>>nam;
            cout<<"Enter deadline: "<<endl;
            cout<<"Enter date: ";
            cin>>dat;
             if(dat>31)
             {
                 cout<<"Invalid date format! Task not added."<<endl;
                 break;
             }
            cout<<"Enter month: ";
            cin>>mon;
              if(mon>12)
             {
                 cout<<"Invalid month format! Task not added."<<endl;
                 break;
             }
            cout<<"Enter year: ";
            cin>>yea;
             struct node* x=getnode(nam,dat,mon,yea);
             InsertEnd(x);
             cout<<"Task added successfully"<<endl;
        }break;
        case 2:
        {
            int n;
            cout<<"Enter task number to delete: ";
            cin>>n;
            deleteTask(n);
        }break;
        case 3:
        {
            cout<<"Your Tasks: "<<endl;
            display();
        }break;
        case 4:
        {
            cout<<"Exiting application.GoodBye!"<<endl;
            return 0;
        }break;
        default:cout<<"Invalid choice!"<<endl;
    }
}
return 0;
}