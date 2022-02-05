#ifndef MEMBER_H
#define MEMBER_H

#include <QObject>

class Member
{
public:
    Member();
    Member(QString nFirstName) { firstName = nFirstName; }
    inline bool operator==(const Member &rhs) const {return rhs.firstName == firstName;}

    inline QString  getFullName() { return firstName + lastName; }
    inline QString  getFirstName() { return firstName; }

    inline void     setFirstName(QString first) { firstName = first; }
    inline void     setLastNme(QString last) { lastName = last; }

    inline void     setSalary(double nSalary) { salary = nSalary; }
    inline double   getSalary() { return salary; }
private:
    // Elements
    QString firstName, lastName, role;
    double salary;
    // Table Elements TBD
    QString tableName;

};

#endif
