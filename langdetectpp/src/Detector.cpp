#include <memory>
#include <string>

#include "detection/DetectorImpl.h"
#include "profiles/ProfileGroup.h"
#include <langdetectpp/Detector.h>
#include <langdetectpp/Language.h>

using langdetectpp::detection::DetectorImpl;
using langdetectpp::profiles::ProfileGroup;

namespace langdetectpp
{

Detector::Detector(std::unique_ptr<DetectorImpl> pImpl)
    : pImpl_(std::move(pImpl))
{
}

Language Detector::detect(const std::string& text) { return pImpl_->detect(text); }

std::shared_ptr<Detector> Detector::create()
{
    auto profGroup = ProfileGroup::create();
    std::unique_ptr<DetectorImpl> pImpl(new DetectorImpl(profGroup));
    return std::shared_ptr<Detector>(new Detector(std::move(pImpl)));
}

}  // namespace langdetectpp
