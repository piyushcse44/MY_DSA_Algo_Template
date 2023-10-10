-------********Template**********--------------------
template<class T,class V>
class School
{
	T name;
	V id;
	T address;
public:
	School(T name,V id,T address)
	{
		School :: name = name;
		this->id = id;
		this->address = address;
	}
	void get(void);


   


};
template<class T,class V>
void School<T,V> :: get()
{
	cout<<name<<endl;
	cout<<id<<endl;
	cout<<address<<endl;
}





int main()
{
   
     School<string,int> *obj1 = new School<string,int>("S.A.M",1,"Kagzhi Mohalla");
     obj1->get();
  


	return 0;

}


--------------------******************* Random Function ****************************-----------
srand(time(NULL));// #include<time.h>
  int a=rand()%10+2,b=rand()%40+2;
  cout<<a<<" "<<b<<endl;

-----------*********************** file read update write *****************************---------------------------------
string read_file()
{
  string myText;
    ifstream Piyush_file_read("filename.txt");
  while (getline (Piyush_file_read, myText)) {
    cout << myText;
  }
    Piyush_file_read.close();
}
void write_file(string msg)
{
   ofstream Piyush_file_write("Binary_tree.txt",ios::app);  
   Piyush_file_write <<"\n"<< msg <<"\n";
   Piyush_file_write.close();
}