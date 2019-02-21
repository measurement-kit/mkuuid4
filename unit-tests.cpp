#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <regex>

#include "mkuuid4.hpp"

TEST_CASE("gen works as expected") {
  auto uuid4 = mk::uuid4::gen();
  std::clog << uuid4 << std::endl;
  std::regex expect{
      "^[a-f0-9]{8}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{12}$"};
  std::smatch smatch;
  REQUIRE(std::regex_match(uuid4, smatch, expect) == true);
}
