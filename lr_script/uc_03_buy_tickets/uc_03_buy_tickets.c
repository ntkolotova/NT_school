uc_03_buy_tickets()
{
	lr_start_transaction("uc_03_buy_tickets");
	
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
	
	lr_start_transaction("open_flights");
	
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
		"URL=http://{HOST}:{PORT}/cgi-bin/welcome.pl?page=search", 
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
		"URL=http://{HOST}:{PORT}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Flight Selections",
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=SEATPREF",
		"LB=name=\"seatPref\" value=\"",
		"RB=\"",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);

	web_reg_save_param_ex(
		"ParamName=SEATTYPE",
		"LB=name=\"seatType\" value=\"",
		"RB=\"",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);

	web_url("reservations.pl", 
		"URL=http://{HOST}:{PORT}/cgi-bin/reservations.pl?page=welcome", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_save_string(lr_paramarr_random("SEATPREF"), "SEATPREF_RANDOM");
	lr_save_string(lr_paramarr_random("SEATTYPE"), "SEATTYPE_RANDOM");
	
	lr_end_transaction("open_flights", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("find_flights");
	
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
	
	web_reg_save_param_ex(
		"ParamName=OUTBOUNDFLIGHT",
		"LB=name=\"outboundFlight\" value=\"",
		"RB=\"",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=RETURNFLIGHT",
		"LB=name=\"returnFlight\" value=\"",
		"RB=\"",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Flight departing from <B>{DEPARTCITY}</B>",
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=to <B>{ARRIVECITY}</B>",
		LAST);

	web_submit_data("reservations.pl", 
		"Action=http://{HOST}:{PORT}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={DEPARTCITY}", ENDITEM, 
		"Name=departDate", "Value={DEPARTDATE}", ENDITEM,     
		"Name=arrive", "Value={ARRIVECITY}", ENDITEM, 
		"Name=returnDate", "Value={RETURNDATE}", ENDITEM,     
		"Name=numPassengers", "Value=1", ENDITEM,
        "Name=roundtrip", "Value=on", ENDITEM,		
		"Name=seatPref", "Value={SEATPREF_RANDOM}", ENDITEM, 
		"Name=seatType", "Value={SEATTYPE_RANDOM}", ENDITEM, 
		"Name=findFlights.x", "Value=61", ENDITEM, 
		"Name=findFlights.y", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);
	
	lr_save_string(lr_paramarr_random("OUTBOUNDFLIGHT"), "OUTBOUNDFLIGHT_RANDOM");
	lr_save_string(lr_paramarr_random("RETURNFLIGHT"), "RETURNFLIGHT_RANDOM");
	
	lr_end_transaction("find_flights", LR_AUTO);
	
	lr_think_time(15);
	
	lr_start_transaction("choose_flights");
	
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
	

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Payment Details",
		LAST);

	web_submit_data("reservations.pl", 
		"Action=http://{HOST}:{PORT}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/reservations.pl", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={OUTBOUNDFLIGHT_RANDOM}", ENDITEM,
        "Name=returnFlight", "Value={RETURNFLIGHT_RANDOM}", ENDITEM,	
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={SEATTYPE_RANDOM}", ENDITEM, 
		"Name=seatPref", "Value={SEATPREF_RANDOM}", ENDITEM, 
		"Name=reserveFlights.x", "Value=37", ENDITEM, 
		"Name=reserveFlights.y", "Value=6", ENDITEM, 
		LAST);
	
	lr_end_transaction("choose_flights", LR_AUTO);
	
	lr_think_time(10);
	
	lr_start_transaction("buy_flights");
	
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
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Thank you for booking through Web Tours",
		LAST);

	web_submit_data("reservations.pl", 
		"Action=http://{HOST}:{PORT}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{HOST}:{PORT}/cgi-bin/reservations.pl", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={FIRSTNAME}", ENDITEM, 
		"Name=lastName", "Value={LASTNAME}", ENDITEM, 
		"Name=address1", "Value={ADDRESS1}", ENDITEM, 
		"Name=address2", "Value={ADDRESS2}", ENDITEM, 
		"Name=pass1", "Value={FULLNAME}", ENDITEM, 
		"Name=creditCard", "Value={CREDITCARD}", ENDITEM, 
		"Name=expDate", "Value={EXPDATE}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={SEATTYPE_RANDOM}", ENDITEM, 
		"Name=seatPref", "Value={SEATPREF_RANDOM}", ENDITEM, 
		"Name=outboundFlight", "Value={OUTBOUNDFLIGHT_RANDOM}", ENDITEM,
        "Name=returnFlight", "Value={RETURNFLIGHT_RANDOM}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=44", ENDITEM, 
		"Name=buyFlights.y", "Value=13", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);
	
	lr_end_transaction("buy_flights", LR_AUTO);
	
	lr_think_time(15);
	
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
		"Snapshot=t15.inf", 
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
		"Snapshot=t16.inf", 
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
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("logout", LR_AUTO);
	
	lr_think_time(5);
	
	lr_end_transaction("uc_03_buy_tickets", LR_AUTO);

	return 0;
}
