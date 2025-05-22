#include "DynamicArray.h"

//copy ctor
//creates a deep copy of the object 
DynamicArray::DynamicArray(const DynamicArray& other) {
	elements = other.elements;
	Array = new Potions[elements];
	for (int i = 0; i < elements; i++) {
		Array[i] = other.Array[i];
	}
}

//move ctor 
//steal the data from another object
DynamicArray::DynamicArray(DynamicArray&& other) noexcept {
	elements = other.elements;
	Array = other.Array;

	other.Array = nullptr;
	other.elements = 0;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
	if (this == &other) {
		return *this;
	}

	delete[] Array;

	elements = other.elements;
	Array = new Potions[elements];

	for (int i = 0; i < elements; i++) {
		Array[i] = other.Array[i];
	}
	return *this;
}

//move assingment operator
//steals resources from a object
DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept{
	if (this == &other) {
		return *this;
	}
	delete[] Array;
	elements = other.elements;
	Array = other.Array;

	other.Array = nullptr;
	other.elements = 0;

	return *this;
}

// searches the array for a matching potion
// Returns the index of the first match if found or -1 if no match 
int DynamicArray::find(const Potions& other) {
	for (int i = 0; i < elements; i++) {
		if (Array[i] == other) {
			return i;
		}
	}
	return -1;
}

Potions DynamicArray::find(int index) const{
	if (index < 0 || index >= elements) {
		throw std::out_of_range("Index out of range");
	}
	return Array[index];
}



int DynamicArray::find(const std::string& potionName) const{
	for (int i = 0; i < elements; i++) {
		if (Array[i].getName() == potionName) {
			return i;
		}
	}
	return -1;
}


void DynamicArray::insert(const Potions& other) {//insert new object into the end of the dynamic array
	int newElements = elements + 1;

	if (find(other) != -1) {
		//std::cout << "Potion already exists. Skipping insertion.\n";
		return;
	}

	if (Array == nullptr) {
		Array = new Potions[1];
		Array[0] = other;
		elements = 1;
		return;
	}

	//std::cout << elements << "\n";//debug statement

	Potions* newArray = new Potions[newElements];

	for (int i = 0; i < elements; i++) {
		newArray[i] = Array[i];
	}

	//std::cout << elements << "\n"; //debug statement

	newArray[elements] = other;

	delete[] Array;

	Array = newArray;
	elements = newElements;
}

void DynamicArray::insert(const std::string& n, const std::string& d, const std::string& p, int c) {  //insert strings and a integer 

   // Create a new Potions object using the converted cost  
   Potions newPotion(n, d, p, c);  

   // Use the existing insert method to add the new potion  
   insert(newPotion);  
}

void DynamicArray::display(int viewElement) const {
	const Potions& potion = Array[viewElement];
	if (viewElement >= elements) {
		return;
	}
	std::cout << "Potion Name: " << potion.getName() << "\n"
		<< "Description: " << potion.getDesc() << "\n"
		<< "Potency: " << potion.getPotency() << "\n"
		<< "Cost: " << potion.getCost() << "\n"
		<< "Formatted cost: "; const_cast<Potions&>(potion).displayFormattedCost(const_cast<Potions&>(potion));

}

void DynamicArray::display() const {
	for (int i = 0; i < elements; i++) {
		const Potions& potion = Array[i]; // Access the correct element
		std::cout << "Potion Name: " << potion.getName() << "\n"
			<< "Description: " << potion.getDesc() << "\n"
			<< "Potency: " << potion.getPotency() << "\n"
			<< "Cost: " << potion.getCost() << "\n"
			<< "Formatted cost: ";
		const_cast<Potions&>(potion).displayFormattedCost(const_cast<Potions&>(potion));
		std::cout << "\n"; // Add a newline for better readability
	}
}

void DynamicArray::Delete(const Potions& other) {
	int index = find(other);
	if (index == -1) {
		std::cout << "Potion not found ";
	}

	int newElements = elements - 1;

	Potions* newArray = new Potions[newElements];

	for (int i = 0, j = 0; i < elements; i++) {
		if (i != index) {
			newArray[j++] = Array[i];
		}
	}

	delete[] Array;
	elements = newElements;
	Array = newArray;
}

void DynamicArray::Delete(int other) {
	int index = other;
	if (index >= elements) {
		std::cout << "Potion not found ";
		return;
	}

	int newElements = elements - 1;

	Potions* newArray = new Potions[newElements];

	for (int i = 0, j = 0; i < elements; i++) {
		if (i != index) {
			newArray[j++] = Array[i];
		}
	}

	delete[] Array;
	elements = newElements;
	Array = newArray;
}