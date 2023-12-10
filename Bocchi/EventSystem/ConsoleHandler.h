#ifndef BOCCHI_CONSOLEHANDLER_H
#define BOCCHI_CONSOLEHANDLER_H
#ifndef LISING
#include <memory>
#include <utility>
#include <conio.h>
#endif
#include "ObservedInterface.h"

class ConsoleHandler : public ObservedInterface {
public:
    explicit ConsoleHandler(std::shared_ptr<ObserverInterface> observer) {
        this->observer = std::move(observer);
    }
    KEY getKey(){
        return this->observer->keys[_getch()];
    }
    void listen() {
        notify(getKey());
    }
    void notify(KEY key) override {
        this->observer->update(key);
    }
};

#endif //BOCCHI_CONSOLEHANDLER_H
