#ifndef _IMPROVABLE_H_
#define _IMPROVABLE_H_

#include "Property.h"

class ImprovableProperty : public Property {
	
	std::vector<int> tuition;

	public:
		ImprovableProperty (const std::string &name, int purch_cost, int up_cost, std::vector<std::string> set, std::vector<int> tuition);
		
		int getNumImprov () const;
		void upgrade (int num);
		void downgrade (int num);
		int getValue () const override;
		virtual int getRent () const override;
		
};

#endif

