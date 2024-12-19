

#include "arraylist.h"

template<class ItemType>
ArrayList<ItemType>::ArrayList() : maxCount(DEFAULT_CAPACITY), itemCount(0){}

template<class ItemType>
ArrayList<ItemType>::ArrayList(const ArrayList<ItemType>& aList){
	maxCount = DEFAULT_CAPACITY;
	items = aList;
	itemCount = sizeof(items);
}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const{
	return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry){
	bool ableToInsert = (newPosition >= 1) &&
                            (newPosition <= itemCount + 1) &&
                            (itemCount < maxCount);
	if (ableToInsert){
		for(int pos = itemCount + 1; pos > newPosition; pos--){
			items[pos] = items[pos - 1];
        	}
        	items[newPosition] = newEntry;
        	itemCount++;
    	}
    	return ableToInsert;
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position){
	if ((position > itemCount) || (position < 1)){
		return false;
	}

	for (int i = position; i < itemCount; i++) {
		items[i] = items[i + 1];
	}
	itemCount--;
    return true;
}

template<class ItemType>
void ArrayList<ItemType>::clear(){
	itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
	bool ableToGet = (position >= 1) && (position <= itemCount);

	if (ableToGet){
		return items[position];
	} 
	throw "Item not found";
} 

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry){
    ItemType temp;
	if ((position > itemCount) || (position < 1)){
		return temp;
	}

	items[position] = newEntry;
    	
    return newEntry;
}