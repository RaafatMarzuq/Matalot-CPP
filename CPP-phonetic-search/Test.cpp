#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of p and b")
{
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));

    string text2 = "salt and pepper";
    CHECK(find(text2, "zalt") == string("salt"));
    CHECK(find(text2, "salD") == string("salt"));
    CHECK(find(text2, "zALt") == string("salt"));
    CHECK(find(text2, "ant") == string("and"));
    CHECK(find(text2, "bebber") == string("pepper"));
    CHECK(find(text2, "PeBpEr") == string("pepper"));
    CHECK(find(text2, "AND") == string("and"));
    CHECK(find(text2, "ZALD") == string("salt"));
}
TEST_CASE("Test replacement of w and v , also of lower-case and upper-case")
{
    string text = "I bought a new volkswagen";
    CHECK(find(text, "volksvagen") == string("volkswagen"));
    CHECK(find(text, "wolkswagen") == string("volkswagen"));
    CHECK(find(text, "wolksvagen") == string("volkswagen"));
    CHECK(find(text, "WolksVagen") == string("volkswagen"));
    CHECK(find(text, "volkswagen") == string("volkswagen"));
    CHECK(find(text, "i") == string("I"));
    CHECK(find(text, "BuOght") == string("bought"));
    CHECK(find(text, "wulczvajen") == string("volkswagen"));
    CHECK(find(text, "VOLKSWagEN") == string("volkswagen"));
    CHECK(find(text, "NEW") == string("new"));
    CHECK(find(text, "BUOJHD") == string("bought"));
}

TEST_CASE("Test replacement of i and y ,also of  lower-case and upper-case")
{
    string text = "I know how to spill superkalifragilistikexpialigetisch";
    CHECK(find(text, "superkalyfragilystikexpyaligetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "SuperkalYfragIlistIkexpYaligetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "superkalIfragIlIstIkexpIalIgetIsch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "superkalifragilistikexpialigetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "zbill") == string("spill"));
    CHECK(find(text, "Huw") == string("how"));
    CHECK(find(text, "HOW") == string("how"));
    CHECK(find(text, "du") == string("to"));
    CHECK(find(text, "zoperkalifragilistikexpialigetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "suFerCalifraJilYstikexpialigetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "ZuperKaliFragYLiZtikexpYaLigetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "superkalifRAGYlistikEXpialigetisch") == string("superkalifragilistikexpialigetisch"));
}

TEST_CASE("Test replacement of j and g,also of  lower-case and upper-case")
{
    string text = "Sir Roger George Moore was an English actor best known for playing British secret agent James Bond";
    CHECK(find(text, "Rojer") == string("Roger"));
    CHECK(find(text, "georje") == string("George"));
    CHECK(find(text, "ajent") == string("agent"));
    CHECK(find(text, "games") == string("James"));
    CHECK(find(text, "james") == string("James"));
    CHECK(find(text, "Zir") == string("Sir"));
    CHECK(find(text, "syr") == string("Sir"));
    CHECK(find(text, "rujer") == string("Roger"));
    CHECK(find(text, "muuRE") == string("Moore"));
    CHECK(find(text, "enjlyzh") == string("English"));
}

TEST_CASE("Test replacement of more than two letters,also of  lower-case and upper-case")
{
    string text = "Roll the dice twice";
    CHECK(find(text, "tike") == string("dice"));
    CHECK(find(text, "rull") == string("Roll"));
    CHECK(find(text, "dhe") == string("the"));
    CHECK(find(text, "tvice") == string("twice"));
    CHECK(find(text, "DICe") == string("dice"));
    CHECK(find(text, "ROLL") == string("Roll"));
    CHECK(find(text, "DICE") == string("dice"));
    CHECK(find(text, "RolL") == string("Roll"));
    CHECK(find(text, "TVyce") == string("twice"));
    CHECK(find(text, "TvICE") == string("twice"));
    CHECK(find(text, "THE") == string("the"));
}
TEST_CASE("Test replacement ofmore than two letters,also lower-case and upper-case")
{
    string text = "the suspect was eating pizza";
    CHECK(find(text, "DHE") == string("the"));
    CHECK(find(text, "SuSbEcT") == string("suspect"));
    CHECK(find(text, "zozbekt") == string("suspect"));
    CHECK(find(text, "SUSPECT") == string("suspect"));
    CHECK(find(text, "Vaz") == string("was"));
    CHECK(find(text, "wAZ") == string("was"));
    CHECK(find(text, "eading") == string("eating"));
    CHECK(find(text, "eatynj") == string("eating"));
    CHECK(find(text, "EATING") == string("eating"));
    CHECK(find(text, "BiZza") == string("pizza"));
    CHECK(find(text, "bissa") == string("pizza"));
    CHECK(find(text, "PyzZa") == string("pizza"));
    CHECK(find(text, "PIZZA") == string("pizza"));
}
TEST_CASE("Test replacement ofmore than two letters,also lower-case and upper-case")
{
    string text = "The eagle has left the building";
    CHECK(find(text, "the") == string("The"));
    CHECK(find(text, "eajle") == string("eagle"));
    CHECK(find(text, "HAs") == string("has"));
    CHECK(find(text, "Haz") == string("has"));
    CHECK(find(text, "lept") == string("left"));
    CHECK(find(text, "LeFt") == string("left"));
    CHECK(find(text, "boilding") == string("building"));
    CHECK(find(text, "puildyng") == string("building"));
    CHECK(find(text, "BUILding") == string("building"));
    CHECK(find(text, "BUILDING") == string("building"));
}
TEST_CASE("Test replacement ofmore than two letters,also lower-case and upper-case")
{
    string text = "To be or not to be That is the question";
    CHECK(find(text, "do") == string("To"));
    CHECK(find(text, "pe") == string("be"));
    CHECK(find(text, "Be") == string("be"));
    CHECK(find(text, "ur") == string("or"));
    CHECK(find(text, "OR") == string("or"));
    CHECK(find(text, "dhAd") == string("That"));
    CHECK(find(text, "yz") == string("is"));
    CHECK(find(text, "Iz") == string("is"));
    CHECK(find(text, "koestion") == string("question"));
    CHECK(find(text, "CuestyUN") == string("question"));
    CHECK(find(text, "QUESTION") == string("question"));
}
TEST_CASE("Test replacement ofmore than two letters,also lower-case and upper-case")
{
    string text = "rick and morty are the best";
    CHECK(find(text, "ryck") == string("rick"));
    CHECK(find(text, "Rikk") == string("rick"));
    CHECK(find(text, "Riqq") == string("rick"));
    CHECK(find(text, "murty") == string("morty"));
    CHECK(find(text, "Morti") == string("morty"));
    CHECK(find(text, "mordi") == string("morty"));
    CHECK(find(text, "MORTY") == string("morty"));
    CHECK(find(text, "ARE") == string("are"));
    CHECK(find(text, "Pezt") == string("best"));
    CHECK(find(text, "fezT") == string("best"));
    CHECK(find(text, "RICC") == string("rick"));

    
}
