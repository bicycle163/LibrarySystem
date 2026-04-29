#include "LibrarySystem.h"

	LibrarySystem::LibrarySystem(){
	    loadBook();
		loadUser(); 
	}
	
	//主页面 
	void LibrarySystem::run(){
	    string choice;
		do{
		system("cls");
		cout<<"——————图书馆管理系统——————\n";
		cout<<"1.注册读者身份\n";
		cout<<"2.登录\n";
		cout<<"3.显示开发者信息\n";
		cout<<"4.更改主题颜色\n";
		cout<<"0.退出程序\n"; 
		cout<<"请选择(输入对应数字)\n";
		cin>>choice;
			if(choice=="1"){
			 		    registerreader(); 
						}
			else if(choice=="2"){
				login();
			}	 
			else if(choice=="3"){ 
			    Thankyou();
			}
			else if(choice=="4"){ 
			    Setting();
			}
			else if(choice=="0"){
			 	saveBook();
			 	saveUser();
			 	cout<<"程序已退出\n";
			 	system("pause");
			}
			else{
			 	cout<<"输入无效，请重新输入\n";
			 	system("pause");
			}
		}while(choice!="0");
	}	
	
	//开发人信息	
	void LibrarySystem::Thankyou()
    {
    system("cls");
	cout<<"**************************************************"<<endl;
	cout<<"*****         《H大图书馆管理系统》          *****"<<endl;
	cout<<"*****          湖南大学计算机学院            *****"<<endl;
	cout<<"*****   通信2501班  王梓卿 刘鑫杰 卢征 编写  *****"<<endl;
	cout<<"*****         王梓卿   202508030128          *****"<<endl;
	cout<<"*****         刘鑫杰   202508030112          *****"<<endl;
	cout<<"*****          卢征    202508030109          *****"<<endl;
	cout<<"*****           感谢您的使用与支持           *****"<<endl;
	cout<<"**************************************************"<<endl;
	system("pause");
	system("cls");
    }
	
	//个性化界面	
	void LibrarySystem::Setting()
    {
        string choice;
        setting:
        system("cls");
        cout<<"*************************"<<endl;
        cout<<"主题颜色设置"<<endl;
        cout<<"*************************"<<endl;
        cout<<"   背 景    字 体   "<<endl;
        cout<<"1：深沉黑 + 极简白（默认）"<<endl;
        cout<<"2：天空蓝 + 云朵白"<<endl;
        cout<<"3：中国红 + 中华黄"<<endl;
        cout<<"4：足茵绿 + 球场白"<<endl;
        cout<<"5：茶花粉 + 清纯白"<<endl;
        cout<<"0：返回上级菜单"<<endl;
        cout<<"*************************"<<endl;
        cout<<"请输入对应编号进行操作："<<endl;
        cin>>choice;
			if(choice=="1"){
                system("color 07");
                goto setting;
            }
            else if(choice=="2"){
                system("color 3F");
                goto setting;
            }
            else if(choice=="3"){
                system("color 4E");
                goto setting;
            }
            else if(choice=="4"){
                system("color 2F");
                goto setting;
            }
            else if(choice=="5"){
                system("color CF");
                goto setting;
            }
            else if(choice=="0"){
                system("cls");
                return;
            }
            else{
            	cout<<"输入无效，请重新输入" <<endl; 
			}
	}
	
	//注册系统	
	void LibrarySystem::registerreader(){
		User newreader(2);
		
		// 检查账户唯一性
		while (true) {
		    system("cls");
		    cout<<"——————注册读者身份——————\n";
            cout<<"请输入账户:\n";
            cin>>newreader.account;
        
            bool exists = false;
            for (size_t i = 0; i < users.size(); i++) {
                if (users[i].account==newreader.account) {
                    exists = true;
                    cout << "该账户已存在，请重新输入！" << endl;
                    system("pause"); 
                    break;
                }
		    }
            if (!exists) break;
		}
		cout<<"请输入密码:";
		cin.ignore();
        getline(cin,newreader.password);	
		cout<<"您的新账户创建成功\n";
        newreader.hasBorrowed = false;

		users.push_back(newreader);
		currentUserAccount = newreader.account;
		saveUser();
		system("pause");
	}
	
	//加载数据			
	void LibrarySystem::login(){
    string account;
    string password;
    int role = 0;   //  初始化 
    while (true) {
    	system("cls");
	    cout << "======================= 用户登录 ====================\n";
        cout << "请输入账户：";
        cin >> account;
        cout << "请输入密码：";
        cin >> password;
        bool found = false;
        for (size_t i = 0; i < users.size(); i++) {
            if (users[i].account == account &&users[i].password == password) {
                found = true;
                role = users[i].getRole();
                currentUserAccount = users[i].account; // 保存当前登录账号
                cout << "登录成功！" << endl;
                break;
            }
        }
        if (found) break;
        else{
            cout << "账号或密码错误，请重新输入！\n";//可以加一个登录失败次数限制
			system("pause"); 
        }
    }
        if (role == 1) {
            adminMenu();
        } 
		else if (role == 2) {
            readerMenu();
        }
	}
    
	//管理员界面 
	void LibrarySystem::adminMenu(){
		string choice;
		do{
			system("cls");
			cout<<"——————管理员系统——————\n";
			cout<<"1.显示所有图书\n";
			cout<<"2.增加书籍\n";
			cout<<"3.删除书籍\n";
			cout<<"4.修改书籍\n";
			cout<<"5.搜索书籍\n"; 
			cout<<"6.借阅书籍\n"; 
			cout<<"7.归还书籍\n"; 
			cout<<"8.重置读者密码为123456\n";
			cout<<"9.图书排行榜\n"; 
			cout<<"10.查询借阅书籍\n";
			cout<<"0.退回上一步\n"; 
			cout<<"请选择(输入对应数字)\n";
			cin>>choice;
			 	if(choice=="1"){
			 		showAllBooks();
				}
			 	else if(choice=="2"){
			 		addBook(); 
			 	}
			 	else if(choice=="3"){
			 		deleteBook();
			 	}
			 	else if(choice=="4"){
			 		modifyBooks();
				}	
				else if(choice=="5"){
					searchBooks();
				}
				else if(choice=="6"){
			 		borrowBook();	 		     
			 	}
			 	else if(choice=="7"){
			 		returnBook(); 		     
			 	}
			 	else if(choice=="8"){
                    passwordreset();		 		     
			 	}
			 	else if(choice=="9"){
                    rank_list();		 		     
			 	}
			 	else if(choice=="10"){
                    check_borrowBook();		 		     
			 	}
			 	else if(choice=="0"){
			 	}
			 	else{
			 		cout<<"输入无效，请重新输入\n";
			 		system("pause");
				}
		}while(choice!="0");
	}
	
	//读者页面	
	void LibrarySystem::readerMenu(){
		string choice;
		do{
			system("cls");
			cout<<endl;
			cout<<"——————用户系统——————\n";
			cout<<"1.显示所有图书\n";
			cout<<"2.搜索书籍\n"; 
			cout<<"3.借阅书籍\n"; 
			cout<<"4.归还书籍\n"; 
			cout<<"5.图书排行榜\n"; 
			cout<<"6.查询借阅书籍\n"; 
			cout<<"0.退回上一步\n"; 
			cout<<"请选择(输入对应数字)\n";
			cin>>choice;
			 	if(choice=="1"){
			 		showAllBooks();
			 	}
			 	else if(choice=="2"){
			 		searchBooks();		 		     
			 	}
			 	else if(choice=="3"){
			 		borrowBook();	 		     
			 	}
			 	else if(choice=="4"){
			 		returnBook(); 		     
			 	}
			 	else if(choice=="5"){
			 		rank_list();	     
			 	}
			 	else if(choice=="6"){
			 		check_borrowBook();     
			 	}		
			 	else if(choice=="0"){
			 	}
			 	else{
			 		cout<<"输入无效，请重新输入\n";
			 		system("pause");
				}
		}while(choice!="0");
	}		
	
	//加载数据	
	void LibrarySystem::loadBook(){
		ifstream read;
		read.open("Book.txt",ios::in);
		if (!read.is_open()) {
            cout << "未找到 Book.txt，将创建新书库。\n";
            return;
        }
		
		string line;
        while (getline(read, line)) {//read输入流 
            if (line.empty()) continue;

            istringstream iss(line);//把字符串变成输入流，一个可以像cin一样的读对象 

            Book b;
            string isbnStr, priceStr,ifborrowStr,borrowCountStr;

            getline(iss, b.topic, '|');//iss是输入流，接收对象是book的每个成员，直到读到‘|’ 
            getline(iss, isbnStr, '|');
            getline(iss, b.author, '|');
            getline(iss, b.publisher, '|');
            getline(iss, priceStr,'|');
            getline(iss,ifborrowStr,'|');
            getline(iss,borrowCountStr,'|');
            getline(iss,b.publishDate,'|');
            getline(iss,b.borrower);

           istringstream(isbnStr) >> b.ISBN;
            istringstream(priceStr) >> b.price;//处理字符串变数字方法 
            b.ifborrow = (ifborrowStr == "1");
            istringstream(borrowCountStr) >> b.borrowCount;

            books.push_back(b);//push_back函数用于在vector动态数组books加新book类的book。 
        }

        read.close();
    }
    
    //保存书籍 
	void LibrarySystem::saveBook(){
		ofstream write;
		write.open("Book.txt",ios::out);//先清空文件，再写文件 
		if (!write.is_open()) return;
        for (size_t i = 0; i < books.size(); i++) {
            write << books[i].topic << "|"
            << books[i].ISBN << "|"
            << books[i].author << "|"
            << books[i].publisher << "|"
            << books[i].price <<"|"
            << (books[i].ifborrow ? 1 : 0) << "|"
            << books[i].borrowCount << "|"
            << books[i].publishDate << "|"
            << books[i].borrower << endl;
        }
		write.close();
	}
	
	//展示书籍	
	void LibrarySystem::showAllBooks(){
		system("cls");
        cout << "\n====================================图书列表 (" << books.size() << "本)==================================\n";
        cout << "-------------------------------------------------------------------------------------\n";
        cout<< left
		<<setw(6) << "序号"
		<<setw(20) << "书名"
		<<setw(15) << "ISBN"   
        <<setw(18) << "作者"
		<<setw(18) << "出版社" 
		<<setw(8)  << "价格"
		<<setw(10)<<"是否借出"
		<<setw(10)<<"借出次数"
		<<setw(10)<<"出版日期"<< endl;
		cout << "-------------------------------------------------------------------------------------\n";     
        if (books.empty()) {
            cout << "暂无图书数据！"<< endl;
            return;
        }

        for (size_t i = 0; i < books.size(); i++) {
            cout <<left
		    <<setw(6)  << i + 1 
            <<setw(20) << books[i].topic
            <<setw(15) << books[i].ISBN
            <<setw(18) << books[i].author
            <<setw(18) << books[i].publisher
            <<setw(10)  << books[i].price
            <<setw(10)  <<(books[i].ifborrow ? "是" :"否")
            <<setw(8)  << books[i].borrowCount
            <<setw(10) << books[i].publishDate<<endl;
        }
        cout << "-------------------------------------------------------------------------------------\n";
        system("pause");
	}
    
    //添加书籍 
	void LibrarySystem::addBook(){
		system("cls");
		Book newBook;
		cout<<"请输入书名(小于20个字符)：";
		cin.ignore(); 
		getline(cin,newBook.topic);
		
        while (true) {
            cout <<"请输入ISBN(十位数字): ";
            cin>>newBook.ISBN;
            bool exists = false;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].ISBN == newBook.ISBN) {
                    exists = true;
                    cout << "该ISBN已存在，请重新输入！" << endl;
                    break;
                }
            }
            if (!exists) break;
        }
		newBook.ifborrow=false;
		newBook.borrowCount=0;
		newBook.borrower="无";
	    cin.ignore();
		cout<<"请输入作者:";	
		getline(cin,newBook.author);
		cout << "请输入出版社: ";
        getline(cin, newBook.publisher);
        cout << "请输入价格: ";
        cin >> newBook.price;
        cin.ignore(); 
        cout << "请输入出版日期: ";
        getline(cin, newBook.publishDate);
        books.push_back(newBook);
		cout<<"图书添加成功"<<endl;	
		system("pause");	
		saveBook(); 
	}
	
	//删除书籍	
	void LibrarySystem::deleteBook(){
		   system("cls");
        if (books.empty()) {
           cout << "当前书库没有图书，无法删除！"<< endl;
           return;
        }

        showAllBooks(); // 先显示，方便用户选择

        cout << "请输入要删除的图书序号：";
        string input;
          cin >> input;
          
    for (size_t i = 0; i < input.size(); i++) {
          if (!isdigit(input[i])) {
            cout << "输入无效，请输入数字序号！\n";
            system("pause");
            return;
          }
      }
      
         int index;
          istringstream iss(input);
           iss >> index;
           
        // 合法性检查
        if (index < 1 || index > books.size()) {
          cout << "序号无效，删除失败！"<< endl;
          system("pause");
           return;
        }
    
        books.erase(books.begin() + index - 1);

        cout << "图书删除成功！"<< endl;
        system("pause");
        }

    //用户加载 
    void LibrarySystem::loadUser(){
        ifstream read;
        read.open("User.txt", ios::in);
        if (!read.is_open()) return;
        string line;
        while (getline(read, line)) {
            if (line.empty()) continue;
            istringstream iss(line);
            string account, password, roleStr,hasBorrowedStr;
            getline(iss, account, '|');
            getline(iss, password, '|');
            getline(iss, roleStr, '|');
            getline(iss, hasBorrowedStr);
            int role;
            istringstream(roleStr) >> role; 
            User u(role); // 1=管理员，2=读者
            u.account = account;
            u.password = password;
            u.hasBorrowed = (hasBorrowedStr == "1"); // 读取借书状态
            users.push_back(u);
        }
        read.close();
	} 
	
	//用户保存 
	void LibrarySystem::saveUser(){
	    ofstream write;
        write.open("User.txt", ios::out);  // 清空文件再写
        if (!write.is_open()) return; 
        for (size_t i = 0; i < users.size(); i++) {
            write << users[i].account << "|"
            << users[i].password << "|"
            << users[i].getRole() << "|"
            << (users[i].hasBorrowed ? 1 : 0) << endl;
        }
        write.close();
	}
	 
	//修改图书  
    void LibrarySystem::modifyBooks() {
        if (books.empty()) {
            cout << "当前书库没有图书，无法修改！\n";
            system("pause");
            return;
        }
        int modify = -1;
        while (true) {
            system("cls");
            cout << "=================== 修改图书 =================\n";
            cout << "请输入要修改的图书 ISBN：";
            string input;
            cin >> input;
            bool valid = true;
            for (size_t i = 0; i < input.size(); i++) {
                if (!isdigit(input[i])) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                cout << "ISBN 只能包含数字，请重新输入！\n";
                system("pause");
                continue;
            }
            long long ISBN;//转化步骤 
            istringstream iss(input);
            iss >> ISBN;
            bool exists = false;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].ISBN == ISBN) {
                modify = i;
                exists = true;
                break;
                }
            }
            if (exists) break;
            cout << "未发现该 ISBN 对应的图书，请重新输入！\n";
            system("pause");
        }
        string choice;
        cin.ignore(1024, '\n');
        do{
    	    system("cls");
            cout << "1. 修改题名\n";
            cout << "2. 修改作者\n";
            cout << "3. 修改出版社\n";
            cout << "4. 修改价格\n";
            cout << "5. 修改出版日期\n";
            cout << "请选择修改项：";
         	getline(cin,choice);
            if(choice=="1"){
                cout << "请输入新题名：";
                getline(cin, books[modify].topic);
            }
            else if(choice=="2"){
                cout << "请输入新作者：";
                getline(cin, books[modify].author);
            }
            else if(choice=="3"){
                cout << "请输入新出版社：";
                getline(cin, books[modify].publisher);
            }
            else if(choice=="4"){
                cout << "请输入新价格：";
                string priceStr;
                cin >> priceStr;
                cin.ignore(1024, '\n');
                istringstream ps(priceStr);
                ps >> books[modify].price;
            }
            else if(choice=="5"){
                cout << "请输入新出版日期：";
                getline(cin, books[modify].publishDate);
            }
	        else{
        	    cout<<"输入无效，请重新输入\n"; 
        	    system("pause");
	      	}
     	}while(choice<"1"||choice>"5");
        saveBook();
        cout << "图书修改成功！\n";
        system("pause");
    }		
	
	//重置密码系统	
	void LibrarySystem::passwordreset(){
		system("cls");
        string acc;
        cout << "请输入要重置密码的读者账号：";
        cin >> acc;
        bool found = false;
        for (size_t i = 0; i < users.size(); i++) {
            if (users[i].account == acc && users[i].getRole() == 2) {
                users[i].password = "123456";  
                found = true;
                break;
            }
        }
        if (found) {
            saveUser();   
            cout << "密码已重置为 123456\n";
        } 
		else {
            cout << "未找到该读者账号！\n";
        }
        system("pause");	
	}
		
	//比较函数 
	bool LibrarySystem::compareBookByTopic(const Book& a, const Book& b)
        {
          return a.topic < b.topic;
        }

    //搜索书籍 
	void LibrarySystem::searchBooks(){
		system("cls");
        string choice;
        cout << "=========== 图书搜索 ===========" << endl;
        cout << "1. 按书名精确查找" << endl;
        cout << "2. 按ISBN精确查找" << endl;
        cout << "3. 按作者精确查找" << endl;
        cout << "请选择搜索方式：";
        cin>>choice;
        vector<Book> results;
        if(choice=="1") { 
            string key;
            cout << "请输入完整书名：";
            cin>>key;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].topic == key) {
                    results.push_back(books[i]);
                    break;  
                }
            }
        }
        else if(choice=="2"){  
            long long key;
            cout << "请输入 ISBN：";
            cin >> key;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].ISBN == key) {
                    results.push_back(books[i]);
                    break;   
                }
            }
        }
        else if(choice=="3") { 
            string key;
            cout << "请输入作者名：";
            cin>> key;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].author == key) {
                    results.push_back(books[i]);
                }
            } 
            sort(results.begin(), results.end(),LibrarySystem::compareBookByTopic);
        }
        else{
            cout << "无效选择！" << endl;
            system("pause");
            return;
        }
        // ===== 显示结果 =====
        system("cls");
        cout << "========== 搜索结果（" << results.size() << " 本） ==========" << endl;
        if (results.empty()) {
            cout << "未找到符合条件的图书！" << endl;
            system("pause");
            return;
        }
        cout << left
        <<setw(6) << "序号"
		<<setw(20) << "书名"
		<<setw(15) << "ISBN"   
        <<setw(18) << "作者"
		<<setw(18) << "出版社" 
		<<setw(8)  << "价格"
		<<setw(10)<<"是否借出"
		<<setw(10)<<"借出次数"
		<<setw(10)<<"出版日期"<< endl;
        cout << "---------------------------------------------------------------------" << endl;
        for (size_t i = 0; i < results.size(); i++) {
            cout << left
            <<setw(6)  << i + 1
            <<setw(20) << results[i].topic
            <<setw(15) << results[i].ISBN
            <<setw(18) << results[i].author
            <<setw(18) << results[i].publisher
            <<setw(10)  << results[i].price
            <<setw(10)  <<(results[i].ifborrow ? "是" :"否")
            <<setw(8)  << results[i].borrowCount
            <<setw(10) <<results[i].publishDate<< endl;
        }
        system("pause");
	}
	
	//借书系统	
	void LibrarySystem::borrowBook() {
        system("cls");
        cout << "================= 借书系统 =================" << endl;
        // 找到当前登录用户指针
        User* currentUser = NULL;
        for (size_t i = 0; i < users.size(); i++) {
            if (users[i].account == currentUserAccount) {
                currentUser = &users[i]; // 取地址，指向用户对象
                break;
            }
        }
        if (currentUser == NULL) {
            cout << "用户状态异常，请重新登录！\n";
            system("pause");
            return;
        } 
        if (currentUser->hasBorrowed) {
            cout << "您已借过一本书，无法再借！\n";
            system("pause");
            return;
        }
        randomRecommendBooks();
        showAllBooks();
        cout << "请输入要借的书的序号：";
        int index;
        cin >> index;
        if (index < 1 || index > books.size()) {
            cout << "序号无效！\n";
            system("pause");
            return;
        }
        Book* b = &books[index - 1]; // 取地址，方便用指针修改
        if (b->ifborrow) {
            cout << "该书已被借出，无法借阅！\n";
        } 
		else {
            b->ifborrow = true;
            b->borrowCount += 1;
            b->borrower = currentUser->account;
            currentUser->hasBorrowed = true;
            cout << "借书成功！\n";
        }
        saveBook();
        saveUser();
        system("pause");
    }

    //还书系统 
    void LibrarySystem::returnBook() {
        system("cls");
        cout << "================= 还书系统 =================" << endl;
        // 找到当前登录用户指针
        User* currentUser =NULL;
        for (size_t i = 0; i < users.size(); i++) {
            if (users[i].account == currentUserAccount) {
                currentUser = &users[i];
                break;
            }
        }
        if (currentUser == NULL) {
            cout << "用户状态异常，请重新登录！\n";
            system("pause");
            return;
        }
        if (!currentUser->hasBorrowed) {
            cout << "您当前没有借书，无需归还！\n";
            system("pause");
            return;
        }
        // 找到用户借的书
        Book* borrowedBook = NULL;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].borrower == currentUser->account) {
                borrowedBook = &books[i]; // 指针指向对应书
                break;
            }
        }
        if (!borrowedBook) { // 理论上不会发生，保险起见
            cout << "未找到您借的书，系统状态异常！\n";
            system("pause");
            return;
        }
        borrowedBook->ifborrow = false;
        borrowedBook->borrower = "无"; // 重置借书人
        currentUser->hasBorrowed = false;
        cout << "还书成功！\n";
        saveBook();
        saveUser();
        system("pause");
    }
    
    //时间排序辅助函数 
    bool LibrarySystem::compareBookBypublishDate(const Book& a, const Book& b){
    	long time_a,time_b;
    	size_t firstpoint_a=a.publishDate.find(".");
    	size_t secondpoint_a=a.publishDate.find(".",firstpoint_a+1);
    	size_t firstpoint_b=b.publishDate.find(".");
    	size_t secondpoint_b=b.publishDate.find(".",firstpoint_b+1);//时间字串查找 
    	stringstream sss_a(a.publishDate.substr(0,firstpoint_a));
    	sss_a>>time_a;
    	time_a*=10000;
    	int temp_montha,temp_daya;
    	stringstream ss_a(a.publishDate.substr(firstpoint_a+1,secondpoint_a - firstpoint_a - 1));
    	ss_a>>temp_montha;
    	time_a+=(temp_montha*100);
    	stringstream s_a(a.publishDate.substr(secondpoint_a+1));
    	s_a>>temp_daya;
    	time_a+=temp_daya;
    	stringstream sss_b(b.publishDate.substr(0,firstpoint_b));
    	sss_b>>time_b;
    	time_b*=10000;
    	int temp_monthb,temp_dayb;
    	stringstream ss_b(b.publishDate.substr(firstpoint_b+1,secondpoint_b - firstpoint_b - 1));
    	ss_b>>temp_monthb;
    	time_b+=(temp_monthb*100);
    	stringstream s_b(b.publishDate.substr(secondpoint_b+1));
    	s_b>>temp_dayb;
    	time_b+=temp_dayb;
    	return(time_a>time_b);
	}
	
	//排行榜辅助函数 
	bool LibrarySystem::compareBookByborrowCount(const Book& a, const Book& b){
		return a.borrowCount>b.borrowCount;
	}
	
	//排行榜函数 
    void LibrarySystem::rank_list(){
		string choice;
        do {
          	system("cls");
		    cout << "________________________排行榜_______________________" << endl;
            cout << "1. 出版时间排行榜（从新到旧）" << endl;
            cout << "2. 借阅排行榜" << endl;
            cout << "0. 返回" << endl;
            cout << "请选择: ";
            cin>>choice;
            if (choice == "0") {
        	    system("cls");
                cout << "返回主菜单..."<< endl;
                system("pause"); 
            }
            else if (choice == "1" || choice == "2") {
        	    system("cls");
                vector<Book> temp_listbooks = books;
                if (choice == "1") {
                    sort(temp_listbooks.begin(), temp_listbooks.end(), compareBookBypublishDate);    
                    cout << "\n====================================出版时间排行榜 (" << temp_listbooks.size() << "本)==================================\n";
                    cout << "-------------------------------------------------------------------------------------\n";
                    cout<< left
		            <<setw(6) << "序号"
	            	<<setw(20) << "书名"
	            	<<setw(15) << "ISBN"   
                    <<setw(18) << "作者"
	            	<<setw(18) << "出版社" 
	               	<<setw(8)  << "价格"
	               	<<setw(10)<<"是否借出"
		            <<setw(10)<<"借出次数"
	               	<<setw(10)<<"出版日期"<< endl;   
                    cout << "-------------------------------------------------------------------------------------\n";     
                    if (temp_listbooks.empty()) {
                        cout << "暂无图书数据！"<< endl;
                        return;
                    }
                    for (size_t i = 0; i < 10; i++) {
                    cout <<left
		            <<setw(6)  << i + 1
                    <<setw(20) <<temp_listbooks [i].topic
                    <<setw(15) <<temp_listbooks [i].ISBN
                    <<setw(18) <<temp_listbooks [i].author
                    <<setw(18) <<temp_listbooks [i].publisher
                    <<setw(10)  <<temp_listbooks [i].price
                    <<setw(10)  <<(temp_listbooks [i].ifborrow ? "是" :"否")
                    <<setw(8)  <<temp_listbooks [i].borrowCount
                    <<setw(10) <<temp_listbooks [i].publishDate
                    <<endl;
                    }
                    cout << "-------------------------------------------------------------------------------------\n";
                    system("pause");
	            }
	            else if (choice == "2") {
	        	    system("cls");
                    sort(temp_listbooks.begin(), temp_listbooks.end(),compareBookByborrowCount);
                    cout << "\n====================================出版时间排行榜 (" << temp_listbooks.size() << "本)==================================\n";
                    cout << "-------------------------------------------------------------------------------------\n";
                    cout<< left
		            <<setw(6) << "序号"
		            <<setw(20) << "书名"
		            <<setw(15) << "ISBN"   
                    <<setw(18) << "作者"
		            <<setw(18) << "出版社" 
		            <<setw(8)  << "价格"
		            <<setw(10)<<"是否借出"
		            <<setw(10)<<"借出次数"
		            <<setw(10)<<"出版日期"<< endl;   
                    cout << "-------------------------------------------------------------------------------------\n";     
                    if (temp_listbooks.empty()) {
                        cout << "暂无图书数据！"<< endl;
                        return;
                    }
                    for (size_t i = 0; i < 10; i++) {
                        cout <<left
		                <<setw(6)  << i + 1
                        <<setw(20) << temp_listbooks[i].topic
                        <<setw(15) << temp_listbooks[i].ISBN
                        <<setw(18) << temp_listbooks[i].author
                        <<setw(18) << temp_listbooks[i].publisher
                        <<setw(10)  << temp_listbooks[i].price
                        <<setw(10)  <<(temp_listbooks[i].ifborrow ? "是" :"否")
                        <<setw(8)  << temp_listbooks[i].borrowCount
                        <<setw(10) << temp_listbooks[i].publishDate<<endl;
                    }
                    cout << "-------------------------------------------------------------------------------------\n";
                    system("pause");
	            }
            }
            else{
                cout<<"输入无效，请重新输入！\n";
		          system("pause");
		    }
        }while(choice!="0");
	}	
    
    //查询借阅 
	void LibrarySystem::check_borrowBook(){
        system("cls");
        User* currentUser = NULL;
        for (size_t i = 0; i < users.size(); i++) {
            if (users[i].account == currentUserAccount) {
                currentUser = &users[i];
                break;
            }
        }
        if (currentUser == NULL) {
            cout << "用户状态异常，请重新登录！\n";
            system("pause");
            return;
        }
        if (!currentUser->hasBorrowed) {
            cout << "您当前没有借书\n";
            system("pause");
            return;
        }
        Book* borrowedBook = NULL;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].borrower == currentUser->account) {
                borrowedBook = &books[i]; 
                break;
            }
        }
        if (!borrowedBook) { // 理论上不会发生，保险起见
            cout << "未找到您借的书，系统状态异常！\n";
            currentUser->hasBorrowed = false;
            saveUser();
            system("pause");
            return;
        }
        cout << "========== 您借阅的书籍信息 ==========\n";
        cout << "--------------------------------------\n";
        cout << left << setw(15) << "书名：" << borrowedBook->topic << "\n";
        cout << left << setw(15) << "ISBN：" << borrowedBook->ISBN << "\n";
        cout << left << setw(15) << "作者：" << borrowedBook->author << "\n";
        cout << left << setw(15) << "出版社：" << borrowedBook->publisher << "\n";
        cout << left << setw(15) << "价格：" << borrowedBook->price << "元\n";
        cout << left << setw(15) << "出版日期：" << borrowedBook->publishDate << "\n";
        cout << left << setw(15) << "借阅次数：" << borrowedBook->borrowCount << "次\n";
        cout << "--------------------------------------\n";
        system("pause");
    }

    //随机推荐 
    void LibrarySystem::randomRecommendBooks() {
        cout << "=========== 推荐图书 ===========\n";
        int total = books.size();
        int num = total >= 4 ? 4 : total;
        cout << "-------------------------------------------------------------------------------------\n";
        cout<< left
		<<setw(6) << "序号"
		<<setw(20) << "书名"
        <<setw(18) << "作者"
		<<setw(16) << "出版社" 
		<<setw(8)  << "价格"
		<<setw(12)<<"借出次数"
		<<setw(10)<<"出版日期"<< endl;
        cout << "-------------------------------------------------------------------------------------\n";
        int hasRecommend[4] = {-1,-1,-1,-1}; // 存储已推荐的图书下标
        int recommendCount = 0; // 已推荐的数量
        while(recommendCount < num){ // 循环选够数量
            int location= rand() % total; 
            bool repeat = false;
            for(int j=0;j<recommendCount;j++){
                if(hasRecommend[j]==location) repeat=true;
            }
            if(!repeat){
            cout << left
            << setw(6)  << recommendCount + 1
            << setw(20) << books[location].topic
            << setw(18) << books[location].author 
            << setw(18) << books[location].publisher 
            << setw(10) << books[location].price 
            << setw(8) << books[location].borrowCount 
            << setw(10) << books[location].publishDate << endl;
            hasRecommend[recommendCount] = location; // 记录已用下标
            recommendCount++;
            }
        }
        cout<<"点击任意键显示所有图书"<<endl; 
        system("pause");   
    }
