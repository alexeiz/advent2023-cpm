#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day04.hpp"

using namespace std;

namespace {
/// Find scratchcards winning numbers.
/// https://adventofcode.com/2023/day/4
puzzle_reg _{"4.2", []{
    using day4::cards;

    vector<int> copies(size(cards), 1);

    int card = 0;
    for (auto const & [wins, nums]: cards)
    {
        int matches = 0;
        for (auto n: nums)
            matches += wins.contains(n);

        for (int i = card + 1; i != card + 1 + matches && i < ssize(copies); ++i)
            copies[i] += copies[card];

        ++card;
    }

    int scratchcards_tot = ranges::fold_left(copies, 0, plus<>{});
    fmt::print(cout, "total scratchcards: {}\n", scratchcards_tot);
}};
}
