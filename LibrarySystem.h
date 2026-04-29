#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib> 
#include "Book.h"
#include "User.h"
using namespace std;
	
	class LibrarySystem{
		private:
		string currentUserAccount;
        vector<Book> books;
        vector<User> users;
        public:
		LibrarySystem();
		void run();	
		void readerMenu();
		void adminMenu();
		void login();
		void registerreader();
        void modifyBooks();
        void passwordreset();
	    static bool compareBookByTopic(const Book& a, const Book& b);
	    static bool compareBookBypublishDate(const Book& a, const Book& b);
	    static bool compareBookByborrowCount(const Book& a, const Book& b);
		void searchBooks();
		void loadBook();
		void saveBook();
		void loadUser();
    	void saveUser();
        void addBook();
        void deleteBook();
		void showAllBooks();
		void borrowBook();
		void returnBook();
		void check_borrowBook(); 
		void rank_list();
		void Setting();
		void Thankyou();
		void randomRecommendBooks();
	};
	
