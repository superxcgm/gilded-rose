//
// Created by Yujia Li  on 2020/6/7.
//

#include <cstddef>
#include "commodity.h"

int Commodity::GetSellIn() {
    return 0;
}

int Commodity::GetQuality() {
    return 0;
}

Commodity::Commodity() : sell_in_(0), quality_(0) {}

Commodity::Commodity(int sell_in, size_t quality) : sell_in_(sell_in) {
    if (quality > 50) {
        throw IllegalQuality(quality);
    }

    quality_ = quality;
}
