module;

#define POCO_ENABLE_MODULES

//extern "C"
//{
//#include "pcre2_auto_possess.c"
//#include "pcre2_chartables.c"
//#include "pcre2_compile.c"
//#include "pcre2_config.c"
//#include "pcre2_context.c"
//#include "pcre2_convert.c"
//#include "pcre2_dfa_match.c"
//#include "pcre2_error.c"
//#include "pcre2_extuni.c"
//#include "pcre2_find_bracket.c"
//#include "pcre2_jit_compile.c"
//#include "pcre2_jit_match.c"
//#include "pcre2_jit_misc.c"
//#include "pcre2_maketables.c"
//#include "pcre2_match.c"
//#include "pcre2_match_data.c"
//#include "pcre2_newline.c"
//#include "pcre2_ord2utf.c"
//#include "pcre2_pattern_info.c"
//#include "pcre2_script_run.c"
//#include "pcre2_serialize.c"
//#include "pcre2_string_utils.c"
//#include "pcre2_study.c"
//#include "pcre2_substitute.c"
//#include "pcre2_substring.c"
//#include "pcre2_tables.c"
//#include "pcre2_ucd.c"
//#include "pcre2_ucptables.c"
//#include "pcre2_valid_utf.c"
//#include "pcre2_xclass.c"
//}

#include "RegularExpression.cpp"

export module poco.foundation:RegularExpression;

export namespace Poco
{
    export using Poco::RegularExpression;
}
