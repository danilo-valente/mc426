#ifndef USER_DAO_H
#define USER_DAO_H

#include <EDB.h>
#include <SD.h>

class UserDAO {
private:
	Strig fileName;
	void writer(unsigned long address, byte data);
	byte reader(unsigned long address);
public:
	UserDAO(String fileName);
	virtual ~UserDAO();

	void insert(User);
	User& read();
};

#endif /* USER_DAO_H */
