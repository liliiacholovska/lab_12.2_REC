#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.2(2)/lab12.2(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestDuplicatePairRec_NoDuplicates)
        {
            Node* head = nullptr;
            Node* tail = nullptr;
            int values[] = { 1, 2, 3, 4, 5, 6 };
            int size = sizeof(values) / sizeof(values[0]);

            CreateListRec(head, tail, values, size);
            Assert::IsFalse(DuplicatePairRec(head));

            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }

        TEST_METHOD(TestDuplicatePairRec_WithDuplicates)
        {
            Node* head = nullptr;
            Node* tail = nullptr;
            int values[] = { 1, 2, 2, 4, 5, 2 };
            int size = sizeof(values) / sizeof(values[0]);

            CreateListRec(head, tail, values, size);
            Assert::IsTrue(DuplicatePairRec(head));

            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
	};
}