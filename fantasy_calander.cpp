#include <bits/stdc++.h>
using namespace std;
//---------------------------------------------------- CALANDER ----------------------------------------

string months[]= {"January","February","March","April","May","June","July","August","September","October","November","December"};
int monthDay[]= {31,28,31,30,31,30,31,31,30,31,30,31};
int m=100, n=100, i=0,j=0;
int **ar=new int *[m];

void initializer()
{
    for(int i=0; i<m; i++)
    {
        ar[i]= new int [n];
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            ar[i][j]= 0;
        }
    }
}


class Node
{
public:
    string title;
    string description;
    int date;
    string month;
    Node* next;
};

int get_1st_weekday(string day)
{
    int count=-1;
    string arr1[7]= {"Sunday", "Monday",  "Tuesday",  "Wednesday",  "Thursday",  "Friday",  "Saturday"};
    string arr2[7]= {"sunday", "monday",  "tuesday",  "wednesday",  "thursday",  "friday",  "saturday"};
    for (int i=0; i<7; i++)
    {
        count++;
        if(arr1[i]==day)
        {
            break;
        }
        else if(arr2[i]==day)
        {
            break;
        }
    }
    return count;
}

bool check_leap_year(int year)
{
    if((year%4 == 0 && year%100 != 0)||year%400 == 0)
    {
        return true;
    }
    return false;
}

void create_calendar()
{
    int year,month,day,daysInMonth,weekDay=0,startingDay;
    string starting_day;
    cout<<"Enter your desired year: ";
    cin>>year;
    cout<<"Enter the starting day of the year: ";
    cin>>starting_day;


    startingDay=get_1st_weekday(starting_day);
    if(check_leap_year(year)==true)
    {
        monthDay[1]=29;
    }

    initializer();

    for(month=0; month<12; month++)
    {
        daysInMonth=monthDay[month];
        j=0;
        for(weekDay=0; weekDay<startingDay; weekDay++)
        {

            ar[i][j] = -1 ;
            j++;
        }
        for(day=1; day<=daysInMonth; day++)
        {
            ar[i][j] = day;
            j++;
            if(++weekDay>6)
            {
                weekDay=0;
            }
            startingDay=weekDay;
        }
        i++;
    }
    int c=0;
    for(int i=0; i<12; i++)
    {
        c=0;
        cout<<"\n\n---------------"<<months[i]<<"-------------------\n";
        cout<<"\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n";

        for(int j=0; j<37; j++)
        {
            if(ar[i][j]==0)
            {
                break;
            }
            c++;
            if(ar[i][j]==-1)
            {
                cout<<"     ";
            }
            else
            {
                cout.width(5);
                cout<<right<<ar[i][j];
            }
            if(c==7)
            {
                c=0;
                cout<<endl;
            }
        }
        cout<<endl;
    }
}

void view_calendar(Node* head)
{
    for(int i=0; i<12; i++)
    {
        int c=0;
        cout<<"\n\n---------------"<<months[i]<<"-------------------\n";
        cout<<"\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n";

        for(int j=0; j<37; j++)
        {
            if(ar[i][j]==0)
            {
                break;
            }
            c++;
            if(ar[i][j]==-1)
            {
                cout<<"     ";
            }
            else
            {
                Node* n = head;
                int f=0;

                while(n!=NULL)
                {
                    if(n->date==ar[i][j]&&n->month==months[i])
                    {
                        f=1;
                    }
                    n = n->next;
                }

                if(f==1)
                {
                    string a = "*";
                    int b = ar[i][j];

                    cout.width(4);
                    cout<<right<<a<<b;
                }
                else
                {
                    cout.width(5);
                    cout<<right<<ar[i][j];
                }
            }
            if(c==7)
            {
                c=0;
                cout<<endl;
            }
        }
        cout<<endl;
    }
}

