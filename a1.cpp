#include <bits/stdc++.h> 
using namespace std;

// Classes below

class Student {
public:
	string name;
	int rollNO;
	int CGPA;
	int branchID;
	int univID;
	Student* nextStudent;
};

class University{
public:
	int univID;
	string univName;
	string univLocation;
	int foundingYear;
	University *nextUniversity;
};

struct Branch{
public:
	int branchID;
	string branchName;
	int univID;
	Branch* nextBranch;
};

Student *stu_head = NULL;
University *univ_head = NULL;
Branch *branch_head = NULL;

// Functions to Insert Records Below

void insertStudent(int roll, string name, int cgpa, int branchID, int universityID)
{
	Student* t = new Student();
	t->rollNO = roll;
	t->name = name;
	t->branchID = branchID;
	t->univID = universityID;

	if(stu_head==NULL)
	{
		stu_head = t;
	}
	else
	{
		t->nextStudent = stu_head;
		stu_head = t;
	}
}

void insertUniversity(int uid, string uname, string uloc, int yr)
{
	University *t = new University();
	t -> univID = uid;
	t -> univName = uname;
	t -> univLocation = uloc;
	t -> foundingYear = yr;

	if(univ_head==NULL)
	{
		univ_head = t;
	}
	else
	{
		t->nextUniversity = univ_head;
		univ_head = t;
	}
}

void insertBranch(int bid, string bname, int uid)
{
	Branch *t = new Branch();
	t -> branchID = bid;
	t -> branchName = bname;
	t -> univID = uid;

	if(branch_head==NULL)
	{
		branch_head = t;
	}
	else
	{
		t->nextBranch = branch_head;
		branch_head = t;
	}
}

// Function To Check Uniqueness of IDs Below

bool isUniqueStu(int in_roll)
{
	Student *temp = new Student();
	temp = stu_head;

	while(temp!=NULL)
	{
		if(temp->rollNO == in_roll)
		{
			return false;
		}
		temp = temp->nextStudent;
	}
	return true;
}

bool isUniqueUniv(int univ_id)
{
	University *temp = new University();
	temp = univ_head;

	while(temp!=NULL)
	{
		if(temp->univID == univ_id)
		{
			return false;
		}
		temp = temp->nextUniversity;
	}

	return true;
}

bool isUniqueBranch(int b_id)
{
	Branch *temp = new Branch();
	temp = branch_head;

	while(temp!=NULL)
	{
		if(temp->branchID == b_id)
		{
			return false;
		}
		temp = temp->nextBranch;
	}
	return true;
}

// Function To check Avaliblity of University and Branch IDs Below

bool isUnivIDAvailable(int u_id)
{
	University *temp = new University();
	temp = univ_head;

	while(temp!=NULL)
	{
		if(temp->univID == u_id)
		{
			return true;
		}
		temp = temp->nextUniversity;
	}
	return false;
}

bool isBranchIDAvailable(int b_id)
{
	Branch *temp = new Branch();
	temp = branch_head;

	while(temp!=NULL)
	{
		if(temp->branchID == b_id)
		{
			return true;
		}
		temp = temp->nextBranch;
	}

	return false;
}

// Functions To Display Entire DB below

void displayStudentDB()
{
	Student* temp = new Student();
	temp = stu_head;
	cout<<endl;
	cout<<"All Students Listed in DB are as follows:  "<<endl;
	cout<<endl;

	while(temp!=NULL)
	{
		cout<<"Name: "<<temp->name<<endl;
		cout<<"Roll No: "<<temp->name<<endl;
		cout<<"CGPA: "<<temp->CGPA<<endl;
		cout<<"Branch ID: "<<temp->branchID<<endl;
		cout<<"University ID: "<<temp->univID<<endl;
		temp = temp->nextStudent;
		cout<<endl;
	}
}

void displayUniversityDB()
{
	University* temp = new University();
	temp = univ_head;
	cout<<endl;
	cout<<"All University Listed in DB are as follows:  "<<endl;
	cout<<endl;

	while(temp!=NULL)
	{
		cout<<"University ID: "<<temp->univID<<endl;
		cout<<"University Name: "<<temp->univName<<endl;
		cout<<"University Location: "<<temp->univLocation<<endl;
		cout<<"University's Founding Year: "<<temp->foundingYear<<endl;
		temp = temp->nextUniversity;
		cout<<endl;
	}	
}

void displayBranchDB()
{
	Branch* temp = new Branch();
	temp = branch_head;
	cout<<endl;
	cout<<"All University Listed in DB are as follows:  "<<endl;
	cout<<endl;

	while(temp!=NULL)
	{
		cout<<"Branch ID: "<<temp->branchID<<endl;
		cout<<"Branch Name: "<<temp->branchName<<endl;
		cout<<"Associated University's ID: "<<temp->univID<<endl;
		temp = temp->nextBranch;
		cout<<endl;
	}
}

