//
// You must provide your implementation of maxGroceryBox() and all
// helper functions in this file.
//

#include "grocery.h"

// You may prototype helper functions here and implement them below

void helper(const std::vector<GItem>& inventory, unsigned int index, int weight_limit, int currweight, 
 std::vector<GItem> & maxvector, std::vector<GItem> & currvector, int & maxvalue, int curvalue);
std::vector<GItem> maxGroceryBox(const std::vector<GItem>& inventory, int weight_limit)
{
    // TODO implement!

	std::vector<GItem> cur;
	std::vector<GItem> result;
	int max=0;
	helper(inventory, 0, weight_limit, 0, result, cur, max, 0);
	return result;

}


void helper(const std::vector<GItem>& inventory, unsigned int index, int weight_limit, int currweight, 
 std::vector<GItem> & maxvector, std::vector<GItem> & currvector, int & maxvalue, int curvalue){

	if(index==inventory.size()){

		if(curvalue>maxvalue){
			//update the maxvector
			maxvector.clear();
			for(unsigned int i=0;i<currvector.size();i++){
				maxvector.push_back(currvector[i]);
			}

			//update the max value
			maxvalue=curvalue;
		}
		return;
	}
	
	helper(inventory, index+1, weight_limit, currweight, maxvector, currvector, maxvalue, curvalue);

	if((currweight+inventory[index].weight)>weight_limit){

		if(curvalue>maxvalue){

			//update the maxvector
			maxvector.clear();
			for(unsigned int i=0;i<currvector.size();i++){
				maxvector.push_back(currvector[i]);
			}

			//update the max value
			maxvalue=curvalue;	
		}
		return;
	}

	//use a new vector so dont have to pop back
	std::vector<GItem> add;
	for(unsigned int i=0;i<currvector.size();i++){
		add.push_back(currvector[i]);
	}
	add.push_back(inventory[index]);
	helper(inventory, index+1, weight_limit, currweight+inventory[index].weight, 
		maxvector, add, maxvalue, curvalue+inventory[index].value);
}


