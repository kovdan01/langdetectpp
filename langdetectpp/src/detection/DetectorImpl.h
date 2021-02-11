#pragma once

#include "detection/DetectionRunner.h"
#include "ngrams/NGramExtractor.h"
#include "profiles/ProfileGroup.h"
#include <langdetectpp/Language.h>
#include <memory>

namespace langdetectpp::detection
{

class DetectorImpl
{
protected:
    std::shared_ptr<profiles::ProfileGroup> profileGroup_;

public:
    DetectorImpl(std::shared_ptr<profiles::ProfileGroup> profileGroup)
        : profileGroup_(profileGroup)
    {
    }
    Language detect(const std::string& text)
    {
        ngrams::NGramExtractor extractor(text);
        auto extracted = extractor.extract();
        DetectionRunner runner(profileGroup_, extracted);
        return runner.detect();
    }
};

}  // namespace langdetectpp::detection
