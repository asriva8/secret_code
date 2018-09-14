#include "secret_code.h"
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>


Secret_Code::Secret_Code()
{
    std::string str;
    std::cout<<"Enter the secret code for each alphabet from A-Z\n";
    for (int i=0; i<26; i++)
    {
        getline(std::cin, str);
        code.push_back(str);
    }
}
