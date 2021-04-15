#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_DISABLE_EXCEPTIONS
#include "catch.hpp"

#include <aegis.hpp>

#include "bot.hpp"

TEST_CASE("Test get guild", "[test]") {
    // This setup is a bit awkward since all source code are in the same function.
    aegis::core bot(aegis::create_bot_t().log_level(spdlog::level::trace).token("NjkwODI5NzAxMTk0NzExMDc0.XnXHSw.jKC-3CThZ7BdxJG8QZLfKDh8MwI"));

    // If we do not yield control back to the library, any API will fail.
    // Thus, ready event is used to run the test.
    bot.set_on_ready([&](aegis::gateway::events::ready obj) {

        // Replace the ID with your server ID.
        auto g = bot.find_guild(aegis::snowflake("687789803722637389"));

        std::cout << g->get_member_count() << '\n';
        std::cout << bot.get_guild_count() << '\n';
        std::cout << g->get_id() << '\n';

        REQUIRE(g->get_name() == "Sevena");

        bot.shutdown();
    });

    bot.run();
    bot.yield();
}
