

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
using namespace std;
int char_count=4;
string input {"ABCDEFGHIJK"};
int t_count=3;
mutex mtx;
condition_variable cv;
int c_thread=0;
void fun(int t_run)
{
    int n=input.size();
    int idx=t_run * char_count;
    while(true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [=] { return c_thread == t_run; });

        for (int i = 0; i < char_count; ++i) {
            std::cout << input[(idx + i) % n];
        }
        std::cout << std::endl;

        idx = (idx + t_count * char_count) % n;
        c_thread = (c_thread + 1) % t_count;

        cv.notify_all();        
    }
    // cout<<"\nIn fun with param as : "<<temp<<" thread id :"<<this_thread::get_id()<<endl;
    // for(int i=1;i<=t_run;i++)
    // {
    //     cout<< i <<endl;        
    // }
    // // cout<<endl;
}
int main()
{
    vector<thread> t;
    // threads.emplace_back(print_chars, std::ref(input), char_count, i, num_threads);
    // threads.push_back   ( thread (print_chars, std::ref(input), char_count, i, num_threads) );

    t.push_back(thread(fun,0));
    t.push_back(thread(fun,1));
    t.push_back(thread(fun,2));
    t[0].join(); t[1].join(); t[2].join();
    // thread t1(fun,5);
    // cout << "Thread 1 ID: " << t1.get_id() << endl;
    // t1.join(); 
    // thread t2(fun,2);
    // cout << "Thread 2 ID: " << t2.get_id() << endl;
    // t2.join();

    return 0;
}
