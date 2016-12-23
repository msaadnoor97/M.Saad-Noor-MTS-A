#include<iostream>
#include"opencv2/highgui/highgui.hpp" 
#include<string>
#include<vector>
#include<fstream>
using namespace std;
using namespace cv;
struct node
{
	Mat image;
	int id;
	string name;
	node* next;
};
class linkedlist
{
private:
	node* newnode;
	node* head;
	node* cur;
	int id;
public:
	linkedlist()
	{
		head=NULL;
		cur=NULL;
		newnode=NULL;
		id=0;
	}
	void addnode(string _address,string _name)
	{
		if (head==NULL)
		{
			newnode=new node;
			head=newnode;
			newnode->image=imread(_address,CV_LOAD_IMAGE_UNCHANGED);
			newnode->id=id;
			id++;
			newnode->name=_name;	
			newnode->next=NULL;
			cur=newnode;
		}
		else
		{
			newnode=new node;
			cur->next=newnode;
			newnode->image=imread(_address,CV_LOAD_IMAGE_UNCHANGED);
			newnode->id=id;
			id++;
			newnode->name=_name;
			newnode->next=NULL;
			cur=newnode;

		}
	}
	void readcsv()
	{
		ifstream data("CSV.txt",ios::in);
		string line, address,name;
		while (getline(data, line))
		{
			stringstream liness(line);
			getline(liness, address,';');
			getline(liness, name);
			addnode(address,name);
		}
	};
	node* searchbyid(int _id)
	{
		node* temp=head;
		while(temp !=NULL && temp->id!= _id)
		{
			temp=temp->next;
		}
		if (temp==NULL)
			cout<<"No such item exist"<<endl;

		return temp;
	}
	node* searchbyname(string _name)
	{
		node* temp=head;
		while(temp !=NULL && temp->name!= _name)
		{
			temp=temp->next;
		}
		if (temp==NULL)
			cout<<"No such item exist"<<endl;
		return temp;
	}
	void displayimage(node* temp)
	{
		namedWindow(temp->name,CV_WINDOW_KEEPRATIO);
		imshow(temp->name,temp->image);
		waitKey(0);
	}
};
int main()
{
    linkedlist a;
	a.readcsv();
	int id;
	cin>>id;
	a.displayimage(a.searchbyid(id));
	system("pause");
	return 0;
}


