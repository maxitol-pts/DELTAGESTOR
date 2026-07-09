#ifndef DELTAG_Basics_h
#define DELTAG_Basics_h
#include <filesystem>
#include <iostream>
namespace dg{
    namespace fs = std::filesystem;
inline void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
} 
namespace dg{
   inline void log(std::string text)
{
    std::cout << text << std::endl;
}
}
#endif 