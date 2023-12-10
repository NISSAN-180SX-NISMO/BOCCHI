//
// Created by user on 08.12.2023.
//

#ifndef BOCCHI_OBSERVEDINTERFACE_H
#define BOCCHI_OBSERVEDINTERFACE_H
#ifndef LISING
#include <memory>
#endif
#include "ObserverInterface.h"

class ObservedInterface {
protected:
    std::shared_ptr<ObserverInterface> observer;
public:
    explicit ObservedInterface() = default;
    virtual ~ObservedInterface() = default;
    virtual void notify(KEY) = 0;
};


#endif //BOCCHI_OBSERVEDINTERFACE_H
