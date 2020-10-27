/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 这个文件来自 GOSCPS(https://github.com/GOSCPS)
 * 使用 GOSCPS 许可证
 * File:    Main.cpp
 * Content: Main C++ Source File
 * Copyright (c) 2020 GOSCPS 保留所有权利.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <filesystem>
#include <vector>
#include <ctime>
#include <cstdlib>

constexpr auto Color_Red = "\033[31m";
constexpr auto Color_Null = "\033[0m";

using namespace std;

int main(int argc,char *argv[]){

    auto home = getenv("HOME");
    std::string home_s(home);
    
    std::filesystem::path p = std::filesystem::path(home_s) / ".Shell_Saying";

    if(argc != 1){
        p = std::filesystem::path(string(argv[1]));
    }

    //文件不存在
    if(!filesystem::exists(p)){
        std::cout << Color_Red << "File Not Found:" << p.filename() << Color_Null << endl;
        exit(-1);
    }

    //是个目录
    std::filesystem::directory_entry entry(p);
    if(entry.status().type() == std::filesystem::file_type::directory){
        std::cout << Color_Red << "Is a directory:" << p.filename() << Color_Null << endl;
        exit(-1);
    }

    ifstream ifs;
    ifs.open(filesystem::canonical(p));

    //打不开
    if(!ifs.is_open()){
        cout << Color_Red << "Open File Error:" << filesystem::canonical(p) << Color_Null << endl;
        exit(-1);
    }

    /*---OK---*/
    vector<string> saying_list;

    string buf;
    while(getline(ifs,buf)){
        saying_list.push_back(buf);
    }
    ifs.close();

    time_t a = 0;
    //输出
    srand(time(&a));

    cout << saying_list[rand() % (saying_list.size()-1)] << endl;
    
return 0;
}