#include <string>
#include <iostream>
#include <fstream>

#include <aegis.hpp>

#include "utils.hpp"

void replace(std::string username, std::string item, std::string change)
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
    if (item == "experience") {
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
    if (item == "bow") {
        loopNum = 5;
    }
    if (item == "arrows") {
        loopNum = 6;
    }
    if (item == "healthkit") {
        loopNum = 7;
    }
    if (item == "bandages") {
        loopNum = 8;
    }
    if (item == "bm") {
        loopNum = 9;
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
            outfile << change << std::endl;
        }
        else {
            outfile << line << std::endl;
        }
    }
    outfile.close();
    infile.close();
    remove("testfile.txt");
    rename("temp.txt", "testfile.txt");
    deleteSpace();
}

void deleteSpace() {
    std::ifstream infile;
    std::ofstream outfile;
    infile.open("testfile.txt");
    outfile.open("temp.txt");
    std::string line;

    while (!infile.eof()) {

        getline(infile, line);
        if (line == "") {

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

void pdeath(std::string username, aegis::channel &_chan) {
    std::vector<aegis::gateway::objects::field> death;
    aegis::gateway::objects::field dying;
    dying.name("You Died");
    dying.value("Try again?");
    death.push_back(dying);
    aegis::gateway::objects::embed sadness;
    sadness.title("Yikes");
    sadness.color(31);
    sadness.fields(death);
    _chan.create_message_embed("", sadness);
    replace(username, "experience", "0");
    replace(username, "gold", "0");
    replace(username, "health", "100");
    replace(username, "sword", "no");
    replace(username, "armor", "no");
    replace(username, "bow", "no");
    replace(username, "bandages", "0");
    replace(username, "healthkit", "no");
    replace(username, "arrows", "0");
    replace(username, "bm", "0");
}
