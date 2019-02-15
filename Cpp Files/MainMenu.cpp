#include "MainMenu.h"

MainMenu::MainMenu() 
{ 
	input = "";
	showMenu(); 
}

void MainMenu::showMenu()
{
	std::cout << "This is a consolidation program for all my Project Euler solutions." << std::endl;

	while (input.compare("quit"))
	{
		std::cout << "--------------------MAIN MENU---------------------" << std::endl;
		std::cout << "COMMAND   DESCRIPTION" << std::endl;
		std::cout << "list      Show list of available problems" << std::endl;
		std::cout << "info #    Show problem info" << std::endl;
		std::cout << "#         Execute problem number's program" << std::endl;
		std::cout << "quit      Exit program" << std::endl;
		std::cout << "> ";

		getline(std::cin, input);

		std::cout << std::endl;

		if (input.compare("list") == 0) showList();
		else if (input.compare("1") == 0)  P1();
		else if (input.compare("2") == 0)  P2();
		else if (input.compare("3") == 0)  P3();
		else if (input.compare("4") == 0)  P4();
		else if (input.compare("5") == 0)  P5();
		else if (input.compare("6") == 0)  P6();
		else if (input.compare("7") == 0)  P7();
		else if (input.compare("8") == 0)  P8();
		else if (input.compare("9") == 0)  P9();
		else if (input.compare("10") == 0) P10();
		else if (input.compare("11") == 0) P11();
		else if (input.compare("13") == 0) P13();
		else if (input.compare("14") == 0) P14();
		else if (input.compare("16") == 0) P16();
		else if (input.compare("17") == 0) P17();
		else if (input.compare("18") == 0) P18();
		else if (input.compare("54") == 0) P54();


		std::cout << std::endl;
	}
}

void MainMenu::showList()
{
	std::cout << "Available solutions:" << std::endl;
	std::cout << "  1   2   3   4   5   6   7   8   9  10 " << std::endl;
	std::cout << " 11  13  14  16  17  18  54  67         " << std::endl;
}
