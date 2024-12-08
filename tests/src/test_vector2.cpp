#include <gtest/gtest.h>
#include <walle-lib/vector2.hpp>

// Validates the behavior of the constructors
TEST(Vector2, test_constructor) {
  Vector2 v;

  EXPECT_NEAR(v.x(), 0.0, 0.00001);
  EXPECT_NEAR(v.y(), 0.0, 0.00001);
}

TEST(Vector2, test_operator_plus_equal) {
  Vector2 v1(1, 2);
  Vector2 v2(3, 4);

  v1 += v2;

  EXPECT_NEAR(v1.x(), 4.0, 0.00001);
  EXPECT_NEAR(v1.y(), 6.0, 0.00001);
}

TEST(Vector2, test_operator_minus_equal) {
  Vector2 v1(1, 2);
  Vector2 v2(3, 4);

  v1 -= v2;

  EXPECT_NEAR(v1.x(), -2.0, 0.00001);
  EXPECT_NEAR(v1.y(), -2.0, 0.00001);
}
