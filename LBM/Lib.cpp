#include <iostream>
#include <stdio.h>
#include <cstring>
#include <ctime>
using namespace std;

class Library
{
    public:
    string book_name;
    Library()
    {
        book_name="";
    }

    void display()
    {
        cout<<"1.Display The Books in Library"<<endl;
        cout<<"2.Lend a Book"<<endl;
        cout<<"3.Add a Book"<<endl;
        cout<<"4.Return The Book"<<endl;
    }

    void display1(string name,int roll,int hist,int geog,int m,int sc)
    {
        string n=name;
        int r=roll;
        int his=hist,geo=geog,math=m,sci=sc;
        cout<<"Books name are:"<<endl;
        cout<<"1.History: "<<his<<endl;
        cout<<"2.Geography:"<<geo<<endl;
        cout<<"3.Mathematics: "<<math<<endl;
        cout<<"4.Science: "<<sci<<endl;
        cout<<"Enter c to continue and q to quit."<<endl;
        string choice;
        cin>>choice;
        if(choice=="c")
        {
            display2(n,r,his,geo,math,sci);
        }
        else if(choice=="q")
        {
            cout<<"Session has terminated."<<endl;
        }

        else
        {
            display1(n,r,his,geo,math,sci);
        }
    }

    void display2(string name,int roll,int hist,int geog,int m,int sc)
    {
        string n=name;
        int r=roll;
        int his=hist,geo=geog,math=m,sci=sc;
        display();
        cout<<"Enter Your Choice"<<endl;
        int choice;
        cin>>choice;
        if(choice==1)
        {
            display1(n,r,his,geo,math,sci);
        }
        if(choice==2)
        {
            cout<<"Enter The Position of Book which You want"<<endl;
            int l;
            cin>>l;
            lend(l,n,r,his,geo,math,sci);

        }
        if(choice==3)
        {
            cout<<"Enter The Position of Book that you want to add"<<endl;
            int k;
            cin>>k;
            lend(k,n,r,his,geo,math,sci);
        }
        if(choice==4)
        {
            cout<<"The Book Has been returned by "<<n<<endl;
        }
    }

    void lend(int l,string name,int roll,int hist,int geog,int m,int sc)
    {
        string n=name;
        int r=roll;
        int le=l;
        int his=hist,geo=geog,math=m,sci=sc;
        time_t t; // t passed as argument in function time()
        struct tm * tt; // decalring variable for localtime()
        time (&t); //passing argument to time()
        tt = localtime(&t);
        
        if(le==1)
        {
            cout<<"History Book is lended to "<<n<<endl;;
            cout<<"Time: " << asctime(tt) << endl;
            his=his-1;
            cout<<"Enter c to continue and q to quit."<<endl;
        string choice;
        cin>>choice;
        if(choice=="c")
        {
            display2(n,r,his,geo,math,sci);
        }
        else if(choice=="q")
        {
            cout<<"Session has terminated."<<endl;
        }

        else
        {
            display1(n,r,his,geo,math,sci);
        }
        }
        else if(le==2)
        {
            cout<<"Geography Book is lended to "<<n<<endl;;
            cout<<"Time: " << asctime(tt) << endl;
            geo=geo-1;
            cout<<"Enter c to continue and q to quit."<<endl;
        string choice;
        cin>>choice;
        if(choice=="c")
        {
            display2(n,r,his,geo,math,sci);
        }
        else if(choice=="q")
        {
            cout<<"Session has terminated."<<endl;
        }

        else
        {
            display1(n,r,his,geo,math,sci);
        }
        }
        else if(le==3)
        {
            cout<<"Mathematics Book is lended to "<<n<<endl;;
            cout<<"Time: " << asctime(tt) << endl;
            math=math-1;
            cout<<"Enter c to continue and q to quit."<<endl;
        string choice;
        cin>>choice;
        if(choice=="c")
        {
            display2(n,r,his,geo,math,sci);
        }
        else if(choice=="q")
        {
            cout<<"Session has terminated."<<endl;
        }

        else
        {
            display1(n,r,his,geo,math,sci);
        }
        }
        else if(le==4)
        {
            cout<<"Science Book is lended to "<<n<<endl;;
            cout<<"Time: " << asctime(tt) << endl;
            sci=sci-1;
            cout<<"Enter c to continue and q to quit."<<endl;
        string choice;
        cin>>choice;
        if(choice=="c")
        {
            display2(n,r,his,geo,math,sci);
        }
        else if(choice=="q")
        {
            cout<<"Session has terminated."<<endl;
        }

        else
        {
            display1(n,r,his,geo,math,sci);
        }
        }
        else
        {
            display2(n,r,his,geo,math,sci);
        }
    }
};

int main()
{
    int his,geo,math,sci;
    his=20;
    math=10;
    geo=12;
    sci=24;
    cout<<"Enter Your Name"<<endl;
    std::istream& getline(std::istream&, std::string&, char='\n');
    std::string name;
    std::getline(std::cin, name);
    cout<<"Enter Your Roll No."<<endl;
    int roll;
    cin>>roll;
    Library L;
    L.display2(name,roll,his,geo,math,sci);
}