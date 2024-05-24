#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day01.hpp"

using namespace std;

namespace {
/// Fix calibration document.
/// https://adventofcode.com/2023/day/1
puzzle_reg _{"1.1", []{
    auto const & calibration = day1::calibration;

    regex calib2_re{R"((\d).*(\d))"};  // search for 2 digits
    regex calib1_re{R"(\d)"};          // search for 1 digit

    int calib_tot = 0;
    for (auto && line: calibration)
    {
        cmatch m;
        if (regex_search(line, m, calib2_re))
            calib_tot += stoi(m[1].str()) * 10 + stoi(m[2].str());
        else if (regex_search(line, m, calib1_re))
            calib_tot += stoi(m[0].str()) * 11;
    }

    fmt::print(cout, "calibration: {}\n", calib_tot);
}};
}
