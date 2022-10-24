#include <windows.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>


#define nano 0.000000001f


class Challenges {
public:
	void GetChallenge(unsigned int Number)
	{
		if (Number == 1)
		{
			FirstChallege();
		}
		if (Number == 2)
		{
			SecondChallenge();
		}
		if (Number == 3)
		{
			ThirdChallenge();
		}
		if (Number == 4)
		{
			FourthChallenge();
		}
		if (Number == 5)
		{
			FithChallenge();
		}
		if (Number == 6)
		{
			SixthChallenge();
		}
		if (Number == 7)
		{
			SeventhChallenge();
		}
		if (Number == 8)
		{
			EightChallenge();
		}
		if (Number == 9)
		{
			NinthChallenge();
		}
		if (Number == 10)
		{
			TenthChallenge();
		}
		if (Number == 11)
		{
			EleventhChallenge();
		}
		if (Number == 12)
		{
			TwelthChallenge();
		}
	}


private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	void SpaceCheck() {
		bool Continue = false;
		while (!Continue)
		{
			if ((GetKeyState(VK_SPACE) & 0x8000) != 0)
			{
				Continue = true;
			}
		}
	}

	void FirstChallege() {
		// Joke
		std::cout << "What did the green grape say to the purple grape?			|Please press space|" << std::endl;
		SpaceCheck();
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "Stop holding your breath." << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
	}

	void SecondChallenge() {
		// Name
		std::string Name;
		std::cout << "What is your name?" << std::endl;
		std::cin >> Name;
		std::cout << "Hello " << Name << std::endl;
	}

	void ThirdChallenge() {
		// Area
		float Width;
		float Height;
		float Depth;
		std::cout << "Please input a width" << std::endl;
		std::cin >> Width;
		std::cout << "Please input a height" << std::endl;
		std::cin >> Height;
		std::cout << "Please input a depth" << std::endl;
		std::cin >> Depth;
		float Area = Width * Height * Depth;
		std::cout << "The area for the cuboid is " << Area << std::endl;
	}

	void FourthChallenge() {
		// speed s=tv
		float Speed1;
		float Speed2;
		float Time1;
		float Time2;
		float Distance;
		std::cout << "Please input a speed" << std::endl;
		std::cin >> Speed1;
		std::cout << "Please input a time" << std::endl;
		std::cin >> Time1;
		Distance = Speed1 * Time1;
		std::cout << "The distance for the object is " << Distance << std::endl;
		std::cout << "Please input a time" << std::endl;
		std::cin >> Time2;
		Speed2 = Distance / Time2;
		std::cout << "It would take you " << Time2 << " seconds at " << Speed2 << " meters per second to travel " << Distance << " meters." << std::endl;
	}

	void FithChallenge() {
		time_t CurrnetTime;
		time(&CurrnetTime);

		struct tm BirthDate;
		int year;
		std::cout << "Please input the year you were born" << std::endl;
		std::cin >> year;
		BirthDate.tm_year = year - 1900;

		int month;
		std::cout << "Please input the month you were born" << std::endl;
		std::cin >> month;
		BirthDate.tm_mon = month - 1;

		int day;
		std::cout << "Please input the day you were born" << std::endl;
		std::cin >> day;
		BirthDate.tm_mday = day;

		BirthDate.tm_hour = 0;
		BirthDate.tm_min = 0;
		BirthDate.tm_sec = 0;
		BirthDate.tm_isdst = 0;

		double SecondsAlive = difftime(CurrnetTime, mktime(&BirthDate));
		double DaysAlive = ((SecondsAlive / 60) / 60) / 24;
		std::cout << "You have been alive for " << DaysAlive << " days, this is " << SecondsAlive << " seconds." << std::endl;

	}

	void SixthChallenge() 
	{// Guess seconds
		std::string enter;
		std::cout << "Press SPACE when you think 10 seconds have elapsed" << std::endl;
		auto start = std::chrono::high_resolution_clock::now();
		SpaceCheck();
		auto stop = std::chrono::high_resolution_clock::now();
		auto TimeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		std::cout << ((float)TimeTaken.count() * nano) << "seconds has elapsed." << std::endl;
		std::cout << "You were " << std::abs(10.0f - ((float)TimeTaken.count() * nano)) << " seconds from the being perfect." << std::endl;
		UpdateScoreFile(std::abs(10.0f - ((float)TimeTaken.count() * nano)), "ten.txt");
		std::cout << "The best time was " << GetHighScore("ten.txt") << " seconds." << std::endl;


	}

