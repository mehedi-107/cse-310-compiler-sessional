#pragma once
#include <bits/stdc++.h>
using namespace std;

unsigned int SDBMHash(string str, unsigned int num_buckets)
{
    unsigned int hash = 0;
    unsigned int len = str.length();
    for (unsigned int i = 0; i < len; i++)
    {
        hash = ((str[i]) + (hash << 6) + (hash << 16) - hash) %
               num_buckets;
    }
    // cout<<"SDBM Hash: "<<hash<<endl;
    return hash;
}

// https://stackoverflow.com/questions/19892609/djb2-by-dan-bernstein-for-c

unsigned int djb2(std::string s, unsigned int num_buckets)
{
    unsigned int hash = 5381;
    char c;
    for (int i = 0; i < s.size(); i++)
    {
        c = s[i++];
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        hash = hash % num_buckets;
    }
    // cout<<"DJB2 Hash: "<<hash<<endl;
    return hash;
}


// source: https://gist.github.com/hwei/1950649d523afd03285c#file-const_fvn_hash-cpp-L6


static unsigned int fnvHash(string str, unsigned int num_buckets)
{
    static const unsigned int FNV_PRIME = 16777619u;
    static const unsigned int OFFSET_BASIS = 2166136261u;
    unsigned int hash = OFFSET_BASIS;
    for (size_t i = 0; i < str.length();i++)
    {
        hash ^= str[i];
        hash *= FNV_PRIME;
        hash = hash % num_buckets;
    }
    // cout<<"FNV Hash: "<<hash<<endl;
    return hash;
}
