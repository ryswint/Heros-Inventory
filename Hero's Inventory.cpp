//Ryan Swint
//Fall 2021 Chapter 3
//Module 4

//Hero's Inventory
//This program focuses on the inventory and nameing skills of the "hero" as they try to save the day.
//Built to run in Windows console
//https://github.com/ryswint




#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

//===================Variables & Constants=============================================================//

const int waitTime = 1000;
int typeTime = 25;

string inventory[10];
string name;
string item;
string loading = "-\|/- ";
string comms;

char answer;
char answerCap;

bool answerLoop;
bool answerLoop2;
bool restart = false;
bool exiGame = false;
bool skipDialog = false;
//===================User Defined Functions=============================================================//

void Report(string report, bool newLine)
{
	if (newLine)
	{
		cout << endl << time(NULL) << ": ";
	}

	for (int i = 0; i < report.length(); i++)
	{
		cout << report[i];
		Sleep(typeTime);
	}

	Sleep(waitTime);
}

string Inventory()
{
	int selection;
	string itemName;
	bool itemMatch = false;
	bool inventoryLoop = 1;
	int itemIndex;
	Sleep(3000);
	system("cls");
	system("color 02");
	Report("LOADING H.E.R.O.S. INVENTORY", 0);
	for (int i = 0; i < 15; i++)
	{
		Sleep(100);
		cout << ".";
	}
	for (int i = 0; i < 15; i++)
	{
		Sleep(50);
		cout << ".";
	}

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		Sleep(150);
		cout << "*H.E.R.O.S. INVENTORY LOADED SUCCESSFULLY*";
		Sleep(150);
		system("cls");
	}

	while (inventoryLoop)
	{
		system("cls");
		system("color 06");
		Report("-*H.E.R.O.S. INVENTORY*-", 0);
		cout << endl;
		Report("INVENTORY CONTENTS:", 1);
		for (int i = 0; i < 10; i++)
		{
			if (inventory[i] != "")
			{
				cout << endl << inventory[i];
			}
		}

		cout << endl;

		Report("1. Use Item", 1);
		Report("2. Rename Item", 1);
		Report("3. Exit Inventory", 1);
		cout << endl << endl << "Selection: ";

		cin >> selection;


		if (cin.fail())
		{
			cin.clear();
			cin.ignore();

			system("Color 40");
			system("Color 04");
			system("Color 40");
			system("Color 06");
			Report("INVALID ENTRY", 1);

		}
		else
		{
			system("Color 60");
			system("Color 06");
			system("Color 60");
			system("Color 06");
		}

		answerLoop = 1;

		switch (selection)
		{
		case 1:
			Report("Which Item do you want to select?", 1);
			cout << endl << "Item: ";
			cin >> itemName;

			for (int i = 0; i < 10; i++)
			{

				if (itemName == inventory[i])
				{
					itemMatch = true;
					itemIndex = i;
					break;
				}
				else
				{
					itemMatch = false;
				}

			}
			if (itemMatch)
			{
				system("Color 60");
				system("Color 06");
				system("Color 60");
				system("Color 06");
				answerLoop2 = 1;
				while (answerLoop2)
				{
					Report("Are you sure you want to use ", 1);
					Report(itemName, 0);
					cout << "? (y, n): ";
					cin >> answer;
					return itemName;


					answerCap = toupper(answer);
					switch (answerCap)
					{
					case 'Y':
						answerLoop2 = false;

						break;
					case 'N':
						answerLoop2 = false;
						break;

					default:
						system("Color 40");
						system("Color 04");
						system("Color 40");
						system("Color 09");
						Report("INVALID ENTRY", 1);
						answerLoop2 = true;
					}
				}
			}
			else
			{
				system("Color 40");
				system("Color 04");
				system("Color 40");
				system("Color 06");
				Report("NO ITEM WITH THAT DESIGNATION EXISTS\n", 1);
				break;
			}
		case 2:

			Report("Which Item do you want to rename?", 1);
			cout << endl << "Item: ";
			cin >> itemName;

			for (int i = 0; i < 10; i++)
			{

				if (itemName == inventory[i])
				{
					itemMatch = true;
					itemIndex = i;
					break;
				}
				else
				{
					itemMatch = false;
				}

			}
			if (itemMatch)
			{
				system("Color 60");
				system("Color 06");
				system("Color 60");
				system("Color 06");
				Report("NEW ITEM DESIGNATION (NO SPACES): ", 1);
				cin >> itemName;
				system("Color 60");
				system("Color 06");
				system("Color 60");
				system("Color 06");
				inventory[itemIndex] = itemName;
				break;
			}
			else
			{
				system("Color 40");
				system("Color 04");
				system("Color 40");
				system("Color 06");
				Report("NO ITEM WITH THAT DESIGNATION EXISTS\n", 1);
				break;
			}
		case 3:
			return "NOTHING";
		}
	}
}

