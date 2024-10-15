#include "Headers.h"

ThreadPool::ThreadPool(size_t num_Threads) : stop(false) {
    for (size_t i = 0; i < num_Threads; ++i) {
        workers.emplace_back([this] {
            for (;;) {
                std::unique_lock<std::mutex> lock(queueMutex);
                condition.wait(lock, [this] {return stop || !tasks.empty(); });
                if (stop && tasks.empty())
                    return;
                auto task = std::move(tasks.front());
                tasks.pop();
                lock.unlock();
                task();
            }
            });
    }
}

ThreadPool::~ThreadPool() {
    std::unique_lock<std::mutex> lock(queueMutex);
    stop = true;
    lock.unlock();
    condition.notify_all();
    for (std::thread& worker : workers)
        worker.join();
}
std::string get_thread_id() {
    auto myid = std::this_thread::get_id;
    std::stringstream ss;
    ss << myid;
    std::string mystr = ss.str();
    return mystr;
}