#include <Controller.h>
#include <InputHandler.h>

const char Controller::kFilename[] = "Users.txt";

void Controller::RegisterNewUser(std::vector<User>& existing_users)
{
	system("cls");
	auto newUser = InputHandler::GetNewUser(existing_users);
	std::ofstream stream;
	stream.open(kFilename, std::ofstream::app);
	stream << newUser;
	existing_users.emplace_back(std::move(newUser));
}

std::pair<User, bool> Controller::LogInUser(const std::vector<User>& existing_users)
{
	return InputHandler::GetExistingUser(existing_users);
}

std::vector<User> Controller::LoadExistingUsers()
{
	
	std::ifstream stream;
	stream.open(kFilename);
	if (!stream)
	{
		std::ofstream tempStream;
		tempStream.open(kFilename);
		tempStream.close();
		return std::vector<User> {};
	}
	std::vector<User> users;
	std::string tempUsername, tempPassword;
	while (stream >> tempUsername >> tempPassword)
	{
		users.emplace_back(tempUsername, tempPassword);
	}
	return users;
}

void Controller::ChangePassword(const User& user, std::vector<User>& existing_users)
{
	system("cls");

	const auto username = user.GetUsername();
	const auto oldPassword = user.GetPassword();
	const auto it = std::remove_if(existing_users.begin(), existing_users.end(), [&username](const auto& tempUser)
		{
			return username == tempUser.getUsername();
		});
	existing_users.erase(it, existing_users.end());

	auto userWithNewPassword = InputHandler::GetUserWithNewPassword(username);
	existing_users.emplace_back(userWithNewPassword);

	std::ifstream inputStream;
	std::ofstream outputStream;
	inputStream.open(kFilename);
	outputStream.open("UsersTemp.txt");
	std::string tempUsername, tempPassword;
	while (inputStream >> tempUsername >> tempPassword)
	{
		if (username == tempUsername && oldPassword == tempPassword) tempPassword = userWithNewPassword.GetPassword();
		outputStream << tempUsername << " " << tempPassword << '\n';
	}

	inputStream.close();
	outputStream.close();
	std::remove(kFilename);
	std::rename("UsersTemp.txt", kFilename);
}
