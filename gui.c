#include "converter_tree.h"
#include "converter.h"
#include <stdlib.h>
#include <ncursesw/curses.h>
#include <locale.h>
#include <setjmp.h>
#include <stdio.h>

static char *printed_kana[1024 * 4];
static char path[16];
static size_t printed_kana_len, path_i;
static struct converter conv[1];

static jmp_buf exit_buf;
static void exit_rtok(void)
{
	longjmp(exit_buf, 1);
}

static void init(void)
{
	init_converter(conv, 0);
	path_i = 0;
	printed_kana_len = 0;
	// hiragana
	add_character(conv->root,
				  "あ", "a",
				  1, 0);
	add_character(conv->root,
				  "い", "i",
				  1, 0);
	add_character(conv->root,
				  "う", "u",
				  1, 0);
	add_character(conv->root,
				  "え", "e",
				  1, 0);
	add_character(conv->root,
				  "お", "o",
				  1, 0);
	add_character(conv->root,
				  "か", "ka",
				  2, 0);
	add_character(conv->root,
				  "き", "ki",
				  2, 0);
	add_character(conv->root,
				  "く", "ku",
				  2, 0);
	add_character(conv->root,
				  "け", "ke",
				  2, 0);
	add_character(conv->root,
				  "こ", "ko",
				  2, 0);
	add_character(conv->root,
				  "さ", "sa",
				  2, 0);
	add_character(conv->root,
				  "し", "shi",
				  3, 0);
	add_character(conv->root,
				  "し", "si",
				  2, 0);
	add_character(conv->root,
				  "す", "su",
				  2, 0);
	add_character(conv->root,
				  "せ", "se",
				  2, 0);
	add_character(conv->root,
				  "そ", "so",
				  2, 0);
	add_character(conv->root,
				  "た", "ta",
				  2, 0);
	add_character(conv->root,
				  "ち", "chi",
				  3, 0);
	add_character(conv->root,
				  "つ", "tsu",
				  3, 0);
	add_character(conv->root,
				  "て", "te",
				  2, 0);
	add_character(conv->root,
				  "てぃ", "ti",
				  2, 0);
	add_character(conv->root,
				  "てぅ", "tu",
				  2, 0);
	add_character(conv->root,
				  "と", "to",
				  2, 0);
	add_character(conv->root,
				  "な", "na",
				  2, 0);
	add_character(conv->root,
				  "に", "ni",
				  2, 0);
	add_character(conv->root,
				  "ぬ", "nu",
				  2, 0);
	add_character(conv->root,
				  "ね", "ne",
				  2, 0);
	add_character(conv->root,
				  "の", "no",
				  2, 0);
	add_character(conv->root,
				  "は", "ha",
				  2, 0);
	add_character(conv->root,
				  "ひ", "hi",
				  2, 0);
	add_character(conv->root,
				  "ふ", "hu",
				  2, 0);
	add_character(conv->root,
				  "ふ", "fu",
				  2, 0);
	add_character(conv->root,
				  "へ", "he",
				  2, 0);
	add_character(conv->root,
				  "ほ", "ho",
				  2, 0);
	add_character(conv->root,
				  "ま", "ma",
				  2, 0);
	add_character(conv->root,
				  "み", "mi",
				  2, 0);
	add_character(conv->root,
				  "む", "mu",
				  2, 0);
	add_character(conv->root,
				  "め", "me",
				  2, 0);
	add_character(conv->root,
				  "も", "mo",
				  2, 0);
	add_character(conv->root,
				  "や", "ya",
				  2, 0);
	add_character(conv->root,
				  "ゆ", "yu",
				  2, 0);
	add_character(conv->root,
				  "よ", "yo",
				  2, 0);
	add_character(conv->root,
				  "ら", "ra",
				  2, 0);
	add_character(conv->root,
				  "ら", "la",
				  2, 0);
	add_character(conv->root,
				  "り", "ri",
				  2, 0);
	add_character(conv->root,
				  "り", "li",
				  2, 0);
	add_character(conv->root,
				  "る", "ru",
				  2, 0);
	add_character(conv->root,
				  "る", "lu",
				  2, 0);
	add_character(conv->root,
				  "れ", "re",
				  2, 0);
	add_character(conv->root,
				  "れ", "le",
				  2, 0);
	add_character(conv->root,
				  "ろ", "ro",
				  2, 0);
	add_character(conv->root,
				  "ろ", "lo",
				  2, 0);
	add_character(conv->root,
				  "わ", "wa",
				  2, 0);
	add_character(conv->root,
				  "ゐ", "wi",
				  2, 0);
	add_character(conv->root,
				  "ゑ", "we",
				  2, 0);
	add_character(conv->root,
				  "を", "wo",
				  2, 0);
	add_character(conv->root,
				  "ん", "n",
				  1, 0);
	add_character(conv->root,
				  "ん", "m",
				  1, 0);
	add_character(conv->root,
				  "が", "ga",
				  2, 0);
	add_character(conv->root,
				  "ぎ", "gi",
				  2, 0);
	add_character(conv->root,
				  "ぐ", "gu",
				  2, 0);
	add_character(conv->root,
				  "げ", "ge",
				  2, 0);
	add_character(conv->root,
				  "ご", "go",
				  2, 0);
	add_character(conv->root,
				  "ざ", "za",
				  2, 0);
	add_character(conv->root,
				  "じ", "ji",
				  2, 0);
	add_character(conv->root,
				  "じ", "zi",
				  2, 0);
	add_character(conv->root,
				  "ず", "zu",
				  2, 0);
	add_character(conv->root,
				  "ぜ", "ze",
				  2, 0);
	add_character(conv->root,
				  "ぞ", "zo",
				  2, 0);
	add_character(conv->root,
				  "だ", "da",
				  2, 0);
	add_character(conv->root,
				  "ぢ", "jji",
				  3, 0);
	add_character(conv->root,
				  "ぢ", "di",
				  3, 0);
	add_character(conv->root,
				  "づ", "dzu",
				  3, 0);
	add_character(conv->root,
				  "づ", "du",
				  2, 0);
	add_character(conv->root,
				  "で", "de",
				  2, 0);
	add_character(conv->root,
				  "ど", "do",
				  2, 0);
	add_character(conv->root,
				  "ば", "ba",
				  2, 0);
	add_character(conv->root,
				  "び", "bi",
				  2, 0);
	add_character(conv->root,
				  "ぶ", "bu",
				  2, 0);
	add_character(conv->root,
				  "べ", "be",
				  2, 0);
	add_character(conv->root,
				  "ぼ", "bo",
				  2, 0);
	add_character(conv->root,
				  "ぱ", "pa",
				  2, 0);
	add_character(conv->root,
				  "ぴ", "pi",
				  2, 0);
	add_character(conv->root,
				  "ぷ", "pu",
				  2, 0);
	add_character(conv->root,
				  "ぺ", "pe",
				  2, 0);
	add_character(conv->root,
				  "ぽ", "po",
				  2, 0);
	add_character(conv->root,
				  "きゃ", "kya",
				  3, 0);
	add_character(conv->root,
				  "きゅ", "kyu",
				  3, 0);
	add_character(conv->root,
				  "きょ", "kyo",
				  3, 0);
	add_character(conv->root,
				  "しゃ", "sha",
				  3, 0);
	add_character(conv->root,
				  "しゅ", "shu",
				  3, 0);
	add_character(conv->root,
				  "しょ", "sho",
				  3, 0);
	add_character(conv->root,
				  "ちゃ", "cha",
				  3, 0);
	add_character(conv->root,
				  "ちゅ", "chu",
				  3, 0);
	add_character(conv->root,
				  "ちょ", "cho",
				  3, 0);
	add_character(conv->root,
				  "にゃ", "nya",
				  3, 0);
	add_character(conv->root,
				  "にゅ", "nyu",
				  3, 0);
	add_character(conv->root,
				  "にょ", "nyo",
				  3, 0);
	add_character(conv->root,
				  "ひゃ", "hya",
				  3, 0);
	add_character(conv->root,
				  "ひゅ", "hyu",
				  3, 0);
	add_character(conv->root,
				  "ひょ", "hyo",
				  3, 0);
	add_character(conv->root,
				  "みゃ", "mya",
				  3, 0);
	add_character(conv->root,
				  "みゅ", "myu",
				  3, 0);
	add_character(conv->root,
				  "みょ", "myo",
				  3, 0);
	add_character(conv->root,
				  "りゃ", "rya",
				  3, 0);
	add_character(conv->root,
				  "りゃ", "lya",
				  3, 0);
	add_character(conv->root,
				  "りゅ", "ryu",
				  3, 0);
	add_character(conv->root,
				  "りゅ", "lyu",
				  3, 0);
	add_character(conv->root,
				  "りょ", "ryo",
				  3, 0);
	add_character(conv->root,
				  "りょ", "lyo",
				  3, 0);
	add_character(conv->root,
				  "っ", "'",
				  1, 0);
	add_character(conv->root,
				  "ぎゃ", "gya",
				  3, 0);
	add_character(conv->root,
				  "ぎゅ", "gyu",
				  3, 0);
	add_character(conv->root,
				  "ぎょ", "gyo",
				  3, 0);
	add_character(conv->root,
				  "じゃ", "ja",
				  2, 0);
	add_character(conv->root,
				  "じゃ", "zya",
				  3, 0);
	add_character(conv->root,
				  "じゅ", "ju",
				  2, 0);
	add_character(conv->root,
				  "じゅ", "zyu",
				  3, 0);
	add_character(conv->root,
				  "じょ", "jo",
				  2, 0);
	add_character(conv->root,
				  "じょ", "zyo",
				  3, 0);
	add_character(conv->root,
				  "ぢゃ", "jja",
				  3, 0);
	add_character(conv->root,
				  "ぢゃ", "dya",
				  3, 0);
	add_character(conv->root,
				  "ぢゅ", "jju",
				  3, 0);
	add_character(conv->root,
				  "ぢゅ", "dyu",
				  3, 0);
	add_character(conv->root,
				  "ぢょ", "jjo",
				  3, 0);
	add_character(conv->root,
				  "ぢょ", "dyo",
				  3, 0);
	add_character(conv->root,
				  "びゃ", "bya",
				  3, 0);
	add_character(conv->root,
				  "びゅ", "byu",
				  3, 0);
	add_character(conv->root,
				  "びょ", "byo",
				  3, 0);
	add_character(conv->root,
				  "ぴゃ", "pya",
				  3, 0);
	add_character(conv->root,
				  "ぴゅ", "pyu",
				  3, 0);
	add_character(conv->root,
				  "ぴょ", "pyo",
				  3, 0);
	add_character(conv->root,
				  "ゔ", "vu",
				  2, 0);
	add_character(conv->root,
				  "ゔぁ", "va",
				  2, 0);
	add_character(conv->root,
				  "ゔぃ", "vi",
				  2, 0);
	add_character(conv->root,
				  "ゔぇ", "ve",
				  2, 0);
	add_character(conv->root,
				  "ゔぉ", "vo",
				  2, 0);
	add_character(conv->root,
				  "ぁ", ";a",
				  2, 0);
	add_character(conv->root,
				  "ぃ", ";i",
				  2, 0);
	add_character(conv->root,
				  "ぅ", ";u",
				  2, 0);
	add_character(conv->root,
				  "ぇ", ";e",
				  2, 0);
	add_character(conv->root,
				  "ぉ", ";o",
				  2, 0);
	add_character(conv->root,
				  "っ", ";tsu",
				  4, 0);
	add_character(conv->root,
				  "っ", ";tu",
				  3, 0);
	add_character(conv->root,
				  "か", ";ka",
				  3, 0);
	add_character(conv->root,
				  "け", ";ke",
				  3, 0);
	add_character(conv->root,
				  "ふぁ", "fa",
				  2, 0);
	add_character(conv->root,
				  "ふぃ", "fi",
				  2, 0);
	add_character(conv->root,
				  "ふぇ", "fe",
				  2, 0);
	add_character(conv->root,
				  "ふぉ", "fo",
				  2, 0);
	add_character(conv->root,
				  "ゟ", ";yori",
				  5, 0);
	// katakana
	add_character(conv->root,
				  "ア", "A",
				  1, 0);
	add_character(conv->root,
				  "イ", "I",
				  1, 0);
	add_character(conv->root,
				  "ウ", "U",
				  1, 0);
	add_character(conv->root,
				  "エ", "E",
				  1, 0);
	add_character(conv->root,
				  "オ", "O",
				  1, 0);
	add_character(conv->root,
				  "カ", "Ka",
				  2, 0);
	add_character(conv->root,
				  "カ", "kA",
				  2, 0);
	add_character(conv->root,
				  "カ", "KA",
				  2, 0);
	add_character(conv->root,
				  "キ", "Ki",
				  2, 0);
	add_character(conv->root,
				  "キ", "kI",
				  2, 0);
	add_character(conv->root,
				  "キ", "KI",
				  2, 0);
	add_character(conv->root,
				  "ク", "Ku",
				  2, 0);
	add_character(conv->root,
				  "ク", "kU",
				  2, 0);
	add_character(conv->root,
				  "ク", "KU",
				  2, 0);
	add_character(conv->root,
				  "ケ", "Ke",
				  2, 0);
	add_character(conv->root,
				  "ケ", "kE",
				  2, 0);
	add_character(conv->root,
				  "ケ", "KE",
				  2, 0);
	add_character(conv->root,
				  "コ", "Ko",
				  2, 0);
	add_character(conv->root,
				  "コ", "kO",
				  2, 0);
	add_character(conv->root,
				  "コ", "KO",
				  2, 0);
	add_character(conv->root,
				  "サ", "Sa",
				  2, 0);
	add_character(conv->root,
				  "サ", "sA",
				  2, 0);
	add_character(conv->root,
				  "サ", "SA",
				  2, 0);
	add_character(conv->root,
				  "シ", "shI",
				  3, 0);
	add_character(conv->root,
				  "シ", "sHi",
				  3, 0);
	add_character(conv->root,
				  "シ", "sHI",
				  3, 0);
	add_character(conv->root,
				  "シ", "Shi",
				  3, 0);
	add_character(conv->root,
				  "シ", "ShI",
				  3, 0);
	add_character(conv->root,
				  "シ", "SHi",
				  3, 0);
	add_character(conv->root,
				  "シ", "SHI",
				  3, 0);
	add_character(conv->root,
				  "シ", "Si",
				  2, 0);
	add_character(conv->root,
				  "シ", "sI",
				  2, 0);
	add_character(conv->root,
				  "シ", "SI",
				  2, 0);
	add_character(conv->root,
				  "ス", "Su",
				  2, 0);
	add_character(conv->root,
				  "ス", "sU",
				  2, 0);
	add_character(conv->root,
				  "ス", "SU",
				  2, 0);
	add_character(conv->root,
				  "セ", "Se",
				  2, 0);
	add_character(conv->root,
				  "セ", "sE",
				  2, 0);
	add_character(conv->root,
				  "セ", "SE",
				  2, 0);
	add_character(conv->root,
				  "ソ", "So",
				  2, 0);
	add_character(conv->root,
				  "ソ", "sO",
				  2, 0);
	add_character(conv->root,
				  "ソ", "SO",
				  2, 0);
	add_character(conv->root,
				  "タ", "Ta",
				  2, 0);
	add_character(conv->root,
				  "タ", "tA",
				  2, 0);
	add_character(conv->root,
				  "タ", "TA",
				  2, 0);
	add_character(conv->root,
				  "チ", "chI",
				  3, 0);
	add_character(conv->root,
				  "チ", "cHi",
				  3, 0);
	add_character(conv->root,
				  "チ", "cHI",
				  3, 0);
	add_character(conv->root,
				  "チ", "Chi",
				  3, 0);
	add_character(conv->root,
				  "チ", "ChI",
				  3, 0);
	add_character(conv->root,
				  "チ", "CHi",
				  3, 0);
	add_character(conv->root,
				  "チ", "CHI",
				  3, 0);
	add_character(conv->root,
				  "チ", "Ti",
				  2, 0);
	add_character(conv->root,
				  "チ", "tI",
				  2, 0);
	add_character(conv->root,
				  "チ", "TI",
				  2, 0);
	add_character(conv->root,
				  "ツ", "tsU",
				  3, 0);
	add_character(conv->root,
				  "ツ", "tSu",
				  3, 0);
	add_character(conv->root,
				  "ツ", "tSU",
				  3, 0);
	add_character(conv->root,
				  "ツ", "Tsu",
				  3, 0);
	add_character(conv->root,
				  "ツ", "TsU",
				  3, 0);
	add_character(conv->root,
				  "ツ", "TSu",
				  3, 0);
	add_character(conv->root,
				  "ツ", "TSU",
				  3, 0);
	add_character(conv->root,
				  "ツ", "Tu",
				  2, 0);
	add_character(conv->root,
				  "ツ", "tU",
				  2, 0);
	add_character(conv->root,
				  "ツ", "TU",
				  2, 0);
	add_character(conv->root,
				  "テ", "Te",
				  2, 0);
	add_character(conv->root,
				  "テ", "tE",
				  2, 0);
	add_character(conv->root,
				  "テ", "TE",
				  2, 0);
	add_character(conv->root,
				  "ト", "To",
				  2, 0);
	add_character(conv->root,
				  "ト", "tO",
				  2, 0);
	add_character(conv->root,
				  "ト", "TO",
				  2, 0);
	add_character(conv->root,
				  "ナ", "Na",
				  2, 0);
	add_character(conv->root,
				  "ナ", "nA",
				  2, 0);
	add_character(conv->root,
				  "ナ", "NA",
				  2, 0);
	add_character(conv->root,
				  "ニ", "Ni",
				  2, 0);
	add_character(conv->root,
				  "ニ", "nI",
				  2, 0);
	add_character(conv->root,
				  "ニ", "NI",
				  2, 0);
	add_character(conv->root,
				  "ヌ", "Nu",
				  2, 0);
	add_character(conv->root,
				  "ヌ", "nU",
				  2, 0);
	add_character(conv->root,
				  "ヌ", "NU",
				  2, 0);
	add_character(conv->root,
				  "ネ", "Ne",
				  2, 0);
	add_character(conv->root,
				  "ネ", "nE",
				  2, 0);
	add_character(conv->root,
				  "ネ", "NE",
				  2, 0);
	add_character(conv->root,
				  "ノ", "No",
				  2, 0);
	add_character(conv->root,
				  "ノ", "nO",
				  2, 0);
	add_character(conv->root,
				  "ノ", "NO",
				  2, 0);
	add_character(conv->root,
				  "ハ", "Ha",
				  2, 0);
	add_character(conv->root,
				  "ハ", "hA",
				  2, 0);
	add_character(conv->root,
				  "ハ", "HA",
				  2, 0);
	add_character(conv->root,
				  "ヒ", "Hi",
				  2, 0);
	add_character(conv->root,
				  "ヒ", "hI",
				  2, 0);
	add_character(conv->root,
				  "ヒ", "HI",
				  2, 0);
	add_character(conv->root,
				  "フ", "Hu",
				  2, 0);
	add_character(conv->root,
				  "フ", "hU",
				  2, 0);
	add_character(conv->root,
				  "フ", "HU",
				  2, 0);
	add_character(conv->root,
				  "フ", "Fu",
				  2, 0);
	add_character(conv->root,
				  "フ", "fU",
				  2, 0);
	add_character(conv->root,
				  "フ", "FU",
				  2, 0);
	add_character(conv->root,
				  "ヘ", "He",
				  2, 0);
	add_character(conv->root,
				  "ヘ", "hE",
				  2, 0);
	add_character(conv->root,
				  "ヘ", "HE",
				  2, 0);
	add_character(conv->root,
				  "ホ", "Ho",
				  2, 0);
	add_character(conv->root,
				  "ホ", "hO",
				  2, 0);
	add_character(conv->root,
				  "ホ", "HO",
				  2, 0);
	add_character(conv->root,
				  "マ", "Ma",
				  2, 0);
	add_character(conv->root,
				  "マ", "mA",
				  2, 0);
	add_character(conv->root,
				  "マ", "MA",
				  2, 0);
	add_character(conv->root,
				  "ミ", "Mi",
				  2, 0);
	add_character(conv->root,
				  "ミ", "mI",
				  2, 0);
	add_character(conv->root,
				  "ミ", "MI",
				  2, 0);
	add_character(conv->root,
				  "ム", "Mu",
				  2, 0);
	add_character(conv->root,
				  "ム", "mU",
				  2, 0);
	add_character(conv->root,
				  "ム", "MU",
				  2, 0);
	add_character(conv->root,
				  "メ", "Me",
				  2, 0);
	add_character(conv->root,
				  "メ", "mE",
				  2, 0);
	add_character(conv->root,
				  "メ", "ME",
				  2, 0);
	add_character(conv->root,
				  "モ", "Mo",
				  2, 0);
	add_character(conv->root,
				  "モ", "mO",
				  2, 0);
	add_character(conv->root,
				  "モ", "MO",
				  2, 0);
	add_character(conv->root,
				  "ヤ", "Ya",
				  2, 0);
	add_character(conv->root,
				  "ヤ", "yA",
				  2, 0);
	add_character(conv->root,
				  "ヤ", "YA",
				  2, 0);
	add_character(conv->root,
				  "ユ", "Yu",
				  2, 0);
	add_character(conv->root,
				  "ユ", "yU",
				  2, 0);
	add_character(conv->root,
				  "ユ", "YU",
				  2, 0);
	add_character(conv->root,
				  "ヨ", "Yo",
				  2, 0);
	add_character(conv->root,
				  "ヨ", "yO",
				  2, 0);
	add_character(conv->root,
				  "ヨ", "YO",
				  2, 0);
	add_character(conv->root,
				  "ラ", "Ra",
				  2, 0);
	add_character(conv->root,
				  "ラ", "rA",
				  2, 0);
	add_character(conv->root,
				  "ラ", "RA",
				  2, 0);
	add_character(conv->root,
				  "ラ", "La",
				  2, 0);
	add_character(conv->root,
				  "ラ", "lA",
				  2, 0);
	add_character(conv->root,
				  "ラ", "LA",
				  2, 0);
	add_character(conv->root,
				  "リ", "Ri",
				  2, 0);
	add_character(conv->root,
				  "リ", "rI",
				  2, 0);
	add_character(conv->root,
				  "リ", "RI",
				  2, 0);
	add_character(conv->root,
				  "リ", "Li",
				  2, 0);
	add_character(conv->root,
				  "リ", "lI",
				  2, 0);
	add_character(conv->root,
				  "リ", "LI",
				  2, 0);
	add_character(conv->root,
				  "ル", "Ru",
				  2, 0);
	add_character(conv->root,
				  "ル", "rU",
				  2, 0);
	add_character(conv->root,
				  "ル", "RU",
				  2, 0);
	add_character(conv->root,
				  "ル", "Lu",
				  2, 0);
	add_character(conv->root,
				  "ル", "lU",
				  2, 0);
	add_character(conv->root,
				  "ル", "LU",
				  2, 0);
	add_character(conv->root,
				  "レ", "Re",
				  2, 0);
	add_character(conv->root,
				  "レ", "rE",
				  2, 0);
	add_character(conv->root,
				  "レ", "RE",
				  2, 0);
	add_character(conv->root,
				  "レ", "Le",
				  2, 0);
	add_character(conv->root,
				  "レ", "lE",
				  2, 0);
	add_character(conv->root,
				  "レ", "LE",
				  2, 0);
	add_character(conv->root,
				  "ロ", "Ro",
				  2, 0);
	add_character(conv->root,
				  "ロ", "rO",
				  2, 0);
	add_character(conv->root,
				  "ロ", "RO",
				  2, 0);
	add_character(conv->root,
				  "ロ", "Lo",
				  2, 0);
	add_character(conv->root,
				  "ロ", "lO",
				  2, 0);
	add_character(conv->root,
				  "ロ", "LO",
				  2, 0);
	add_character(conv->root,
				  "ワ", "Wa",
				  2, 0);
	add_character(conv->root,
				  "ワ", "wA",
				  2, 0);
	add_character(conv->root,
				  "ワ", "WA",
				  2, 0);
	add_character(conv->root,
				  "ヰ", "Wi",
				  2, 0);
	add_character(conv->root,
				  "ヰ", "wI",
				  2, 0);
	add_character(conv->root,
				  "ヰ", "WI",
				  2, 0);
	add_character(conv->root,
				  "ヱ", "We",
				  2, 0);
	add_character(conv->root,
				  "ヱ", "wE",
				  2, 0);
	add_character(conv->root,
				  "ヱ", "WE",
				  2, 0);
	add_character(conv->root,
				  "ヲ", "Wo",
				  2, 0);
	add_character(conv->root,
				  "ヲ", "wO",
				  2, 0);
	add_character(conv->root,
				  "ヲ", "WO",
				  2, 0);
	add_character(conv->root,
				  "ン", "N",
				  1, 0);
	add_character(conv->root,
				  "ン", "M",
				  1, 0);
	add_character(conv->root,
				  "ッ", "''",
				  2, 0);
	add_character(conv->root,
				  "ガ", "Ga",
				  2, 0);
	add_character(conv->root,
				  "ガ", "gA",
				  2, 0);
	add_character(conv->root,
				  "ガ", "GA",
				  2, 0);
	add_character(conv->root,
				  "ギ", "Gi",
				  2, 0);
	add_character(conv->root,
				  "ギ", "gI",
				  2, 0);
	add_character(conv->root,
				  "ギ", "GI",
				  2, 0);
	add_character(conv->root,
				  "グ", "Gu",
				  2, 0);
	add_character(conv->root,
				  "グ", "gU",
				  2, 0);
	add_character(conv->root,
				  "グ", "GU",
				  2, 0);
	add_character(conv->root,
				  "ゲ", "Ge",
				  2, 0);
	add_character(conv->root,
				  "ゲ", "gE",
				  2, 0);
	add_character(conv->root,
				  "ゲ", "GE",
				  2, 0);
	add_character(conv->root,
				  "ゴ", "Go",
				  2, 0);
	add_character(conv->root,
				  "ゴ", "gO",
				  2, 0);
	add_character(conv->root,
				  "ゴ", "GO",
				  2, 0);
	add_character(conv->root,
				  "ザ", "Za",
				  2, 0);
	add_character(conv->root,
				  "ザ", "zA",
				  2, 0);
	add_character(conv->root,
				  "ザ", "ZA",
				  2, 0);
	add_character(conv->root,
				  "ジ", "Ji",
				  2, 0);
	add_character(conv->root,
				  "ジ", "jI",
				  2, 0);
	add_character(conv->root,
				  "ジ", "JI",
				  2, 0);
	add_character(conv->root,
				  "ジ", "Zi",
				  2, 0);
	add_character(conv->root,
				  "ジ", "zI",
				  2, 0);
	add_character(conv->root,
				  "ジ", "ZI",
				  2, 0);
	add_character(conv->root,
				  "ズ", "Zu",
				  2, 0);
	add_character(conv->root,
				  "ズ", "zU",
				  2, 0);
	add_character(conv->root,
				  "ズ", "ZU",
				  2, 0);
	add_character(conv->root,
				  "ゼ", "Ze",
				  2, 0);
	add_character(conv->root,
				  "ゼ", "zE",
				  2, 0);
	add_character(conv->root,
				  "ゼ", "ZE",
				  2, 0);
	add_character(conv->root,
				  "ゾ", "Zo",
				  2, 0);
	add_character(conv->root,
				  "ゾ", "zO",
				  2, 0);
	add_character(conv->root,
				  "ゾ", "ZO",
				  2, 0);
	add_character(conv->root,
				  "ダ", "Da",
				  2, 0);
	add_character(conv->root,
				  "ダ", "dA",
				  2, 0);
	add_character(conv->root,
				  "ダ", "DA",
				  2, 0);
	add_character(conv->root,
				  "ヂ", "jjI",
				  3, 0);
	add_character(conv->root,
				  "ヂ", "jJi",
				  3, 0);
	add_character(conv->root,
				  "ヂ", "jJI",
				  3, 0);
	add_character(conv->root,
				  "ヂ", "Jji",
				  3, 0);
	add_character(conv->root,
				  "ヂ", "JjI",
				  3, 0);
	add_character(conv->root,
				  "ヂ", "JJi",
				  3, 0);
	add_character(conv->root,
				  "ヂ", "JJI",
				  3, 0);
	add_character(conv->root,
				  "ヅ", "dzU",
				  3, 0);
	add_character(conv->root,
				  "ヅ", "dZu",
				  3, 0);
	add_character(conv->root,
				  "ヅ", "dZU",
				  3, 0);
	add_character(conv->root,
				  "ヅ", "Dzu",
				  3, 0);
	add_character(conv->root,
				  "ヅ", "DzU",
				  3, 0);
	add_character(conv->root,
				  "ヅ", "DZu",
				  3, 0);
	add_character(conv->root,
				  "ヅ", "DZU",
				  3, 0);
	add_character(conv->root,
				  "デ", "De",
				  2, 0);
	add_character(conv->root,
				  "デ", "dE",
				  2, 0);
	add_character(conv->root,
				  "デ", "DE",
				  2, 0);
	add_character(conv->root,
				  "ディ", "Di",
				  2, 0);
	add_character(conv->root,
				  "ディ", "dI",
				  2, 0);
	add_character(conv->root,
				  "ディ", "DI",
				  2, 0);
	add_character(conv->root,
				  "デゥ", "Du",
				  2, 0);
	add_character(conv->root,
				  "デゥ", "dU",
				  2, 0);
	add_character(conv->root,
				  "デゥ", "DU",
				  2, 0);
	add_character(conv->root,
				  "ド", "Do",
				  2, 0);
	add_character(conv->root,
				  "ド", "dO",
				  2, 0);
	add_character(conv->root,
				  "ド", "DO",
				  2, 0);
	add_character(conv->root,
				  "バ", "Ba",
				  2, 0);
	add_character(conv->root,
				  "バ", "bA",
				  2, 0);
	add_character(conv->root,
				  "バ", "BA",
				  2, 0);
	add_character(conv->root,
				  "ビ", "Bi",
				  2, 0);
	add_character(conv->root,
				  "ビ", "bI",
				  2, 0);
	add_character(conv->root,
				  "ビ", "BI",
				  2, 0);
	add_character(conv->root,
				  "ブ", "Bu",
				  2, 0);
	add_character(conv->root,
				  "ブ", "bU",
				  2, 0);
	add_character(conv->root,
				  "ブ", "BU",
				  2, 0);
	add_character(conv->root,
				  "ベ", "Be",
				  2, 0);
	add_character(conv->root,
				  "ベ", "bE",
				  2, 0);
	add_character(conv->root,
				  "ベ", "BE",
				  2, 0);
	add_character(conv->root,
				  "ボ", "Bo",
				  2, 0);
	add_character(conv->root,
				  "ボ", "bO",
				  2, 0);
	add_character(conv->root,
				  "ボ", "BO",
				  2, 0);
	add_character(conv->root,
				  "パ", "Pa",
				  2, 0);
	add_character(conv->root,
				  "パ", "pA",
				  2, 0);
	add_character(conv->root,
				  "パ", "PA",
				  2, 0);
	add_character(conv->root,
				  "ピ", "Pi",
				  2, 0);
	add_character(conv->root,
				  "ピ", "pI",
				  2, 0);
	add_character(conv->root,
				  "ピ", "PI",
				  2, 0);
	add_character(conv->root,
				  "プ", "Pu",
				  2, 0);
	add_character(conv->root,
				  "プ", "pU",
				  2, 0);
	add_character(conv->root,
				  "プ", "PU",
				  2, 0);
	add_character(conv->root,
				  "ペ", "Pe",
				  2, 0);
	add_character(conv->root,
				  "ペ", "pE",
				  2, 0);
	add_character(conv->root,
				  "ペ", "PE",
				  2, 0);
	add_character(conv->root,
				  "ポ", "Po",
				  2, 0);
	add_character(conv->root,
				  "ポ", "pO",
				  2, 0);
	add_character(conv->root,
				  "ポ", "PO",
				  2, 0);
	add_character(conv->root,
				  "キャ", "kyA",
				  3, 0);
	add_character(conv->root,
				  "キャ", "kYa",
				  3, 0);
	add_character(conv->root,
				  "キャ", "kYA",
				  3, 0);
	add_character(conv->root,
				  "キャ", "Kya",
				  3, 0);
	add_character(conv->root,
				  "キャ", "KyA",
				  3, 0);
	add_character(conv->root,
				  "キャ", "KYa",
				  3, 0);
	add_character(conv->root,
				  "キャ", "KYA",
				  3, 0);
	add_character(conv->root,
				  "キュ", "kyU",
				  3, 0);
	add_character(conv->root,
				  "キュ", "kYu",
				  3, 0);
	add_character(conv->root,
				  "キュ", "kYU",
				  3, 0);
	add_character(conv->root,
				  "キュ", "Kyu",
				  3, 0);
	add_character(conv->root,
				  "キュ", "KyU",
				  3, 0);
	add_character(conv->root,
				  "キュ", "KYu",
				  3, 0);
	add_character(conv->root,
				  "キュ", "KYU",
				  3, 0);
	add_character(conv->root,
				  "キョ", "kyO",
				  3, 0);
	add_character(conv->root,
				  "キョ", "kYo",
				  3, 0);
	add_character(conv->root,
				  "キョ", "kYO",
				  3, 0);
	add_character(conv->root,
				  "キョ", "Kyo",
				  3, 0);
	add_character(conv->root,
				  "キョ", "KyO",
				  3, 0);
	add_character(conv->root,
				  "キョ", "KYo",
				  3, 0);
	add_character(conv->root,
				  "キョ", "KYO",
				  3, 0);
	add_character(conv->root,
				  "シャ", "shA",
				  3, 0);
	add_character(conv->root,
				  "シャ", "sHa",
				  3, 0);
	add_character(conv->root,
				  "シャ", "sHA",
				  3, 0);
	add_character(conv->root,
				  "シャ", "Sha",
				  3, 0);
	add_character(conv->root,
				  "シャ", "ShA",
				  3, 0);
	add_character(conv->root,
				  "シャ", "SHa",
				  3, 0);
	add_character(conv->root,
				  "シャ", "SHA",
				  3, 0);
	add_character(conv->root,
				  "シュ", "shU",
				  3, 0);
	add_character(conv->root,
				  "シュ", "sHu",
				  3, 0);
	add_character(conv->root,
				  "シュ", "sHU",
				  3, 0);
	add_character(conv->root,
				  "シュ", "Shu",
				  3, 0);
	add_character(conv->root,
				  "シュ", "ShU",
				  3, 0);
	add_character(conv->root,
				  "シュ", "SHu",
				  3, 0);
	add_character(conv->root,
				  "シュ", "SHU",
				  3, 0);
	add_character(conv->root,
				  "ショ", "shO",
				  3, 0);
	add_character(conv->root,
				  "ショ", "sHo",
				  3, 0);
	add_character(conv->root,
				  "ショ", "sHO",
				  3, 0);
	add_character(conv->root,
				  "ショ", "Sho",
				  3, 0);
	add_character(conv->root,
				  "ショ", "ShO",
				  3, 0);
	add_character(conv->root,
				  "ショ", "SHo",
				  3, 0);
	add_character(conv->root,
				  "ショ", "SHO",
				  3, 0);
	add_character(conv->root,
				  "チャ", "chA",
				  3, 0);
	add_character(conv->root,
				  "チャ", "cHa",
				  3, 0);
	add_character(conv->root,
				  "チャ", "cHA",
				  3, 0);
	add_character(conv->root,
				  "チャ", "Cha",
				  3, 0);
	add_character(conv->root,
				  "チャ", "ChA",
				  3, 0);
	add_character(conv->root,
				  "チャ", "CHa",
				  3, 0);
	add_character(conv->root,
				  "チャ", "CHA",
				  3, 0);
	add_character(conv->root,
				  "チュ", "chU",
				  3, 0);
	add_character(conv->root,
				  "チュ", "cHu",
				  3, 0);
	add_character(conv->root,
				  "チュ", "cHU",
				  3, 0);
	add_character(conv->root,
				  "チュ", "Chu",
				  3, 0);
	add_character(conv->root,
				  "チュ", "ChU",
				  3, 0);
	add_character(conv->root,
				  "チュ", "CHu",
				  3, 0);
	add_character(conv->root,
				  "チュ", "CHU",
				  3, 0);
	add_character(conv->root,
				  "チョ", "chO",
				  3, 0);
	add_character(conv->root,
				  "チョ", "cHo",
				  3, 0);
	add_character(conv->root,
				  "チョ", "cHO",
				  3, 0);
	add_character(conv->root,
				  "チョ", "Cho",
				  3, 0);
	add_character(conv->root,
				  "チョ", "ChO",
				  3, 0);
	add_character(conv->root,
				  "チョ", "CHo",
				  3, 0);
	add_character(conv->root,
				  "チョ", "CHO",
				  3, 0);
	add_character(conv->root,
				  "ニャ", "nyA",
				  3, 0);
	add_character(conv->root,
				  "ニャ", "nYa",
				  3, 0);
	add_character(conv->root,
				  "ニャ", "nYA",
				  3, 0);
	add_character(conv->root,
				  "ニャ", "Nya",
				  3, 0);
	add_character(conv->root,
				  "ニャ", "NyA",
				  3, 0);
	add_character(conv->root,
				  "ニャ", "NYa",
				  3, 0);
	add_character(conv->root,
				  "ニャ", "NYA",
				  3, 0);
	add_character(conv->root,
				  "ニュ", "nyU",
				  3, 0);
	add_character(conv->root,
				  "ニュ", "nYu",
				  3, 0);
	add_character(conv->root,
				  "ニュ", "nYU",
				  3, 0);
	add_character(conv->root,
				  "ニュ", "Nyu",
				  3, 0);
	add_character(conv->root,
				  "ニュ", "NyU",
				  3, 0);
	add_character(conv->root,
				  "ニュ", "NYu",
				  3, 0);
	add_character(conv->root,
				  "ニュ", "NYU",
				  3, 0);
	add_character(conv->root,
				  "ニョ", "nyO",
				  3, 0);
	add_character(conv->root,
				  "ニョ", "nYo",
				  3, 0);
	add_character(conv->root,
				  "ニョ", "nYO",
				  3, 0);
	add_character(conv->root,
				  "ニョ", "Nyo",
				  3, 0);
	add_character(conv->root,
				  "ニョ", "NyO",
				  3, 0);
	add_character(conv->root,
				  "ニョ", "NYo",
				  3, 0);
	add_character(conv->root,
				  "ニョ", "NYO",
				  3, 0);
	add_character(conv->root,
				  "ミャ", "myA",
				  3, 0);
	add_character(conv->root,
				  "ミャ", "mYa",
				  3, 0);
	add_character(conv->root,
				  "ミャ", "mYA",
				  3, 0);
	add_character(conv->root,
				  "ミャ", "Mya",
				  3, 0);
	add_character(conv->root,
				  "ミャ", "MyA",
				  3, 0);
	add_character(conv->root,
				  "ミャ", "MYa",
				  3, 0);
	add_character(conv->root,
				  "ミャ", "MYA",
				  3, 0);
	add_character(conv->root,
				  "ミュ", "myU",
				  3, 0);
	add_character(conv->root,
				  "ミュ", "mYu",
				  3, 0);
	add_character(conv->root,
				  "ミュ", "mYU",
				  3, 0);
	add_character(conv->root,
				  "ミュ", "Myu",
				  3, 0);
	add_character(conv->root,
				  "ミュ", "MyU",
				  3, 0);
	add_character(conv->root,
				  "ミュ", "MYu",
				  3, 0);
	add_character(conv->root,
				  "ミュ", "MYU",
				  3, 0);
	add_character(conv->root,
				  "ミョ", "myO",
				  3, 0);
	add_character(conv->root,
				  "ミョ", "mYo",
				  3, 0);
	add_character(conv->root,
				  "ミョ", "mYO",
				  3, 0);
	add_character(conv->root,
				  "ミョ", "Myo",
				  3, 0);
	add_character(conv->root,
				  "ミョ", "MyO",
				  3, 0);
	add_character(conv->root,
				  "ミョ", "MYo",
				  3, 0);
	add_character(conv->root,
				  "ミョ", "MYO",
				  3, 0);
	add_character(conv->root,
				  "リャ", "ryA",
				  3, 0);
	add_character(conv->root,
				  "リャ", "rYa",
				  3, 0);
	add_character(conv->root,
				  "リャ", "rYA",
				  3, 0);
	add_character(conv->root,
				  "リャ", "Rya",
				  3, 0);
	add_character(conv->root,
				  "リャ", "RyA",
				  3, 0);
	add_character(conv->root,
				  "リャ", "RYa",
				  3, 0);
	add_character(conv->root,
				  "リャ", "RYA",
				  3, 0);
	add_character(conv->root,
				  "リャ", "lyA",
				  3, 0);
	add_character(conv->root,
				  "リャ", "lYa",
				  3, 0);
	add_character(conv->root,
				  "リャ", "lYA",
				  3, 0);
	add_character(conv->root,
				  "リャ", "Lya",
				  3, 0);
	add_character(conv->root,
				  "リャ", "LyA",
				  3, 0);
	add_character(conv->root,
				  "リャ", "LYa",
				  3, 0);
	add_character(conv->root,
				  "リャ", "LYA",
				  3, 0);
	add_character(conv->root,
				  "リュ", "ryU",
				  3, 0);
	add_character(conv->root,
				  "リュ", "rYu",
				  3, 0);
	add_character(conv->root,
				  "リュ", "rYU",
				  3, 0);
	add_character(conv->root,
				  "リュ", "Ryu",
				  3, 0);
	add_character(conv->root,
				  "リュ", "RyU",
				  3, 0);
	add_character(conv->root,
				  "リュ", "RYu",
				  3, 0);
	add_character(conv->root,
				  "リュ", "RYU",
				  3, 0);
	add_character(conv->root,
				  "リュ", "lyU",
				  3, 0);
	add_character(conv->root,
				  "リュ", "lYu",
				  3, 0);
	add_character(conv->root,
				  "リュ", "lYU",
				  3, 0);
	add_character(conv->root,
				  "リュ", "Lyu",
				  3, 0);
	add_character(conv->root,
				  "リュ", "LyU",
				  3, 0);
	add_character(conv->root,
				  "リュ", "LYu",
				  3, 0);
	add_character(conv->root,
				  "リュ", "LYU",
				  3, 0);
	add_character(conv->root,
				  "リョ", "ryO",
				  3, 0);
	add_character(conv->root,
				  "リョ", "rYo",
				  3, 0);
	add_character(conv->root,
				  "リョ", "rYO",
				  3, 0);
	add_character(conv->root,
				  "リョ", "Ryo",
				  3, 0);
	add_character(conv->root,
				  "リョ", "RyO",
				  3, 0);
	add_character(conv->root,
				  "リョ", "RYo",
				  3, 0);
	add_character(conv->root,
				  "リョ", "RYO",
				  3, 0);
	add_character(conv->root,
				  "リョ", "lyO",
				  3, 0);
	add_character(conv->root,
				  "リョ", "lYo",
				  3, 0);
	add_character(conv->root,
				  "リョ", "lYO",
				  3, 0);
	add_character(conv->root,
				  "リョ", "Lyo",
				  3, 0);
	add_character(conv->root,
				  "リョ", "LyO",
				  3, 0);
	add_character(conv->root,
				  "リョ", "LYo",
				  3, 0);
	add_character(conv->root,
				  "リョ", "LYO",
				  3, 0);
	add_character(conv->root,
				  "ー", "-",
				  1, 0);
	add_character(conv->root,
				  "ギャ", "gyA",
				  3, 0);
	add_character(conv->root,
				  "ギャ", "gYa",
				  3, 0);
	add_character(conv->root,
				  "ギャ", "gYA",
				  3, 0);
	add_character(conv->root,
				  "ギャ", "Gya",
				  3, 0);
	add_character(conv->root,
				  "ギャ", "GyA",
				  3, 0);
	add_character(conv->root,
				  "ギャ", "GYa",
				  3, 0);
	add_character(conv->root,
				  "ギャ", "GYA",
				  3, 0);
	add_character(conv->root,
				  "ギュ", "gyU",
				  3, 0);
	add_character(conv->root,
				  "ギュ", "gYu",
				  3, 0);
	add_character(conv->root,
				  "ギュ", "gYU",
				  3, 0);
	add_character(conv->root,
				  "ギュ", "Gyu",
				  3, 0);
	add_character(conv->root,
				  "ギュ", "GyU",
				  3, 0);
	add_character(conv->root,
				  "ギュ", "GYu",
				  3, 0);
	add_character(conv->root,
				  "ギュ", "GYU",
				  3, 0);
	add_character(conv->root,
				  "ギョ", "gyO",
				  3, 0);
	add_character(conv->root,
				  "ギョ", "gYo",
				  3, 0);
	add_character(conv->root,
				  "ギョ", "gYO",
				  3, 0);
	add_character(conv->root,
				  "ギョ", "Gyo",
				  3, 0);
	add_character(conv->root,
				  "ギョ", "GyO",
				  3, 0);
	add_character(conv->root,
				  "ギョ", "GYo",
				  3, 0);
	add_character(conv->root,
				  "ギョ", "GYO",
				  3, 0);
	add_character(conv->root,
				  "ジャ", "zyA",
				  3, 0);
	add_character(conv->root,
				  "ジャ", "zYa",
				  3, 0);
	add_character(conv->root,
				  "ジャ", "zYA",
				  3, 0);
	add_character(conv->root,
				  "ジャ", "Zya",
				  3, 0);
	add_character(conv->root,
				  "ジャ", "ZyA",
				  3, 0);
	add_character(conv->root,
				  "ジャ", "ZYa",
				  3, 0);
	add_character(conv->root,
				  "ジャ", "ZYA",
				  3, 0);
	add_character(conv->root,
				  "ジュ", "zyU",
				  3, 0);
	add_character(conv->root,
				  "ジュ", "zYu",
				  3, 0);
	add_character(conv->root,
				  "ジュ", "zYU",
				  3, 0);
	add_character(conv->root,
				  "ジュ", "Zyu",
				  3, 0);
	add_character(conv->root,
				  "ジュ", "ZyU",
				  3, 0);
	add_character(conv->root,
				  "ジュ", "ZYu",
				  3, 0);
	add_character(conv->root,
				  "ジュ", "ZYU",
				  3, 0);
	add_character(conv->root,
				  "ジョ", "zyO",
				  3, 0);
	add_character(conv->root,
				  "ジョ", "zYo",
				  3, 0);
	add_character(conv->root,
				  "ジョ", "zYO",
				  3, 0);
	add_character(conv->root,
				  "ジョ", "Zyo",
				  3, 0);
	add_character(conv->root,
				  "ジョ", "ZyO",
				  3, 0);
	add_character(conv->root,
				  "ジョ", "ZYo",
				  3, 0);
	add_character(conv->root,
				  "ジョ", "ZYO",
				  3, 0);
	add_character(conv->root,
				  "ジャ", "Ja",
				  2, 0);
	add_character(conv->root,
				  "ジャ", "jA",
				  2, 0);
	add_character(conv->root,
				  "ジャ", "JA",
				  2, 0);
	add_character(conv->root,
				  "ジュ", "Ju",
				  2, 0);
	add_character(conv->root,
				  "ジュ", "jU",
				  2, 0);
	add_character(conv->root,
				  "ジュ", "JU",
				  2, 0);
	add_character(conv->root,
				  "ジョ", "Jo",
				  2, 0);
	add_character(conv->root,
				  "ジョ", "jO",
				  2, 0);
	add_character(conv->root,
				  "ジョ", "JO",
				  2, 0);
	add_character(conv->root,
				  "ヂャ", "jjA",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "jJa",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "jJA",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "Jja",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "JjA",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "JJa",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "JJA",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "dyA",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "dYa",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "dYA",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "Dya",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "DyA",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "DYa",
				  3, 0);
	add_character(conv->root,
				  "ヂャ", "DYA",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "jjU",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "jJu",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "jJU",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "Jju",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "JjU",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "JJu",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "JJU",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "dyU",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "dYu",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "dYU",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "Dyu",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "DyU",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "DYu",
				  3, 0);
	add_character(conv->root,
				  "ヂュ", "DYU",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "jjO",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "jJo",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "jJO",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "Jjo",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "JjO",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "JJo",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "JJO",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "dyO",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "dYo",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "dYO",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "Dyo",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "DyO",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "DYo",
				  3, 0);
	add_character(conv->root,
				  "ヂョ", "DYO",
				  3, 0);
	add_character(conv->root,
				  "ビャ", "byA",
				  3, 0);
	add_character(conv->root,
				  "ビャ", "bYa",
				  3, 0);
	add_character(conv->root,
				  "ビャ", "bYA",
				  3, 0);
	add_character(conv->root,
				  "ビャ", "Bya",
				  3, 0);
	add_character(conv->root,
				  "ビャ", "ByA",
				  3, 0);
	add_character(conv->root,
				  "ビャ", "BYa",
				  3, 0);
	add_character(conv->root,
				  "ビャ", "BYA",
				  3, 0);
	add_character(conv->root,
				  "ビュ", "byU",
				  3, 0);
	add_character(conv->root,
				  "ビュ", "bYu",
				  3, 0);
	add_character(conv->root,
				  "ビュ", "bYU",
				  3, 0);
	add_character(conv->root,
				  "ビュ", "Byu",
				  3, 0);
	add_character(conv->root,
				  "ビュ", "ByU",
				  3, 0);
	add_character(conv->root,
				  "ビュ", "BYu",
				  3, 0);
	add_character(conv->root,
				  "ビュ", "BYU",
				  3, 0);
	add_character(conv->root,
				  "ビョ", "byO",
				  3, 0);
	add_character(conv->root,
				  "ビョ", "bYo",
				  3, 0);
	add_character(conv->root,
				  "ビョ", "bYO",
				  3, 0);
	add_character(conv->root,
				  "ビョ", "Byo",
				  3, 0);
	add_character(conv->root,
				  "ビョ", "ByO",
				  3, 0);
	add_character(conv->root,
				  "ビョ", "BYo",
				  3, 0);
	add_character(conv->root,
				  "ビョ", "BYO",
				  3, 0);
	add_character(conv->root,
				  "ピャ", "pyA",
				  3, 0);
	add_character(conv->root,
				  "ピャ", "pYa",
				  3, 0);
	add_character(conv->root,
				  "ピャ", "pYA",
				  3, 0);
	add_character(conv->root,
				  "ピャ", "Pya",
				  3, 0);
	add_character(conv->root,
				  "ピャ", "PyA",
				  3, 0);
	add_character(conv->root,
				  "ピャ", "PYa",
				  3, 0);
	add_character(conv->root,
				  "ピャ", "PYA",
				  3, 0);
	add_character(conv->root,
				  "ピュ", "pyU",
				  3, 0);
	add_character(conv->root,
				  "ピュ", "pYu",
				  3, 0);
	add_character(conv->root,
				  "ピュ", "pYU",
				  3, 0);
	add_character(conv->root,
				  "ピュ", "Pyu",
				  3, 0);
	add_character(conv->root,
				  "ピュ", "PyU",
				  3, 0);
	add_character(conv->root,
				  "ピュ", "PYu",
				  3, 0);
	add_character(conv->root,
				  "ピュ", "PYU",
				  3, 0);
	add_character(conv->root,
				  "ピョ", "pyO",
				  3, 0);
	add_character(conv->root,
				  "ピョ", "pYo",
				  3, 0);
	add_character(conv->root,
				  "ピョ", "pYO",
				  3, 0);
	add_character(conv->root,
				  "ピョ", "Pyo",
				  3, 0);
	add_character(conv->root,
				  "ピョ", "PyO",
				  3, 0);
	add_character(conv->root,
				  "ピョ", "PYo",
				  3, 0);
	add_character(conv->root,
				  "ピョ", "PYO",
				  3, 0);
	add_character(conv->root,
				  "ァ", ";A",
				  2, 0);
	add_character(conv->root,
				  "ィ", ";I",
				  2, 0);
	add_character(conv->root,
				  "ゥ", ";U",
				  2, 0);
	add_character(conv->root,
				  "ェ", ";E",
				  2, 0);
	add_character(conv->root,
				  "ォ", ";O",
				  2, 0);
	add_character(conv->root,
				  "ッ", ";tsU",
				  4, 0);
	add_character(conv->root,
				  "ッ", ";tSu",
				  4, 0);
	add_character(conv->root,
				  "ッ", ";tSU",
				  4, 0);
	add_character(conv->root,
				  "ッ", ";Tsu",
				  4, 0);
	add_character(conv->root,
				  "ッ", ";TsU",
				  4, 0);
	add_character(conv->root,
				  "ッ", ";TSu",
				  4, 0);
	add_character(conv->root,
				  "ッ", ";TSU",
				  4, 0);
	add_character(conv->root,
				  "ヵ", ";Ka",
				  2, 0);
	add_character(conv->root,
				  "ヵ", ";kA",
				  2, 0);
	add_character(conv->root,
				  "ヵ", ";KA",
				  2, 0);
	add_character(conv->root,
				  "ヶ", ";Ke",
				  2, 0);
	add_character(conv->root,
				  "ヶ", ";kE",
				  2, 0);
	add_character(conv->root,
				  "ヶ", ";KE",
				  2, 0);
	add_character(conv->root,
				  "ヴァ", "Va",
				  2, 0);
	add_character(conv->root,
				  "ヴァ", "vA",
				  2, 0);
	add_character(conv->root,
				  "ヴァ", "VA",
				  2, 0);
	add_character(conv->root,
				  "ヴィ", "Vi",
				  2, 0);
	add_character(conv->root,
				  "ヴィ", "vI",
				  2, 0);
	add_character(conv->root,
				  "ヴィ", "VI",
				  2, 0);
	add_character(conv->root,
				  "ヴ", "Vu",
				  2, 0);
	add_character(conv->root,
				  "ヴ", "vU",
				  2, 0);
	add_character(conv->root,
				  "ヴ", "VU",
				  2, 0);
	add_character(conv->root,
				  "ヴェ", "Ve",
				  2, 0);
	add_character(conv->root,
				  "ヴェ", "vE",
				  2, 0);
	add_character(conv->root,
				  "ヴェ", "VE",
				  2, 0);
	add_character(conv->root,
				  "ヴォ", "Vo",
				  2, 0);
	add_character(conv->root,
				  "ヴォ", "vO",
				  2, 0);
	add_character(conv->root,
				  "ヴォ", "VO",
				  2, 0);
	add_character(conv->root,
				  "ファ", "Fa",
				  2, 0);
	add_character(conv->root,
				  "ファ", "fA",
				  2, 0);
	add_character(conv->root,
				  "ファ", "FA",
				  2, 0);
	add_character(conv->root,
				  "フィ", "Fi",
				  2, 0);
	add_character(conv->root,
				  "フィ", "fI",
				  2, 0);
	add_character(conv->root,
				  "フィ", "FI",
				  2, 0);
	add_character(conv->root,
				  "フェ", "Fe",
				  2, 0);
	add_character(conv->root,
				  "フェ", "fE",
				  2, 0);
	add_character(conv->root,
				  "フェ", "FE",
				  2, 0);
	add_character(conv->root,
				  "フォ", "Fo",
				  2, 0);
	add_character(conv->root,
				  "フォ", "fO",
				  2, 0);
	add_character(conv->root,
				  "フォ", "FO",
				  2, 0);
	// punctuation
	add_character(conv->root,
				  "｛", "{",
				  1, 0);
	add_character(conv->root,
				  "｝", "}",
				  1, 0);
	add_character(conv->root,
				  "（", "(",
				  1, 0);
	add_character(conv->root,
				  "）", ")",
				  1, 0);
	add_character(conv->root,
				  "［", "[",
				  1, 0);
	add_character(conv->root,
				  "］", "]",
				  1, 0);
	add_character(conv->root,
				  "【", "[[",
				  2, 0);
	add_character(conv->root,
				  "【", "[(",
				  2, 0);
	add_character(conv->root,
				  "】", "]]",
				  2, 0);
	add_character(conv->root,
				  "】", ")]",
				  2, 0);
	add_character(conv->root, "、",
				  ",",
				  1, 0);
	add_character(conv->root,
				  "。", ".",
				  1, 0);
	add_character(conv->root,
				  "・", "'.",
				  1, 0);
	add_character(conv->root,
				  "「", "'[",
				  2, 0);
	add_character(conv->root,
				  "「", "['",
				  2, 0);
	add_character(conv->root,
				  "」", "']",
				  2, 0);
	add_character(conv->root,
				  "」", "]'",
				  2, 0);
	add_character(conv->root,
				  "『", "\"[",
				  2, 0);
	add_character(conv->root,
				  "『", "[\"",
				  2, 0);
	add_character(conv->root,
				  "』", "\"]",
				  2, 0);
	add_character(conv->root,
				  "』", "]\"",
				  2, 0);
	add_character(conv->root,
				  "　", "  ",
				  2, 0);
	add_character(conv->root,
				  "〜", "~",
				  1, 0);
	add_character(conv->root,
				  "：", ":",
				  1, 0);
	add_character(conv->root,
				  "！", "!",
				  1, 0);
	add_character(conv->root,
				  "？", "?",
				  1, 0);
	add_character(conv->root,
				  "？", "?",
				  1, 0);
	add_character(conv->root,
				  "0", "0",
				  1, 0);
	add_character(conv->root,
				  "1", "1",
				  1, 0);
	add_character(conv->root,
				  "2", "2",
				  1, 0);
	add_character(conv->root,
				  "3", "3",
				  1, 0);
	add_character(conv->root,
				  "4", "4",
				  1, 0);
	add_character(conv->root,
				  "5", "5",
				  1, 0);
	add_character(conv->root,
				  "6", "6",
				  1, 0);
	add_character(conv->root,
				  "7", "7",
				  1, 0);
	add_character(conv->root,
				  "8", "8",
				  1, 0);
	add_character(conv->root,
				  "9", "9",
				  1, 0);
	add_character(conv->root,
				  "／", "/",
				  1, 0);
	add_character(conv->root,
				  "＊", "*",
				  1, 0);
}

