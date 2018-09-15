#include "secret_code.h"
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<iomanip>


Secret_Code::Secret_Code()
{
    std::string str;
    std::cout<<"Enter the secret code for each alphabet from a-z\n";
    for (int i=0; i<26; i++)
    {
        std::cout<<"Enter code for "<<(char)(97+i)<<"\n";
        getline(std::cin, str);
        code.push_back(str);
    }
}

void Secret_Code::get_original_words()
{
    std::string str;
    int n;
    std::cout<<"Enter the number of words to convert into secret codes\n";
    std::cin>>n;
    getline(std::cin,str);  //This is done to remove a '\n' after receiving an input in n from use.
    original_words.clear();
    for (int i=0; i<n; i++)
    {   std::cout<<"Enter Word "<<i+1<<"\n";
        getline(std::cin,str);
        original_words.push_back(str);
    }

}

void Secret_Code::encrypt_words()
{
    encrypted_words.clear();
    std::string str;
    for (int i=0; i<original_words.size(); i++)
    {
        str.clear();
        for (int j=0; j<original_words[i].size(); j++)
        {
            int ASCII = (int) original_words[i][j];
            int index = ASCII-97;   //97 is the ASCII code of 'a'. index for the secret code of 'a' is 0 in 'code' string.

            for (int k=0; k<code[index].size(); k++)
            {
                str.push_back(code[index][k]);

            }
        }
        encrypted_words.push_back(str);
    }
    for (int i=0; i< original_words.size(); i++)
    {
        std::cout<<std::setw(20)<<std::left<<original_words[i]<<std::setw(10)<<std::left<<encrypted_words[i]<<"\n";
    }

    std::vector<int> counting_array;
    int count = 0;
    for (int i=0; i<original_words.size(); i++)
    {
        counting_array.push_back(0);
    }

    for (int i=0; i<original_words.size(); i++)
    {
        if(counting_array[i]==0)
        {
            count++;

            for (int j=i; j<original_words.size(); j++)
            {
                if(counting_array[i]==counting_array[j])
                {
                    counting_array[j]=count;
                }
            }
        }
    }
    std::cout<<"Number of unique secret codes are "<<count<<std::endl;
}
