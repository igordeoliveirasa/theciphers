//
//  main.cpp
//  SystemTest
//
//  Created by Igor de Oliveira Sa on 23/03/14.
//  Copyright (c) 2014 Igor de Oliveira Sa. All rights reserved.
//

#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char * argv[])
{
    // insert code here...
    std::cout << "Running System Tests...\n";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

