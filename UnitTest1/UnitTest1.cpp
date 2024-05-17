#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_12.13_open.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestAddAndFindEmployee)
        {
            HashTable hashTable(10);

            Employee employee = { "Smith", "J.D.", "Manager", 2010, 50000.0 };
            hashTable.AddEmployee(employee);

            Employee* foundEmployee = hashTable.FindEmployee("Smith");

            Assert::IsNotNull(foundEmployee);
            Assert::AreEqual(std::string("Smith"), foundEmployee->surname);
            Assert::AreEqual(std::string("J.D."), foundEmployee->initials);
            Assert::AreEqual(std::string("Manager"), foundEmployee->position);
            Assert::AreEqual(2010, foundEmployee->yearOfHire);
            Assert::AreEqual(50000.0, foundEmployee->salary);
        }

        TEST_METHOD(TestRemoveEmployee)
        {
            HashTable hashTable(10);

            Employee employee = { "Smith", "J.D.", "Manager", 2010, 50000.0 };
            hashTable.AddEmployee(employee);

            bool removed = hashTable.RemoveEmployee("Smith");

            Assert::IsTrue(removed);

            Employee* foundEmployee = hashTable.FindEmployee("Smith");

            Assert::IsNull(foundEmployee);
        }

        TEST_METHOD(TestEditEmployee)
        {
            HashTable hashTable(10);

            Employee employee = { "Smith", "J.D.", "Manager", 2010, 50000.0 };
            hashTable.AddEmployee(employee);

            Employee* foundEmployee = hashTable.FindEmployee("Smith");
            Assert::IsNotNull(foundEmployee);

            foundEmployee->initials = "A.B.";
            foundEmployee->position = "Director";
            foundEmployee->yearOfHire = 2015;
            foundEmployee->salary = 60000.0;

            foundEmployee = hashTable.FindEmployee("Smith");
            Assert::IsNotNull(foundEmployee);
            Assert::AreEqual(std::string("A.B."), foundEmployee->initials);
            Assert::AreEqual(std::string("Director"), foundEmployee->position);
            Assert::AreEqual(2015, foundEmployee->yearOfHire);
            Assert::AreEqual(60000.0, foundEmployee->salary);
        }

       
	};
}
