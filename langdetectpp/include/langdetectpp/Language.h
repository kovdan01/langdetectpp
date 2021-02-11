#pragma once

#include <langdetectpp/export.h>

#include <string>

namespace langdetectpp
{

enum class Language
{
    AF,
    AR,
    BG,
    BN,
    CA,
    CS,
    CY,
    DA,
    DE,
    EL,
    EN,
    ES,
    ET,
    FA,
    FI,
    FR,
    GU,
    HE,
    HI,
    HR,
    HU,
    ID,
    IT,
    JA,
    KN,
    KO,
    LT,
    LV,
    MK,
    ML,
    MR,
    NE,
    NL,
    NO,
    PA,
    PL,
    PT,
    RO,
    RU,
    SK,
    SL,
    SO,
    SQ,
    SV,
    SW,
    TA,
    TE,
    TH,
    TL,
    TR,
    UK,
    UNKNOWN,
    UR,
    VI,
    ZH_CN,
    ZH_TW,
};

std::string LANGDETECTPP_EXPORT stringOfLanguage(Language lang);

std::string LANGDETECTPP_EXPORT englishNameOfLanguage(Language lang);

} // langdetectpp
