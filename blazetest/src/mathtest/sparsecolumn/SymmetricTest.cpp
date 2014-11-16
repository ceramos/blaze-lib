//=================================================================================================
/*!
//  \file src/mathtest/sparsecolumn/SymmetricTest.cpp
//  \brief Source file for the symmetric SparseColumn class test
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <cstdlib>
#include <iostream>
#include <blaze/math/CompressedVector.h>
#include <blaze/math/DynamicVector.h>
#include <blaze/math/Views.h>
#include <blazetest/mathtest/sparsecolumn/SymmetricTest.h>


namespace blazetest {

namespace mathtest {

namespace sparsecolumn {

//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Constructor for the symmetric SparseColumn class test.
//
// \exception std::runtime_error Operation error detected.
*/
SymmetricTest::SymmetricTest()
   : mat_ ( 4UL )
   , tmat_( 4UL )
{
   testConstructors();
   testAssignment();
   testAddAssign();
   testSubAssign();
   testMultAssign();
   testScaling();
   testSubscript();
   testIterator();
   testNonZeros();
   testReset();
   testClear();
   testSet();
   testInsert();
   testAppend();
   testErase();
   testReserve();
   testFind();
   testLowerBound();
   testUpperBound();
   testIsDefault();
   testIsSame();
   testSubvector();
}
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Test of the SparseColumn constructors.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all constructors of the SparseColumn class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testConstructors()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn constructor";

      initialize();

      // 0th matrix column
      {
         CT col0 = column( mat_, 0UL );

         checkSize    ( col0, 4UL );
         checkNonZeros( col0, 0UL );

         if( col0[0] != 0 || col0[1] != 0 || col0[2] != 0 || col0[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 0th sparse column failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 1st matrix column
      {
         CT col1 = column( mat_, 1UL );

         checkSize    ( col1, 4UL );
         checkNonZeros( col1, 2UL );

         if( col1[0] != 0 || col1[1] != 1 || col1[2] != 0 || col1[3] != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 1st sparse column failed\n"
                << " Details:\n"
                << "   Result:\n" << col1 << "\n"
                << "   Expected result:\n( 0 1 0 -2 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 2nd matrix column
      {
         CT col2 = column( mat_, 2UL );

         checkSize    ( col2, 4UL );
         checkNonZeros( col2, 2UL );

         if( col2[0] != 0 || col2[1] != 0 || col2[2] != 3 || col2[3] != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 2nd sparse column failed\n"
                << " Details:\n"
                << "   Result:\n" << col2 << "\n"
                << "   Expected result:\n( 0 0 3 4 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 3rd matrix column
      {
         CT col3 = column( mat_, 3UL );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 3UL );

         if( col3[0] != 0 || col3[1] != -2 || col3[2] != 4 || col3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 3rd sparse column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 -2 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn constructor";

      initialize();

      // 0th matrix column
      {
         TCT col0 = column( tmat_, 0UL );

         checkSize    ( col0, 4UL );
         checkNonZeros( col0, 0UL );

         if( col0[0] != 0 || col0[1] != 0 || col0[2] != 0 || col0[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 0th sparse column failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 1st matrix column
      {
         TCT col1 = column( tmat_, 1UL );

         checkSize    ( col1, 4UL );
         checkNonZeros( col1, 2UL );

         if( col1[0] != 0 || col1[1] != 1 || col1[2] != 0 || col1[3] != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 1st sparse column failed\n"
                << " Details:\n"
                << "   Result:\n" << col1 << "\n"
                << "   Expected result:\n( 0 1 0 -2 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 2nd matrix column
      {
         TCT col2 = column( tmat_, 2UL );

         checkSize    ( col2, 4UL );
         checkNonZeros( col2, 2UL );

         if( col2[0] != 0 || col2[1] != 0 || col2[2] != 3 || col2[3] != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 2nd sparse column failed\n"
                << " Details:\n"
                << "   Result:\n" << col2 << "\n"
                << "   Expected result:\n( 0 0 3 4 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 3rd matrix column
      {
         TCT col3 = column( tmat_, 3UL );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 3UL );

         if( col3[0] != 0 || col3[1] != -2 || col3[2] != 4 || col3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 3rd sparse column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 -2 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseColumn assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all assignment operators of the SparseColumn class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testAssignment()
{
   //=====================================================================================
   // Row-major copy assignment
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn copy assignment";

      initialize();

      CT col1 = column( mat_, 1UL );
      col1 = column( mat_, 2UL );

      checkSize    ( col1, 4UL );
      checkNonZeros( col1, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 8UL );

      if( col1[0] != 0 || col1[1] != 0 || col1[2] != 3 || col1[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 0 0 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != 0 || mat_(0,3) != 0 ||
          mat_(1,0) != 0 || mat_(1,1) != 0 || mat_(1,2) != 3 || mat_(1,3) != 4 ||
          mat_(2,0) != 0 || mat_(2,1) != 3 || mat_(2,2) != 3 || mat_(2,3) != 4 ||
          mat_(3,0) != 0 || mat_(3,1) != 4 || mat_(3,2) != 4 || mat_(3,3) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  0  3  4 )\n"
                                     "(  0  3  3  4 )\n"
                                     "(  0  4  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector assignment";

      initialize();

      CT col1 = column( mat_, 1UL );

      blaze::DynamicVector<int,blaze::columnVector> vec1( 4UL, 0 );
      vec1[1] = 8;
      vec1[3] = 9;

      col1 = vec1;

      checkSize    ( col1, 4UL );
      checkNonZeros( col1, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( col1[0] != 0 || col1[1] != 8 || col1[2] != 0 || col1[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 0 8 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != 0 || mat_(0,3) != 0 ||
          mat_(1,0) != 0 || mat_(1,1) != 8 || mat_(1,2) != 0 || mat_(1,3) != 9 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != 3 || mat_(2,3) != 4 ||
          mat_(3,0) != 0 || mat_(3,1) != 9 || mat_(3,2) != 4 || mat_(3,3) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  8  0  9 )\n"
                                     "(  0  0  3  4 )\n"
                                     "(  0  9  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector assignment";

      initialize();

      CT col3 = column( mat_, 3UL );

      blaze::CompressedVector<int,blaze::columnVector> vec1( 4UL );
      vec1[3] = 9;

      col3 = vec1;

      checkSize    ( col3, 4UL );
      checkNonZeros( col3, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 3UL );

      if( col3[0] != 0 || col3[1] != 0 || col3[2] != 0 || col3[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 0 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) != 0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 0 || mat_(1,3) != 0 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != 3 || mat_(2,3) != 0 ||
          mat_(3,0) != 0 || mat_(3,1) !=  0 || mat_(3,2) != 0 || mat_(3,3) != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0  0 )\n"
                                     "(  0  0  3  0 )\n"
                                     "(  0  0  0  9 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major copy assignment
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn copy assignment";

      initialize();

      TCT col1 = column( tmat_, 1UL );
      col1 = column( tmat_, 2UL );

      checkSize    ( col1 , 4UL );
      checkNonZeros( col1 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 8UL );

      if( col1[0] != 0 || col1[1] != 0 || col1[2] != 3 || col1[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 0 0 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) != 0 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 0 || tmat_(1,2) != 3 || tmat_(1,3) != 4 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 3 || tmat_(2,2) != 3 || tmat_(2,3) != 4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 4 || tmat_(3,2) != 4 || tmat_(3,3) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  0  3  4 )\n"
                                     "(  0  3  3  4 )\n"
                                     "(  0  4  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector assignment";

      initialize();

      TCT col1 = column( tmat_, 1UL );

      blaze::DynamicVector<int,blaze::columnVector> vec1( 4UL, 0 );
      vec1[1] = 8;
      vec1[3] = 9;

      col1 = vec1;

      checkSize    ( col1 , 4UL );
      checkNonZeros( col1 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( col1[0] != 0 || col1[1] != 8 || col1[2] != 0 || col1[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 0 8 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) != 0 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 8 || tmat_(1,2) != 0 || tmat_(1,3) != 9 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != 3 || tmat_(2,3) != 4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 9 || tmat_(3,2) != 4 || tmat_(3,3) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  8  0  9 )\n"
                                     "(  0  0  3  4 )\n"
                                     "(  0  9  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector assignment";

      initialize();

      TCT col3 = column( tmat_, 3UL );

      blaze::CompressedVector<int,blaze::columnVector> vec1( 4UL );
      vec1[3] = 9;

      col3 = vec1;

      checkSize    ( col3 , 4UL );
      checkNonZeros( col3 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 3UL );

      if( col3[0] != 0 || col3[1] != 0 || col3[2] != 0 || col3[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 0 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) != 0 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) != 0 || tmat_(1,3) != 0 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != 3 || tmat_(2,3) != 0 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) != 0 || tmat_(3,3) != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0  0 )\n"
                                     "(  0  0  3  0 )\n"
                                     "(  0  0  0  9 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseColumn addition assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the addition assignment operators of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testAddAssign()
{
   //=====================================================================================
   // Row-major SparseColumn addition assignment
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn addition assignment";

      initialize();

      CT col2 = column( mat_, 2UL );
      col2 += column( mat_, 3UL );

      checkSize    ( col2  , 4UL );
      checkNonZeros( col2  , 3UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 9UL );

      if( col2[0] != 0 || col2[1] != -2 || col2[2] != 7 || col2[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 -2 7 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != -2 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) != -2 || mat_(2,2) !=  7 || mat_(2,3) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) !=  9 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1 -2 -2 )\n"
                                     "(  0 -2  7  9 )\n"
                                     "(  0 -2  9  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector addition assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector addition assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      col2 += vec;

      checkSize    ( col2,  4UL );
      checkNonZeros( col2,  4UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  4UL );
      checkNonZeros( mat_, 11UL );

      if( col2[0] != 2 || col2[1] != -4 || col2[2] != 3 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 2 -4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  2 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != -4 || mat_(1,3) != -2 ||
          mat_(2,0) != 2 || mat_(2,1) != -4 || mat_(2,2) !=  3 || mat_(2,3) !=  4 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) !=  4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  2  0 )\n"
                                     "( 0  1 -4 -2 )\n"
                                     "( 2 -4  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector addition assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector addition assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      col2 += vec;

      checkSize    ( col2,  4UL );
      checkNonZeros( col2,  4UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  4UL );
      checkNonZeros( mat_, 11UL );

      if( col2[0] != 2 || col2[1] != -4 || col2[2] != 3 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 2 -4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  2 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != -4 || mat_(1,3) != -2 ||
          mat_(2,0) != 2 || mat_(2,1) != -4 || mat_(2,2) !=  3 || mat_(2,3) !=  4 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) !=  4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  2  0 )\n"
                                     "( 0  1 -4 -2 )\n"
                                     "( 2 -4  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major SparseColumn addition assignment
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn addition assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );
      col2 += column( tmat_, 3UL );

      checkSize    ( col2 , 4UL );
      checkNonZeros( col2 , 3UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 9UL );

      if( col2[0] != 0 || col2[1] != -2 || col2[2] != 7 || col2[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 -2 7 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != -2 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) != -2 || tmat_(2,2) !=  7 || tmat_(2,3) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) !=  9 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1 -2 -2 )\n"
                                     "(  0 -2  7  9 )\n"
                                     "(  0 -2  9  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector addition assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector addition assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      col2 += vec;

      checkSize    ( col2 ,  4UL );
      checkNonZeros( col2 ,  4UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  4UL );
      checkNonZeros( tmat_, 11UL );

      if( col2[0] != 2 || col2[1] != -4 || col2[2] != 3 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 2 -4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  2 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != -4 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 2 || tmat_(2,1) != -4 || tmat_(2,2) !=  3 || tmat_(2,3) !=  4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) !=  4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  2  0 )\n"
                                     "( 0  1 -4 -2 )\n"
                                     "( 2 -4  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector addition assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector addition assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      col2 += vec;

      checkSize    ( col2 ,  4UL );
      checkNonZeros( col2 ,  4UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  4UL );
      checkNonZeros( tmat_, 11UL );

      if( col2[0] != 2 || col2[1] != -4 || col2[2] != 3 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 2 -4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  2 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != -4 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 2 || tmat_(2,1) != -4 || tmat_(2,2) !=  3 || tmat_(2,3) !=  4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) !=  4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  2  0 )\n"
                                     "( 0  1 -4 -2 )\n"
                                     "( 2 -4  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseColumn subtraction assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the subtraction assignment operators of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testSubAssign()
{
   //=====================================================================================
   // Row-major SparseColumn subtraction assignment
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn subtraction assignment";

      initialize();

      CT col2 = column( mat_, 2UL );
      col2 -= column( mat_, 3UL );

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 3UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 9UL );

      if( col2[0] != 0 || col2[1] != 2 || col2[2] != -1 || col2[3] != -1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 2 -1 -1 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  2 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  2 || mat_(2,2) != -1 || mat_(2,3) != -1 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != -1 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  2 -2 )\n"
                                     "(  0  2 -1 -1 )\n"
                                     "(  0 -2 -1  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector subtraction assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      col2 -= vec;

      checkSize    ( col2,  4UL );
      checkNonZeros( col2,  4UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  4UL );
      checkNonZeros( mat_, 11UL );

      if( col2[0] != -2 || col2[1] != 4 || col2[2] != 3 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -2 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) !=  4 || mat_(1,3) != -2 ||
          mat_(2,0) != -2 || mat_(2,1) !=  4 || mat_(2,2) !=  3 || mat_(2,3) !=  4 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) !=  4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -2  0 )\n"
                                     "(  0  1  4 -2 )\n"
                                     "( -2  4  3  4 )\n"
                                     "(  0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector subtraction assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      col2 -= vec;

      checkSize    ( col2,  4UL );
      checkNonZeros( col2,  4UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  4UL );
      checkNonZeros( mat_, 11UL );

      if( col2[0] != -2 || col2[1] != 4 || col2[2] != 3 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -2 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) !=  4 || mat_(1,3) != -2 ||
          mat_(2,0) != -2 || mat_(2,1) !=  4 || mat_(2,2) !=  3 || mat_(2,3) !=  4 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) !=  4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -2  0 )\n"
                                     "(  0  1  4 -2 )\n"
                                     "( -2  4  3  4 )\n"
                                     "(  0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major SparseColumn subtraction assignment
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn subtraction assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );
      col2 -= column( tmat_, 3UL );

      checkSize    ( col2 , 4UL );
      checkNonZeros( col2 , 3UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 9UL );

      if( col2[0] != 0 || col2[1] != 2 || col2[2] != -1 || col2[3] != -1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 2 -1 -1 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  2 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  2 || tmat_(2,2) != -1 || tmat_(2,3) != -1 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != -1 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  2 -2 )\n"
                                     "(  0  2 -1 -1 )\n"
                                     "(  0 -2 -1  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector subtraction assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      col2 -= vec;

      checkSize    ( col2 ,  4UL );
      checkNonZeros( col2 ,  4UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  4UL );
      checkNonZeros( tmat_, 11UL );

      if( col2[0] != -2 || col2[1] != 4 || col2[2] != 3 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  4 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -2 || tmat_(2,1) !=  4 || tmat_(2,2) !=  3 || tmat_(2,3) !=  4 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) !=  4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -2  0 )\n"
                                     "(  0  1  4 -2 )\n"
                                     "( -2  4  3  4 )\n"
                                     "(  0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector subtraction assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      col2 -= vec;

      checkSize    ( col2 ,  4UL );
      checkNonZeros( col2 ,  4UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  4UL );
      checkNonZeros( tmat_, 11UL );

      if( col2[0] != -2 || col2[1] != 4 || col2[2] != 3 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  4 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -2 || tmat_(2,1) !=  4 || tmat_(2,2) !=  3 || tmat_(2,3) !=  4 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) !=  4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -2  0 )\n"
                                     "(  0  1  4 -2 )\n"
                                     "( -2  4  3  4 )\n"
                                     "(  0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseColumn multiplication assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the multiplication assignment operators of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testMultAssign()
{
   //=====================================================================================
   // Row-major SparseColumn multiplication assignment
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn multiplication assignment";

      initialize();

      CT col2 = column( mat_, 2UL );
      col2 *= column( mat_, 3UL );

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 12 || col2[3] != 20 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 12 20 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != 12 || mat_(2,3) != 20 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 20 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0 12 20 )\n"
                                     "(  0 -2 20  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector multiplication assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[2] = -4;

      col2 *= vec;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != -12 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 -12 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=   0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=   0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != -12 || mat_(2,3) !=  0 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) !=   0 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0   0  0 )\n"
                                     "(  0  1   0 -2 )\n"
                                     "(  0  0 -12  0 )\n"
                                     "(  0 -2   0  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector multiplication assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[2] = -4;

      col2 *= vec;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 5UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != -12 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 -12 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=   0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=   0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != -12 || mat_(2,3) !=  0 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) !=   0 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0   0  0 )\n"
                                     "(  0  1   0 -2 )\n"
                                     "(  0  0 -12  0 )\n"
                                     "(  0 -2   0  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major SparseColumn multiplication assignment
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn multiplication assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );
      col2 *= column( tmat_, 3UL );

      checkSize    ( col2 , 4UL );
      checkNonZeros( col2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 12 || col2[3] != 20 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 12 20 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != 12 || tmat_(2,3) != 20 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 20 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0 12 20 )\n"
                                     "(  0 -2 20  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector multiplication assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[2] = -4;

      col2 *= vec;

      checkSize    ( col2 , 4UL );
      checkNonZeros( col2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != -12 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 -12 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=   0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=   0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != -12 || tmat_(2,3) !=  0 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) !=   0 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0   0  0 )\n"
                                     "(  0  1   0 -2 )\n"
                                     "(  0  0 -12  0 )\n"
                                     "(  0 -2   0  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector multiplication assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[2] = -4;

      col2 *= vec;

      checkSize    ( col2 , 4UL );
      checkNonZeros( col2 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 5UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != -12 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 -12 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=   0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=   0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != -12 || tmat_(2,3) !=  0 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) !=   0 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0   0  0 )\n"
                                     "(  0  1   0 -2 )\n"
                                     "(  0  0 -12  0 )\n"
                                     "(  0 -2   0  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of all SparseColumn (self-)scaling operations.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all available ways to scale an instance of the SparseColumn
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testScaling()
{
   //=====================================================================================
   // Row-major self-scaling (v*=2)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v*=2)";

      initialize();

      CT col2 = column( mat_, 2UL );

      col2 *= 3;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 9 || col2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) !=  9 || mat_(2,3) != 12 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 12 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0  9 12 )\n"
                                     "(  0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v=v*2)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v=v*2)";

      initialize();

      CT col2 = column( mat_, 2UL );

      col2 = col2 * 3;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 9 || col2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) !=  9 || mat_(2,3) != 12 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 12 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0  9 12 )\n"
                                     "(  0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v=2*v)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v=2*v)";

      initialize();

      CT col2 = column( mat_, 2UL );

      col2 = 3 * col2;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 9 || col2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) !=  9 || mat_(2,3) != 12 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 12 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0  9 12 )\n"
                                     "(  0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v/=s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v/=s)";

      initialize();

      CT col2 = column( mat_, 2UL );

      col2 /= 0.5;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 6 || col2[3] != 8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 6 8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != 6 || mat_(2,3) !=  8 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0  6  8 )\n"
                                     "(  0 -2  8  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v=v/s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v=v/s)";

      initialize();

      CT col2 = column( mat_, 2UL );

      col2 = col2 / 0.5;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 6 || col2[3] != 8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 6 8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != 6 || mat_(2,3) !=  8 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0  6  8 )\n"
                                     "(  0 -2  8  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major SparseColumn::scale()
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::scale()";

      initialize();

      // Integral scaling the 3rd column
      {
         CT col3 = column( mat_, 3UL );
         col3.scale( 3 );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 3UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 7UL );

         if( col3[0] != 0 || col3[1] != -6 || col3[2] != 12 || col3[3] != 15 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 -6 12 15 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
             mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  0 || mat_(1,3) != -6 ||
             mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) !=  3 || mat_(2,3) != 12 ||
             mat_(3,0) != 0 || mat_(3,1) != -6 || mat_(3,2) != 12 || mat_(3,3) != 15 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0 -6 )\n"
                                        "( 0  0  3 12 )\n"
                                        "( 0 -6 12 15 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Floating point scaling the 3rd column
      {
         CT col3 = column( mat_, 3UL );
         col3.scale( 0.5 );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 3UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 7UL );

         if( col3[0] != 0 || col3[1] != -3 || col3[2] != 6 || col3[3] != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 -3 6 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
             mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 0 || mat_(1,3) != -3 ||
             mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != 3 || mat_(2,3) !=  6 ||
             mat_(3,0) != 0 || mat_(3,1) != -3 || mat_(3,2) != 6 || mat_(3,3) !=  7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0 -3 )\n"
                                        "( 0  0  3  6 )\n"
                                        "( 0 -3  6  7 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v*=s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v*=s)";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      col2 *= 3;

      checkSize    ( col2 , 4UL );
      checkNonZeros( col2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 9 || col2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) !=  9 || tmat_(2,3) != 12 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 12 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  0 -2 )\n"
                                     "( 0  0  9 12 )\n"
                                     "( 0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v=v*s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v=v*s)";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      col2 = col2 * 3;

      checkSize    ( col2 , 4UL );
      checkNonZeros( col2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 9 || col2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) !=  9 || tmat_(2,3) != 12 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 12 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  0 -2 )\n"
                                     "( 0  0  9 12 )\n"
                                     "( 0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v=s*v)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v=s*v)";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      col2 = 3 * col2;

      checkSize    ( col2 , 4UL );
      checkNonZeros( col2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 9 || col2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) !=  9 || tmat_(2,3) != 12 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 12 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  0 -2 )\n"
                                     "( 0  0  9 12 )\n"
                                     "( 0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v/=s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v/=s)";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      col2 /= 0.5;

      checkSize    ( col2 , 4UL );
      checkNonZeros( col2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 6 || col2[3] != 8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 6 8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != 0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != 6 || tmat_(2,3) !=  8 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  0 -2 )\n"
                                     "( 0  0  6  8 )\n"
                                     "( 0 -2  8  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v=v/s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v=v/s)";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      col2 = col2 / 0.5;

      checkSize    ( col2 , 4UL );
      checkNonZeros( col2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != 6 || col2[3] != 8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 6 8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != 0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != 6 || tmat_(2,3) !=  8 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  0 -2 )\n"
                                     "( 0  0  6  8 )\n"
                                     "( 0 -2  8  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major SparseColumn::scale()
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn::scale()";

      initialize();

      // Integral scaling the 3rd column
      {
         TCT col3 = column( tmat_, 3UL );
         col3.scale( 3 );

         checkSize    ( col3 , 4UL );
         checkNonZeros( col3 , 3UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 7UL );

         if( col3[0] != 0 || col3[1] != -6 || col3[2] != 12 || col3[3] != 15 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 -6 12 15 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
             tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  0 || tmat_(1,3) != -6 ||
             tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) !=  3 || tmat_(2,3) != 12 ||
             tmat_(3,0) != 0 || tmat_(3,1) != -6 || tmat_(3,2) != 12 || tmat_(3,3) != 15 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n(  0  0  0  0 )\n"
                                        "(  0  1  0 -6 )\n"
                                        "( -2  0 -3 12 )\n"
                                        "(  7 -6 12 15 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Floating point scaling the 3rd column
      {
         TCT col3 = column( tmat_, 3UL );
         col3.scale( 0.5 );

         checkSize    ( col3 , 4UL );
         checkNonZeros( col3 , 3UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 7UL );

         if( col3[0] != 0 || col3[1] != -3 || col3[2] != 6 || col3[3] != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 -3 6 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
             tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != 0 || tmat_(1,3) != -3 ||
             tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != 3 || tmat_(2,3) !=  6 ||
             tmat_(3,0) != 0 || tmat_(3,1) != -3 || tmat_(3,2) != 6 || tmat_(3,3) !=  7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0 -3 )\n"
                                        "( 0  0 -3  6 )\n"
                                        "( 0 -3  6  7 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseColumn subscript operator.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of adding and accessing elements via the subscript operator
// of the SparseColumn class template. In case an error is detected, a \a std::runtime_error
// exception is thrown.
*/
void SymmetricTest::testSubscript()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::operator[]";

      initialize();

      CT col2 = column( mat_, 2UL );

      // Assignment to the element at index 1
      col2[1] = 9;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != 0 || col2[1] != 9 || col2[2] != 3 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 9 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 9 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  9 || mat_(2,2) != 3 || mat_(2,3) !=  4 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element at index 2
      col2[2] = 0;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 2UL );

      if( col2[0] != 0 || col2[1] != 9 || col2[2] != 0 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 9 0 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 9 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  9 || mat_(2,2) != 0 || mat_(2,3) !=  4 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  0  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element at index 3
      col2[3] = -8;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 2UL );

      if( col2[0] != 0 || col2[1] != 9 || col2[2] != 0 || col2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  9 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  9 || mat_(2,2) !=  0 || mat_(2,3) != -8 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != -8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  0 -8 )\n"
                                     "( 0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Addition assignment to the element at index 0
      col2[0] += -3;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -3 || col2[1] != 9 || col2[2] != 0 || col2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -3 9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -3 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) !=  9 || mat_(1,3) != -2 ||
          mat_(2,0) != -3 || mat_(2,1) !=  9 || mat_(2,2) !=  0 || mat_(2,3) != -8 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) != -8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1  9 -2 )\n"
                                     "( -3  9  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Subtraction assignment to the element at index 1
      col2[1] -= 6;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -3 || col2[1] != 3 || col2[2] != 0 || col2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -3 3 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -3 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) !=  3 || mat_(1,3) != -2 ||
          mat_(2,0) != -3 || mat_(2,1) !=  3 || mat_(2,2) !=  0 || mat_(2,3) != -8 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) != -8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1  3 -2 )\n"
                                     "( -3  3  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Multiplication assignment to the element at index 1
      col2[1] *= -3;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -3 || col2[1] != -9 || col2[2] != 0 || col2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -3 -9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -3 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) != -9 || mat_(1,3) != -2 ||
          mat_(2,0) != -3 || mat_(2,1) != -9 || mat_(2,2) !=  0 || mat_(2,3) != -8 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) != -8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1 -9 -2 )\n"
                                     "( -3 -9  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Division assignment to the element at index 3
      col2[3] /= 2;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -3 || col2[1] != -9 || col2[2] != 0 || col2[3] != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -3 -9 0 -4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -3 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) != -9 || mat_(1,3) != -2 ||
          mat_(2,0) != -3 || mat_(2,1) != -9 || mat_(2,2) !=  0 || mat_(2,3) != -4 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) != -4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1 -9 -2 )\n"
                                     "( -3 -9  0 -4 )\n"
                                     "(  0 -2 -4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::operator[]";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      // Assignment to the element at index 1
      col2[1] = 9;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != 0 || col2[1] != 9 || col2[2] != 3 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 9 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != 9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  9 || tmat_(2,2) != 3 || tmat_(2,3) !=  4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element at index 2
      col2[2] = 0;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 2UL );

      if( col2[0] != 0 || col2[1] != 9 || col2[2] != 0 || col2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 9 0 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != 9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  9 || tmat_(2,2) != 0 || tmat_(2,3) !=  4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  0  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element at index 3
      col2[3] = -8;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 2UL );

      if( col2[0] != 0 || col2[1] != 9 || col2[2] != 0 || col2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  9 || tmat_(2,2) !=  0 || tmat_(2,3) != -8 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != -8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  0 -8 )\n"
                                     "( 0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Addition assignment to the element at index 0
      col2[0] += -3;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -3 || col2[1] != 9 || col2[2] != 0 || col2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -3 9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -3 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -3 || tmat_(2,1) !=  9 || tmat_(2,2) !=  0 || tmat_(2,3) != -8 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) != -8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1  9 -2 )\n"
                                     "( -3  9  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Subtraction assignment to the element at index 1
      col2[1] -= 6;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -3 || col2[1] != 3 || col2[2] != 0 || col2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -3 3 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -3 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  3 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -3 || tmat_(2,1) !=  3 || tmat_(2,2) !=  0 || tmat_(2,3) != -8 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) != -8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1  3 -2 )\n"
                                     "( -3  3  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Multiplication assignment to the element at index 1
      col2[1] *= -3;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -3 || col2[1] != -9 || col2[2] != 0 || col2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -3 -9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -3 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) != -9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -3 || tmat_(2,1) != -9 || tmat_(2,2) !=  0 || tmat_(2,3) != -8 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) != -8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1 -9 -2 )\n"
                                     "( -3 -9  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Division assignment to the element at index 3
      col2[3] /= 2;

      checkSize    ( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -3 || col2[1] != -9 || col2[2] != 0 || col2[3] != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -3 -9 0 -4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -3 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) != -9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -3 || tmat_(2,1) != -9 || tmat_(2,2) !=  0 || tmat_(2,3) != -4 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) != -4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1 -9 -2 )\n"
                                     "( -3 -9  0 -4 )\n"
                                     "(  0 -2 -4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseColumn iterator implementation.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the iterator implementation of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testIterator()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      initialize();

      // Testing the Iterator default constructor
      {
         test_ = "Row-major Iterator default constructor";

         CT::Iterator it = CT::Iterator();

         if( it != CT::Iterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing the ConstIterator default constructor
      {
         test_ = "Row-major ConstIterator default constructor";

         CT::ConstIterator it = CT::ConstIterator();

         if( it != CT::ConstIterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing conversion from Iterator to ConstIterator
      {
         test_ = "Row-major Iterator/ConstIterator conversion";

         CT col2 = column( mat_, 2UL );
         CT::ConstIterator it( begin( col2 ) );

         if( it == end( col2 ) || it->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator conversion detected\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 1st column via Iterator
      {
         test_ = "Row-major Iterator subtraction";

         CT col1 = column( mat_, 1UL );
         const size_t number( end( col1 ) - begin( col1 ) );

         if( number != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 2nd column via ConstIterator
      {
         test_ = "Row-major ConstIterator subtraction";

         CT col2 = column( mat_, 2UL );
         const size_t number( cend( col2 ) - cbegin( col2 ) );

         if( number != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing read-only access via ConstIterator
      {
         test_ = "Row-major read-only access via ConstIterator";

         CT col2 = column( mat_, 2UL );
         CT::ConstIterator it ( cbegin( col2 ) );
         CT::ConstIterator end( cend( col2 ) );

         if( it == end || it->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid initial iterator detected\n";
            throw std::runtime_error( oss.str() );
         }

         ++it;

         if( it == end || it->value() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it++;

         if( it != end ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-increment failed\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment via Iterator
      {
         test_ = "Row-major assignment via Iterator";

         CT col3 = column( mat_, 3UL );
         int value = 6;

         for( CT::Iterator it=begin( col3 ); it!=end( col3 ); ++it ) {
            *it = value++;
         }

         if( col3[0] != 0 || col3[1] != 6 || col3[2] != 7 || col3[3] != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 6 7 8 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != 0 || mat_(0,3) != 0 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) != 0 || mat_(1,3) != 6 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != 3 || mat_(2,3) != 7 ||
             mat_(3,0) != 0 || mat_(3,1) != 6 || mat_(3,2) != 7 || mat_(3,3) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  6  7  8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing addition assignment via Iterator
      {
         test_ = "Row-major addition assignment via Iterator";

         CT col3 = column( mat_, 3UL );
         int value = 2;

         for( CT::Iterator it=begin( col3 ); it!=end( col3 ); ++it ) {
            *it += value++;
         }

         if( col3[0] != 0 || col3[1] != 8 || col3[2] != 10 || col3[3] != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 8 10 12 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  8 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) !=  3 || mat_(2,3) != 10 ||
             mat_(3,0) != 0 || mat_(3,1) != 8 || mat_(3,2) != 10 || mat_(3,3) != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  8 )\n"
                                        "( 0  0  3 10 )\n"
                                        "( 0  8 10 12 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing subtraction assignment via Iterator
      {
         test_ = "Row-major subtraction assignment via Iterator";

         CT col3 = column( mat_, 3UL );
         int value = 2;

         for( CT::Iterator it=begin( col3 ); it!=end( col3 ); ++it ) {
            *it -= value++;
         }

         if( col3[0] != 0 || col3[1] != 6 || col3[2] != 7 || col3[3] != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 6 7 8 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != 0 || mat_(0,3) != 0 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) != 0 || mat_(1,3) != 6 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != 3 || mat_(2,3) != 7 ||
             mat_(3,0) != 0 || mat_(3,1) != 6 || mat_(3,2) != 7 || mat_(3,3) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  6  7  8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing multiplication assignment via Iterator
      {
         test_ = "Row-major multiplication assignment via Iterator";

         CT col3 = column( mat_, 3UL );
         int value = 1;

         for( CT::Iterator it=begin( col3 ); it!=end( col3 ); ++it ) {
            *it *= value++;
         }

         if( col3[0] != 0 || col3[1] != 6 || col3[2] != 14 || col3[3] != 24 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 6 14 24 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  6 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) !=  3 || mat_(2,3) != 14 ||
             mat_(3,0) != 0 || mat_(3,1) != 6 || mat_(3,2) != 14 || mat_(3,3) != 24 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3 14 )\n"
                                        "( 0  6 14 24 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing division assignment via Iterator
      {
         test_ = "Row-major division assignment via Iterator";

         CT col3 = column( mat_, 3UL );

         for( CT::Iterator it=begin( col3 ); it!=end( col3 ); ++it ) {
            *it /= 2;
         }

         if( col3[0] != 0 || col3[1] != 3 || col3[2] != 7 || col3[3] != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 3 7 12 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) != 0 || mat_(1,3) !=  3 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != 3 || mat_(2,3) !=  7 ||
             mat_(3,0) != 0 || mat_(3,1) != 3 || mat_(3,2) != 7 || mat_(3,3) != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  3 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  3  7 12 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      initialize();

      // Testing the Iterator default constructor
      {
         test_ = "Column-major Iterator default constructor";

         TCT::Iterator it = TCT::Iterator();

         if( it != TCT::Iterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing the ConstIterator default constructor
      {
         test_ = "Column-major ConstIterator default constructor";

         TCT::ConstIterator it = TCT::ConstIterator();

         if( it != TCT::ConstIterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing conversion from Iterator to ConstIterator
      {
         test_ = "Column-major Iterator/ConstIterator conversion";

         TCT col2 = column( tmat_, 2UL );
         TCT::ConstIterator it( begin( col2 ) );

         if( it == end( col2 ) || it->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator conversion detected\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 1st column via Iterator
      {
         test_ = "Column-major Iterator subtraction";

         TCT col1 = column( tmat_, 1UL );
         const size_t number( end( col1 ) - begin( col1 ) );

         if( number != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 2nd column via ConstIterator
      {
         test_ = "Column-major ConstIterator subtraction";

         TCT col2 = column( tmat_, 2UL );
         const size_t number( cend( col2 ) - cbegin( col2 ) );

         if( number != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing read-only access via ConstIterator
      {
         test_ = "Column-major read-only access via ConstIterator";

         TCT col2 = column( tmat_, 2UL );
         TCT::ConstIterator it ( cbegin( col2 ) );
         TCT::ConstIterator end( cend( col2 ) );

         if( it == end || it->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid initial iterator detected\n";
            throw std::runtime_error( oss.str() );
         }

         ++it;

         if( it == end || it->value() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it++;

         if( it != end ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-increment failed\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment via Iterator
      {
         test_ = "Column-major assignment via Iterator";

         TCT col3 = column( tmat_, 3UL );
         int value = 6;

         for( TCT::Iterator it=begin( col3 ); it!=end( col3 ); ++it ) {
            *it = value++;
         }

         if( col3[0] != 0 || col3[1] != 6 || col3[2] != 7 || col3[3] != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 6 7 8 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) != 0 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) != 0 || tmat_(1,3) != 6 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != 3 || tmat_(2,3) != 7 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 6 || tmat_(3,2) != 7 || tmat_(3,3) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  6  7  8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing addition assignment via Iterator
      {
         test_ = "Column-major addition assignment via Iterator";

         TCT col3 = column( tmat_, 3UL );
         int value = 2;

         for( TCT::Iterator it=begin( col3 ); it!=end( col3 ); ++it ) {
            *it += value++;
         }

         if( col3[0] != 0 || col3[1] != 8 || col3[2] != 10 || col3[3] != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 8 10 12 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  8 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) !=  3 || tmat_(2,3) != 10 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 8 || tmat_(3,2) != 10 || tmat_(3,3) != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  8 )\n"
                                        "( 0  0  3 10 )\n"
                                        "( 0  8 10 12 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing subtraction assignment via Iterator
      {
         test_ = "Column-major subtraction assignment via Iterator";

         TCT col3 = column( tmat_, 3UL );
         int value = 2;

         for( TCT::Iterator it=begin( col3 ); it!=end( col3 ); ++it ) {
            *it -= value++;
         }

         if( col3[0] != 0 || col3[1] != 6 || col3[2] != 7 || col3[3] != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 6 7 8 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) != 0 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) != 0 || tmat_(1,3) != 6 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != 3 || tmat_(2,3) != 7 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 6 || tmat_(3,2) != 7 || tmat_(3,3) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  6  7  8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing multiplication assignment via Iterator
      {
         test_ = "Column-major multiplication assignment via Iterator";

         TCT col3 = column( tmat_, 3UL );
         int value = 1;

         for( TCT::Iterator it=begin( col3 ); it!=end( col3 ); ++it ) {
            *it *= value++;
         }

         if( col3[0] != 0 || col3[1] != 6 || col3[2] != 14 || col3[3] != 24 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 6 14 24 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  6 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) !=  3 || tmat_(2,3) != 14 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 6 || tmat_(3,2) != 14 || tmat_(3,3) != 24 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3 14 )\n"
                                        "( 0  6 14 24 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing division assignment via Iterator
      {
         test_ = "Column-major division assignment via Iterator";

         TCT col3 = column( tmat_, 3UL );

         for( TCT::Iterator it=begin( col3 ); it!=end( col3 ); ++it ) {
            *it /= 2;
         }

         if( col3[0] != 0 || col3[1] != 3 || col3[2] != 7 || col3[3] != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 3 7 12 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) != 0 || tmat_(1,3) !=  3 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != 3 || tmat_(2,3) !=  7 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 3 || tmat_(3,2) != 7 || tmat_(3,3) != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  3 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  3  7 12 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c nonZeros() member function of the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c nonZeros() member function of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testNonZeros()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::nonZeros()";

      initialize();

      // Initialization check
      CT col3 = column( mat_, 3UL );

      checkSize    ( col3, 4UL );
      checkNonZeros( col3, 3UL );

      if( col3[0] != 0 || col3[1] != -2 || col3[2] != 4 || col3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 -2 4 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the sparse column
      col3[2] = 0;

      checkSize    ( col3, 4UL );
      checkNonZeros( col3, 2UL );

      if( col3[0] != 0 || col3[1] != -2 || col3[2] != 0 || col3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 -2 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the sparse matrix
      mat_(3,0) = 5;

      checkSize    ( col3, 4UL );
      checkNonZeros( col3, 3UL );

      if( col3[0] != 5 || col3[1] != -2 || col3[2] != 0 || col3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 5 -2 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn::nonZeros()";

      initialize();

      // Initialization check
      TCT col3 = column( tmat_, 3UL );

      checkSize    ( col3, 4UL );
      checkNonZeros( col3, 3UL );

      if( col3[0] != 0 || col3[1] != -2 || col3[2] != 4 || col3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 -2 4 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the sparse column
      col3[2] = 0;

      checkSize    ( col3, 4UL );
      checkNonZeros( col3, 2UL );

      if( col3[0] != 0 || col3[1] != -2 || col3[2] != 0 || col3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 -2 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the sparse matrix
      tmat_(3,0) = 5;

      checkSize    ( col3, 4UL );
      checkNonZeros( col3, 3UL );

      if( col3[0] != 5 || col3[1] != -2 || col3[2] != 0 || col3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 5 -2 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c reset() member function of the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c reset() member function of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testReset()
{
   using blaze::reset;


   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::reset()";

      initialize();

      // Resetting a single element in column 3
      {
         CT col3 = column( mat_, 3UL );
         reset( col3[1] );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 2UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 5UL );

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 3rd column
      {
         CT col3 = column( mat_, 3UL );
         reset( col3 );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 0UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 2UL );

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 0 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn::reset()";

      initialize();

      // Resetting a single element in column 3
      {
         TCT col3 = column( tmat_, 3UL );
         reset( col3[1] );

         checkSize    ( col3 , 4UL );
         checkNonZeros( col3 , 2UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 5UL );

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 3rd column
      {
         TCT col3 = column( tmat_, 3UL );
         reset( col3 );

         checkSize    ( col3 , 4UL );
         checkNonZeros( col3 , 0UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 2UL );

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 0 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c clear() function with the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c clear() function with the SparseColumn class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testClear()
{
   using blaze::clear;


   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major clear() function";

      initialize();

      // Clearing a single element in column 3
      {
         CT col3 = column( mat_, 3UL );
         clear( col3[1] );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 2UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 5UL );

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Clear operation failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major clear() function";

      initialize();

      // Clearing a single element in column 3
      {
         TCT col3 = column( tmat_, 3UL );
         clear( col3[1] );

         checkSize    ( col3 , 4UL );
         checkNonZeros( col3 , 2UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 5UL );

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Clear operation failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c set() member function of the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c set() member function of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testSet()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::set()";

      initialize();

      CT col0 = column( mat_, 0UL );

      // Setting a non-zero element at the end of the column
      {
         CT::Iterator pos = col0.set( 3UL, 1 );

         checkSize    ( col0, 4UL );
         checkNonZeros( col0, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 9UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 0 || col0[1] != 0 || col0[2] != 0 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 0 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a non-zero element at the beginning of the column
      {
         CT::Iterator pos = col0.set( 0UL, 2 );

         checkSize    ( col0,  4UL );
         checkNonZeros( col0,  2UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  4UL );
         checkNonZeros( mat_, 10UL );

         if( pos->value() != 2 || pos->index() != 0UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 0\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 2 || col0[1] != 0 || col0[2] != 0 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 2 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a non-zero element at the center of the column
      {
         CT::Iterator pos = col0.set( 2UL, 3 );

         checkSize    ( col0,  4UL );
         checkNonZeros( col0,  3UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  4UL );
         checkNonZeros( mat_, 12UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 2 || col0[1] != 0 || col0[2] != 3 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 2 0 3 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting an already existing element
      {
         CT::Iterator pos = col0.set( 3UL, 4 );

         checkSize    ( col0,  4UL );
         checkNonZeros( col0,  3UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  4UL );
         checkNonZeros( mat_, 12UL );

         if( pos->value() != 4 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 2 || col0[1] != 0 || col0[2] != 3 || col0[3] != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 2 0 3 4 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn::set()";

      initialize();

      TCT col0 = column( tmat_, 0UL );

      // Setting a non-zero element at the end of the column
      {
         TCT::Iterator pos = col0.set( 3UL, 1 );

         checkSize    ( col0 , 4UL );
         checkNonZeros( col0 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 9UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 0 || col0[1] != 0 || col0[2] != 0 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 0 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a non-zero element at the beginning of the column
      {
         TCT::Iterator pos = col0.set( 0UL, 2 );

         checkSize    ( col0 ,  4UL );
         checkNonZeros( col0 ,  2UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  4UL );
         checkNonZeros( tmat_, 10UL );

         if( pos->value() != 2 || pos->index() != 0UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 0\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 2 || col0[1] != 0 || col0[2] != 0 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 2 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a non-zero element at the center of the column
      {
         TCT::Iterator pos = col0.set( 2UL, 3 );

         checkSize    ( col0 ,  4UL );
         checkNonZeros( col0 ,  3UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  4UL );
         checkNonZeros( tmat_, 12UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 2 || col0[1] != 0 || col0[2] != 3 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 2 0 3 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting an already existing element
      {
         TCT::Iterator pos = col0.set( 3UL, 4 );

         checkSize    ( col0 ,  4UL );
         checkNonZeros( col0 ,  3UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  4UL );
         checkNonZeros( tmat_, 12UL );

         if( pos->value() != 4 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 2 || col0[1] != 0 || col0[2] != 3 || col0[3] != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 2 0 3 4 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c insert() member function of the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c insert() member function of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testInsert()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::insert()";

      initialize();

      CT col0 = column( mat_, 0UL );

      // Inserting a non-zero element at the end of the column
      {
         CT::Iterator pos = col0.insert( 3UL, 1 );

         checkSize    ( col0, 4UL );
         checkNonZeros( col0, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 9UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 0 || col0[1] != 0 || col0[2] != 0 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 0 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a non-zero element at the beginning of the column
      {
         CT::Iterator pos = col0.insert( 0UL, 2 );

         checkSize    ( col0,  4UL );
         checkNonZeros( col0,  2UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  4UL );
         checkNonZeros( mat_, 10UL );

         if( pos->value() != 2 || pos->index() != 0UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 0\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 2 || col0[1] != 0 || col0[2] != 0 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 2 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a non-zero element at the center of the column
      {
         CT::Iterator pos = col0.insert( 2UL, 3 );

         checkSize    ( col0,  4UL );
         checkNonZeros( col0,  3UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  4UL );
         checkNonZeros( mat_, 12UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 2 || col0[1] != 0 || col0[2] != 3 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 2 0 3 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to insert an already existing element
      try {
         col0.insert( 3UL, 4 );

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Inserting an existing element succeeded\n"
             << " Details:\n"
             << "   Result:\n" << col0 << "\n"
             << "   Expected result:\n( 2 0 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn::insert()";

      initialize();

      TCT col0 = column( tmat_, 0UL );

      // Inserting a non-zero element at the end of the column
      {
         TCT::Iterator pos = col0.insert( 3UL, 1 );

         checkSize    ( col0 , 4UL );
         checkNonZeros( col0 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 9UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 0 || col0[1] != 0 || col0[2] != 0 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 0 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a non-zero element at the beginning of the column
      {
         TCT::Iterator pos = col0.insert( 0UL, 2 );

         checkSize    ( col0 ,  4UL );
         checkNonZeros( col0 ,  2UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  4UL );
         checkNonZeros( tmat_, 10UL );

         if( pos->value() != 2 || pos->index() != 0UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 0\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 2 || col0[1] != 0 || col0[2] != 0 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 2 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a non-zero element at the center of the column
      {
         TCT::Iterator pos = col0.insert( 2UL, 3 );

         checkSize    ( col0 ,  4UL );
         checkNonZeros( col0 ,  3UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  4UL );
         checkNonZeros( tmat_, 12UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( col0[0] != 2 || col0[1] != 0 || col0[2] != 3 || col0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 2 0 3 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to insert an already existing element
      try {
         col0.insert( 3UL, 4 );

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Inserting an existing element succeeded\n"
             << " Details:\n"
             << "   Result:\n" << col0 << "\n"
             << "   Expected result:\n( 2 0 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c append() member function of the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c append() member function of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testAppend()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::append()";

      MT mat( 9UL );

      CT col1 = column( mat, 1UL );
      col1.reserve( 4UL );

      // Appending one non-zero element
      col1.append( 1UL, 1 );

      checkSize    ( col1, 9UL );
      checkCapacity( col1, 4UL );
      checkNonZeros( col1, 1UL );
      checkRows    ( mat , 9UL );
      checkColumns ( mat , 9UL );
      checkNonZeros( mat , 1UL );

      if( col1[1] != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 0 1 0 0 0 0 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat(1,1) != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n";
         throw std::runtime_error( oss.str() );
      }

      // Appending three more non-zero elements
      col1.append( 3UL, 2 );
      col1.append( 4UL, 3 );
      col1.append( 8UL, 4 );

      checkSize    ( col1, 9UL );
      checkCapacity( col1, 4UL );
      checkNonZeros( col1, 4UL );
      checkRows    ( mat , 9UL );
      checkColumns ( mat , 9UL );
      checkNonZeros( mat , 7UL );

      if( col1[1] != 1 || col1[3] != 2 || col1[4] != 3 || col1[8] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Append operation failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 0 1 0 2 3 0 0 0 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat(1,1) != 1 || mat(1,3) != 2 || mat(1,4) != 3 || mat(1,8) != 4 ||
          mat(3,1) != 2 || mat(4,1) != 3 || mat(8,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn::append()";

      TMT mat( 9UL );

      TCT col1 = column( mat, 1UL );
      col1.reserve( 4UL );

      // Appending one non-zero element
      col1.append( 1UL, 1 );

      checkSize    ( col1, 9UL );
      checkCapacity( col1, 4UL );
      checkNonZeros( col1, 1UL );
      checkRows    ( mat , 9UL );
      checkColumns ( mat , 9UL );
      checkNonZeros( mat , 1UL );

      if( col1[1] != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 0 1 0 0 0 0 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat(1,1) != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n";
         throw std::runtime_error( oss.str() );
      }

      // Appending three more non-zero elements
      col1.append( 3UL, 2 );
      col1.append( 4UL, 3 );
      col1.append( 8UL, 4 );

      checkSize    ( col1, 9UL );
      checkCapacity( col1, 4UL );
      checkNonZeros( col1, 4UL );
      checkRows    ( mat , 9UL );
      checkColumns ( mat , 9UL );
      checkNonZeros( mat , 7UL );

      if( col1[1] != 1 || col1[3] != 2 || col1[4] != 3 || col1[8] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Append operation failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 0 1 0 2 3 0 0 0 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat(1,1) != 1 || mat(1,3) != 2 || mat(1,4) != 3 || mat(1,8) != 4 ||
          mat(3,1) != 2 || mat(4,1) != 3 || mat(8,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c erase() member function of the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c erase() member function of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testErase()
{
   //=====================================================================================
   // Row-major index-based erase function
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::erase( size_t )";

      initialize();

      CT col3 = column( mat_, 3UL );

      // Erasing the non-zero element at the end of the column
      col3.erase( 3UL );

      checkSize    ( col3, 4UL );
      checkNonZeros( col3, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 6UL );

      if( col3[0] != 0 || col3[1] != -2 || col3[2] != 4 || col3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 -2 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the non-zero element at the beginning of the column
      col3.erase( 1UL );

      checkSize    ( col3, 4UL );
      checkNonZeros( col3, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 4UL );

      if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Trying to erase an already erased element
      col3.erase( 3UL );

      checkSize    ( col3, 4UL );
      checkNonZeros( col3, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 4UL );

      if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major iterator-based erase function
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::erase( Iterator )";

      initialize();

      CT col3 = column( mat_, 3UL );

      // Erasing the non-zero element at the end of the column
      {
         CT::Iterator pos = col3.erase( col3.find( 3UL ) );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 2UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 6UL );

         if( pos != col3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( col3[0] != 0 || col3[1] != -2 || col3[2] != 4 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 -2 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the non-zero element at the beginning of the column
      {
         CT::Iterator pos = col3.erase( col3.find( 1UL ) );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 4UL );

         if( pos->value() != 4 || pos->index() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase an already erased element
      {
         CT::Iterator pos = col3.erase( col3.find( 3UL ) );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 4UL );

         if( pos != col3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major iterator-range-based erase function
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::erase( Iterator, Iterator )";

      initialize();

      // Erasing the 2nd column
      {
         CT col2 = column( mat_, 2UL );

         CT::Iterator pos = col2.erase( col2.begin(), col2.end() );

         checkSize    ( col2, 4UL );
         checkNonZeros( col2, 0UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 4UL );

         if( pos != col2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( col2[0] != 0 || col2[1] != 0 || col2[2] != 0 || col2[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing the column failed\n"
                << " Details:\n"
                << "   Result:\n" << col2 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the first half of the 3th column
      {
         CT col3 = column( mat_, 3UL );

         CT::Iterator pos = col3.erase( col3.begin(), col3.find( 3UL ) );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 2UL );

         if( pos->value() != 5 || pos->index() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 0 || col3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a partial column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 0 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the second half of the 4th column
      {
         CT col3 = column( mat_, 3UL );

         CT::Iterator pos = col3.erase( col3.find( 3UL ), col3.end() );

         checkSize    ( col3, 4UL );
         checkNonZeros( col3, 0UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 1UL );

         if( pos != col3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 0 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a partial column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase an empty range
      {
         CT col1 = column( mat_, 1UL );

         CT::Iterator pos = col1.erase( col1.find( 1UL ), col1.find( 1UL ) );

         checkSize    ( col1, 4UL );
         checkNonZeros( col1, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 1UL );

         if( pos != col1.find( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the given end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( col1[0] != 0 || col1[1] != 1 || col1[2] != 0 || col1[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing an empty range failed\n"
                << " Details:\n"
                << "   Result:\n" << col1 << "\n"
                << "   Expected result:\n( 0 1 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major index-based erase function
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn::erase( size_t )";

      initialize();

      TCT col3 = column( tmat_, 3UL );

      // Erasing the non-zero element at the end of the column
      col3.erase( 3UL );

      checkSize    ( col3 , 4UL );
      checkNonZeros( col3 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 6UL );

      if( col3[0] != 0 || col3[1] != -2 || col3[2] != 4 || col3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 -2 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the non-zero element at the beginning of the column
      col3.erase( 1UL );

      checkSize    ( col3 , 4UL );
      checkNonZeros( col3 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 4UL );

      if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Trying to erase an already erased element
      col3.erase( 3UL );

      checkSize    ( col3 , 4UL );
      checkNonZeros( col3 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 4UL );

      if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major iterator-based erase function
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::erase( Iterator )";

      initialize();

      TCT col3 = column( tmat_, 3UL );

      // Erasing the non-zero element at the end of the column
      {
         TCT::Iterator pos = col3.erase( col3.find( 3UL ) );

         checkSize    ( col3 , 4UL );
         checkNonZeros( col3 , 2UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 6UL );

         if( pos != col3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( col3[0] != 0 || col3[1] != -2 || col3[2] != 4 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 -2 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the non-zero element at the beginning of the column
      {
         TCT::Iterator pos = col3.erase( col3.find( 1UL ) );

         checkSize    ( col3 , 4UL );
         checkNonZeros( col3 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 4UL );

         if( pos->value() != 4 || pos->index() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase an already erased element
      {
         TCT::Iterator pos = col3.erase( col3.find( 3UL ) );

         checkSize    ( col3 , 4UL );
         checkNonZeros( col3 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 4UL );

         if( pos != col3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 4 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major iterator-range-based erase function
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::erase( Iterator, Iterator )";

      initialize();

      // Erasing the 2nd column
      {
         TCT col2 = column( tmat_, 2UL );

         TCT::Iterator pos = col2.erase( col2.begin(), col2.end() );

         checkSize    ( col2 , 4UL );
         checkNonZeros( col2 , 0UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 4UL );

         if( pos != col2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( col2[0] != 0 || col2[1] != 0 || col2[2] != 0 || col2[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing the column failed\n"
                << " Details:\n"
                << "   Result:\n" << col2 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the first half of the 3th column
      {
         TCT col3 = column( tmat_, 3UL );

         TCT::Iterator pos = col3.erase( col3.begin(), col3.find( 3UL ) );

         checkSize    ( col3 , 4UL );
         checkNonZeros( col3 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 2UL );

         if( pos->value() != 5 || pos->index() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 0 || col3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a partial column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 0 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the second half of the 4th column
      {
         TCT col3 = column( tmat_, 3UL );

         TCT::Iterator pos = col3.erase( col3.find( 3UL ), col3.end() );

         checkSize    ( col3 , 4UL );
         checkNonZeros( col3 , 0UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 1UL );

         if( pos != col3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 0 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a partial column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase an empty range
      {
         TCT col1 = column( tmat_, 1UL );

         TCT::Iterator pos = col1.erase( col1.find( 1UL ), col1.find( 1UL ) );

         checkSize    ( col1 , 4UL );
         checkNonZeros( col1 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 1UL );

         if( pos != col1.find( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the given end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( col1[0] != 0 || col1[1] != 1 || col1[2] != 0 || col1[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing an empty range failed\n"
                << " Details:\n"
                << "   Result:\n" << col1 << "\n"
                << "   Expected result:\n( 0 1 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c reserve() member function of the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c reserve() member function of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testReserve()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::reserve()";

      MT mat( 20UL );

      CT col0 = column( mat, 0UL );

      // Increasing the capacity of the column
      col0.reserve( 10UL );

      checkSize    ( col0, 20UL );
      checkCapacity( col0, 10UL );
      checkNonZeros( col0,  0UL );

      // Further increasing the capacity of the column
      col0.reserve( 15UL );

      checkSize    ( col0, 20UL );
      checkCapacity( col0, 15UL );
      checkNonZeros( col0,  0UL );
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn::reserve()";

      TMT mat( 20UL );

      TCT col0 = column( mat, 0UL );

      // Increasing the capacity of the column
      col0.reserve( 10UL );

      checkSize    ( col0, 20UL );
      checkCapacity( col0, 10UL );
      checkNonZeros( col0,  0UL );

      // Further increasing the capacity of the column
      col0.reserve( 15UL );

      checkSize    ( col0, 20UL );
      checkCapacity( col0, 15UL );
      checkNonZeros( col0,  0UL );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c find() member function of the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c find() member function of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testFind()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::find()";

      initialize();

      CT col2 = column( mat_, 2UL );

      // Searching for the first element
      {
         CT::Iterator pos = col2.find( 2UL );

         if( pos == col2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Current column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 3\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for the second element
      {
         CT::Iterator pos = col2.find( 3UL );

         if( pos == col2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Current column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 4\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for a non-existing non-zero element
      {
         CT::Iterator pos = col2.find( 1UL );

         if( pos != col2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Non-existing element could be found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 0\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn::find()";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      // Searching for the first element
      {
         TCT::Iterator pos = col2.find( 2UL );

         if( pos == col2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Current column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 3\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for the second element
      {
         TCT::Iterator pos = col2.find( 3UL );

         if( pos == col2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Current column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 4\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for a non-existing non-zero element
      {
         TCT::Iterator pos = col2.find( 1UL );

         if( pos != col2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Non-existing element could be found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 0\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c lowerBound() member function of the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c lowerBound() member function of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testLowerBound()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::lowerBound()";

      initialize();

      CT col1 = column( mat_, 1UL );

      // Determining the lower bound for index 0
      {
         CT::Iterator pos = col1.lowerBound( 0UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for index 1
      {
         CT::Iterator pos = col1.lowerBound( 1UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for index 2
      {
         CT::Iterator pos = col1.lowerBound( 2UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn::lowerBound()";

      initialize();

      TCT col1 = column( tmat_, 1UL );

      // Determining the lower bound for index 0
      {
         TCT::Iterator pos = col1.lowerBound( 0UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for index 1
      {
         TCT::Iterator pos = col1.lowerBound( 1UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for index 2
      {
         TCT::Iterator pos = col1.lowerBound( 2UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c upperBound() member function of the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c upperBound() member function of the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testUpperBound()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseColumn::upperBound()";

      initialize();

      CT col1 = column( mat_, 1UL );

      // Determining the upper bound for index 0
      {
         CT::Iterator pos = col1.upperBound( 0UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for index 1
      {
         CT::Iterator pos = col1.upperBound( 1UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for index 2
      {
         CT::Iterator pos = col1.upperBound( 2UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseColumn::upperBound()";

      initialize();

      TCT col1 = column( tmat_, 1UL );

      // Determining the upper bound for index 0
      {
         TCT::Iterator pos = col1.upperBound( 0UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for index 1
      {
         TCT::Iterator pos = col1.upperBound( 1UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for index 2
      {
         TCT::Iterator pos = col1.upperBound( 2UL );

         if( pos == col1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isDefault() function with the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isDefault() function with the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testIsDefault()
{
   using blaze::isDefault;


   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDefault() function";

      initialize();

      // isDefault with default column
      {
         CT col0 = column( mat_, 0UL );

         if( isDefault( col0[1] ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column element: " << col0[1] << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( col0 ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col0 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with non-default column
      {
         CT col1 = column( mat_, 1UL );

         if( isDefault( col1[1] ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column element: " << col1[1] << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( col1 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDefault() function";

      initialize();

      // isDefault with default column
      {
         TCT col0 = column( tmat_, 0UL );

         if( isDefault( col0[1] ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column element: " << col0[1] << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( col0 ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col0 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with non-default column
      {
         TCT col1 = column( tmat_, 1UL );

         if( isDefault( col1[1] ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column element: " << col1[1] << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( col1 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isSame() function with the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isSame() function with the SparseColumn class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testIsSame()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSame() function";

      // isSame with matching columns
      {
         CT col1 = column( mat_, 1UL );
         CT col2 = column( mat_, 1UL );

         if( blaze::isSame( col1, col2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching columns
      {
         CT col1 = column( mat_, 1UL );
         CT col2 = column( mat_, 2UL );

         if( blaze::isSame( col1, col2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and matching subvector
      {
         typedef blaze::SparseSubvector<CT>  SubvectorType;

         CT col1 = column( mat_, 1UL );
         SubvectorType sv = subvector( col1, 0UL, 4UL );

         if( blaze::isSame( col1, sv ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and non-matching subvector (different size)
      {
         typedef blaze::SparseSubvector<CT>  SubvectorType;

         CT col1 = column( mat_, 1UL );
         SubvectorType sv = subvector( col1, 0UL, 3UL );

         if( blaze::isSame( col1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and non-matching subvector (different offset)
      {
         typedef blaze::SparseSubvector<CT>  SubvectorType;

         CT col1 = column( mat_, 1UL );
         SubvectorType sv = subvector( col1, 1UL, 3UL );

         if( blaze::isSame( col1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching columns on submatrices
      {
         typedef blaze::SparseSubmatrix<MT>          SubmatrixType;
         typedef blaze::SparseColumn<SubmatrixType>  ColumnType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 2UL, 3UL );
         ColumnType col1 = column( sm, 1UL );
         ColumnType col2 = column( sm, 1UL );

         if( blaze::isSame( col1, col2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching columns on submatrices
      {
         typedef blaze::SparseSubmatrix<MT>          SubmatrixType;
         typedef blaze::SparseColumn<SubmatrixType>  ColumnType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 2UL, 3UL );
         ColumnType col1 = column( sm, 0UL );
         ColumnType col2 = column( sm, 1UL );

         if( blaze::isSame( col1, col2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching column subvectors on submatrices
      {
         typedef blaze::SparseSubmatrix<MT>          SubmatrixType;
         typedef blaze::SparseColumn<SubmatrixType>  ColumnType;
         typedef blaze::SparseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 0UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching column subvectors on submatrices (different size)
      {
         typedef blaze::SparseSubmatrix<MT>          SubmatrixType;
         typedef blaze::SparseColumn<SubmatrixType>  ColumnType;
         typedef blaze::SparseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 0UL, 3UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching column subvectors on submatrices (different offset)
      {
         typedef blaze::SparseSubmatrix<MT>          SubmatrixType;
         typedef blaze::SparseColumn<SubmatrixType>  ColumnType;
         typedef blaze::SparseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 1UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSame() function";

      // isSame with matching columns
      {
         TCT col1 = column( tmat_, 1UL );
         TCT col2 = column( tmat_, 1UL );

         if( blaze::isSame( col1, col2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching columns
      {
         TCT col1 = column( tmat_, 1UL );
         TCT col2 = column( tmat_, 2UL );

         if( blaze::isSame( col1, col2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and matching subvector
      {
         typedef blaze::SparseSubvector<TCT>  SubvectorType;

         TCT col1 = column( tmat_, 1UL );
         SubvectorType sv = subvector( col1, 0UL, 4UL );

         if( blaze::isSame( col1, sv ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and non-matching subvector (different size)
      {
         typedef blaze::SparseSubvector<TCT>  SubvectorType;

         TCT col1 = column( tmat_, 1UL );
         SubvectorType sv = subvector( col1, 0UL, 3UL );

         if( blaze::isSame( col1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and non-matching subvector (different offset)
      {
         typedef blaze::SparseSubvector<TCT>  SubvectorType;

         TCT col1 = column( tmat_, 1UL );
         SubvectorType sv = subvector( col1, 1UL, 3UL );

         if( blaze::isSame( col1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse column:\n" << col1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching columns on submatrices
      {
         typedef blaze::SparseSubmatrix<TMT>         SubmatrixType;
         typedef blaze::SparseColumn<SubmatrixType>  ColumnType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 2UL, 3UL );
         ColumnType col1 = column( sm, 1UL );
         ColumnType col2 = column( sm, 1UL );

         if( blaze::isSame( col1, col2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching columns on submatrices
      {
         typedef blaze::SparseSubmatrix<TMT>         SubmatrixType;
         typedef blaze::SparseColumn<SubmatrixType>  ColumnType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 2UL, 3UL );
         ColumnType col1 = column( sm, 0UL );
         ColumnType col2 = column( sm, 1UL );

         if( blaze::isSame( col1, col2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching column subvectors on submatrices
      {
         typedef blaze::SparseSubmatrix<TMT>         SubmatrixType;
         typedef blaze::SparseColumn<SubmatrixType>  ColumnType;
         typedef blaze::SparseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 0UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching column subvectors on submatrices (different size)
      {
         typedef blaze::SparseSubmatrix<TMT>         SubmatrixType;
         typedef blaze::SparseColumn<SubmatrixType>  ColumnType;
         typedef blaze::SparseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 0UL, 3UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching column subvectors on submatrices (different offset)
      {
         typedef blaze::SparseSubmatrix<TMT>         SubmatrixType;
         typedef blaze::SparseColumn<SubmatrixType>  ColumnType;
         typedef blaze::SparseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 1UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c subvector() function with the SparseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c subvector() function used with the SparseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testSubvector()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major subvector() function";

      initialize();

      typedef blaze::SparseSubvector<CT>  SubvectorType;

      CT col1 = column( mat_, 1UL );
      SubvectorType sv = subvector( col1, 0UL, 4UL );

      if( sv[1] != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator access failed\n"
             << " Details:\n"
             << "   Result: " << sv[1] << "\n"
             << "   Expected result: 1\n";
         throw std::runtime_error( oss.str() );
      }

      if( sv.begin()->value() != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << sv.begin()->value() << "\n"
             << "   Expected result: 1\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major subvector() function";

      initialize();

      typedef blaze::SparseSubvector<TCT>  SubvectorType;

      TCT col1 = column( tmat_, 1UL );
      SubvectorType sv = subvector( col1, 0UL, 4UL );

      if( sv[1] != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator access failed\n"
             << " Details:\n"
             << "   Result: " << sv[1] << "\n"
             << "   Expected result: 1\n";
         throw std::runtime_error( oss.str() );
      }

      if( sv.begin()->value() != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << sv.begin()->value() << "\n"
             << "   Expected result: 1\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************




//=================================================================================================
//
//  UTILITY FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Initialization of all member matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function initializes all member matrices to specific predetermined values.
*/
void SymmetricTest::initialize()
{
   // Initializing the symmetric row-major matrix
   mat_.reset();
   mat_(1,1) =  1;
   mat_(1,3) = -2;
   mat_(2,2) =  3;
   mat_(2,3) =  4;
   mat_(3,3) =  5;

   // Initializing the symmetric column-major matrix
   tmat_.reset();
   tmat_(1,1) =  1;
   tmat_(1,3) = -2;
   tmat_(2,2) =  3;
   tmat_(2,3) =  4;
   tmat_(3,3) =  5;
}
//*************************************************************************************************

} // namespace sparsecolumn

} // namespace mathtest

} // namespace blazetest




//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running symmetric SparseColumn class test..." << std::endl;

   try
   {
      RUN_SPARSECOLUMN_CLASS_TEST;
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during symmetric SparseColumn class test:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************