#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day05.hpp"

#include <boost/icl/interval_set.hpp>
#include <boost/icl/interval_map.hpp>

using namespace std;
using namespace boost;

namespace {
/// Map seeds to location.
/// https://adventofcode.com/2023/day/5
puzzle_reg _{"5.2", []{
    using namespace day5;

    icl::interval_set<ssize_t> seed_ranges;
    for (int i = 0; i < ssize(seeds); i += 2)
        seed_ranges.add({seeds[i], seeds[i] + seeds[i + 1]});

    for (auto && ct: categories)
    {
        icl::interval_map<ssize_t, ssize_t> cat_map;
        icl::interval_set<ssize_t> cat_set;
        for (auto && rg: ct.get())
        {
            cat_map.add({{rg.src, rg.src + rg.len}, ssize_t{rg.dst} - rg.src});
            cat_set.add({rg.src, rg.src + rg.len});
        }

        auto seed_map = cat_map & seed_ranges;
        icl::interval_set<ssize_t> mapped_ranges;
        for (auto && [r, s]: seed_map)
            mapped_ranges.add({r.lower() + s, r.upper() + s});

        mapped_ranges += seed_ranges - cat_set;
        seed_ranges.swap(mapped_ranges);
    }

    fmt::print(cout, "lowest seed location: {}\n", seed_ranges.begin()->lower());
}};
}
