//select.c
//For station selection
//Jack_Xul
#include "select.h"
const char *st_info[]={"BR" , "BL" , "G" , "Y" , "R"};
const char *BR[] = {
	"BR1-Taipei Zoo",
	"BR2-Muzha",
	"BR3-Wanfang Community",
	"BR4-Wanfang Hospital",
	"BR5-Xinhai",
	"BR6-Linguang",
	"BR7-Liuzhangli",
	"BR8-Technology Building",
	"BR9-Daan",
	"BR10-Zhongxiao Fuxing",
	"BR11-Nanjing Fuxing",
	"BR12-Zhonshan Junior High School",
	"BR13-Songshan Airport",
	"BR14-Dazhi",
	"BR15-Jiannan Road",
	"BR16-Xihu",
	"BR17-Gangqian",
	"BR18-Wende",
	"BR19-Neihu",
	"BR20-Dahu Park",
	"BR21-Huzhou",
	"BR22-Donghu",
	"BR23-Nangang Software Park",
	"BR24-Taipei Nangang Exhibition Center"
};
const char *BL[] = {
	"BL1-Dingpu" ,
	"BL2-Yongning" ,
	"BL3-Tucheng" ,
	"BL4-Haishan" ,
	"BL5-Far Eastern Hospital" ,
	"BL6-Fuzhong" ,
	"BL7-Banqiao" ,
	"BL8-Xinpu" ,
	"BL9-Jiangzicui" ,
	"BL10-Longshan Temple" ,
	"BL11-Ximen" ,
	"BL12-Taipei Main Station" ,
	"BL13-Shandao Temple" ,
	"BL14-Zhongxiao Xinsheng" ,
	"BL15-Zhongxiao Fuxing" ,
	"BL16-Zhongxiao Dunhua" ,
	"BL17-Sun Yat-Sen Memorial Hall" ,
	"BL18-Taipei City Hall" ,
	"BL18-Taipei City Hall" ,
	"BL19-Yongchun" ,
	"BL20-Houshanpi" ,
	"BL21-Kunyang" ,
	"BL22-Nangang" ,
	"BL23-Taipei Nangang Exhibition Center"
};
const char *G[] = {
	"G1-Xindian",
	"G2-Xindian District Office",
	"G3-Qizhang",
	"G4-Dapinglin",
	"G5-Jingmei",
	"G6-Wanlong",
	"G7-Gongguan",
	"G8-Taipower Building",
	"G9-Guting",
	"G10-Chiang Kai-Shek Memorial Hall",
	"G11-Xiaonanmen",
	"G12-Ximen",
	"G13-Beimen",
	"G14-Zhonshan",
	"G15-Songjiang Nanjing",
	"G16-Nanjing Fuxing",
	"G17-Taipei Arena",
	"G18-Nanjing Sanmin",
	"G19-Songshan"
};
const char *Y[] = {"Y1" , "Y2" , "Y3" , "Y4" , "Y5"};
const char* R[] = {
  	"R2-Xiangshan",
  	"R3-Taipei 101 World Trade Center",
   	"R4-Xinyi Anhe",
  	"R5-Daan",
  	"R6-Daan Park",
  	"R7-Dongmen",
  	"R8-Chiang Kai-Shek Memorial Hall",
  	"R9-NTU Hospital",
  	"R10-Taipei Main Station",
  	"R11-Zhonshan",
  	"R12-Shuanglian",
  	"R13-Minquan West Road",
  	"R14-Yuanshan",
  	"R15-Jiantan",
  	"R16-Shilin",
  	"R17-Zhishan",
  	"R18-Mingde",
  	"R19-Shipai",
  	"R20-Qilian",
  	"R21-Qiyan",
  	"R22-Beitou",
  	"R23-Fuxinggang",
  	"R24-Zhongyi",
  	"R25-XGuandu",
  	"R26-Zhuwei",
  	"R27-YHongshulin",
  	"R28-Tamsui"
};

/*
 *
 *
 *Color selection
 *
 *
 * */


int colo_selection(){
	int st_size = sizeof(st_info)/sizeof(st_info[0]);
	int select_item = 0;
	bool flag = true;
	initscr();//initialize the screen      <===> endwin();
	cbreak();//turn off line buffering     <===> nocbreak();
	noecho();//turn off echoing of typed keys <===> echo();
	keypad(stdscr, TRUE);//turn on keypad mode ==> up down left right  <===> keypad(stdscr, FALSE);
			     //
	while (flag){
		clear();
		
		// Print the list
		printw("Select Info : \n");
		for (int i = 0; i < st_size; i++){
			if (i == select_item){
				printw("--> %s\n", st_info[i]);
			}else{
				printw("   %s\n", st_info[i]);
			}
		}
		int c = getch();	
		switch(c){
			case KEY_UP:
				if (select_item > 0){
					select_item--;
				}
				else if (select_item == 0){
					select_item = st_size - 1;
				}
				break;
			case KEY_DOWN:
				if(select_item < st_size - 1){
					select_item++;
				}
				else if (select_item == st_size - 1){
					select_item = 0;
				}
				break;
			case '\n': //Enter
				mvprintw(st_size + 2 , 0,"Station Info : %s\n", st_info[select_item]);
				refresh();//For the screen to update ==> used in curses mode
				flag = false;
				break;
		}
	}
	//endwin();//end curses mode == (nocbreak() + echo() + keypad(stdscr, FALSE))
	return select_item;
}


