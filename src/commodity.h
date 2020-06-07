//
// Created by Yujia Li  on 2020/6/7.
//

#ifndef GILDED_ROSE_COMMODITY_H
#define GILDED_ROSE_COMMODITY_H

#include <string>

class Commodity {
    int sell_in_;
    size_t quality_;

public:
    int GetSellIn();

    int GetQuality();

    Commodity();

    Commodity(int sell_in, size_t quality);

    class IllegalQuality : public std::runtime_error {
    public:
        explicit IllegalQuality(size_t quality) : std::runtime_error(
                "quality should between 0 and " + std::to_string(kMaxQuality) + ", while " + std::to_string(quality) + " is given.") {}
    };

    static constexpr size_t kMaxQuality{50};

    void DayAfter();
};


#endif //GILDED_ROSE_COMMODITY_H
