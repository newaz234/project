#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class User
{
    string name;
    string number;
    string id;
    int password;
    int account_balance=0;
public:
    User(string name,string number,string id,int password)
    {
        this->name=name;
        this->number=number;
        this->id=id;
        this->password=password;
    }
     int check_number(string number)
    {
        if(this->number==number)
            return 1;
        else
            return 0;
    }
   cash_in(int amount)
   {
       account_balance+=amount;
   }
   cashout(int amount)
   {
       if(amount<=account_balance)
        account_balance-=amount;
       else{
        cout<<"you don't have sufficient balance"<<endl;
       }
   }
   send_money(int amount)
   {
       if(amount<=account_balance)
        account_balance-=amount;
       else{
        cout<<"you don't have sufficient balance"<<endl;
       }
   }
   friend class Employeemanager;
};
class Agent
{
  string name;
    string number;
    string id;
    int password;
    int account_balance;
public:
    friend class Employeemanager;
    Agent(string name,string number,string id,int password,int account_balance)
    {
        this->name=name;
        this->number=number;
        this->id=id;
        this->password=password;
        this->account_balance=account_balance;
    }
    int check_number(string number)
    {
        if(this->number==number)
            return 1;
        else
            return 0;
    }
    cash_in(int amount)
   {
       account_balance+=amount;
   }
   cashout(int amount)
   {
       if(amount<=account_balance){
        account_balance-=amount;
       }
       else{
        cout<<"you don't have sufficient balance"<<endl;

       }
   }
   send_money(int amount)
   {
       if(amount<=account_balance)
        account_balance-=amount;
       else
       {
        cout<<"you don't have sufficient balance"<<endl;

       }
   }

};
class Employeemanager
{
    vector<User> user;
    vector<Agent> agent;
public:
    show_balance()
    {
        int key,flag=0;
        string number;
        cout<<"1.user balance"<<endl;
        cout<<"2.agent balance "<<endl;
        cout<<"please enter a key : ";
        cin>>key;
        cout<<"enter account number : ";
        cin>>number;
        if(key==2){
        for(int i=0;i<agent.size();i++)
      {
          if(agent[i].number==number)
            {
                cout<<"your account balance is "<<agent[i].account_balance<<endl;
                flag=1;
                break;
            }
      }
      if(flag==0)
      cout<<"no register account with this number"<<endl;
        }
        else if(key==1)
        {
            for(int i=0;i<user.size();i++)
      {
          if(user[i].number==number)
            {
                cout<<"your account balance is "<<user[i].account_balance<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"no register account with this number"<<endl;
        }
        }
    }
    add_new_agent_or_user()
  {
      int key;
      cout<<"1.add user"<<endl;
      cout<<"2.add agent"<<endl;
      cout<<"0.exit"<<endl;
      cout<<"enter a key : ";
      cin>>key;
       system("cls");
      if(key==0)
        return 0;
    string name;
    string number;
    string id;
    int password,deposit;
    cout<<"number : ";
    cin>>number;
    getchar();
    cout<<"name : ";
    getline(cin,name);
    cout<<"id : ";
    cin>>id;
    cout<<"password : ";
    cin>>password;

    if(key==2){
            cout<<"deposit : ";
    cin>>deposit;
    Agent *p=new Agent(name,number,id,password,deposit);
    agent.push_back(*p);
    delete p;
    }
    else if(key==1)
    {
       User *p=new User(name,number,id,password);
       user.push_back(*p);
       delete p;
    }
  }


  remove_user_or_agent(){
      int key;
      cout<<"1. Remove user"<<endl;
      cout<<"2.Remove agent"<<endl;
      cout<<"enter a key : ";
      cin>>key;
       system("cls");
      string number;
      cout<<"enter number : ";
      cin>>number;
      int flag=0;
      if(key==1){
      for(int i=0;i<user.size();i++)
          if(user[i].check_number(number))
          {
              cout<<user[i].number<<" remove successfully "<<endl;
              user.erase(user.begin()+i);
              flag=1;

              break;
          }
      }
      else if(key==2)
      {
          for(int i=0;i<agent.size();i++)
          if(agent[i].check_number(number))
          {
               cout<<agent[i].number<<" remove successfully "<<endl;
              agent.erase(agent.begin()+i);
              flag=1;
              break;
          }
      }
      if(flag==0)
          cout<<"there is no registered account with this number"<<endl;
  }
  transfer_money()
  {
      int key,amount,i=0,j=0;
      string sender_number,receiver_number;
      cout<<"1.agent to agent"<<endl;
      cout<<"2.agent to user "<<endl;
      cout<<"3.user to agent "<<endl;
      cout<<"4.user to user "<<endl;
      cout<<"enter a key : ";
       system("cls");
      cin>>key;
      cout<<"sender number :";
      cin>>sender_number;
      cout<<"reciever number :";
      cin>>receiver_number;
      switch(key)
      {
          case 1:
             i=agent_info(sender_number);
             if(i==-1)
                break;
             j=agent_info(receiver_number);
             if(j==-1)
                break;
                cout<<"enter amount : ";
                cin>>amount;
                agent[i].cashout(amount);
             if(agent[i].account_balance>=amount)
             {
                 agent[j].cash_in(amount);
                 cout<<"successfully "<<amount<<" tk transfered from "<<sender_number<<" to "<<receiver_number<<endl;
             }
             break;
          case 2:
            i=agent_info(sender_number);
             if(i==-1)
                break;
             j=user_info(receiver_number);
             if(j==-1)
                break;
                cout<<"enter amount : ";
                cin>>amount;
                agent[i].cashout(amount);
             if(agent[i].account_balance>=amount)
             {
                 user[j].cash_in(amount);
                 cout<<"successfully "<<amount<<" tk transfered from "<<sender_number<<" to "<<receiver_number<<endl;
             }
             break;
          case 3:
            i=user_info(sender_number);
             if(i==-1)
                break;
             j=agent_info(receiver_number);
             if(j==-1)
                break;
                cout<<"enter amount : ";
                cin>>amount;
                user[i].cashout(amount);
             if(user[i].account_balance>=amount)
             {
                 agent[j].cash_in(amount);
                 cout<<"successfully "<<amount<<" tk transfered from "<<sender_number<<" to "<<receiver_number<<endl;
             }
             break;
          case 4:
            i=user_info(sender_number);
             if(i==-1)
                break;
             j=user_info(receiver_number);
             if(j==-1)
                break;
                cout<<"enter amount  : ";
                cin>>amount;
                user[i].send_money(amount);
             if(user[i].account_balance>=amount)
             {
                 user[j].cash_in(amount);
                 cout<<"successfully "<<amount<<" tk transfered from "<<sender_number<<" to "<<receiver_number<<endl;
             }
             break;
          default :
            cout<<"wrong keyword"<<endl;

      }

  }
  int agent_info(string number)
  {
      for(int i=0;i<agent.size();i++)
      {
          if(agent[i].check_number(number))
            return i;
      }
      cout<<number<<"is not registered in our system"<<endl;
      return -1;
  }
  int user_info(string number)
  {
      for(int i=0;i<user.size();i++)
      {
          if(user[i].check_number(number))
            return i;
      }
      cout<<number<<" is not registered in our system"<<endl;
      return -1;
  }

};


int main()
{
    cout<<"welcome to online mobile banking management system"<<endl;
    Employeemanager em;
    int t=1;
    while(t){
    cout<<"1.add member"<<endl;
    cout<<"2.money transfer"<<endl;
    cout<<"3.show balance"<<endl;
    cout<<"4.remove member"<<endl;
    cout<<"0.exit"<<endl;
    cout<<"Please enter a key : ";
    cin>>t;
    system("cls");
   switch(t)
   {
       case 1:
 em.add_new_agent_or_user();
 break;
 case 4:
 em.remove_user_or_agent();
 break;
 case 2:
 em.transfer_money();
 break;
 case 3:
 em.show_balance();
 break;
 case 0:
    cout<<"thank you"<<endl;
    break;
    default:
    cout<<"wrong keyword"<<endl;
    }
    system("pause");
    system("cls");
    }

    return 0;
}
