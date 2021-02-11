cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(langdetectpp
        VERSION 0.0.0
        LANGUAGES CXX
)

# folly facebook
find_package(Folly REQUIRED)

# boost asio
find_package(
    Boost 1.67.0 REQUIRED
    COMPONENTS filesystem system thread
)

# thread support
set(THREADS_PREFER_PTHERAD_FLAG ON)
find_package(Threads REQUIRED)

set(LIB_SOURCES
    src/Language.cpp
    src/Detector.cpp
    src/profiles/Profile.cpp
    src/profiles/ProfileGroup.cpp
    src/detection/DetectionRunner.cpp
    src/ngrams/NGramExtractor.cpp
    src/profiles/langs/af.cpp
    src/profiles/langs/ar.cpp
    src/profiles/langs/bg.cpp
    src/profiles/langs/bn.cpp
    src/profiles/langs/ca.cpp
    src/profiles/langs/cs.cpp
    src/profiles/langs/cy.cpp
    src/profiles/langs/da.cpp
    src/profiles/langs/de.cpp
    src/profiles/langs/el.cpp
    src/profiles/langs/en.cpp
    src/profiles/langs/es.cpp
    src/profiles/langs/et.cpp
    src/profiles/langs/fa.cpp
    src/profiles/langs/fi.cpp
    src/profiles/langs/fr.cpp
    src/profiles/langs/gu.cpp
    src/profiles/langs/he.cpp
    src/profiles/langs/hi.cpp
    src/profiles/langs/hr.cpp
    src/profiles/langs/hu.cpp
    src/profiles/langs/id.cpp
    src/profiles/langs/it.cpp
    src/profiles/langs/ja.cpp
    src/profiles/langs/kn.cpp
    src/profiles/langs/ko.cpp
    src/profiles/langs/lt.cpp
    src/profiles/langs/lv.cpp
    src/profiles/langs/mk.cpp
    src/profiles/langs/ml.cpp
    src/profiles/langs/mr.cpp
    src/profiles/langs/ne.cpp
    src/profiles/langs/nl.cpp
    src/profiles/langs/no.cpp
    src/profiles/langs/pa.cpp
    src/profiles/langs/pl.cpp
    src/profiles/langs/pt.cpp
    src/profiles/langs/ro.cpp
    src/profiles/langs/ru.cpp
    src/profiles/langs/sk.cpp
    src/profiles/langs/sl.cpp
    src/profiles/langs/so.cpp
    src/profiles/langs/sq.cpp
    src/profiles/langs/sv.cpp
    src/profiles/langs/sw.cpp
    src/profiles/langs/ta.cpp
    src/profiles/langs/te.cpp
    src/profiles/langs/th.cpp
    src/profiles/langs/tl.cpp
    src/profiles/langs/tr.cpp
    src/profiles/langs/uk.cpp
    src/profiles/langs/ur.cpp
    src/profiles/langs/vi.cpp
    src/profiles/langs/zh_cn.cpp
    src/profiles/langs/zh_tw.cpp
)

add_library(${PROJECT_NAME}
    ${LIB_SOURCES}
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../3rd-party/mirror_utf8cpp/source
    src
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Boost::filesystem
    Boost::system
    Boost::thread
    Folly::folly
    Threads::Threads
)

ntc_target(${PROJECT_NAME})
