//To Login in admin panel or faculty panel please enter the credentials as follows:
//Username:admin 
//and
//Password:admin@1

# include <iostream>
# include <stdio.h>
# include <ctime>
#include <cstring>
# include <fstream>
using namespace std;

class Student
{
    public:
    fstream f;
    fstream f1;
    string username,password;
    void loginStudent()
    {
        f.open("username.txt");
        cout<<"Username :   ";
        cin>>username;
        cout<<"Password :   ";
        cin>>password;
        if(f.is_open())
        {
            while(f.good())
            {
                std::string user;
                f>>user;
                if(username==user)
                {
                    checkPassword(password);
                }
            }
        }
    }
    void checkPassword(string pass)
    {
        f1.open("password.txt");
        std::string passw=pass;
        if(f1.is_open())
        {
            while (f1.good())
            {
                std::string passwa;
                f1>>passwa;
                if(passw==passwa)
                {
                    studentDisplay();
                }
            }
            
        }
    }
    void studentDisplay()
    {
        cout<<"Your Attendance is : "<<endl;
    }
};

class Teacher
{
    
    public:
    fstream f;
    fstream f1;
    fstream f2;
    std::istream& getline(std::istream&, std::string&, char='\n');
    string admin_username,admin_password;
    std::string student_first_name,student_last_name,student_username,student_password,roll,father_name,mother_name;
    void display()
    {
    Student s;
    cout<<"Enter '1' To Login to Student Panel"<<endl;
    cout<<"Enter '2' To Login to Faculty/Admin Panel"<<endl;
    cout<<"Enter '0' To Exit The System"<<endl;
    int choice;
    cout<<"Enter Your Choice"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        s.loginStudent();
        break;
    
    case 2:
        loginAdmin();
        break;
    case 0:
        cout<<"Session has been Terminated"<<endl;
        break;
    default :
        display();
    }
    }
    void loginAdmin()
    {   
        cout<<"Admin Login :    "<<endl;
        cout<<endl;
        cout<<"Username :   ";
        cin>>admin_username;
        cout<<"Password :   ";
        cin>>admin_password;
        
        if(admin_username=="admin"&&admin_password=="admin@1")
        {
            teacherDisplay();
        }
        else
        {
            cout<<"Invalid Credentials"<<endl;
            cout<<"Enter 'c' to Continue to admin login or 'b' to go back or 'q' to terminate the session"<<endl;
            string choice;
            cin>>choice;
            if(choice=="c")
            {
                cout<<"Please Enter Valid Credentials"<<endl;
                loginAdmin();
            }
            else if(choice=="b")
            {
                display();
            }
            else
            {
                cout<<"Session has been terminated"<<endl;
            }
            

        }
    }

    void teacherDisplay()
    {
            cout<<"Enter '1' to register student"<<endl;
            cout<<"Enter '2' to view students in the class"<<endl;
            cout<<"Enter '3' to delete student by their roll number"<<endl;
            cout<<"Enter '4' to view the attendance of all students"<<endl;
            cout<<"Enter '5' to go back"<<endl;
            cout<<"Enter Your Choice :  "<<endl;
            int choice;
            cin>>choice;
            switch (choice)
            {
            case 1:
                registerStudent();
                break;
            
            case 2:
                viewStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                attendance();
            break;
            case 5:
                display();
            default:
                break;
            }
    }

    void registerStudent()
    {
        f.open("data.txt",ios::app);
        f1.open("username.txt",ios::app);
        f2.open("password.txt",ios::app);
        cout<<"Registration of Student in the Class[Please Do Not Give Space Between Any of the Inputs]"<<endl;
        cout<<"First Name :   ";  cin>>student_first_name;
        cout<<"Last Name :  ";    cin>>student_last_name;
        cout<<"Username[No Spaces] :   ";cin>>student_username;
        cout<<"Password[No Spaces] :   ";cin>>student_password;
        cout<<"Roll Number[No Spaces] : ";cin>>roll;
        cout<<"Father's Name[Only First Name] :  ";cin>>father_name;
        cout<<"Mother's Name[Only First Name] :  ";cin>>mother_name;
        if(f.is_open())
        {
            f<<student_first_name<<student_last_name<<endl;
            f.close();
        }
        if(f1.is_open())
        {
            f1<<student_username<<endl;
            f1.close();
        }
        if(f2.is_open())
        {
            f2<<student_password<<endl;
            f2.close();
        }
        teacherDisplay();
    }

    void viewStudent()
    {
        cout<<"The Students in the class are : "<<endl;
        f.open("data.txt");
        if(f.is_open())
        {
            // cout<<"I am open";
            while (f.good())
            {
            std::string name;
            f>>name;
            cout<<name<<endl;
            }
        }
        f.close();
        teacherDisplay();
    }

    void deleteStudent()
    {
        cout<<"To remove the Student from the class"<<endl;
        cout<<"Please Enter their Roll Number:"<<endl;
        cout<<"Roll No. :   ";
        teacherDisplay();
    }

    void attendance()
    {
        cout<<"The Attendance of Students is as Follows:"<<endl;
        teacherDisplay();
    }

    void EditAttendance()
    {
        
    }
};


int main()
{
    Teacher t;
    t.display();
    return 0;
}