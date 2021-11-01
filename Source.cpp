#include <iostream>

#include <fstream>    
#include <string>
#include <vector>
#include "strutils.h"
#include <algorithm> 
using namespace std;
 

struct courseNode  //given coursenode  
{
	 string courseCode, courseName;
	 vector<int> studentsAttendingIDs;
	 courseNode * next;
};
 

struct Node *head=NULL;//Declaring starting points
struct courseNode *head1=NULL;
struct courseNode *head2=NULL;
 


void insertNode0(string code , string name,string sayi){  //addding  new course code and do nessercy unit conversions.
    struct courseNode *newNode=new courseNode;
	newNode->courseCode=code;
	newNode->courseName=name;
	int kal =atoi(sayi);
	newNode->studentsAttendingIDs.push_back(kal);
	

    newNode->next=head1;
    head1=newNode;
	
}
 
//Traverse/ display all nodes (print items)

/*
void display0(){
    if(head1==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    struct courseNode *temp=head1;
    while(temp!=NULL){
		cout<<temp->courseCode<<" ";
		cout<<temp->courseName<<": ";
		for (auto i = temp->studentsAttendingIDs.begin(); i !=  temp->studentsAttendingIDs.end(); ++i) //https://www.geeksforgeeks.org/vector-in-cpp-stl/
			cout << *i << " ";
		cout<<endl;

        temp=temp->next;
    }
   // cout<<endl;
}*/
void display1(bool son){
    if(head1==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    struct courseNode *temp=head1;
    while(temp!=NULL){
		cout<<temp->courseCode<<" ";
		cout<<temp->courseName;
		if (temp->studentsAttendingIDs.size()>=3 ||  son == false) //cheching if it is final output display  and decide if a course will be close
		{
			cout<<": ";
			for (auto i = temp->studentsAttendingIDs.begin(); i !=  temp->studentsAttendingIDs.end(); ++i) //https://www.geeksforgeeks.org/vector-in-cpp-stl/ i got this for loop that site
				cout << *i << " ";
		}else
		{
			cout<<" -> This course will be closed";
		}

		cout<<endl;

        temp=temp->next;
    }
   // cout<<endl;
}
void bul0(string kod,string ders, string id ){
	bool exst= false;
	int kal =atoi(id);
    struct courseNode *temp=head1;
    while(temp!=NULL){
		if (temp->courseCode== kod )//checks if eleement already exists
		{

			temp->studentsAttendingIDs.push_back(kal); // it adds to vector
			sort(temp->studentsAttendingIDs.begin(), temp->studentsAttendingIDs.end());// https://iq.opengenus.org/sorting-vector-in-cpp/ <- got from there it sorts the vectr.
			exst = true;

		}
        temp=temp->next;
    }
	if (exst == false)
	{
		insertNode0(kod,ders,id); // if given lesson doesnt exsit it creates here
		//sort(temp.stud.begin(), v.end()); 
	}
}
void bul0_ek(string kod,string ders, string id ){//adds nessercy addtional students
	bool exst= false;
	bool icinde = false;
	int kal =atoi(id);
    struct courseNode *temp=head1;
    while(temp!=NULL){//checks if designated lessons contians in link list
		//cout<<kod<<endl<<ders<<id;
		if (temp->courseCode== kod ) 
		{
			for (auto i = temp->studentsAttendingIDs.begin(); i !=  temp->studentsAttendingIDs.end(); ++i) //https://www.geeksforgeeks.org/vector-in-cpp-stl 
			{
				if (*i == kal)//checks if given lessons contains gicen id
				{
					
					icinde = true;
				}
			}
	
			if (icinde==true)
			{

				cout<<"Student with id "<<id<<" already is enrolled to "<<kod<<". No action taken."<<endl;
			}else
			{
				cout<<"Student with id "<<id <<" is enrolled to "<<kod<<"."<<endl;
				temp->studentsAttendingIDs.push_back(kal);
				sort(temp->studentsAttendingIDs.begin(), temp->studentsAttendingIDs.end());// https://iq.opengenus.org/sorting-vector-in-cpp/
			}
			
			exst = true;

		}
        temp=temp->next;
    }
	if (exst == false)//if lessons doenst exist it creates new lesson
	{
		cout<<kod<<" does not exist in the list of Courses. It is added up. "<<endl;
		insertNode0(kod,ders,id);
		
		cout<<"Student with id "<<id <<" is enrolled to "<<kod<<"."<<endl;
		//sort(temp.stud.begin(), v.end()); 


	}
}
void bul0_sil(string kod,string ders, string id ){
	bool exst= false;
	bool icinde = false;
	int kal =atoi(id);
	int yer =0;
    struct courseNode *temp=head1;
	
    while(temp!=NULL){
		//cout<<kod<<endl<<ders<<id;
		if (temp->courseCode== kod ) //detects if given lesson exist in list 
		{
			for (auto i = temp->studentsAttendingIDs.begin(); i !=  temp->studentsAttendingIDs.end(); ++i) //https://www.geeksforgeeks.org/vector-in-cpp-stl/ checks if given id exist in 
			{
				if (*i == kal && temp->courseCode == kod)
				{
					
					icinde = true;
				}
				else if(icinde == false)
				{
					yer+=1;
				}
				
			}
			
	   
			if (icinde==true)
			{

				cout<<"Student with id "<<id<<" has dropped "<<kod<<endl;
				//temp->studentsAttendingIDs.erase(); 
				//erase(temp->studentsAttendingIDs,temp->studentsAttendingIDs[0]);
				//ugantus deletus
				temp->studentsAttendingIDs.erase(temp->studentsAttendingIDs.begin()+yer);//removes given number from vector
			}else 
			{
				cout<<"Student with id "<<id<<" is not enrolled to "<<kod<<", thus he can't drop that course."<<endl;
			}
			
			exst = true;

		}
        temp=temp->next;
    }
	if (exst == false)
	{
		cout<<kod<<" does not exist in the list of Courses. It is added up. "<<endl;
		insertNode0(kod,ders,id);
		cout<<"Student with id "<<id <<" is enrolled to "<<kod<<"."<<endl;
		//sort(temp.stud.begin(), v.end()); 


	}
}


void parcala1(string str,string & tmp_code,string &tmp_name,string &tmp_id)
{
	int length,ina;
	  string kelime,sid,sal,sal1;
	  str += " ";
      length = str.length();
        ina = 0;
    for (int i = 0; i < length; i++) 
    {
       if(int(str.at(i)) != 32 && int(str.at(i)) != 9 )
        {
         kelime+=str.at(i);   
        }else{ //disects given line and seprates 3 three parts(this part is only made for 3 parted txt file it is only for coursesandstudnets.txt format)
			if (ina == 0)
			{
				tmp_code = kelime;
			}
     
			if (ina == 1)
			{
				tmp_name = kelime;
			}
     
			if (ina == 2)
			{
				tmp_id =kelime;
			}
			//cout<<kelime<<endl;
			ina +=1;
            kelime= "";
        }      
    }
}
void parcala2(string str,string & tmp_code,string &tmp_name,string &tmp_id,bool & drop)
{
	
	int length,ina,hadi;
	  string kelime,sid,sal,sal1;
	  bool atma = false;
	  str += " ";
      length = str.length();
        ina = 0;
    for (int i = 0; i < length; i++) 
    {
       if(int(str.at(i)) != 32 && int(str.at(i)) != 9 ) //checks if is charcter " " or tab.
        {
         kelime+=str.at(i);   //constructs ids names  codes to diffrent strings 
        }else{

			
			if (atoi(kelime) >= 1) //checks if given constructed is numeric or alphabetic
			{
				tmp_id = kelime;
				//cout<<"@@@@@"<<tmp_code<<tmp_name<<tmp_id<<endl;
				if (drop == false)//checks if it isa addtion or removel process
				{
						bul0_ek(tmp_code,tmp_name,tmp_id);
						//sortlist0();
				}else if( drop == true)
					{

						bul0_sil(tmp_code,tmp_name,tmp_id);

							//cout<<"@@@@@"<<tmp_code<<tmp_name<<tmp_id<<endl;
						//	cout<<"7777"<<tmp_code<<tmp_name<<tmp_id<<endl;

							//bul0_sil(tmp_code,tmp_name,tmp_id);
					}
			
			}else
			{ // holds values of code and namme of lessons until line providies new alpabetic strings.When it revices alpahabetic strings it replaces old ones
				if(ina == 0)
				{
					tmp_code= kelime;
					ina +=1;
					//cout<<"?????"<<tmp_code<<endl;
				
				}
				else if(ina == 1)
				{
				
					tmp_name= kelime;
					ina= 0;
				}

			}


			
            kelime= "";
        }      
    }
}

void dele()
{
	struct courseNode *temp=head1;
    while(temp!=NULL)
	{
		temp = temp->next;
	}

}

void sortlist0(){//devam
	bool ok = false;
	int i = 0;
	string name,name1,code,code1;
	vector<int> id,id1;
	courseNode *ok0, *ok1;
	
    if(head1==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    struct courseNode *temp=head1;
    struct courseNode *temp1=head2;
	struct courseNode *temptemp=head1;
	/*for ( temp = head1;temp!= NULL;temp=temp->next)
	 {

		 cout<<"@@@@"<<temp->courseName<<endl;
		 		for ( temp1=temp->next;temp1 != NULL;temp1 =temp1->next)
					 {

						 cout<<"qq"<<temp1->courseName<<endl;
					 }

	 }
	*/



	 for ( temp = head1;temp!= NULL;temp=temp->next)
	 {
		// cout<<"@@@@"<<temp->courseName<<endl;
		 //for (temp1=temp->next;temp1 != NULL;temp1 =temp1->next /* temp1 = head1;temp1!= NULL;temp1=temp1->next*/)
		 for (temp1=temp->next;temp1 != NULL;temp1 =temp1->next/* temp1 = head1;temp1!= NULL;temp1=temp1->next*/)
		 {
			// cout<<"qq"<<temp1->courseName<<endl;
			 int sayac= 0;
			 ok = false;
			while (ok == false)
			{
				if (int(temp->courseName.at(sayac))!=int(temp1->courseName.at(sayac)) && ok ==false) //cheks if two strings are same 
				{
					//cout<<"!!!!!!"<<temp->courseName<<temp1->courseName<<endl;
					ok = true;
					//cout<<"kalas"<<endl;
					//cout<<temp->courseName.at(sayac)<<temp1->courseName.at(sayac)<<endl;
					if (int(temp->courseName.at(sayac))>int(temp1->courseName.at(sayac))) // checks  which one alphabetically comes first  
					{
						//cout<<"!!!!!!"<<temp->courseName<<temp1->courseName<<endl;
						//cout<<temp->courseName.at(sayac)<<temp1->courseName.at(sayac)<<endl;
						//cout<<temp->courseName<<"@@0"<<temp1->courseName<<endl;
					//	temp->courseName += "bok";
						
						//temptemp->next = temp->next;
						//cout<<temptemp<<temp<<temp1<<endl;
						/*
						temp->next = temp1->next;
						temp1->next = temptemp->next;*/

						/*
						temptemp->courseCode = temp->courseCode;
						temptemp->courseName = temp->courseName;
						temptemp->studentsAttendingIDs = temp->studentsAttendingIDs;
						//temptemp->next = temp->next;

						temp->courseCode = temp1->courseCode;
						temp->courseName = temp1->courseName;
						temp->studentsAttendingIDs = temp1->studentsAttendingIDs;
						//temp->next = temp1->next;

						
						temp1->courseCode = temptemp->courseCode;
						temp1->courseName = temptemp->courseName;
						temp1->studentsAttendingIDs = temptemp->studentsAttendingIDs;
						*/
						//cout<<"////?TEMP0"<<temp->courseCode<<temp->courseName<<endl;
						//cout<<"////?TEMP1"<<temp1->courseCode<<temp1->courseName<<endl;
						
						code = temp->courseCode; //swaps the values of two nodes
						name = temp->courseName;
						id = temp->studentsAttendingIDs;
						code1 = temp1->courseCode;
						name1 = temp1->courseName;
						id1 = temp1->studentsAttendingIDs;
						temp->courseCode = code1;
						temp->courseName = name1;
						temp->studentsAttendingIDs = id1;
						temp1->courseCode = code;
						temp1->courseName = name;
						temp1->studentsAttendingIDs = id;
						//cout<<"////TEMP0"<<temp->courseCode<<temp->courseName<<endl;
						//cout<<"////TEMP1"<<temp1->courseCode<<temp1->courseName<<endl;
						 //sal
					//	temp1->next = temptemp->next;
						/*
						code = temp->courseCode;
						name = temp->courseName;
						id = temp->studentsAttendingIDs;
						ok0 = temp->next;
						
						code1 = temp1->courseCode;
						name1 = temp1->courseName;
						id1 = temp1->studentsAttendingIDs;
						ok1 = temp1->next;

						temp->courseCode = code1;
						temp->courseName = name1;
						temp->studentsAttendingIDs = id1;
						temp->next = ok1;
						
						temp1->courseCode = code;
						temp1->courseName = name;
						temp1->studentsAttendingIDs = id;
						temp1->next = ok0;
						*/
		               
					}

				}
				sayac+=1;
			}
		 }
	 }
	 /*
    while(temp!=NULL)
	{
		while (temp1!=NULL)
		{
			while ()
			{

			}
		}
			 
        temp=temp->next;
    }*/
    
}

int main(){

	ifstream infile; 
	string dosya,tmp_code,tmp_name,tmp_id;
	string tmp_code1,tmp_name1,tmp_id1;
	string tmp_code2,tmp_name2,tmp_id2;

	string stringFromFile;
	bool ilk = true;
	int k;
	bool son = false;
	cout<<"Please enter file name:"<<endl;
	cin>> dosya;
	//dosya = "coursesAndStudents.txt"; //for quick testing
	infile.open(dosya); 
		if(infile.fail()) //Display error if the file failed to open
	{
	cout<<"Input file failed to open";
	}
	else
	{
		while (getline(infile,  stringFromFile)) //gets lines from file
		{

			if (ilk == true)
			{

				/*
				parcala1(stringFromFile,tmp_code,tmp_name,tmp_id);
				//courseNode *head = constructList();
				//courseNode* ptr = head;
				head1 ->courseCode = tmp_code;
				head1 ->courseName = tmp_name;
				head1 ->next = nullptr;
				k = atoi(tmp_id);
				head1 ->studentsAttendingIDs.push_back(k);
				printList1(head1);*/
				parcala1(stringFromFile,tmp_code,tmp_name,tmp_id);
				
				insertNode0(tmp_code,tmp_name,tmp_id);
				cout<<"Successfully opened file "<<dosya<<endl;
				cout<<"The linked list is created. "<<endl;
				cout<<"The initial list is: "<<endl;
				ilk = false;
				//creates first node and initlazies the list 
			
			}else
			{
				parcala1(stringFromFile,tmp_code,tmp_name,tmp_id);//adds other lines to link list
				bul0(tmp_code,tmp_name,tmp_id);
				
			}


		}
		
		infile.close();

		//display1(son);
	sortlist0();
	//cout<<"gor"<<endl;
	display1(son);
	string gelicek,gelicek1;
	bool drop;
	ifstream infile1; 
	int ply_scm;
	//it takes inputs and calls the nessercy functions
	do
	{
		cout<<endl<<"Please select one of the choices:"<<endl;
		cout<<"1. Add to List"<<endl;
		cout<<"2. Drop from List"<<endl;
		cout<<"3. Display List"<<endl;
		cout<<"4. Finish Add/Drop and Exit"<<endl;
		cin>> ply_scm;
		if (ply_scm == 3)
		{
			cout<<"The current list of course and the students attending them:"<<endl;
			sortlist0();
			display1(son);
		}
		if (ply_scm == 1)
		{
			cout<<"Give the student ID and the course names and course codes that he/she wants to add:"<<endl;
			cin.ignore();
			getline(cin,gelicek);
			
			
			drop = false;
			parcala2(gelicek,tmp_code1,tmp_name1,tmp_id1,drop);
			sortlist0();
			//bul0(tmp_code1,tmp_name1,tmp_id1);
			/*cin>>gelicek;
			getline(infile1,  gelicek);
			parcala1(gelicek,tmp_code1,tmp_name1,tmp_id1);
			cout<<tmp_code1<<tmp_name1<<tmp_id1<<endl;
			*/
			/*
			parcala1(gelicek,tmp_code1,tmp_name1,tmp_id1);
			cout<<tmp_code1<<tmp_name1<<tmp_id1<<endl;*/

		}
		if (ply_scm == 2)
		{
	       
			cout<<"Give the student ID and the course names and course codes that he/she wants to drop:"<<endl;
			cin.ignore();
			getline(cin,gelicek1);
			drop = true;
			
			//parcala2(gelicek,tmp_code1,tmp_name1,tmp_id1,drop);
			/*
			parcala2(gelicek,tmp_code2,tmp_name2,tmp_id2,drop);
			cout<<"***"<<tmp_code2<<tmp_name2<<tmp_id2<<endl;
			bul0_sil(tmp_code2,tmp_name2,tmp_id2);

			drop = false;
			*/

			parcala2(gelicek1,tmp_code2,tmp_name2,tmp_id2,drop);//diespcts the line
		}

	} while (ply_scm != 4);
	cout<<"The add/drop period is finished. Printing the final list of courses and students attending them."<<endl;
	cout<<"NOTE: Courses with less than 3 students will be closed this semester."<<endl;
	sortlist0();
	son = true;
	display1(son); //final specail output display
	courseNode *temp7=head1;
	courseNode *temp9=head1;
	 //deletes  the link list
	while (temp7!= NULL)
	{
		 temp9 = temp7;
		 temp9= temp7->next;
		//cout<<temp7->courseCode<<"sda"<<temp9->courseCode<<endl;
		 //cout<<"deletd one "<<temp7->courseCode<<endl;
		 free(temp7);
		 temp7 =temp9;
	}
	 return 0;
	/*
	for ( temp7 = head1;temp7!= NULL;temp7=temp7->next)
	 {
		 temp9 = temp7;
		 cout<<temp7->courseCode<<endl<<temp9->courseCode<<endl;
		 delete temp9;
		 cout<<temp7->courseCode<<endl<<temp9->courseCode<<endl;
	}
	*/
	//display1(son);
	
   



	}
		
}
