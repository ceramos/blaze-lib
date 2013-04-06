//=================================================================================================
/*!
//  \file src/mathtest/dmatdmatadd/MDbMDb.cpp
//  \brief Source file for the MDbMDb dense matrix/dense matrix addition math test
//
//  Copyright (C) 2011 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. This library is free software; you can redistribute
//  it and/or modify it under the terms of the GNU General Public License as published by the
//  Free Software Foundation; either version 3, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with a special
//  exception for linking and compiling against the Blaze library, the so-called "runtime
//  exception"; see the file COPYING. If not, see http://www.gnu.org/licenses/.
*/
//=================================================================================================


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <cstdlib>
#include <iostream>
#include <blaze/math/DynamicMatrix.h>
#include <blazetest/mathtest/Creator.h>
#include <blazetest/mathtest/dmatdmatadd/OperationTest.h>
#include <blazetest/system/MathTest.h>


//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running 'MDbMDb'..." << std::endl;

   using blazetest::mathtest::TypeB;

   try
   {
      // Matrix type definitions
      typedef blaze::DynamicMatrix<TypeB>  MDb;

      // Creator type definitions
      typedef blazetest::Creator<MDb>  CMDb;

      // Running tests with small matrices
      for( size_t i=0UL; i<=9UL; ++i ) {
         for( size_t j=0UL; j<=9UL; ++j ) {
            RUN_DMATDMATADD_OPERATION_TEST( CMDb( i, j ), CMDb( i, j ) );
         }
      }

      // Running tests with large matrices
      RUN_DMATDMATADD_OPERATION_TEST( CMDb(  67UL,  67UL ), CMDb(  67UL,  67UL ) );
      RUN_DMATDMATADD_OPERATION_TEST( CMDb(  67UL, 127UL ), CMDb(  67UL, 127UL ) );
      RUN_DMATDMATADD_OPERATION_TEST( CMDb( 128UL,  64UL ), CMDb( 128UL,  64UL ) );
      RUN_DMATDMATADD_OPERATION_TEST( CMDb( 128UL, 128UL ), CMDb( 128UL, 128UL ) );
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during dense matrix/dense matrix addition:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
