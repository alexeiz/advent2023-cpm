#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day04.hpp"

using namespace std;

namespace {
/// Find scratchcards winning numbers.
/// https://adventofcode.com/2023/day/4
puzzle_reg _{"4.1", []{
    using day4::cards;

    int points_tot = 0;

    for (auto const & [wins, nums]: cards)
    {
        int points = 0;
        for (auto n: nums)
        {
            if (wins.contains(n))
                points = points ? points << 1 : 1;
        }

        points_tot += points;
    }

    fmt::print(cout, "total points: {}\n", points_tot);
}};
}
