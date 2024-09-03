#include <iostream>
#include <thread>
#include <condition_variable>
#include <string>
#include <chrono>

using namespace std::literals;

std::string sdata;
std::mutex mut;
std::condition_variable cond_var;
bool ready = false;

void reader()
{
    std::unique_lock<std::mutex> uniq_lck(mut);
    cond_var.wait(uniq_lck, []{ return ready; });
    std::cout << "Reader thread wakes up\n";
    std::cout << "Data is \"" << sdata << "\"\n";
}

void writer()
{
    {
        std::lock_guard<std::mutex> lck_guard(mut);
        std::this_thread::sleep_for(2s);
        sdata = "Populated";
        ready = true;
    }
    cond_var.notify_one();
}

int main()
{
    sdata = "Empty";
    std::cout << "Data is \"" << sdata << "\"\n";

    std::thread read(reader);
    std::thread write(writer);

    write.join();
    read.join();
}
