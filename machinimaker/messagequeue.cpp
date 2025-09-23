#include "messagequeue.h"

MessageQueue* MessageQueue::m_instance = nullptr;

MessageQueue* MessageQueue::instance(){
    if(!m_instance){
        m_instance = new MessageQueue();
    }
    return m_instance;
}

MessageQueue::MessageQueue(QObject *parent) : QObject(parent) {};

void MessageQueue::addMessage(const Message& message) {
    m_queue.push(message);
    emit MessageAdded();
}

bool MessageQueue::popMessage(Message& message) {
    if (m_queue.empty()) {
        return false;
    }
    message = m_queue.front();
    m_queue.pop();
    emit MessagePopped();
    return true;
}

std::queue<Message> MessageQueue::getQueue() const {
    return m_queue;
}

void MessageQueue::clearQueue(){
    std::queue<Message> empty;
    m_queue.swap(empty);
}
