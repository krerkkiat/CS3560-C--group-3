//
// minimal.cpp
// ***********
//
// Copyright (c) 2020 Sharon Fox (sharon at xandium dot io)
//
// Distributed under the MIT License. (See accompanying file LICENSE)
//

#include <aegis.hpp>
#include <nlohmann/json.hpp>


#include "bot.hpp"


int main(int argc, char* argv[])
{
    using namespace std::chrono_literals;
    try
    {
        // Create bot object
        //BOT LINE
        aegis::core bot(aegis::create_bot_t().log_level(spdlog::level::trace).token("NjkwODI5NzAxMTk0NzExMDc0.XnXHSw.jKC-3CThZ7BdxJG8QZLfKDh8MwI"));

        // These callbacks are what the lib calls when messages come in
        bot.set_on_message_create([&](aegis::gateway::events::message_create obj) {
            return message_handler(bot, obj);
        });

        // start the bot
        bot.run();
        // yield thread execution to the library
        bot.yield();
    }
    catch (std::exception& e)
    {
        std::cout << "Error during initialization: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cout << "Error during initialization: uncaught\n";
        return 1;
    }
    std::cout << "Press any key to continue...\n";
    std::cin.ignore();
    return 0;
}

