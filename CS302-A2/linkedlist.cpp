
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
	// enforce precondition
	if((position >= 1) && (position <= itemCount)){
		// Count from the beginning of the chain
		Node<ItemType>* curPtr = headPtr;
		for (int skip = 1; skip < position; skip++){
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
	return nullptr;
} 

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0){}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
    headPtr = nullptr;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
	return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
    if (newPosition < 1) {
		cout << "Invalid position";
		return false;
	}

	Node<ItemType>* currPtr = new Node<ItemType>(newEntry);	

	if (newPosition == 1) {
		currPtr->setNext(headPtr);
		headPtr = currPtr;
		itemCount++;
	}
	else{
		Node<ItemType>* newPtr = headPtr;
		for (int i = 1; i < newPosition -1; i++){
			newPtr = newPtr->getNext();
	}

	currPtr->setNext(newPtr->getNext());
	newPtr->setNext(currPtr);
	itemCount++;

	}
    return true;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove){
		Node<ItemType>* ptrToDelete = nullptr;
		if (position == 1){
			// Remove the first node in the chain
			ptrToDelete = headPtr; // Save pointer to node 
			headPtr = headPtr->getNext();// save pointer to next node
		}
		else{
			// Find node that is before the one to remove
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			// Point to node to remove
			ptrToDelete = prevPtr->getNext();
			// Disconnect indicated node from chain by connecting the prior node with the one after
			prevPtr->setNext(ptrToDelete->getNext());
		}

		ptrToDelete->setNext(nullptr);
		delete ptrToDelete;
		ptrToDelete = nullptr;
		itemCount--; // Decrease count of entries
	}
	return ableToRemove;
}

template<class ItemType>
void LinkedList<ItemType>::clear(){   // Got this function from GeeksForGeeks
    Node<ItemType>* ptrToDelete = headPtr;
	while (ptrToDelete != nullptr) {
		Node<ItemType>* currPtr = ptrToDelete->getNext();
		delete ptrToDelete;
		ptrToDelete = currPtr;
	}
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {

    Node<ItemType>* currentNode = headPtr;

    for (int skip = 1; skip < position; skip++) {
        currentNode = currentNode->getNext();
    }

	return currentNode->getItem();


} 

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry){
	// enforce precondition
	bool ableToReplace = (position >= 1) && (position <= itemCount);
	if (ableToReplace){
		Node<ItemType>* nodePtr = getNodeAt(position);
		ItemType oldEntry = nodePtr->getItem();
		nodePtr->setItem(newEntry);	
		return oldEntry;	
	} 
	throw "Item not found";
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
	clear();
} 