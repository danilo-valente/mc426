#ifndef USER_H
#define USER_H

class User {
public:
	User(String login, String senha, String nome);
	virtual ~User();
	String login;
	String senha;
	String nome;
};

#endif /* USER_H */
