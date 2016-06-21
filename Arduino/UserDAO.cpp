#include "UserDAO.h"

UserDAO::UserDAO(string fileName) : fileName(fileName){
    Serial.begin(9600);

    Serial.print("Initializing SD card...");

    pinMode(10, OUTPUT);

    if (!SD.begin()) {
        Serial.println("initialization failed!");
        return;
    }

    Serial.println("initialization done.");

    dbFile = SD.open(fileName, FILE_WRITE);

    db.create(0, TABLE_SIZE, sizeof(User));
}

void UserDAO::writer(unsigned long address, byte data)
{
    dbFile.seek(address);
    dbFile.write(data);
    dbFile.flush();
}

byte UserDAO::reader(unsigned long address)
{
    dbFile.seek(address);
    return dbFile.read();
}

UserDAO::insert(User user) {
    db.appendRec(EDB_REC user);
}

User& UserDAO::read() {
    User user;
    Serial.print("Record Count: "); Serial.println(db.count());
    db.readRec(0, EDB_REC user);
}
