#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QObject>
#include "DataStructs.h"

class Transaction
{
public:
    Transaction();
    Transaction(QString, double, QString, Store, Category, bool, Member);
    Transaction(QString, double, QString, QString, QString, bool, QString);
    Transaction(const Transaction&);

    inline void setDate (QString nD)    { date          = nD;   }
    inline void setStore(Store nS)      { store         = nS;   }
    inline void setDesc (QString nDsc)  { description   = nDsc; }
    inline void setAmt  (double nAmt)   { amount        = nAmt; }
    inline void setCtg  (Category ctg)  { category      = ctg;  }
    inline void setMbr  (Member mbr)    { member        = mbr;  }
    inline void setShr  (bool shr)      { shared        = shr;  }

    inline auto getDate () -> QString   { return date;          }
    inline auto getStore() -> Store     { return store;         }
    inline auto getDesc () -> QString   { return description;   }
    inline auto getAmt  () -> double    { return amount;        }
    inline auto getCtg  () -> Category  { return category;      }
    inline auto getMbr  () -> Member    { return member;        }
    inline auto getShr  () -> bool      { return shared;        }

private:
    QString     date, description;
    double      amount;
    Store       store;
    Category  category;
    Member      member;
    bool        shared;
};

#endif // TRANSACTION_H
