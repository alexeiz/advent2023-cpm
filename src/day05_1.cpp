#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day05.hpp"

using namespace std;

namespace {
/// Map seeds to location.
/// https://adventofcode.com/2023/day/5
puzzle_reg _{"5.1", []{
    using namespace day5;

    auto lowest_loc = numeric_limits<unsigned>::max();
    for (auto s: seeds)
    {
        for (auto const & cat: categories)
            s = cat(s);

        lowest_loc = min(lowest_loc, s);
    }

    fmt::print(cout, "lowest seed location: {}\n", lowest_loc);
}};
}