void view_month(Node* head)
{
    cout<<"Input month"<<endl;
    string month;
    cin>>month;
    for(int i=0; i<12; i++)
    {
        int c=0;

        if(months[i]==month)
        {
            cout<<"\n\n---------------"<<months[i]<<"-------------------\n";
            cout<<"\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n";

            for(int j=0; j<37; j++)
            {
                if(ar[i][j]==0)
                {
                    break;
                }
                c++;
                if(ar[i][j]==-1)
                {
                    cout<<"     ";
                }
                else
                {

                    Node* n = head;
                    int f=0;

                    while(n!=NULL)
                    {
                        if(n->date==ar[i][j]&&n->month==months[i])
                        {
                            f=1;
                        }
                        n = n->next;
                    }

                    if(f==1)
                    {
                        string a = "*";
                        int b = ar[i][j];

                        cout.width(4);
                        cout<<right<<a<<b;
                    }
                    else
                    {
                        cout.width(5);
                        cout<<right<<ar[i][j];
                    }
                }
                if(c==7)
                {
                    c=0;
                    cout<<endl;
                }
            }
            cout<<endl;

        }
    }
}

//-------------------------------------------------- ALARM -------------------------------------------

void printList(Node* n)
{
    while (n != NULL)
    {
        cout << n->title <<" ";
        cout << n->description<<" ";
        cout << n->date <<" ";
        cout << n->month <<" "<<endl;
        n = n->next;
    }
}


void add_reminder(Node** head_ref)
{
    string title;
    string description;
    int date;
    string month;
    cin>>title>>description>>date>>month;

    /* 1. allocate node */
    Node* new_node = new Node();

    /* 2. put in the data */
    new_node->title = title;
    new_node->description = description;
    new_node->date = date;
    new_node->month = month;

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

void update_reminder(Node* n)
{
    string temp_title;
    string new_description;
    int temp_date;
    string temp_month;
    cout<<"To update input title, date and month"<<endl;
    cin>>temp_title>>temp_date>>temp_month;

    while(n!=NULL)
    {
        if(n->title == temp_title&&n->date==temp_date&&n->month==temp_month)
        {
            cout<<"Modify description"<<endl;
            cin>>new_description;
            n->description = new_description;
        }
        n = n->next;
    }
}

void delete_reminder(Node** head_ref)
{
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;

    string temp_title;
    int temp_date;
    string temp_month;
    cout<<"To update input title, date and month"<<endl;
    cin>>temp_title>>temp_date>>temp_month;

    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->title == temp_title&&temp->date==temp_date&&temp->month==temp_month)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }

    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
    else
    {
        while (temp != NULL && temp->title != temp_title&&temp->date!=temp_date&&temp->month!=temp_month)
        {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == NULL)
            return;

        // Unlink the node from linked list
        prev->next = temp->next;

        // Free memory
        delete temp;
    }
}


// Driver code
int main()
{
    system("Color DE");
    // allocate 3 nodes in the heap

    Node* head = NULL;

    create_calendar();

    int operation = 0, flag=0;

    while(true)
    {
        cout<<"Add reminder press 1"<<endl;
        cout<<"Upade reminder press 2"<<endl;
        cout<<"Delete a specfic reminder press 3"<<endl;
        cout<<"View all the reminders of a specific month press 4"<<endl;
        cout<<"Exit press 0"<<endl;
        cout<<endl;

        int input;
        cin>>input;


        switch(input)
        {
        case 1:
            add_reminder(&head);
            operation++;
            break;
        case 2:
            update_reminder(head);
            operation++;
            break;
        case 3:
            delete_reminder(&head);
            operation++;
            break;
        case 4:
            view_month(head);
            break;
        case 0:
            flag=1;
            break;
        default:
            cout<<" Invalid input "<<endl;
        }

        if(flag==1)
        {
            break;
        }




        //view_calendar(head);

        //printList(head);
    }

    if(operation>=3)
    {
        view_calendar(head);
    }



    return 0;
}


