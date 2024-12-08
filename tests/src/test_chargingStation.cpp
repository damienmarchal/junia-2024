#include <gtest/gtest.h>
#include <walle-lib/chargingStation.hpp>

TEST(ChargingStation, test_attach)
{
    ChargingStation cs;
    Robot r;
    r.set_battery(0);
    cs.set_position(0, 0);
    r.set_position(0, 0.2);
    EXPECT_EQ(cs.attach(&r), 0);
    cs.update(1);
    EXPECT_NEAR(r.get_battery(), ChargingStationProperties::REFUEL_RATE, 0.00001);    
}