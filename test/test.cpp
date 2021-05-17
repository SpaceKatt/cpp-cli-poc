// Copyright 2021 Thomas Kercehval
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("sample test case", "[second field]") {
    REQUIRE(1 == 1);
}
