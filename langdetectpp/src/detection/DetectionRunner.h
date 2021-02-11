#pragma once
#include "ngrams/ExtractedNGrams.h"
#include "profiles/Profile.h"
#include "util/stats.h"
#include <langdetectpp/Language.h>
#include <memory>
#include <tuple>
#include <vector>

namespace langdetectpp::detection
{

class DetectionRunner
{
protected:
    std::shared_ptr<profiles::ProfileGroup> profileGroup_;
    ngrams::ExtractedNGrams& textNGrams_;
    std::vector<double> langScores_;
    util::UniformIntDist ngramLengthDist_ {1, 3};
    util::Alpha alpha_ {0.5, 0.05};
    std::vector<double> runTrial();
    Language getBestScore();
    std::vector<double>* getLanguageScoresForRandomNGramOrNull();

public:
    DetectionRunner(
        std::shared_ptr<profiles::ProfileGroup>,
        ngrams::ExtractedNGrams&);
    Language detect();
};

}  // namespace langdetectpp::detection
