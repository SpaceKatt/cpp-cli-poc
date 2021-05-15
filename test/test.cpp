#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE( "sample test case", "[second field]" ) {
    REQUIRE( 1 == 1 );
}