#include<iostream>
#include<list>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Employee
{
    public:
    int emp_id;
    string emp_name;
    int dob;
    int salary;
    
    void add_employee()
    {
        cout<<"Enter employee id:"<<endl;
        cin>>emp_id;
        cout<<"Enter employee name:"<<endl;
        cin>>emp_name;
        cout<<"Enter employee dob:"<<endl;
        cin>>dob;
        cout<<"Enter employee salary:"<<endl;
        cin>>salary;
    }
    int display_employee()
    {
        cout<<"Employee id:"<<emp_id<<endl;
        cout<<"Employee name:"<<emp_name<<endl;
        cout<<"Employee dob:"<<dob<<endl;
        cout<<"Employee salary:"<<salary<<endl;
        return 0;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Team
{
    public:
    int team_id;
    string team_name;
    int number_of_members=0;
    //Employee *team_emp_details[100];
    list<Employee> team_emp_details;
    void add_team()
    {
        cout<<"Enter Team id:"<<endl;
        cin>>team_id;
        cout<<"Enter team name"<<endl;
        cin>>team_name;
    }
    void display_team()
    {
        cout<<"Team id:"<<team_id<<endl;
        cout<<"Team name"<<team_name<<endl;
        cout<<"Total members in team:"<<number_of_members<<endl;
        if(number_of_members>0)
        {
            //for(int i=0;i<number_of_members;i++)
        list<Employee>::iterator iter;/////////////////////////////////////////////////<<<<----------------------
        for(iter=team_emp_details.begin();iter!=team_emp_details.end();iter++)
    {
            {
            cout<<"Displaying Employees of Team"<<endl;
            cout<<iter->display_employee()<<endl; 
            }                 //Problem Solved Here by changing the return type from "VOID" to "INT"
        }
     }                      ///////////DISPLAYING EMPLOYEES OF TEAM
}
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
list<Employee> emp;
list<Team> team;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_employee()
    {
    Employee t_emp;
    t_emp.add_employee();
    emp.push_back(t_emp);
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int display_employee()
    {
        for (Employee i : emp)
        {
            i.display_employee();
        }
    return 0;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int manage_team_menu()
{
    int manage_choice;
    cout<<"***************************************************************************************"<<endl;
    cout<<"MANAGE TEAMS MENU"<<endl;
    cout<<"1.Add Teams\n2.Add employee to team\n3.Display Team\n4.Delete team by ID\n5.Remove Employee from Team"<<endl;
    cout<<"6.Update Team Name"<<endl;
    cin>>manage_choice;
    cout<<"***************************************************************************************"<<endl;
    return manage_choice;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int add_team()
{
    Team t_team;
    t_team.add_team();
    team.push_back(t_team);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int add_employee_to_given_team()
{
    int search_team_id;
    int search_emp_id;
    cout<<"Enter Desired Team ID in which you want to add employee:"<<endl;
    cin>>search_team_id;
    list<Team>::iterator iterT;
    for(iterT=team.begin();iterT!=team.end();iterT++)
    {
        if(iterT->team_id==search_team_id)
        {
            cout<<"Displaying the Team details for ID:"<<search_team_id;
            iterT->display_team();
            cout<<"Enter Employee ID for adding into Team:"<<iterT->team_name<<endl;
            cin>>search_emp_id;
            list<Employee>::iterator iterE;
            for(iterE=emp.begin();iterE!=emp.end();iterE++)
            {         
                if(iterE->emp_id==search_emp_id)
                {
                    cout<<"Displaying the Employee details for ID:"<<search_emp_id;
                    iterE->display_employee();
                    Employee E1;
                    E1.emp_id=iterE->emp_id;
                    E1.emp_name=iterE->emp_name;
                    E1.dob=iterE->dob;
                    E1.salary=iterE->salary;
                    iterT->team_emp_details.push_back(E1);
                    iterT->number_of_members++;
                    return 0;
                }
            }
            cout<<"You GARBAGE GUY!!\nGiven Employee ID is not in database!!!"<<endl;
            return 0;
        }

    }
    cout<<"You GARBAGE GUY!!\nGiven Team ID is not in database!!!"<<endl;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int display_team()
{
        for (Team i : team)
        {
            i.display_team();
        }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int delete_team_by_id()
{
    list<Team>::iterator iter;
    int search_id=0;
    cout<<"Enter Team ID to delete"<<endl;
    cin>>search_id;
    for(iter=team.begin();iter!=team.end();iter++)
    {
        if(search_id==iter->team_id)
        {
        team.erase(iter);
        cout<<"Deleted Team with Details with ID:"<<search_id<<endl;
        return 0;
        }    
    }
    cout<<"YOU GARBAGE GUY\nYou entered wrong ID"<<endl;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int remove_employee_from_team()
{
    int search_team_id;
    int search_emp_id;
    list<Team>::iterator iterT;
    cout<<"Enter Team ID from which you wish to remove Employee"<<endl;
    cin>>search_team_id;
    for(iterT=team.begin();iterT!=team.end();iterT++)
    {
        if(search_team_id==iterT->team_id)
        {
            cout<<"Enter Employee ID from which you wish to remove"<<endl;
            cin>>search_emp_id;
            list<Employee>::iterator iterE;
            for(iterE=iterT->team_emp_details.begin();iterE!=iterT->team_emp_details.end();iterE++)
            {
                if(search_emp_id==iterE->emp_id)
                {
                    iterE->display_employee(); ////////////ERROR LOGIC NEEDED TO REMOVE EMPLOYEE FROM TEAM
                    iterT->team_emp_details.erase(iterE);
                    cout<<"Deleted Employee Details with ID:"<<search_emp_id<<endl;
                    iterT->number_of_members--;
                    return 0;
                    //list<Employee> team_emp_details;
                }    
            }
        }
            cout<<"YOU GARBAGE GUY\nYou entered wrong Employee ID"<<endl;
            return 0;
        }  
            cout<<"YOU GARBAGE GUY\nYou entered wrong Team ID"<<endl;
            return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int update_team_name()
{
    list<Team>::iterator iter;
    int search_id=0;
    cout<<"Enter Team ID to Update Name"<<endl;
    cin>>search_id;
    for(iter=team.begin();iter!=team.end();iter++)
    {
        if(search_id==iter->team_id)
        {
            string new_team_name;
            cout<<"Enter New Team Name:"<<endl;
            cin>>new_team_name;
            iter->team_name=new_team_name;
            cout<<"Updating Team Nmae with Details with ID:"<<search_id<<endl;
            return 0;
        }    
    }
    cout<<"YOU GARBAGE GUY\nYou entered wrong ID"<<endl;
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void manage_teams()
{
    int manage_choice;
    manage_choice=manage_team_menu();
    switch (manage_choice)
          {
    case 1: add_team();
            break;
    case 2: add_employee_to_given_team();
            break;
    case 3: display_team();
            break;
    case 4: delete_team_by_id();
            break;
    case 5: remove_employee_from_team();
            break;
    case 6: update_team_name();
            break;
    default:
            cout<<"You GARBAGE GUY!!\nWrong Input\n Try Again!!"<<endl;
}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int search_employee_by_id()
{
    int search_id;
    cout<<"Enter Employee ID for search:"<<endl;
    cin>>search_id;
    list<Employee>::iterator iter;
    for(iter=emp.begin();iter!=emp.end();iter++)
    {
        if(search_id==iter->emp_id)
        {
            iter->display_employee();
            return 0;
        }
    }
    cout<<"Given Employee ID is not in database!!!"<<endl;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int search_employee_by_name()
{
    string search_name;
    cout<<"Enter Employee Name for search:"<<endl;
    cin>>search_name;
    list<Employee>::iterator iter;
    for(iter=emp.begin();iter!=emp.end();iter++)
    {
        if(search_name==iter->emp_name)
        {
            iter->display_employee();
            return 0;
        }
    }
    cout<<"Given Employee Name is not in database!!!"<<endl;
    return 0;   
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int search_employee_by_sal()
{
      int search_sal;
    cout<<"Enter Salary for Employee search:"<<endl;
    cin>>search_sal;
    list<Employee>::iterator iter;
    for(iter=emp.begin();iter!=emp.end();iter++)
    {
        if(search_sal==iter->salary)
        {
            iter->display_employee();
            return 0;
        }
    }
    cout<<"No Employee is matched with given Salary in database!!!"<<endl;
    return 0;    
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int update_emp_by_name()
{
    list<Employee>::iterator iter;
    int search_id;
    string emp_updated_name;
    cout<<"Enter The Employee Id for you wish to Update NAME"<<endl;
    cin>>search_id;
    cout<<"Enter the Updated Name"<<endl;
    cin>>emp_updated_name;
    for(iter=emp.begin();iter!=emp.end();iter++)
    {
        if(search_id==iter->emp_id)
        {
            iter->emp_name=emp_updated_name;
            cout<<"Updated Employee Details with ID:"<<search_id<<endl;
            return 0;
        }    
            
    }
    cout<<"YOU GARBAGE GUY\nYou entered wrong ID"<<endl;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int update_emp_by_sal()
{
    list<Employee>::iterator iter;
    int search_id;
    int emp_updated_salary;
    cout<<"Enter The Employee Id for you wish to Update SALARY"<<endl;
    cin>>search_id;
    cout<<"Enter the Updated Salary"<<endl;
    cin>>emp_updated_salary;
    for(iter=emp.begin();iter!=emp.end();iter++)
    {
        if(search_id==iter->emp_id)
        {
            iter->salary=emp_updated_salary;
            cout<<"Updated Salary of Employee with ID:"<<search_id<<endl;
            return 0;
        }    
    }
    cout<<"YOU GARBAGE GUY\nYou entered wrong ID"<<endl;
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int update_employee()
{
    int choice=0;
    cout<<"1.Update Name\n2.Update Salary"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 1: update_emp_by_name();
                break;
        case 2: update_emp_by_sal();
                break;
        default: cout<<"YOU GARBAGE GUY\nWRONG CHOICE"<<endl;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int delete_employee()
{
    list<Employee>::iterator iter;
    int search_id=0;
    cout<<"Enter Emplloyee id to delete"<<endl;
    cin>>search_id;
    for(iter=emp.begin();iter!=emp.end();iter++)
    {
        if(search_id==iter->emp_id)
        {
        emp.erase(iter);
        cout<<"Deleted Employee Details with ID:"<<search_id<<endl;
        return 0;
        }    
    }
    cout<<"YOU GARBAGE GUY\nYou entered wrong ID"<<endl;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main_menu()
{
    int choice;
    cout<<"***************************************************************************************"<<endl;
    cout<<"MAIN MENU"<<endl;
    cout<<"1.Add Employee\n2.Display Employee\n3.Search Employee by id\n4.Search Employee by Name\n5.Search Employee by Salary\n6.Update Employee"<<endl;
    cout<<"7.Delete employee()\n8.Manage Teams"<<endl;
    cin>>choice;
    cout<<"***************************************************************************************"<<endl;
    return choice;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int choice;
    Employee emp[100];
    Team team[10];
    while(1)
    {
    choice=main_menu();
        switch (choice)
        {
            case 1: add_employee();
                    break;
            case 2: display_employee();
                    break;
            case 3: search_employee_by_id();
                    break;
            case 4: search_employee_by_name();
                    break;
            case 5: search_employee_by_sal();
                    break;
            case 6: update_employee();
                    break;
            case 7: delete_employee();
                    break;
            case 8: manage_teams();
                    break;
            default:
            cout<<"You GARBAGE GUY!!\nWrong Input\n Try Again!!"<<endl;
        }
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
