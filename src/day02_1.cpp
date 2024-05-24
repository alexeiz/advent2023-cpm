#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day02.hpp"

using namespace std;

namespace {
/// Play cubes game.
/// https://adventofcode.com/2023/day/2
puzzle_reg _{"2.1", []{
    auto const & games = day2::games;
    array<int, 3> max_cubes{12, 13, 14};
    int games_tot = 0;

    for (int i = 0; i != ssize(games); ++i)
    {
        for (auto && grab: games[i])
        {
            for (auto && [num, color]: grab)
            {
                if (max_cubes[color] < num)
                    goto bail;
            }
        }

        games_tot += i + 1;
    bail:
    }

    fmt::print(cout, "games: {}\n", games_tot);
}};
}
