#define STRING_LENGTH 14

char random_string[STRING_LENGTH];

uc_06_registration_of_new_users()
{
	lr_start_transaction("uc_06_registration_of_new_users");
	
	lr_start_transaction("open_start_page");
	
//	web_add_header("Sec-Fetch-Dest", 
//		"document");
//
//	web_add_header("Sec-Fetch-Mode", 
//		"navigate");
//
//	web_add_header("Sec-Fetch-Site", 
//		"none");
//
//	web_add_header("Sec-Fetch-User", 
//		"?1");
//
//	web_add_auto_header("Upgrade-Insecure-Requests", 
//		"1");
//
//	web_add_auto_header("sec-ch-ua", 
//		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");
//
//	web_add_auto_header("sec-ch-ua-mobile", 
//		"?0");
//
//	web_add_auto_header("sec-ch-ua-platform", 
//		"\"Windows\"");
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Web Tours",
		LAST);

	web_url("WebTours", 
		"URL=http://{HOST}:{PORT}/WebTours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_url("header.html", 
		"URL=http://{HOST}:{PORT}/WebTours/header.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/WebTours/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"frame");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"navigate");
//
//	web_add_auto_header("Sec-Fetch-Site", 
//		"same-origin");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Web Tours",
		LAST);
	
	web_url("welcome.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/WebTours/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=USERSESSION",
		"LB=name=\"userSession\" value=\"",
		"RB=\"",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Web Tours Navigation Bar",
		LAST);

	web_url("nav.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

//	web_revert_auto_header("Sec-Fetch-Dest");
//
//	web_revert_auto_header("Sec-Fetch-Mode");
//
//	web_revert_auto_header("Sec-Fetch-Site");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Web Tours",
		LAST);
	
	web_url("home.html", 
		"URL=http://{HOST}:{PORT}/WebTours/home.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("open_start_page", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("customer_profile");
	
//	web_add_header("Sec-Fetch-Dest", 
//		"frame");
//
//	web_add_header("Sec-Fetch-Mode", 
//		"navigate");
//
//	web_add_header("Sec-Fetch-Site", 
//		"same-origin");
//
//	web_add_header("Sec-Fetch-User", 
//		"?1");
//
//	web_add_header("Upgrade-Insecure-Requests", 
//		"1");
//
//	web_add_header("sec-ch-ua", 
//		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");
//
//	web_add_header("sec-ch-ua-mobile", 
//		"?0");
//
//	web_add_header("sec-ch-ua-platform", 
//		"\"Windows\"");
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User Information",
		LAST);

	web_url("login.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/WebTours/home.html", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("customer_profile", LR_AUTO);
	
	lr_think_time(15);
	
	lr_start_transaction("confirmation");
    
    generate_random_string(random_string);
    
    lr_save_string(random_string, "randomPARAMETERS");
	
//	web_add_header("Origin", 
//		"http://{HOST}:{PORT}");
//
//	web_add_header("Sec-Fetch-Dest", 
//		"frame");
//
//	web_add_header("Sec-Fetch-Mode", 
//		"navigate");
//
//	web_add_header("Sec-Fetch-Site", 
//		"same-origin");
//
//	web_add_header("Sec-Fetch-User", 
//		"?1");
//
//	web_add_header("Upgrade-Insecure-Requests", 
//		"1");
//
//	web_add_header("sec-ch-ua", 
//		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");
//
//	web_add_header("sec-ch-ua-mobile", 
//		"?0");
//
//	web_add_header("sec-ch-ua-platform", 
//		"\"Windows\"");
	
	web_submit_data("login.pl", 
		"Action=http://{HOST}:{PORT}/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={randomPARAMETERS}", ENDITEM, 
		"Name=password", "Value={randomPARAMETERS}", ENDITEM, 
		"Name=passwordConfirm", "Value={randomPARAMETERS}", ENDITEM, 
		"Name=firstName", "Value={randomPARAMETERS}", ENDITEM, 
		"Name=lastName", "Value={randomPARAMETERS}", ENDITEM, 
		"Name=address1", "Value={randomPARAMETERS}", ENDITEM, 
		"Name=address2", "Value={randomPARAMETERS}", ENDITEM, 
		"Name=register.x", "Value=61", ENDITEM, 
		"Name=register.y", "Value=9", ENDITEM, 
		LAST);
	
	lr_end_transaction("confirmation", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("greetings");
	
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"frame");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"navigate");
//
//	web_add_auto_header("Sec-Fetch-Site", 
//		"same-origin");
//
//	web_add_header("Sec-Fetch-User", 
//		"?1");
//
//	web_add_auto_header("Upgrade-Insecure-Requests", 
//		"1");
//
//	web_add_auto_header("sec-ch-ua", 
//		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");
//
//	web_add_auto_header("sec-ch-ua-mobile", 
//		"?0");
//
//	web_add_auto_header("sec-ch-ua-platform", 
//		"\"Windows\"");
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Web Tours",
		LAST);

	web_url("welcome.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/welcome.pl?page=menus", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/login.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Web Tours Navigation Bar",
		LAST);

	web_url("nav.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Welcome, <b>{randomPARAMETERS}</b>, to the Web Tours reservation pages.",
		LAST);

	web_url("login.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("greetings", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("logout");
	
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"frame");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"navigate");
//
//	web_add_auto_header("Sec-Fetch-Site", 
//		"same-origin");
//
//	web_add_header("Sec-Fetch-User", 
//		"?1");
//
//	web_add_auto_header("Upgrade-Insecure-Requests", 
//		"1");
//
//	web_add_auto_header("sec-ch-ua", 
//		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");
//
//	web_add_auto_header("sec-ch-ua-mobile", 
//		"?0");
//
//	web_add_auto_header("sec-ch-ua-platform", 
//		"\"Windows\"");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Web Tours",
		LAST);
	
	web_url("welcome.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Web Tours Navigation Bar",
		LAST);

	web_url("nav.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

//	web_revert_auto_header("Sec-Fetch-Dest");
//
//	web_revert_auto_header("Sec-Fetch-Mode");
//
//	web_revert_auto_header("Sec-Fetch-Site");
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Web Tours",
		LAST);

	web_url("home.html", 
		"URL=http://{HOST}:{PORT}/WebTours/home.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("logout", LR_AUTO);
	
	lr_think_time(5);
	
	lr_end_transaction("uc_06_registration_of_new_users", LR_AUTO);

	return 0;
}









void generate_random_string(char *random_string) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    
    srand(time(NULL));

    for (i = 0; i < STRING_LENGTH; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        random_string[i] = charset[key];
    }
}
