#include <Controller.h>
#include <User.h>

// Clears stream if User input is invalid
inline void ClearAppInput();

int main()
{
	auto existingUsers = Controller::LoadExistingUsers();
	std::cout << "REGISTRATION FORM" << std::endl;
	std::pair<User, bool> loggedUser{ User(), false };
	while (true)
	{
		if (!loggedUser.second)
		{
			int option;
			std::cout << "1. Register\n";
			std::cout << "2. Log In\n";
			std::cout << "3. Exit\n";
			if (std::cin >> option)
			{
				system("cls");
				switch (option)
				{
				case 1:
					Controller::RegisterNewUser(existingUsers);
					break;
				case 2:
					loggedUser = Controller::LogInUser(existingUsers);
					break;
				case 3:
					return 0;
				default:
					system("cls");
					std::cout << "Wrong Option\n";
					continue;
				}
			}
			else
			{
				ClearAppInput();
				continue;
			}
		}
		else
		{
			auto user(loggedUser.first);
			system("cls");
			std::cout << "Hello, " << user.GetUsername() << "\n";
			std::cout << "1. Log Out\n";
			std::cout << "2. Change Password\n";
			std::cout << "3. Exit\n";
			int option;
			if (std::cin >> option)
			{
				system("cls");
				switch (option)
				{
				case 1:
					loggedUser.second = false;
					break;
				case 2:
					Controller::ChangePassword(user, existingUsers);
					loggedUser.second = false;
					system("cls");
					break;
				case 3:
					return 0;
				default:
					std::cout << "Wrong option\n";
					continue;
				}
			}
			else
			{
				ClearAppInput();
				continue;
			}
		}
	}
}

inline void ClearAppInput()
{
	std::cout << "Invalid option, try again\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("cls");
}