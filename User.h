#pragma once

#include <iostream>
#include <string>
using namespace std;

class User
{
	private:
	    int role;//一是管理员，二是读者
    public:
	    string account;
	    string password;
	    bool hasBorrowed; 
        User(int r) : role(r),hasBorrowed(false){}
        int getRole(); 
};

