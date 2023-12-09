#ifndef BOCCHI_EVENT_H
#define BOCCHI_EVENT_H

class Event {
public:
    Event() = default;
    virtual ~Event() = default;
    virtual void appendListener() = 0;
    virtual void notify() = 0;
};

#endif //BOCCHI_EVENT_H
