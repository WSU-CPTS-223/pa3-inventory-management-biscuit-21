[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.

## Test Code Explanation
** tests can be accessed by using the 'test' command. more info is listed about it under ':help'**
TestSuite tests all (used) DataMaps and UnorderMap class functions using cassert. Each function verifies expected behavior and special cases:

testQuoteLineParser() – Makes sure the CSV lines are parsed correctly regardless of format or empty fields.

testLoadMaps() – Ensures that UnorderedMaps objects IDMap and categoryMap load data correctly and that elements can be found using find().

testInsert() – Makes sure that new elements are inserted correctly and that separate chaining correctly handles multiple entries in the same bucket.

testFind() – Checks that find() returns the correct data for it's key and nullptr if the key is not in the map, and handles chaining collisions correctly.

testErase() – Placeholder for future deletion test if erase() is implemented.

testRehash() – Inserts more items than the initial table size to trigger rehashing and confirms all data remains accessible afterward.