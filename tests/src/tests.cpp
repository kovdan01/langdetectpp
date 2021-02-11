#include <cassert>
#include <sstream>
#include <string>

#include <folly/Conv.h>
#include <folly/FileUtil.h>
#include <folly/Format.h>
#include <folly/Hash.h>
#include <iostream>
#include <memory>
#include <tuple>
#include <unordered_map>
#include <vector>

#include <boost/filesystem.hpp>
#include <glog/logging.h>
#include <langdetectpp/langdetectpp.h>

namespace bfs = boost::filesystem;
using langdetectpp::Language;

int main()
{
    std::vector<std::pair<std::string, Language>> files =
    {
        {"ar_from_wikipedia.txt", Language::AR},
        {"en_jezebel.txt", Language::EN},
        {"ru_from_wikipedia.txt", Language::RU},
        {"de_from_wikipedia.txt", Language::DE},
        {"fr_from_wikipedia.txt", Language::FR},
        {"es_from_wikipedia.txt", Language::ES}
    };

    std::size_t maxLen = 0;
    for (auto& elem : files)
    {
        auto fname = elem.first;
        if (fname.size() > maxLen)
        {
            maxLen = fname.size();
        }
    }
    auto detector = langdetectpp::Detector::create();
    bfs::path basePath = bfs::canonical("./../text");
    for (auto& elem : files)
    {
        std::string fname = elem.first;
        bfs::path filePath = basePath / fname;
        std::string strPath = filePath.string();
        std::string data;
        folly::readFile(strPath.c_str(), data);
        // LOG(INFO) << data;
        auto lang = detector->detect(data);

        std::ostringstream logLine;
        logLine << fname;
        for (std::size_t i = fname.size(); i < maxLen; i++)
        {
            logLine << " ";
        }
        LOG(INFO) << logLine.str() << "  ->  "
                  << langdetectpp::englishNameOfLanguage(lang);
        assert(elem.second == lang);
    }
}
