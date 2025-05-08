/*    noamgal46@gmail.com    */


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include <sstream>
using namespace matrix;

TEST_CASE("SquareMat test"){
    SUBCASE("regular, empty and copy constructor"){
        SquareMat sm0;
        CHECK(sm0[0][0] == 0);
        SquareMat sm1(10);
        sm0[0][0] = 1;
        CHECK(sm1 != sm0);
        SquareMat sm2(sm0);
        CHECK(sm2 == sm0);
    }
    SUBCASE("operator[]"){
    SquareMat sm;
    sm[0][0] = 6;
    CHECK(sm[0][0] == 6);
    sm[0][0] = 3;
    CHECK(sm[0][0] == 3);
    }
    SUBCASE("operator==, operator!=, operator="){
        SquareMat sm1(10);
        SquareMat sm2(2);
        sm1[0][0] = 4;
        CHECK(sm1 != sm2);
        sm2[1][1] = 1;
        sm2[1][0] = 3;
        CHECK(sm1 == sm2);
        SquareMat sm3;
        sm3 = sm2;
        CHECK(sm3 == sm2);
        CHECK(sm3.equal(sm2));

        }
    SUBCASE("operator+ and operator-"){
        SquareMat sm1(3);
        double input1[] = {3,7,4,2,7,4,3,5,2};
        sm1.helper(input1);
        SquareMat sm2(3);
        double input2[] = {6,2,6,8,5,24,4,5,1};
        sm2.helper(input2);
        SquareMat ans1(3);
        SquareMat ans2(3);
        double inputForAns1[] = {9,9,10,10,12,28,7,10,3};
        ans1.helper(inputForAns1);
        double inputForAns2[] = {-3,5,-2,-6,2,-20,-1,0,1};
        ans2.helper(inputForAns2);
        CHECK(sm1 + sm2 == ans1);
        CHECK(ans1.equal(sm1 + sm2));
        CHECK(sm1 - sm2 == ans2);
        CHECK(ans2.equal(sm1 - sm2));

    }
    SUBCASE("-mat"){
        SquareMat sm1(3);
        double arr[] = {3,7,4,2,7,4,3,5,2};
        SquareMat ans(3);
        double inputAns[] = {-3,-7,-4,-2,-7,-4,-3,-5,-2};
        sm1.helper(arr);
        ans.helper(inputAns);
        SquareMat ans1;
        ans1 = -sm1;
        CHECK(ans1 == ans);
        CHECK(ans.equal(ans1));
    }
    SUBCASE("operator*"){
        SquareMat sm1(5);
        SquareMat sm2(5);
        SquareMat ans;
        double inputSm1[] = {7,3,6,3,-4,8,3,-23,5,8,0,10,5,-3,5,-67,7,23,8,-34,0,45,23,0,40};
        double inputSm2[] = {4,8,-4,34,2,74,0,4,-3,2,45,6,-4,-64,3,76,8,4,-4,0,11,22,32,-1,0};
        sm1.helper(inputSm1);
        sm2.helper(inputSm2);
        ans[0][0]= 4524;
        CHECK(sm1 * sm2 == ans);
    }
    SUBCASE("*scalar and scalar*"){
        SquareMat sm(5);
        SquareMat ans;
        double inputSm[] = {7,3,6,3,-4,8,3,-23,5,8,0,10,5,-3,5,-67,7,23,8,-34,0,45,23,0,40};
        double scalar = 0;
        sm.helper(inputSm);
        ans[0][0] = 0;
        CHECK(ans == sm * scalar);
        CHECK(ans == scalar * sm);
        scalar = -3;
        ans[0][0] = -234;
        CHECK(ans == sm * scalar);
        CHECK(ans == scalar * sm);
        scalar = 13;
        ans[0][0] = 1014;
        CHECK(ans == sm * scalar);
        CHECK(ans == scalar * sm);
    }
    SUBCASE("operator/"){
        SquareMat sm(5);
        SquareMat ans;
        double inputSm[] = {7,3,6,3,-4,8,3,-23,5,8,0,10,5,-3,5,-67,7,23,8,-34,0,45,23,0,40};
        sm.helper(inputSm);
        double scalar = 0;
        CHECK_THROWS_AS(sm / scalar, std::invalid_argument);
        scalar = -5;
        ans[0][0] = -15.6;
        CHECK(ans == sm / scalar);
        scalar = 4;
        ans[0][0] = 19.5;
        CHECK(ans == sm / scalar);    
    }
    SUBCASE("operator++ and operator--"){
        SquareMat sm(5);
        SquareMat ans;
        double inputSm[] = {7,3,6,3,-4,8,3,-23,5,8,0,10,5,-3,5,-67,7,23,8,-34,0,45,23,0,40};
        sm.helper(inputSm);
        ans[0][0] = 78;
        CHECK(sm++ == ans);
        ans[0][0] = 78 + 25;
        CHECK(sm == ans);
        ans[0][0] = 78 +25 + 25;
        CHECK(++sm == ans);
        CHECK(sm-- == ans);
        ans[0][0] = 78;
        CHECK(--sm == ans);
    }
    SUBCASE("operator > < >= <= "){
        SquareMat sm(5);
        SquareMat ans;
        double inputSm[] = {7,3,6,3,-4,8,3,-23,5,8,0,10,5,-3,5,-67,7,23,8,-34,0,45,23,0,40};
        sm.helper(inputSm);
        ans[0][0] = 78;
        CHECK(sm >= ans);
        CHECK(sm <= ans);
        CHECK(++sm > ans);
        CHECK(sm >= ans);
        CHECK(ans <= sm);
        CHECK(ans < sm);
    }
    SUBCASE("operator+= and operator-="){
        SquareMat sm1(3);
        double input1[] = {3,7,4,2,7,4,3,5,2};
        sm1.helper(input1);
        SquareMat sm2(3);
        double input2[] = {6,2,6,8,5,24,4,5,1};
        sm2.helper(input2);
        sm1 += sm2;
        SquareMat ans;
        ans[0][0] = 98;
        CHECK(sm1 == ans);
        sm2 -= sm1;
        ans[0][0] = -37;
        CHECK(sm2 == ans);
    }
    SUBCASE("operator/="){
        SquareMat sm(5);
        SquareMat ans;
        double inputSm[] = {7,3,6,3,-4,8,3,-23,5,8,0,10,5,-3,5,-67,7,23,8,-34,0,45,23,0,40};
        sm.helper(inputSm);
        double scalar = -5;
        ans[0][0] = -15.6;
        sm /= scalar;
        CHECK(sm == ans);
        scalar = 4;
        ans[0][0] = 19.5;
        sm.helper(inputSm);
        sm /= scalar;
        CHECK(sm == ans);
    }
    SUBCASE("operator *="){
        SquareMat sm1(5);
        SquareMat sm2(5);
        SquareMat ans;
        double inputSm1[] = {7,3,6,3,-4,8,3,-23,5,8,0,10,5,-3,5,-67,7,23,8,-34,0,45,23,0,40};
        sm1.helper(inputSm1);
        double inputSm2[] = {4,8,-4,34,2,74,0,4,-3,2,45,6,-4,-64,3,76,8,4,-4,0,11,22,32,-1,0};
        sm2.helper(inputSm2);
        ans[0][0]= 4524;
        sm1 *= sm2;
        CHECK(sm1 == ans);
        sm1.helper(inputSm1);
        double scalar = 0;
        ans[0][0] = 0;
        sm1 *= scalar;
        CHECK(sm1 == ans);
        sm1.helper(inputSm1);
        scalar = -3;
        ans[0][0] = -234;
        sm1 *= scalar;
        CHECK(sm1 == ans);
        sm1.helper(inputSm1);
        scalar = 13;
        ans[0][0] = 1014;
        sm1 *= scalar;
        CHECK(sm1 == ans);
    }
    SUBCASE("operator~"){
        SquareMat sm1(5);
        SquareMat sm2(5);
        SquareMat ans;
        double inputSm1[] = {7,3,6,3,-4,8,3,-23,5,8,0,10,5,-3,5,-67,7,23,8,-34,0,45,23,0,40};
        sm1.helper(inputSm1);
        double inputSm2[] = {7,8,0,-67,0,3,3,10,7,45,6,-23,5,23,23,3,5,-3,8,0,-4,8,5,-34,40};
        sm2.helper(inputSm2);
        ans = ~sm1;
        CHECK(ans.equal(sm2));
    }
    SUBCASE("operator^"){
        SquareMat sm(5);
        SquareMat ans(5);
        double inputSm[] = {7,3,6,3,-4,8,3,-23,5,8,0,10,5,-3,5,-67,7,23,8,-34,0,45,23,0,40};
        double inputAns1[] = {1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
        ans.helper(inputAns1);
        sm.helper(inputSm);
        CHECK(ans.equal( sm^0 )); 
        CHECK(ans == (sm^0));
        double inputAns2[] = {-96459,-581258,-49439,-59806,-519601,-102779,-49206,-143351,-709,11328,-16986,857178,54447
                                ,113696,708041,-76535,-2852876,132048,-418983,-2511678,801,4674061,182519,632564,4093012};
        ans.helper(inputAns2);
        CHECK(ans.equal( sm^4 )); 
        CHECK(ans == (sm^4));

    }
    SUBCASE("operator!"){
        SquareMat sm(4);
        double inputSm[] = {7,3,6,3,-4,8,3,-23,5,8,0,10,5,-3,5,-67};
        sm.helper(inputSm);
        double det = !sm;
        CHECK(det == 38835);  
        double input2[] = {2,6,-7,5,12,-9,8,14,4,4,-8,-4,3,5,6,3};
        sm.helper(input2);
        det = !sm;
        CHECK(det == -12904);
    }
    SUBCASE("operator% (mat)"){
        SquareMat sm1(4);
        SquareMat sm2(4);
        SquareMat ans(4);
        SquareMat ans1;
        double input1[] =        {7, 3,  6,  3, -4, 8, 3, -23,   5,8, 0,10, 5,-3,  5,-67};
        double input2[] =        {2, 6, -7,  5, 12,-9, 8,  14,   4,4,8,-4, 3, 5,  6,  3};
        double inputAns[] =      {14,18,-42,15,-48,-72,24, -322,20,32,0,-40,15,-15,30,-201};
        sm1.helper(input1);
        sm2.helper(input2);
        ans.helper(inputAns);
        ans1 = sm1 % sm2; 
        CHECK(ans1 == ans);
        CHECK(ans1.equal(ans));
    }
    SUBCASE("operator%= (mat)"){
        SquareMat sm1(4);
        SquareMat sm2(4);
        SquareMat ans(4);
        double input1[] =        {7, 3,  6,  3, -4, 8, 3, -23,   5,8, 0,10, 5,-3,  5,-67};
        double input2[] =        {2, 6, -7,  5, 12,-9, 8,  14,   4,4,8,-4, 3, 5,  6,  3};
        double inputAns[] =      {14,18,-42,15,-48,-72,24, -322,20,32,0,-40,15,-15,30,-201};
        sm1.helper(input1);
        sm2.helper(input2);
        sm1 %= sm2;
        ans.helper(inputAns);
        CHECK(sm1 == ans);
        CHECK(sm1.equal(ans));
    }
    SUBCASE("operator% (integer)"){
        SquareMat sm1(4);
        double input1[] =        {7, 3,  6,  3, -4, 8.3, 3, -23, 5.12 ,8, 0,10.333, 5,-3.1,  5,-67};
        sm1.helper(input1);
        int modulu = 4;
        SquareMat ans(4);
        SquareMat ans1(4);
        double input2[] =        {3, 3,  2,  3,  0, 0.3, 3,  -3, 1.12, 0, 0,2.333, 1, -3.1,  1,  -3};
        ans.helper(input2);
        ans1 = sm1 % modulu ;
        CHECK(ans1 == ans);
    }
    SUBCASE("operator% (integer)"){
        SquareMat sm1(4);
        double input1[] =        {7, 3,  6,  3, -4, 8.3, 3, -23, 5.12 ,8, 0,10.333, 5,-3.1,  5,-67};
        sm1.helper(input1);
        int modulu = 4;
        sm1 %= modulu;
        SquareMat ans(4);
        double input2[] =        {3, 3,  2,  3,  0, 0.3, 3,  -3, 1.12, 0, 0,2.333, 1, -3.1,  1,  -3};
        ans.helper(input2);
        CHECK(sm1 == ans);
    }
}
