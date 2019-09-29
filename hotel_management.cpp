#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

char ID [14];
char first_name [15];
char last_name [15];
char country_name [20];
char number [15];
char duration [4];

void insert ()
{
    int x ;
    while(x=1)
    {
        cout<< "ENTER THE FIRST NAME: \n " ;
        cin>> first_name;
        cout<< "ENTER THE LAST NAME: \n " ;
        cin>> last_name;
        cout<< "ENTER YOUR ID: \n " ;
        cin>> ID;
        cout<< "ENTER YOUR COUNTRY NAME: \n " ;
        cin>> country_name ;
        cout<< "ENTER YOUR PHONE NUMBER: \n " ;
        cin>> number;
        cout<< "ENTER THE DURATION OF STAY: \n " ;
        cin>> duration;

        fstream f ;
        f.open("hotel.txt",ios::out|ios::app);
        f<< ID <<"|"<< first_name <<"|"<< last_name <<"|"<< country_name <<"|"<< number <<"|"<< duration <<"\n" ;
        cout<< "If YOU WANT TO INSERT ANOTHER RECORD PRESS 1\nIF NOT PRESS 2\n";
        cin>> x ;

        if (x == 2)
        {
            cout<< "THANKS FOR USING OUR PROGRAMME \n ";
            break ;
        }
        f.close();
    }

}

void view()
{
    fstream f ;
    f.open("hotel.txt",ios::in);
    cout<<"ID|First Name|Last Name|Country|Number|Duration\n" ;
    while(!f.eof())
    {
        f.getline(ID,15,'|');
        cout<< ID<<"\t" ;
        f.getline(first_name,16,'|');
        cout<<first_name<<"\t";
        f.getline(last_name,16,'|');
        cout<< last_name<<"\t";
        f.getline(country_name,21,'|');
        cout<< country_name<<"\t";
        f.getline(number,16,'|');
        cout<< number<<"\t";
        f.getline(duration,5,'\n');
        cout<<duration<<"\n";
    }
 f.close();
}

void search_id ()
{
	char search_key[15];
	bool flag = false ;
	fstream f ;
	f.open("hotel.txt",ios::in);
	cout<<"ENTER SEARCH KEY: \n ";
	cin>> search_key;
	 while(!f.eof()){
	         f.getline(ID,15,'|');
	         f.getline(first_name,16,'|');
	         f.getline(last_name,16,'|');
	         f.getline(country_name,21,'|');
	         f.getline(number,16,'|');
	         f.getline(duration,5,'\n');
	         if(strcmp(search_key,ID)==0){
	            cout<<ID<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<country_name<<"\t"<<number<<"\t"<<duration<<"\n";
	              flag=true;
	    }
	 }
	       if (flag==false)
	        cout<<"NOT FOUND \n";
}

void search_name ()
{
	char search_key [15];
	bool flag = false;
	fstream f;
	f.open("hotel.txt",ios::in);
	cout<<"ENTER SEARCH KEY:\n";
	cin>> search_key;
	 while(!f.eof()){
	         f.getline(ID,15,'|');
	         f.getline(first_name,16,'|');
	         f.getline(last_name,16,'|');
	         f.getline(country_name,21,'|');
	         f.getline(number,16,'|');
	         f.getline(duration,5,'\n');
	         if(strcmp(search_key,first_name)==0){
	            cout<<ID<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<country_name<<"\t"<<number<<"\t"<<duration<<"\n";
	              flag=true;
	    }
	}
	       if (flag==false)
	        cout<<"NOT FOUND \n";
}

void search()
{
	int key ;
	cout<<"ENTER 1 TO SEARCH WITH ID: \nENTER 2 TO SEARCH WITH NAME: \n";
	cin>> key;
	
	if (key==1)
		search_id();
	else if(key==2)
	    search_name();
	else
	    cout<<"WRONG INPUT\nENTER 1 TO SEARCH WITH ID: \nENTER 2 TO SEARCH WITH NAME: \n ";
}

