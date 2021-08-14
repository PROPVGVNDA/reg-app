#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <fstream>

class User
{
public:
	User() = default;
	explicit User(const std::string& t_Username, const std::string& t_Password);
	const std::string& GetUsername() const;
	const std::string& GetPassword() const;
	friend std::ofstream& operator<<(std::ofstream& stream, const User& user);
private:
	std::string m_Username;
	std::string m_Password;
};

#endif