#ifndef BOCCHI_OBSERVERINTERFACE_H
#define BOCCHI_OBSERVERINTERFACE_H

enum KEY {
    NONE,
    UP,
    DOWN,
    ENTER,
    ESCAPE,
    SPECIAL
};



class ObserverInterface {
public:
    std::vector<KEY> keys = std::vector<KEY>(255, KEY::NONE);
    explicit ObserverInterface() {
        keys[72] = KEY::UP;
        keys[80] = KEY::DOWN;
        keys[13] = KEY::ENTER;
        keys[27] = KEY::ESCAPE;
        keys[224] = KEY::SPECIAL;
    }
    virtual ~ObserverInterface() = default;
    virtual void update(KEY) = 0;
};

#endif //BOCCHI_OBSERVERINTERFACE_H
