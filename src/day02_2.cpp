#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day02.hpp"

using namespace std;

namespace {
/// Play cubes game.
/// https://adventofcode.com/2023/day/2
puzzle_reg _{"2.2", []{
    auto const & games = day2::games;
    int power_tot = 0;

    for (auto && game: games)
    {
        array<int, day2::colors_count> min_cubes{};

        for (auto && grab: game)
        {
            for (auto && [num, color]: grab)
                min_cubes[color] = max(min_cubes[color], num);
        }

        power_tot += ranges::fold_left(min_cubes, 1, multiplies<int>{});
    }

    fmt::print(cout, "games power: {}\n", power_tot);
}};
}
