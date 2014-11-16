//developed by Lysenko Vladyslav
#include "Operation.h"

//Operation constructor
Operation::Operation(Account& fr,const string& from,const string& to,const double& amount):
    _accountFrom(fr),_numberFrom(from), _numberTo(to),_amount(amount){
        return;
}
