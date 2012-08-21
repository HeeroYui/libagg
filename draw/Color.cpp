/**
 *******************************************************************************
 * @file draw/Color.h
 * @brief Ewol Tool Kit : basic colors
 * @author Edouard DUPIN
 * @date 23/04/2012
 * @par Project
 * draw
 *
 * @par Copyright
 * Copyright 2011 Edouard DUPIN, all right reserved
 *
 * This software is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY.
 *
 * Licence summary : 
 *    You can modify and redistribute the sources code and binaries.
 *    You can send me the bug-fix
 *
 * Term of the licence in in the file licence.txt.
 *
 *******************************************************************************
 */

#include <etk/Types.h>
#include <etk/tool.h>
#include <draw/Color.h>
#include <draw/Debug.h>


const draw::Color draw::color::none((uint32_t)0x00000000);
const draw::Color draw::color::aliceBlue((uint32_t)0xF0F8FFFF);
const draw::Color draw::color::antiqueWhite((uint32_t)0xFAEBD7FF);
const draw::Color draw::color::aqua((uint32_t)0x00FFFFFF);
const draw::Color draw::color::aquamarine((uint32_t)0x7FFFD4FF);
const draw::Color draw::color::azure((uint32_t)0xF0FFFFFF);
const draw::Color draw::color::beige((uint32_t)0xF5F5DCFF);
const draw::Color draw::color::bisque((uint32_t)0xFFE4C4FF);
const draw::Color draw::color::black((uint32_t)0x000000FF);
const draw::Color draw::color::blanchedAlmond((uint32_t)0xFFEBCDFF);
const draw::Color draw::color::blue((uint32_t)0x0000FFFF);
const draw::Color draw::color::blueViolet((uint32_t)0x8A2BE2FF);
const draw::Color draw::color::brown((uint32_t)0xA52A2AFF);
const draw::Color draw::color::burlyWood((uint32_t)0xDEB887FF);
const draw::Color draw::color::cadetBlue((uint32_t)0x5F9EA0FF);
const draw::Color draw::color::chartreuse((uint32_t)0x7FFF00FF);
const draw::Color draw::color::chocolate((uint32_t)0xD2691EFF);
const draw::Color draw::color::coral((uint32_t)0xFF7F50FF);
const draw::Color draw::color::cornflowerBlue((uint32_t)0x6495EDFF);
const draw::Color draw::color::cornsilk((uint32_t)0xFFF8DCFF);
const draw::Color draw::color::crimson((uint32_t)0xDC143CFF);
const draw::Color draw::color::cyan((uint32_t)0x00FFFFFF);
const draw::Color draw::color::darkBlue((uint32_t)0x00008BFF);
const draw::Color draw::color::darkCyan((uint32_t)0x008B8BFF);
const draw::Color draw::color::darkGoldenRod((uint32_t)0xB8860BFF);
const draw::Color draw::color::darkGray((uint32_t)0xA9A9A9FF);
const draw::Color draw::color::darkGrey((uint32_t)0xA9A9A9FF);
const draw::Color draw::color::darkGreen((uint32_t)0x006400FF);
const draw::Color draw::color::darkKhaki((uint32_t)0xBDB76BFF);
const draw::Color draw::color::darkMagenta((uint32_t)0x8B008BFF);
const draw::Color draw::color::darkOliveGreen((uint32_t)0x556B2FFF);
const draw::Color draw::color::darkorange((uint32_t)0xFF8C00FF);
const draw::Color draw::color::darkOrchid((uint32_t)0x9932CCFF);
const draw::Color draw::color::darkRed((uint32_t)0x8B0000FF);
const draw::Color draw::color::darkSalmon((uint32_t)0xE9967AFF);
const draw::Color draw::color::darkSeaGreen((uint32_t)0x8FBC8FFF);
const draw::Color draw::color::darkSlateBlue((uint32_t)0x483D8BFF);
const draw::Color draw::color::darkSlateGray((uint32_t)0x2F4F4FFF);
const draw::Color draw::color::darkSlateGrey((uint32_t)0x2F4F4FFF);
const draw::Color draw::color::darkTurquoise((uint32_t)0x00CED1FF);
const draw::Color draw::color::darkViolet((uint32_t)0x9400D3FF);
const draw::Color draw::color::deepPink((uint32_t)0xFF1493FF);
const draw::Color draw::color::deepSkyBlue((uint32_t)0x00BFFFFF);
const draw::Color draw::color::dimGray((uint32_t)0x696969FF);
const draw::Color draw::color::dimGrey((uint32_t)0x696969FF);
const draw::Color draw::color::dodgerBlue((uint32_t)0x1E90FFFF);
const draw::Color draw::color::fireBrick((uint32_t)0xB22222FF);
const draw::Color draw::color::floralWhite((uint32_t)0xFFFAF0FF);
const draw::Color draw::color::forestGreen((uint32_t)0x228B22FF);
const draw::Color draw::color::fuchsia((uint32_t)0xFF00FFFF);
const draw::Color draw::color::gainsboro((uint32_t)0xDCDCDCFF);
const draw::Color draw::color::ghostWhite((uint32_t)0xF8F8FFFF);
const draw::Color draw::color::gold((uint32_t)0xFFD700FF);
const draw::Color draw::color::goldenRod((uint32_t)0xDAA520FF);
const draw::Color draw::color::gray((uint32_t)0x808080FF);
const draw::Color draw::color::grey((uint32_t)0x808080FF);
const draw::Color draw::color::green((uint32_t)0x008000FF);
const draw::Color draw::color::greenYellow((uint32_t)0xADFF2FFF);
const draw::Color draw::color::honeyDew((uint32_t)0xF0FFF0FF);
const draw::Color draw::color::hotPink((uint32_t)0xFF69B4FF);
const draw::Color draw::color::indianRed ((uint32_t)0xCD5C5CFF);
const draw::Color draw::color::indigo ((uint32_t)0x4B0082FF);
const draw::Color draw::color::ivory((uint32_t)0xFFFFF0FF);
const draw::Color draw::color::khaki((uint32_t)0xF0E68CFF);
const draw::Color draw::color::lavender((uint32_t)0xE6E6FAFF);
const draw::Color draw::color::lavenderBlush((uint32_t)0xFFF0F5FF);
const draw::Color draw::color::lawnGreen((uint32_t)0x7CFC00FF);
const draw::Color draw::color::lemonChiffon((uint32_t)0xFFFACDFF);
const draw::Color draw::color::lightBlue((uint32_t)0xADD8E6FF);
const draw::Color draw::color::lightCoral((uint32_t)0xF08080FF);
const draw::Color draw::color::lightCyan((uint32_t)0xE0FFFFFF);
const draw::Color draw::color::lightGoldenRodYellow((uint32_t)0xFAFAD2FF);
const draw::Color draw::color::lightGray((uint32_t)0xD3D3D3FF);
const draw::Color draw::color::lightGrey((uint32_t)0xD3D3D3FF);
const draw::Color draw::color::lightGreen((uint32_t)0x90EE90FF);
const draw::Color draw::color::lightPink((uint32_t)0xFFB6C1FF);
const draw::Color draw::color::lightSalmon((uint32_t)0xFFA07AFF);
const draw::Color draw::color::lightSeaGreen((uint32_t)0x20B2AAFF);
const draw::Color draw::color::lightSkyBlue((uint32_t)0x87CEFAFF);
const draw::Color draw::color::lightSlateGray((uint32_t)0x778899FF);
const draw::Color draw::color::lightSlateGrey((uint32_t)0x778899FF);
const draw::Color draw::color::lightSteelBlue((uint32_t)0xB0C4DEFF);
const draw::Color draw::color::lightYellow((uint32_t)0xFFFFE0FF);
const draw::Color draw::color::lime((uint32_t)0x00FF00FF);
const draw::Color draw::color::limeGreen((uint32_t)0x32CD32FF);
const draw::Color draw::color::linen((uint32_t)0xFAF0E6FF);
const draw::Color draw::color::magenta((uint32_t)0xFF00FFFF);
const draw::Color draw::color::maroon((uint32_t)0x800000FF);
const draw::Color draw::color::mediumAquaMarine((uint32_t)0x66CDAAFF);
const draw::Color draw::color::mediumBlue((uint32_t)0x0000CDFF);
const draw::Color draw::color::mediumOrchid((uint32_t)0xBA55D3FF);
const draw::Color draw::color::mediumPurple((uint32_t)0x9370D8FF);
const draw::Color draw::color::mediumSeaGreen((uint32_t)0x3CB371FF);
const draw::Color draw::color::mediumSlateBlue((uint32_t)0x7B68EEFF);
const draw::Color draw::color::mediumSpringGreen((uint32_t)0x00FA9AFF);
const draw::Color draw::color::mediumTurquoise((uint32_t)0x48D1CCFF);
const draw::Color draw::color::mediumVioletRed((uint32_t)0xC71585FF);
const draw::Color draw::color::midnightBlue((uint32_t)0x191970FF);
const draw::Color draw::color::mintCream((uint32_t)0xF5FFFAFF);
const draw::Color draw::color::mistyRose((uint32_t)0xFFE4E1FF);
const draw::Color draw::color::moccasin((uint32_t)0xFFE4B5FF);
const draw::Color draw::color::navajoWhite((uint32_t)0xFFDEADFF);
const draw::Color draw::color::navy((uint32_t)0x000080FF);
const draw::Color draw::color::oldLace((uint32_t)0xFDF5E6FF);
const draw::Color draw::color::olive((uint32_t)0x808000FF);
const draw::Color draw::color::oliveDrab((uint32_t)0x6B8E23FF);
const draw::Color draw::color::orange((uint32_t)0xFFA500FF);
const draw::Color draw::color::orangeRed((uint32_t)0xFF4500FF);
const draw::Color draw::color::orchid((uint32_t)0xDA70D6FF);
const draw::Color draw::color::paleGoldenRod((uint32_t)0xEEE8AAFF);
const draw::Color draw::color::paleGreen((uint32_t)0x98FB98FF);
const draw::Color draw::color::paleTurquoise((uint32_t)0xAFEEEEFF);
const draw::Color draw::color::paleVioletRed((uint32_t)0xD87093FF);
const draw::Color draw::color::papayaWhip((uint32_t)0xFFEFD5FF);
const draw::Color draw::color::peachPuff((uint32_t)0xFFDAB9FF);
const draw::Color draw::color::peru((uint32_t)0xCD853FFF);
const draw::Color draw::color::pink((uint32_t)0xFFC0CBFF);
const draw::Color draw::color::plum((uint32_t)0xDDA0DDFF);
const draw::Color draw::color::powderBlue((uint32_t)0xB0E0E6FF);
const draw::Color draw::color::purple((uint32_t)0x800080FF);
const draw::Color draw::color::red((uint32_t)0xFF0000FF);
const draw::Color draw::color::rosyBrown((uint32_t)0xBC8F8FFF);
const draw::Color draw::color::royalBlue((uint32_t)0x4169E1FF);
const draw::Color draw::color::saddleBrown((uint32_t)0x8B4513FF);
const draw::Color draw::color::salmon((uint32_t)0xFA8072FF);
const draw::Color draw::color::sandyBrown((uint32_t)0xF4A460FF);
const draw::Color draw::color::seaGreen((uint32_t)0x2E8B57FF);
const draw::Color draw::color::seaShell((uint32_t)0xFFF5EEFF);
const draw::Color draw::color::sienna((uint32_t)0xA0522DFF);
const draw::Color draw::color::silver((uint32_t)0xC0C0C0FF);
const draw::Color draw::color::skyBlue((uint32_t)0x87CEEBFF);
const draw::Color draw::color::slateBlue((uint32_t)0x6A5ACDFF);
const draw::Color draw::color::slateGray((uint32_t)0x708090FF);
const draw::Color draw::color::slateGrey((uint32_t)0x708090FF);
const draw::Color draw::color::snow((uint32_t)0xFFFAFAFF);
const draw::Color draw::color::springGreen((uint32_t)0x00FF7FFF);
const draw::Color draw::color::steelBlue((uint32_t)0x4682B4FF);
const draw::Color draw::color::tan((uint32_t)0xD2B48CFF);
const draw::Color draw::color::teal((uint32_t)0x008080FF);
const draw::Color draw::color::thistle((uint32_t)0xD8BFD8FF);
const draw::Color draw::color::tomato((uint32_t)0xFF6347FF);
const draw::Color draw::color::turquoise((uint32_t)0x40E0D0FF);
const draw::Color draw::color::violet((uint32_t)0xEE82EEFF);
const draw::Color draw::color::wheat((uint32_t)0xF5DEB3FF);
const draw::Color draw::color::white((uint32_t)0xFFFFFFFF);
const draw::Color draw::color::whiteSmoke((uint32_t)0xF5F5F5FF);
const draw::Color draw::color::yellow((uint32_t)0xFFFF00FF);
const draw::Color draw::color::yellowGreen((uint32_t)0x9ACD32FF);


