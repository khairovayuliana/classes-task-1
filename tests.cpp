#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "main.cpp"

TEST_CASE("Point: Structure definition and initialization") {
    Point p;
    REQUIRE(sizeof(p.x) == sizeof(double));
    REQUIRE(sizeof(p.y) == sizeof(double));
}

TEST_CASE("Point: Input and output") {
    SECTION("Simple values") {
        Point p;
        std::istringstream input("4.93 5.51");
        std::ostringstream output;
        
        input >> p.x >> p.y;
        output << p.x << " " << p.y;
        
        REQUIRE(output.str() == "4.93 5.51");
    }

    SECTION("Negative values") {
        Point p;
        std::istringstream input("-2.5 3.75");
        std::ostringstream output;
        
        input >> p.x >> p.y;
        output << p.x << " " << p.y;
        
        REQUIRE(output.str() == "-2.5 3.75");
    }

    SECTION("Zero values") {
        Point p;
        std::istringstream input("0 0");
        std::ostringstream output;
        
        input >> p.x >> p.y;
        output << p.x << " " << p.y;
        
        REQUIRE(output.str() == "0 0");
    }

    SECTION("Large values") {
        Point p;
        std::istringstream input("123456.789 -987654.321");
        std::ostringstream output;
        
        input >> p.x >> p.y;
        output << p.x << " " << p.y;
        
        REQUIRE(output.str() == "123456.789 -987654.321");
    }
}

TEST_CASE("Point: Precision check") {
    Point p;
    std::istringstream input("3.1415926535 2.7182818284");
    std::ostringstream output;
    
    input >> p.x >> p.y;
    output << std::fixed << std::setprecision(10) << p.x << " " << p.y;
    
    REQUIRE(output.str() == "3.1415926535 2.7182818284");
}
