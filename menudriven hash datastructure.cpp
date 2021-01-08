#include<iostream>
#include<list>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

class Hash
{
private:
int bucket;
list<int>*Hash_table;
public:
Hash(int x);
void insert_key(int x);
void delete_key(int x);
void display();
int hash_function(int key)
{
return(key%bucket);
}
};
Hash::Hash(int x)
{
bucket=x;
Hash_table=new list<int>[bucket];
}

void Hash::insert_key(int x)
{
int index=hash_function(x);
Hash_table[index].push_back(x);
}

void Hash::delete_key(int x)
{
int count=0;
int index=hash_function(x);
list<int>::iterator i;
for(auto i=Hash_table[index].begin();i!=Hash_table[index].end();i++)
{
if(*i==x)
{
Hash_table[index].erase(i);
count++;
break;
}
}
if(count==0)
{
cout<<"Data "<<x<<" was not found:"<<endl;
}
}

void Hash::display()
{
for(int j=0;j<bucket;j++)
{
cout<<j;
for(auto k=Hash_table[j].begin();k!=Hash_table[j].end();k++)
{
cout<<"-->"<<*k;
}
cout<<"\n";
}

}

int main()
{
int buc;
cout<<"Enter the total number of keys or index you want to be in your hash:\n->";
cin>>buc;
Hash data(buc);
while(1)
{
int choice;

cout<<"PRESS:\n1 to insert data to the hash:\n2 to delete data from the hash:\n3 to display complete data inside hash:\n0 to EXIT:\n"<<endl;

cin>>choice;
system("clear");
switch(choice)
{
case 1:
int val;
cout<<"Enter data:"<<endl;
cin>>val;
data.insert_key(val);
system("clear");
break;
case 2:
int val2;
cout<<"Enter the data you want removed from the hash:"<<endl;
cin>>val2;
data.delete_key(val2);

break;
case 3:
data.display();
break;
case 0:
cout<<"-----EXIT-----"<<endl;
exit(0);
}
}
}