void display_studentAtKiit(){
    Student *temp1=stu_head;
    University *temp2=univ_head;
    
    while(temp2!=NULL){
        if(temp2->univName=="KIIT University"){
            break;
        }
        temp2=temp2->nextUniversity;
    }
    
    
cout<<"List of students reading in KIIT University are "<<endl;
    while(temp1!=NULL){
        if(temp1->univID==temp2->univID){
            cout<<temp1->name<<endl;
        }
        temp1=temp1->nextStudent;
    }
}

void diplay_KiitStudentCse(){
    Student *temp1=stu_head;
    University *temp2=univ_head;
    Branch *temp3=branch_head;
    
    while(temp2!=NULL){
        if(temp2->univName=="KIIT University"){
            break;
        }
        temp2=temp2->nextUniversity;
    }
    
    while(temp3!=NULL){
        if(temp3->branchName=="CSE"){
            break;
        }
        temp3=temp3->nextBranch;
    }
    
    cout<<"List of students reading in KIIT University with CSE branch are "<<endl;
    
    
    while(temp1!=NULL){
        if(temp1->univID==temp2->univID&&temp1->branchID==temp3->branchID){
            cout<<temp1->name<<endl;
        }
        temp1=temp1->nextStudent;
    }
}

// Main Function

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

while(true) 
{
	cout<<"Wlcm to Student Record management!!!\nEnter 1 to create a new Student Record\nEnter 2 to create a new University Record\nEnter 3 to create a new Branch Record\nEnter 4 to Display the whole Student DB\nEnter 5 to Display the whole University DB\nEnter 6 to Display the whole Branch DB\nEnter 7 to Display the student list reading at KIIT University\nEnter 8 to Display the student list reading at KIIT University with CSE branch\n";
	cout<<"Enter Your Choice"<<endl;
	int choice;

	cin>>choice;

	if(choice==1)
	{
		cout<<"Enter Roll No of Student: "<<endl;
		int roll_num; cin>>roll_num;
		if(isUniqueStu(roll_num)==false)
		{
			cout<<"An Record with the given Roll No Already Exists"<<endl;
			break;
		}

		cout<<"Enter Name of Student: "<<endl;
		string name_stu; cin>>name_stu;

		cout<<"Enter CGPA of Student: "<<endl;
		int cgpa_stu; cin>>cgpa_stu;

		cout<<"Enter Branch ID of Student: "<<endl;
		int bid_stu; cin>>bid_stu;
		if(isBranchIDAvailable(bid_stu) == false)
		{
			cout<<"No Branch Exists with the Given Branch ID"<<endl;
			break;
		}

		cout<<"Enter University ID of Student: "<<endl;
		int uid_stu; cin>>uid_stu;
		if(isUnivIDAvailable(uid_stu)==false)
		{
			cout<<"No University Exists with the Given University's ID"<<endl;
			break;
		}
		insertStudent(roll_num, name_stu, cgpa_stu, bid_stu, uid_stu);
		cout<<"Student Record Created!!"<<endl;
	}
	else if(choice==2)
	{
		cout<<"Enter Name of University: "<<endl;
		string uname; cin>>uname;

		cout<<"Enter University's ID: "<<endl;
		int uid; cin>>uid;
		if(isUniqueUniv(uid)==false)
		{
			cout<<"An Record with the given University ID Already Exists"<<endl;
			break;
		}

		cout<<"Enter University's Location: "<<endl;
		string loc; cin>>loc;

		cout<<"Enter University's Founding Year: "<<endl;
		int yr; cin>>yr;
		insertUniversity(uid, uname, loc, yr);
		cout<<"University Record Created!!"<<endl;
	}
	else if(choice==3)
	{
		cout<<"Enter Branch ID: ";
		int bid; cin>>bid;
		if(isUniqueBranch(bid)==false)
		{
			cout<<"An Record with the given Branch ID already exists"<<endl;
			break;
		}

		cout<<"Enter Branch Name: ";
		string bname; cin>>bname;

		cout<<"Enter University ID: ";
		int uid; cin>>uid;

		insertBranch(bid, bname, uid);
		cout<<"Branch Record Created!!"<<endl;
	}
	else if(choice==4)
	{
		displayStudentDB();
	}
	else if(choice==5)
	{
		displayUniversityDB();
	}
	else if(choice==6)
	{
		displayBranchDB();
	}
    else if(choice==7)
	{
		display_studentAtKiit();
	}
	else if(choice==8)
	{
		diplay_KiitStudentCse();
	}
}
	return 0;
}
