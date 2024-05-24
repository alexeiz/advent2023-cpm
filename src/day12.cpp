/// Hot springs.
/// https://adventofcode.com/2023/day/12

#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day12.hpp"

namespace std {
bool operator<(span<int> const & lhs, span<int> const & rhs)
{
    return lexicographical_compare(lhs.begin(), lhs.end(),
                                   rhs.begin(), rhs.end());
}
}  // namespace std

using namespace std;

namespace {
using key_t = tuple<string_view, int, span<int>>;
using cache_t = map<key_t, uint64_t>;

uint64_t count_arrangement(string_view rec, int cur_gr, span<int> groups, cache_t & results)
{
    auto cache_result = [&](auto res) {
        results[{rec, cur_gr, groups}] = res;
        return res;
    };

    if (rec.empty())
        return (groups.empty() && !cur_gr) || (size(groups) == 1 && groups.front() == cur_gr);

    if (auto pos = results.find({rec, cur_gr, groups}); pos != results.end())
        return pos->second;

    auto term_group = [&] {
        if (!cur_gr)
            return count_arrangement(rec.substr(1), cur_gr, groups, results);

        if (groups.empty() || groups.front() != cur_gr)
            return 0lu;

        return count_arrangement(rec.substr(1), 0, groups.subspan(1), results);
    };

    auto extend_group = [&] {
        return count_arrangement(rec.substr(1), cur_gr + 1, groups, results);
    };

    if (rec.front() == '.')  // terminate current group
        return cache_result(term_group());

    if (rec.front() == '#')  // extend current group
        return cache_result(extend_group());

    assert(rec.front() == '?');  // uncertain
    return cache_result(term_group() + extend_group());
}

puzzle_reg _1{"12.1", []{
    using namespace day12;

    uint64_t arrangements = 0;
    for (auto && s: springs)
    {
        cache_t results;
        arrangements += count_arrangement(s.first, 0, {begin(s.second), end(s.second)}, results);
    }

    fmt::println(cout, "total hot spring arrangements: {}", arrangements);
}};

puzzle_reg _2{"12.2", []{
    using namespace day12;

    int rep = 5;  // repeat input this number of times
    uint64_t arrangements = 0;
    for (auto && s: springs)
    {
        string rec = fmt::format("{}", fmt::join(vector(rep, s.first), "?"));
        vector<int> groups;
        for (int i = 0; i != rep; ++i)
            ranges::copy(s.second, back_inserter(groups));

        cache_t results;
        arrangements += count_arrangement(rec, 0, {begin(groups), end(groups)}, results);
    }

    fmt::println(cout, "total hot spring arrangements: {}", arrangements);
}};
}
