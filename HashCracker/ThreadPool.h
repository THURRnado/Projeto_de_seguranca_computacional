#pragma once

#ifndef THREADPOOL
#define THREADPOOL

class ThreadPool {
public:
    ThreadPool(size_t num_Threads);
    virtual ~ThreadPool();

    template <class F>
    void enqueue(F&& task);

    std::string get_thread_id();

    //private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;

};
template<class F>
void ThreadPool::enqueue(F&& task) {
    std::unique_lock<std::mutex> lock(queueMutex);
    tasks.emplace(std::forward<F>(task));
    lock.unlock();
    condition.notify_one();
}

#endif