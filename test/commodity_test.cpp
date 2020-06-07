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

TEST(Commodity, should_throw_exception_when_init_commodity_with_quality_greater_than_50) {
    EXPECT_THROW(new Commodity(0, Commodity::kMaxQuality + 1), Commodity::IllegalQuality);
}

TEST(Commodity, should_reduce_quality_1_after_1_day) {
    int init_sell_in = 3;
    int init_quality = 4;
    Commodity commodity(init_sell_in, init_quality);

    commodity.DayAfter();

    EXPECT_THAT(commodity.GetSellIn(), testing::Eq(init_sell_in - 1));
    EXPECT_THAT(commodity.GetQuality(), testing::Eq(init_quality - 1));
}

TEST(Commodity, should_reduce_quality_2_after_1_day_when_expired) {
    int init_sell_in = -1;
    int init_quality = 4;
    Commodity commodity(init_sell_in, init_quality);

    commodity.DayAfter();

    EXPECT_THAT(commodity.GetSellIn(), testing::Eq(init_sell_in - 1));
    EXPECT_THAT(commodity.GetQuality(), testing::Eq(init_quality - 2));
}

TEST(Commodity, should_not_reduce_quality_when_quality_already_0) {
    int init_sell_in = -1;
    int init_quality = 0;
    Commodity commodity(init_sell_in, init_quality);

    commodity.DayAfter();

    EXPECT_THAT(commodity.GetSellIn(), testing::Eq(init_sell_in - 1));
    EXPECT_THAT(commodity.GetQuality(), testing::Eq(init_quality));
}

TEST(BackstagePass, should_quality_increase_2_in_10_days_before_show_time) {
    int init_sell_in = 10;
    int init_quality = 5;
    BackstagePass back_stage_pass(init_sell_in, init_quality);

    back_stage_pass.DayAfter();

    EXPECT_THAT(back_stage_pass.GetSellIn(), testing::Eq(init_sell_in - 1));
    EXPECT_THAT(back_stage_pass.GetQuality(), testing::Eq(init_quality + 2));
}

TEST(BackstagePass, should_quality_increase_3_in_5_days_before_show_time) {
    int init_sell_in = 5;
    int init_quality = 5;
    BackstagePass back_stage_pass(init_sell_in, init_quality);

    back_stage_pass.DayAfter();

    EXPECT_THAT(back_stage_pass.GetSellIn(), testing::Eq(init_sell_in - 1));
    EXPECT_THAT(back_stage_pass.GetQuality(), testing::Eq(init_quality + 3));
}

TEST(BackstagePass, should_not_increase_quality_when_quality_reach_50) {
    int init_sell_in = 5;
    int init_quality = 50;
    BackstagePass back_stage_pass(init_sell_in, init_quality);

    back_stage_pass.DayAfter();

    EXPECT_THAT(back_stage_pass.GetSellIn(), testing::Eq(init_sell_in - 1));
    EXPECT_THAT(back_stage_pass.GetQuality(), testing::Eq(init_quality));
}