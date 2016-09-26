/* CS300 Prog 01- Store Inventory
 * Last Update: 09/14/2016
 * 
 */
 
 #include <iostream>
 #include <fstream>
 #include <string> 
 
 using namespace std;
 
 class Part
 {
	 public:
		int partNum;
		string description;
		int quantity;
		float unitPrice;
};

void printAllParts(Part [], int);
void addPart(Part [], int&);
void modifyPart(Part [], int);
void total (Part [], int count);

int main()
{
	
	
	Part arr[100]; //this is the array to hold odjects
	int count = 0; //counter for the array
	
	
	//try to read from file here
	
	std::fstream file("inventory.txt", std::ios::in);
	
	if(file)
	{
		int i=0; //index
		int partNum = 0;
		std::string description = "";
		int quantity = 0;
		float unitPrice = 0;
		
		//use a loop to keep reading file
		//if reading file fails or goes over the
		//limit of the array the loop will end
		while(file >> partNum && i<100)
		{
			//to skin the /n 
			file.ignore();
			std::getline(file, description);
			file >> quantity;
			file >> unitPrice;	
			
			// copy info from local var to array
			arr[i].partNum = partNum;
			arr[i].description = description;
			arr[i].quantity = quantity;
			arr[i].unitPrice = unitPrice;
			
			//increase index and counters
			i++;
			count++;
			
			
		}	
		//close file
		file.close();
	}
	
	//ask for a choice
	int choice=0;

	cout<<"**********************"<<endl;
	cout<<"1. Print the part"<<endl;
	cout<<"2. Creat a part"<<endl;
	cout<<"3. Modify a part"<<endl;
	cout<<"4. Print total"<<endl;
	cout<<"5. Exit the program"<<endl;
	cout<<"Please make a choice:";
	cin>> choice;	
	
	//check if the choice is valid
	while (cin.good() && choice != 5)
	{
		switch (choice)
		{
			case 1:
				printAllParts(arr, count);
				break;
				
			case 2:
				cin.ignore();
				addPart(arr, count);
				break;
				
			case 3:
				modifyPart(arr, count);
				break;
				
			case 4:
				total(arr, count);
				break;
			default:
				cout<<"Invalid choice"<<endl;
		}
		cout<<endl;
		cout<<"**********************"<<endl;
		cout<<"1. Print all parts"<<endl;
		cout<<"2. Creat a part"<<endl;
		cout<<"3. Modify a part"<<endl;
		cout<<"4. Print total"<<endl;
		cout<<"5. Exit the program"<<endl;
		cout<<"Please make a choice:";
		cin>> choice;
	}
			
	//end of prog, open/create txt file to write
	
	file.open("inventory.txt", std::ios::out);
	
	if(file)	//if file is good, then write to the file
	{	
		int i=0;
		int partNum = 0;
		std::string description = "";
		int quantity = 0;
		float unitPrice = 0;
		
		while (i < count)
		{
			//write each element to local var
			partNum = arr[i].partNum;
			description = arr[i].description;
			quantity = arr[i].quantity;
			unitPrice = arr[i].unitPrice;
			
			//write to file
			file << partNum<<std::endl;
			file << description<<std::endl;
			file << quantity<<std::endl; 
			file << unitPrice <<std::endl;
			
			i++; //increase index
		}
		file.close(); //close file
	}
	
 return 0;
}

void printAllParts(Part arr[], int count) //print parts
{
	if (count == 0) //check if inventory is empty
	{
		cout<<"Empty inventory."<< endl;
		return;
	}
	//print all elements from array
	for (int i = 0; i < count; i++)
	{
		cout<<arr[i].partNum
			<<"   " <<arr[i].description
			<<"   " <<arr[i].quantity 
			<<"  $ " <<arr[i].unitPrice <<endl;
	}
}
	
void addPart(Part arr[], int &count) //add a part
{
	cout<<"New part description: "; //get description
	string desc;
	getline (cin, desc);
	
	cout<<"New part quantity:"; //get quantity
	int quantity = 0;
	cin>>quantity;
	
	cout<<"New part unit price:"; //get price
	float price = 0;
	cin>>price;
	
	//enter locan var to array
	arr[count].partNum = count + 1;
	arr[count].description = desc;
	arr[count].quantity = quantity;
	arr[count].unitPrice = price;
	
	count++; //move counter up 
	
	
		
}

void modifyPart (Part arr[], int count) //modify part
{
	if (count == 0) //check if inventory is empty
	{
		cout<<"Empty inventory."<< endl;
		return;
	}
	
	cout<<"Enter part number to modify:"; //get part number
	int part = 0;
	cin>>part; //store part number
	part=part-1;
	
	if (part > count) //check if part number is valid
	{
		cout<<"Invalid part number."<< endl;
		return;
	}
	
	//print part information
	cout<<arr[part].partNum
			<<"   " <<arr[part].description
			<<"   " <<arr[part].quantity 
			<<"  $ " <<arr[part].unitPrice <<endl;
	
	std::cin.ignore(); //ignore the new line
	cout<<"New part description: ";
	string desc;
	getline (cin, desc);
	
	cout<<"New part quantity:";
	int quantity = 0;
	cin>>quantity;
	
	cout<<"New part unit price:";
	float price = 0;
	cin>>price;
	
	//write local var to array
	 
	arr[part].description = desc;
	arr[part].quantity = quantity;
	arr[part].unitPrice = price;
	
}
	
void total (Part arr[], int count) //print total
{
	float total = 0; //var to store total
	for (int i=0; i<count; i++) //loop to read the array
	{
	total = total + (arr[i].unitPrice * arr[i].quantity); //sum of prices
	}
	cout<<"Total cost of inventory :$"<<total<<endl;
}