void update()
{
	bool flag =false;
	char search_key [20];
	int new_ID ;
	fstream f;
	fstream f2 ("hotel2.txt");
	f.open("hotel.txt",ios::out|ios::app|ios::in);
	f2.open("hotel2.txt",ios::out|ios::app|ios::in);

	cout<<"ENTER THE ID YOU WANT TO UPDATE\n" ;
    cin>>search_key;
	while(!f.eof()){
	        f.getline(ID,15,'|');
	        f.getline(first_name,16,'|');
	        f.getline(last_name,16,'|');
	        f.getline(country_name,21,'|');
	        f.getline(number,16,'|');
	        f.getline(duration,5,'\n');
	        if(strcmp(search_key,ID)==0){ 
        		flag=true;
            	cout<< "ENTER THE NEW ID:\n ";
            	cin>>new_ID;
            	f2<<new_ID<<"|"<<first_name<<"|"<<last_name<<"|"<<country_name<<"|"<<number<<"|"<<duration<<"\n" ;
        	} else {
            	f2<<ID<<"|"<<first_name<<"|"<<last_name<<"|"<<country_name<<"|"<<number<<"|"<<duration<<"\n" ;
			}
	}
       
	if (flag==false)
    cout<<"Not found \n";
    else
    cout<< "UPDATED \n";

	f.close();
	f2.close();

	remove ("hotel.txt");
	rename ("hotel2.txt","hotel.txt");
}

void del()
{
	fstream f ;
	fstream f2 ("hotel2.txt");
    int flag=0;
    char search_key[20];
	f.open("hotel.txt",ios::in|ios::out|ios::app);
    f2.open("hotel2.txt",ios::in|ios::out|ios::app);
    
	cout<<"ENTER THE ID YOU WANT TO DELETE\n" ;
    cin>>search_key;
	while(!f.eof()){
	        f.getline(ID,15,'|');
	        f.getline(first_name,16,'|');
	        f.getline(last_name,16,'|');
	        f.getline(country_name,21,'|');
	        f.getline(number,16,'|');
	        f.getline(duration,5,'\n');
	        if(strcmp(search_key,ID)==0)
			{
	        	flag=1;
			} else {
				f2<<ID<<"|"<<first_name<<"|"<<last_name<<"|"<<country_name<<"|"<<number<<"|"<<duration<<"\n" ;
			}
	    }
	
	f2.close();
	f.close();
	if(flag!=1)
	{
		cout<<"NOT FOUND \n";
	}
	else
	{
		cout<<"THE RECORD HAS DELETED\n";	
	}
	remove("hotel.txt");
	rename("hotel2.txt","hotel.txt");
	
}


int main()
{
	int i ;
    char ch ;
	cout<< "\n";
	cout << " WELCOME TO HOTEL MANEGMENT SYSTEM " << endl << endl;
	
	 do {
	     
		cout<<"          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  \n";
		cout<<"         <                   ENTER AN SELECTION                  > \n";
		cout<<"         <                                                       > \n";
		cout<<"         <     1 : TO REGISTER A NEW CUSTOMER                    > \n";
	 	cout<<"         <     2 : TO VIEW ALL CUSTOMER RECORDS                  > \n";
	  	cout<<"         <     3 : TO SEARCH AN EXISTING CUSTOMER                > \n";
	    cout<<"         <     4 : TO UPDATE DETAILS ABOUT AN EXISTING CUSTOMER  > \n";
	    cout<<"         <     5 : TO DELETE AN EXISTING CUSTOMER                > \n";
	    cout<<"          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  \n";	
		cout<< " Selection: ";
	    
		cin>> i;
	    cout<<"\n";
	     
   	    switch (i)
	    {
	    	case 1 :
	        insert();
	        break;
	        
	   		case 2:
	        view();
	        break;
	        
	    	case 3:
	        search();
	        break;
	        
	    	case 4:
	        update();
	        break;
	        
			case 5:
	        del();
	        break;
	        			
			default :
	    
		    cout<<i<<" IS NOT A VAILD \n ";
			break;
	    }
	    cout<<"\nIF YOU WANT TO GO BACK TO MAIN MENU PRESS 0 \nIF NOT PRESS ANY OTHER KEY TO EXIT\n ";
    	cin>>ch;
	}
    while(ch=='0');	
    return 0;
}