static size_t print_kana_found(int col)
{
	int pr_line = col - 4;
	size_t i, line = 1;
	move(line, 1);
	for (i = 0; i < printed_kana_len; i++)
	{
		printw("%s", printed_kana[i]);
		int x, y;
		getyx(stdscr, y, x);
		if (x > pr_line)
		{
			move(++line, 1);
		}
		(void)y;
	}
	path[path_i] = 0;
	printw("%s", path);
	return line;
}
static void add_kana(char *kana)
{
	if (kana)
		printed_kana[printed_kana_len++] = kana;
}
static void process_char(int ch)
{
	if (ch == KEY_BACKSPACE)
	{
		if (path_i == 0)
		{
			if (printed_kana_len)
				--printed_kana_len;
		}
		else
		{
			path_i = 0;
			conv->location = conv->root;
		}
	}
	else if (ch == 'q' || ch == 'Q')
	{
		exit_rtok();
	}
	else
	{
		path[path_i++] = (char)ch;
		unsigned char fres = feed_converter(conv, (char)ch);
		if (!(fres & 1))
		{
			add_kana(get_current_conversion(conv));
			path_i = 0;
			conv->location = conv->root;
			return;
		}
		if (!(fres & 2))
		{
			add_kana(get_current_conversion(conv));
			path_i = 0;
			conv->location = conv->root;
			return;
		}
	}
}

int main(int argc, char **argv)
{
	FILE *out;
	if (argc == 2)
	{
		out = fopen(argv[1], "w");
	}
	else
	{
		return 1;
	}
	setlocale(LC_ALL, "");
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	int row, col;

	init();

	if (!setjmp(exit_buf))
	{
		while (1)
		{
			getmaxyx(stdscr, row, col);
			clear();
			print_kana_found(col);
			process_char(getch());
			refresh();
		}
	}

	(void)row;
	endwin();
	size_t i;
	for (i = 0; i < printed_kana_len; i++)
	{
		fprintf(out, "%s", printed_kana[i]);
	}
	fclose(out);
	return 0;
}
