#define CATCH_CONFIG_DISABLE_EXCEPTIONS
#include "catch.hpp"

#include <fstream>
#include <string>

#include "utils.hpp"

TEST_CASE("Test util functions", "[test]") {
    std::string username, gold, tmp;

    // Prepare the data.
    std::ofstream outfile;
    outfile.open("testfile.txt");
    outfile << "bobcat\n";
    outfile << "0\n0\n100\nno\nno\nno\n0\nno\n0\n0\n";
    outfile.close();

    // Call the target function.
    replace("bobcat", "gold", "99");

    // Test if it operate correctly.
    std::ifstream infile;
    infile.open("testfile.txt");
    infile >> username;
    infile >> tmp;
    infile >> gold;
    infile.close();

    REQUIRE(username == "bobcat");
    REQUIRE(gold == "99");
}
