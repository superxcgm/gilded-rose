//
// Created by Yujia Li  on 2020/6/7.
//

#include <cstddef>
#include "commodity.h"

int Commodity::GetSellIn() {
    return sell_in_;
}

int Commodity::GetQuality() {
    return quality_;
}

Commodity::Commodity() : sell_in_(0), quality_(0) {}

Commodity::Commodity(int sell_in, size_t quality) : sell_in_(sell_in) {
    if (quality > kMaxQuality) {
        throw IllegalQuality(quality);
    }

    quality_ = quality;
}

void Commodity::DayAfter() {
    if (sell_in_ < 0) {
        ReduceQuality();
    }
    ReduceQuality();
    sell_in_--;
}

void Commodity::ReduceQuality() {
    if (quality_ > 0) {
        quality_--;
    }
}

BackstagePass::BackstagePass(int sell_in, int quality) : Commodity(sell_in, quality) {}

void BackstagePass::DayAfter() {
    if (sell_in_ <= 0) {
        quality_ = 0;
    } else {
        if (sell_in_ <= 5) {
            IncreaseQuality();
        }
        IncreaseQuality();
        IncreaseQuality();
    }
    sell_in_--;
}

void BackstagePass::IncreaseQuality() {
    if (quality_ < kMaxQuality) {
        quality_++;
    }
}