	void SeventhChallenge()
	{// Type Alphabet
		std::string alphabet;
		std::cout << "Press SPACE when you're ready to type the alphabet." << std::endl;
		auto start = std::chrono::high_resolution_clock::now();
		std::cin >> alphabet;
		auto stop = std::chrono::high_resolution_clock::now();
		auto TimeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		if (alphabet == "abcdefghijklmnopqrstuvwxyz" || "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
		{
			std::cout << "You typed the alphabet right and it took you " << ((float)TimeTaken.count() * nano) << " seconds" << std::endl;
			UpdateScoreFile(((float)TimeTaken.count() * nano), "alph.txt");
		}
		else {
			std::cout << "You typed the alphabet incorrectly and it took you " << ((float)TimeTaken.count() * nano) << " seconds" << std::endl;
		}
		std::cout << "The fastest time was " << GetHighScore("alph.txt") << " seconds." << std::endl;
	}

	void UpdateScoreFile(float score, std::string FileName)
	{
		std::string filename(FileName);
		std::fstream file;

		file.open(filename, std::ios_base::app | std::ios_base::in);
		if (file.is_open())
			file << std::to_string(score) << std::endl;
		file.close();
	}

	std::string GetHighScore(std::string FileName)
	{
		std::fstream file;
		std::string filename(FileName);
		std::string tp;
		std::string Score1;
		std::string HighScore;
		std::vector<float> VecScore;
		file.open(filename, std::ios::in); //open a file to perform read operation using file object
		if (file.is_open()) {   //checking whether the file is open
			while (file.peek() != EOF)
			{
				std::getline(file, Score1);
				try {
					VecScore.push_back(stof(Score1));
				}
				catch (...){}
			}
			file.close();
		}
		for (int i = 0; i < VecScore.size(); i++) {
			if (VecScore[0] > VecScore[i])
				VecScore[0] = VecScore[i];
		}
		HighScore = std::to_string(VecScore[0]);
		VecScore.clear();
		return HighScore;
	}

	void EightChallenge() {
		time_t CurrnetTime;
		time(&CurrnetTime);

		struct tm BirthDate;
		int year;
		std::cout << "Please input the year you were born" << std::endl;
		std::cin >> year;
		BirthDate.tm_year = year - 1900;

		int month;
		std::cout << "Please input the month you were born" << std::endl;
		std::cin >> month;
		BirthDate.tm_mon = month - 1;

		int day;
		std::cout << "Please input the day you were born" << std::endl;
		std::cin >> day;
		BirthDate.tm_mday = day;

		BirthDate.tm_hour = 0;
		BirthDate.tm_min = 0;
		BirthDate.tm_sec = 0;
		BirthDate.tm_isdst = 0;

		double SecondsAlive = difftime(CurrnetTime, mktime(&BirthDate));
		if (SecondsAlive < 5.68E8)
		{
			std::cout << "You're not 18 yet." << std::endl;
		}
		if (SecondsAlive > 5.68E8)
		{
			std::cout << "You're at least 18." << std::endl;
		}
	}

	void NinthChallenge() {
		bool Another = true;
		std::string YN;
		while (Another)
		{
			int Suit = rand() % 3;
			int Card = rand() % 12;
			std::string SuitStr;
			std::string CardStr;
			if (Suit == 0)
			{
				SuitStr = "Diamonds";
			}
			if (Suit == 1)
			{
				SuitStr = "Hearts";
			}
			if (Suit == 2)
			{
				SuitStr = "Spades";
			}
			if (Suit == 3)
			{
				SuitStr = "clubs";
			}
			if (Card <= 9)
			{
				CardStr = std::to_string(Card + 1);
			}
			if (Card == 0)
			{
				CardStr = "Ace";
			}
			if (Card == 10)
			{
				CardStr = "Jack";
			}
			if (Card == 11)
			{
				CardStr = "Queen";
			}
			if (Card == 12)
			{
				CardStr = "King";
			}
			std::cout << "Your card is " << CardStr << " of " << SuitStr << std::endl;
			std::cout << "Would you like another? (y/n)" << std::endl;
			std::cin >> YN;
			if (YN != "y")
			{
				Another = false;
			}
		}
	}

	void TenthChallenge() {
		bool Another = true;
		std::string YN;
		while (Another)
		{
			std::string RPSPerson;
			std::string RPSBotStr;
			int RPSPersonInt;
			std::cout << "Please input rock, paper or scissors." << std::endl;

			std::cin >> RPSPerson;
			if (RPSPerson == "rock")
			{
				RPSPersonInt = 0;
			}
			if (RPSPerson == "paper")
			{
				RPSPersonInt = 1;
			}
			if (RPSPerson == "scissors")
			{
				RPSPersonInt = 2;
			}
			
			int RPSBot = rand() % 2;

			if (RPSBot == 0)
			{
				RPSBotStr = "rock";
			}
			if (RPSBot == 1)
			{
				RPSBotStr = "paper";
			}
			if (RPSBot == 2)
			{
				RPSBotStr = "scissors";
			}


			if (RPSPersonInt == RPSBot)
			{
				std::cout << "Tie" << std::endl;
			}

			if (RPSPersonInt == 0 && RPSBot == 1)//rock and paper
			{
				std::cout << "You lose :(" << std::endl;
			}
			if (RPSPersonInt == 1 && RPSBot == 0)//paper and rock
			{
				std::cout << "You win!!!" << std::endl;
			}

			if (RPSPersonInt == 0 && RPSBot == 2)//rock and scissors
			{
				std::cout << "You Win!!!" << std::endl;
			}
			if (RPSPersonInt == 2 && RPSBot == 0)//scissors and rock
			{
				std::cout << "You lose :(" << std::endl;
			}

			if (RPSPersonInt == 1 && RPSBot == 2)//paper and scissors
			{
				std::cout << "You lose :(" << std::endl;
			}
			if (RPSPersonInt == 2 && RPSBot == 1)//scissors and paper
			{
				std::cout << "You win!!!" << std::endl;
			}
			std::cout << "You chose " << RPSPerson << " and the bot chose " << RPSBotStr << std::endl;
			std::cout << "Would you like another go? (y/n)" << std::endl;
			std::cin >> YN;
			if (YN != "y")
			{
				Another = false;
			}
		}
	}

	void EleventhChallenge() {
		bool Another = true;
		std::string YN;
		while (Another)
		{
			std::string ED;
			std::cout << "Would you like to encrypt or decrypt? (e/d)" << std::endl;
			std::cin >> ED;
			if (ED == "e")
			{
				std::string Text;
				int Key;
				std::cout << "Please input the text" << std::endl;
				std::cin >> Text;
				std::cout << "Please input the key" << std::endl;
				std::cin >> Key;
				std::string EncryptText = Encrypt(Text, Key);
				std::cout << "Your encrypted text is " << EncryptText << std::endl;
			}
			if (ED == "d")
			{
				std::string Text;
				int Key;
				std::cout << "Please input the text" << std::endl;
				std::cin >> Text;
				std::cout << "Please input the key" << std::endl;
				std::cin >> Key;
				std::string DecryptText = Decrypt(Text, Key);
				std::cout << "Your decrypt text is " << DecryptText << std::endl;
			}
			std::cout << "Would you like another? (y/n)" << std::endl;
			std::cin >> YN;
			if (YN != "y")
			{
				Another = false;
			}
		}
	}

	std::string Encrypt(std::string String, int Key)
	{
		std::string ciphertext = String;
		for (int i = 0; i < String.size(); i++)
		{
			ciphertext[i] = String[i] + Key + i;
		}
		return ciphertext;
	}

	std::string Decrypt(std::string String, int Key)
	{
		std::string ciphertext = String;
		for (int i = 0; i < String.size(); i++)
		{
			ciphertext[i] = String[i] - Key - i;
		}
		return ciphertext;
	}

	void TwelthChallenge() 
	{// reaction time
		bool Another = true;
		std::string YN;
		while (Another)
		{
			std::string enter;
			float Time = ((float)((rand() % 50)+25))/10.0f;
			std::cout << "Press SPACE when the colour changes" << std::endl;

			SetConsoleTextAttribute(hConsole, 10);
			Sleep(Time * pow(10.0f,3.0f));
			std::cout << "NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW " << std::endl;
			std::cout << "NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW " << std::endl;
			std::cout << "NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW " << std::endl;
			std::cout << "NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW " << std::endl;
			std::cout << "NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW " << std::endl;
			std::cout << "NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW " << std::endl;
			std::cout << "NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW " << std::endl;
			std::cout << "NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW " << std::endl;
			std::cout << "NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW " << std::endl;
			std::cout << "NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW " << std::endl;
			std::cout << "NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW NOW " << std::endl;
			SetConsoleTextAttribute(hConsole, 7);
			auto start = std::chrono::high_resolution_clock::now();
			SpaceCheck();
			auto stop = std::chrono::high_resolution_clock::now();
			auto TimeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
			std::cout << "It took you " << ((float)TimeTaken.count()) * nano << " seconds to press space" << std::endl;

			UpdateScoreFile(((float)TimeTaken.count()) * nano, "React.txt");
			std::cout << "The best time was " << GetHighScore("React.txt") << " seconds." << std::endl;

			std::cout << "Would you like another? (y/n)" << std::endl;
			std::cin >> YN;
			if (YN != "y")
			{
				Another = false;
			}
		}
	}

};

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main() 
{
	ShowConsoleCursor(false);

	std::cout << std::fixed;
	srand(time(NULL));

	Challenges ChallengeMain;
	bool Another = true;
	std::string YN;
	while (Another)
	{
		unsigned int CHNumber;
		std::cout << "please input a number between 1 and 12." << std::endl;
		std::cin >> CHNumber;

		ChallengeMain.GetChallenge(CHNumber);

		std::cout << "Would you like another? (y/n)" << std::endl;
		std::cin >> YN;
		if (YN != "y")
		{
			Another = false;
		}
	}
	std::string End;
	std::cin >> End;
	return 0;
}