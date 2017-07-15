//////////////////////////////////
#define _WIN32_WINNT 0x0500	//
#include <iostream>		//
#include <ctime>		//
#include <conio.h>		// Библиотеки
#include <fstream>		//
#include <windows.h>		//
using namespace std;		//
//////////////////////////////////

/* Глобальные переменные */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Part=0, inst=0, blue=0, green=0, blues=0, red=0, lil=0, yellow=0, white=0, svetblue=0, svetred=0, svetlil=0, svetwhite=0, bit16=1, bit8=0, Sound=1, Reading=0, FirstGamerWin=0, SecondGamerWin=0;																																																																														//
																																																																																																																															//
unsigned short int Cyclicvariable=0, Points=0, Random=0, valet=0, dama=0, korol=0, dvoika=0, troika=0, chetverka=0, tyz=0, ace=0, color=0, knopka=0,BotLevel=1, CompletedLevel=0, GoldPoints=0, GoldPointAchievement=0, Compliment=0, firstpl=0, secondpl=0, GamerSum=0, ComputerSum=0, FirstSumPoints=0, SecondSumPoints=0, play1=0;																																														//
																																																																																																																															//
int SumPts=0, pts=0, Calibration=0, DifferencePts=0, ConsoleWidht=0, ConsoleHeight=0, Space=0;																																																																																																																		//
																																																																																																																															//
float WinsFirstBotLevel=0, WinsSecondBotLevel=0, WinsThirdBotLevel=0, WinsFourthBotLevel=0, LossesFirstBotLevel=0, LossesSecondBotLevel=0, LossesThirdBotLevel=0, LossesFourthBotLevel=0;																																																																																	//
																																																																																																																															//
string BlueNotBuy = "1. Синий (200 PTS)", GreenNotBuy = "2.Зеленый(200 PTS)", BluesNotBuy = "3. Голубой (200 PTS)", RedNotBuy = "4. Красный (200 PTS)", LilNotBuy = "5. Лиловый (200 PTS)", YellowNotBuy = "6. Желтый (200 PTS) ", WhiteNotBuy = "7. Белый (200 PTS)       ", SvetBlueNotBuy = "8. Светло-синий (350 PTS)", SvetRedNotBuy = "9. Светло-красный ", SvetLilNotBuy = "Q. Светло-Лиловый (350 PTS) ", SvetWhiteNotBuy = "W. Ярко-белый (350 PTS)       ", Buy = "     (Куплено)    ", Spacing = "(350 PTS)";	//
																																																																																																																															//
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);																																																																																																																			//
																																																																																																																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void nenter (unsigned short int NumberEnter)
{
	for(Cyclicvariable=0; Cyclicvariable<NumberEnter; Cyclicvariable++)
	   cout << "\n";
} // Функция для создания отступов

void wait (unsigned short int Time)
{
	int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;
	clock_t end_time = clock() + Time * CLOCKS_PER_MSEC;
	while (clock() < end_time) {}
} // Функция для реализации задержки

void FullScreen ()
{
	COORD coord;
	coord=GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),coord); // Самый большой размер окна
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0); // Полноэкранный режим
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
} // Функция для выставления параметров консольного окна

void ConsoleWidhtAndHeight()
{
	HANDLE hWndConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo)) {
			ConsoleWidht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
			ConsoleHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
		}
} // Функция для подсчета высоты и ширины консольного окна

int nSpacer (unsigned short int NumberSpace)
{
	for(Cyclicvariable=0; Cyclicvariable<NumberSpace; Cyclicvariable++)
	cout << " ";
	return NumberSpace;
} // Функция для установки определённого количество пробелов

int CoutCenterNameColor (string Str, int NumberColor, string Str2, int NumberColor2)
{
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	ConsoleWidhtAndHeight();
	int NumberChar = strlen(Str.c_str());
	int NumberChar2 = strlen(Str2.c_str());
	int TotalChar=0;
	TotalChar = NumberChar + NumberChar2 + 10;
	int CenterStr = TotalChar / 2;
	int CenterConsole = ConsoleWidht / 2;
	Space = CenterConsole - CenterStr;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
	nSpacer(Space);
	SetConsoleTextAttribute(hConsole, (WORD)((NumberColor << 4) | 7));
	cout << Str;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
	nSpacer(8);
	SetConsoleTextAttribute(hConsole, (WORD)((NumberColor2 << 4) | 7));
	cout << Str2;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
	return Space;
} // Функция для цветного отображения пунктов выбора в настройках цвета

void Center (string Str)
{
	ConsoleWidhtAndHeight();
	int NumberChar = strlen(Str.c_str());
	int CenterStr = NumberChar / 2;
	int CenterConsole = ConsoleWidht / 2;
	Space = CenterConsole - CenterStr;
	nSpacer(Space);
	cout << Str;
} // Функция для отображения текста по центру экрана

void CenterC (string Str1)
{
	ConsoleWidhtAndHeight();
	int NumberChar = strlen(Str1.c_str());
	int CenterStr = NumberChar / 2;
	int CenterConsole = ConsoleWidht / 2;
	int FourCenterConsole = CenterConsole / 2;
	Space = CenterConsole - CenterStr - FourCenterConsole;
	nSpacer(Space - 1);
	cout << "|" + Str1 + "|";
} // Функция для грамотного отображения пунктов выбора в меню магазине цветов, используется только в самом магазине

void CenterCL (string Str1)
{
	ConsoleWidhtAndHeight();
	int NumberChar = strlen(Str1.c_str());
	int CenterStr = NumberChar / 2;
	int CenterConsole = ConsoleWidht / 2;
	int FourCenterConsole = CenterConsole / 2;
	Space = CenterConsole - CenterStr - FourCenterConsole;
	nSpacer(Space - 1);
	cout << "|" + Str1;
} // Вторая функция для грамотного отображения пунктов выбора в меню магазина цветов, тоже используется только в самом магазине

void CenterM (string Str1)
{
	ConsoleWidhtAndHeight();
	int NumberChar = strlen(Str1.c_str());
	int CenterStr = NumberChar / 2;
	int CenterConsole = ConsoleWidht / 2;
	int FourCenterConsole = CenterConsole / 2;
	Space = CenterConsole - CenterStr - FourCenterConsole;
	nSpacer(Space);
	cout << Str1;
} // Третья функция для грамотного отображения пунктов выбора в меню магазина цветов, тоже используется только в самом магазине

void cls ()
{
    system ("cls");
} // Функция для очистки экрана

void win ()
{
	  Center("      *******************\n");
	  Center("      *  Ты победил :)  *\n");
	  Center("      *******************\n");
} // Функция отображения сообщения о победе пользователя в одиночном режиме

void lose ()
{
	  Center("      ********************\n");
	  Center("      *  Ты проиграл :(  *\n");
	  Center("      ********************\n");
} // Функция отображения сообщения о поражении пользователя в одиночном режиме

void tie ()
{
	  Center("  ****************\n");
	  Center("  *    Ничья :D  *\n");
	  Center("  ****************\n");
} // Функция отображения сообщения о ничье в одиночном режиме

void player1 ()
{
      Center("*****************************\n");
	  Center("*  Первый игрок победил :)  *\n");
	  Center("*****************************\n");

} // Функция отображения сообщения о победе первого игрока в многопользовательском режиме

void player2 ()
{
      Center("*****************************\n");
	  Center("*  Второй игрок победил :)  *\n");
	  Center("*****************************\n");
} // Функция отображения сообщения о победе второго игрока в многопользовательском режиме

void polosa ()
{
    Center("__________________________________________\n");
} // Функция отображения короткой полосы по центру экрана

void poloca ()
{
	nenter(1);
	Center("______________________________________________________________________________________________________________________________________\n");
} // Функция отображения длинной полосы по центру экрана

void gamer1()
{
	cout <<"                                 1. Взять еще карту" << "\n";
	cout <<"                                 2. Конец хода     " << "\n";
} // Функция отображения сообщения с меню выбора для первого игрока в многопользовательском режиме

void gamer2 ()
{
	cout <<"                                                                                                                    4. Взять еще карту" << "\n";
	cout <<"                                                                                                                    5. Конец хода     " << "\n";
} // Функция отображения сообщения с меню выбора для второго игрока в многопользовательском режиме

void gamer1malo ()
{
	cout <<"                                 1. Взять еще карту" << "\n";
} // Функция отображения сообщения с меню выбора для первого игрока в многопользовательском режиме

void gamer2malo ()
{
	cout <<"                                                                                                                   4. Взять еще карту" << "\n";
} // Функция отображения сообщения с меню выбора для второго игрока в многопользовательском режиме

void card ()
{
	Center("1. Взять еще одну карту\n");
	Center("2. Конец хода\n");
} // Функция отображения сообщения с меню выбора для пользователя в одиночном режиме

void restart ()
{
	Center("___________________________________________\n");
	Center("|Повторить игру?                          |\n");
	Center("|Enter. Рестарт                           |\n");
	Center("|Esc. Вернуться в главное меню            |\n");
	Center("|_________________________________________|\n");
} // Функция отображения сообщения с меню выбора для пользователя в одиночном режиме, после окончания партии

void guide ()
{
	Center("                     t#MMMMMMMMMMMMMMW2bi                                                                                                \n");
	Center("                  ,BMMM@@@MMMMMMMMM@@M#0$$n      ICY7CC            i,..     $ZIC7U0#,  iU7cc7Y7XCY7;;ii.           @MMMMMMMMM$WW@MMMMMMMM\n");
	Center("                 QMM@@@MMM#87;,:inbMM@#@@MM@    .MMMMMM           ,MMMMMM  .MMMMMMMMi  QMMMMMMMMMMMMMMMMMME;       MMMMMMMMMMMMMMMMMMMMMM\n");
	Center("                @M@###MM1           vMM###@MM   .MM#MM#            MM#@M@   M$MMMMMM,  XM@M@@@MMMMMMMMMMMMMMMv     QM@#@@@MMMMMMMMMMMMMMM\n");
	Center("               bM@###M$              .MMMMMMM7  .M@#WM#            M#$BM#   MM@@@@MM.  YMM@@M@YCCon2I9QMMM#@MMW    QM$#@@MMMMM@@#@#@#@$$#\n");
	Center("              .M@##$M@                 i.       ,M@$@M#            M@W$##   MM@@@@MM,  iM@#@M0          ,#M$##M#   bM###MM               \n");
	Center("              EM##$@Mi                          ,M##@M$            @#WQ##   MM#@@@@M.  ,MM##MB            @M$$$MC  EM@##@M.              \n");
	Center("              MM#$$@M                           ,M@#@MB            ##0W@@   MM#$@@MM.  .M#$$M$            YM#W$$M  ZM@@#@M:              \n");
	Center("              M@$$$M@          6A22IUA6EbEbQ$Q  ,M@##MQ            $#BW@#   MM@@$#@M.  .M@$@M@             M$QE$M. AM@#@@M.              \n");
	Center("              M@#$#@M          MMMMMMMM@MMM@M@  ;M@#@MW            #@QW#@   MM@@@#@M,   M@#$M@             W#QW$M, zM@@#@MbvCXCXC7I.     \n");
	Center("        .,,:,,@MM#$@M.         MMMMMMMM#QWEW@@  ;M#$#ME            ##W0##   MM@@@@MM.   M@$@MM             b@$Q$Mi zM@#@#@MMMMMMMMMv     \n");
	Center("       U$EEEQAtCC@@BM;         So7CCCYC$$bEQ@@  7M#$#ME            $@EQ$@   MM@@@@MM.   M@#$MM             E@QQWM, SM@###@MMMMMMMMM,     \n");
	Center("      CEAo7XYCvn@M#@M#                 0#$WQW@  cM#$#M0            #$QE#B   MM@@@##M,   M@$#MM             #$W0$M  SM@###ME998ZEbbB.     \n");
	Center("     ;EnnCt777i,6MM@@MZ                Q@QBW#@  ;M@$#M#            #$EQ#A   @MM###MM:   M##$M@            .M$0Q##  nM@@#MM               \n");
	Center("    YEtoUICvi;YiCMM@@@M#.             Y@$$QB$M  .M@#$@M.          U@QQQ#9iXCSQ@M@@@M:   M@W$MM            Q@QWBMv  IM@#@@M               \n");
	Center("   Z$AInCvi1ECti,MMM@@@MM#X.      :t#MM##$#$@M   $M@##@@C       :EMWWQ$B2BM$9Y;MM@MMi   M@#$@$           QMQWWMW   IM@@$@M               \n");
	Center("   WEA9Ci:X$QE8   CMMM@@@MMMMMMMMMMMMMMM@#B$Mb    #MM##MMMMMMMMMMM$B$@M  $btC$MMMM@Mi   MM$#@#  .,,,,;1WMMW$#MW    9M@B#@M,              \n");
	Center("    WZnYv,vooCz     SMMMMMMMMMM@MMMMMMMbt77nI:     Y@MMMM@#####@M@MMMb  ;z977iv$MMMM;   MM@#@@MMMMMMMMM@@#@MMX     IM$$@MMMMMMMMM####$##M\n");
	Center("    v$oCc;iC1XC.      .1Q@MMMMMMMMMMMbtoC7Xnv,,.     .;EB;iYi;;cSbUc   WbZ2tcv,nMMMM;   MMMMMMMMM$EBbbA#MM#C       ZMM@MM$oISAI9EMMM@MWWM\n");
	Center("     bEn1;:i7vn.            .,:,,.     Ioo2iiYi,.       7tA2ZIv:v.    QQ6Uvinv:MMMMMC   b6Uz6UZZQ;7Cv;;cC          #MMM$C;11ciCob#MM@$#$M\n");
} // Функция отображения "шапки" для информационного табло в 6 пункте меню игры

void statistic ()
{
	Center("CMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@MMMMMMMMMMMM@MMMMMMMMM@MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@MMMMMMMMM@MMMMMMMMMMMM@MMMMMMM@MMMMMMMMMMMMMMM \n");
	Center("CMMMMMMMMMMMMMMMMMMMMMMMMMMM@MMMMMMMMMMMMMMM@MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@MMMMMMM@MMMMMMMMMMMMMMM \n");
	Center("CM@          8M#MM,       QM@MM.          MM#M@        MM#M$  iMM@Mt  8M@MM,          MM#MM        MM#M@  ,MM@MI  zM@MM:  @M@MM   MM#MM          vMM \n");
	Center("XM@          8M@MM        9M#MM.          MM$M#        MM#M@  :MM@MX  UM@MM,          MM$MM        MM#MM  ,MM@M2  CM@MM:  @MMMM   MM$MM          vMM \n");
	Center("CM@   .  .   UM@MM, .   . 0M@MM   .. .,   MM#M@ .   . .MM#M#  :MMMMc  UM@MM.  ..  .   MM#MM .      MM#MM  .MM@M1  7M@MM,  MM$co.  MM#MM   ,  ..  iMM \n");
	Center("XMM  oMMMM8  EM@MMMMM  vMMMM#MM,  MMMMM. .MM$MMMMS  MMMMM#MM  ;MMMM6  bM@MMi  MMMMM.  MM$MMMMA  MMMMM#MM  :MMMM0  zM@MM;  MMX  QMMMM$MM  ;MMMMM  XMM \n");
	Center("tMM  ;MMMMc  IM#MM@MM  ,MM@M#MM.  MMMMM   MM$M@MMi  MM@MM$M@  iMMMMU  bM@MM,  MM@MM   MM$M@MMv  #M@MM$MM  :MMMMQ  zM@MMi  MM2  tM@MM#MM  :MMMMM  vMM \n");
	Center("XM@  iMM@M@@$MM@MM$MM  .MM#M#MM.          MM$M@MMi  @M#MM@M@  iMM     6M@MM,  MM#MM$@WMM$M#MM;  BM#MM#MM  ,MM     CM@MM:    .M#MM@MM$MM          vMM \n");
	Center("CMM  vMM@MMMMMM#MM$MM  ,MM#M#MM,         .MM$M@MM;  MM#MM$M@  oMM   . 0M@MM:  MM$MMMMMMM$M@MMY  #M#MM$MM  XMM     6M@MM;    .MMMM#MM$MM          7MM \n");
	Center("XM@  :MM@MZ:,$M@MM$MM   MM#M#MM   ::.:i   MM$M#MM,  @M#MM@M@  .C;,i.  zM@MM.  MM#MMi,:MM$M@MMi  QM#MM#MM   C;::.  YM@MM,  :i,;,BM@MM$MM   i,.i,  ;MM \n");
	Center("tMM  7MMMMC  AM#MM$MM  ,MM@M#MM,  MMMMM. .MM#M@MM;  MM#MM#M@     MM$  EM@MM:  MMMMM   MM$M@MMc  #M#MM$MM     MM@  AM@MM;  MMb  zMMMM#MM  iMMMMM  7MM \n");
	Center("XM@  YMMMMt  bM@MM$MM  .MM#M$MM.  MM#MM   MM$M#MMi  @M$MM#M@     MMn  AM#MM,  MMMMM   MM$M#MM;  BM#MM#MM     #M6  CM@MMi  MM7  oM@MM$MM  .MM@M$  cMM \n");
	Center("tM@          9M#MM#MM  .MM@M#MM.  MM#MM   MM#M@MM:  @M#MM#M@  vMMMMX  9M@MM.          MM$M@MM;  $M@MM$MM  iMMMM2  tM@MM:  MMMMM   MM#MM   MM@MW  ;MM \n");
	Center("7M#          9M@MM$MM  .MM#M$MM   MM$MM   MM$M#MM:  #M$MM#M#  :MMMMY  oM#MM.          MM$M@MMi  EM#MM#MM  ,MMMMn  7M@MM,  @M@MM   MM$MM   MM#ME  iMM \n");
	Center("CMM:viY;;c;;i$M@MM#MM,:cMM@M@MMY:,MM#MM:iiMM#M@MMS:,MM#MM#M@::2MM@Mb:,$M@MMXii;v;;vi;:MM#M@MMU:,@M@MM#MM::tMM@MW:,QM@MM1:,MM@MMi::MM@MM,i;MM@M@,iAMM \n");
	Center("SMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n");
} // Функция отображения "шапки" для информационного табло в 8 пункте меню игры

void misha ()
{
	Center("UMMMMMMMMMMEM1MZ@@MMMMMMM$MSMEMMMMMMMM@MBQMSMtMZ@@ZM1MzM#MMMMQMQMMMMWM2M#MMbMtMZ@MMM@M@M$QM$MQM8@@MM@MMMM$MoMbMMM@8MWM#M$QM$M@MMMMMMWMzM#MM@M@MMMM$M \n");
	Center("WMYSXzXot1CAMEM$MMvn72CnvMMQM1Ct1oC2C1vM@@MEMbM$MMWMZMbMMYCCC7M@7nXCYMEMMcYUMEM$MMvSXnvM@MMc7YM#MMv172XnvMM0MtYvMM$Mv7;M@MMYttot1oCtcMEMMYCCotottX$M \n");
	Center("$M         iMQMbMM       nM6M.         MM#MzMzMb@@EM2M6M@     Mt    .MZM@  iMWMBMM     MMMM   M0MM       nM6M.  MMQM   M@$M         .MZM@         YM \n");
	Center("WM         v@CM0MM       oMZM,         MI@MIMzME@@8MSMzM#    .M2     MAM@  ;@1M$EM     MM2M   MQMM       SMZM,  MMEM   M@#M         .MUM$         YM \n");
	Center("$M  :Mt@6     M0MM  iM2@8#MZM,  $BtM,    oMAMUM#MM#MZM6M@tM       C@nM9MM     MY       MM     M0MM  iMz@8@MZM,  MM@M.  M@$M  .M9@M  .MbM@CWCM;    7M \n");
	Center("WM  ,M@MM     MQMM  ;MMMMMM9M:  MMMM.    2MAMbMMMM@MbMzM$MM       cMEMzM@     Mn       M@     MWMM  ;MMMMMM6M:  MMMM,  M##M  ,MMMM  .MAM$MMMM7    ;M \n");
	Center("$M  .MEMM     M0MM       oM9M,  MMQM.    zM9M.      .MZM$$M;2i  UYEMAM6MM  ;A:  nz     MMio   M0MM       zM9M,         M@#M         .M8M$@M     ovEM \n");
	Center("WM  .M6M@    .MQMM       CMZM:  MMbM.    8MZM.       MUMW$MMMt  MMMMSM2M@  7M:  MM     M@MM.  MWMM       UM9M:         M@#M         ,MUM#MM     MM#M \n");
	Center("$M  .M0MM     MEMM  ,Cv;:BMZM,  MMBM.    oM9M:::;ii:iMZM$#M       vM9M6MM  iMi:.MM     M@@M   MQMM:;;C;  oMZM,  C;;7.  M@#M   Civ7  .MbM@     CiMMWM \n");
	Center("BM  iMMMM     MQMM  7MMMMMM9M:  MMMMi    nM6M$MMMMMM$MoM@MM       1M@MIMM  iM#MMMM     M@#M  .MQ@MMMMMb  bMZM:  MMMM,  M@#M  ,MMMM  ,MAM@    ;MMMM@M \n");
	Center("$M   .  .  .i.MbMM   ..  6M9M.  .  .   i.0MAMzMEM@EMIM6M@ .   7i    .M8M@  :MUMbMM     M@#M   MQMM   ..  nMZM.  MMQM   M@#M   MWMM  .M8M@     .   ;M \n");
	Center("WM         vMMMEMM       XM9M,         MM@M2MoMb#@ZMnMoM$    .M#     MUM@  ,MIMbMM     M#$M   MQMM       SM6M.  MMbM   M@$M   MQMM   MAM@         iM \n");
	Center("QM.........iM6MEMM...,.. EM8M:.........M@$M6MIMEM@EMAMZM@ ...,MI....,MbM@  :MAMEMM.....M@#M. .MQMM...... EMZM:  MM0M, .M@#M. .MQMM. :MbM@ ..,.,.. 7M \n");
	Center("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n");
	Center(".. . . .. .        . .        . .... .                    . .   .  .               . .      .      . . .      .             .             . . . .  , \n");
} // Функция отображения "шапки" для информационного табло в 4 пункте меню игры

