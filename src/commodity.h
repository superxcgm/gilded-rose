//
// Created by Yujia Li  on 2020/6/7.
//

#ifndef GILDED_ROSE_COMMODITY_H
#define GILDED_ROSE_COMMODITY_H


class Commodity {
    int sell_in_;
    size_t quality_;

public:
    int GetSellIn();
    int GetQuality();

    Commodity();
};


#endif //GILDED_ROSE_COMMODITY_H
