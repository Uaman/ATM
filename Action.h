#pragma once;
#include <iostream>
#include "Account.h"
using namespace std;

//class Action{
//	public:
//		void action(const double&, const Account&, const Account&){};
//		virtual ~Action();
//		Action& operator=(const Action&);
//		Action(const Action&);
//	private:
//		virtual void  do_action(const double&, const Account&, const Account&)=0;
//};	
//
//
//
//class  WithdrawMoney: public Action{ 
//  private:
//     virtual void do_action(const double&, const Account&, const Account& to);       
//	 WithdrawMoney(const WithdrawMoney&);
//     WithdrawMoney& operator=(const      WithdrawMoney&);
//  public:
//	  ~WithdrawMoney(){};
//};
//
//
//class MoneyOrder: public Action{
//	private:
//		virtual void do_action(const double&, const Account&, const Account&);
//		MoneyOrder(const MoneyOrder&);
//		MoneyOrder& operator=(const MoneyOrder&);
//	public:
//		~ MoneyOrder(){};
//};
//
//class  SurplusProcessing: public Action{
//	private:
//		virtual void  do_action(const double& am, const Account&, const Account&);
//		SurplusProcessing(const 
//		SurplusProcessing&);
//		SurplusProcessing& operator=(const SurplusProcessing&);
//	public:
//		~ SurplusProcessing(){};
//};
