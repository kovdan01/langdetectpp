#pragma once

#include <langdetectpp/export.h>
#include <langdetectpp/Language.h>

#include <memory>

namespace langdetectpp
{

namespace detection
{

class DetectorImpl;

}  // namespace detection

class LANGDETECTPP_EXPORT Detector
{
protected:
    std::unique_ptr<detection::DetectorImpl> pImpl_;
    Detector(std::unique_ptr<detection::DetectorImpl>);

public:
    Language detect(const std::string&);
    static std::shared_ptr<Detector> create();
};

}  // namespace langdetectpp