typedef struct {
	const char * colorName;
	draw::Color color;
} colorList_ts;

static const colorList_ts listOfColor[] = {
	{ "none",				draw::color::none},
	{ "AliceBlue",			draw::color::aliceBlue},
	{ "AntiqueWhite",		draw::color::antiqueWhite},
	{ "Aqua",				draw::color::aqua},
	{ "Aquamarine",			draw::color::aquamarine},
	{ "Azure",				draw::color::azure},
	{ "Beige",				draw::color::beige},
	{ "Bisque",				draw::color::bisque},
	{ "Black",				draw::color::black},
	{ "BlanchedAlmond",		draw::color::blanchedAlmond},
	{ "Blue",				draw::color::blue},
	{ "BlueViolet",			draw::color::blueViolet},
	{ "Brown",				draw::color::brown},
	{ "BurlyWood",			draw::color::burlyWood},
	{ "CadetBlue",			draw::color::cadetBlue},
	{ "Chartreuse",			draw::color::chartreuse},
	{ "Chocolate",			draw::color::chocolate},
	{ "Coral",				draw::color::coral},
	{ "CornflowerBlue",		draw::color::cornflowerBlue},
	{ "Cornsilk",			draw::color::cornsilk},
	{ "Crimson",			draw::color::crimson},
	{ "Cyan",				draw::color::cyan},
	{ "DarkBlue",			draw::color::darkBlue},
	{ "DarkCyan",			draw::color::darkCyan},
	{ "DarkGoldenRod",		draw::color::darkGoldenRod},
	{ "DarkGray",			draw::color::darkGray},
	{ "DarkGrey",			draw::color::darkGrey},
	{ "DarkGreen",			draw::color::darkGreen},
	{ "DarkKhaki",			draw::color::darkKhaki},
	{ "DarkMagenta",		draw::color::darkMagenta},
	{ "DarkOliveGreen",		draw::color::darkOliveGreen},
	{ "Darkorange",			draw::color::darkorange},
	{ "DarkOrchid",			draw::color::darkOrchid},
	{ "DarkRed",			draw::color::darkRed},
	{ "DarkSalmon",			draw::color::darkSalmon},
	{ "DarkSeaGreen",		draw::color::darkSeaGreen},
	{ "DarkSlateBlue",		draw::color::darkSlateBlue},
	{ "DarkSlateGray",		draw::color::darkSlateGray},
	{ "DarkSlateGrey",		draw::color::darkSlateGrey},
	{ "DarkTurquoise",		draw::color::darkTurquoise},
	{ "DarkViolet",			draw::color::darkViolet},
	{ "DeepPink",			draw::color::deepPink},
	{ "DeepSkyBlue",		draw::color::deepSkyBlue},
	{ "DimGray",			draw::color::dimGray},
	{ "DimGrey",			draw::color::dimGrey},
	{ "DodgerBlue",			draw::color::dodgerBlue},
	{ "FireBrick",			draw::color::fireBrick},
	{ "FloralWhite",		draw::color::floralWhite},
	{ "ForestGreen",		draw::color::forestGreen},
	{ "Fuchsia",			draw::color::fuchsia},
	{ "Gainsboro",			draw::color::gainsboro},
	{ "GhostWhite",			draw::color::ghostWhite},
	{ "Gold",				draw::color::gold},
	{ "GoldenRod",			draw::color::goldenRod},
	{ "Gray",				draw::color::gray},
	{ "Grey",				draw::color::grey},
	{ "Green",				draw::color::green},
	{ "GreenYellow",		draw::color::greenYellow},
	{ "HoneyDew",			draw::color::honeyDew},
	{ "HotPink",			draw::color::hotPink},
	{ "IndianRed",			draw::color::indianRed},
	{ "Indigo",				draw::color::indigo},
	{ "Ivory",				draw::color::ivory},
	{ "Khaki",				draw::color::khaki},
	{ "Lavender",			draw::color::lavender},
	{ "LavenderBlush",		draw::color::lavenderBlush},
	{ "LawnGreen",			draw::color::lawnGreen},
	{ "LemonChiffon",		draw::color::lemonChiffon},
	{ "LightBlue",			draw::color::lightBlue},
	{ "LightCoral",			draw::color::lightCoral},
	{ "LightCyan",			draw::color::lightCyan},
	{ "LightGoldenRodYellow",	draw::color::lightGoldenRodYellow},
	{ "LightGray",			draw::color::lightGray},
	{ "LightGrey",			draw::color::lightGrey},
	{ "LightGreen",			draw::color::lightGreen},
	{ "LightPink",			draw::color::lightPink},
	{ "LightSalmon",		draw::color::lightSalmon},
	{ "LightSeaGreen",		draw::color::lightSeaGreen},
	{ "LightSkyBlue",		draw::color::lightSkyBlue},
	{ "LightSlateGray",		draw::color::lightSlateGray},
	{ "LightSlateGrey",		draw::color::lightSlateGrey},
	{ "LightSteelBlue",		draw::color::lightSteelBlue},
	{ "LightYellow",		draw::color::lightYellow},
	{ "Lime",				draw::color::lime},
	{ "LimeGreen",			draw::color::limeGreen},
	{ "Linen",				draw::color::linen},
	{ "Magenta",			draw::color::magenta},
	{ "Maroon",				draw::color::maroon},
	{ "MediumAquaMarine",	draw::color::mediumAquaMarine},
	{ "MediumBlue",			draw::color::mediumBlue},
	{ "MediumOrchid",		draw::color::mediumOrchid},
	{ "MediumPurple",		draw::color::mediumPurple},
	{ "MediumSeaGreen",		draw::color::mediumSeaGreen},
	{ "MediumSlateBlue",	draw::color::mediumSlateBlue},
	{ "MediumSpringGreen",	draw::color::mediumSpringGreen},
	{ "MediumTurquoise",	draw::color::mediumTurquoise},
	{ "MediumVioletRed",	draw::color::mediumVioletRed},
	{ "MidnightBlue",		draw::color::midnightBlue},
	{ "MintCream",			draw::color::mintCream},
	{ "MistyRose",			draw::color::mistyRose},
	{ "Moccasin",			draw::color::moccasin},
	{ "NavajoWhite",		draw::color::navajoWhite},
	{ "Navy",				draw::color::navy},
	{ "OldLace",			draw::color::oldLace},
	{ "Olive",				draw::color::olive},
	{ "OliveDrab",			draw::color::oliveDrab},
	{ "Orange",				draw::color::orange},
	{ "OrangeRed",			draw::color::orangeRed},
	{ "Orchid",				draw::color::orchid},
	{ "PaleGoldenRod",		draw::color::paleGoldenRod},
	{ "PaleGreen",			draw::color::paleGreen},
	{ "PaleTurquoise",		draw::color::paleTurquoise},
	{ "PaleVioletRed",		draw::color::paleVioletRed},
	{ "PapayaWhip",			draw::color::papayaWhip},
	{ "PeachPuff",			draw::color::peachPuff},
	{ "Peru",				draw::color::peru},
	{ "Pink",				draw::color::pink},
	{ "Plum",				draw::color::plum},
	{ "PowderBlue",			draw::color::powderBlue},
	{ "Purple",				draw::color::purple},
	{ "Red",				draw::color::red},
	{ "RosyBrown",			draw::color::rosyBrown},
	{ "RoyalBlue",			draw::color::royalBlue},
	{ "SaddleBrown",		draw::color::saddleBrown},
	{ "Salmon",				draw::color::salmon},
	{ "SandyBrown",			draw::color::sandyBrown},
	{ "SeaGreen",			draw::color::seaGreen},
	{ "SeaShell",			draw::color::seaShell},
	{ "Sienna",				draw::color::sienna},
	{ "Silver",				draw::color::silver},
	{ "SkyBlue",			draw::color::skyBlue},
	{ "SlateBlue",			draw::color::slateBlue},
	{ "SlateGray",			draw::color::slateGray},
	{ "SlateGrey",			draw::color::slateGrey},
	{ "Snow",				draw::color::snow},
	{ "SpringGreen",		draw::color::springGreen},
	{ "SteelBlue",			draw::color::steelBlue},
	{ "Tan",				draw::color::tan},
	{ "Teal",				draw::color::teal},
	{ "Thistle",			draw::color::thistle},
	{ "Tomato",				draw::color::tomato},
	{ "Turquoise",			draw::color::turquoise},
	{ "Violet",				draw::color::violet},
	{ "Wheat",				draw::color::wheat},
	{ "White",				draw::color::white},
	{ "WhiteSmoke",			draw::color::whiteSmoke},
	{ "Yellow",				draw::color::yellow},
	{ "YellowGreen",		draw::color::yellowGreen}
};
static const int32_t listOfColorSize = sizeof(listOfColor) / sizeof(colorList_ts);


