#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <QObject>
#include <queue>
#include "message.h"

class MessageQueue:public QObject
{
    Q_OBJECT

public:
    static MessageQueue* instance();

    void addMessage(const Message& message);
    bool popMessage(Message& message);
    std::queue<Message> getQueue() const;

signals:
    void MessageAdded();
    void MessagePopped();

private:
    MessageQueue(QObject *parent = nullptr);
    static MessageQueue* m_instance;
    std::queue<Message> m_queue;
};

#endif // MESSAGEQUEUE_H
