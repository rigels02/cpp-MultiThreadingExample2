#ifndef WALLET_H
#define WALLET_H

#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include <iostream>

class Wallet
{
    int mMoney;
    std::mutex mutex;
public:
    Wallet() :mMoney(0){}
    int getMoney()   { 	return mMoney; }
    void addMoney(int money)
    {
        mutex.lock();
        for(int i = 0; i < money; ++i)
        {
            mMoney++;
        }
        mutex.unlock();
    }
};

#endif // WALLET_H
