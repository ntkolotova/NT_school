uc_05_cancel_itinerary()
{
	int i;
	int flightidCount;
	char body[1000] = "";
	char flightIDName[50];
	char cgfield[50];
	
	lr_start_transaction("uc_05_cancel_itinerary");
	
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
	
	lr_start_transaction("do_login");
	
//	web_add_header("Origin", 
//		"http://{HOST}:{PORT}");
//
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
		"Text=User password was correct",
		LAST);
	
	web_reg_find("Fail=Found",
		"Search=Body",
		"Text=name=\"userSession\" value=\"{USERSESSION}\"",
		LAST);
	
	web_submit_data("login.pl", 
		"Action=http://{HOST}:{PORT}/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={USERSESSION}", ENDITEM,
		"Name=username", "Value={USERNAME}", ENDITEM, 
		"Name=password", "Value={PASSWORD}", ENDITEM, 
		"Name=login.x", "Value=71", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Web Tours Navigation Bar",
		LAST);

	web_url("nav.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/login.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Welcome to Web Tours",
		LAST);

	web_url("login.pl_2", 
		"URL=http://{HOST}:{PORT}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/login.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("do_login", LR_AUTO);
	
	lr_think_time(10);
	
	lr_start_transaction("open_itinerary");
	
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
		"URL=http://{HOST}:{PORT}/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Web Tours Navigation Bar",
		LAST);

	web_url("nav.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
		web_reg_save_param_ex(
		"ParamName=FLIGHTID",
		"LB=name=\"flightID\" value=\"",
		"RB=\"",
		"NotFound=error",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Flights List",
		LAST);

	web_url("itinerary.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/itinerary.pl", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("open_itinerary", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("cancel_itinerary");
	
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
	
//	web_reg_find("Fail=NotFound",
//		"Search=Body",
//		"Text=name=\"flightID\" value=\"{FLIGHTID}\"",
//		LAST);
	
	strcat(body, "1=on&removeFlights.x=66&removeFlights.y=7"); 
	
	flightidCount = atoi(lr_eval_string("{FLIGHTID_count}"));
	
//	lr_message("%d", flightidCount);
	
	for(i=1;i<=flightidCount;i++){
		
        snprintf(flightIDName, sizeof(flightIDName), "{FLIGHTID_%d}", i);
        
        snprintf(cgfield, sizeof(cgfield), "%d", i);
        
        strcat(body, "&flightID=");
		strcat(body, lr_eval_string(flightIDName));
        strcat(body, "&.cgifields=");
		strcat(body, lr_eval_string(cgfield));
	}
	
	lr_save_string(body, "BODY");
	
	web_custom_request("web_custom_request",
		"URL=http://localhost:1080/cgi-bin/itinerary.pl",
		"Method=POST",
		"TargetFrame=",
		"Snapshot=t12.inf", 
		"Resource=0",
		"Referer=",
		"Body={BODY}",
		LAST);
	
	web_reg_find("Fail=Found",
		"Search=Body",
		"Text={FLIGHTID_1}",
		LAST);

	lr_end_transaction("cancel_itinerary", LR_AUTO);
	
	lr_think_time(10);
	
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
		"Snapshot=t13.inf", 
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
		"Snapshot=t14.inf", 
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
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("logout", LR_AUTO);
	
	lr_think_time(5);
	
	lr_end_transaction("uc_05_cancel_itinerary", LR_AUTO);

	return 0;
}
