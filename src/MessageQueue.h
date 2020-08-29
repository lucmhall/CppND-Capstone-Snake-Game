#ifndef MESAGEQUEUE_H
#define MESAGEQUEUE_H

#include <mutex>
#include <deque>
#include <condition_variable>

template <class T>
class MessageQueue
{
public:
    void send(T &&msg);
    T receive();

private:
    std::deque<T> _queue;
    std::condition_variable _condition;
    std::mutex _mutex;
};

#endif