//
// Copyright (c) 2018 potato-framework by Loïc Boutter (https://github.com/Lo-X/potato-framework)
//
// Everyone is permitted to copy and distribute verbatim or modified
// copies of this license document, and changing it is allowed as long
// as the name is changed.
//
//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//
//  0. You just DO WHAT THE FUCK YOU WANT TO.
//

#include <bandit/bandit.h>
#include <utils/json.hpp>

using namespace bandit;
using namespace snowhouse;

go_bandit([]() {
    describe("JSON parser", []() {
        it("should serialize data - array style", [&]() {
            spud::Json j;
            j["pi"] = 3.141;
            j["happy"] = true;
            j["name"] = "Niels";
            j["nothing"] = nullptr;
            j["answer"]["everything"] = 42;
            j["list"] = { 1, 0, 2 };
            j["object"] = { {"currency", "USD"}, {"value", 42.99} };

            AssertThat(j.dump(), Equals("{\"answer\":{\"everything\":42},\"happy\":true,\"list\":[1,0,2],\"name\":\"Niels\",\"nothing\":null,\"object\":{\"currency\":\"USD\",\"value\":42.99},\"pi\":3.141}"));
        });

        it("should serialize data - initializer style", [&]() {
            spud::Json j{
                {"pi", 3.141},
                {"happy", true},
                {"name", "Niels"},
                {"nothing", nullptr},
                {"answer", {
                    {"everything", 42}
                }},
                {"list", {1, 0, 2}},
                {"object", {
                    {"currency", "USD"},
                    {"value", 42.99}
                }}
            };

            AssertThat(j.dump(), Equals("{\"answer\":{\"everything\":42},\"happy\":true,\"list\":[1,0,2],\"name\":\"Niels\",\"nothing\":null,\"object\":{\"currency\":\"USD\",\"value\":42.99},\"pi\":3.141}"));
        });

        it("should deserialize data", [&]() {
            spud::Json j = spud::Json::parse("{ \"happy\": true, \"pi\": 3.141 }");

            AssertThat(j["happy"], Equals(true));
            AssertThat(j["pi"], Equals(3.141));
        });
    });
});