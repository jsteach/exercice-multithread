#include "entrypoint.h"

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

int candiesTaken = 0;
std::mutex jar_mutex;

void takeCandies(int numberOfCandies){
    jar_mutex.lock();
    for(int i =0; i < numberOfCandies;++i){
        candiesTaken++;
    }
    jar_mutex.unlock();
}

void raylib_start(void){

    while(1){
        
    }
    
    std::vector<std::thread> threads;
    const int kids = 8;
    const int candiesPerKid = 100'000;
    for(int i =0; i < kids; ++i){
        threads.emplace_back(std::thread(takeCandies,candiesPerKid));
    }

    for(int i = 0; i < threads.size();++i){
        threads[i].join();
    }

    std::cout << "The number of candies taken are: " << candiesTaken << std::endl;
}