void settings ()
{
	Center("  :;::i,::,::,i:::,:i,i::ii:i,i:,::,i,:i::i,i::::,i,:::ii,i::::::,i:::::i:ii:i:,i,::,:i,i::i::i,i:,:::;i     .ci:::,i,i::::,i,:i:::,i,:i:,i,::,ii:;i  \n");
	Center("  vMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM     YMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM9  \n");
	Center("  iM@;W;MM7MM;BY0Mo@MvbbC#SC@XA0vMMCM$Y$C6#7#ZC$7$MtMMvE9X@C1W;MM7MM;WtC@7b$CBnoMbBM1IB7#It#nt$;MMXMM;#C     ,@t6M6WMX6AvM#zMbXQ;MMXM@vQv@M7MM;E7EMC  \n");
	Center("  :MM   MMcMM   ;MtMM.           MMCMB           XMSMM         MM7MM           :MbQM,           MMvMM   6M7MM.  :M6$M,  .M$6Mv   MM7MM   MMXMM   vMC  \n");
	Center("  :MM   MMvMM   XMS@M.           MM7MW           tMCMM         MMcMM           iM6QMi           MMvMM   MMEMM.  vM6WM:  ,M#MMQ   MMvMM   MMcMM   YMC  \n");
	Center("  :MM   MMYMM   YM2MM.   . ...   MMtM$   ,   ,   CMo@M. .   .  MM7MM   ..  .   ;MEWM:   .. ..   MMcMM   #MXMM   ;M9$M:  .MM...   MMXMM   MM7MM   7Mt  \n");
	Center("  iMM   MMzMM   CMz@M,  1MMMMA  .MM7M$  .MMMMM.  tMCMM$MM.  MMMMMcMM   MMMMM;  ;MZQM;  iMMMMM   MMcMM   #MtMM.  YM6BMi  iMM   MM@MMvMM   MMXMM.  XMX  \n");
	Center("  :MM   MMbMM.  7MnMM,  YMMMMz   MMCM@   MMXMM   7Mn@MYMM   AMXMMYMM   @M$MM:  vMb0Mi  ,MMoMC   MM;MM   #MzMM,  ;MU$Mi  iMM   @MYMMYMM   MM2MM.  XMt  \n");
	Center("  iMM           CMI@M.           MMCM#   MMYMMiY;EMt@M7MM   2M1MMYMM           iM8$Mi  .M@IMC   MMYMM   @M,     vMb$M:     ;1i@M7MMYMM   MM.     7MC  \n");
	Center("  :MM           XMnMM:          .MMCM#   MMYMMMMM#MC@MvMM   AM7MMYMM           iMZQMi  ,M@nMt   MM;MM   MM;     vMA$M; .   IMM@McMMYMM   MMi   . CMt  \n");
	Center("  :MM           CMU@M.           MMCM$   MMYMM,:,bMtMM7MM   IM1MMYMM           :M8BMi   M@IMt   MMYMM   Yv,     vM8BM:     :;,@MXMMYMM   YY.     YMC  \n");
	Center("  :MM   MMMMM.  7MnMM,  7MMMM2  .MMCM#   MMCMM   7M1@McMM   9MCMMYMM   MMMMMMMM0M9QMi  ,MM6Mn   MM;MM      MM:  vMU$Mi  ;MM   @M7MMYMM      MM,  CMt  \n");
	Center("  :MM   MMCMM   CMo@M.  ;MBQMY  .MM7M$   MMMMM.  1MCMMYMM   6MC@MvMM   bMnMMXMMtMAQM;  iMMMMM   MMvMM      MM.  YM6BMi  :MM   MM#MMcMM      MM.  7MC  \n");
	Center("  :MM   MMcMM   YMzMM.  :MQ0Mv   MM1M#           CMo@MYMM   oMCMM7MM   6MtMMvM@zM8WM:           MMvMM   vi.MM   ;MZ$M:  .MM,ii   MM7MM   Yi,MM   7Mt  \n");
	Center("  :MM   MMvMM   7MS@M.  :MQZM;   MMXMW           tMCMMYMM   AMC@MvMM   6M7MMvM@CMIQMi           MMcMM   MM$MM   vM6BM:  .M#MM6   MMvMM   MMWMM   YMX  \n");
	Center("  :M@   MMvMM   ;M1@M.  .M08Mi   M@1MQ           XMo@MYMM   CMCMM7MM   AMtMMvM#oMZQM,           MMvMM   WM7MM   :MA$M,   M$AM;   MM7MM   MMCMM   ;Mt  \n");
	Center("  iM@@MWMM7MMbMM$Mo@M2MM8MQ8M9MM9MMCMBMM@MM$MM@MMBM1MMCMMWMM#MnMM7MMWMM$M1MM7M@nMbWM9MMQMM@MMMM8MMCM@BM@@MCMMZMMQM6BMAMM9M#zMEMMbMMXM@#M#@MXMMbMMWMC  \n");
	Center("  vMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM6  \n");
} // Функция отображения "шапки" для 5 пункта в меню игры

