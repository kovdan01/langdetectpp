#pragma once
#include <array>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

#include "ngrams/ExtractedNGrams.h"
#include "utf8.h"
#include "util/CircleArray.h"

namespace langdetectpp::ngrams
{

class NGramExtractor
{
protected:
    const char* iter_ {nullptr};
    const char* end_ {nullptr};
    const std::string& textRef_;
    util::CircleArray<std::uint32_t, 3> codePoints_;
    std::vector<std::uint32_t> oneGrams_;
    std::vector<std::tuple<std::uint32_t, std::uint32_t>> bigrams_;
    std::vector<std::tuple<std::uint32_t, std::uint32_t, std::uint32_t>> trigrams_;
    bool advance();

public:
    NGramExtractor(const std::string& text);
    bool good();
    ExtractedNGrams extract();
};

}  // namespace langdetectpp::ngrams
