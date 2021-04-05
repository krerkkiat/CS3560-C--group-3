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

// text file
#include <string>
#include <iostream>
#include <fstream>



using json = nlohmann::json;
using aegis::rest::rest_reply;
using aegis::gateway::objects::message;

void replace(std::string username, std::string item, int num);

int main(int argc, char * argv[])
{
    using namespace std::chrono_literals;
    try
    {
        // Create bot object
 
 
 
 
 ////////////////////////////////////////THIS IS THE BOT TOKEN LINE
 
 
 
 
 
 // These callbacks are what the lib calls when messages come in
        bot.set_on_message_create([&](aegis::gateway::events::message_create obj)
        {
                try
                {
                    //get snowflakes related to this message
                    // C++17 version
                    //const auto [channel_id, guild_id, message_id, member_id] = obj.msg.get_related_ids();
                    const aegis::snowflake channel_id = obj.msg.get_channel().get_id();
                    const aegis::snowflake guild_id = obj.msg.get_guild().get_id();
                    const aegis::snowflake message_id = obj.msg.get_id();
#if !defined(AEGIS_DISABLE_ALL_CACHE)
                    const aegis::snowflake member_id = obj.msg.get_user().get_id();
#else
                    const aegis::snowflake member_id = obj.msg.author.id;
#endif

                    // Is message author myself?
                    if (member_id == bot.get_id())
                        return;

                    // Ignore bot messages and DMs
                    if (obj.msg.is_bot() || !obj.msg.has_guild())
                        return;

                    auto& _channel = obj.msg.get_channel();
                    auto& _guild = _channel.get_guild();
                    auto& username = obj.msg.author.username;

                    std::string content{ obj.msg.get_content() };

                    // Simple Hi response
                                                                   // file work

                    bool found = 0;
                    std::string user = username;
                    std::ifstream infile;
                    infile.open("testfile.txt");
                    while (!infile.eof())                          // search for username
                    {
                        std::string temp = "";
                        getline(infile, temp);
                        if(temp == user){
                            found = 1;
                        }
                    }
                    infile.close();                                         //file output
                    if (found == 0) {
                        _channel.create_message(fmt::format("Hello {}, you must be new here, type 'bm start' to get started", username));
                        std::ofstream outfile;                                                  
                        outfile.open("testfile.txt", std::ofstream::out | std::ofstream::app);
                        outfile << username << std::endl << "1" << std::endl << "0" << std::endl << "100" << std::endl << "no" << std::endl << "no" << std::endl;
                        outfile.close();
                    }else {
                        std::string plevel = "";
                        std::string pgold = "";
                        std::string phealth = "";
                        std::string psword = "";
                        std::string parmor = "";
                        bool find = 0;
                        infile.open("testfile.txt");
                        while (!infile.eof() && find != 1)                          // search for username
                        {
                            std::string temp = "";
                            getline(infile, temp);
                            if (temp == user) {
                                find = 1;
                            }
                        }
                        //if (find == 1) {

                        getline(infile, plevel);                   // getting profile info
                        getline(infile, pgold);
                        getline(infile, phealth);
                        getline(infile, psword);
                        getline(infile, parmor);

                        //}
                        infile.close();
                            
                        if (content == "test")                              // manipulating profile data
                        {
                            replace(username, "gold", 3333);
                        }
                        
                        if (content == "bm profile") {
                            
                            _channel.create_message(fmt::format("{}'s profile:", user));
                            _channel.create_message(fmt::format("   Level: {}", plevel));
                            _channel.create_message(fmt::format("   Gold: {}", pgold));
                            _channel.create_message(fmt::format("   Health: {}", phealth));
                            _channel.create_message(fmt::format("   Sword? {}", psword));
                            _channel.create_message(fmt::format("   Armor? {}", parmor));
                        }
                        if (content == "bm start") {
                            _channel.create_message("Hello, welcome to BaerMelk \n This is a freeroaming game where you can adventure to gather resources, fight mobs, and gain experience to defeat the main boss, BaerMelk.");
                        }
                        if (content == "bm help") {
                            _channel.create_message("Baer Melk Commands: \n bm shop \n bm adventure \n bm buy [item] \n bm sell [item]");
                        }if (content == "bm shop") {
                            _channel.create_message("Shop: \n- Sword (100 gold) \n- Bow(50 gold) \n- Arrows(25 gold) \n- New Armor(200 gold) \n- Health Kit(100 gold) \n- Bandages(50 gold) ");
                        }
                        if (content == "bm adventure") {
                            int gold;
                            int health;
                            bool flee = false;
                            _channel.create_message("You may encounter dangerous mobs and/or find loot...");
                            srand(time(0));
                            int num = rand() % 3 + 1;
                            switch (num) {
                            case 0:
                                gold = rand() % 25 + 25;
                                _channel.create_message(fmt::format("You found {} gold!", gold));
                                break;
                            case 1:
                                gold = rand() % 25 + 25;
                                _channel.create_message(fmt::format("You found {} gold!", gold));
                                //_channel.create_message("You found encountered a poisonous spider. \n Do you wish to flee or kill?");
                                //std::string content{ obj.msg.get_content() };
                                //if (content == "flee") {
                                //    _channel.create_message("You got away safely");
                                //}
                                //else if (content == "kill") {
                                //    health = rand() % 15 + 10;
                                //    _channel.create_message(fmt::format("You lost {} health!", health));
                                //}
                                break;
                            case 2:
                                health = rand() % 25 + 25;
                                _channel.create_message(fmt::format("You killed a giant spider! But you lost {} health :(", health));
                                break;
                            case 3:
                                _channel.create_message("You found a set of old armor!");
                                break;
                            }
                        }
                        }
                // Send a message, wait for message to successfully be sent, then react to that message
                 if (content == "~Delay")
                {
                    _channel.create_message("First message").then([](message msg)
                    {
                        // add a reaction to that new message
                        msg.create_reaction("success:429554838083207169");
                    });
                }
                else if (content == "~exit")
                {
                    bot.shutdown();
                    return;
                }

            }
            catch (std::exception & e)
            {
                std::cout << "Error: " << e.what() << '\n';
            }
            return;
        });

        // start the bot
        bot.run();
        // yield thread execution to the library
        bot.yield();
    }
    catch (std::exception & e)
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

void replace(std::string username, std::string item, int num)
{
std::ifstream infile;
std::ofstream outfile;
infile.open("testfile.txt");
outfile.open("temp.txt");
int loopNum = 0;

std::string line;

if (item == "gold") {
    loopNum = 1;
}
if (item == "level") {
    loopNum = 0;
}
if (item == "health") {
    loopNum = 2;
}
if (item == "sword") {
    loopNum = 3;
}
if (item == "armor") {
    loopNum = 4;
}


while (!infile.eof()) {

    getline(infile, line);
    if (line == username) {
        outfile << line << std::endl;
        for (int i = 0; i < loopNum; i++) {
            getline(infile, line);
            outfile << line << std::endl;
        }
        getline(infile, line);
        outfile << num << std::endl;
    }
    else {
        outfile << line << std::endl;
    }
}
outfile.close();
infile.close();
remove("testfile.txt");
rename("temp.txt", "testfile.txt");

}