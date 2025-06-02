#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "main.cpp"
#include <sstream>
#include <iostream>

class Dragon {
public:
    std::string name;
    int tail_length;
};

TEST_CASE("Dragon: Class definition and initialization") {
    SECTION("Type checks") {
        Dragon d;
        REQUIRE(std::is_same<decltype(d.name), std::string>::value);
    }

    SECTION("Direct initialization") {
        Dragon d{"Lily", 250};
        REQUIRE(d.name == "Lily");
        REQUIRE(d.tail_length == 250);
    }

    SECTION("Field assignment") {
        Dragon d;
        d.name = "Toothless";
        d.tail_length = 17;
        REQUIRE(d.name == "Toothless");
        REQUIRE(d.tail_length == 17);
    }
}


TEST_CASE("Basic dragon creation and output") {
    Dragon d;
    d.name = "Toothless";
    d.tail_length = 17;
    
    std::ostringstream output;
    output << "Dragon " << d.name << " has a tail of " << d.tail_length << " meter(s)";
    
    REQUIRE(output.str() == "Dragon Toothless has a tail of 17 meter(s)");
}

TEST_CASE("Input/output simulation") {
    SECTION("Normal case") {
        std::istringstream input("Kitty 350");
        std::ostringstream output;
        
        Dragon d;
        input >> d.name >> d.tail_length;
        output << "Dragon " << d.name << " has a tail of " << d.tail_length << " meter(s)";
        
        REQUIRE(output.str() == "Dragon Kitty has a tail of 350 meter(s)");
    }
    
    SECTION("Minimum tail length") {
        std::istringstream input("MiniDragon 1");
        Dragon d;
        input >> d.name >> d.tail_length;
        output << "Dragon " << d.name << " has a tail of " << d.tail_length << " meter(s)";
        
        REQUIRE(output.str() == "Dragon MiniDragon has a tail of 1 meter(s)");
    }
    
    SECTION("Maximum tail length") {
        std::istringstream input("BigDragon 1000");
        Dragon d;
        input >> d.name >> d.tail_length;
        output << "Dragon " << d.name << " has a tail of " << d.tail_length << " meter(s)";
        
        REQUIRE(output.str() == "Dragon BigDragon has a tail of 1000 meter(s)");
    }
    
    SECTION("Name with numbers") {
        std::istringstream input("Dragon123 500");
        Dragon d;
        input >> d.name >> d.tail_length;
        output << "Dragon " << d.name << " has a tail of " << d.tail_length << " meter(s)";
        
        REQUIRE(output.str() == "Dragon Dragon123 has a tail of 500 meter(s)");
    }
}
