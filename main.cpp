#include <iostream>
#include <string>
#include <thread>

#include "dummyclass.h"
#include "wallet.h"

using namespace std;


void thread_function()
{

    for(int i = 0; i < 10; i++){
         std::cout<<"thread function Executing...thread id= "<<this_thread::get_id()<<" "<<std::endl;
        std::chrono::duration<int, std::milli> timespan(1000);
        std::this_thread::sleep_for(timespan);
    }
    std::cout<<"thread function Completed"<<std::endl;
}

void threadCallback(int const & x)
{
    int & y = const_cast<int &>(x);
        y++;
    std::cout<<"Inside Thread x = "<<x<<std::endl;
}
/**
 * @brief testMultithreadedWallet 5 threads add 1000 to wallet in parallel
 * @return expected result 5000
 */
int testMultithreadedWallet()
{
    Wallet walletObject;
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
    }

    for(int i = 0; i < threads.size() ; i++)
    {
        threads.at(i).join();
    }
    return walletObject.getMoney();
}

int main()
{
    int val = 0;
    bool tpass = true;
        for(int k = 0; k < 1000; k++)
        {
            if((val = testMultithreadedWallet()) != 5000)
            {
                std::cout << "Error at count = "<<k<<"  Money in Wallet = "<<val << std::endl;
                tpass = false;
                //break;
            }
        }
    if(tpass){
    std::cout<<"========= testMultithreadedWallet passed...======="<< std::endl;
    }        
    /*
    *Pass the pointer to member function as callback function and
    * pass pointer to Object as second argument, argumrnt third
    */
    DummyClass dummyObj;
        int x = 10;
        std::thread threadObj0(&DummyClass::sampleMemberFunction,&dummyObj, x);
        threadObj0.join();
    //----------------//
        std::cout<<"Thread is changing ref value x..."<<std::endl;
        x = 9;
        std::cout<<"In Main Thread : Before Thread Start x = "<<x<<std::endl;
        std::thread threadObj(threadCallback, std::ref(x));
        threadObj.join();
        std::cout<<"In Main Thread : After Thread Joins, x = "<<x<<std::endl;

    std::thread threadObj1(thread_function);

    for(int i = 0; i < 10; i++){
        std::cout<<"Display From MainThread... Thread id= "<<this_thread::get_id()<<" "<<std::endl;
            std::chrono::duration<int, std::milli> timespan(1000);
            std::this_thread::sleep_for(timespan);
        }
            std::cout<<"MainThread completed"<<std::endl;
        threadObj1.join();
        std::cout<<"Exit of Main function"<<std::endl;
        //-----------------//

        return 0;

}

class MultiThreads {
    static const int num_threads = 10;

    static void call_from_thread(int tid) {
              std::cout << "Launched by thread " << tid << std::endl;

    }


    void runMultiThreads() {
        std::thread t[num_threads];
        //Launch a group of threads
        for (int i = 0; i < num_threads; ++i) {
            t[i] = std::thread(call_from_thread, i);
        }
        std::cout << "Launched from the the main\n";
        //Join the threads with the main thread
        for (int i = 0; i < num_threads; ++i) {
            t[i].join();
        }
    }
};