static bool strnCmpNoCase(const char * input1, const char * input2, int32_t maxLen)
{
	int32_t iii=0;
	while ('\0' != *input1 && '\0' != *input2 && iii < maxLen) {
		char in1 = *input1;
		char in2 = *input2;
		if (in1 != in2) {
			if (in1 <= 'Z' && in1 >= 'A') {
				in1 = in1 - 'A' + 'a';
			}
			if (in2 <= 'Z' && in2 >= 'A') {
				in2 = in2 - 'A' + 'a';
			}
			if (in1 != in2) {
				return false;
			}
		}
		iii++;
		input1++;
		input2++;
	}
	return true;
}



void draw::ParseColor(const char* _input, struct agg::rgba8& color)
{
	color = draw::color::white;
	if (NULL == _input) {
		DRAW_ERROR("try to parse Color with NULL pointer");
		return;
	}
	const char* inputData = _input;
	uint32_t _red, _green, _blue, _alpha;
	float fred, fgreen, fblue, falpha;
	size_t len = strlen(_input);
	
	if(    len >=1
	    && inputData[0] == '#') {
		if(len == 4) {
			int32_t red=0, green=0, blue=0;
			if (sscanf(inputData + 1, "%1x%1x%1x", &red, &green, &blue) == 3) {
				color.r = (red | red << 4);
				color.g = (green | green << 4);
				color.b = (blue | blue << 4);
			} else {
				TK_ERROR(" pb in parsing the color : \"" << inputData << "\"");
			}
		} else if (len==5) {
			int32_t red=0, green=0, blue=0, alpha=0;
			if (sscanf(inputData + 1, "%1x%1x%1x%1x", &red, &green, &blue, &alpha) == 4) {
				color.r = (red | red << 4);
				color.g = (green | green << 4);
				color.b = (blue | blue << 4);
				color.a = (alpha | alpha << 4);
			} else {
				TK_ERROR(" pb in parsing the color : \"" << inputData << "\"");
			}
		} else if (len == 7) {
			int32_t red=0, green=0, blue=0;
			if (sscanf(inputData + 1, "%2x%2x%2x", &red, &green, &blue) == 3) {
				color.r = red;
				color.g = green;
				color.b = blue;
			} else {
				TK_ERROR(" pb in parsing the color : \"" << inputData << "\"");
			}
		} else if (len == 9) {
			int32_t red=0, green=0, blue=0, alpha=0;
			if (sscanf(inputData + 1, "%2x%2x%2x%2x", &red, &green, &blue, &alpha) == 4) {
				color.r = red;
				color.g = green;
				color.b = blue;
				color.a = alpha;
			} else {
				TK_ERROR(" pb in parsing the color : \"" << inputData << "\"");
			}
		} else {
			TK_ERROR(" pb in parsing the color : \"" << inputData << "\" ==> unknown methode ...");
		}
	} else if(    4 <= len
	           && inputData[0] == 'r'
	           && inputData[1] == 'g'
	           && inputData[2] == 'b'
	           && inputData[3] == '(' ) {
		int32_t _red=0, _green=0, _blue=0, _alpha=0;
		float   fred=0, fgreen=0, fblue=0, falpha=0;
		if (sscanf(inputData + 4, "%u,%u,%u,%u", &_red, &_green, &_blue, &_alpha) == 4) {
			color.r = etk_min(0xFF, _red);
			color.g = etk_min(0xFF, _green);
			color.b = etk_min(0xFF, _blue);
			color.a = etk_min(0xFF, _alpha);
		} else if (sscanf(inputData + 4, "%u,%u,%u", &_red, &_green, &_blue) == 3) {
			color.r = etk_min(0xFF, _red);
			color.g = etk_min(0xFF, _green);
			color.b = etk_min(0xFF, _blue);
		} else if (sscanf(inputData + 4, "%f%%,%f%%,%f%%,%f%%", &fred, &fgreen, &fblue, &falpha) == 4) {
			fred   = etk_avg(0.0, fred, 1.0);
			fgreen = etk_avg(0.0, fgreen, 1.0);
			fblue  = etk_avg(0.0, fblue, 1.0);
			falpha = etk_avg(0.0, falpha, 1.0);
			color.r = (uint8_t)(fred * 255.);
			color.g = (uint8_t)(fgreen * 255.);
			color.b = (uint8_t)(fblue * 255.);
			color.a = (uint8_t)(falpha * 255.);
		} else if (sscanf(inputData + 4, "%f%%,%f%%,%f%%", &fred, &fgreen, &fblue) == 3) {
			fred  = etk_avg(0.0, fred, 1.0);
			fgreen= etk_avg(0.0, fgreen, 1.0);
			fblue = etk_avg(0.0, fblue, 1.0);
			color.r = (uint8_t)(fred * 255.);
			color.g = (uint8_t)(fgreen * 255.);
			color.b = (uint8_t)(fblue * 255.);
		} else {
			TK_ERROR(" pb in parsing the color : \"" << inputData << "\" ==> unknown methode ...");
		}
	} else {
		bool findIt = false;
		// direct named color ...
		for (int32_t iii=0; iii<listOfColorSize; iii++) {
			if (strnCmpNoCase(listOfColor[iii].colorName, inputData, strlen(listOfColor[iii].colorName)) == true) {
				findIt = true;
				color = listOfColor[iii].color;
				// stop searching
				break;
			}
		}
		// not find color ...
		if (findIt == false) {
			TK_ERROR(" pb in parsing the color : \"" << inputData << "\" not find ...");
		}
	}
	TK_VERBOSE("Parse color : \"" << inputData << "\" ==> " << color);
}

etk::CCout& agg::operator <<(etk::CCout &os, const  struct agg::rgba8& obj)
{
	char tmpData[256];
	snprintf(tmpData, 256, "#%02X%02X%02X%02X", obj.r, obj.g, obj.b, obj.a);
	os << tmpData;
	return os;
}
