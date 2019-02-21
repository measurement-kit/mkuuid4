// Part of Measurement Kit <https://measurement-kit.github.io/>.
// Measurement Kit is free software under the BSD license. See AUTHORS
// and LICENSE for more information on the copying conditions.
// =============================================================
// Derivative work of github.com/r-lyeh/sole@c61c49f10d.
//
// Portions Copyright (c) 2015 r-lyeh (https://github.com/r-lyeh)
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgment in the product documentation would be
// appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
#ifndef MEASUREMENT_KIT_MKUUID4_HPP
#define MEASUREMENT_KIT_MKUUID4_HPP

#include <string>

namespace mk {
namespace uuid4 {

/// gen generates a new uuid4 as a string.
std::string gen() noexcept;

} // namespace uuid4
} // namespace mk

// If you just want to know about the API, you can stop reading here. What
// follows is the inline implementation of the library. By default it is not
// included when you include the header, but you can change this.
#ifdef MKUUID4_INLINE_IMPL

#include <stdint.h>

#include <iomanip>
#include <random>
#include <sstream>

namespace mk {
namespace uuid4 {

// sole contains the code forked from <github.com/r-lyeh/sole@c61c49f10d>.
namespace sole {

// UUID contains a UUID
class UUID {
 public:
  // str generates a string representation of a UUID
  std::string str() const noexcept;

  // ab contains the A and B components of the UUID
  uint64_t ab;

  // cd contains the C and D components of the UUID
  uint64_t cd;
};

std::string UUID::str() const noexcept {
  std::stringstream ss;
  ss << std::hex << std::nouppercase << std::setfill('0');

  uint32_t a = (uint32_t)((ab >> 32) & 0xFFFFFFFF);
  uint32_t b = (ab & 0xFFFFFFFF);
  uint32_t c = (uint32_t)((cd >> 32) & 0xFFFFFFFF);
  uint32_t d = (cd & 0xFFFFFFFF);

  ss << std::setw(8) << (a) << '-';
  ss << std::setw(4) << (b >> 16) << '-';
  ss << std::setw(4) << (b & 0xFFFF) << '-';
  ss << std::setw(4) << (c >> 16) << '-';
  ss << std::setw(4) << (c & 0xFFFF);
  ss << std::setw(8) << d;

  return ss.str();
}

// uuid4 generates a UUID4 UUID
static UUID uuid4() noexcept {
  std::random_device rd;
  std::uniform_int_distribution<uint64_t> dist(0, (uint64_t)(~0));
  UUID my;

  my.ab = dist(rd);
  my.cd = dist(rd);

  /* The version 4 UUID is meant for generating UUIDs from truly-random or
       pseudo-random numbers.

       The algorithm is as follows:

       o  Set the four most significant bits (bits 12 through 15) of the
          time_hi_and_version field to the 4-bit version number from
          Section 4.1.3.

       o  Set the two most significant bits (bits 6 and 7) of the
          clock_seq_hi_and_reserved to zero and one, respectively.

       o  Set all the other bits to randomly (or pseudo-randomly) chosen
          values.

       See <https://tools.ietf.org/html/rfc4122#section-4.4>. */
  my.ab = (my.ab & 0xFFFFFFFFFFFF0FFFULL) | 0x0000000000004000ULL;
  my.cd = (my.cd & 0x3FFFFFFFFFFFFFFFULL) | 0x8000000000000000ULL;

  return my;
}

}  // namespace sole

std::string gen() noexcept { return sole::uuid4().str(); }

}  // namespace uuid4
}  // namespace mk
#endif  // MKUUID4_INLINE_IMPL
#endif  // MEASUREMENT_KIT_MKUUID4_HPP
