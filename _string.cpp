// Online C++ compiler to run C++ program online
//Custom string class
// all constructors, operators overloading etc
#include <iostream>
#include <cstring>
using namespace std;
class _string{
     char *res;
    unsigned int len;
    friend ostream& operator<<(ostream &out, const _string& temp);
    friend istream& operator>>(istream &out, const _string& temp);
    public:
    _string():res(nullptr),len(0){        cout<<"\n Inside --- default constructor"; }
    _string(const char *ch){
        len=strlen(ch);
        res=new char[len+1];
        strcpy(res,ch);
        cout<<"\n Inside --- parameterised constructor";
    }
    _string(const _string& temp){
        len=temp.len;
        res=new char[len+1];
        strcpy(res,temp.res);
        cout<<"\n Inside --- copy constructor";
    }
   _string( _string&& temp){
        len=temp.len;
        res=temp.res;
       temp.res=nullptr;
       temp.len=0; 
       cout<<"\n Inside --- move constructor";
    }
    // _string(const _string& temp){
    _string& operator=(const _string& temp){
        if(this!= &temp) {
            delete[] res;
            len=temp.len;
            res=new char[len+1];
            strcpy(res,temp.res);
            cout<<"\n Inside --- copy assigment constructor";
        }
        return *this;
    }
    unsigned int _length(){
        return len;
    } 
    void print(){
    cout<<"\tData: "<<(res == nullptr ? "nullptr": res)  <<", length: "<<len;
    }
~_string(){
    if(res){
        delete[] res;
        res=nullptr;
        len=0;
        cout<<"\n Inside --- default destructor";
    }
}
};
ostream& operator<<(ostream& out, const _string& temp)
{
    cout<<"\n Inside --- operator << overloading\t ";
    out<<temp.res;
    return out;
}
istream& operator>>(istream& in, const _string& temp)
{
    cout<<"\n Inside --- operator >> overloading\t ";
    in>>temp.res;
    return in;
}

int main() {
    _string str1;    str1.print(); //default constructor
    _string str2 = "manish";   str2.print();    //parameterised constructor
    _string str3 = str2;      str3.print();  //copy constructor
    _string str4(str2);     str4.print();  //   same as above copy constructor
    str1=str2;    str1.print();      //copy assigment constructor
    _string str5;    str5.print(); //default constructor
     str5="PATEL";    str5.print();      //copy assigment constructor
    unsigned int _len= str5._length();     //length function
    cout<<"\n Length: "<<_len;
    cout<<str2;       // operator << overloading
    cin>>str2;           // operator >> overloading
    _string str6 = move(str5); // move constructor
    
    // _string str
    // std::cout << "Hello, World!";

    return 0;
}




/*  NOTES
parameterised constr. pass multuple values or see diff options
same as _string str2("hello",2);

If we make class data member const as "const char*ch" then to allocate mem,dynamically, we need to use const_cast as below to use both const + dynamic allocation( deep copy)
strcpy(const_cast<char*>(res), ch); // Copy the string into res 

ini. list, const int a; int &mem; those should be do in ini. list, not in body, so ini.list used
we have another class object in current class, where it has only para.constr., but doesnt have default.const
then we need to ini. another class obj with ini.list

const string &str
const not to change anything accidently in body code
 &str is ref pointing to that resource, if we dont use & it will thro error as it did not find copy.const.
 
copy.const,  class obj is created then its called,
if object already created then copy assgn.oper called

str3="hello" str3 is already created , chec ??

in copy.assg.oper 
check for self ini as str3=str3; case as in body (this != &str);
delete [] res; // must delete otherwise overwrite,mem.leaked [] is for array delete
Ques.in case after delete, no allocation happen, so you loose existing data. how to fix ?
ans char *temp =this->res; len=; res=new char; strcpy(res,str.res); del [] temp;
ans.or use CAS copy as swap
pass as (string str) (no const &) , swap(this,str ); return this; implement swap as std:swap(res,this.res)


str3=str2;  str3 is calling = operator
vs 
cout<<str2; cout is calling << operator, so you can not do in class. make it global outside of class.
  cout is object, str2 is param, but cout is std.c++ lib, we cant change there so other option to implement 
  is make global << override function with param (cout,str)
 to access _string class priv.data make it that function friend in your class 

move constructor for optimization purpose came after c++11
give ownership to new n self die, 
receive as rvalue, lvalue concepts _string (const string &&str) no const

destructor  delete, derefenrece ptr 

*/
