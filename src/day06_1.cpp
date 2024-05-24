#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day06.hpp"

using namespace std;

namespace {
/// Number of ways to win the race.
/// https://adventofcode.com/2023/day/6
puzzle_reg _{"6.1", []{
    using namespace day6;

    int win_comb = 1;
    int race_len = ssize(race_dur);
    double eps = 1e-6;

    for (int i = 0; i != race_len; ++i)
    {
        double t = race_dur[i];
        double d = race_rec[i];
        double sdisc = sqrt(t * t - 4 * d);
        win_comb *= int(floor((t + sdisc) / 2 - eps)) - int(ceil((t - sdisc) / 2 + eps)) + 1;
    }

    fmt::print(cout, "total win combinations: {}\n", win_comb);
}};
}
