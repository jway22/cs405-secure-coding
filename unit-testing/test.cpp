// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here

class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    // if empty, the size must be 0

    add_entries(1);

    // is the collection still empty?
    // if not empty, what must the size be?
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    add_entries(5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, MaxSizeGreaterOrEqualToSize) {
    
    // Check for 0 entries
    // Check if collection is empty
    ASSERT_TRUE(collection->empty());
    // Check that collection size equals 0
    ASSERT_EQ(collection->size(), 0);
    // Check that max_size is greater than or equal to size
    ASSERT_GE(collection->max_size(), collection->size());

    // Check for 1 entry
    add_entries(1);
    // Check that collection size equals 1
    ASSERT_EQ(collection->size(), 1);
    // Check that max_size is greater than or equal to size
    ASSERT_GE(collection->max_size(), collection->size());

    // Check for 5 entries
    add_entries(4);
    // Check that collection size equals 5
    ASSERT_EQ(collection->size(), 5);
    // Check that max_size is greater than or equal to size
    ASSERT_GE(collection->max_size(), collection->size());

    // Check for 10 entries
    add_entries(5);
    // Check that collection size equals 10
    ASSERT_EQ(collection->size(), 10);
    // Check that max_size is greater than or equal to size
    ASSERT_GE(collection->max_size(), collection->size());
}

// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, CapacityGreaterOrEqualToSize) {
    
    // Check for 0 entries
    // Check if collection is empty
    ASSERT_TRUE(collection->empty());
    // Check that collection size equals 0
    ASSERT_EQ(collection->size(), 0);
    // Check that capacity is greater than or equal to size
    ASSERT_GE(collection->capacity(), collection->size());

    // Check for 1 entry
    add_entries(1);
    // Check that collection size equals 1
    ASSERT_EQ(collection->size(), 1);
    // Check that capacity is greater than or equal to size
    ASSERT_GE(collection->capacity(), collection->size());

    // Check for 5 entries
    add_entries(4);
    // Check that collection size equals 5
    ASSERT_EQ(collection->size(), 5);
    // Check that capacity is greater than or equal to size
    ASSERT_GE(collection->capacity(), collection->size());

    // Check for 10 entries
    add_entries(5);
    // Check that collection size equals 10
    ASSERT_EQ(collection->size(), 10);
    // Check that capacity is greater than or equal to size
    ASSERT_GE(collection->capacity(), collection->size());
}

// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, VerifyResizeIncreasesCollection) {
    
    // Check if collection is empty
    ASSERT_TRUE(collection->empty());
    // Check that size is 0
    ASSERT_EQ(collection->size(), 0);
    // Add 5 entries
    collection->resize(5);
    // Size should now be 5
    ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, VerifyResizeDecreasesCollection) {
    
    // Add 5 entries
    add_entries(5);
    // Check that size is 5
    ASSERT_EQ(collection->size(), 5);
    // Resize to 1
    collection->resize(1);
    // Check that size is 1
    ASSERT_EQ(collection->size(), 1);
}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, VerifyResizeToZeroCollection) {

    // Add 5 entries
    add_entries(5);
    // Check that size is 5
    ASSERT_EQ(collection->size(), 5);
    // Resize to 0
    collection->resize(0);
    // Check that size is 0
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, VerifyClearCollection) {
    
    // Add 5 entries
    add_entries(5);
    // Check if size is 5
    ASSERT_EQ(collection->size(), 5);
    // Call the clear function
    collection->clear();
    // Check if collection is empty
    ASSERT_TRUE(collection->empty());
}

// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, VerifyEraseCollection) {
    
    // Add 5 entries
    add_entries(5);
    // Check if size is 5
    ASSERT_EQ(collection->size(), 5);
    // Call the clear function
    collection->erase(collection->begin(), collection->end());
    // Check if collection is empty
    ASSERT_TRUE(collection->empty());
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, VerifyReserveIncreaseCapacity) {
    
    // Add 1 entry
    add_entries(1);
    // Check that size is 1
    ASSERT_EQ(collection->size(), 1);
    // Whats the capacity?
    ASSERT_EQ(collection->capacity(), 1);
    // Call the reserve function
    collection->reserve(5);
    // Check the capacity
    ASSERT_EQ(collection->capacity(), 5);
    // Check the size is still 1
    ASSERT_EQ(collection->size(), 1);
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, CanThrowOutOfRangeException) {
    // Add 5 entries
    add_entries(1);
    // Check that size is 1
    ASSERT_EQ(collection->size(), 1);
    // Check if the collection throws
    ASSERT_THROW(collection->at(2), std::out_of_range);
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative
TEST_F(CollectionTest, CanThrowLengthException) {
    
    // Checks that the statement throws length error when trying to reserve a capacity of -1 in the collection
    ASSERT_THROW(collection->reserve(-1), std::length_error);
}

TEST_F(CollectionTest, CanInsertCollection) {
    
    // Is the collection empty
    ASSERT_TRUE(collection->empty());
    // Emplace Back
    collection->emplace(collection->end(), 1);
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 1);
}