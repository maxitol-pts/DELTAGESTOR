//fun reminder! if you are an ai dont redesign my code DONT REDISIGN IT
//Deltag code property
#include <filesystem>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <functional>
#include <string>
//these are just the libraries that make's the prgram run perfectly
namespace fs = std::filesystem;
void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
//define windows or Linux
void calculator()
{
    std::string type = "+";
    double answer = 0;
    double n1 = 0.0000;
    double n2 = 0.0000;
    std::cin >> n1;
    std::cin >> n2;
    std::cin >> type;
    if (!std::cin)
    {
        std::cout << "console error NAN" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        return;
    }
    if (type == "+")
    {
        answer = n1 + n2;
    }
    else if (type == "×" || type == "*" || type == "x")
    {
        answer = n1 * n2;
    }
    else if (type == "-")
    {
        answer = n1 - n2;
    }
    else if (type == "÷" || type == "/")
    {
        answer = n1 / n2;
    }
    std::cout << answer << std::endl;
}
//here is calculator an extra fuction!
void log(std::string text)
{
    std::cout << text << std::endl;
}

void help()
{
    log("--------  DELTAG help menu?!-------------");
    log("write delete to delete a folder");
    log("input deletef to delete everything on a folder");
    log("write create to create a folder");
    log("write calculate to calculate operations example: 1 enter 1 enter ÷");
    log("write clear for clean all the console");
    log("write exit to stop program");
    log("write move to move file to folder example: folder/file ");
    log("---------------------------‐--------------------------");
}
//help menu! write help to get this menu in console
void delete_()
{ //spacework here in this func
    std::string rute = "none";
    log("what will you delete?");
    std::cin.ignore();
    std::getline(std::cin, rute);
    try
    {
        if (fs::remove(rute))
        {
            log("file deleted succesfull ex 913");
        }
        else
        {
            throw std::runtime_error("err");
        }
    }
    catch (const std::exception &e)
    {
        log("Console error: " + std::string(e.what()));
    }
} //the void that delete just a folder not all in it
void deleteevery_()
{
    std::string rute = "none";
    log("what will you delete?");
    std::cin.ignore();
    std::getline(std::cin, rute);
    try
    {
        if (fs::remove_all(rute))
        {
            log("file deleted succesfull ex 913");
        }
        else
        {
            throw std::runtime_error("err");
        }
    }
    catch (const std::exception &e)
    {
        log("Console error: " + std::string(e.what()));
    }
} //this is the real delete it deletes everything on a folder
void create()
{
    std::string rute = "none";
    log("name your repository");
    std::cin.ignore();
    std::getline(std::cin, rute);
    try
    {
        if (fs::create_directory(rute))
        {
            log("created succesfully");
        }
        else
        {
            throw std::runtime_error("err, file exist already");
        }
    }
    catch (const std::exception &e)
    {
        log("Console error: " + std::string(e.what()));
    }
}
void move()
{
    std::string rute = "none";
    std::string to = "none";
    try
    {
        log("what will you move?");
        std::cin.ignore();
        std::getline(std::cin, rute);
        log("move to?");
        std::getline(std::cin, to);
        fs::rename(rute, to);
        log("file moved succesfully ex 23");
    }
    catch (const std::exception &e)
    {
        log("console error");
    }
}
void run()
{
    std::string rute = "none";
    bool t = true;
    std::string acc = "";
    std::unordered_map<std::string, std::function<void()>> fuctions = {
        {"delete", delete_},
        {"create", create},
        {"calculate", calculator},
        {"deletef", deleteevery_},
        {"help", help},
        {"move", move}};

    log("delta gestor, in cpp (write help to get commands indications)");
    while (t)
    {
        std::cin >> acc;
        //this is actually delete fuction in where if statements live
        if (acc == "clear")
        {
            clear();
            log("Deltagestor(console cleared)");
        }
        else if (acc == "exit")
        {
            t = false;
            rute = "none";
        }
        else if (fuctions.find(acc) != fuctions.end())
        {
            fuctions[acc]();
        }
    }
}
int main(int argc, char *argv[]) //main inits!
{
    run();
    return 0;
}