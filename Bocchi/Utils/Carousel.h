#ifndef BOCCHI_CAROUSEL_H
#define BOCCHI_CAROUSEL_H
#ifndef LISING
#include <vector>
#include <memory>
#endif

template <class Data>
class Carousel {
private:
    std::vector<Data> vector;
    size_t currentIndex = 0;
public:
    void append(Data data) {
        vector.push_back(data);
    }
    void clear() {
        vector.clear();
        this->currentIndex = 0;
    }
    Data& getNext() {
        if (currentIndex == vector.size() - 1) {
            currentIndex = 0;
            return vector[currentIndex];
        }
        else {
            currentIndex++;
            return vector[currentIndex];
        }
    }

    Data& getPrevious() {
        if (currentIndex == 0) {
            currentIndex = vector.size() - 1;
            return vector[currentIndex];
        }
        else {
            currentIndex--;
            return vector[currentIndex];
        }
    }

    bool empty() {
        return vector.empty();
    }

    size_t getCurrentIndex() {
        return this->currentIndex;
    }
    Carousel(std::pair<std::_Rb_tree_iterator<std::pair<MenuCase *const, MenuCase *>>,
             std::_Rb_tree_iterator<std::pair<MenuCase *const, MenuCase *>>> pair1, size_t currentIndex = 0) {
        this->currentIndex = currentIndex;
        for (auto it = pair1.first; it != pair1.second; it++) {
            this->append(it->second);
        }
    }
};

#endif //BOCCHI_CAROUSEL_H
