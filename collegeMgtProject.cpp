#include<iostream>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
#include <windows.h>
#include<fstream>
using namespace std;
void gotoxy(int x, int y)
{

            COORD c;
            c.X = x;
            c.Y = y;

            SetConsoleCursorPosition(
                GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void delay()
{
      for(int k=0;k<=20000000;k++)
      {
          k++;
          k--;
      }
}
class Admin
{
            string aid;
             char password[20];
             fstream f;
     public:
            void add_admin()
            {
                char ch;
                int i=0;
                f.open("Admin.txt",ios::app);
                cout<<"enter admin id: "<<endl;
                cin>>aid;
                cout<<"enter password: "<<endl;
                ch=getch();
                while(ch!= 13)
                {
                    password[i]=ch;
                    i++;
                    cout.put('*');
                    ch=getch();
                }
                 password[i]='\0';
                 f<<aid<<" "<<password<<endl;
                 f.close();
                 cout<<"you are added as a admin successfully."<<endl;
                 cout<<"Please Wait .";
                                    for(int j=1;j<=10;j++)
                                    {
                                        cout<<" . ";
                                        delay();
                                    }
            }
            int PasswordFunction()
            {
                string a;
                char pass[20],ch;
                int i=0,status=0;
                  f.open("Admin.txt",ios::in);
                  cout<<"enter Admin Id For Login: "<<endl;
                  cin>>a;
                  cout<<"enter Password For Login: "<<endl;
                  ch=getch();
                while(ch!= 13)
                {
                    pass[i]=ch;
                    i++;
                    cout.put('*');
                    ch=getch();
                }
                 pass[i]='\0';
                  while(1)
                  {
                      f>>aid>>password;
                      if(f.eof())
                      {
                          break;
                      }
                      int x=strcmp(password,pass);
                      int x2= aid.compare(a);
                      //cout<<"x= "<<x<<endl;
                     // cout<<"x2= "<<x2<<endl;
                      if( !x && !x2)
                      {
                          cout<<"login successfully."<<endl;
                          status=1;
                          return 1;
                      }
                  }
                  f.close();
                  if(status==0)
                  {
                          cout<<"Your Id & Password wrong."<<endl;
                          return 0;
                    }
            }

};
void Admin_Function()
{
    char ch;
    Admin a1;
    do
     {
         system("cls");
         int x;
        cout<<"Check Login Password, press 1."<<endl;
        cout<<"Add Admin, press 2."<<endl;
        cout<<"enter your Choice: "<<endl;
        cin>>x;
        switch(x)
        {
            case 1:a1.PasswordFunction();
                        break;
            case 2:a1.add_admin();
                        break;

            default:cout<<"\ninvalid input."<<endl;
        }
        cout<<"\nDo you want to Go To Admin Menu. If Yes then Press y/Y: "<<endl;
        cin>>ch;
     }while(ch=='y' ||ch=='Y');
}

class College : public Admin
{
    private:
              static string college_name;
              static string college_address;

    public:
          static void update_deatils()
          {
                cout<<"enter College Name: "<<endl;
                cin>>college_name;
                 cout<<"enter College address: "<<endl;
                cin>>college_address;
          }
           void show_college_deatils()
          {
                cout<<"College Name: "<<college_name<<endl;
                cout<<"College address: "<<college_address<<endl;
          }
};
string College:: college_name="GNIOT";
string College:: college_address="Greater Noida";
class Student : public College
{
        private:    int rollno,age,marks[5],total=0;
                         float per;
                         string name;
                         long long mobno;
                         fstream f;
        public: void input_details()
                    {
                        int temprollno,status=0;
                         cout<<"Enter Student Rollno: ";
                        cin>>temprollno;
                         f.open("student.txt",ios::in);
                         while(1)
                        {
                            f>>rollno>>name>>age>>mobno>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>total>>per;
                            if(f.eof())
                            {
                                break;
                            }
                            if(temprollno== rollno)
                            {
                                cout<<temprollno<<" is already exit."<<endl;
                                status=1;
                                break;
                            }
                        }
                        f.close();
                        if(status==0)
                        {
                                f.open("student.txt",ios::app);
                                    rollno=temprollno;
                                    cout<<"Enter Student Name: ";
                                    cin>>name;
                                    cout<<"Enter Student Age: ";
                                    cin>>age;
                                    while(1)
                                    {
                                        long long temp;
                                        int l=0;
                                        cout<<"Enter Student Mobile Number: ";
                                        cin>>mobno;
                                        temp=mobno;
                                        while(temp!=0)
                                        {
                                            temp/=10;
                                            l++;
                                        }
                                        if(l!=10)
                                        {
                                            cout<<"You are entered wrong number.\nPlease input again: "<<endl;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    cout<<"Enter Five Subject Marks: "<<endl;
                                    total=0;
                                    for(int i=0;i<5;i++)
                                    {
                                        cout<<"enter "<<i+1<<". Subject Marks: ";
                                        cin>>marks[i];
                                        total=total+marks[i];
                                    }
                                    per=total/5.0;
                                    f<<rollno<<" "<<name<<" "<<age<<" "<<mobno<<" "<<marks[0]<<" "
                                    <<marks[1]<<" "<<marks[2]<<" "<<marks[3]<<" "<<marks[4]<<" "<<total<<" "<<per<<endl;
                                    f.close();
                                    cout<<name<<" Student Details added Successfully."<<endl;
                                    cout<<"Please Wait .";
                                    for(int j=1;j<=10;j++)
                                    {
                                        cout<<" . ";
                                        delay();
                                    }
                        }

                    }
                    void show_details()
                  {
                      system("cls");
                        f.open("student.txt",ios::in);
                        cout<<"--------------Student All Details--------------------"<<endl;
                        while(1)
                        {
                            f>>rollno>>name>>age>>mobno>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>total>>per;
                            if(f.eof())
                            {
                                break;
                            }
                            cout<<"Rollno: "<<rollno<<endl;
                            cout<<"Name: "<<name<<endl;
                            cout<<"Age: "<<age<<endl;
                            cout<<"Mobno: : "<<mobno<<endl;
                            for(int i=0;i<5;i++)
                            {
                                cout<<"Subject "<<i+1<<" : "<<marks[i]<<endl;
                            }
                             cout<<"Total Marks "<<total<<endl;
                             cout<<"Percentage "<<per<<"%"<<endl;
                            show_college_deatils();
                             cout<<"----------------------------------------------------"<<endl;
                        }
                        f.close();
                  }
                  void update_deatils()
                  {
                       system("cls");
                       fstream f2;
                       f2.open("tempstudent.txt",ios::app);
                        int temprollno,count=0;
                        long long tempmob;
                        cout<<"enter student rollno to update mob no: "<<endl;
                        cin>>temprollno;
                        f.open("student.txt",ios::in);

                        while(1)
                        {
                            f>>rollno>>name>>age>>mobno>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>total>>per;
                            if(f.eof())
                            {
                                break;
                            }
                            if(temprollno==rollno)
                            {
                                 while(1)
                                    {
                                        long long temp;
                                        int l=0;
                                        cout<<"Enter New Mobile Number for Update: "<<endl;
                                       cin>>tempmob;
                                        temp=tempmob;
                                        while(temp!=0)
                                        {
                                            temp/=10;
                                            l++;
                                        }
                                        if(l!=10)
                                        {
                                            cout<<"You are entered wrong number.\nPlease input again: "<<endl;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    mobno=tempmob;
                                    cout<<name<<" student Mobile Number is Updated successfully."<<endl;
                                   count=1;
                            }
                             f2<<rollno<<" "<<name<<" "<<age<<" "<<mobno<<" "<<marks[0]<<" "
                                    <<marks[1]<<" "<<marks[2]<<" "<<marks[3]<<" "<<marks[4]<<" "<<total<<" "<<per<<endl;
                        }
                        if(count==0)
                        {
                            cout<<temprollno<<" is not found."<<endl;
                        }
                        f.close();
                         f2.close();
                         remove("student.txt");
                         rename("tempstudent.txt","student.txt");
                         cout<<"Please wait . ";
                         for(int i=1;i<10;i++)
                         {
                             cout<<" . ";
                             delay();
                         }
                         cout<<endl;
                  }
                  void search_details()
                  {
                            system("cls");
                        int temprollno,count=0;
                        cout<<"enter student rollno to search: "<<endl;
                        cin>>temprollno;
                        f.open("student.txt",ios::in);

                        while(1)
                        {
                            f>>rollno>>name>>age>>mobno>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>total>>per;
                            if(f.eof())
                            {
                                break;
                            }
                            if(temprollno==rollno)
                            {
                                    cout<<"--------------Student Details--------------------"<<endl;
                                    cout<<"Rollno: "<<rollno<<endl;
                                    cout<<"Name: "<<name<<endl;
                                    cout<<"Age: "<<age<<endl;
                                    cout<<"Mobno: : "<<mobno<<endl;
                                    for(int i=0;i<5;i++)
                                    {
                                        cout<<"Subject "<<i+1<<" : "<<marks[i]<<endl;
                                    }
                                     cout<<"Total Marks "<<total<<endl;
                                     cout<<"Percentage "<<per<<"%"<<endl;
                                      show_college_deatils();
                                     cout<<"----------------------------------------------------"<<endl;
                                     count=1;
                            }
                        }
                        if(count==0)
                        {
                            cout<<temprollno<<" is not found."<<endl;
                        }
                        f.close();
                  }
};
void Student_Function()
{
    Student s;
    char ch;
    do
     {
         system("cls");
         int x;
         cout<<"\nAdd New Student , press 1."<<endl;
        cout<<"View All Student, press 2."<<endl;
        cout<<"Search Student, press 3."<<endl;
        cout<<"Update Student Deatils, press 4."<<endl;
        cout<<"enter your Choice: "<<endl;
        cin>>x;
        switch(x)
        {
            case 1:s.input_details();
                        break;
            case 2:s.show_details();
                        break;
            case 3:s.search_details();
                        break;
            case 4:
                        int w;
                        w= s.PasswordFunction();
                        if(w==1)
                        {
                             s.update_deatils();
                        }
                        else{
                            cout<<"you are not a valid person to update information"<<endl;
                         }
                        break;
            default:cout<<"\ninvalid input."<<endl;
        }
        cout<<"\nDo you want to Go To Student Menu. If Yes then Press y/Y: "<<endl;
        cin>>ch;
     }while(ch=='y' ||ch=='Y');
}
class Trainer: public College
{
    private:        int tid,salary;
                         string name;
                         string subject;
                         long long mobno;
                         fstream f;
        public: void input_details()
                    {
                        int tempid,status=0;
                         cout<<"Enter Trainer ID: ";
                        cin>>tempid;
                         f.open("Trainer.txt",ios::in);
                         if(f.fail())
                         {
                             cout<<"you are the first one to add as a trainer ."<<endl;
                         }
                         else
                         {
                                while(1)
                                {
                                    f>>tid>>name>>salary>>mobno>>subject;
                                    if(f.eof())
                                    {
                                        break;
                                    }
                                    if(tempid== tid)
                                    {
                                        cout<<tempid<<" is already exit."<<endl;
                                        status=1;
                                        break;
                                    }
                                }
                                f.close();
                         }

                        if(status==0)
                        {
                                  f.open("Trainer.txt",ios::app);
                                    tid=tempid;
                                    cout<<"Enter Tainer Name: ";
                                    cin>>name;
                                    cout<<"Enter Trainer Salary: ";
                                    cin>>salary;
                                    while(1)
                                    {
                                        long long temp;
                                        int l=0;
                                        cout<<"Enter Trainer Mobile Number: ";
                                        cin>>mobno;
                                        temp=mobno;
                                        while(temp!=0)
                                        {
                                            temp/=10;
                                            l++;
                                        }
                                        if(l!=10)
                                        {
                                            cout<<"You are entered wrong number.\nPlease input again: "<<endl;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    cout<<"Enter Trainer Course: "<<endl;
                                    cin>>subject;

                                    f<<tid<<" "<<name<<" "<<salary<<" "<<mobno<<" "<<subject<<endl;
                                    f.close();
                                    cout<<name<<" Trainer Details added Successfully."<<endl;
                                    cout<<"Please Wait .";
                                    for(int j=1;j<=10;j++)
                                    {
                                        cout<<" . ";
                                        delay();
                                    }
                        }
                    }
                    void show_details()
                  {
                      system("cls");
                        f.open("Trainer.txt",ios::in);
                        show_college_deatils();
                        cout<<"--------------Trainer All Details--------------------"<<endl;
                        while(1)
                        {
                            f>>tid>>name>>salary>>mobno>>subject;
                            if(f.eof())
                            {
                                break;
                            }
                            cout<<"T ID: "<<tid<<endl;
                            cout<<"Name: "<<name<<endl;
                            cout<<"Salary: "<<salary<<endl;
                            cout<<"Mobno: : "<<mobno<<endl;
                             cout<<"Course "<<subject<<endl;
                             cout<<"----------------------------------------------------"<<endl;
                        }
                        f.close();
                  }
                  void update_deatils()
                  {
                       system("cls");
                       fstream f2;
                       f2.open("temptrainer.txt",ios::app);
                        int tempid,count=0;
                        long long tempmob;
                        cout<<"enter Trainer ID to update mob no: "<<endl;
                        cin>>tempid;
                        f.open("Trainer.txt",ios::in);

                        while(1)
                        {
                            f>>tid>>name>>salary>>mobno>>subject;
                            if(f.eof())
                            {
                                break;
                            }
                            if(tempid==tid)
                            {
                                 while(1)
                                    {
                                        long long temp;
                                        int l=0;
                                        cout<<"Enter New Mobile Number for Update: "<<endl;
                                       cin>>tempmob;
                                        temp=tempmob;
                                        while(temp!=0)
                                        {
                                            temp/=10;
                                            l++;
                                        }
                                        if(l!=10)
                                        {
                                            cout<<"You are entered wrong number.\nPlease input again: "<<endl;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    mobno=tempmob;
                                    cout<<name<<" Trainer Mobile Number is Updated successfully."<<endl;
                                   count=1;
                            }
                             f2<<tid<<" "<<name<<" "<<salary<<" "<<mobno<<" "<<subject<<endl;
                        }
                        if(count==0)
                        {
                            cout<<tempid<<" is not found."<<endl;
                        }
                        f.close();
                         f2.close();
                         remove("Trainer.txt");
                         rename("temptrainer.txt","Trainer.txt");
                         cout<<"Please wait . ";
                         for(int i=1;i<10;i++)
                         {
                             cout<<" . ";
                             delay();
                         }
                         cout<<endl;
                  }
                  void search_details()
                  {
                            system("cls");
                        int tempid,count=0;
                        cout<<"enter Trainer ID to search: "<<endl;
                        cin>>tempid;
                        f.open("Trainer.txt",ios::in);

                        while(1)
                        {
                            f>>tid>>name>>salary>>mobno>>subject;
                            if(f.eof())
                            {
                                break;
                            }
                            if(tempid==tid)
                            {
                                    cout<<"--------------Trainer Details--------------------"<<endl;
                                    cout<<"T ID: "<<tid<<endl;
                                    cout<<"Name: "<<name<<endl;
                                    cout<<"Salary: "<<salary<<endl;
                                    cout<<"Mobno: : "<<mobno<<endl;
                                     cout<<"Course "<<subject<<endl;
                                      show_college_deatils();
                                     cout<<"----------------------------------------------------"<<endl;
                                     count=1;
                            }
                        }
                        if(count==0)
                        {
                            cout<<tempid<<" is not found."<<endl;
                        }
                        f.close();
                  }

};
void Trainer_Function()
{
         Trainer t;
    char ch;
    do
     {
         system("cls");
         int x;
         cout<<"\nAdd New Trainer , press 1."<<endl;
        cout<<"View All Trainer, press 2."<<endl;
        cout<<"Search Trainer, press 3."<<endl;
        cout<<"Update Trainer Deatils, press 4."<<endl;
        cout<<"enter your Choice: "<<endl;
        cin>>x;
        switch(x)
        {
            case 1:t.input_details();
                        break;
            case 2:t.show_details();
                        break;
            case 3:t.search_details();
                        break;
            case 4:int w;
                        w= t.PasswordFunction();
                        if(w==1)
                        {
                                t.update_deatils();
                        }
                        else{
                            cout<<"you are not a valid person to update information"<<endl;
                         }
                        break;
            default:cout<<"\ninvalid input."<<endl;
        }
        cout<<"\nDo you want to Go To Trainer Menu. If Yes then Press y/Y: "<<endl;
        cin>>ch;
     }while(ch=='y' ||ch=='Y');
}


void ViewProjectCode()
{
      fstream f;
      char ch;
       f.open("collegeMgtProject.cpp",ios::in);
       if(f.fail())
       {
           cout<<"this file is not found. please check project name."<<endl;
       }
       else
       {
           ch=f.get();
           while(ch != EOF)
           {
               cout.put(ch);
               ch=f.get();
           }
       }
       f.close();
       cout<<"go to main menu. press any key"<<endl;
       cin>>ch;
}
void Exit_Project()
{
      char exit[50]={">>>>>>>>>>>Thank You For Visit<<<<<<<<<<<<"};
       system("cls");
        gotoxy(10,5);
        for(int i=0;exit[i]!='\0';i++)
        {
            cout<<exit[i];
            delay();
        }
}
main()
{
    system("color F1");
    char welcome[50]={">>>>>>>>>>>Welcome to Project<<<<<<<<<<<<"};
        gotoxy(10,5);
        for(int i=0;welcome[i]!='\0';i++)
        {
            cout<<welcome[i];
            delay();
        }
        char ch;
     do
     {
         int x;
         cout<<"\n\t\tFor Student Login, press 1."<<endl;
        cout<<"\t\tFor Trainer Login, press 2."<<endl;
        cout<<"\t\tFor Admin Login, press 3."<<endl;
        cout<<"\t\tFor Project Code View, press 4."<<endl;
        cout<<"\t\tExit From Project, press 5."<<endl;
        cout<<"\t\tenter your choice: "<<endl;
        cin>>x;
        switch(x)
        {
            case 1:Student_Function();
                        break;
            case 2:Trainer_Function();
                        break;
            case 3:Admin_Function();
                        break;
            case 4:ViewProjectCode();
                        break;
            case 5:Exit_Project();
                        exit(0);
                        break;
            default:cout<<"\ninvalid input."<<endl;
        }
        system("cls");
        cout<<"\nDo you want to Go To Main Menu. If Yes then Press y/Y: "<<endl;
        cin>>ch;
     }while(ch=='y' ||ch=='Y');
     Exit_Project();
}
