// uintptr_t --> alias for unsigned integer type capable of holding a pointer

#include "serialization.hpp"

uintptr_t serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}

int main(){
	Data myData;
	myData.str = "Hello World";
	myData.num = 12345;

	uintptr_t myUint;
	myUint = serialize(&myData);
	//std::cout << std::hex << myUint << std::dec << std::endl;
	Data *returnData = deserialize(myUint);

	if (&myData == returnData){
		std::cout << "\nSuccesfull serialize and deserialize process\n";
		std::cout << "MyData     : " << myData.str << "  " << myData.num << "  Address: " << &myData << std::endl;
		std::cout << "ReturnData : " << returnData->str << "  " << returnData->num << "  Address: " << returnData << std::endl;
	}
}