void Continue(bool* rs, bool* eg)
{
	Sleep(3000);
	system("Color 40");
	system("Color 04");
	system("Color 40");
	system("Color 04");
	answerLoop = true;
	while (answerLoop)
	{
		cout << endl << endl << "TRY AGAIN? (y/n) ";
		cin >> answer;
		answerCap = toupper(answer);
		switch (answerCap)
		{
		case 'Y':
			*rs = true;
			*eg = false;
			answerLoop = false;
			cin.ignore();
			break;
		case 'N':
			*rs = false;
			*eg = true;
			answerLoop = false;
			break;
		default:
			Report("INVALID ENTRY.", 1);
			answerLoop = true;
		}

	}
}
//===================Main Function=====================================================================//

int main()
{
	while (1)
	{
		for (int i = 0; i < 10; i++)
		{
			inventory[i] = { "" };
		}
		restart = false;
		skipDialog = false;
		system("cls");
		system("Color 02");
		srand(time(NULL));


		Report("-*H.E.R.O.S. SHIP COMPUTER SYSTEM -- NSS OPPOSITION NS1473-- MAIN BATTLE GROUP*-", 0);
		cout << endl;
		Report("SYSTEM ACCESS REQUESTED............", 1);

		Report("ENTER YOUR DESIGNATION\nDESIGNATION: ", 1);
		getline(cin, name);
		name = "Cadet " + name;
		if (name == "Cadet Skip") skipDialog = true;

		if (!skipDialog)
		{
			system("Color 20");
			system("Color 02");
			system("Color 20");
			system("Color 02");

			Report("DESIGNATION ACCEPTED", 1);
			Report("ACCESS KEY REQUIRED: ", 1);



			for (int i = 0; i < 10; i++)
			{


				cout << "*";
				Sleep((rand() % 400 + 1) * 2);

			}

			cout << endl;

			for (int k = 0; k < 2; k++)
			{
				for (int i = 0; i < 5; i++)
				{
					cout << "\b";
					cout << loading[i];
					Sleep(200);

				}
			}

			system("Color 20");
			system("Color 02");
			system("Color 20");
			system("Color 02");


			Report("KEY VERIFIED", 1);

			cout << endl;

			Report("INITIALIZING CONNECTION", 1);

			for (int i = 0; i < 15; i++)
			{
				Sleep(100);
				cout << ".";
			}
			for (int i = 0; i < 15; i++)
			{
				Sleep(50);
				cout << ".";
			}


			for (int i = 0; i < 1000; i++)
			{
				cout << endl;

				for (int i = 0; i < 100; i++)
				{

					cout << rand() % 2;


				}
			}

			system("cls");
			for (int i = 0; i < 3; i++)
			{
				Sleep(150);
				cout << "*SYSTEM ACCESS GRANTED*";
				Sleep(150);
				system("cls");
			}
			system("Color 09");
			Report("-*H.E.R.O.S. COMMUNICATION NETWORK*-", 0);


			cout << endl;

			Report("INCOMING COMMUNICATION FROM COMMAND.......", 1);

			cout << endl;


			Report(name, 1);
			Report("This is Commander Nemlock.", 1);
			Report("The ship has been infiltrated by a hostile alien race, designation: Trolls.", 1);
			Report("We require some items from Cargo Bay Alpha to rectify this situation.", 1);
			Report("Luck would have it that you were assigned to unclog the toilet in the cargo bay head.", 1);
			Report("It is very important that you get the Midas Key to the bridge ASAP.", 1);
			Report("The Trolls are a strange species.", 1);
			Report("They were designated Trolls by fleet command because they resemble the mythological trolls of Earth.", 1);
			Report("They resemble them in appearance and in behavior.", 1);
			Report("If you encounter a Troll on the way to the bridge, they will will demand a toll.", 1);
			Report("They will demand your most valuable item.", 1);
			Report("This is why it is imperitive that you obfuscate your inventory.", 1);
			Report("Retrieve the Midas Key along with two other items in the cargo hold and give them all new designations.", 1);
			Report("This may be enough to fool any Trolls you meet along the way.", 1);
			Report("If the Bridge Troll does not get his toll, he will claim the souls of everyone aboard the Opposition.", 1);
			Report("Now hurry up, and don't screw this up like you did with the Valkyre, or you'll be scrubbing toilets in Hell!", 1);


			answerLoop = 1;
			while (answerLoop)
			{
				cout << endl << endl << "ACCEPT MISSION (y/n) ";
				cin >> answer;
				answerCap = toupper(answer);

				switch (answerCap)
				{
				case 'Y':
					answerLoop = false;

					break;
				case 'N':
					answerLoop = false;
					Report("You have doomed the entire ship and yourself, you are dead. You are the worst cadet the fleet has ever known!", 1);
					Continue(&restart, &exiGame);
					break;

				default:
					system("Color 40");
					system("Color 04");
					system("Color 40");
					system("Color 09");
					Report("INVALID ENTRY", 1);
					answerLoop = true;
				}
			}
			if (restart)
			{
				continue;
			}
			if (exiGame)
			{
				return 0;
			}


			system("Color 90");
			system("Color 09");
			system("Color 90");
			system("Color 09");
			system("cls");
			system("Color 02");
			Report("LOADING H.E.R.O.S. NARRATION APPLICATION", 0);
			for (int i = 0; i < 15; i++)
			{
				Sleep(100);
				cout << ".";
			}
			for (int i = 0; i < 15; i++)
			{
				Sleep(50);
				cout << ".";
			}

			system("cls");
			for (int i = 0; i < 3; i++)
			{
				Sleep(150);
				cout << "*H.E.R.O.S. NARRATION APPLICATION LOADED SUCCESSFULLY*";
				Sleep(150);
				system("cls");
			}

			system("Color 17");
			Report("-*H.E.R.O.S. NARRATION APPLICATION*-", 0);
			cout << endl;
			Report("You stare at the monitor in disbelief that you finally have the chance to redeem yourself.", 1);
			Report("The simple missunderstanding with the Valkyre has literally sent your career straight to the toilet.", 1);
			Report("You have always known yourself to be a hero, and now everyone else will know it too.", 1);
			Report("It's all down to getting the Midas Key to the Bridge Troll.", 1);
			Report("A Mission worty of a Legendary hero such as you!", 1);
			Report("You could get promoted straight to captain!", 1);
			Report("The Valkyre will sing of your majesty so loudly, they will hear the echos in Valhalla!", 1);
			Report("Susan from Engineering might actually acknowledge your existance now!", 1);
			Report("Mommy will finally love you!", 1);
			Report("You will finally have friends!", 1);
			Report("Well, friends that are of high enough quality for what you will become.", 1);
			Report("Everyone else though, they will pay!", 1);
			Report("They will ALL pay!", 1);
			Report("They will all rue they day they didn't give you the respect you deserve!", 1);
			Report("One by one you will hunt them down, there will be nowhere to hide! ", 1);
			Report("They will get all get it quickly though, you are no monster.", 0);
			Report("Except for maybe you are?!?!", 0);
			Report("NO ONE KNOWS YOU AND NO ONE CAN CHALLENGE YOU!", 0);
			Report("YOU ARE A GOD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", 0);

			system("cls");

			system("Color 71");
			system("Color 17");


			Report("USER INPUT [INTROSPECTION DISABLED]", 0);
			system("Color 71");
			system("Color 17");
			system("Color 71");
			system("Color 17");
			system("cls");

			Report("-*H.E.R.O.S. NARRATION APPLICATION*-", 0);
			cout << endl;
			Report("You start digging through cargo boxes.", 1);
			Report("After a short time of reading and opening cargo, you find the Midas Key.", 1);
			Report("You put the Midas into your personal pocket dimention carrying case.", 1);
			Report("You Load H.E.R.O.S. Inventory and proceed to give it a false name.", 1);
		}
		inventory[0] = { "MidasKey" };


		item = Inventory();


		system("Color 17");
		system("cls");
		Report("-*H.E.R.O.S. NARRATION APPLICATION*-", 0);
		cout << endl;

		if (item != "NOTHING")
		{
			Report("YOU CANNOT USE ", 1);
			Report(item, 0);
			Report(" HERE!", 0);
		}

		Report("You also grab a worthless sand crystal from the last planet the Opposition had visited.", 1);
		inventory[1] = { "SandCrystal" };

		item = Inventory();

		system("Color 17");
		system("cls");
		Report("-*H.E.R.O.S. NARRATION APPLICATION*-", 0);
		cout << endl;

		if (item != "NOTHING")
		{
			Report("YOU CANNOT USE ", 1);
			Report(item, 0);
			Report(" HERE!", 0);
		}

		Report("In a hurry as to not upset the Commander, you take your plunger as the third item.", 1);
		inventory[2] = { "Plunger" };

		item = Inventory();

		system("Color 17");
		system("cls");
		Report("-*H.E.R.O.S. NARRATION APPLICATION*-", 0);
		cout << endl;

		if (item != "NOTHING")
		{
			Report("YOU CANNOT USE ", 1);
			Report(item, 0);
			Report(" HERE!", 0);
		}

		system("Color 17");
		system("cls");
		Report("-*H.E.R.O.S. NARRATION APPLICATION*-", 0);
		cout << endl;

		Report("As you head to the Cargo Bay door, you find an interesting cargo box.  Labeled Troll", 1);
		Report("To round out your inventory, you pick up Troll Repellant, a Troll Doll, and a Trolls Movie.", 1);

		inventory[3] = { "TrollRepellant" };
		inventory[4] = { "TrollDoll" };
		inventory[5] = { "TrollsMovie" };

		item = Inventory();

		system("Color 17");
		system("cls");
		Report("-*H.E.R.O.S. NARRATION APPLICATION*-", 0);
		cout << endl;

		if (item != "NOTHING")
		{
			Report("YOU CANNOT USE ", 1);
			Report(item, 0);
			Report(" HERE!", 0);
		}

		Report("You step out of Cargo Bay Alpha.", 1);
		Report("The corridors are empty.", 1);
		Report("You swallow your fear and make way toward the bridge.", 1);
		Report("You turn a corner and are face to face with a Troll!", 1);
		Report("The Troll looks at your item list, that you left open for some reason.", 1);

		for (int i = 0; i < 10; i++)
		{

			if ("MidasKey" == inventory[i])
			{
				Report("You were stupid enough to not rename the Midas Key.", 1);

				system("Color 40");
				system("Color 04");
				system("Color 40");
				system("Color 04");

				Report("You got beat down.", 1);
				Report("The wrong Troll made off with the Midas Key", 1);
				Report("Your vision starts to fade...", 1);
				Report("YOU ARE DEAD", 1);

				Continue(&restart, &exiGame);
				break;
			}
			if ("TrollRepellant" == inventory[i])
			{
				Report("Why would you not rename the Troll Repellant?", 1);

				system("Color 40");
				system("Color 04");
				system("Color 40");
				system("Color 04");

				Report("You got utterly destroyed.", 1);
				Report("A full can of Troll Repellant gets sprayed into your bruised face.", 1);
				Report("Your vision starts to fade...", 1);
				Report("YOU ARE DEAD", 1);

				Continue(&restart, &exiGame);
				break;
			}
			if ("TrollsMovie" == inventory[i])
			{
				Report("The Troll gets extremely excited.", 1);

				system("Color 40");
				system("Color 04");
				system("Color 40");
				system("Color 04");

				Report("You take a hit right to the mouth", 1);
				Report("The Troll gleefully hops away with the Trolls Movie", 1);
				Report("Your vision starts to fade...", 1);
				Report("YOU ARE DEAD", 1);

				Continue(&restart, &exiGame);
				break;
			}

		}


		if (restart)
		{
			continue;
		}
		if (exiGame)
		{
			return 0;
		}

		Report("The Troll looks confused.", 1);
		Report("'Dont see Shiney Key, give me valuable to pass!'", 1);


		item = Inventory();

		system("Color 17");
		system("cls");
		Report("-*H.E.R.O.S. NARRATION APPLICATION*-", 0);
		cout << endl;

		if (item == inventory[0])
		{
			Report("Your stupidity is impressive.", 1);
			Report("The Troll takes pity on you and straight up murders you.", 1);
			Continue(&restart, &exiGame);

		}
		if (item == inventory[1])
		{
			inventory[1] = { "" };
			Report("The Troll cautiously takes the Sand Crystal.", 1);
			Report("Without any warning, the Troll shoves it into its mouth!", 1);
			Report("You hear teeth shatter as the Troll chews furiously and a strained gulp as the Troll swallows teeth and all.", 1);
			Report("The Troll falls to the ground dead with a smile on its face.", 1);
		}
		if (item == inventory[2])
		{
			inventory[2] = { "" };
			Report("The troll cautiously takes the Plunger.", 1);
			Report("You are unfamiliar with Troll facial expressions, but you see what you believe to be wonder in its eyes.", 1);
			Report("'Now me be king!'", 1);
			Report("The Troll places the filty Plunger on its head.", 1);
			Report("It then proceeds to march down the corridor, in no specific direction.", 1);
			Report("It disappears around a corner, singing to itself.", 1);
			Report("You realize as the Troll departs, that you had started to respect that Plunger.", 1);
			Report("You shed a lone tear for your lost comrade.", 1);
		}
		if (item == "NOTHING")
		{
			Report("You trip and die or whatever.", 1);
			Report("You Stupid idiot!", 1);
			Continue(&restart, &exiGame);
		}
		else
		{
			Report("The Troll judges you.", 1);
			Report("Harshly.", 1);
			Report("The Troll looks at you with pity and walks off.", 1);
		}
		if (restart)
		{
			continue;
		}
		if (exiGame)
		{
			return 0;
		}

		Report("You collect yourself after that strangeness.", 1);
		Report("You continue to the bridge with a newfound confidence.", 1);
		Report("You had survived an encounter with a Troll!", 1);
		Report("You are going to save the ship afterall.", 1);
		Report("You arrive at the bridge door.", 1);
		Report("Anxiety overtakes you, this is not your first time on the bridge.", 1);
		Report("Every previous visit was to be reprimanded by Commander Nemlock.", 1);
		Report("You count to ten and calm yourself down.", 1);
		Report("You punch in your access code and step onto the bridge..........", 1);
		Sleep(3000);

		system("cls");
		Report("-*H.E.R.O.S. NARRATION APPLICATION*-", 0);
		cout << endl;

		Report("Bridge Troll:'Ah! How perfectly punctual!'", 1);
		Report("Bridge Troll:'I'm elated the treasured commodity has finally arrived!'", 1);
		Report("Bridge Troll:'It better justify the interuption to my mastication!'", 1);
		Report("Nemlock:'It's about time Cadet!  This thing was about to chow down on me!'", 1);
		Report("You take in your surroundings.", 1);
		Report("This Troll is much larger than the one you saw in the corridor.", 1);
		Report("You struggle to understand what this Troll is saying as well.", 1);
		Report("An angry Commander Nemlock is tied up and covered in an unknown powder.", 1);
		Report("You see a giant bottle next to the Commander, the label read 'Garlic Powder.'", 1);
		Report("You see no connection.", 1);
		Report("Nemlock:'Stop standing there zoning out, give him the damn Midas Key!'", 1);
		Report("Bridge Troll:'Yes, give me your most prized possesion!'", 1);
		Report("Here it is, your moment of truth.", 1);

		while (1)
		{
			item = Inventory();

			system("Color 17");
			system("cls");
			Report("-*H.E.R.O.S. NARRATION APPLICATION*-", 0);
			cout << endl;

			if (item == inventory[0])
			{
				Report("You hand the Bridge Troll the Midas Key.", 1);
				Report("Bridge Troll:'Interesting!  This is a priceless trinket!'", 1);
				Report("Nemlock:'You got what you wanted, now get off the ship!", 1);
				Report("Bridge Troll:'I must appologize, I must not have realized that you grasp of language was inadequate.'", 1);
				Report("Bridge Troll:'I asked for your most prized possesion, you delivered to me a Cadet you dispise.'", 1);
				Report("Nemlock:'Yes, but this worthless Cadet delivered to you the most valuable thing on the ship!'", 1);
				Report("Bridge Troll:'You have failed on many levels.'", 1);
				Report("Bridge Troll:'First of all, valuable does not equate to prized.'", 1);
				Report("Bridge Troll:'Second, I asked you both for your most prized possesion.'", 1);
				Report("The Bridge Troll grins literally from ear to ear.", 1);
				Report("Bridge Troll:'You delivered a Cadet, the Cadet delievered a trinket.'", 1);
				Report("Bridge Troll:'You must learn just because something is shiney doesn't make it valuable.'", 1);
				Report("The Bridge Trolls mouth opens wide and eats the Commander in one bite.", 1);
				Report("He then turns his hungry gaze towards you.", 1);
				if (inventory[1] == "")
				{
					Report("You just stand there as you become desert.", 1);
					Continue(&restart, &exiGame);
					break;
				}
				else
				{
					Report("The door to the bridge opens, and in comes a Troll with a plunger on its head.", 1);
					Report("Troll King:'I King now!  You no eat friend!  You bow!'", 1);
					Report("The Bridge Troll falls to the ground, praising the Plunger donning Troll.", 1);
					Report("Seconds later, both Trolls dissapear.", 1);
					Report("The ship is safe, but at what cost?", 1);
					Continue(&restart, &exiGame);
					break;

				}
			}
			if (item == inventory[1])
			{
				Report("You hand the Bridge Troll the Sand Crystal.", 1);
				Report("The Bridge Troll Stares at you in disbelief.", 1);
				Report("Commander Nemlock Stares at you in disbelief.", 1);
				Report("You die of embarassment.", 1);
				Continue(&restart, &exiGame);
				break;

			}
			if (item == inventory[2])
			{
				Report("You hand the Bridge Troll the Plunger.", 1);
				Report("The Bridge Troll Stares at you in disbelief.", 1);
				Report("Commander Nemlock Stares at you in disbelief.", 1);
				Report("Nemlock:'What the actual fu...'", 1);
				Report("Bridge Troll:'You have done it!  You have fulfilled the Troll bargain!'", 1);
				Report("Nemlock:'What the actual fu...'", 1);
				Report("Bridge Troll:'I now have your most prized possesion and I will now become Troll King!'", 1);
				Report("The Bridge Troll places the sewage covered Plunger on its head.", 1);
				Report("Nemlock:'What the actual fu...", 1);
				Report("The Troll King:'For your act, your ship and everyone aboard are guarenteed protection against any Troll!'", 1);
				Report("The Troll King:'No matter what, no Troll will ever be hostile towards any of you.'", 1);
				Report("The Troll King:'Literally nothing!'", 1);
				Report("The Troll King:'Now where is my son?  We shall depart at once'", 1);
				Report("You respond with a blank stare.", 1);
				Report("The Troll King:'Come now!  He is the only other Troll on board.'", 1);
				Report("You respond with a blank stare.", 1);
				Report("The Troll King:'He Looks just like me... but smaller.'", 1);
				Report("The Troll King:'He'll be looking around the ship for something shiney, he is just a child.'", 1);
				Report("You finally realize the connection.", 1);
				Report("You tell The Troll King what happened to his son.", 1);
				Report("The Troll King:'What the actual fu...'", 1);

				system("cls");
				system("Color 20");
				system("Color 02");
				system("Color 20");
				system("Color 02");

				Report("YOU WIN!!!YOU WIN!!!YOU WIN!!!YOU WIN!!!YOU WIN!!!YOU WIN!!!YOU WIN!!!YOU WIN!!!", 0);

				Sleep(3000);
				return 0;
				break;
			}
			if (item == "NOTHING")
			{
				Report("You hand the Bridge Troll Nothing", 1);
				Report("The Bridge Troll sighs", 1);
				Report("Bridge Troll:'Look, it takes forever to get through the narration, just try again.'", 1);
				continue;
			}
			else
			{
				Report("You hand the item to the Bridge Troll", 1);
				Report("Bridge Troll:'ALL HUMANS MUST DIE FOR THIS INSULT!!!'", 1);
				Continue(&restart, &exiGame);
				break;
			}
		}


		if (restart)
		{
			continue;
		}
		if (exiGame)
		{
			return 0;
		}

	}
}



