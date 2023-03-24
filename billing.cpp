#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
    int pcode;
    float price;
    float dis;
    string pname;
    public:
    void menu();
    void administrator();
    void buyer();
    void edit();
    void add();
    void rem();
    void list();
    void receipt();
    

};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t_____________________________________________\n";
    cout<<"\t\t\t\t                                             \n";
    cout<<"\t\t\t\t             supermarket main menu           \n";
    cout<<"\t\t\t\t                                             \n";
    cout<<"\t\t\t\t_____________________________________________\n";
    cout<<"\t\t\t\t                                             \n";
    cout<<"\t\t\t\t                                             \n";
    cout<<"\t\t\t\t|           1) ADMINISTRATOR                |\n";
    cout<<"\t\t\t\t                                             \n";
    cout<<"\t\t\t\t|           2) BUYER                        |\n";
    cout<<"\t\t\t\t                                             \n";
    cout<<"\t\t\t\t|           3) EXIT                         |\n";
    cout<<"\n\t\t\t  please select!";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
        cout<<"\t\t\t please login \n";
        cout<<"\t\t\t enter email \n";
        cin>>email;
        cout<<"\t\t\t password     \n";
        cin>>password;

        if(email="ck@email.com" && password="ck")
        {
            administrator();
        }
        else
        {
            cout<<"invalid email and password";
        }
        break;
    }
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout<<"please select from the given option";
    }
}
goto m;
}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t ADMINISTRATOR MENU";
    cout<<"\n\t\t\t|____1) Add the product_______|";
    cout<<"|                                     |";
    cout<<"\n\t\t\t|____2) Modify the product____|";
    cout<<"|                                     |";
    cout<<"\n\t\t\t|____3) Delete the product____|";
    cout<<"|                                     |";
    cout<<"\n\t\t\t|____4) Back to main menu_____|";

    cout<<"\n\n\t please enter your choice";
    cin>>choice;

    switch(choice)
    {
        case 1:
        add();
        break;

        case 2:
        edit();
        break;

        case 3:
        rem();
        break;

        case 4:
        menu();
        break;

        default:
        cout<<"invalid choice!";
    }
    goto m;

}

void shopping :: buyer()

{ 
    m:
    int choice;
    cout<<"\t\t\t  1) Buyer \n";
    cout<<"\t\t\t________________\n";
    cout<<"                      \n";
    cout<<"\t\t\t  2) Buy product\n";
    cout<<"                      \n";
    cout<<"\t\t\t  2) go back    \n";
    cout<<"\t\t\t Enter your choice:";
    cin>>choice;

    switch(choice)
    {
        case 1:
        receipt();
        break;

        case 2:
        menu();

        default:
        cout<<"invalid choice";
    }
    goto m;

}

void shopping :: add()
{ m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n Name of the product";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on product";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;

        }
        data.close();
    }
    if(token==1)
    goto m;
    else
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<dis<<"\n";
        data.close();

    }
    cout<<"\n\n\t\t Record inserted !";


}

void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code:";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n file doesn't exist! ";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t product new code:";
                cin>>c;

                cout<<"\n\n name of the product:";
                cin>>pname;
                cout<<"\n\t\t price:";
                cin>>p;
                cout<<"\n\t\t discount:";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t record edited";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n record not found sorry!";

        }
    }

}

void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t delete product";
    cout<<"\n\n\t product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"file doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t product deleted succesfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n record not found";
        }
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|______________________________________\n";
    cout<<"prono\t\t Name \t\t price \n";
    cout<<"\n\n|______________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    } 
    data.close();
}

void shopping_receipt()
{ 
    m:
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    void list();


    cout<<"\n\n\t\t\t\t RECEIPT  ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n empty database";
    }
    else{
        data.close();

        list();
        cout<<"\n______________________________________________________\n";
        cout<<"\n|                                                      \n";
        cout<<"\n            Please place the order                     \n";
        cout<<"\n|                                                      \n";
        cout<<"\n_______________________________________________________\n";

        do
        {
            cout<<"\n\n Enter product code:";
            cin>>arrc[c];
            cout<<"\n\n Enter the product quantity:";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n duplicate product code. please try again!";
                    goto m;
                }
                c++;
                cout<<"\n\n Do you want to buy the another product? if yes then press y else no";
                cin>>choice;
            }    
        } while (choice == "y");

        
        

    }
}

