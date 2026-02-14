// #include "DoublyList.hpp"
// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     cout << "==================== INT LIST TESTS ====================\n";
//     DoublyList<int> li;

//     cout << "Initially empty? " << li.isEmpty() << "\n";
//     cout << "Length: " << li.getLength() << "\n";

//     cout << "\nAppending 10, 20, 30...\n";
//     li.append(10);
//     li.append(20);
//     li.append(30);
//     cout << "List: " << li;
//     cout << "Empty? " << li.isEmpty() << "\n";
//     cout << "Length: " << li.getLength() << "\n";

//     cout << "\ngetElement tests:\n";
//     cout << "Element at 0: " << li.getElement(0) << "\n";
//     cout << "Element at 1: " << li.getElement(1) << "\n";
//     cout << "Element at 2: " << li.getElement(2) << "\n";

//     cout << "\ninsert tests:\n";
//     cout << "Insert 5 at position 0\n";
//     li.insert(0, 5);
//     cout << "List: " << li;

//     cout << "Insert 15 at position 2\n";
//     li.insert(2, 15);
//     cout << "List: " << li;

//     cout << "Insert 40 at position length (end)\n";
//     li.insert(li.getLength(), 40);
//     cout << "List: " << li;
//     cout << "Length: " << li.getLength() << "\n";

//     cout << "\nreplace tests:\n";
//     cout << "Replace position 1 with 99\n";
//     li.replace(1, 99);
//     cout << "List: " << li;

//     cout << "\nsearch tests:\n";
//     cout << "Search 99: " << li.search(99) << "\n";
//     cout << "Search 123: " << li.search(123) << "\n";

//     cout << "\nremove tests:\n";
//     cout << "Remove position 0\n";
//     li.remove(0);
//     cout << "List: " << li;

//     cout << "Remove last position\n";
//     li.remove(li.getLength() - 1);
//     cout << "List: " << li;

//     cout << "Remove middle (position 1 if possible)\n";
//     if (li.getLength() > 2) {
//         li.remove(1);
//     } else if (li.getLength() > 1) {
//         li.remove(1);
//     }
//     cout << "List: " << li;
//     cout << "Length: " << li.getLength() << "\n";

//     cout << "\nclear test:\n";
//     li.clear();
//     cout << "List: " << li;
//     cout << "Empty? " << li.isEmpty() << "\n";
//     cout << "Length: " << li.getLength() << "\n";

//     cout << "\nException tests (int list):\n";
//     try {
//         cout << "Trying getElement(0) on empty...\n";
//         cout << li.getElement(0) << "\n";
//     } catch (const string& e) {
//         cout << "Caught exception: " << e << "\n";
//     }

//     try {
//         cout << "Trying remove(0) on empty...\n";
//         li.remove(0);
//     } catch (const string& e) {
//         cout << "Caught exception: " << e << "\n";
//     }

//     try {
//         cout << "Trying insert(-1, 7)...\n";
//         li.insert(-1, 7);
//     } catch (const string& e) {
//         cout << "Caught exception: " << e << "\n";
//     }

//     try {
//         cout << "Trying insert(1, 7) on empty (should be out of bounds unless you allow only 0)...\n";
//         li.insert(1, 7);
//     } catch (const string& e) {
//         cout << "Caught exception: " << e << "\n";
//     }

//     cout << "\nCopy constructor test (int):\n";
//     li.append(1);
//     li.append(2);
//     li.append(3);
//     cout << "Original li: " << li;
//     DoublyList<int> liCopy(li);
//     cout << "Copy liCopy: " << liCopy;

//     cout << "Modify original (replace pos 1 with 200)...\n";
//     li.replace(1, 200);
//     cout << "Original li: " << li;
//     cout << "Copy liCopy (should be unchanged): " << liCopy;