/*
 *
 *
 *Station selection
 *
 *
 * */


int st_selection(int *value){
//value 
//0 : BR
//1 : BL
//2 : G
//3 : Y
//4 : R
	int sub_nums;
	int select_item = 0;
	bool flag = true;
	int c;
	switch (*value){
		case 0://BR
			sub_nums = sizeof(BR)/sizeof(BR[0]);
			while(flag){
				clear();
				//print the list
				printw("You're now in the list of %s line\n", st_info[*value]);
				for (int i = 0; i < sub_nums; i++){
					if (i == select_item){
						printw("--> %s\n", BR[i]);
					}else{
						printw("   %s\n", BR[i]);
					}
				}
				refresh();
				//catch the input
				switch(getch()){
					case KEY_UP:
						if (select_item > 0){
							select_item--;
						}
						else if (select_item == 0){
							select_item = sub_nums - 1;
						}
						break;
					case KEY_DOWN:
						if (select_item < sub_nums - 1){
							select_item++;
						}
						else if (select_item == sub_nums - 1){
							select_item = 0;
						}
						break;
					case '\n':
						mvprintw(sub_nums + 2, 0, "You've selected %s\n", BR[select_item]);
						refresh();
						flag = false;
						break;
				}
			}
			break;
		case 1://BL
			sub_nums = sizeof(BL)/sizeof(BL[0]);
			while(flag){
				clear();
				//print the list
				printw("You're now in the list of %s line\n", st_info[*value]);
				for (int i = 0; i < sub_nums; i++){
					if (i == select_item){
						printw("--> %s\n", BL[i]);
					}else{
						printw("   %s\n", BL[i]);
					}
				}
				refresh();
				//catch the input
				switch(getch()){
					case KEY_UP:
						if (select_item > 0){
							select_item--;
						}
						else if (select_item == 0){
							select_item = sub_nums - 1;
						}
						break;
					case KEY_DOWN:
						if (select_item < sub_nums - 1){
							select_item++;
						}
						else if (select_item == sub_nums - 1){
							select_item = 0;
						}
						break;
					case '\n':
						mvprintw(sub_nums + 2, 0, "You've selected %s\n", BL[select_item]);
						refresh();
						flag = false;
						break;
				}
			}
			break;
		case 2://G
			sub_nums = sizeof(G)/sizeof(G[0]);
			while(flag){
				clear();
				//print the list
				printw("You're now in the list of %s line\n", st_info[*value]);
				for (int i = 0; i < sub_nums; i++){
					if (i == select_item){
						printw("--> %s\n", G[i]);
					}else{
						printw("   %s\n", G[i]);
					}
				}
				refresh();
				//catch the input
				switch(getch()){
					case KEY_UP:
						if (select_item > 0){
							select_item--;
						}
						else if (select_item == 0){
							select_item = sub_nums - 1;
						}
						break;
					case KEY_DOWN:
						if (select_item < sub_nums - 1){
							select_item++;
						}
						else if (select_item == sub_nums - 1){
							select_item = 0;
						}
						break;
					case '\n':
						mvprintw(sub_nums + 2, 0, "You've selected %s\n", G[select_item]);
						refresh();
						flag = false;
						break;
				}
			}
			break;
		case 3://Y
			break;
		case 4://R
			sub_nums = sizeof(R)/sizeof(R[0]);
			while(flag){
				clear();
				//print the list
				printw("You're now in the list of %s line\n", st_info[*value]);
				for (int i = 0; i < sub_nums; i++){
					if (i == select_item){
						printw("--> %s\n", R[i]);
					}else{
						printw("   %s\n", R[i]);
					}
				}
				refresh();
				//catch the input
				switch(getch()){
					case KEY_UP:
						if (select_item > 0){
							select_item--;
						}
						else if (select_item == 0){
							select_item = sub_nums - 1;
						}
						break;
					case KEY_DOWN:
						if (select_item < sub_nums - 1){
							select_item++;
						}
						else if (select_item == sub_nums - 1){
							select_item = 0;
						}
						break;
					case '\n':
						mvprintw(sub_nums + 2, 0, "You've selected %s\n", R[select_item]);
						refresh();
						flag = false;
						break;
				}
			}
			break;
		default:
			printw("Error!\n");
			break;
	}

	endwin();//end curses mode == (nocbreak() + echo() + keypad(stdscr, FALSE))





	return select_item;
}
