#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>

#include "mkuuid4.hpp"

SECTION("gen works as expected") {
  auto uuid4 = mk::uuid4::gen();
  std::clog << uuid4 << std::endl;
}