void easy ()
{
	Center(".6UAbAb6UtCCC7SoZ6ztCC6UbU89zttCZno26SS617SC9CC1oIn7on9Z9ZAIo7So9868Z2n7oUZZ6AS7oS6nCnC71YSXCCCCCXSn8AUtC16IbI91C1o6bUZt11S6SCS1ZtCnoA8AbU9tCtzAbU8IU1\n");
	Center(";MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	Center("vM       MMMMMM.   MMM      .MM@ iM  Mv #MM. @MM  MMM       MMM       MMM     MMM  MMMMMM@MMMMMMMMM,   MMM     MMM     CMM: 0MM, EMM,      MMM.      M\n");
	Center(";M  ...  MMMM@:,.  MMM  ...  MM#  I  6  QMM  MMM  MMM  ...  MMM  . .  MMM     MMM  MMMMMMMM,.MMMMM:,.  MMM  .. MMM  .  bMM, QM:. $MM  .,,  MMM  .,,  M\n");
	Center("vM  MMM  MMMMo ;M  MMM .MMM .MM#        $MM. MMM. MMM  MMM  MMM  MMM  MMMM@ CMMMM  MMMMMMMM  MMMME :M  MMM  MMMMMM  MMMMMMi MM .MMMM. MMM: MMM  MMM. M\n");
	Center(";M  MMMMMMMM  #MM  MMM  MMM  MMMMX    vMMMM.      MMM  MMM  MMM  MMMMMMMMM6 iMMMM.      MMM@@MMM  #MM  MMM     MMM  MMMMMMi   MMMMMM.      MMM       M\n");
	Center(";M  MMMttMMM  MMM  MMM  MMM  MMMZ:    :AMMM.   .  MMM  MMM  MMM  MMMSCMMMMA ;MMMM  ...  MMMXcMMM  MMM  MMM  .  MMM  MMM@MMi  .tWMMMM.   .  MMM:.  ,  M\n");
	Center(";M  MMM  MMM  MMM  MMM .MMM  MM#        QMM. MMM. MMM  MMM  MMM  MMM  MMMM2 iMMMM  MMM. MMM  MMM  MMM  MMM .MMMMMM  MMM@MM: MM .MMMM. MMM, MMMMM :M  M\n");
	Center(";M       MMM  MMM  MMM       MM$  M  M. QMM  @MM  MMM       MMM       MMMMt :MMMM       MMMzzMMM  MMM  MMM     MMM  MMM@MM, EMQ  EMM  @MM  MMMMM  M  M\n");
	Center("iM.      MMM  MMM  MMM      ,MMM vM. Mc @MM, MMM. MMM,      MMM.     .MMMMb cMMMM,      MMMMMMMM  MMM  MMM     MMM  MMMMMMi QMM: $MM, @MM, MMMMM ,M. M\n");
	Center("iMMMMMMMMM#MMMM#MMMM@MMMMMMMMM@MMMMMMMMMM#MMMM@MMMM#MMMMMMMMM$MMMMMMMMM$@#MMM@@$MMMMMMMMM$@$#@#MMMM#MMM@#MMMMMMM@MMMM$@$@@MMM@MMMM@MMMM#MMMM#@#@MMMMMM\n");
} // Функция отображения "шапки" для легкого уровня сложности в одиночном режиме

void medium ()
{
	Center("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	Center("MM#@@M@@MM@MMM#@#MMM#@@M@@MMM$MM$MM@#MMMWMMM$#MMM@@@@@#MMM#@@M@@MMM#@M#MMM@$MMMM@MMMMMMM@@@@@@MMM@#M@M#MMM@@@@$MMMMM#M@@MMMMM$MMM##MMM#@@M#@MMM@@M@@#M\n");
	Center("MZ      MMMMMM   MMM      MMM vM ;M .MMC #MM  MM0      MM#      MMM    ,MMi MMMMMMMMMMMM      QMM      zMM,    MMMMi    MMMMY MMM  MM6      MM$      M\n");
	Center("ME CWB  MMMM: B  MMM :W$. MMM  c  ;  MM2 MMM  MMQ Y$B  MMM ;W$  MMME. 9#MMi MMMMMMMI #MM  W$; bMM  MME UMM. M@QMMMMi @: MMMM7 MMM  MMb ZMM  MM# CMM  M\n");
	Center("Mb MMM:.MMMQ. M, MMM IMMY MMM,     .CMMI 8@@  MMB MMM  MM@ QMMC MMMMY MMMMY B$WE#MMo #MM  MMM #MM  MM$ 2MM, MM@MMMM; Mb MMMMo 0@M .MMb BMM  MM# 8MM. M\n");
	Center("M0 @MMMMMM$ bMM. MMM 1MMi MMMMQ    MMMM8     .MMQ BMM  MMM 8MMMMMMMM: MMMM7     .MMMMMMM  MMMMMMM.     zMM:    MMMMX M6 MMMMS     .MM8      MM$      M\n");
	Center("Mb MMM, MM@ 8MM  MMM IMM7 MMM.      7MMA QMM  MMB MMM  MM@ QMMv MMMM: MMMMY MMM ,MM1 $MM  MMM $MM  M@#$MMM, MMMMMM       7MMS #MM .MMMM  M  MMMM  M. M\n");
	Center("Mb cAZ  MM# zMM  MMM ,6b  MMM  1 .X  MMz MMM  MMQ ;8Z  MM@ :69  MMMM, MMMM; 8#W .MM9 @MM  Z9: bMM  MMMMMMM. WbUMMM  ;,:; .MM7 MMM  MMMM  M  MMMM  M. M\n");
	Center("Mb      MM$ IMM  MMM      MMM 7M cM .MMS #MM  MMW      MM@      MMMM, MMMM7     :MMMMMMM      QMM  MMMMMMM,    MMM 7MMMM .MMC MMM  MMMM  M  MMMM  M. M\n");
	Center("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
} // Функция отображения "шапки" для среднего уровня сложности в одиночном режиме

void hardcore ()
{
	Center(":MMMMMMMM@@@@MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@@@M@@@@@M@MMMMMMMMMMMMMMMMMMMMMMMMMMM@M@MMMMMM@@MMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	Center(":Mo1nzCtMM@MMMXCCMMMCnnoC2MM@YMMYMMY@MMXnMM$vMMMCC1oCCMMMnC2S1CMMM71nX$MMI7M@@@@@@@@@M$770M67XMMMoCon1CMMMC11oC1MM@MZtnttM@MM27MMM;#MMzC1oCCMMMSXSntCM\n");
	Center(";M      MMMMMM   MM6      MM; 8$ Qb ;MM  MM, IMM      @MM      MM9    .MM  MMMM@@MMMMM,   M   1MM      $MM      MMMM     MMMM  MMY .MM      7MM      $\n");
	Center(";M  CC  @MMM. 7  MMb ,Ct  MM;  . .  ;MM  MMv ZMM  CC. @MM  CY  MMM;  v8MM  MMMMMMM  MMQ;  .  ;@MM  Eb: @MM ,bb. MMMM  z  MMMM  M  :BMM  XC, XMM  Ebi @\n");
	Center("vM .MMi MMMi  M. MMb vMM  MM9       9MM  CC, 8MM  MMi MMM :MM: MMMM  MMMM  Yvi:QMM  MMMM,   iMMMM .8b: @MM .b9. MMMM  M. MMMM  C  MMMM  MMC 1MM  8b: #\n");
	Center(";M .MMMMMM# .MM  MME iMM  MMMM.   .MMMM      EMM  MM, @MM .MMMMMMMM  MMMM      iMMMMMMMMMz @MMMMM      MMM      MMMM. M. MMMM   XMMMMM  MM; tMM      $\n");
	Center("cM .MM: MM@ .MM  MMb vMM  MM1       CMM  #@: 9MM .MMi MMM :MM. MMMM  MMMM  MM2 ;MM  MMMM    ,MMMM  #@, @MM .#A2oMM$       iMM  @  MMMM  MMt 1MM  $9ozM\n");
	Center(";M  ::  @M@  MM  MM8  ::  MM; .: :. iMM  MMi AMM  ::  #MM  :,  MMMM  MMMM  v;: ;MM  MMo.  i  .$MM  MM, @MM .MMMMMME  :.,. .MM  M,  2MM  ,:  XMM  MMMMM\n");
	Center(";M      MM@ .MM  MMb      MMY $M @# YMM  MM, 9MM      @MM      MMMM  MMMM      iMMMMMM:  .M   zMM  MM. #MM  MMM@MMB iMMMM :MM  MMU ,MM      nMM  MM@M@\n");
	Center(":MMMMMMMMMM@MMMM@MMMMMMMMMMMMMMMMMMMMMM@@MMM@MMMMMMMMMMMMMMMMMMM@@M@@M@@MMMMMMMMMM#@@MMMMMMMMMMMM@@MMM@MMM@MM@$@@@MMMMMMMMMMMM@MMM@MMMMMMMMMMMM@@M@#@@\n");
} // Функция отображения "шапки" для хардкорного уровня сложности в одиночном режиме

void nepobedimyu ()
{
	Center(":n$$#$W7viv;2$$7Y7W$#$$7YCBc9bv0z;vQ2vY02;YQ#$#$SvcQ#$#WnvYQ#$QvvoQ;;;;i;i;;v20icIQivU#B$zc;W$#$$zcvW$#$$ncvB$#$$tYv$$#Qvi;vW$#E;i;YW7vYQ7vYW7;i;E#EvQ2i;i6b;;@c  :Mi\n");
	Center("YMnnt1CMMMMM#CCMMMCn1SCMMM7M$bMn#MM7#MMX@MMznnCtMMMSCSt1MMM7noCMM#7MMMMMMMMMM$tMM$1MM$tCY$MM2St1C@MMz1t1CMMMnntCY@MMntXXMMMMCnCoMMMMvMMMvMMMYMMMMZ1bM1WMMMEnMM@;  ,#$\n");
	Center("o$     ;MMMM.  oMX     ZMi M. M .MM ,MM ,MM     iMM     iM$    MM  MMMMMMMMMM  MM  MM    .MM     ,MM     :MM     ,M@    MMMW    MMM6 ;MA ;Mn YMMM   M  MMM  MM  MM  M\n");
	Center("n$ Y#Y ;MMM .S zMC t@Y 8Mv      .MM iMM ,MM :@o :MM i@C ,MM$  $MM. MMMMMM  MM  MM. MM  MMMMM ,@0 ,MM :@Z :MM cMMMMM@ 7M@MMMB Si MMM8 7MM 7M9  :M    M .MMM  MM  MM  M\n");
	Center("o$ nMMi@MQ .b@ 2MC $M2 bMMt    c@MM     iMM vMM iMM YMMi#MMM  MMM,     MMY,MM.     MM. . :MM ,MM .MM iMM :MM  ,..1M@  . MMMM MI MMME #z  XM6 :. ;   M    M. MM  M.  M\n");
	Center("n$ oMMiMMt QMz IMC #MA EMMC    C@MM     iMM ;MM iMM cMM;#MMM  MMM, ..  MMn,MM.     MM. . iMM .MM ,MM iMM :MM  .. :MM    MMEi i. i@MQ ii  CM9 M; M   M  . M. MM  v.  M\n");
	Center("o$ cMY ;Mo 7M1 SM7 CMY ZM;      .MM ;MM :MM iM9 iMM iM1 :MMM  MMM. MM: MM  MM  MM. MM  MMMMM .MM .MM ,ME ,MM vMM iM@ 7MMMM.      iME  iM YMz YMMM   M ;E M. MM   M. M\n");
	Center("t$     YMS cMX CMX     ZM; M. M .MM .MM .MM     iM@     :MMM  MMM.     MMM@MM  MM  MM    .MM .MM .MM     :MM     iM@    MM. MMME iMb vM8 ;MS ;MMM   M    M  MM  MM  M\n");
	Center("cMS2AznMMM;MMMvMMMt2AztMMMYM$UMY$MMi#MMi#MMCI2UCMMMC2IICMMMM1UMMM#SoAS2MMMMMMbYMMb7MMWn1CWMMcWMMv$MMoo6zS@MMSoA2SMMMnoScMM$;MMMMv@MM;MMM;@MM;MMMMon6MU2oSMWYMMZCMMZIW\n");
} // Функция отображения "шапки" для непобедимого уровня сложности в одиночном режиме

void Header ()
{
	Center("     .,;v7cYcYv7Y7c7vYcYc7YYcYcYYYc7Y7cYvYY7Y7vYcYcYcYYYY7vYc7c7vYYYv7cYYYv7c7YYvYvYYYc7YYcYvYv7cYc7CoY:.. ..iv7cYcYcYvYc7X     ,1XtCnCtCtXC7XY7vYvYYS7.     ,X7;vcXY\n");
	Center("     0QbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbEbE8EbQBWti...:;77YcYvYvYcYvY7SCn299A1177;Y77c1tn1S117XYXi      :1tvYvv;Y\n");
	Center("     966IAUAUAUAIAUAU6UAUAU6I6UAU6U6UAUAU6I6IAIAU6UAI6UAI6U6U6U6IAI6U6I6I6I6UAIAU6U6UAU6U6I6I6I9Ubbo:. .,c7CYYvYcYvYY77tCn77vi..             .,ivttoCCL    in1YYvYvY;\n");
	Center("     o2oU2U2UzIzIzIzUzI2UzUIAIU2AIU2AIUI62A2A26IU2U2A2A2A2UIUIUI62A2A2U2A2A2U2AIAI6IU2U2UIA2U26Ib6Y.  .:YYYvv;c;v;Y7Ctnv:.                        .:v1ZAC,iCCcYcYcYvY\n");
	Center("     z9EE0EQEQEEE0bEb0E0b0EQEQE0EQEQ0Q0QEQEQEQEQ0QEQEQE0EQEQ0QEQ0QEQEQ0QEQE0EQE0EQEQEQEQEQEQ0Q0Q8v...iY1CC7C7C7CX1tt;.     .                          .Yo9otcYvYcYcYv\n");
	Center("     M@#M@M@M@MMM@M@M@M@M@#W$$#$$$#$#$#$#$$$#B$$$$#$#$#$$B$B#$$$$$$$#$$$$$$$$B$$$B#$$$#$$$#$#B$$$QB$##@$#$#$#$#$@$n                                     .;S1CcYvYvYvY\n");
	Center("     M                                                                                                               iiX;.     :vCL            ,MW         iC17YcYvYv\n");
	Center("     M                                                                                                             :@@#$@@U  1@@##@#I         .@MMZ         .;1X7cYvY\n");
	Center("     M   . . . . .     ..iivvY;;i:.       .i,:,:,.   .::,:,:.   .i::,::.    .:,:,:,,      .,i;;Ycvi;,.     .  ..   M$W0QQB$2I#WQ0QQ#@i       .@M@MM1          ,nC7cYv\n");
	Center("     M  ... ... .    iCozno1Sto1onz1c.    ;2ISz1o7,  .I2oSont,  ,6zSzSz7,  ,ozoSoXC1Y.  iC2oonS1Stonootv.     .    M$EE8EbQQW00bbbEB@v      ,MM@@@MM0          .7C7cY\n");
	Center("     M   . . ...   ,CztC77ccvvvYYXCn1ov   :nCC7XC@@  .CSXCYY@#  .ICC77Y@W  CSC7Cv;ZMM..to1XCYY;v;YcX7CCzS;    ..   b#WbbbEbEbEbbbE0#$.     cMM@##@#MMQ           CC7c\n");
	Center("     M  ....... . .nSX7Y7;;v7YXvcY77XCoS  :CCYXv7#@  .1C7Y7;M#  .SCY7YY#Q.;nX77v;UMM. C1CY7vviYY7YY;7YX7toY   .,.   b$WbEbE8b8b80Q#B.     IMM@@$##@#MMM.          YC7\n");
	Center("     M   ... ... .izXC77vX#MMMMM#XYXYXXon .tX7YYY#$  .C177c;@$  .277YYc#A77CY7vioMM, ;CC77cvtMMMMMMB77YXYXW7  .,,    8#WbEbEbEbEQ#8      bMM@@#######MMM.         .17\n");
	Center("     M  ... . .   ;1CYXY;#M@v..:C1XY7Y7cM,.CCY7c7##  .1C7YY;@B  .oC7XYY0ncXY7v;nMM:  Cn77YY;MMB:..iCC77Y7c1#i   ,:.   t#BEEbEbQQ@6      iMM#@#@@@@@#@#MM@          ;z\n");
	Center("     M   . . . . .in77Y7;Mb      iXCY7vvM7.X7XYYc$#  .C1Y7c;@$  .zCX77cYv7YXYcnMMc   otXY7c7ME      XC77YYvMC   .:i.   7$$EEb0Q@X       vMMM@@M@0MMM@@MMM.         .n\n");
	Center("     M. ... ...   i1CY7vvMS     .7tY7YviMo.Yt77YYoZ   tC7Y7;@B  .oCY7Y7vcY7Y7cz#t    c1X7YY;@C      nXXY7;1MS  ..,vni   i$$EQW#X    i.   8MMMMMIio#MMMMM;           7\n");
	Center("     M   ... . .  .zC7Y7v8C  .  .o7XYY;1Mc co7Y7c77;..7CYXY;@$  .I77Y7YEoYY7Y7v7,    itCY7Yv@o     iCCY7v;bM; .:icYIZC   v##$@X   ,ii:     :i:  E7 .i;,             :\n");
	Center("     M  ... . . . .X177Y7Y0,    7CCY7vi@M, .UzYv7YCtSCCY7YY;@B  .oC7XcY$#n7Y7Y7Xn:    S1777Yzn.   .Ct77YviMM. ..,.,;1bA   v#M1   :Cii,,.       iM@                  .\n");
	Center("     M   . . . .   ,otY7Y7z;   c1CYYvitMQ   :WEC;vcY7XY7YXc;@$  .IX7Y7v$ZYYCYXYX1o,   iSCXY7YUv  .Y1XXcviEMA   ..,;XSB$E   ;v   ;AYci:,:,,    9MMMM;                 \n");
	Center("     M  . . .....   CnCY7Y7n7ittC77;iYMM,    .WM@ov;vvYY7YY;@$  .oC77cv$E ioCYXYXnz.   CzY7Y7X1vcC177cviSMM   ,,ic1XSSS;        ,Ynv;ii,,,.   ,   ..                 \n");
	Center("     M   . . . . .   2z7cYY7CtX7Yc;iCMMY   .   ,EMMMbSY7cYv;#$  .z77cc;$0  7zCYYc7to   .UzcYY77tCCYYv;:zMM,   ..,,.,i:    .;i,    ;6CYii,,:,                         \n");
	Center("     M  ..... . . .   bBt;v;c;v;iicQMMS   ...     i0MMC;;i;,$Q  ,SY;;iiQ0   Ctv;;i;Yc   .EWY;iv;v;;iiY#MM,      ...,,   XMMMMMM7   toXCY;;v.   i@E.                 .\n");
	Center("     M   ..... . ...   AMMQUXCXoEMMMM:   . . .       ,vEEb96M@   1Qb9ZZM$.  .bWEZb8EQz    C@BIXXYCtEMMM@        ..,;   XMM@@@MMM;  iEACCX7.   t@$@$,     .          .\n");
	Center("     M. . . . . . ...   .6MMMMMMMM@;    . .......     :MMMMMM$   :MMMMMM$    :MMMMMMMM: ...;#MMMMMMMMWi       .  ,;i   SMM@$##MMX   S1S1i    6#WQ0$#S               i\n");
	Center("     M   . . . . . .        ,i::.      . . . . . .     ... ...    .. . .       .     tZ$$#WQbb6QI: .  v$$#$#$#@6 .      WM###@ME      ;i   ,W$Q0b0E$#b              Y\n");
	Center("     M                                                                              2WWQ0bE8bbbbQt    SBWQWQWQBM#   .I#E@@#$##M$0$b:      1#$E0bbbEEW$Q:           ,S\n");
	Center("     Mt;7tXCXCCCXtXCCtC77CXCYYYYc7Y7YXY7Y7Y7Y7YXY7Y7Y7Y7c7Y7Y7Y7Y7Y7YYcYY7Y7Y7Y7c;ibWQbb90$#Eb8EE$E:.,8Bbb8EbEbMM  cMMMM@@##$@#@MMMMn   .Q@$EE8EbEbEEW$MC          Xn\n");
	Center("     YIA88bZbZb8bZb8bZboZ9b86S2zIzI2U2U2UzI2IzU2IzIzUzUzUoIzUzI2UzIoIoIzIzIzI2I2z10#W88AEMMMMQEbEb$M$b9MM@E8Ebb@M  MM@@#@#@#@#@#@#@MM   vM@W0bEbE8E80E$@@    .    von\n");
	Center("                                                                                  ,B@#$#MM, YQbbbbEMn,:b$WbEbb8@@  WMM@@@MMM@MMM@@MMM    .b#Q0bb8bb0E$@C   ..    izz,\n");
	Center("                                                                                   zMMMMM9  UEEbb6$MWi;:,X0EE8b@M   $MMMMME8oIMMMMM@.      o@WQEEb0Q#$i   .,.   iSz: \n");
	Center("                                                                                          ,QQEZ8AEMMY;;vi2E08bZ@@    ,7C7, t#  ;CY     E;   i$$WEQW#b    ,:,   YoC,  \n");
	Center("                                                                                         X#QQ88A$MMU:;Yv;oQbb8b@M         :MMz      .ibBQc   .W#$B@I    Yi,  .71XYY:.\n");
	Center("                                                                                       :Q#QEbbQMMMt,icvciI0EbEZ@@        6MMMM$.   vz892tti    IM@;   .Y;. .;SX7YY71t\n");
	Center("                                                                                      2@$QE8EWMM@S;i;;cv;oQbE8b#M                     ..;i;i.   i,   .,...i7CY7vYvYY7\n");
	Center("                                                                                    ,W$Wbbbb8bZA2bbzYv;viIEE8b6@MC,.             ...     ..,:.      ....iCXXYYvYvYvYc\n");
	Center("                                                                                  .2@QQ8b9b98Z89bZWMZ7Y;;oQbb69$MoC;vi.             ...            .,iXCCYYcYvYvYvc;v\n");
	Center("                                                                                 .b##$QW0W0WEQQQ0Q$M8otX;nEQEEb@Mz.  :v;:.                      .:iCXC77YYvYcYcYvY;vY\n");
	Center("                                                                                  :@MMMMMMMMMMMMMMMM17Iot;WMMMMMM:     .2otY;:.           ..iYSz9Io77c7vYvYvYvYvv;YC2\n");
	Center("                                                                                   :..     . .  ..., ,vonC1ItCC2:     .tCC7ttononzozoInoSoSzCvi. .77vYvYcYvYcYvY7So2S\n");
} // Функция отображения "шапки" в главном меню игры

void updates ()
{
	Center("@QQQWQWWBQBWWQBQBQWQWQWQBQBQWQWQWQBQWQWQWQWQWWBQWQWQWQBQWQWQWQWQWQWQWQWWWQWWWWBQBQWQWQWQWQBQWQWQWQWQBQWQWQWQWQWQWQBWBQWQWQWQWWWQWQWQWQWQWQWQWQWQWQWQWW\n");
	Center("#WQBWBWBQWWWWWQWQBWBQWQWWWQBQBQBQWWWQBQWWWWWQWQWWBQBWBQBQWWWWWQBWWQBWWQBQBQWWWQBQBQWWWQWWBQBQWWBWWQWQBWBWWQWWWQWQWQWQBQBQWQWQBWBQWWBWWWBQWQWQWW$WWWBQB\n");
	Center("@$#$#$#$$W$W$W$W$B$W$W$W$W$W$B$B$B$W$B$W$W$W$W$W$W$W$B$W$W$W$W$W$W$W$W$W$B$W$W$W$W$W$W$W$W$W$B$B$B$W$WBW$W$QBW$W$W$W$W$W$W$W$BBW$W$W$B$W$BBW$W$$#$#$#$\n");
	Center("#$$#$#$BB@MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@MMMMMMMMMMM@MMMMMMMMMMMMMMMMMMMMMW$$$$#$$\n");
	Center("#$#$#$$#MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM#$$#$#$\n");
	Center("#$$#$$MMMMM$ ..... ... AMZ .......  bM;  zMMMM,  $M, ... .... ;MS ........ BM# .........#M........  ;Mv  oMMMM,  QMC  YMMMM. .M@ .......  YMMMMM@B$#$#\n");
	Center("@$#$$QMMMMMb           vM7          zM.  YMMMM   ZM            M;          8MQ          $M           M.  cMMMM   UM,  :MMQ:   MB          .MMMMMM0#$#$\n");
	Center("##$#$BMMMMMQ   QWWQ$.  1Mz  :M@@@M@@MM,  .;iiv   BM   o$0WBc  ,M7  ;MMMQ   EMMQI   WB   #M   #MM@@#Q#M:  .;ii;   EM;  :n      M@   @MM@@#E#MMM@MMW####\n");
	Center("#$@##QMMMMMQ   MMMMM:  nM2  .v;i;ii,#M:          WM   @MMMMz  :MC  .c;v.  .@MMMY  vMM   @M   ivii,iMMMi          EMv      i   M#   ;;ii,vMMMMMMMMQ@#@$\n");
	Center("#####WMMMMMW   MMMMM,  zMA          6M:  ;86AZ   $M   $MMMMn  :MC         IMMM@   #MM   @M         @MM:  ;b9U8   QMv   ,AMM   M@         MMMMM@MMW#@##\n");
	Center("#$@#@QMMMMM0  .MMMMMi  oMo  ;MMMM:  QMi  2MMMM.  WM   @MMMMz  iMC  cMMM8   QMMY  ,MMM   @M  .@MMMMMMMMi  zMMMM.  0M;  cMMM@   M#  .MMMMMMMMMM@MMMQ@#@$\n");
	Center("$#@@#$MMMMMQ   v;;;Y.  zMz  .UnSS.  bM,  tMMMM   WM   iYi;c,  :M7  ,2oSn   QMM   EMM@   #M   tSntn7iSM:  CMMMM   0Mv  vMMM$   M#   SnnC1Yi2MMMMMMB#@@#\n");
	Center("##@#@QMMMMM9           YM7          6M.  ;MMM@   bM           .M;          ZM;   MMM@   $M           M.  ;MMM@   6M,  :MMMB   @Q          .MMMMMMW@@@#\n");
	Center("$@@@@#0@MMM@nAIA2IzU2Ao#M#1A2AzI2A2z@Mbon$MMMMz2oMMUoA2IzIzAII0MWoIAIUIAIAo@MZCz$MMMM2S2MMzUI62I2UonEMboS$MMMMUoSMMWno0MMM@ooIMMS6IUzI2Uo1QMMMM@0#@@##\n");
	Center("##@@@@@QBMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMBQ@@@#@#\n");
	Center("$@@@@@@M$$$@#@#@#@@@#@#####@#@@@#@#@###@#@##$##@###@#@#@@@#@#@###@#@@@#@#@###@#@##$##@#@#@#@@@#@#@#@###@##$#$##@###@#@##$########@@@@@#@#@##$$$@@@@@@#\n");
	Center("##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@M#\n");
	Center("$@@@@@@@@@@@@@@@@@@@@@@@@@@M@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
} // Функция отображения "шапки" в 7 пункте меню игры

void pvp ()
{
	Center("                      :S$MMMMMMMMMMMMMMMMMMMMMMMMMM@2i                     \n");
	Center("                .nMMMMMMMM#oY,                ,;10MMMMMMMM8,               \n");
	Center("             nMMMMMM1,                                .X$MMMMMA.           \n");
	Center("          zMMMMQ:                                          .ZMMMMZ         \n");
	Center("       .@MMMn                                                  YMMMM,      \n");
	Center("      MMM$.                                                       EMMM,    \n");
	Center("    bMM$     MMMMMMMMMMM$2.   MMMMMMc      ;MMMME 0MMMMMMMMMMM0;    bMMW   \n");
	Center("   MMM.     ,MMMMMMMMMMMMMMM  EMMMMMM      MMMMM  MMMMMMMMMMMMMMM9    MMM  \n");
	Center("  MMM       .MMMMMM@@MMMMMMMM  MMMMMM;    :MMMME  $MMMMMM@@MMMMMMM@    MMM \n");
	Center(" bMM        .MMMMMM    SMMMMM# :MMMMMM    MMMMM   $MMMMM.    MMMMMM.    MMz\n");
	Center(":MM,        .MMMMM@    bMMMMM$  MMMMMM:  :MMMMn   $MMMMM,    MMMMMM     ,MM\n");
	Center("MMM         .MMMMMMMMMMMMMMMM   .MMMMMM  MMMMM    @MMMMMMMMMMMMMMM6      MM\n");
	Center("MMM         .MMMMMMMMMMMMMMB     MMMMMM  MMMMv    @MMMMMMMMMMMMMM;       MM\n");
	Center("vMM.        ,MMMMMMIEEQbo,        MMMMM#@MMMM     @MMMMM#6EbEIY         :MM\n");
	Center(" $MM        .MMMMM@               0MMMMMMMMM,     @MMMMM.               MM7\n");
	Center("  MM@       ,MMMMMM                MMMMMMMMM      @MMMMMi              MMM \n");
	Center("   MMM      :MMMMMM                2MMMMMMM.      MMMMMMY            .MMM  \n");
	Center("    $MMb    ,MMMMM@                 MMMMMMB       $MMMMM;           @MMU   \n");
	Center("     .MMMW                                                       .@MMM     \n");
	Center("       ,MMMMC                                                  9MMM$.      \n");
	Center("          UMMMMQ,                                          ;#MMMMC         \n");
	Center("             tMMMMMMI,                                i6MMMMMM7            \n");
	Center("                .SMMMMMMMMQo;,               .,Y2$MMMMMMM@Y                \n");
	Center("                      .iABMMMMMMMMMMMMMMMMMMMMMMMMBSi                      \n");
} // Функция отображения "шапки" в 2 пункте меню игры

void shop ()
{
Center("@M@@MWMMQMMWM#@M$MMQMM$M@@MBMMBMMWM$@M$MMQMM$M@@MQMMQMMBM#@M$MMQM@BM#@MWMMBMMWM$@MBMMWM@$M#@MWMMQMM$M#@MWMMQM@#MC\n");
Center("@M#MMMMMbM@QM@MMMMM@MMMMMMMMMMMMM@M$#M$MMMMMMMM@MQMM$MMMMMMMMMM#MMQM#MMMMMMMM@M$#M$MM@MMQM#MM@MMbMMMMM@MEMM#MM#Mv\n");
Center("@MMC6CMMQMMWMMt8tA9AMMn6zzQC8EtbSWM#@M$oECQ6t8CMMWMM6UZtQoU016AAMM$MMCEXbEtbo$M#@MBS26M@$M@X6CMMQMMCA7MMBMMoAC@Mt\n");
Center("@MM   MMWMM$MM     .MM           ;M@@M;        @MWMM.          .MMWM@        YM@@Mi  .MMWM#   MM0MM   MMQMM   tMC\n");
Center("@MM   MMMMMMMM     ,MM           YM@@MC        @MQMM:          ,MM$M@        1M#MM7  ,MM$MM   MMQMM   MMWMM.  6M1\n");
Center("@MM   , ,MM. ,     .MM   ;;:iY   YM@@MY   vi,:.MMBMM.  :viic,  .MM$M@.::iY   CM@@Mv  .MM$M@   MMQMM   MMWMM.  CMt\n");
Center("@MM .   .MM   .... :MM.  MMMMM1  CM@@Mo  YMMMMM@MQMMi  @MMMM@  :MM$MMMMMMMC  2M#MMC  iMMMMM   MMQMM   MMMMMi  bMt\n");
Center("@MM     .MM        ,MM   MMMMMi  7M@@M7  ,MM$M#@MWMM.  UMMMMz  ,MMWM@MMMMMi  1M@@MY  :MM#MM   MMQMM   MM@MM:  oMC\n");
Center("@MM   MM:  YMM     .MM           YM@@MC  .MM$M@#MWMM,          ,MM$M@        CM#MM7  :MM      MMWMM           UM1\n");
Center("@MM  .MM,  YMM ... :MM         . tM@@M1  iMMQM$@MWMM:        . iMMWM#      . UM@@M7  CMM   . .MMEMM           ZMC\n");
Center("MMM   MM:  CMM     .MM   .. ..   vM@@M7  .MMBM##MWMM.   .  .   .MM$M@   ..   7M@MMY  .Cv...   MMWMM   ..  .   nMn\n");
Center("@MM   MMMMMMMM  .. :MM   MMMMMY  CM@@Mt  :MMWM$@MWMM:  $MMMMB  :MMWMMMMMMMY  2M@@M7     QMM   MM0MM   MMMMM;  6MC\n");
Center("@MM   MMWMM$MM     ,MM   MM#MMi  YM@MMC  ,MMBM##MQMM:  tMMMMt  ,MM$MMMMMMMY  tM#MM7     CMM   MMQMM   MM#MM,  6M1\n");
Center("@MM   MMEMM$MM     .MM   MM$MM.  7M@@MY  .MMQM#@MBMM.  7M@@MY  .MM$M#        XM@@Mv  ,bC$M@   MMQMM   MMWMM.  1Mt\n");
Center("@MM   MM0MMWMM     .MM   MMWMM,  cM#@MX  .MM$M##MQMM,  YM#@M7  ,MM$M@        CM#MMY  iMM@M@   MMQMM   MMWMM.  AM1\n");
Center("@MM   MMEMMBMM     .MM   @M$MM.  vM@@Mc  .MMWM#@MWMM.  YM@@M;  .MM$M#        CM@@Mi  .MM$M#   MMEMM   MMQMM.  nMC\n");
Center("@MMMMMMM0MMWMMMMMMM@MMMMMMMQMMMMM@M#@M@MM@MMWM##MQMM@MM@M#@M@MM@MM$MMMMMMMMMM@M$@M@MM@MM$MMMMMMMWMMMMMMMWMM@MMMMC\n");
Center("@M#@M$MMbMMQM@@M$MMWMM$M@@MQMMQMM$M$$MWMMWMM0MB#MQMMQMM#M##MWMMWMMQM$MM$MM$MM$M$#MQMMBMMWM$MMBMMbM@$M@@MEMMWMM$Mv\n");
} // Функция отображения "шапки" в 3 пункте меню игры

void Congratulations ()
{
	Center("MM@M@MM@M#M@MM#M@MM@M#M#MM@M#MMMM#M$M@@M#MMMM#M$M@MM@M@MM@M$M@MM@M@MM@M$M@MM@M@MMMM#M$M@@M$M@MM#M#M@MM@M@MM@M$M@MM@M@MM@M$M@MM@M$M@MM#M#MM@M#M@MM#M#MZ\n");
	Center("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM$MMMMMMMMMMM$MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM$M@$MQM@MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMBMWM@MMMMMMMMMMMMMMMMMM9\n");
	Center("MMi,::i:i,:.MM:,::::i,:.MM,,::::,2M#MM,,:i:,,EM$MM.::i::i:,;MM.,:i:::,,CM$,,:i::i:,UM#M@@M#M@.:,::MM.::i::i,,;MM,::i:,.MMi..MM@M#MM..UME..@MY..MM,.:Mb\n");
	Center("MM          MM          MM       ;M@MM       1M@MM         .MM         :MQ         CMMMM#MMM@     MM         .MM       @M.  MM@M@MM  ;Mn  $M.  MM   M0\n");
	Center("MM.         MM          MM       ;M@MM       CM#MM         .MM         :MW         i#6MM@MWEt     MM         .MM       @M.  @b@M$Wb  cMS  @M,  MM   ME\n");
	Center("MM.  MMMMX  MM  .MMMM;  MMMMMMM  YM@MM  YMM  UM@MM  zMMMM. :MM  EMMMM  ;M#  MMMMM     MMMM.  MM. .MM  zMMMM. :MM  EMMMMMM:    9Mi    CMZ  MM:  MM  .MQ\n");
	Center("MM.  MMMMi  MM   MMMM.  MM       cM@MM  :M@  2M@MM         ,MM         ;M$         XM$MM  :MEMM   MM         ,MM       MM,  MM  .M$  7Mz  @M,  MM   MQ\n");
	Center("MM,  MM@Mi  MM. .MMMM,  MM       7MMMM  CMM  @MMMM         .MM         ;M#         WMMMM  iMMMM  .MM         :MM       @M:  MM   MM  XMt  #M,  MM   Mb\n");
	Center("MM   MMMM:  MM   MMMM.  MM:;iC7  vM0 :   i.  ..,MM  .Ci;iiiXMM  :CiY7  iMB  iC;XY  ..,MM  .M@MM   MM:7   St  .MM  :t;v:MM.  MM::;MM  vM#,:MMCL,MMi:;ME\n");
	Center("MM,  MM@M;  MM. ,MMMM;  MMMMMMM  CMo            MM  IMMMMMMMMM  $MMMM  vM#  MMMMM     MM  iM@MM  .MMMM; .MM. :MM  MMMMMMM:  MMMMMMM  7MMMMMMMMMMMMMMMb\n");
	Center("MM   MM@M:  MM   U7X2.  MMv7Y21  YMo  ..    .   MM  iM@MM@M#M@  YM@MM  :MB  vU7In     MM  .M@MM   MMMM   MM  .MM  i67CiMM.  MM#M#MM  vM@iiMMA;iMMYitME\n");
	Center("MM.  MM@M:  MM          MM       cMz  MMMMMMM   MM  ;M@MM#M$M@  7M@MM  iMW         oMMMM  ,M@MM   M@MM.  MM  .MM       @M.  MM#M$MM  vMY  BM.  MM   Mb\n");
	Center("MM   MM@M,  MM          MM       ;Mn  $M#M@MM   MM  :M#M@#M$M@  vM#MM  :MQ         ;M@MM  .M@MM   MM@M   MM  .M@       @M.  MM$MBM@  ;MC  WM.  MM   ME\n");
	Center("MM@M@MM@M@M@MMMMMMMMMMM@MMMMMMMMMMMMMMMM#M@MM@M@MMMMMM#MM#M$MMMMMM#MMMM@MMMMMMMMMMM@M#MMMM@M@MM@M@M@MM@M@MM@M@MMMMMMMMMMM@M@MM@M#MMMM@MMMMMM@MMMM@M@ME\n");
	Center("MMBM#M@$M$MM@M#M@MMMM@M@@M@M#MMMM$M$MM$MEMW@@#M#M@@M$MQM@$MQM#MMBM0M#MM$M$MM@M#MMMM#MWM@@MBMW@@@M$M#$M$M#M@@M$M#MM@M@MM#M$M@@@QMEM#MM#M$MM#MBM#MM@M#MU\n");
} // Функция отображения "шапки" в момент открытия нового уровня сложности

void BlackJack ()
{
	wait (50);
	Center("                                              .YAn.                                                   oIC.                                 \n");
	wait (50);
	Center("                                            c0Q1.iM:       . .                                      .Mv.i9bo.                              \n");
	wait (50);
	Center("                                         ;EQz.    :M1z$@MMM@@@MMM@@bS;.                    CWEQEZ:,,@.  ...cEQ2,                           \n");
	wait (50);
	Center("                                      ibWU,     iQ@Wb1;iii;cvc;v;;;76MM@MMQ7.    .       .MM1SC7MM@MC  ,M;    vEWA:                        \n");
	wait (50);
	Center("                             :,    ibB6:      :MMtvii:C@MM@#@#@$$QEtii;czWMMM$.iMMMM, .;$M6;cvCLbM:@M7.Mi        ;bW6:                     \n");
	wait (50);
	Center("                           Y@c70C2W8i        CMC;cv;;MM$XE#@MMMMMMW0$7;c;;;@MnMM1::bM$$EYv;YYYvi8M,@M:              :tZo,                  \n");
	wait (50);
	Center("                          tW  C$6i          :MciYYYiMM1iMQWA7ii;CQMMBQcv7v;:WM:EMICcCoAE@$vv7Y7iEM:#M;   9I;,        .QWE@n,               \n");
	wait (50);
	Center("                         2Mz26i           itM@,cc7viMM:EM$         ,MMYvY7v;,MM.MMMM@@@#$$icY7viZM,#MMM CL ,tvi    YbA.  iMMIIi            \n");
	wait (50);
	Center("                        ZMC.           i2##S@M:iYYY;;@M2$Mi 7@Mv     M7;7YY;:MM.M$vEMMMMMM;;7YY:bM:#MS ;M     M#A2W8:  n. .$t YB7          \n");
	wait (50);
	Center("                      .MM   .       :2$#bInnYMM;:;;cii;zXY$@7;MMMM  YMiYY7viiMM.MM    . .M;vY7vi8M,@M. $WY ,:I$ZC,   :Wc    E2 CM          \n");
	wait (50);
	Center("                     :Mibc  Z6:   Q#@EUozSS1CvMMb;vii::,:,::6MB;MWC6M;vvY;iiMM,8M$.      M;;7Y7:bM:@@UASz9#MMQX;     2:      oMQ           \n");
	wait (50);
	Center("                    7M.  MY ..2:  X@2zSononotCc#M#ZbEQEQQ$@M#IUM@MMQiv;;:ibMM:bMQ2       M;vY7vi8M,#M@7oIB@A: ,@Q$M:          ;M.          \n");
	wait (50);
	Center("                   UM     @t.   .  :#ooSonoSIbWC$MMM@#@@@$WQMMMMQ7i:i:ic#MMttMMW6        Mv;7YYibM:$M$1$$C.   ,;EM7  ,9b.      ,MX         \n");
	wait (50);
	Center("                  0B       M;  zMA7i;#oononI67,19bWMMM$9WMMM@8i:,,:;z#MMB6Z@M@0Y         M;vYXciZM,#MMn;        .;,ib@bQ#:       @8        \n");
	wait (50);
	Center("                 MZ       o#Mi bM9Ez i@zoSz6I     n;v2@#@E7:,,,iIWMM@WQQ@MM@A;          7M;;7YY:EM:#Mc           ;ZW6S2oZ@Y       bM       \n");
	wait (50);
	Center("               .MC      .UCo0$Yi; ;   v@ozSWi     1WMMEv,,,;U$@@BQ8W#MMM$o;.           YMMicY7vi8M,@Mi        i9#EozSzSoSI#S       CM,     \n");
	wait (50);
	Center("              iM:      .Q.  cW$:       v@z26C .v:MM@1:,,7$M@$QWW#MMEW1c,              C0.M;;7YY:bM:@M;     .CB@ZUoo1znz1on2$9       iMY    \n");
	wait (50);
	Center("             7M. Y    ,M     $z@c       v@2zAWb#MM;:,ibMME2E$@#$ZAMS        #M$,:    7M  MicY7viZM,@Mi   :o@B99B8QZoSoSonoS2E#.      .M9   \n");
	wait (50);
	Center("            7M  ,AWC   ,i:vXCI2z@Y       ;@otcMMCiiiQMMUWMM@AY;,   Z,     iMM;MMMM  ;M   M;;7YYibM:@M, ;0#0zz61izX1bznznononzEMC       b$  \n");
	wait (50);
	Center("            :M;    92  .;cYBMWIIz@7       i#7MMiivv@MY;MMM@MM##@A@0@MMMMMM@t:iM$:MY:M  ,MMivY7viQM:MMEzBA2no2b     Y8o1onzoZ$#oi        nM \n");
	wait (50);
	Center("              CWZ,v   .W@#. .C#$bz@7       ,MM::;;vii:i::,:,:i;ivi;ii;;i;iiii:MWiM$@   MMZi;v;viv@tCMMovC1onI6,.   I6nzSUb@8;          .Eb \n");
	wait (50);
	Center("                :8bc :M$$Mn    ;U@WMX       M;,i;v;;;;;;iii;i;i;;;i;i;i;i;;;iiM$:MQEi@M2::i;;v;;iivc;9MMtvXon9vn  vWno2B$o,          YQE:  \n");
	wait (50);
	Center("                   iSc;,         .1#M1      vMMM##@@@@@$#######$####@$#$#$#$#B@CLMv nM@E$$#####$@#BW#1:SM$YY1nbbQQb7XX7,           ;bc     \n");
	wait (50);
	Center("            YM@MM@M@MMMM#M$M#MM@M#M@@M$M$M@MM@M@MMMM#M$M@MM@M@MMMM#M$M@MM#M#M@@M#M$M#@@#M#MM@M$M$M@MM@M@MM@M$M$M@@M@M@MM@M#M$M@@M#M#MM@M#MY\n");
	wait (50);
	Center("            SMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMZ\n");
	wait (50);
	Center("            cMM.,,:,::,.$M@MMMM; 7MMMM@M@MM.,,:,::,.QM@MM,,,:,::,.QM@MM. QMMMM. bM@MMMMMMB.,,.EM@MM,,,:,::,.bM@MM,,::,,:,.bM@MM. bMMMM..bMt\n");
	wait (50);
	Center("            cMM         MMMMMMM. .MMMM@M@MM         bMMMM         bM@MM  6MMMM  nM@MM@M@Mo    9MMMM         UMMMM         IMMMM  zMMMM  XMC\n");
	wait (50);
	Center("            vMM  :CcC7  i12MMMM  .MMMM@M@MM  :tc7C  ZM@MM  :X;77  AM@MM  bM@vXi:QM@M@MM@M$iY  2M@MM  ,CcXC  oM@MM  ,C;YC  nM@MM  2M@vXiiEMX\n");
	wait (50);
	Center("            cMM  MMMMM.   .MMMM: iMMMM@M@MM  MMMMM. WMMMM  MMMMM  8M@MM  @MQ  MMMM@M@@M@MMMM  QMMMM  MMMMM. EMMMM  @MMMM  IMMMM  $M$  MMMMX\n");
	wait (50);
	Center("            vMM  9M#M@   .iMMMM  .MMMM@M@MM  UM#M@  bM@MM  EMMMM  bM@MM  o@I  MM@M#M@MM@M@MM  AM@MM  nM#@M  IM@MM  9MMMM  AM@MM  CM9  MMMM7\n");
	wait (50);
	Center("            vMM         MMMMMMM, :MMMM@M@MM         WMMMM  QM@MMMMMM@MM    ,MMMM@M@MMMM@M@MM  EMMMM         EMMMM  ZM@MMMMMM@MM    .MMMMMM7\n");
	wait (50);
	Center("            :MM         $MMMMMM. :MMMM@M@MM         EM@MM  QMMMMMMMM@MM    :MMMM@M@MMMMMM@MM  9M@MM         6M@MM  9MMMMMMMM@MM    ,MMMM@M7\n");
	wait (50);
	Center("            vMM  @MMMM    ,MMMM. :MMMM@M@MM  $MMMM  QMMMM  WMMMM  ZM@MM  $ME  MMMM@MM  9MMMM  bMMMM  0MMMM  8MMMM  bMMMM  2M@MM  EM$  MMMMC\n");
	wait (50);
	Center("            vMM  MMMMM    .MMMM, YMMMMMM@MM  #MMMM  EM@MM  @MMMM  ZM@MM  $Mb  MMMM@MM  $MMMM  bM@MM  QMMMM  8M@MM  $MMMM  2M@MM  QMB  MMMMX\n");
	wait (50);
	Center("            cMM   . ..  9M#MMMM   .   EM@MM  bM@MM  bMMMM   . ..  8MMMM  9MM@$  9M@MM   . ..  9MMMM  UMMMM  IMMMM   . ..  IMMMM  zMM@@  AM1\n");
	wait (50);
	Center("            :MM         $MMM@MM       2M@MM  8M@MM  6M@MM         6M@MM  6MMMM  CM@MM         zM@MM  zMMMM  SM@MM         nM@MM  nMMMM  7MX\n");
	wait (50);
	Center("            vMMCInZn6oI1@M@MMMMUUn6zzt#M@MMXC#M@MMCX#M@MMCInZn9z21#M@MMXC$M@MMC7$M@MMtASZS6221$M@MM7CBM@MMCX$M@MMtAnZSZz21$M@MMCtWM@MMCC#Mt\n");
	wait (50);
	Center("          YM@MMMMM#$$#MMMMMM@$@MMMMMM@#@MMMMMM@$@MMMMMM##$#$$$$$@MMMMMM@#@MMMMMM@#@MM@MM@MM#@MMMMMMM#$$$@MMMM$@MMMMMM@##MMMMMM@$##MMMMMMM#@MMMMM@$@MM$$B$$#MMM:\n");
	wait (50);
	Center("          UMMZYYY6MMMM1YvcccMMMCcc;;:MMMcYvcctMMMcvc;7SMMMMMMMMMMovY;Y;MMMXYvYvYMMMiMMvMM;#MMQYv;YvMMMMMMo;cMMMovYvYvMMM7YvYcCMMMM$YvcvYMMM6iC;YMMMiMMMMMMMMiMY\n");
	wait (50);
	Center("          1MM     MMMM      @MM      MMM      MM@      MMMMMMMMMM      #MM      MMM :M iM iMM      1MMMM@   WMM      @MM      BMMM.     vMM.    MMb ZMMMMMMY MY\n");
	wait (50);
	Center("          XMM  M  MMMM  MMz MMM iMMMMMMM SMMi MM@ zMM  MMMMMMMMMM  MM9 MMM ,MMv MMM       iMM. MMM UMMMQ @@ QMM  MMz MMM ;MMz  .MM, MMM vMMMM AMMM0 $MMMMMM1 Mv\n");
	wait (50);
	Center("          nMM  M  MMMM  MMS MMM      MMM      MMM oMM  MME    bMM  MMS @MM .MMv MMMMv    MMMM.     AMM. $MB BMM  MMt @MM      MMMM:     CMMM@ AMMMW     .MMY Mv\n");
	wait (50);
	Center("          zMS  Z  1MMM  MMo @MM  ;i  MMM  ,..,MM@ oMM  MM$    QMM  MMn MMM ,MMv MMMQ,    bMMM. :.. 6MM  MMZ WMM  MM2 MMM  i;. C#MM, .,. YMMM# tMMMW .i:  MMW.Mi\n");
	wait (50);
	Center("          bM       bMM  MMX MMM iMM7 MMM YMMMMMMM XMM  MMMMMMMMMM  MMX @MM .MM; MMM       iMM  MMM oMM  MMZ WMM  MM7 MMM iMMo  ,MM, MMM cMMM# 1MMMW #MM  MMMMMi\n");
	wait (50);
	Center("          bM AMMMZ 0MM      @MM      MMM :MMMMMM@      MMMMMMMMMM  MMY #MM      MMM iM 7M :MM  MM# 1MM  MMz bMM      MMM      MMMM  MMM iMMMW YMMME      MMY M;\n");
	wait (50);
	Center("          0MEMMMMMbMMM#0QEQEMMMBQ0QEWMMMZMMMMMMMMEQEQE#MMMMMMMMMME#MMMZMMM$QQEQQMMM9MMEMMbMMM#0MMM9MMM$WMMM6MMM$QEQEQMMM$EQEWWMMMMMZMMM6MMMMM6MMMMMEQE0E@MMMIMY\n");
	wait (50);
	Center("          .AIYi;i7SYivn66ZAUv;;2U896zvivnCii:iiiv66Z69n;iiii:ii;;SCviYocivz69ZUU;i;2XYzCv2Y;;CS;icnY;vCS;;c2;i;oU869Icivo968AIv;i;7z;i;2Y;i;voviiivUUZ9UtviczS \n");
} // Функция анимированного отображения в момент заставки

void loading ()
{
	Center(";2tnCCvii;7nttCv;vYiii;7iicnC1CYiiiiii:iiiiii7cii7;ii;7tCXi;iiiCCci;7vii:iiiiiit.           :7XX7CXtXC7C7C7XYXY77C7CCtC1C1CtCC7CXC77YYcYi.          \n");
	wait (50);
	Center("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMC       .S$@@@#$@#@#@@@@M@MMMMMMM@@##$$B$$$$##@#@@M@MMMMMM@bv       \n");
	wait (50);
	Center("Mi    QMMM     MM2 MMMA MM;    nMMMMMMMMMMMMM ,MM UMMM    MMMMM  IMM @MMMMMMMMMMn     9MMM@$0QEQ0QQBQ$#$$##@@M@M@@#$QQEQEQQWQB$#$##@MMMMMMMMMMM;    \n");
	wait (50);
	Center("M.iMM  iMM 9MM MMS MMMA MM: MM ;MMMMMMMMMMMMM .MM IMMM IMMMMM9 M XMM MMMMMMMMMMM1   vMMMMMMMM@MMM$W0#@MM##MMM#MMMMMMMMM@MMM#@@MM@@MMM#MMMMM@MMMM$   \n");
	wait (50);
	Center("M: i: nMMM  :. MMU M,@W MMi :i CMMMMMMMMMMMMM ,MM UMMM  .,MMY,0M tMM  . .MMX   M2  IMZ  :: iM@. zM$WM@ MMM@ .C 1: CMU EMv :@MM @MMM..C.i.  nM@  #M  \n");
	wait (50);
	Center("M:.b9 iBMM .Ci MM2 M QM MMi C7 7MMMMMMMMMMMMM iMM QMMM ,2tMM  MM CMM c8: MMI,,:Mo ;MMM  bM  :M  MMQWMY bMM  MM29i MM.9MMA YMMX zMM  MM9U6  MMY @MMM \n");
	wait (50);
	Center("M..MM  tMM 0MM MMI # v7 MM. MM iMMY@M@7MMQnMM  $0 :@MM Y@#MM  MM YMM bMo MMMMMMMi MMMM  8M: :M  MMb@M:  MC oMMMM: ZCMM$M6 CMMi  MI YMMMMU .M;,MMQ#Mi\n");
	wait (50);
	Center("Mv    #MMM 6M@ @M8      MMi MM vMM 9MZ MM: MM,     :MM    MM,.MM CMM     MMMMMMMi MMMM  8M .MM  MMQMboi Mv ZM@MM;   MMWM8 nMQCc MC zM@@M6 ,:iMMEbbMA\n");
	wait (50);
	Center("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM;,MMMMi nY.#MM: MMMMYA2 bW EM@MMC Q iMMM0 ZMXz6 2$ 9M@#ME : .MMB8b@Q\n");
	wait (50);
	Center("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   nM@MM: $M7 ;M, MME6:MM  M  MMMM; M0 ,MMQ 8M,MM  M  MMMMb C9  MMWb@Q\n");
	wait (50);
	Center("MS    WM#   iMM 9MM $MQ    vMM.nMMM.7MM   .MM,vMMMMMMMMME    1MMMC    6MM   :M   8M@MM. bMQ  $. YS .iMM, b@ .YYA, UM. vMb 1z.MM: U@..7v$8 :M:  MMB$Q\n");
	wait (50);
	Center("M  nC AMM;  EMM EM.:MM6 bQ  MM vMMM ,MM7  IMM ,MMMMMM@MMt EQ  ;MM. t1 iMM c9$M   bM@MM  YM.  MMMMMMMM@@MM@MM@W@MMMMMMM6;i MMMMMMMMMM@WMMY  MM   @MME\n");
	wait (50);
	Center("M.;MM AMMM QMMM io:MMMb #@  MM .bQM iMMM cMMM  bo2@MMMMMz @M, iMM..MMYbMM o#@M   EMMMt..:Y.YMMMM@M@@#$$$WWEW$@@MMM@@@MM@@MMM@@##$$W$$MM$iii$MY. i@M0\n");
	wait (50);
	Center("M.iMM ZMMM IMMM  iMMMME    :MM    M ;MMM :MMM.    6MMMMM6    ,MMM. MMMMMM   iM   bM@@MMMMMMMM@##@#@#@@MMMMM@MMMMMMM@A;QMMMMMMMMMMMMMMMMMMMMMMMMMM#ME\n");
	wait (50);
	Center("M.,MM UMMM 2MMM Q$ MMMU MMMMMM 6M M :MMM ,MMM iMM IMM@MMn MM;  MM. MM ;MM @MMM   EM#W$$@$###$#$###$@@M$$WQ8ASz29A6i,...CL:.,.:,,....         0M#$#@Q\n");
	wait (50);
	Center("M.    6MMM CMMM nM$ $Mo MMMMMM    M ,MMM .MMM     ZMB #MS    .MMM,    YMM   .M   EM$WQ$WBW$W$W$$$$##MS                                       6M##$Mb\n");
	wait (50);
	Center("MM$$$#MMMMQMMMMWMMMbMMMQMMMMMM##$@M#@MMMB@MMM@$$B#MMM9MMM$$$$MMMMM$$B#MMM#BW@M   0M$0QQWQBQBWBW$#MMMM#      oM;                              #M@#@ME\n");
	wait (50);
	Center("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW  bMWQ0WQWQBW#@MMM#U:iM       M;                              MM#@#Mb\n");
	wait (50);
	Center("MM@SXS@MMM2t7CCMM@CC7tEMMnCnYMMQzMM2QMMCMM8MC@MMtCvbMMX#MM7MM#7MMEUMMbCCXoMMMMM. EMWEQQ$#MMMMQC,     Mc      M6                              MM#$#@0\n");
	wait (50);
	Center("MMY   AMMM     @MS     MM.   MM. MM ,MM b; M zM#   vMM SMM @MC MM  MM     WMMMM  EM0E$MM#U;          0b      MM     ZCv;XCoSAU$$$Q@Mi        MMQBQ@Q\n");
	wait (50);
	Center("MMX M 8MMM QMM MMU MMi MMM: MMM: MM iMM      $M@ MMMMM IMM MMU MM. MM 1MM $MMMM  QMW$$       v       7M   .M.AQ     ZMM@MMM@@@MM@@MMC    1.  M#EE0$$\n");
	wait (50);
	Center("MMn M 0MMM ZMM MM2 MMMMMMM, MMM: M  CMMM:   MMM@   :MM     MMI M. .MM     @MMMM  EMWMM       MM,     .M.    ..       .MMMMMMM@@MMM#ZMv  8M.  M#bEb$W\n");
	wait (50);
	Center("MX     XMM WMM MMU MMY.MMM. MMM;  M ;MM.     #M@ MMMMM CM$ MMb  M, MMM. M $MMMM  QM#$MM      : MW     @7    MMMM       #zzn7v:: .0  .;iA@M   M#0EE$$\n");
	wait (50);
	Center("M  WZW  MM  .  @MS ..  MMM  MMM. EM ,MM S: # 2M# ..tMM 2MM @Mo 6M. MMM, M WMW M  bM@#@MM     ;..UMn   Z@   :#bWMz.     Ui7;Y7M8 ##;    7MM   M@Q$Q@W\n");
	wait (50);
	Center("M9EMMMn2MM7i:iiMM@i::iIMMMz7MMMUXMMYZMMiMMnMi#MMi:,oMMiMMMCMMMIMM#QMMM#$MoMMMcM, EMM#@@M#    7.  YU   :M  MM@$QW@MA   iIYZY6      9;   7#$   M@#$@MB\n");
	wait (50);
	Center("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM$@M@@MM@@MM###MM@MM#MMM  bM@@#@MMS   Y,    .v  @. @MMM@@M#,  oSicYUt  7U :1.   i@M  .MM@@$B9\n");
	wait (50);
	Center("MM##$#MMM##@@@MM@MM@MM@MM@$#WMMMMMW#MMM@#@#@MMM$MM@B$MM                          EMM$@M8 MX    v: 7M@Mo0A     Y   7QYYQ6ii7,  .XvbQ8.  0M@Ct8MW08EE0\n");
	wait (50);
	Center("M.    8M@     MM  M M. MM    MMMM@  vMM     MM; MM.  MM:                         bM@@MB  ;Mi ,MMMQQbb8MI$      ,QMM$7;MM9Iti:.cZ6:8EMMMWbZ@#@$#EQQBQ\n");
	wait (50);
	Center("M.,MM 9M@ MMt MM.     .MM CMMMMME M iMM #MM MMY M bM# Mv                         6M@MM    UM  BM$BbbZ#1.@     ZMM7..CL#M$M$Wbbc6iC#MbQ$   97 c7@$$$B\n");
	wait (50);
	Center("M.iMM 8MM MM6 MMM8   6MMM    MMc @M ;MM     MMo    6M Mv                         YMMM1   ..8M  vZW@@M$  MY  WMS:;t@MCLQMEbIQ$#MBAEMi .v7onz;  $A@#@Q\n");
	wait (50);
	Center("M.:MM 9M@ MMb MMQ,   .EMM :$bMM. MM iMM ;bv MMt b ;MM MY                         ,MMMc   i..WM     iEi  Qb  M0b$C@MM$@0M@MEXiBMQ##67; 8oI .MM,:;,MMQ\n");
	wait (50);
	Center("M .MM UM@ Yz. MM  X X  MM .EAMM. MM :MM #MM MMv M7zUCiM;                          @MMc   :, ,@#         7@  nMMMo.  .,,.cU$#Q$ME$$:W Z@     MM Y:MM:\n");
	wait (50);
	Center("M;vMM 8M@    .MM:XM MS,MM,   MMv.MM.7MM WM# MMn.MMC ,MM;                          ,MMB . ,:. iMb .      .M,.6Q.             ;MMW0#:. :MM  .SM8 MUMM \n");
	wait (50);
	Center("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM;                           iMMc . ,:. ;MC .      MM.    ,,:::,:,,..   nM#QQi@..QMM@Qz   MM  \n");
	wait (50);
	Center("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@                                    .MMC   ....CMi      Y@   ..:.........,,,   ;$W$$oi  S.  6MoM@   \n");
	wait (50);
	Center("M:CM MMM@   vMMM;    AMM #ME MMi MM cMMMMMB  @MM                                      XMMX:,    CM.    iA    .              .  Z#W$#@@2QM1U6MMM:    \n");
	wait (50);
	Center("M cM MMM# b .MMM  MM 1MM MM$ MM, MM ,MM bMMo  $M                                        ,9#@M#E62MMIAoZMWI6AQEZb9b9b9bZb98ZbEWMMMMMMMMMMMMM@C       \n");
	wait (50);
	Center("M. Y MMMM M;:MMM, 0b zMM :n, MM: Mo 7MM,$MMME 7M                                             ,;i;iY1ozzt1SzzzSoSzSzSzSzS2n2Szntvv;v;i:,,            \n");
	wait (50);
	Center("Mb:. MMMI $  @MM, .. UMM     MM; #. YMMEMMMMM YM                                                                                                    \n");
	wait (50);
	Center("MMM@ MM7      MM  MM 7MMMMMB MM;  M iMM 9MM@  ZM                                                                                                    \n");
	wait (50);
	Center("M:   MM7 MMMn MM  MM 7MMMMMb MM: MM :MMMMMW  WMM                                                                                                    \n");
	wait (50);
	Center("MMMMMMMM@MMMM#MMM@MM@MM@@@MM@MMMMMM@MMMMMMM@MMM@                                                                                                    \n");
} // Функция анимированного отображения в момент заставки (2)

void gameover ()
{
	Center("iMMMMMMMMMMMMMMM@MMMMMMMMMMMMMMM@MMMMMMMMMMMMMMMMMMC              .MMM,               ,@6Z8#M@@@S;;YQ@W#1;1B$QQXiXQ00@7.,Wb$8v.o$$W;::1##@EA6b0@#@M@bZAZb\n");
	Center("iMMMMMMMMMMMMMMM@MMMMMMMMMMMMMMMMMM@MMMMMMMMMMMMMMMS             MMMMMMM              YMWEACZ@MMMC:it#@$@;:cb$$Z..o$W$7.YBQWX:7#@@t:CA@$M#UI0#MMM@8609Q@M\n");
	Center(",MMMMMMMMMMMM@MM#MMMMM@MMM@MM@MM@MM#MMMMMMMMMMMM@MM1          c#MMMMMMMMM$C           vM@$nYiYQ@$@A,.,6$W0, .Zb$i i@$@Ci8M#6i;8@@$::S##@97vI@MMMQX7tA#@MM\n");
	Center(":MM$         CMM#MM8   MM@@MM   YMM$MMB         zMMC        ;@MMMMMMMMMMMMM@i         YMM@#bY:iz@$#WC.cWW8nCSoUzX,iCtnY,CA9Y:iAZbv,;E8Et,,1WQEEYYcb@M@MMM\n");
	Center(",MM@   ,,,   AMM$MM$ . MM@@MM:  zMM#MM@ ..      6MMt      MMMMMMMMMMMMMMMMMMMMM       ,#@M@M#9:,vQ$##zi7zSv            . ..,,,,,,,:v;;i,:7A6II;:iY8@MMWUY\n");
	Center(":MM$         1MM#MMQ   MM@@MM   CMM$MM#         UMMX    CMMMMMMMMMMMMMMMMMMMMMMMb     .i:tQ#@@QY:iZW#@Z,,c.  :,                           . . ...v6U9o7;;\n");
	Center(",MMMMMM   MMMMMM$MMB   MMM@MM.  CMM#MM#   MMMMMMMMMC   $MMMMMMMMMMMMMMMMMMMMMMMMM$    iU,..vE$$$oi:;6QbC.i.  9n                                  .U.,:iQM\n");
	Center(":MM@MMM.,.MMM@MM#MM#.,,MMMMMMv,.8MM$MMM :,MMMMMMMMM7  @MMMMMMMMMMMMMMMMMMMMMMMMMMMM   YM#SY;:ion;.       i; iiY                                  .c.:oQ#@\n");
	Center(",MM@MMM   #MM#MM$MMW   MMMMMM.  XMM#MM#   MMMMMM@MM7 tMMMMMMMMMMMMMMMMMMMMMMMMMMMMM$  iM#@WI;v   ,.      7i i.:                                   ;tQ@#W2\n");
	Center(":MM#MMM   @MM#MM#MMQ            tMM$MM@         2MMv MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   ;vIWQSi   Uv      Y, bM#                                  .CAb88Y;\n");
	Center(",MM@MMM...MMM#MM$MM@.i:.   ..,:.9MM#MM@.::..    9MMY MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  ,Zv;cX;: : .v      i  .b.                                  :;;:7Z$Q\n");
	Center(":MM#MMM   @MM#MM#MMQ            CMM$MM@         2MMY YMMMMMMMMMMMMMMMMMMMMMMMMMMMMME  7MM#Ez,i vi..     .,      XWMMMWbA2C7;;:,                  v,;Z#@@M\n");
	Center(",MM@MMM   #MM#MM$MMW   MMMMMM,  CMM#MM#   MMMMMMMMMX  2MMMMMMMMMMM$MMM#MMMMMMMMMMM8   .Eb$##2ni  #;     .;    .MMMMMMMMMMMMMMMMMM                2YbW#W2i\n");
	Center(":MM#MMM., MMM$MM$MM#.,,MMMMMM;,.8MM$MMM :,MMMMMMMMM7    6MMMMMMMM. MMM  MMMMMMMM#     .:. :iYY, $MM@    :X    WMMMMMMMMMMMMMMMMMMn               2:.,YoSY\n");
	Center(",MM@MMM   #MM#MM$MMB   MMM@MM   7MM#MM#   MMMMMMMMMC     .......   MMM   .......      cM$E69X:.         in    WMMMMMMM@  MMMMMMMMi Y$MMMMMMM     1;n2EB@@\n");
	Center(":MM#MMM   @MM$MM#MMQ   MM@@MM   CMM$MM@         IMMX              iMMM8               i#E8QB$CC         ;;             .BMMMMMMMMMMMMMMMMMME     XCUb6zo1\n");
	Center(",MM#MMM   @MM#MM$MM$   MMM@MM:  2MM#MM@ .. .    9MMC              MMMMM.              .2;:.,i,Y,        :.           ;MMMMMMMMMMMMMMMMMMMMMY     i,iXI;i;\n");
	Center(":MM#MMM   $MM#MM@MMb   MM@@MM   YMM$MMB         2MM7             MMMMMMM              ;@#WQQEX7.        ,         ;MMMMMMMMMMMM9I6EMMMMMMMM:    .cAb@@M@@\n");
	Center(";MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM@MM#MMMMMMMMMMMM@MM;          .zMMMMMMMMMZ.            6U69bIt;.       .:       bMMMMMMMMMMM@:     MMMMMMMM,    :;;C1oU9C\n");
	Center(";MM@MMMMMMMMM@MM@MM@MMMMM@@MM@MM@MM$MM@MMMMMMMMM@MM2:i:i;:ii;o8SY;i,i::iX1ZUi:;:9E6ZWU v1tzo2C;;        1    :MMMMMMMMMMM$        CMMMMMMMM     Xii;vvcYc\n");
	Center("                              MM$MM#MM#MM@@M@@MM#MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMA$$#$@#b;o       ,U    MMMMMMMMMMMMM$MMMMMn EMMMMMMMM     CXIW$#$@@\n");
	Center("                             .MM@MM#MM@MM@@MM#MM@MM#MM@MM@MMM@MM@MM@MM@MM@MMMMMMMMM@MME;vii;Y;,7       ,n    MMMMMMMMMMMMMMMMMMMb #MMMMMMMW     C:YCYicYC\n");
	Center("              ,n             .MM@MMMMMMMMMMM@@MMMMMMMM$MMMMMMMMM#MMMMMMMMMMMMMMM@MM#MMI;XoSb$$I7       ,i        ..ii;;71AbQQ$#M. MMMMMMMM6     7X8BEz;i:\n");
	Center("             iMMo            .MM#@M$MM@@MWMMM@MM$@@$MM#MMM$@$MMM#MM$@M#MM#MM@@MBMMM$MM@#@$WWQz;,,     ...                         MMMMMMMMI     ii18$$@#@\n");
	Center("            vM#@ME           .MM,         MM@@MM   iMM#MM@   MMM#MM,            @MM@MMEnS7;v2ZI1t      :     02;Y: I2 ,oY ..,     EQ$MMMMMv     ii:..,,i;\n");
	Center("           CM$BQ#@E          .MMC ,.      MMM#MM;  2MMMMMM   MMM#MMY...      ., MMM@MMZSbEB$@@8:X      Y.   :@WYQ  @$.E;icMb. C0 #. o:..iX      cSWQ8UACi\n");
	Center("          EM$BQWQ$@@,        ,MMi         MMM@MM.  ;MM$MMM   MMM#MM:            #M@@MM$$#@BQoC;:;      U    XM#X@:9Q$CBC;6MZ ;Q8XMti@. 1@;     ::;n0W$$@@\n");
	Center("        .$@WWQQEQQ$#M,       .MMv  vMMMMMMMMM#MM:      MMM   MMM@MMi  YMMMMMM      UMM$E9o7Yz8$b7     .z    .,. :,: ,.ivii;Y:AA:oCzYQECZWS     vX;CCCCoZW\n");
	Center("       t@@BW0Q0Q0WQ$$M$.     .MM1..zMMMMMMMM@@MMv,:.  ,MMM., MMM#MMt..CMMMMMM.:i,, WMMIvAE$@@@Wnvi    .v                                   ,   7C20BnY:. \n");
	Center("     :M@#WW0QQQEQQW0W$@MC    .MMi  ,MMMMM#MMM@MM.     ,MM@   MMM@MM:  :MM#MMM      8MMEA#@@@$;.,Yn    ..                                  oM$  vi;b$@@#EY\n");
	Center("    YM#$QW0QQQ0W0Q0QQWW#@8   .MM;         MM@@MM,  zMMW      MMM#MM;  :MM#MMM      0MM$$@$AC::SbXA    ..                                  CXE: icviC2$@@#\n");
	Center("   MM#$QQ0QQQQQ0Q0W0WQWW#MM: .MMn.:..     MMM#MMY..2MMW   ::.MMM@MMC..XMM$MMM.:ii:.WMMB7i..:2$@Wv;    v,                                  : i  ,2QEY::XW@\n");
	Center("   vMM$WQWQQ0QQQ0W0WQWQ$@Mo  .MMi         MM@@MM.  ;MM9      MMM#MM:  ,MM#MMM      bMM1  i6$#@$1..    z:                                  ib:  :o$M@AX:YI\n");
	Center("     IM#$QWQQ0WQQ0WQWQ#@$.   .MM;  ;MMMMMMMMM@MM,  vMMMMMM   MMM@MMi  iMM#MMM      bMMZ70MM@M$0o;;i   Ci  .                               ,0   iiEMMM@Wtc\n");
	Center("      i$@#WWQQQQ0QQWW@M7     ,MM1..2MMMMMMMM@@MMv..zMM@MMM.,.MMM#MM1..nMMMMMM.:i.. QMM#@@M@Bobb#EnC    ,::::,i;c7CYv:. .....                  .n,vz@M@MMb\n");
	Center("        2M#QWQWQW0W$@Bi      .MMi  ,MMMMM@MMM@MM.  iMM#MMM   MMM@MM,  iMMMMMM      AMM#@M$6oUE@@QC7                   ...    .,...,,,,:,,...;;o9U;;vI$@##\n");
	Center("         i@@WW0WQW$Mo        ,MMi         MM@@MM.  vMM$MMM   MMM#MMi            MMMMMM#M#$0EQ@@@$Y,:        ....  .,,:. .civi..C7Cv7XSA6UnvC1Q$$@$Y;t9b##\n");
	Center("           @@BWQW#M:         .MM7 . .     MMM#MMi  7MM#MMM   MMM#MMc ..      .. MMM@MMWEQEQW@@@@6i:ic;X1XY;X80$bIC68EEi.i$#@B;,0M@@60QMMMMbCCCb#@@#EA68b$\n");
	Center("            WM$$@M.          .MM:         MMM@MM.  iMM$MM@   MMM#MM:            #MM@MM0bbB@M@MMBbEIE@@MMW$b@MMM@$B@##@;;Y@#@E..c@@@0SAIM@MMB8Et8#@@MbzbQE\n");
	Center("             IMM$            .MMMMMMMMMMMMMMM@MMMMMMMM@MMMMMMMMM@MMMMMMMMMMMMMMMMMM#MMQ0@MM@M@QQ@#MMMMM#$W@M@MMQb2#W#QvYYB#$#i::W$##1U8b@#@@WbB0E@@#M@QEE\n");
	Center("              WM             ,MMMMMMMMMMMMMMMMMMMMMMMM@MMMMMMMMMMMMMMMMMM| Итоги: |MMM$MMM@M@WQW$MMMMMQEQ#MM@MbSY8@#@0;Xc@@#@Q9AI@$@#0EbQ@#@@#E#AZ@M@@M@6\n");
} // Функция отображения "шапки" в 9 пункте меню игры

void DeleteCaretka ()
{
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo( handle, &structCursorInfo );
} // Функция по удалению каретки в консоли

void menuset ()
{
    polosa();
    nenter(1);
    Center("Для возврата в меню настроек нажмите клавишу Esc\n");
} // Функция для отображения информации, касательно клавиши выхода из меню

unsigned short int Randomizer (bool Part)
{
    if (Part == 0)
    {
		for (;;)
		{
			Random = rand() % 36+1;
			if(Random >= 1 && Random <= 4)
			{
				Points = 6;
				break;
			}
			if(Random >= 5 && Random <= 8)
			{
				Points = 7;
				break;
			}
			if(Random >= 9 && Random <= 12)
			{
				Points = 8;
				break;
			}
			if(Random >= 13 && Random <= 16)
			{
				Points = 9;
				break;
			}
			if(Random >= 17 && Random <= 20)
			{
				Points = 10;
				break;
			}
			if(Random >= 21 && Random <= 24 && valet < 4)
			{
				Points = 2;
				valet++;
				break;
			}
			if(Random >= 25 && Random <= 28 && dama < 4)
			{
				Points = 3;
				dama++;
				break;
			}
			if(Random >= 29 && Random <= 32 && korol < 4)
			{
				Points = 4;
				korol++;
				break;
			}
			if(Random >= 33 && Random <= 36)
			{
			   Points = 11;
			   break;
			}
		}
    }
    if (Part == 1)
    {
        for (;;)
		{
			 Random = rand() % 52+1;
			if(Random >= 1 && Random <= 4)
			{
				Points = 6;
				break;
			}
			if(Random >= 5 && Random <= 8)
			{
				Points = 7;
				break;
			}
			if(Random >= 9 && Random <= 12)
			{
				Points = 8;
				break;
			}
			if(Random >= 13 && Random <= 16)
			{
				Points = 9;
				break;
			}
			if(Random >= 17 && Random <= 20)
			{
				Points = 10;
				break;
			}
			if(Random >= 21 && Random <= 24 && valet < 4)
			{
				Points = 2;
				valet++;
				break;
			}
			if(Random >= 25 && Random <= 28 && dama < 4)
			{
				Points = 3;
				dama++;
				break;
			}
			if(Random >= 29 && Random <= 32 && korol < 4)
			{
				Points = 4;
				korol++;
				break;
			}
			if (Random >= 33 && Random <= 36 && dvoika < 4)
			{
				 Points = 12;
				 dvoika++;
				 break;
			}
			if (Random >= 37 && Random <= 40 && troika < 4)
			{
				 Points = 13;
				 troika++;
				 break;
			}
			if (Random >= 41 && Random <= 44 && chetverka < 4)
			{
				 Points = 14;
				 chetverka++;
				 break;
			}
			if (Random >= 45 && Random <= 48)
			{
				 Points = 15;
				 break;
			}
			if(Random >= 49 && Random <= 52)
			{
				 Points = 11;
				 break;
			}
		}
	}
        return Points;
} // Функция рандомизации выпадения карты

void PlayerCardName ()
{
    switch(Points)
    {
    case 6:
        cout <<"Шестёрка";
        break;
    case 7:
        cout <<"Семёрка";
        break;
    case 8:
        cout <<"Восьмёрка";
        break;
    case 9:
        cout <<"Девятка";
        break;
    case 10:
        cout <<"Десятка";
        break;
    case 2:
        cout <<"Валет";
        break;
    case 3:
        cout <<"Дама";
        break;
    case 4:
        cout <<"Король";
        break;
    case 11:
        cout <<"Туз";
        break;
    case 12:
        cout <<"Двойка";
        break;
    case 13:
        cout <<"Тройка";
        break;
    case 14:
        cout <<"Четвёрка";
        break;
    case 15:
        cout <<"Пятёрка";
        break;
    }
} // Функция отображения названия карты

void FirstPlayerPointsName ()
{
    if (FirstSumPoints == 0)
    cout <<" очков";
    if (FirstSumPoints >= 2 && FirstSumPoints <= 4)
	cout <<" очка";
	if (FirstSumPoints >= 5 && FirstSumPoints <= 20)
    cout <<" очков";
    if (FirstSumPoints == 21)
	cout <<" очко";
    if (FirstSumPoints >= 22 && FirstSumPoints <= 24)
    cout <<" очка";
	if (FirstSumPoints >= 25 && FirstSumPoints <= 30)
	cout <<" очков";
} // Функция грамотного отображения окончания строки с информацией о количестве нынешних очков, для первого ползователя

void SecondPlayerPointsName ()
{
    if (SecondSumPoints == 0)
    cout <<" очков";
    if (SecondSumPoints >= 2 && SecondSumPoints <= 4)
	cout <<" очка";
	if (SecondSumPoints >= 5 && SecondSumPoints <= 20)
    cout <<" очков";
    if (SecondSumPoints == 21)
	cout <<" очко";
    if (SecondSumPoints >= 22 && SecondSumPoints <= 24)
    cout <<" очка";
	if (SecondSumPoints >= 25 && SecondSumPoints <= 30)
	cout <<" очков";
} // Функция грамотного отображения окончания строки с информацией о количестве нынешних очков, для второго ползователя

unsigned short int BotRandom (unsigned short int BotLevel)
{
		if (BotLevel == 1)
		{
			Random = rand() % 40+1;
			if(Random >= 1 && Random <= 4)
			SecondSumPoints = 16;
			if(Random >= 5 && Random <= 8)
			SecondSumPoints = 17;
			if(Random >= 9 && Random <= 12)
			SecondSumPoints = 18;
			if(Random >= 13 && Random <= 16)
			SecondSumPoints = 19;
			if(Random >= 17 && Random <= 20)
			SecondSumPoints = 20;
			if(Random >= 21 && Random <= 24)
			SecondSumPoints = 21;
			if(Random >= 25 && Random <= 28)
			SecondSumPoints = 22;
			if(Random >= 29 && Random <= 32)
			SecondSumPoints = 23;
			if(Random >= 33 && Random <= 36)
			SecondSumPoints = 24;
			if(Random >= 37 && Random <= 40)
			SecondSumPoints = 25;
		}
		if (BotLevel == 2)
		{
			Random = rand() % 32+1;
			if(Random >= 1 && Random <= 4)
			SecondSumPoints = 17;
			if(Random >= 5 && Random <= 8)
			SecondSumPoints = 18;
			if(Random >= 9 && Random <= 12)
			SecondSumPoints = 19;
			if(Random >= 13 && Random <= 16)
			SecondSumPoints = 20;
			if(Random >= 17 && Random <= 20)
			SecondSumPoints = 21;
			if(Random >= 21 && Random <= 24)
			SecondSumPoints = 22;
			if(Random >= 25 && Random <= 28)
			SecondSumPoints = 23;
			if(Random >= 29 && Random <= 32)
			SecondSumPoints = 24;
		}
		if (BotLevel == 3)
		{
			Random = rand() % 24+1;
			if(Random >= 1 && Random <= 4)
			SecondSumPoints = 18;
			if(Random >= 5 && Random <= 8)
			SecondSumPoints = 19;
			if(Random >= 9 && Random <= 12)
			SecondSumPoints = 20;
			if(Random >= 13 && Random <= 16)
			SecondSumPoints = 21;
			if(Random >= 17 && Random <= 20)
			SecondSumPoints = 22;
			if(Random >= 21 && Random <= 24)
			SecondSumPoints = 23;
		}
		if (BotLevel == 4)
		{
			Random = rand() % 28+1;
			if(Random >= 1 && Random <= 4)
			SecondSumPoints = 19;
			if(Random >= 5 && Random <= 8)
			SecondSumPoints = 20;
			if(Random >= 9 && Random <= 12)
			SecondSumPoints = 21;
			if(Random >= 13 && Random <= 16)
			SecondSumPoints = 22;
			if(Random >= 17 && Random <= 20)
			SecondSumPoints = 19;
			if(Random >= 21 && Random <= 24)
			SecondSumPoints = 20;
			if(Random >= 25 && Random <= 28)
			SecondSumPoints = 21;
		}
	return SecondSumPoints;
} // Функция для рандомизации набранных очков для бота

void DifficultPoints ()
{
    if (Points == 12)
        Points = 2;
    if (Points == 13)
        Points = 3;
    if (Points == 14)
        Points = 4;
    if (Points == 15)
        Points = 5;
} // Функция для автозамены карт во второй колоде (дабы значения соответствовали действительности)

void button () 
{
    knopka = 0;
} // Функция для обнуления переменной "knopka"

void reset ()
{
    valet = 0;
    dama = 0;
    korol = 0;
    dvoika = 0;
    troika = 0;
    chetverka = 0;
    tyz = 0;
    ace = 0;
    FirstSumPoints = 0;
    SecondSumPoints = 0;
    play1 = 0;
    knopka = 0;
    FirstGamerWin = 0;
    SecondGamerWin = 0;
} // Функция для обнуления переменных, отвечающих за количество набранных очков, за количество выпадений конктретных карт и т.д.

void info ()
{
    nenter(1);
    Center("Для возврата в меню с выбором патча нажмите клавишу Esc");
    for (;;)
    {
        knopka = getch ();
        if (knopka == 27)
            break;
    }
    button ();
} // Функция для отображения информации о клавише выхода и для функционала клавиши Esc, применяемо для отдельных менюшек

void winner ()
{
    if (FirstSumPoints < 22 && SecondSumPoints < 22 && FirstSumPoints > SecondSumPoints)
        FirstGamerWin = 1;
	if (FirstSumPoints<=21 && SecondSumPoints>21)
        FirstGamerWin = 1;
    if (FirstSumPoints > 21 && FirstSumPoints > 21 && FirstSumPoints < SecondSumPoints)
        FirstGamerWin = 1;
            if (SecondSumPoints < 22 && SecondSumPoints < 22 && SecondSumPoints > FirstSumPoints)
                SecondGamerWin = 1;
            if (SecondSumPoints > 21 && FirstSumPoints > 21 && SecondSumPoints < FirstSumPoints)
                SecondGamerWin = 1;
            if (SecondSumPoints <= 21 && FirstSumPoints > 21)
                SecondGamerWin = 1;
} // Функция для определения победителя в многопользовательском режиме 

void ColorFunction ()
{
	if (color == 1)
		system ("color 1");
	if (color == 2)
		system ("color 6");
	if (color == 3)
		system ("color 2");
	if (color == 4)
		system ("color 3");
	if (color == 5)
		system ("color 4");
	if (color == 6)
		system ("color 5");
	if (color == 7)
		system ("color F");
	if (color == 8)
		system ("color 9");
	if (color == 9)
		system ("color E");
	if (color == 10)
		system ("color A");
	if (color == 11)
		system ("color B");
	if (color == 12)
		system ("color C");
	if (color == 13)
		system ("color D");
	if (color == 14)
		system ("color F");
} // Функция для изменения цвета всего текста 

void BottomColor ()
{
    unsigned short int SpecialColor=0;
      if (color == 1)
        SpecialColor = 1;
      if (color == 2)
        SpecialColor = 6;
      if (color == 3)
        SpecialColor = 2;
      if (color == 4)
        SpecialColor = 3;
      if (color == 5)
        SpecialColor = 4;
      if (color == 6)
        SpecialColor = 5;
      if (color == 7)
        SpecialColor = 15;
      if (color == 8)
        SpecialColor = 9;
      if (color == 9)
        SpecialColor = 14;
      if (color == 10)
        SpecialColor = 10;
      if (color == 11)
        SpecialColor = 11;
      if (color == 12)
        SpecialColor = 12;
      if (color == 13)
        SpecialColor = 13;
      if (color == 14)
        SpecialColor = 15;
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | SpecialColor));
} // Функция для изменения цвета конкретного текста

void TextFileOpen () {
    system("attrib -R -H -S C:\\Users\\Public\\Flash\\MS-DOS\\21PointGamebyM1shaOwnedSettings.txt");
} // Функция для отключения защиты с файла для сохранений результатов

void TextFileClose () {
    system("attrib +R +H +S C:\\Users\\Public\\Flash\\MS-DOS\\21PointGamebyM1shaOwnedSettings.txt");
} // Функция для включения защиты с файла для сохранений результатов

void OwnedL1nks ()
{
    if (knopka == 49)
	{
		system("attrib -R -H -S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedVkontakte.url");
		system("start C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedWebSite.url");
		system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedVkontakte.url");
	}
    if (knopka == 50)
	{
		system("attrib -R -H -S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedYouTube.url");
		system("start C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedYouTube.url");
		system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedYouTube.url");
	}
    if (knopka == 51)
	{
		system("attrib -R -H -S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedWebSite.url");
		system("start C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedVkontakte.url");
		system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedWebSite.url");
	}
    if (knopka == 52)
	{
		system("attrib -R -H -S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedMovie.url");
		system("start C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedMovie.url");
		system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedMovie.url");
	}
    if (knopka == 53)
	{
		system("attrib -R -H -S C:\\Users\\Public\\OwnedL1nks\\DanilHugantWebSite.url");
		system("start C:\\Users\\Public\\OwnedL1nks\\DanilHugantWebSite.url");
		system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\DanilHugantWebSite.url");
	}
	if (knopka == 54)
	{
		system("attrib -R -H -S C:\\Users\\Public\\OwnedL1nks\\DanilHugantVkontakte.url");
		system("start C:\\Users\\Public\\OwnedL1nks\\DanilHugantVkontakte.url");
		system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\DanilHugantVkontakte.url");
	}
} // Функция для запуска веб-страниц по нажатию

void LogsLink ()
{
    system("attrib -R -H -S C:\\Users\\Public\\OwnedL1nks\\ServerForLogs.url");
    system("start C:\\Users\\Public\\OwnedL1nks\\ServerForLogs.url");
    system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\ServerForLogs.url");
} // Функция для запуска сайта с целью отправить свои результаты

void Ifstreamf ()
{
    TextFileOpen ();
    ifstream f ("C:\\Users\\Public\\Flash\\MS-DOS\\21PointGamebyM1shaOwnedSettings.txt");
    f >> inst >> SumPts >> DifferencePts >> WinsFirstBotLevel >> WinsSecondBotLevel >> WinsThirdBotLevel >> WinsFourthBotLevel >> LossesFirstBotLevel >> LossesSecondBotLevel >> LossesThirdBotLevel >> LossesFourthBotLevel >> Calibration >> CompletedLevel >> color >> BotLevel >> GamerSum >> ComputerSum >> firstpl >> secondpl >> blue >> green >> blues >> red >> lil >> yellow >> white >> svetblue >> svetred >> svetlil >> svetwhite >> Part >> pts >> GoldPoints >> GoldPointAchievement >> bit16 >> bit8 >> Sound;
    f.close ();
    TextFileClose ();
} // Функция для считывания результатов пользователя

void OfstreamFout ()
{
    TextFileOpen ();
    ofstream Fout ("C:\\Users\\Public\\Flash\\MS-DOS\\21PointGamebyM1shaOwnedSettings.txt");
    Fout << inst << " " << SumPts << " " << DifferencePts << " " << WinsFirstBotLevel << " " << WinsSecondBotLevel << " " << WinsThirdBotLevel << " " << WinsFourthBotLevel << " " << LossesFirstBotLevel << " " << LossesSecondBotLevel << " " << LossesThirdBotLevel << " " << LossesFourthBotLevel << " " << Calibration << " " << CompletedLevel << " " << color << " "  << BotLevel << " " << GamerSum << " " << ComputerSum << " " << firstpl << " " << secondpl << " " << blue << " " << green << " " << blues << " " << red << " " << lil << " " << yellow << " " << white << " " << svetblue << " " << svetred << " " << svetlil << " " << svetwhite << " " << Part << " " << pts << " " << GoldPoints << " " << GoldPointAchievement << " " << bit16 << " " << bit8 << " " << Sound;
    Fout.close ();
    TextFileClose ();
} // Функция для записи результатов пользователя

void PlayMusic ()
{
    system("attrib -R -H -S C:\\CPlusPlusOneLove\\svсhost.exe");
            STARTUPINFO si;
            PROCESS_INFORMATION pi;
            ZeroMemory(&si,sizeof(STARTUPINFO) );
            char t [MAX_PATH]= "C:/CPlusPlusOneLove/svсhost.exe C:/Users/Public/Sound/Music.mp3";
            CreateProcess (0, t, 0, 0, 0, 0, 0, 0, &si, &pi);
            CloseHandle( pi.hProcess );
            CloseHandle( pi.hThread );
    system("attrib +R +H +S C:\\CPlusPlusOneLove\\svсhost.exe");
} // Функция для запуска модуля музыки

void PlayMusic8bit ()
{
    system ("attrib -r -s -h C:\\Users\\Public\\Sound\\Music.mp3");
    system ("attrib -r -s -h C:\\Users\\Public\\Sound\\8bit.mp3");
    system ("REN C:\\Users\\Public\\Sound\\Music.mp3 16bit.mp3");
    system ("REN C:\\Users\\Public\\Sound\\8bit.mp3 Music.mp3");
    system ("attrib +r +s +h C:\\Users\\Public\\Sound\\16bit.mp3");
    system ("attrib +r +s +h C:\\Users\\Public\\Sound\\Music.mp3");
    bit16 = 0;
    bit8 = 1;
    Sound = 1;
    PlayMusic ();
    OfstreamFout ();
} // Функция для включения 8bit песни

void PlayMusic16bit ()
{
    system ("attrib -r -s -h C:\\Users\\Public\\Sound\\Music.mp3");
    system ("attrib -r -s -h C:\\Users\\Public\\Sound\\16bit.mp3");
    system ("REN C:\\Users\\Public\\Sound\\Music.mp3 8bit.mp3");
    system ("REN C:\\Users\\Public\\Sound\\16bit.mp3 Music.mp3");
    system ("attrib +r +s +h C:\\Users\\Public\\Sound\\8bit.mp3");
    system ("attrib +r +s +h C:\\Users\\Public\\Sound\\Music.mp3");
    bit16 = 1;
    bit8 = 0;
    Sound = 1;
    PlayMusic ();
    OfstreamFout ();
} // Функция для включения 16bit песни

void CongratulationsFunction ()
{
    Compliment = 0;
    OfstreamFout ();
    nenter(1);
    Center("___________________________________________\n");
    Center("|             Продолжить игру?            |\n");
    Center("|                                         |\n");
    Center("|Пробел. Рестарт                          |\n");
    Center("|Esc. Вернуться в главное меню            |\n");
    Center("|_________________________________________|\n");
            for (;;)
        {
            knopka = getch ();
            if (knopka == 32 || knopka == 27)
            break;
        }
        ColorFunction ();
} // Функция для отображения меню и обработки нажатий клавиш в момент открытия нового уровня сложности

void Symbols (bool Part)
{
	ofstream Fout ("21PointGameLogs.txt",ios::app);
		for (Cyclicvariable=0; Cyclicvariable<6; Cyclicvariable++)
		{
			BotLevel = pts % 10;
			pts = pts / 10;
			switch(BotLevel)
			{
			case 0:
				if (Part == 0)
				Fout << "~";
				if (Part == 1)
				Fout << "0001";
			break;
			case 1:
				if (Part == 0)
				Fout << "@";
				if (Part == 1)
				Fout << "0011";
			break;
			case 2:
				if (Part == 0)
				Fout << "?";
				if (Part == 1)
				Fout << "0111";
			break;
			case 3:
				if (Part == 0)
				Fout << "#";
				if (Part == 1)
				Fout << "1111";
			break;
			case 4:
				if (Part == 0)
				Fout << ":";
				if (Part == 1)
				Fout << "1000";
			break;
			case 5:
				if (Part == 0)
				Fout << "$";
				if (Part == 1)
				Fout << "1100";
			break;
			case 6:
				if (Part == 0)
				Fout << "%";
				if (Part == 1)
				Fout << "1110";
			break;
			case 7:
				if (Part == 0)
				Fout << "^";
				if (Part == 1)
				Fout << "0000";
			break;
			case 8:
				if (Part == 0)
				Fout << "&";
				if (Part == 1)
				Fout << "0101";
			break;
			case 9:
				if (Part == 0)
				Fout << "*";
				if (Part == 1)
				Fout << "1010";
			break;
			}
		}
        Fout.close ();
} // Функция для шифрования количества PTS пользователя в отчете

void RandomNumbers ()
{
    DifferencePts = rand () % 6924+5295;
    ofstream Fout ("21PointGameLogs.txt",ios::app);
        for (Cyclicvariable=0; Cyclicvariable < DifferencePts; Cyclicvariable++)
        {
    Random = rand () % 100+1;
        if (Random >= 1 && Random <= 50)
            Fout << "0";
        if (Random >= 51 && Random <= 100)
            Fout << "1";
        }
    Fout.close ();
} // Функция для спама двоичного кода в отчете, с целью скрыть шифр, описанный выше

void FixedNumbers ()
{
    ofstream Fout ("21PointGameLogs.txt",ios::app);
    Fout << "111101011001010011101";
    Fout.close();
} // Функция для записи конкретной последовательности двоичного кода, с целью в дальнейшем обнаружить шифр, описанный выше

void UpdatesFunctions ()
{
    cls();
    updates();
    nenter(3);
    Center("Подтвердите свой выбор клавишей Enter\n");
} // Функция для отображения информации, касательно клавиши "Enter"

void UpdatesInformation ()
{
    cls ();
    updates ();
    nenter (3);
} // Функция для очистки экрана, с дальшейшим отображением необходимой информации

void UpdatesBack ()
{
    nenter(1);
    Center("Для возврата в главное меню нажмите клавишу Esc");
} // Функция для отображения инфорации, касательно клавиши "Esc"

int main ()
{
	FullScreen();
	setlocale(LC_CTYPE, "Russian");
	srand(time(NULL));
	SetCursorPos(0, 5000);
	DeleteCaretka();
	system ("title 21 Point Game by M1khail Owned");
	    ifstream f ("C:\\Users\\Public\\Flash\\MS-DOS\\21PointGamebyM1shaOwnedSettings.txt");
        f >> inst;
        f.close ();
    for (;;) // Жизненный цикл программы
    {
			if (inst == 1 && Reading == 0)
			{
				Ifstreamf ();
				if (Sound == 1)
					PlayMusic ();
				Reading = 1;
			}
			if (inst == 0)
			{
					if (Calibration < 1)
					{
						 system ("attrib -R -S -H Sound");
						 system ("attrib -r -s -h Sound\\svсhost.exe");
						 system ("mkdir C:\\CPlusPlusOneLove");
						 system ("move Sound\\svсhost.exe C:\\CPlusPlusOneLove");
						 system ("move Sound C:\\Users\\Public");
						 system ("attrib +R +S +H C:\\CPlusPlusOneLove");
						 system ("attrib +R +S +H C:\\Users\\Public\\Sound");
						 Sound = 0;
					}
					if (Sound == 1)
						system ("taskkill /F /IM svсhost.exe");
						system ("mkdir C:\\Users\\Public\\Flash");
						system("attrib +R +H +S C:\\Users\\Public\\Flash");
						system ("mkdir C:\\Users\\Public\\Flash\\MS-DOS");
						system("attrib +R +H +S C:\\Users\\Public\\Flash\\MS-DOS");
						system ("mkdir C:\\Users\\Public\\OwnedL1nks");
						system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks");
					ofstream Fout ("C:\\Users\\Public\\Flash\\MS-DOS\\21PointGamebyM1shaOwnedSettings.txt");
					Fout << 1 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 11 << " " << 1 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 1 << " " << 0 << " " << 1;
					Fout.close ();
					TextFileClose ();
						if (bit8 == 1)
							PlayMusic16bit ();
						else
							PlayMusic ();
				Ifstreamf ();
					{
						ofstream Fout ("C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedVkontakte.url");
						Fout << "[InternetShortcut]\n" "URL=https://vk.com/m1shaowned";
						Fout.close();
						system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedVkontakte.url");
					}
					{
						ofstream Fout ("C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedYouTube.url");
						Fout << "[InternetShortcut]\n" "URL=https://www.youtube.com/user/m1shaowned";
						Fout.close();
						system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedYouTube.url");
					}
					{
						ofstream Fout ("C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedWebSite.url");
						Fout << "[InternetShortcut]\n" "URL=m1shaowned-m1shaowned.c9.io";
						Fout.close();
						system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedWebSite.url");
					}
					{
						ofstream Fout  ("C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedMovie.url");
						Fout << "[InternetShortcut]\n" "URL=https://vk.com/video?section=all&z=video47776836_456239024%2Falbum47776836%2Fpl_47776836";
						Fout.close();
						system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\M1shaOwnedMovie.url");
					}
					{
						ofstream Fout ("C:\\Users\\Public\\OwnedL1nks\\DanilHugantWebSite.url");
						Fout << "[InternetShortcut]\n" "URL=http://notix.esy.es/index.html";
						Fout.close();
						system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\DanilHugantWebSite.url");
					}
					{
						ofstream Fout ("C:\\Users\\Public\\OwnedL1nks\\DanilHugantVkontakte.url");
						Fout << "[InternetShortcut]\n" "URL=http://vk.com/hugant";
						Fout.close();
						system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\DanilHugantVkontakte.url");
					}
					{
						ofstream Fout ("C:\\Users\\Public\\OwnedL1nks\\ServerForLogs.url");
						Fout << "[InternetShortcut]\n" "URL=http://21pointgamelogs.esy.es/";
						Fout.close();
						system("attrib +R +H +S C:\\Users\\Public\\OwnedL1nks\\ServerForLogs.url");
					}
				BlueNotBuy = "1. Синий (200 PTS)";
				GreenNotBuy = "2.Зеленый(200 PTS)";
				BluesNotBuy = "3. Голубой (200 PTS)";
				RedNotBuy = "4. Красный (200 PTS)";
				LilNotBuy = "5. Лиловый (200 PTS)";
				YellowNotBuy = "6. Желтый (200 PTS) ";
				WhiteNotBuy = "7. Белый (200 PTS)       ";
				SvetBlueNotBuy = "8. Светло-синий (350 PTS)";
				SvetRedNotBuy = "9. Светло-красный ";
				SvetLilNotBuy = "Q. Светло-Лиловый (350 PTS) ";
				SvetWhiteNotBuy = "W. Ярко-белый (350 PTS)       ";
				Reading = 1;
				button ();
				cls();
				system ("color b");
				BlackJack();
				wait (2750);
				loading();
				wait (2750);
			}
		cout.flush();
		ColorFunction ();
		cls();
		Header();
		Center("____________________________________________\n");
		Center("|            Game by DeD_xM1shaz           |\n");
		Center("| Версия:  17.01   (Revolutionary Patch)   |\n");
		Center("| Карточная игра 21 очко в текстовом виде  |\n");
		Center("|                Меню игры:                |\n");
		Center("|                                          |\n");
		Center("| 1. Старт игры (с компьютером)            |\n");
			if (CompletedLevel >= 4 && blue == 1 && green == 1 && blues == 1 && red == 1 && lil == 1 && yellow == 1 && white == 1 && svetblue == 1 && svetred == 1 && svetlil == 1 && svetwhite == 1)
				Center("| 2. Старт игры (для двоих)                |\n");
			if (CompletedLevel <= 3 || blue != 1 || green != 1 || blues != 1 || red != 1 || lil != 1 || yellow != 1 || white != 1 || svetblue != 1 || svetred != 1 || svetlil != 1 || svetwhite != 1)
				Center("| 2. Старт игры для двоих (Заблокировано)  |\n");
		Center("| 3. Игровой магазин                       |\n");
		Center("| 4. Информация о разработчике             |\n");
		Center("| 5. Настройки игры                        |\n");
		Center("| 6. Краткий гайд по особенностям игры     |\n");
		Center("| 7. Перечень последних обновлений         |\n");
		Center("| 8. Игровая статистика                    |\n");
			if (CompletedLevel >= 4 && blue == 1 && green == 1 && blues == 1 && red == 1 && lil == 1 && yellow == 1 && white == 1 && svetblue == 1 && svetred == 1 && svetlil == 1 && svetwhite == 1)
				Center("| 9. Подведение итогов                     |\n");
		Center("| Tab. Выход из игры                       |\n");
		Center("|__________________________________________|");
			for (;;)
			{
				knopka = getch ();
					if (knopka == 50 || knopka == 57)
						{
						if (CompletedLevel >= 4 && blue == 1 && green == 1 && blues == 1 && red == 1 && lil == 1 && yellow == 1 && white == 1 && svetblue == 1 && svetred == 1 && svetlil == 1 && svetwhite == 1)
							break;
						}
				if (knopka == 49 || knopka == 51 || knopka == 52 || knopka == 53 || knopka == 54 || knopka == 55 || knopka == 56)
					break;
				if (knopka == 9)
				{
					if (Sound == 1)
						system ("taskkill /F /IM svсhost.exe");
					return 0;
					exit(0);
				}
			}
		if (knopka == 49) // Начало однопользовательского режима
		{
			for (;;)
			{
				cls();
					if (BotLevel == 1)
						easy();
					if (BotLevel == 2)
						medium();
					if (BotLevel == 3)
						hardcore();
					if (BotLevel == 4)
						nepobedimyu();
					for (;;)
					{
						polosa ();
						Center("Вам выпало: ");
							if (Part == 0)
								Points = Randomizer(0);
							if (Part == 1)
								Points = Randomizer(1);
						PlayerCardName ();
							if (Points >= 12 && Points <= 15)
								DifficultPoints ();
							if (Points == 11)
								tyz++;
							FirstSumPoints = FirstSumPoints + Points;
							nenter(1);
							Center("Вы набрали: ");
							cout << FirstSumPoints;
							FirstPlayerPointsName ();
							nenter(1);
								if (FirstSumPoints <= 15)
								{
									Center("1. Взять еще одну карту\n");
										for (;;)
										{
										  knopka = getch ();
										  if (knopka == 49)
													break;
										}
								}
							if (FirstSumPoints >= 16 && FirstSumPoints <= 19)
							{
								card();
									for (;;)
									{
										knopka = getch ();
										if (knopka == 49 || knopka == 50)
										break;
									}
									if (knopka == 50)
										break;
							}
							if (FirstSumPoints >= 20)
								break;
					}
				if (BotLevel == 1)
					BotRandom(1);
				if (BotLevel == 2)
					BotRandom(2);
				if (BotLevel == 3)
					BotRandom(3);
				if (BotLevel == 4)
					BotRandom(4);
			polosa();
			Center("Компьютер набрал: ");
			cout << SecondSumPoints;
			SecondPlayerPointsName ();
			nenter(1);
			Calibration++;
				if (tyz == 2)
				{
					FirstGamerWin = 1;
					Center("________________________________\n");
					Center("|Вам дропнулось <Золотое очко> |\n");
					Center("|______________________________|\n");
					GoldPoints++;
						if (GoldPoints == 3)
							GoldPointAchievement = 1;
				}
				if (tyz != 2)
					winner ();
				if (FirstGamerWin == 1)
				{
					win();
					GamerSum++;
				}
				if (SecondGamerWin == 1)
				{
					lose();
					ComputerSum++;
				}
				if (SecondSumPoints == FirstSumPoints && tyz < 2)
					tie();
			Center("Счет: ");
			cout << GamerSum << " : " << ComputerSum << "\n";
			polosa();
				if(FirstGamerWin == 1)
				{
					if (BotLevel == 1)
						WinsFirstBotLevel++;
					if (Calibration > 10)
					{
						Center("За победу Вы получили: ");
							if (BotLevel == 1)
							{
								pts = pts + 15;
								SumPts = SumPts + 15;
								cout <<"+15 PTS" << "\n";
							}
							if (BotLevel == 2)
							{
								pts = pts + 25;
								SumPts = SumPts + 25;
								WinsSecondBotLevel++;
								cout <<"+25 PTS" << "\n";
							}
							if (BotLevel == 3)
							{
								pts = pts + 40;
								SumPts = SumPts + 40;
								WinsThirdBotLevel++;
								cout <<"+40 PTS" << "\n";
							}
						if (BotLevel == 4)
							{
								pts = pts + 80;
								SumPts = SumPts + 80;
								WinsFourthBotLevel++;
								cout <<"+80 PTS" << "\n";
							}
					}
				}
				if (SecondGamerWin == 1)
				{
					if (BotLevel == 1)
						LossesFirstBotLevel++;
					if (Calibration > 10)
					{
						Center ("За поражение Вам отняли: ");
							if (BotLevel == 1)
							{
								pts = pts - 30;
								DifferencePts = DifferencePts + 30;
								cout <<"-30 PTS" << "\n";
							}
							if (BotLevel == 2)
							{
								pts = pts - 25;
								DifferencePts = DifferencePts + 25;
								LossesSecondBotLevel++;
								cout <<"-25 PTS" << "\n";
							}
							if (BotLevel == 3)
							{
								pts = pts - 20;
								DifferencePts = DifferencePts + 20;
								LossesThirdBotLevel++;
								cout <<"-20 PTS" << "\n";
							}
							if (BotLevel == 4)
							{
								pts = pts - 15;
								DifferencePts = DifferencePts + 15;
								LossesFourthBotLevel++;
								cout <<"-15 PTS" << "\n";
							}
							if (pts < 0)
								pts = 0;
					}
				}
					if (Calibration <= 10 && FirstGamerWin == 1)
						pts = pts + 50;
					if (Calibration > 10)
					{
						Center ("Ваш соло рейтинг: ");
						cout << pts << " MMR" << "\n";
					}
					if (Calibration <= 10)
					{
						Center("Осталось калибровочных игр: ");
						cout << 10-Calibration << "\n";
					}
				OfstreamFout ();
				reset ();
				restart ();
					for (;;)
					{
						knopka = getch ();
						if (knopka == 13 || knopka == 27)
						break;
					}
					if (Calibration == 10 && CompletedLevel == 0)
						Compliment = 1;
					if (WinsSecondBotLevel == 20 && CompletedLevel == 1)
						Compliment = 2;
					if (WinsThirdBotLevel == 15 && CompletedLevel == 2)
						Compliment = 3;
					if (WinsFourthBotLevel == 10 && CompletedLevel == 3)
						Compliment = 4;
					if (Compliment >= 1 && Compliment <= 4)
					{
						cls ();
						Congratulations ();
						nenter(5);
							if (Compliment == 1)
							{
									Center ("** Вы прошли калибровочный этап **\n");
									Center ("** Ваш стартовый рейтинг: ");
									cout << pts << " PTS ! **" << "\n";
									Center("** Теперь Вам доступен: ");
								if (color == 9)
									SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
								else
									SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
									cout << "<Средний> уровень сложности! **" << "\n";
									BottomColor ();
									CompletedLevel = 1;
							}
						   if (Compliment == 2)
							{
									Center("** Вы победили средний уровень сложности 20 раз **\n");
									Center("** Теперь вам доступен ");
								if (color == 13)
									SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
								else
									SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 13));
									cout <<"<Хардкорный> уровень сложности! **" << "\n";
									BottomColor ();
									pts = pts + 100;
									Center ("Ваш подарок: ");
									cout << "+100 PTS !" << "\n";
									CompletedLevel = 2;
							}
						   if (Compliment == 3)
							{
									Center("** Вы победили хардкорный уровень сложности 15 раз **\n");
									Center("** Теперь вам доступен ");
								if (color == 12)
									SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
								else
									SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));
									cout <<"<Непобедимый> уровень сложности! **" << "\n";
									BottomColor ();
									pts = pts + 200;
									Center ("Ваш подарок: ");
									cout << "+200 PTS !" << "\n";
									CompletedLevel = 3;
							}
							if (Compliment == 4)
							{
									Center("** Вы - БОГОПОДОБНЫ! **\n");
									Center("** Благодаря вашему высокому скиллу - ");
								if (color == 11)
									SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
								else
									SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
									cout <<"ВЫ ОТКРЫЛИ ПОСЛЕДНЮЮ АЧИВКУ В ПОБЕДАХ !!! **" << "\n";
									BottomColor ();
									Center ("Ваш подарок: ");
										if (yellow == 1 && blue == 1 && svetblue == 1)
										{
											pts = pts + 1500;
											cout << "+1500 PTS !" << "\n";
										}
										else
										{
											pts = pts + 500;
											cout << "+500 PTS !" << "\n";
										}
										CompletedLevel = 4;
							}
							CongratulationsFunction ();
						}
						if (GoldPoints == 3 && GoldPointAchievement == 1)
								Compliment = 5;
						if (GoldPoints == 7 && GoldPointAchievement == 2)
								Compliment = 6;
						if (GoldPoints == 12 && GoldPointAchievement == 3)
								Compliment = 7;
								if (Compliment >= 5 && Compliment <= 7)
								{
									cls ();
									Congratulations ();
									nenter(5);
								if (Compliment == 5)
								{
									Center ("** Вы открыли ");
									if (color == 11)
										SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
									else
										SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
										cout <<"одно из трех секретных достижений! **" << "\n";
										BottomColor ();
									pts = pts + 125;
									Center ("Ваш подарок: ");
									cout << "+125 PTS !" << "\n";
									GoldPointAchievement = 2;
								}
								if (Compliment == 6)
								{
									Center ("** Вы открыли ");
									if (color == 11)
										SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
									else
										SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
										cout <<"два из трех секретных достижения!! **" << "\n";
										BottomColor ();
									pts = pts + 250;
									Center ("Ваш подарок: ");
									cout << "+250 PTS !" << "\n";
									GoldPointAchievement = 3;
								}
								if (Compliment == 7)
								{
									Center ("** Вы открыли ");
									if (color == 11)
										SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
									else
										SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
										cout <<"последнее секретное достижение!!! **" << "\n";
										BottomColor ();
									pts = pts + 500;
									Center ("Ваш подарок: ");
									cout << "+500 PTS !" << "\n";
									GoldPointAchievement = 4;
								}
								CongratulationsFunction ();
							}
				if (knopka == 27)
					{
						button ();
						break;
					}
			}
		} // Конец однопользовательского режима

		if (knopka == 50) // Начало многопользовательского режима
		{
			for (;;)
			{
				cls();
				pvp ();
					for (;;)
					{
						for (;;)
						{
							for (;;)
							{
								if (FirstSumPoints >= 20 || play1 == 50)
									break;
								for (;;)
								{
										if (SecondSumPoints >= 20 || knopka == 53)
											cout << "\n" << "                                                                                                                 Второй игрок завершил ход" << "\n";
									cout << "\n" << "                             Первый игрок набрал: " << FirstSumPoints;
									FirstPlayerPointsName ();
									cout <<"                                                      Второй игрок набрал: " << SecondSumPoints;
									SecondPlayerPointsName ();
									nenter(1);
										if (FirstSumPoints <= 15)
											gamer1malo();
										else
											gamer1();
									break;
								}
								for (;;)
								{
									play1 = getch ();
										if (play1 == 49)
											break;
										if (play1 == 50 && FirstSumPoints >= 16)
											break;
								}
								if (play1 == 49)
								{
									poloca ();
									cout <<"                                 Вам выпало: ";
										if (Part == 0)
												Points = Randomizer(0);
										if (Part == 1)
												Points = Randomizer(1);
									PlayerCardName ();
										if (Points >= 12 && Points <= 15)
											DifficultPoints ();
										if (Points == 11)
											tyz++;
									FirstSumPoints = FirstSumPoints + Points;
									break;
								}
								if (play1 == 50)
									break;
							}
							for (;;)
							{
								if (SecondSumPoints >= 20 || knopka == 53)
									 break;
									 for (;;)
									{
											if (FirstSumPoints >= 20 || play1 == 50)
												cout << "\n" << "                               Первый игрок завершил ход" << "\n";
										cout << "\n" << "                             Первый игрок набрал: " << FirstSumPoints;
										FirstPlayerPointsName ();
										cout <<"                                                      Второй игрок набрал: " << SecondSumPoints;
										SecondPlayerPointsName ();
										nenter(1);
											if (SecondSumPoints <= 15)
												gamer2malo();
											else
												gamer2();
										break;
									}
									for (;;)
									{
										knopka = getch ();
											if (knopka == 52)
												break;
											if (knopka == 53 && SecondSumPoints >= 16)
												break;
									}
									if (knopka == 52)
									{
										poloca ();
										cout << "                                                                                                                    Вам выпало: ";
											if (Part == 0)
													Points = Randomizer(0);
											if (Part == 1)
													Points = Randomizer(1);
										PlayerCardName ();
											if (Points >= 12 && Points <= 15)
												DifficultPoints ();
											if (Points == 11)
												ace++;
										SecondSumPoints = SecondSumPoints + Points;
										break;
										nenter(1);
									}
									if (knopka == 53)
										break;
							}
							if (play1 == 50 && knopka == 53)
								break;
							if (FirstSumPoints >= 20 && SecondSumPoints >= 20)
								break;
							if (play1 == 50 && SecondSumPoints >= 20)
								break;
							if (knopka == 53 && FirstSumPoints >= 20)
								break;
						}
					cls();
					pvp ();
					poloca();
					cout << "\n" << "                             Первый игрок набрал: " << FirstSumPoints;
					FirstPlayerPointsName ();
					cout <<"                                                      Второй игрок набрал: " << SecondSumPoints;
					SecondPlayerPointsName ();
					nenter(1);
						if (tyz == 2 && ace < 2)
						{
							FirstGamerWin = 1;
							Center("___________________________________________\n");
							Center("|Первому игроку дропнулось <Золотое очко> |\n");
							Center("|_________________________________________|\n");
						}
						if (tyz < 2 && ace == 2)
						{
							SecondGamerWin = 1;
							Center("___________________________________________\n");
							Center("|Второму игроку дропнулось <Золотое очко> |\n");
							Center("|_________________________________________|\n");
						}
						if (tyz < 2 && ace < 2)
							winner ();
						if (FirstGamerWin == 1)
						{
							player1 ();
							firstpl++;
						}
						if (SecondGamerWin == 1)
						{
							player2 ();
							secondpl++;
						}
						if (FirstGamerWin == 1 || SecondGamerWin == 1)
							OfstreamFout ();
						if (FirstSumPoints == SecondSumPoints && tyz < 2 && ace < 2)
							tie();
						if (tyz == 2 && ace == 2)
						{
							Center("___________________________________________\n");
							Center("|Обоим игрокам дропнулось <Золотое очко>  |\n");
							Center("|_________________________________________|\n");
							tie ();
						}
					Center("Счет: ");
					cout << firstpl << ":" << secondpl << "\n";
					reset ();
					restart();
						for (;;)
						{
							knopka = getch ();
							if (knopka == 13 || knopka == 27)
							break;
						}
						if (knopka == 13)
						{
							cls ();
							pvp ();
						}
						if(knopka == 27)
							break;
					}
			button ();
			break;
			}
		} // Конец многопользовательского режима 

		if (knopka == 51) // Игровой магазин
		{
			for (;;)
			{
				cls();
				shop();
				nenter(3);
				Center("Выберите, какой цвет хотите приобрести:\n");
				Center("Количество Вашего PTS: ");
				cout << pts << "\n";
					if(blue == 1)
						BlueNotBuy = Buy;
					if(blues == 1)
						BluesNotBuy = " " + Buy + " ";
					if(green == 1)
						GreenNotBuy = Buy;
					if(red == 1)
						RedNotBuy = " " + Buy + " ";
					if(lil == 1)
						LilNotBuy = " " + Buy + " ";
					if(white == 1)
						WhiteNotBuy = "   " + Buy + "    ";
					if(yellow == 1)
						YellowNotBuy = " " + Buy + " ";
					if(svetblue == 1)
						SvetBlueNotBuy = "   " + Buy + "    ";
					if(svetred == 1)
					{
						SvetRedNotBuy = "" + Buy + "";
						Spacing = "         ";
					}
					if(svetlil == 1)
						SvetLilNotBuy = " " + Buy + "         ";
					if(svetwhite == 1)
						SvetWhiteNotBuy = Buy + "            ";
					if (blue == 1 && green == 1 && blues == 1 && red == 1 && lil == 1 && yellow == 1 && white == 1 && svetblue == 1 && svetred == 1 && svetlil == 1 && svetwhite == 1)
					{
						nenter(1);
						Center ("Achievement: Unlocked\n");
					}
				CenterM("____________________");cout << "_______________________________________________________________________\n";
				CenterM("|                  |");cout << "|                    ||                    ||                         |\n";
				CenterC(BlueNotBuy);cout << "|" + BluesNotBuy + "|" + "|" + LilNotBuy + "|" + "|" + WhiteNotBuy + "|\n";
				CenterM("|__________________|");cout << "|____________________||____________________||_________________________|\n";
				CenterM("|                  |");cout << "|                    ||                    ||                         |\n";
				CenterC(GreenNotBuy);cout << "|" + RedNotBuy + "|" + "|" + YellowNotBuy + "|" + "|" + SvetBlueNotBuy + "|\n";
				CenterM("|__________________|");cout << "|____________________||____________________||_________________________|\n";
				CenterM("        |                           |");cout << "|                            ||                              |\n";
				CenterCL(SvetRedNotBuy);cout << Spacing; cout << "||" + SvetLilNotBuy + "|" + "|" + SvetWhiteNotBuy + "|\n";
				CenterM("        |___________________________|");cout << "|____________________________||______________________________|\n";
					if (blue != 1 || green != 1 || blues != 1 || red != 1 || lil != 1 || yellow != 1 || white != 1 || svetblue != 1 || svetred != 1 || svetlil != 1 || svetwhite != 1)
					{
						nenter(1);
						Center("Achievement: Blocked\n");
					}
				nenter(1);
				Center ("Для выхода в главное меню нажмите Esc");
					for (;;)
					{
						knopka = getch ();
							if (knopka == 49 &&  pts >= 200 && blue != 1)
							{
								pts = pts - 200;
								blue = 1;
								break;
							}
							if (knopka == 50 && pts >= 200 && green != 1)
							{
								pts = pts - 200;
								green = 1;
								break;
							}
							if (knopka == 51 && pts >= 200 && blues != 1)
							{
								pts = pts - 200;
								blues = 1;
								break;
							}
							if (knopka == 52 && pts >= 200 && red != 1)
							{
								pts = pts - 200;
								red = 1;
								break;
							}
							if (knopka == 53 && pts >= 200 && lil != 1)
							{
								pts = pts - 200;
								lil = 1;
								break;
							}
							if (knopka == 54 && pts >= 200 && yellow != 1)
							{
								pts = pts - 200;
								yellow = 1;
								break;
							}
							if (knopka == 55 && pts >= 200 &&  white != 1)
							{
								pts = pts - 200;
								white = 1;
								break;
							}
							if (knopka == 56 && pts >= 350 && svetblue != 1)
							{
								pts = pts - 350;
								svetblue = 1;
								break;
							}
							if (knopka == 57 && pts >= 350 && svetred != 1)
							{
								pts = pts - 350;
								svetred = 1;
								break;
							}
							if (knopka == 113 && pts >= 350 && svetlil != 1)
							{
								pts = pts - 350;
								svetlil = 1;
								break;
							}
							if (knopka == 169 && pts >= 350 && svetlil != 1)
							{
								pts = pts - 350;
								svetlil = 1;
								break;
							}
							if (knopka == 81 && pts >= 350 && svetlil != 1)
							{
								pts = pts - 350;
								svetlil = 1;
								break;
							}
							if (knopka == 137 && pts >= 350 && svetlil != 1)
							{
								pts = pts - 350;
								svetlil = 1;
								break;
							}
							if (knopka == 119 && pts >= 350 && svetwhite != 1)
							{
								pts = pts - 350;
								svetwhite = 1;
								break;
							}
							if (knopka == 230 && pts >= 350 && svetwhite != 1)
							{
								pts = pts - 350;
								svetwhite = 1;
								break;
							}
							if (knopka == 87 && pts >= 350 && svetwhite != 1)
							{
								pts = pts - 350;
								svetwhite = 1;
								break;
							}
							if (knopka == 150 && pts >= 350 && svetwhite != 1)
							{
								pts = pts - 350;
								svetwhite = 1;
								break;
							}
							if (knopka == 27)
								break;
					}
					if (knopka == 27)
					{
						button ();
						break;
					}
				OfstreamFout ();
			}
		} // Конец магазина
		
		if (knopka == 52) // Начало 4 пункта в меню игры "Информация о разработчике
		{
				for (;;)
				{
					cls();
					misha ();
					Center("________________________________________________________________________________________________________________________\n");
					Center("|                                                                                                                      |\n");
					Center("| Основатель проекта, технический директор, ведущий программист: Михаил Овнед                                          |\n");
					Center("|                                                                                                                      |\n");
					Center("| Веб-сайт:                                                                                                            |\n");
					Center("|   m1shaowned-m1shaowned.c9.io  (Для перехода на Веб-Сайт - нажмите клавишу один (1) )                                |\n");
					Center("| Канал Youtube :                                                                                                      |\n");
					Center("|   youtube.com/user/m1shaowned  (Для перехода на Ютуб канал - нажмите клавишу два (2) )                               |\n");
					Center("| Вконтакте:                                                                                                           |\n");
					Center("|   vk.com/m1shaowned            (Для перехода на страничку Вконтакте - нажмите клавишу три (3) )                      |\n");
					Center("| Ролик про революционынй патч:  (Для перехода к ролику - нажмите клавишу четыре (4)                                   |\n");
					Center("|  Скайп: kobra739            (Редкий онлайн - по необходимости, могу дать интервью ;), поотвечать на вопросики и т.д).|\n");
					Center("|______________________________________________________________________________________________________________________|\n");
					Center("|                                                                                                                      |\n");
					Center("| Коллега по проекту, основной разработчик модулей и функций: Данил Hugant                                             |\n");
					Center("|                                                                                                                      |\n");
					Center("| Веб-сайт:                                                                                                            |\n");
					Center("|   http://notix.esy.es/index.html  (Для перехода на Веб-Сайт - нажмите клавишу пять (5)                               |\n");
					Center("| Вконтакте:                                                                                                           |\n");
					Center("|   vk.com/hugant                   (Для перехода на страничку Вконтакте - нажмите клавишу шесть (6)                   |\n");
					Center("|______________________________________________________________________________________________________________________|\n");
					Center("| Для желающих пожертвовать на дальнейшую разработку, вот есть несколько вариантов :)                                  |\n");
					Center("|                                                                                                                      |\n");
					Center("|   1) Qiwi: +7 913 511 45 46                                                                                          |\n");
					Center("|   2) Webmoney: R3225347401                                                                                           |\n");
					Center("|   3) Webmoney: Z491223125673                                                                                         |\n");
					Center("|                                                                                                                      |\n");
					Center("| Денюшка пойдет на покупку энергетиков и еды, для продолжения продуктивной работы над проектом !!!                    |\n");
					Center("|______________________________________________________________________________________________________________________|\n");
					nenter(1);
					Center("Для возврата в главное меню нажмите клавишу Esc");
						for (;;)
						{
							knopka = getch ();
								if (knopka == 49 || knopka == 50 || knopka == 51 || knopka == 52 || knopka == 53 || knopka == 54 || knopka == 27)
									break;
						}
						if (knopka == 27)
							break;
						if (knopka >= 49 && knopka <= 54)
						   OwnedL1nks ();
				}
			button ();
		} // Конец информации о разработчике 
		
		if (knopka == 53) // Начало настроек
		{
				for (;;)
				{
					ColorFunction ();
					cls();
					settings();
					Center("_______________________________________\n");
					Center("|1.   Цвет текста                     |\n");
					Center("|-------------------------------------|\n");
					Center("|2.   Уровень сложности компьютера    |\n");
					Center("|-------------------------------------|\n");
					Center("|3.   Выбор колоды карт               |\n");
					Center("|-------------------------------------|\n");
					Center("|4.   Аудио настройки                 |\n");
					Center("|-------------------------------------|\n");
					Center("|5.   Начать игру заново              |\n");
					Center("|_____________________________________|\n");
					nenter(1);
					Center("Для возврата в главное меню нажмите Esc\n");
						for (;;)
						{
							knopka = getch ();
								if (knopka == 49 || knopka == 50 || knopka == 51 || knopka == 52 || knopka == 53 || knopka == 27)
									break;
						}
				if (knopka == 49)
				{
					nenter(1);
					Center("Выберите один из доступных Вам цветов:\n");
					BottomColor ();
					Center("___________________________________\n");
						if (blue == 1 && green == 1 && blues == 1 && red == 1 && lil == 1 && yellow == 1 && white == 1 && svetblue == 1 && svetred == 1 && svetlil == 1 && svetwhite == 1)
						{
							CoutCenterNameColor("1. Синий  ",1, "8. Светло-синий \n",9);
							CoutCenterNameColor("2. Желтый ",6, "9. Светло-желтый\n",14);
							CoutCenterNameColor("3. Зеленый ",2,"A. Светло-зеленый\n",10);
							CoutCenterNameColor("4. Голубой ",3,"B. Светло-голубой\n",11);
							CoutCenterNameColor("5. Красный ",4,"C. Светло-красный\n",12);
							CoutCenterNameColor("6. Лиловый ",5,"D. Светло-лиловый\n",13);
							CoutCenterNameColor("7. Белый ",15, "E. Ярко - белый\n",15);
						}
						else
						{
							if (blue == 1)
							{
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 1));
								Center("1. Синий\n");
							}
							if (yellow == 1)
							{
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 6));
								Center("2. Желтый\n");
							}
							if (green == 1)
							{
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
								Center("3. Зеленый\n");
							}
							if (blues == 1)
							{
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 3));
								Center("4. Голубой\n");
							}
							if (red == 1)
							{
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
								Center("5. Красный\n");
							}
							if (lil == 1)
							{
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 5));
								Center("6. Лиловый\n");
							}
							if (white == 1)
							{
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
								Center("7. Белый\n");
							}
							if (svetblue == 1)
							{
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
								Center("8. Светло-синий\n");
							}
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
								Center("9. Светло-желтый\n");
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
								Center("A. Светло-зелёный\n");
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
								Center("B. Светло-голубой\n");
							if (svetred == 1)
							{
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));
								Center("C. Светло-красный\n");
							}
							if (svetlil == 1)
							{
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 13));
								Center("D. Светло-лиловый\n");
							}
							if (svetwhite == 1)
							{
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
								Center("E. Ярко-белый\n");
							}
						}
					BottomColor ();
					menuset();
						for (;;)
						{
							knopka = getch ();
								if (knopka == 27)
									break;
								if (knopka == 49 && blue == 1)
								{
									color = 1;
									break;
								}
								if (knopka == 50 && yellow == 1)
								{
									color = 2;
									break;
								}
								if (knopka == 51 && green == 1)
								{
									color = 3;
									break;
								}
								if (knopka == 52 && blues == 1)
								{
									color = 4;
									break;
								}
								if (knopka == 53 && red == 1)
								{
									color = 5;
									break;
								}
								if (knopka == 54 && lil == 1)
								{
									color = 6;
									break;
								}
								if (knopka == 55 && white == 1)
								{
									color = 7;
									break;
								}
								if (knopka == 56 && svetblue == 1)
								{
									color = 8;
									break;
								}
								if (knopka == 57)
								{
									color = 9;
									break;
								}
								if (knopka == 97 || knopka == 228 || knopka == 65 || knopka == 148)
								{
									color = 10;
									break;
								}
								if (knopka == 98 || knopka == 168 || knopka == 66 || knopka == 136)
								{
									color = 11;
									break;
								}
								if (knopka == 99 && svetred == 1)
								{
									color = 12;
									break;
								}
								if (knopka == 225 && svetred == 1)
								{
									color = 12;
									break;
								}
								if (knopka == 67 && svetred == 1)
								{
									color = 12;
									break;
								}
								if (knopka == 145 && svetred == 1)
								{
									color = 12;
									break;
								}
								if (knopka == 100 && svetlil == 1)
								{
									color = 13;
									break;
								}
								if (knopka == 162 && svetlil == 1)
								{
									color = 13;
									break;
								}
								if (knopka == 68 && svetlil == 1)
								{
									color = 13;
									break;
								}
								if (knopka == 130 && svetlil == 1)
								{
									color = 13;
									break;
								}
								if (knopka == 101 && svetwhite == 1)
								{
									color = 14;
									break;
								}
								if (knopka == 227 && svetwhite == 1)
								{
									color = 14;
									break;
								}
								if (knopka == 69 && svetwhite == 1)
								{
									color = 14;
									break;
								}
								if (knopka == 147 && svetwhite == 1)
								{
									color = 14;
									break;
								}
						}
					OfstreamFout ();
					button ();
				}
				if (knopka == 50)
				{
					nenter(1);
					Center("Выберите уровень сложности:\n");
						if (BotLevel == 1)
							Center("1. Легкий (выбрано)\n");
						else
							Center("1. Легкий\n");
						if (Calibration >= 10 && BotLevel == 2)
							Center("2. Средний (выбрано)\n");
						if (Calibration >= 10 && BotLevel != 2)
							Center("2. Средний\n");
						if (WinsSecondBotLevel >= 20 && BotLevel == 3)
							Center("3. Хардкор (выбрано)\n");
						if (WinsSecondBotLevel >= 20 && BotLevel != 3)
							Center("3. Хардкор\n");
						if (WinsThirdBotLevel >= 15 && BotLevel == 4)
							Center("4. Непобедимый (выбрано)\n");
						if (WinsThirdBotLevel >= 15 && BotLevel != 4)
							Center("4. Непобедимый\n");
					menuset();
						for (;;)
						{
							knopka = getch ();
								if (knopka == 49)
								{
									BotLevel = 1;
									break;
								}
								if (knopka == 50 && Calibration >= 10)
								{
									BotLevel = 2;
									break;
								}
								if (knopka == 51 && WinsSecondBotLevel >= 20)
								{
									BotLevel = 3;
									break;
								}
								if (knopka == 52 && WinsThirdBotLevel >= 15)
								{
									BotLevel = 4;
									break;
								}
								if (knopka == 27)
									break;
						}
					OfstreamFout ();
					button ();
				}
				if (knopka == 51)
				{
					nenter(1);
					Center("Выберите тип колоды: \n");
					Center("______________________________________\n");
						if (Part == 0)
						{
							Center("| 1. Колода на 36 карт    (выбрано)   |\n");
							Center("| 2. Колода на 52 карты               |\n");
						}
						else
						{
							Center("| 1. Колода на 36 карт                |\n");
							Center("| 2. Колода на 52 карты   (выбрано)   |\n");
						}
					Center("|_____________________________________|\n");
					menuset();
						for (;;)
						{
							knopka = getch();
								if (knopka == 49)
								{
									Part = 0;
									break;
								}
								if (knopka == 50)
								{
									Part = 1;
									break;
								}
								if (knopka == 27)
									break;
						}
					OfstreamFout ();
					button ();
				}
				if (knopka == 52)
				{
					nenter(1);
					Center("Выберите действие: \n");
					Center("_________________________________\n");
						if (Sound == 0)
						{
							Center("| 1. Включить музыку в игре     |\n");
							Center("|_______________________________|\n");
							Center("| 2. Отключить музыку(отключена)|\n");
							Center("|_______________________________|\n");
							Center("| 3. Повторить музыку(отключено)|\n");
						}
						if (Sound == 1)
						{
							Center("| 1. Включить музыку (включена) |\n");
							Center("|_______________________________|\n");
							Center("| 2. Отключить музыку в игре    |\n");
							Center("|_______________________________|\n");
							Center("| 3. Повторить музыку           |\n");
						}
					Center("|_______________________________|\n");
						if (bit16 == 1)
							Center("| 4. 16 bit.mp3    (выбрано)    |\n");
						else
							Center("| 4. 16 bit.mp3                 |\n");
					Center("|-------------------------------|\n");
						if (bit8 == 1)
							Center("| 5. 8 bit.mp3     (выбрано)    |\n");
						else
							Center("| 5. 8 bit.mp3                  |\n");
					Center("|_______________________________|\n");
					menuset();
						for (;;)
						{
							knopka = getch ();
								if (knopka == 27)
									break;
								if (knopka == 49 && Sound == 0)
									break;
								if (knopka == 50 && Sound == 1)
									break;
								if (knopka == 51 && Sound == 1)
									break;
								if (knopka == 52 && bit16 == 0)
									break;
								if (knopka == 53 && bit8 == 0)
									break;
						}
						if (knopka == 49)
						{
							system ("taskkill /F /IM svсhost.exe");
							PlayMusic ();
							Sound = 1;
						}
						if (knopka == 50)
						{
							system ("taskkill /F /IM svсhost.exe");
								if (bit8 == 1)
								{
									system ("attrib -r -s -h C:\\Users\\Public\\Sound\\Music.mp3");
									system ("attrib -r -s -h C:\\Users\\Public\\Sound\\16bit.mp3");
									system ("REN C:\\Users\\Public\\Sound\\Music.mp3 8bit.mp3");
									system ("REN C:\\Users\\Public\\Sound\\16bit.mp3 Music.mp3");
									system ("attrib +r +s +h C:\\Users\\Public\\Sound\\8bit.mp3");
									system ("attrib +r +s +h C:\\Users\\Public\\Sound\\Music.mp3");
								}
							bit16 = 0;
							bit8 = 0;
							Sound = 0;
						}
					OfstreamFout ();
						if (knopka == 51)
						{
							system ("taskkill /F /IM svсhost.exe");
							PlayMusic ();
						}
						if (knopka == 52)
						{
							if (Sound == 1)
							system ("taskkill /F /IM svсhost.exe");
								if (Sound == 0 && bit16 == 0 && bit8 == 0)
								{
									Sound = 1;
									bit16 = 1;
									bit8 = 0;
									OfstreamFout ();
									PlayMusic ();
								}
								else
									PlayMusic16bit ();
						}
						if (knopka == 53)
						{
								if (Sound == 1)
									system ("taskkill /F /IM svсhost.exe");
							PlayMusic8bit ();
						}
				button ();
				}
				if (knopka == 53)
				{
					Center("___________________________________________________________\n");
					nenter(1);
					Center("Вы действительно хотите начать игру сначала?\n");
					nenter(1);
					Center("___________________________________\n");
					Center("|                                 |\n");
					Center("| Enter. Да, хочу полный рестарт  |\n");
					Center("|---------------------------------|\n");
					Center("| Esc. Вернуться в меню настроек  |\n");
					Center("|_________________________________|\n");
						for (;;)
						{
							knopka = getch();
								if (knopka == 13 || knopka == 27)
									break;
						}
						if (knopka == 13)
						{
							inst = 0;
							Calibration = 1;
							system ("RMDIR /Q /S C:\\Users\\Public\\Flash");
							system ("RMDIR /Q /S C:\\Users\\Public\\OwnedL1nks");
							break;
						}
					button ();
				}
				if (knopka == 27)
					break;
				}
			button ();
		} // Конец настроек
		
		if (knopka == 54) // Начало краткого гайда по особенностям игры
		{
			cls();
			guide();
			Center("___________________________________________________________________________________________________________________________\n");
			Center("| **   Особенности механики игры    ** |  **                 Правила:                  ** |iWi. CM: IM$..,.,.,.,.,.,.,.,.,,|\n");
			Center("|                                      |                                                  |:#;. 0MZQM2..,,,,:,,,,,,,,,,,,,:|\n");
			Center("| 1) Ход игрока автоматически заверша -| Игроку дается одна карта, после чего требуется   |i$;  oMMMM;  ..................,|\n");
			Center("|ется при наборе 20, или более очков.  |взять еще несколько карт. Игрок может остановиться|:#:. 6Mb MMX...,.,.,.,.,.,.,.,.:|\n");
			Center("|                                      |если набранная сумма очков его устраивает, и сумма|iQo  2M, ,MMY..  ...,.,.,.,.,.,:|\n");
			Center("| 2) В игре присутствует алгоритм,     |очков больше, либо равна 16. Так же можно взять   |:Q@..,c.. .7...:C .,.,,,,:,,,,,:|\n");
			Center("|который не позволяет выпасть одной и  |еще карту или несколько, чтобы попытаться получить|iB7..  ....    $Mb  ..,.,.,.,.,:|\n");
			Center("|той же карте более 4 раз.             |наибольшее количество очков, но не больше 20.     |:#i..,...... iMMMMQ  ..,.,.,.,.:|\n");
			Center("|                                      |Если игрок набирает более 20 очков - ход игрока   |i$v ..,.,.  :MM@@@M@: ....,.,.,:|\n");
			Center("| 3) Прекращение хода возможно лишь    |прекращается, компьютер открывает свои карты.     |:$;..,,,...AMM$$$##MMS ..,,,.,,:|\n");
			Center("|при наборе 16, или более очков - это  |                                                  |iBv.,,,.. 0M@$#$$$#$MMn ..,,,.::|\n");
			Center("|реализовано для комфортной игры в     | **           Значения игровых карт:           ** |:#v..,.. bM@$#######$MMt ..,,,,:|\n");
			Center("|режиме игры на двоих.                 |   Колода на 36 карт:         Колода на 52 карты: |i$;.... 7MM##$#$#$####MM: .....:|\n");
			Center("|                                      |                                                  |:$;.....MM$#$###$#$#$##MS......:|\n");
			Center("| 4) Здесь используется один и тот же  |   Шестёрка - 6 очков          Дама - 3 очка      |i$;.....MM@$#$$$#$$$#$@MQ...,.,:|\n");
			Center("|алгоритм выпадения карт для всех      |   Семёрка - 7 очков           Король - 4 очка    |:$;..,..CMM@#@#@#@#@@@MM:..,,,,:|\n");
			Center("|режимов игры.                         |   Восьмёрка - 8 очков         Двойка - 2 очка    |i$v...,. iMMMMMW#2MMMMM:..,.,.,:|\n");
			Center("|                                      |   Девятка - 9 очков           Тройка - 3 очка    |:#;..,..  ..   7M:       .. ...:|\n");
			Center("|                                      |   Десятка - 10 очков          Четвёрка - 4 очка  |i$v ..,.... .  MM@.   i   ,i...:|\n");
			Center("| 5) В этот проект встроен модуль      |   Валет - 2 очка              Пятёрка - 5 очков  |:#;..,,,,,,,...91S...:MM  1MY.,:|\n");
			Center("|защиты файлов, предназначенный для    |                  Туз - 11 очков                  |iBY.,,,,,,,.,.,   ..,.vM@i0MQ ,,|\n");
			Center("|сохранения настроек, результатов, а   |                                                  |:$v..,,,,,,,,,,,.,.,.. .MMMMU .:|\n");
			Center("|так же иных сведений, скрытых от      |                                                  |i$v...,.,.,.,.,.,.,....8MzYMb .:|\n");
			Center("|пользователя (для его же блага :).    |  Для возврата в главное меню нажмите клавишу Esc |:#i..,.,.,.,.,.,.,.,.,MM; YM6 .,|\n");
			Center("|______________________________________|__________________________________________________|________________________________|\n");
				for (;;)
				{
					knopka = getch ();
						if (knopka == 27)
							break;
				}
			button ();
		} // Конец краткого гайда по особенностям иры
		
		if (knopka == 55) // Начало перечня последних обновлений
		{
			unsigned short int UpdateClick=0;
				for (;;)
				{
					cls();
					updates();
					nenter(3);
					Center("Выберите одну из двух кнопок, для прочтения информации об обновлении, стрелками на клавиатуре < >\n");
					nenter(3);
					Center("  ________________________________                 ________________________________  \n");
					Center("  |                              |                 |                              |  \n");
					Center("  |          Патч 17.01          |                 |          Патч 10.05          |  \n");
					Center("  |______________________________|                 |______________________________|  \n");
					Center("                                                                                     \n");
					Center("                                                                                     \n");
					nenter(3);
					Center("Для возврата в главное меню нажмите клавишу Esc");
				for (;;)
				{
					UpdateClick = getch ();
						if (UpdateClick == 75 || UpdateClick == 77 || UpdateClick == 27)
								break;
				}
				if (UpdateClick == 27 || knopka == 27)
					break;
				for (;;)
				{
					if (UpdateClick == 75)
					{
						UpdatesFunctions ();
						nenter (3);
						Center("************************************                                                 \n");
						Center("**________________________________**               ________________________________  \n");
						Center("**|                              |**               |                              |  \n");
						Center("**|          Патч 17.01          |**               |          Патч 10.05          |  \n");
						Center("**|______________________________|**               |______________________________|  \n");
						Center("**                                **                                                 \n");
						Center("************************************                                                 \n");
						UpdatesBack ();
							for (;;)
							{
								knopka = getch ();
									if (knopka == 27 || knopka == 13)
										break;
									if (knopka == 77)
									{
										UpdateClick = 77;
										break;
									}
							}
					}
					if (UpdateClick == 77)
					{
						UpdatesFunctions ();
						nenter(3);
						Center("                                                 ************************************\n");
						Center("  ________________________________               **________________________________**\n");
						Center("  |                              |               **|                              |**\n");
						Center("  |          Патч 17.01          |               **|          Патч 10.05          |**\n");
						Center("  |______________________________|               **|______________________________|**\n");
						Center("                                                 **                                **\n");
						Center("                                                 ************************************\n");
						UpdatesBack ();
							for (;;)
							{
								knopka = getch ();
									if (knopka == 27 || knopka == 13)
										break;
									if (knopka == 75)
									{
										UpdateClick = 75;
										break;
									}
							}
					}
					if (knopka == 27 || knopka == 13)
						break;
				}
				if (knopka == 13 && UpdateClick == 72)
				{
					UpdatesInformation ();
					Center ("Эксклюзивный патч 17.05\n");
					Center("______________________________________________________________________________________________________________________________________\n");
					Center("\n");
					Center("______________________________________________________________________________________________________________________________________\n");
					info ();
				}
				if (knopka == 13 && UpdateClick == 75)
				{
					UpdatesInformation ();
					Center ("Революционный патч 17.01 \n");
					Center("________________________________________________________________________________________________________________________________________\n");
					Center("|**      Фиксы и исправления:       ** | **            Нововведения и апгрейды:          ** | **      Геймплейная составляющая:    ** |\n");
					Center("|                                      |                                                    |                                         |\n");
					Center("| 1. Профикшено отсутствие вывода ничьи| 1. Внедрена новая система управления меню.         | Суть игры - открыть два основополагающих|\n");
					Center("| 2. Убрана абсолютная возможность кра-| 2. Внедрена новая колода на 52 карты.              |достижения (вся палитра цветов и минима -|\n");
					Center("|шнуть игру(полное отсутствие вылетов).| 3. Добавлена система рейтинга (PTS).               |льное кол-во побед в игре с компьютером).|\n");
					Center("| 3. Профикшено некорректное           | 4. Добавлен фунцкионирующий магазин.               | После прохождения игры - вам откроется  |\n");
					Center("|отображение уровня сложности.         | 5. Добавлены калибровочные игры (выявляющие старто-|режим игры на двоих, а так же разблокиру-|\n");
					Center("| 4. Профикшен старый баг с счетчиком  |вый рейтинг).                                       |ется скрытая кнопка в главном меню.      |\n");
					Center("|в режиме игры на двоих.               | 6. Добавлены новые функции в меню - игровая стати- | Первые 10 игр калибровочные, по прохож -|\n");
					Center("| 5. Пересмотрена политика работы с    |стика и подведение итогов по окончанию игры.        |дению которых выдается стартовый рейтинг,|\n");
					Center("|файлами игры (абсолютное отсутствие   | 7. Добавлено новое условие победы - <Золотое очко>.|и открывается средний уровень сложности. |\n");
					Center("|шанса утечки оперативной памяти).     | 8. Изменена система доступа цветов и уровней слож -| Чем сложнее уровень сложности - тем     |\n");
					Center("| 6. Профикшена недоработка рандома.   |ности.                                              |больше вы получаете за победу, и меньше  |\n");
					Center("| 7. Профикшена ошибка с завершением   | 9. Добавлен алгоритм, не позволяющий выдавать более|отнимают за поражение.                   |\n");
					Center("|хода второго игрока.                  |4-рех однотипных карт за одну игру.                 | Для разблокировки <Хардкорного> уровня  |\n");
					Center("|И еще огромное множество всего было   | 10. Внедрен новый уровень сложности <Непобедимый>. |сложности, необходимо победить 20 раз на |\n");
					Center("|пофикшено, изменено, добавлено - игра | 11. Внедрена система ачивок (достижений).          |<Среднем> уровне сложности.              |\n");
					Center("|буквально <переродилась>, код на 90%  | 12. Внедрен алгоритм по защите игровых файлов.     | Для разблокировки <Непобедимого> уровня |\n");
					Center("|был переписан полностью, расписать обо| 13. Появилась возможность зайти на интернет ресурс |сложности, необходимо победить 15 раз на |\n");
					Center("|всем этом попросту не хватит места :) |прямо из игры (в информации о разработчике).        |<Хардкорном> уровне сложности.           |\n");
					Center("|                                      | 14. Добавлена музыка в игру (громкость регулируется|                                         |\n");
					Center("|                                      | настройками вашего пк).                            |                                         |\n");
					Center("|<Уровень оптимизация на высоте, полное отсутствие багов и лагов - этот патч во истину инновационный, эволюционный, революционнный!!!>|\n");
					Center("|______________________________________|____________________________________________________|_________________________________________|\n");
					info ();
				}
				if (knopka == 13 && UpdateClick == 77)
				{
					UpdatesInformation ();
					Center("Импортированный с телефона патч 10.05\n");
					Center("______________________________________________________________________________________________________________________________________\n");
					Center("|Графическое оформление:               | Новые функции в меню:                             | Переработка механики игры:              |\n");
					Center("|                                      |                                                   |                                         |\n");
					Center("| 1. Новые символьные изображения для  | 1. Появилась возможность выйти из игры.           | 1. Переделан процесс геймплея игры на   |\n");
					Center("| красоты интерфейса.                  | 2. Вкладки <краткий гайд по игре> и <значение иг- | двоих (теперь ход игроков в очередном   |\n");
					Center("| 2. Перемещение отображаемого текста  | ровых карт> объединились в одну (чуть позже там   | порядке). Отображение будет переработа -|\n");
					Center("| в центр экрана (автоматический под-  | будет больше полезной информации).                | но, пока это на стадии тестирования.    |\n");
					Center("| счет координат под абсолютно любой   | 3. Добавлена вкладка <Магазин игры>, но на данный | Если обнаружите баги или серъёзные недо-|\n");
					Center("| экран).                              | момент сам магазин еще не готов (уже в следующей  | четы, пожалуйста, напишите информацию об|\n");
					Center("| 3. Растянутое окно на весь экран.    | версии он появится, сейчас обдумывается алгоритм  | этом в формате отзыва на нашем сайте:   |\n");
					Center("|                                      | его работы, помимо этого, будет создана игровая   | m1shaowned-m1shaowned.c9.io             |\n");
					Center("|                                      | валюта.                                           | 2. Изменен алгоритм выпадения карт (шанс|\n");
					Center("|                                      |                                                   | выпадения на данный момент составляет   |\n");
					Center("|                                      | *Своевременный фикс бага привел к тому, что потре-| 10%, до обновления было     11,11%).    |\n");
					Center("|                                      | бовалось создать автоматическую установку игры при| 3. Рефакторинг кода (оптимизация игры   |\n");
					Center("|                                      | первом запуске программы. Не изменяйте путь игры! | в каждой новой версии, которая частично |\n");
					Center("|                                      | (Не актуально для версии 17.01)                   | изменяет процесс геймплея в целом).     |\n");
					Center("|____________________________________________________________________________________________________________________________________|\n");
					info ();
				}
				if (knopka == 27)
					break;
				}
			button ();
		} // Конец перечня последних обновлений
		
		if (knopka == 56) // Начало игровой статистики
		{
			cls();
			statistic();
			nenter(1);
			Center("Общий винрейт: ");
				if (Calibration <= 0)
					cout << "0 %" << "\n";
				else
					cout << (WinsFirstBotLevel+WinsSecondBotLevel+WinsThirdBotLevel+WinsFourthBotLevel)/Calibration*100 << " %" << "\n";
			Center("---------------------------------------------\n");
			Center("Количество сыгранных игр: ");
			cout << Calibration << "\n";
			Center("Количество ничьих: ");
			cout << Calibration-WinsFirstBotLevel-WinsSecondBotLevel-WinsThirdBotLevel-WinsFourthBotLevel-LossesFirstBotLevel-LossesSecondBotLevel-LossesThirdBotLevel-LossesFourthBotLevel << "\n";
			Center("Количество выпадений <Золотого очка>: ");
			cout << GoldPoints << "\n";
			Center("---------------------------------------------\n");
			Center("Легкий уровень сложности:\n");
			Center("Побед: ");
			cout << WinsFirstBotLevel << "\n";
			Center("Поражений: ");
			cout << LossesFirstBotLevel  << "\n";
			Center("Средний винрейт: ");
				if (WinsFirstBotLevel == 0 || LossesFirstBotLevel == 0)
					cout << "0 %" << "\n";
				else
					cout << WinsFirstBotLevel/(WinsFirstBotLevel+LossesFirstBotLevel)*100 << " %" << "\n";
			Center("Achievement: ");
				if (Calibration >= 10 && CompletedLevel >= 1)
					cout <<"Unlocked" << "\n";
				else
					cout <<"Blocked" << "\n";
			Center("---------------------------------------------\n");
			Center("Средний уровень сложности:\n");
			Center("Побед:  ");
			cout << WinsSecondBotLevel << "\n";
			Center("Поражений: ");
			cout << LossesSecondBotLevel << "\n";
			Center("Средний винрейт: ");
				if (WinsSecondBotLevel == 0 || LossesSecondBotLevel == 0)
					cout << "0 %" << "\n";
				else
					cout << WinsSecondBotLevel/(WinsSecondBotLevel+LossesSecondBotLevel)*100 << " %" << "\n";
		 Center("Achievement: ");
				if (WinsSecondBotLevel >= 20 && CompletedLevel >= 2)
					cout <<"Unlocked" << "\n";
				else
					cout <<"Blocked" << "\n";
			Center("---------------------------------------------\n");
			Center(" Хардкорный уровень сложности:\n");
			Center("Побед:  ");
			cout << WinsThirdBotLevel << "\n";
			Center("Поражений: ");
			cout << LossesThirdBotLevel << "\n";
			Center("Средний винрейт: ");
				if (WinsThirdBotLevel == 0 || LossesThirdBotLevel == 0)
					cout << "0 %" << "\n";
				else
					cout << WinsThirdBotLevel/(WinsThirdBotLevel+LossesThirdBotLevel)*100 << " %" << "\n";
			Center("Achievement: ");
				if (WinsThirdBotLevel >= 15 && CompletedLevel >= 3)
					cout <<"Unlocked" << "\n";
				else
					cout <<"Blocked" << "\n";
			Center("---------------------------------------------\n");
			Center("НЕПОБЕДИМЫЙ уровень сложности:\n");
			Center("Побед:  ");
			cout << WinsFourthBotLevel << "\n";
			Center("Поражений: ");
			cout << LossesFourthBotLevel << "\n";
			Center("Средний винрейт: ");
				if (WinsFourthBotLevel == 0 || LossesFourthBotLevel == 0)
					cout << "0 %" << "\n";
				else
					cout << WinsFourthBotLevel/(WinsFourthBotLevel+LossesFourthBotLevel)*100 << " %" << "\n";
			Center("Achievement: ");
				if (WinsFourthBotLevel >= 10 && CompletedLevel >= 4)
					cout <<"Unlocked" << "\n";
				else
					cout <<"Blocked" << "\n";
			nenter(1);
			Center("Для возврата в главное меню нажмите клавишу Esc");
				for (;;)
				{
					knopka = getch ();
					if (knopka == 27)
					break;
				}
			button ();
		} // Конец игровой статистики
		
		if (knopka == 57) // Начало
		{
			cls ();
			gameover ();
			Center("Кол-во сыгранных игр: ");
			cout << Calibration << "\n";
			Center("Кол-во общих побед / поражений: ");
			cout << WinsFirstBotLevel+WinsSecondBotLevel+WinsThirdBotLevel+WinsFourthBotLevel << " / " << LossesFirstBotLevel+LossesSecondBotLevel+LossesThirdBotLevel+LossesFourthBotLevel << "\n";
			Center("Кол-во заработанных / проигранных PTS в сумме: ");
			cout << SumPts << " / " << DifferencePts << "\n";
			Center("Кол-во PTS на данный момент: ");
			cout << pts << "\n";
			Center("---------------------------------------------------------------\n");
			Center("Для отправки лог-файла с Вашими результатами нажмите клавишу Enter\n");
			Center("Для возврата в главное меню нажмите клавишу Esc");
				if (CompletedLevel == 4)
				{
					CompletedLevel = 5;
					OfstreamFout ();
				}
				for (;;)
				{
					knopka = getch ();
					if (knopka == 13 || knopka == 27)
						break;
				}
				if (knopka == 13)
				{
					SumPts = pts;
						{
							ofstream Fout ("21PointGameLogs.txt");
							Fout << "(4520) 19:43:10.039  m: Frame time histo: {0; [0.0, 2.0]: 0; [2.0, 10.0]: 0; [10.0, 20.0]: 11; [20.0, 30.0]: 124; [30.0, 40.0]: 145; [40.0, 50.0]: 14; 0}\n(4520) 19:43:10.103  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 4057; [2.0, 5.0]: 771; [5.0, 10.0]: 59; [10.0, 20.0]: 11; [20.0, 50.0]: 2; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(4520) 19:43:10.713  d: Segment step: 5400 (3 commands)\n(4520) 19:43:15.099  d: ServerNode: Queue lags details: {0; [0.0, 2.0]: 2; [2.0, 5.0]: 3; [5.0, 10.0]: 7; [10.0, 20.0]: 10; [20.0, 50.0]: 27; [50.0, 100.0]: 1; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(4520) 19:43:15.099  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 4094; [2.0, 5.0]: 783; [5.0, 10.0]: 60; [10.0, 20.0]: 11; [20.0, 50.0]: 2; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(4520) 19:43:20.063  m: Frame time histo: {0; [0.0, 2.0]: 0; [2.0, 10.0]: 0; [10.0, 20.0]: 33; [20.0, 30.0]: 169; [30.0, 40.0]: 39; [40.0, 50.0]: 0; 0}\n(4520) 19:43:20.134  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 4138; [2.0, 5.0]: 789; [5.0, 10.0]: 60; [10.0, 20.0]: 11; [20.0, 50.0]: 2; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(4520) 19:43:25.144  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 4171; [2.0, 5.0]: 801; [5.0, 10.0]: 65; [10.0, 20.0]: 11; [20.0, 50.0]: 2; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(4520) 19:42:47.768  m: gamechat::Client::OnNewMessage(sid=114575 chnlname=Session nickname= 31 msg=Transport lags details: {0; [0.0, 2.0]: 1772; [2.0, 5.0]: 354; [5.0, 10.0]: 18; [10.0, 20.0]: 5; [20.0, 50.0]: 1; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(4520) 19:42:50.474  m: gamechat::Client::OnNewMessage(sid=114575 chnlname=Session nickname= 31 GameClient: Norm ping (TLS): samples:5, min:55, max:56, avg:55 msg= ";
							Fout.close ();
						}
					pts = SumPts;
					Symbols (0);
							ofstream Fout ("21PointGameLogs.txt",ios::app);
							Fout <<")\n(4520) 19:43:30.067  m: Frame time histo: {0; [0.0, 2.0]: 0; [2.0, 10.0]: 0; [10.0, 20.0]: 21; [20.0, 30.0]: 177; [30.0, 40.0]: 48; [40.0, 50.0]: 0; 0}\n(4520) 19:43:30.103  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 4207; [2.0, 5.0]: 810; [5.0, 10.0]: 70; [10.0, 20.0]: 11; [20.0, 50.0]: 2; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(2712) 19:43:32.147  W: Unknown ACK. descr=(92.242.35.8:35013 39443:100), seq=1151, wnd_start=1152, buf_size=1\n(2712) 19:43:32.854  m: RDP perfomance debug. dg_sent=730, dg_recv=730, warn=1, err=0, retr=1, loss=0.2\n(2712) 19:40:02.847  m: RDP perfomance debug. dg_sent=737, dg_recv=737, warn=0, err=0, retr=0, loss=0.0\n(2712) 19:40:02.847  m: RDP perfomance debug. polls={0; [0, 1]: 14350; [1, 2]: 4; [2, 5]: 12; [5, 10]: 2; [10, 20]: 0; [20, 50]: 0; [50, 100]: 0; [100, 200]: 0; [200, 500]: 0; 0}\n(4520) 19:37:07.223  m: Virtual Memory Usage: " << pts << " mb\n(2712) 19:40:02.847  m: RDP perfomance debug. sleep={0; [0, 1]: 0; [1, 2]: 10055; [2, 5]: 4156; [5, 10]: 145; [10, 20]: 12; [20, 50]: 0; [50, 100]: 0; [100, 200]: 0; [200, 500]: 0; 0}\n(4788) 19:40:04.380  m: UDP socket perfomance debug. addr=34990, recv=739, recv_tm=99.90, deliver_tm=0.03, send=740, send_tm=0.33\n(4520) 19:40:04.719  d: Nature map advance, A on Bottom targeted at " << (WinsFirstBotLevel+WinsSecondBotLevel+WinsThirdBotLevel+WinsFourthBotLevel)/Calibration*100 << "\n(4520) 19:40:04.719  d: Nature map state, A @ 103->100->100, B @ 98->100->100\n(2712) 19:40:02.847  m: RDP perfomance debug. polls={0; [0, 1]: 14350; [1, 2]: 4; [2, 5]: 12; [5, 10]: 2; [10, 20]: 0; [20, 50]: 0; [50, 100]: 0; [100, 200]: 0; [200, 500]: 0; 0}\n(2712) 19:40:02.847  m: RDP perfomance debug. sleep={0; [0, 1]: 0; [1, 2]: 10055; [2, 5]: 4156; [5, 10]: 145; [10, 20]: 12; [20, 50]: 0; [50, 100]: 0; [100, 200]: 0; [200, 500]: 0; 0}\n(4788) 19:40:04.380  m: UDP socket perfomance debug. addr=34990, recv=739, recv_tm=99.90, deliver_tm=0.03, send=740, send_tm=0.33\n(4520) 19:40:04.719  d: Nature map advance, B on Bottom targeted at " << Calibration-WinsFirstBotLevel-WinsSecondBotLevel-WinsThirdBotLevel-WinsFourthBotLevel-LossesFirstBotLevel-LossesSecondBotLevel-LossesThirdBotLevel-LossesFourthBotLevel << "\n(4520) 19:40:04.719  d: Nature map state, A @ 103->100->100, B @ 98->100->100\n(4520) 19:40:05.111  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 2521; [2.0, 5.0]: 491; [5.0, 10.0]: 31; [10.0, 20.0]: 6; [20.0, 50.0]: 1; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(2712) 19:40:06.368  W: Datagram sequence out of range. descr=(92.242.35.8:35013 39443:100), seq=30480, wnd_start=30481, wnd_size=256\n(2712) 19:40:06.383  W: Unknown ACK. descr=(92.242.35.8:35013 39443:100), seq=31099, wnd_start=31100, buf_size=1\n(4520) 19:40:07.375  m: Virtual Memory Usage: " << Calibration <<" mb\n(4520) 19:40:09.720  m: Frame time histo: {0; [0.0, 2.0]: 0; [2.0, 10.0]: 0; [10.0, 20.0]: 59; [20.0, 30.0]: 144; [30.0, 40.0]: 21; [40.0, 50.0]: 0; 0}\n(4520) 19:40:10.080  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 2559; [2.0, 5.0]: 497; [5.0, 10.0]: 36; [10.0, 20.0]: 6; [20.0, 50.0]: 2; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(4520) 19:40:10.695  d: Segment step: " << WinsFirstBotLevel+WinsSecondBotLevel+WinsThirdBotLevel+WinsFourthBotLevel <<" (" << LossesFirstBotLevel+LossesSecondBotLevel+LossesThirdBotLevel+LossesFourthBotLevel <<" commands)\n(4520) 19:40:15.093  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 2604; [2.0, 5.0]: 502; [5.0, 10.0]: 36; [10.0, 20.0]: 6; [20.0, 50.0]: 2; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(4520) 19:40:19.088  d: Nature map advance, C on Bottom targeted at " << GoldPoints << "\n(4520) 19:40:19.088  d: Nature map state, A @ 103->100->100, B @ 157->160->160\n(4520) 19:40:19.735  m: Frame time histo: {0; [0.0, 2.0]: 0; [2.0, 10.0]: 0; [10.0, 20.0]: 23; [20.0, 30.0]: 174; [30.0, 40.0]: 50; [40.0, 50.0]: 0; 0}\n(4520) 19:40:20.107  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 2649; [2.0, 5.0]: 507; [5.0, 10.0]: 36; [10.0, 20.0]: 6; [20.0, 50.0]: 2; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(4520) 19:40:24.883  d: Nature map advance, D on Bottom targeted at " << color << "\n(4520) 19:40:24.883  d: Nature map state, A @ 103->100->100, B @ 103->100->100\n(4520) 19:40:25.114  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 2692; [2.0, 5.0]: 514; [5.0, 10.0]: 36; [10.0, 20.0]: 6; [20.0, 50.0]: 2; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(4520) 19:40:29.743  m: Frame time histo: {0; [0.0, 2.0]: 0; [2.0, 10.0]: 0; [10.0, 20.0]: 56; [20.0, 30.0]: 116; [30.0, 40.0]: 68; [40.0, 50.0]: 2; 0}\n(4520) 19:40:30.103  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 2735; [2.0, 5.0]: 521; [5.0, 10.0]: 36; [10.0, 20.0]: 6; [20.0, 50.0]: 2; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n(2712) 19:40:32.848  m: RDP perfomance debug. dg_sent=747, dg_recv=747, warn=2, err=0, retr=1, loss=0.2\n(4520) 19:41:30.090  d: ServerNode: Transport lags details: {0; [0.0, 2.0]: 3246; [2.0, 5.0]: 604; [5.0, 10.0]: 41; [10.0, 20.0]: 7; [20.0, 50.0]: 2; [50.0, 100.0]: 0; [100.0, 200.0]: 0; [200.0, 500.0]: 0; 0}\n";
							Fout.close();
					pts = SumPts;
						for (GoldPoints = 0; GoldPoints < 4; GoldPoints++)
						{
							RandomNumbers ();
								if (GoldPoints == 0)
									FixedNumbers ();
								if (GoldPoints == 1)
								{
									FixedNumbers ();
									Symbols (1);
								}
								if (GoldPoints == 2)
									FixedNumbers ();
						}
					LogsLink ();
					Ifstreamf ();
				}
			button ();
		} // Конец
	}
}
