#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <regex>

#include "mkuuid4.hpp"

TEST_CASE("gen generates a valid UUID4") {
  auto uuid4 = mk::uuid4::gen();
  std::clog << uuid4 << std::endl;
  std::regex expect{
      "^[a-f0-9]{8}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{12}$"};
  std::smatch smatch;
  REQUIRE(std::regex_match(uuid4, smatch, expect) == true);
}

TEST_CASE("subsequent gen runs generate different UUID4s") {
  REQUIRE(mk::uuid4::gen() != mk::uuid4::gen());
}
