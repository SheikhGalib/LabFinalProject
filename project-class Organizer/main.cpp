#include <bits/stdc++.h>
using namespace std;
class Routine;
class Student;
void attendenceChcker(Student *stu);
void emptySlot(Routine obj);
class person
{
protected:
    int user_id;
    string name;

public:
    virtual void displayInfo() = 0;
};
class Routine
{
    string arr[5][9];
public:
    string period[9] = {"8.00", "8.50", "9.40", "10.40", "11.30", "12.20", "2.30", "3.20", "4.10"};
    string days[5] = {"Sunday", "Monday", "Tuesday", "Wed", "Thursay"};
    // Routine(){}
    Routine()
    {
        fstream routine("routine.txt", ios::in | ios:: out | ios::app);
        if (routine.is_open())
        {
            for (int i = 0; routine.good(); i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    routine >> arr[i][j]; // reading from file
                }
            }

            routine.close();
        }
        else{
            cout<<"Unable to load routine data to Routine Class\n";
        }
    }
    void routineCheck()
    {
            cout<<"\t\t\tCLASS ROUTINE\n\t";
            for(int k = 0; k < 9; k++) cout<<period[k]<<"\t";
            cout<<endl;

            for (int i = 0; i < 5; i++)
            {
                cout<<days[i]<<"\t";
                for (int j = 0; j < 9; j++)
                {
                    cout<< arr[i][j] << "\t";
                }
                cout<<endl;

            }        
    }
    friend void emptySlot(Routine obj);

};
class Teacher: public person
{
    string cell_no;
public:
    Teacher(){}
    Teacher(int u_i, string n, string cell)
    {
        user_id = u_i;
        name = n;
        cell_no = cell;
    }
    void displayInfo()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Contact Info: "<<cell_no<<endl;
    }
    void giveMessage()
    {
        string s;
        cout<<"Enter Message: ";
        // cin>>s;
        getline(cin, s);
        getline(cin, s);
        cout<<"Options\n 1. Send to All Students\n 2. Send to Specific Student\n";
        int n;
        cout<<"Chose Option: ";
        cin>>n;
        if (n == 1)
        {
            // Send to all
            // To Do.
            fstream message("messageToAll.txt", ios::in | ios:: out | ios:: app);
            message << s << endl;
            message.close();
        }
        else if (n == 2)
        {
            cout<<"Enter Student Roll: ";
            int roll;
            cin>>roll;
            fstream specificMessage ("messageSpecificTo.txt", ios::in | ios:: out | ios:: app);
            specificMessage << roll <<" "<< s <<endl;
            specificMessage.close();
        }
        else{
            cout<<"Invalid Option\n";
        }
    }
    void giveMessage(string messageCT, string d, string t, string to)
    {
            fstream message("messageToAll.txt", ios::in | ios:: out | ios:: app);
            message << messageCT << endl;
            message << d << " "<< t << " " << to <<endl;
            message.close();

    }
    void scheduleSet()
    {
        string s;
        cout<<"Options: ";
        cout<<"1. Set New Schedule \n 2. check previous Schdule\n";
        int n;
        cout<<"Chose Option: ";
        cin>>n;
        if (n == 1)
        {
            // Open schedule.txt and edit.
            fstream schedule ("schedule.txt", ios::in | ios:: out | ios:: app);
            schedule <<name<<" Sir Set the Schedule\n";
            cout<<"Enter Date: ";
            cin>>s;
            schedule <<"Date: "<< s << endl; // Writing to file
            cout<<"Enter Time: ";
            cin>>s;
            schedule <<"Time: "<< s <<endl;
            cout<<"Enter Topic: ";
            // cin>>s;
            getline(cin,s);
            getline(cin,s);
            schedule <<"Topic: "<< s <<endl;
            schedule.close();

        }
        else if (n == 2)
        {
            // Open schedule.txt and read
            fstream schedule ("schedule.txt", ios::in | ios:: out | ios:: app);
            while(schedule.good())
            {
                getline(schedule, s);
                cout<<s<<endl;
            }
            // cout<<"Date: ";
            // schedule >> s; // Reading from file
            // cout<<"\nTime: ";
            // schedule >> s;
            // cout<<"\nTopic: ";
            // schedule >> s;
            // cout<<endl;
            schedule.close();
        }
        else{
            cout<<"Invalid option\n";
        }
    }
    void scheduleSet(string date, string time, string topic)
    {
            // Open schedule.txt and edit.
            fstream schedule ("schedule.txt", ios::in | ios:: out | ios:: app);

            schedule <<"Date: "<< date << endl; // Writing to file

            schedule <<"Time: "<< time <<endl;

            schedule <<"Topic: "<< topic <<endl;
            schedule.close();
    }
    void setId(int id)
    {
        user_id = id;
    }
    void setName(string n)
    {
        name = n;
    }
    void setCellNo(string c)
    {
        cell_no = c;
    }
    int getId()
    {
        return user_id;
    }
    friend void emptySlot(Routine obj);

    void CT_fix(Routine object)
    {
        // find empty slot
        emptySlot(object);
        // Fix CT
        cout<<"Set time for CT\n (press 1, 2, 3 ... 9 as preiod) and (1, 2, 3,..5 as day)\n";
        int p,d;
        cout<<"Period: ";
        cin>>p;
        cout<<"Day: ";
        cin>>d;
        string topic,date;
        cout<<"Enter topic: ";
        cin>>topic;
        cout<<"Enter Date: ";
        cin>>date;
        //-----AUTO-----
        // schedule set function overload
        scheduleSet(date, object.period[p-1], topic);
        // Give message to All Students , function overload
        giveMessage("CT Fixed", date, object.period[p-1], topic);
    }

};

