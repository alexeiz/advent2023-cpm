#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day06.hpp"

using namespace std;

namespace {
/// Number of ways to win the race.
/// https://adventofcode.com/2023/day/6
puzzle_reg _{"6.2", []{
    using namespace day6;
    using ldouble = long double;
    using lint = long long;

    auto digits = [](int n) -> int {
        int i = 0;
        for (; n != 0; ++i, n /= 10)
            ;
        return i;
    };

    auto shift = [](lint n, int s) -> lint {
        for (int i = 0; i != s; ++i, n *= 10)
            ;
        return n;
    };

    lint dur = 0;
    for (auto d: race_dur)
        dur = shift(dur, digits(d)) + d;

    lint rec = 0;
    for (auto r: race_rec)
        rec = shift(rec, digits(r)) + r;

    ldouble eps = 1e-6;
    ldouble sdisc = sqrt(ldouble(dur) * dur - 4 * rec);
    auto win_comb = lint(floor((dur + sdisc) / 2 - eps)) - lint(ceil((dur - sdisc) / 2 + eps)) + 1;

    fmt::print(cout, "total win combinations: {}\n", win_comb);
}};
}
