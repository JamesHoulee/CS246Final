#ifndef _IMPROVABLE_H_
#define _IMPROVABLE_H_

#include "Property.h"

class ImprovableProperty : public Property {
	int numImprovements;

	public:
		ImprovableProperty (const std::string &name, int price, int base_rent);
		
		int getNumImprov () const;
		void upgrade (int num);
		void downgrade (int num);
		int getValue () const override;
		int getRent () const override;
		void notify (Subject & whoNotified) override;
};

#endif

