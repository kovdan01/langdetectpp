#pragma once
#include "profiles/Profile.h"
#include <folly/Hash.h>
#include <memory>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace langdetectpp::profiles
{

class ProfileGroup
{
protected:
    ProfileGroup() { }

public:
    std::vector<std::shared_ptr<Profile>> profiles;
    std::unordered_map<std::uint32_t, std::vector<double>> oneGramWeights;
    std::unordered_map<std::tuple<std::uint32_t, std::uint32_t>, std::vector<double>> bigramWeights;
    std::unordered_map<std::tuple<std::uint32_t, std::uint32_t, std::uint32_t>, std::vector<double>> trigramWeights;

    static std::shared_ptr<ProfileGroup> create();
};

}  // namespace langdetectpp::profiles
