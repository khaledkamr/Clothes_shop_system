/*    @khaledkamr 
         @End          
*/
//header
#include <bits/stdc++.h>
using namespace std;
//classes
struct node
{
    int data;
    string sdata;
    struct node* next;
};
struct node* top = NULL;
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp2;

class items
{
private:
    int pcode;
    float price;
    float dis;
    string pname;
public:
    void menu();
    void admin();
    void customer();
    void add();
    void del(int);
    void list();
    void receipt();
    void push(int);
    void displays();
    void pop_pos(int);
    void new_collection();
    void displayq();
};

void items::menu()
{
M:
    int choice;
    string username;
    string password;

    cout << "\t\t***************\n";
    cout << "\t\t\t\t                                       \n";
    cout << "\t\t\t <><>Clothing store Main Menu<><>           \n";
    cout << "\t\t\t\t                                       \n";
    cout << "\t\t***************\n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t| Selcet Any Of The Following  |\n";
    cout << "\t\t\t\t                   \n";
    cout << "\t\t  1)Employee   |<==\n";
    cout << "\t\t\t\t                   \n";
    cout << "\t\t  2)Customer   |<==\n";
    cout << "\t\t\t\t                   \n";
    cout << "\t\t  3)Exit       |<==\n";
    cout << "\t\t\t\t                   \n";
    cin >> choice;

    switch (choice)
    {
    case 1:

        cout << " login |== \n";
        cout << "  username : ";
        cin >> username;
        cout << " password :  ";
        cin >> password;
        if (username == "a" && password == "a")
        {
            admin();

        }
        else
        {
            cout << "Username or Password is incorrect ";
        }
        break;


    case 2:
    {
        customer();
    }
    case 3:
    {
        exit(0);

    }
    default:
    {
        cout << "Selcet from the given options";
    }
    }
    goto M;
}
void items::admin()
{
M:
    int choice;
    cout << "\n\n*********";
    cout << "\n\n\n\t\t\t Employee Menu";
    cout << "\n\t\t\t                         ";
    cout << "\n\t\t\t|Selcet Any Of The Following   |==";
    cout << "\n\t\t\t                         ";
    cout << "\n\t\t\t|1)Add the product   |<==";
    cout << "\n\t\t\t                         ";
    cout << "\n\t\t\t|2)inventory         |<==";
    cout << "\n\t\t\t                         ";
    cout << "\n\t\t\t|3)Waiting list      |<==";
    cout << "\n\t\t\t                         ";
    cout << "\n\t\t\t|4)Main Menu         |<==\n";
    cout << "\n\t\t\t                         ";

    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        displays();
        break;
    case 3:
        displayq();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Selcet from the given options";
    }
    goto M;
}
void items::customer()
{
M:
    int choice;
    string new_item;

    cout << "\t\t\t Customer \n";
    cout << "\t\t\t ******** \n";
    cout << "                            \n";
    cout << "\t\t\t Selcet Any Of The Following |==\n";
    cout << "                            \n";
    cout << "\t\t\t 1) Buy product   |<==\n";
    cout << "                            \n";
    cout << "\t\t\t 2) our latest tshirt|<==\n";
    cout << "                            \n";
    cout << "\t\t\t 3)  Back         |<==\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();

        break;
    case 2:
        new_collection();
        break;
    case 3:
        menu();
        break;
    default:
        cout << "Selcet from the given options";
    }
    goto M;
}
void items::displays()
{
    node* temp;

    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {

            // Print node data
            cout << temp->data;

            // Assign temp link to temp
            temp = temp->next;
            if (temp != NULL)
                cout << " -> ";
        }
    }
}
void items::pop_pos(int pos)
{

    node* temp = new node;
    node* prev = temp;
    temp = top;

    if (pos == temp->data)
    {
        top = top->next;
        delete temp;

    }
    else
    {
        while (temp->data != pos)
        {
            prev = temp;
            temp = temp->next;

        }
        prev->next = temp->next;
        delete temp;
    }
}
void items::push(int val)
{
    struct node* newnode = new node;
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}
void items::displayq()
{
    node* temp;

    if (front == NULL && rear == NULL)
    {
        cout << " the queue is empty ";
        return;
    }
    else
    {
        temp = front;
       
        while (temp != NULL)
        {
            cout << temp->sdata<< endl;
            temp = temp->next;
        }
       
        cout << "\n";
    }
}
void items::new_collection() //enqueue
{
    string new_name;
    cout << "enter the username : ";
    cin >> new_name;
    node* newnode = new node;
    newnode->sdata = new_name;
    newnode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    cout << " successfully pre-ordered";
}
void items::add()
{
M:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t  <><>Add new product<><>";
    cout << "\n\n\t\t\t***********";
    cout << "\n\n\t Enter the product number : ";
    cin >> pcode;
    cout << "\n\n\t Enter the product name : ";
    cin >> pname;
    cout << "\n\n\t Enter the price of the product : ";
    cin >> price;
    cout << "\n\n\t Enter the discount : ";
    cin >> dis;

    data.open("database.txt", ios::in); // in stand for read mode

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out); // app stand for abandoned | out stand for wirte mode
        data << "  " << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
        data.close();

    }
    else
    {
        data >> c >> n >> p >> d; // initialize the index

        while (!data.eof()) // eof ==>> end of file fun. 
            // this while loop  will make sure to check every content by iteration
        {
            if (c == pcode) // if the code matches
            {
                token++;  // the 0 will be incremented

            }
            data >> c >> n >> p >> d;// and then we will be reading from the file

        }
        data.close();

        if (token == 1)
            goto M;
        else {
            data.open("database.txt", ios::app | ios::out); // app stand for abandoned | out stand for wirte mode
            data << "  " << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t Record inserted !";

    push(pcode);
}
void items::del(int pkey) // the pkey will check for the first product code | if it matches the if block executes
{

    fstream data, data1;
    int token = 0;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist!";

    }
    else
    {
        data1.open("data1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;//iterating purpose
        while (!data.eof()) // it will not match and else block will executes
        {
            if (pcode == pkey)
            {
                token++;
                pop_pos(pkey);
            }
            else
            {
                data1 << "  " << pcode << "  " << "  " << pname << "  " << price << "  " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis; //iterating purpose
        }
        data.close();
        data1.close();

        if (token == 0)
        {
            cout << "\n\n Record not Found";
        }

    }
}
void items::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n#********************#\n";
    cout << "Productnum\t\tName\t\tPrice\n";
    cout << "\n\n#********************#\n";
    data >> pcode >> pname >> price >> dis; //iterating purpose
    while (!data.eof())
    {
        cout << pcode << "\t\t\t" << pname << "\t\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;//iterating purpose
    }
    data.close();
}
void items::receipt()
{
    fstream data;
    int arrcodes[100];  
    int arrquantity[100]; // and multiple quantitys
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t <><>Receipt<><>";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty Database";
    }
    else
    {
        data.close();
        list();
        cout << "\n_____________________________\n";
        cout << "\n                               ";
        cout << "\n    <><>Place the Order<><>  \n";
        cout << "\n                               ";
        cout << "\n_____________________________\n";
        do // why do while because we have to run a specific part of the code 
        //and the other part pased on the choice
        {
        M:
            cout << "\n\n Enter the Product code: ";
            cin >> arrcodes[c];
            del(arrcodes[c]);
            cout << "\n\n Enter the Product quantity : ";
            cin >> arrquantity[c];
            for (int i = 0; i < c; i++) // we will check if the product code matches with the code that has been already entered
            {
                if (arrcodes[c] == arrcodes[i])
                {
                    cout << "\n\n Duplicate product code , try again";
                    goto M;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product?, if (yes type y) else (no type n)";
            cin >> choice;
        } while (choice == 'y');


        data.close();
    }

}

int main() // creating the obj and call
{

    items i;
    i.menu();
}