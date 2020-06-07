//
// Created by Yujia Li  on 2020/6/7.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <commodity.h>

TEST(Commodity, commodity_should_have_sell_in_and_quality) {
    Commodity commodity;

    EXPECT_THAT(commodity.GetSellIn(), testing::Eq(0));
    EXPECT_THAT(commodity.GetQuality(), testing::Eq(0));
}