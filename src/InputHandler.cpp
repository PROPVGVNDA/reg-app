#include <InputHandler.h>

User InputHandler::GetNewUser(const std::vector<User>& existing_users)
{
	system("cls");
	std::string username, password;
	while (true)
	{
		std::cout << "Enter username: ";
		std::cin >> username;
		InputHandler::pValidateUsername(username);
		if (!InputHandler::pIsUsernameUnique(existing_users, username))
		{
			std::cout << "This username is already taken\n";
			std::cout << "Try again\n";
			continue;
		}
		std::cout << "Enter your password: ";
		std::cin >> password;
		return User{ username, password };
	}
}

User InputHandler::GetUserWithNewPassword(const std::string& username)
{
	system("cls");
	std::string newPassword;
	std::cout << "Enter new password: ";
	std::cin >> newPassword;
	return User{ username, newPassword };
}

std::pair<User, bool> InputHandler::GetExistingUser(const std::vector<User>& existing_users)
{
	const unsigned short attempts = 3;
	std::string tempUsername, tempPassword;
	while (true)
	{
		std::cout << "Enter username: ";
		std::cin >> tempUsername;

		if (tempUsername == "\\b")
		{
			system("cls");
			return { User(), false };
		}
		
		const auto it = std::find_if(existing_users.begin(), existing_users.end(), [&tempUsername](const User& user)
			{
				return tempUsername == user.GetUsername();
			});
		if (it == existing_users.end())
		{
			std::cout << "Username was not found, try again or enter \\b to go back\n";
			continue;
		}
		else
		{
			for (unsigned short i = 0; i < attempts; i++)
			{
				std::cout << "Enter password: ";
				std::cin >> tempPassword;
				if (it->GetPassword() == tempPassword)
				{
					return { *it, true };
				}
				std::cout << "Entered password is invalid, try again\n";
			}
			std::cout << "You have no attempts left\n";
			continue;
		}
	}
}

void InputHandler::pValidateUsername(std::string& username)
{
	const char chars[] = "\\|/\n\t-=+?.,<>&*()][{}";
	const auto charsLength(strlen(chars));
	for (unsigned short i = 0; i < charsLength; i++)
	{
		const auto iter(std::remove(username.begin(), username.end(), chars[i]));
		username.erase(iter, username.end());
	}
}

bool InputHandler::pIsUsernameUnique(const std::vector<User>& existingUsers, const std::string& username)
{
	for (const auto& user : existingUsers)
		if (user.GetUsername() == username)
			return false;
	return true;
}


