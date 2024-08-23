// Single with multithreading 
// Online C++ compiler to run C++ program online
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;
class single{
    static single *inst;
    static int count;
    static mutex mtx;
    single(){            cout<<"\n Private construtor---";}
    single(const single &s)=delete;
    single operator=(const single &)=delete;
public:
    static single* getinstance(){
        if(inst== nullptr){
            mtx.lock();
            if(inst== nullptr){
                inst= new single();
                count++;
                cout<<"\n creating class obect first time--- count :"<<count;
            }
            mtx.unlock();
        }
        else{
            cout<<"\n return existing class obect--- count :"<<count;
        }          
        return inst;
    }
    void print(string msg){
        cout<<"\n Inside Print function--- msg: "<<msg<<" count :"<<count<<endl;
    } 
};
single* single::inst=nullptr;
int single::count=0;
mutex single::mtx;

void fun1()
{
    sleep(1);
    single *s1=single::getinstance();
    s1->print("s1");    
}
void fun2()
{
    sleep(1);
    single *s2=single::getinstance();
    s2->print("s2");    
}
int main() {
     thread t1(fun1);
     thread t2(fun2);
    t1.join();
    t2.join();
    
    return 0;
}


