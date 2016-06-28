#ifndef USER_H
#define USER_H

#include <Arduino.h>

class User {
public:
	User(String login, String senha, String nome);
	virtual ~User();
	String username;
	String password;
	String name;
};

#endif /* USER_H */