class Student:public person
{
    //user_id = roll;
    //name;
    int attendencePercentage;
public:
    Student(){}
    Student(int roll, string n)
    {
        user_id = roll;
        name = n;
    }
    void displayInfo()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Roll: "<<user_id<<endl;
    }
    void setRoll(int roll)
    {
        user_id = roll;
    }
    void setName(string n)
    {
        name = n;
    }
    void setAttendence(int a)
    {
        attendencePercentage = a;
    }
    int getRoll()
    {
        return user_id;
    }
    string getName()
    {
        return name;
    }
    // Student set info, overload operator new student add
    friend istream &operator >> (istream& input, Student &obj)
    {
        cout<<"Enter Student Name: ";
        input>>obj.name;
        cout<<"Roll: ";
        input>>obj.user_id;

        return input;
        
    }
    friend void attendenceChcker(Student *stu);
    
};

void attendenceChcker(Student *stu)
{
    int total_weeks = 13;
    int remaining_weeks, per_week_class, done_class, minimum_required, is_possible;

    cout<<"Enter Remaining Weeks: ";
    cin>>remaining_weeks;
    cout<<"Enter per week class of the course: ";
    cin>>per_week_class;
    cout<<"Enter how many class already completed: ";
    cin>>done_class;
    stu->attendencePercentage = round((done_class/((total_weeks - remaining_weeks) * per_week_class * 1.0F)) * 100);
    cout<<"Your Attendence Percentage: "<<round((done_class/((total_weeks - remaining_weeks) * per_week_class * 1.0F)) * 100)<<endl;
    if (stu->attendencePercentage < 60)
    {
        // Suggestion
        cout<<"You are lagging behind\n";
        minimum_required = (total_weeks*per_week_class*0.6 - done_class);
        is_possible = remaining_weeks*per_week_class - minimum_required;
        if (is_possible >= 0)
        {
            cout<<"It is possible to recover\n You need to do minimum "<<minimum_required<<" Class to get 60 Percent Attendence"<<endl;
        }
        else{
            cout<<"You Have INCOMPLETE!\n";
        }
    }

}
void emptySlot(Routine obj)
{
            cout<<"\t\t\tCLASS ROUTINE\n\t";
            for(int k = 0; k < 9; k++) cout<<obj.period[k]<<"\t";
            cout<<endl;

            for (int i = 0; i < 5; i++)
            {
                cout<<obj.days[i]<<"\t   ";
                for (int j = 0; j < 9; j++)
                {
                    if (obj.arr[i][j] == "Nil")
                        cout<< obj.arr[i][j] << "\t";
                    else
                        cout<<"\t";
                }
                cout<<endl;

            }   
}
int main()
{
    Student student[10];
    fstream stu_file("StudentInfo.txt", ios::in | ios:: out | ios:: app);

    for (int i = 0; i < 10; i++)
    {
        int roll, attendence;
        string name;
        stu_file >> roll; student[i].setRoll(roll);
        stu_file >> name; student[i].setName(name);
        stu_file >> attendence; student[i].setAttendence(attendence);
    }
    stu_file.close();

    // Set Teacher Info from file
    Teacher teacher[2];
    fstream teach_file("TeacherInfo.txt", ios::in | ios:: out | ios:: app);
    for (int i = 0; i < 2; i++)
    {
        int id;
        string name, number;
        teach_file >> id;
        getline(teach_file, name);
        teacher[i].setId(id);
        // teach_file >> name;
        getline(teach_file, name);
        teacher[i].setName(name);
        // teach_file >> number;
        getline(teach_file, number);
        teacher[i].setCellNo(number);
    }

    // Create Routine Object.
    Routine routine;
    //routine.routineCheck();
    //emptySlot(routine);
    // Create Options
    A: 
    cout<<"Enter User\n";
    cout<<"1. Teacher \t 2. Student 3. Quit\n";
    int x;
    cin>>x;
    if (x == 1) // For Teacher
    {
        cout<<"Enter User Id: ";
        int ii;
        cin>>ii;
        bool user_check;
        for (int i = 0; i < 2; i++)
        {
            if (teacher[i].getId() == ii)
            {
                cout<<"User Found\n";
                ii = i;
                user_check = true;
                teacher[i].displayInfo();
                break;
            }
        }
        if (user_check)
        {
            cout<<"Select Option\n";

            cout<<" 1.Set Schedule \n 2. CT Fix \n 3. Give message \n 4. Go Back\n";
            int xx;
            cin>>xx;
            if (xx == 1)
            {
                teacher[ii].scheduleSet();
            }
            if (xx == 2)
            {
                teacher[ii].CT_fix(routine);
            }
            if (xx == 3)
            {
                teacher[ii].giveMessage();
            }
            if (xx = 4)
            {
                goto A; // Going Back to User;
            }

        }
        else{
            cout<<"User Not found\n";
        }
    }
    if (x == 2)
    {
        cout<<"Enter Your Roll: ";
        int roll;
        cin>>roll;
        bool user_check;
        for (int i = 0; i < 10; i++)
        {
            if (student[i].getRoll() == roll)
            {
                cout<<"User Found\n";
                roll = i;
                user_check = true;
                student[roll].displayInfo();
                break;
            }
        }
        if (user_check)
        {
            cout<<"Chose Options\n";
            cout<<"1. Routine Check \n 2. Schedule Check \n 3.Message Check \n 4. Individual Message Check \n 5. Attendece Check \n 6. Go Back\n";
            int xx;
            cin>>xx;
            if (xx == 1)
            {
                routine.routineCheck();
            }
            if (xx == 2)
            {
                fstream schedule ("schedule.txt", ios::in | ios:: out | ios:: app);
                string ss;
                while(schedule.good())
                {
                    getline(schedule, ss);
                    cout<<ss<<endl;
                }
                schedule.close();
            }
            if (xx == 3)
            {
                fstream message ("messageToAll.txt", ios::in | ios:: out | ios:: app);
                string ss;
                while(message.good())
                {
                    getline(message, ss);
                    cout<<ss<<endl;
                }
                message.close();
            }
            if (xx == 4)
            {
                fstream specificMessage ("messageSpecificTo.txt", ios::in | ios:: out | ios:: app);
                string ss;
                while(specificMessage.good())
                {
                    getline(specificMessage, ss);
                    cout<<ss<<endl;
                }
                specificMessage.close();
            }
            if (xx == 5)
            {
                attendenceChcker(&student[roll]);
            }
            if (xx = 6)
            {
                goto A;
            }
        }
        else{
            cout<<"You are not a Student, Do you want to Apply (y/n)\n";
            char c;
            cin>>c;
            if (c == 'y')
            {
                Student s_new;
                cin>> s_new;
                cout<<s_new.getName()<<" "<<s_new.getRoll()<<" Added Succesfully to StudentInfo"<<endl;
                fstream student ("StudentInfo.txt", ios:: in | ios:: out | ios:: app);
                
                student << s_new.getRoll() <<" "<<s_new.getName()<<endl;
                student.close();
            }
            else 
            {
                goto A;
            }
        }
    }
    if (x == 3)
    {
        cout<<"Program Terminated\n";
    }
}