//     cout << "\nAssignment operator test (int):\n";
//     DoublyList<int> liAssign;
//     liAssign.append(9);
//     liAssign.append(9);
//     cout << "Before assignment, liAssign: " << liAssign;
//     liAssign = li;
//     cout << "After assignment, liAssign: " << liAssign;
//     cout << "Modify liAssign (remove pos 0)...\n";
//     liAssign.remove(0);
//     cout << "liAssign: " << liAssign;
//     cout << "li (should be unchanged): " << li;

//     cout << "\n\n==================== STRING LIST TESTS ====================\n";
//     DoublyList<string> ls;

//     cout << "Initially empty? " << ls.isEmpty() << "\n";
//     cout << "Length: " << ls.getLength() << "\n";

//     cout << "\nAppending \"apple\", \"banana\", \"cherry\"...\n";
//     ls.append("apple");
//     ls.append("banana");
//     ls.append("cherry");
//     cout << "List: " << ls;
//     cout << "Length: " << ls.getLength() << "\n";

//     cout << "\ngetElement tests:\n";
//     cout << "Element at 0: " << ls.getElement(0) << "\n";
//     cout << "Element at 1: " << ls.getElement(1) << "\n";
//     cout << "Element at 2: " << ls.getElement(2) << "\n";

//     cout << "\ninsert tests:\n";
//     cout << "Insert \"zero\" at position 0\n";
//     ls.insert(0, "zero");
//     cout << "List: " << ls;

//     cout << "Insert \"middle\" at position 2\n";
//     ls.insert(2, "middle");
//     cout << "List: " << ls;

//     cout << "Insert \"last\" at end\n";
//     ls.insert(ls.getLength(), "last");
//     cout << "List: " << ls;

//     cout << "\nreplace tests:\n";
//     cout << "Replace position 1 with \"BEEP\"\n";
//     ls.replace(1, "BEEP");
//     cout << "List: " << ls;

//     cout << "\nsearch tests:\n";
//     cout << "Search \"cherry\": " << ls.search("cherry") << "\n";
//     cout << "Search \"not-here\": " << ls.search("not-here") << "\n";

//     cout << "\nremove tests:\n";
//     cout << "Remove position 0\n";
//     ls.remove(0);
//     cout << "List: " << ls;

//     cout << "Remove last position\n";
//     ls.remove(ls.getLength() - 1);
//     cout << "List: " << ls;

//     cout << "\nclear test:\n";
//     ls.clear();
//     cout << "List: " << ls;
//     cout << "Empty? " << ls.isEmpty() << "\n";
//     cout << "Length: " << ls.getLength() << "\n";

//     cout << "\nCopy + assignment tests (string):\n";
//     ls.append("A");
//     ls.append("B");
//     ls.append("C");
//     cout << "Original ls: " << ls;
//     DoublyList<string> lsCopy(ls);
//     cout << "Copy lsCopy: " << lsCopy;

//     DoublyList<string> lsAssign;
//     lsAssign.append("X");
//     cout << "Before assignment, lsAssign: " << lsAssign;
//     lsAssign = ls;
//     cout << "After assignment, lsAssign: " << lsAssign;

//     cout << "\n\n==================== DOUBLE LIST TESTS ====================\n";
//     DoublyList<double> ld;

//     cout << "Appending 1.5, 2.25, 3.75...\n";
//     ld.append(1.5);
//     ld.append(2.25);
//     ld.append(3.75);
//     cout << "List: " << ld;

//     cout << "Insert 9.99 at pos 1\n";
//     ld.insert(1, 9.99);
//     cout << "List: " << ld;

//     cout << "Replace pos 2 with -4.5\n";
//     ld.replace(2, -4.5);
//     cout << "List: " << ld;

//     cout << "Search -4.5: " << ld.search(-4.5) << "\n";
//     cout << "Remove pos 0\n";
//     ld.remove(0);
//     cout << "List: " << ld;

//     cout << "Clear double list\n";
//     ld.clear();
//     cout << "List: " << ld;
//     cout << "Empty? " << ld.isEmpty() << "\n";

//     cout << "\n==================== DONE ====================\n";
//     return 0;
// }
