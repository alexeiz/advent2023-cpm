#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day11.hpp"

using namespace std;

namespace {
/// Distance between galaxies.
/// https://adventofcode.com/2023/day/11
puzzle_reg _{"11.1", []{
    using namespace day11;

    int ux = ssize(universe);
    int uy = strlen(universe[0]);

    vector<int> expanx(ux);
    vector<int> expany(uy);
    vector<pair<int, int>> galaxies;

    // find galaxies and measure expansion
    for (int ex = 0, i = 0; i != ux; ++i)
    {
        bool found_galaxy = false;
        for (int j = 0; j != uy; ++j)
        {
            if (universe[i][j] == '#')
            {
                found_galaxy = true;
                galaxies.emplace_back(i, j);
            }
        }

        if (!found_galaxy)
            ++ex;
        expanx[i] = ex;
    }

    for (int ex = 0, j = 0; j != uy; ++j)
    {
        for (int i = 0; i != ux; ++i)
            if (universe[i][j] == '#')
                goto skip;

        ++ex;
    skip:
        expany[j] = ex;
    }

    // compute total distance between galaxies after expansion
    int dist_tot = 0;
    for (int i = 0; i != ssize(galaxies); ++i)
        for (int j = i + 1; j != ssize(galaxies); ++j)
        {
            dist_tot += abs((galaxies[i].first  + expanx[galaxies[i].first ]) - (galaxies[j].first  + expanx[galaxies[j].first ]))
                      + abs((galaxies[i].second + expany[galaxies[i].second]) - (galaxies[j].second + expany[galaxies[j].second]));
        }

    fmt::print(cout, "total distance between galaxies: {}\n", dist_tot);
}};
}
