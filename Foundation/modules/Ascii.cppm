module;

#define POCO_ENABLE_MODULES

#include "Ascii.cpp"

export module poco.foundation:ascii;


export namespace Poco
{
	using Poco::Ascii;

	using Poco::Ascii::CharacterProperties::ACP_CONTROL;
	using Poco::Ascii::CharacterProperties::ACP_SPACE;
	using Poco::Ascii::CharacterProperties::ACP_PUNCT;
	using Poco::Ascii::CharacterProperties::ACP_DIGIT;
	using Poco::Ascii::CharacterProperties::ACP_HEXDIGIT;
	using Poco::Ascii::CharacterProperties::ACP_ALPHA;
	using Poco::Ascii::CharacterProperties::ACP_LOWER;
	using Poco::Ascii::CharacterProperties::ACP_UPPER;
	using Poco::Ascii::CharacterProperties::ACP_GRAPH;
	using Poco::Ascii::CharacterProperties::ACP_PRINT;
}
